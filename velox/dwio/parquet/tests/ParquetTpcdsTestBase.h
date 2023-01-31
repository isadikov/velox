/*
* Copyright (c) Facebook, Inc. and its affiliates.
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/

#include <folly/init/Init.h>
#include <vector>

#include "velox/common/base/Fs.h"
#include "velox/common/file/FileSystems.h"
#include "velox/dwio/parquet/RegisterParquetReader.h"
#include "velox/dwio/parquet/duckdb_reader/ParquetReader.h"
#include "velox/exec/tests/utils/HiveConnectorTestBase.h"
#include "velox/exec/tests/utils/PlanBuilder.h"
#include "velox/exec/tests/utils/TempDirectoryPath.h"
#include "velox/exec/tests/utils/TpcdsQueryBuilder.h"
#include "velox/functions/prestosql/aggregates/RegisterAggregateFunctions.h"
#include "velox/functions/prestosql/registration/RegistrationFunctions.h"
#include "velox/parse/TypeResolver.h"

using namespace facebook::velox;
using namespace facebook::velox::exec;
using namespace facebook::velox::exec::test;
using namespace facebook::velox::parquet;

namespace facebook::velox::exec::test {
namespace {

class ParquetTpcdsTestBase : public testing::Test {
public:
 ParquetTpcdsTestBase(ParquetReaderType parquetReaderType)
     : parquetReaderType_(parquetReaderType) {}

 // Set up a DuckDB instance for the entire suite and load TPC-DS data with scale
 // factor 0.01.
 void SetUp() {
   if (duckDb_ == nullptr) {
     duckDb_ = std::make_shared<DuckDbQueryRunner>();
     constexpr double kTpcdsScaleFactor = 0.01;
     duckDb_->initializeTpcds(kTpcdsScaleFactor);
   }
   functions::prestosql::registerAllScalarFunctions();
   aggregate::prestosql::registerAllAggregateFunctions();

   parse::registerTypeResolver();
   filesystems::registerLocalFileSystem();
   registerParquetReaderFactory(parquetReaderType_);

   auto hiveConnector =
       connector::getConnectorFactory(
           connector::hive::HiveConnectorFactory::kHiveConnectorName)
           ->newConnector(kHiveConnectorId, nullptr);
   connector::registerConnector(hiveConnector);
   tempDirectory_ = TempDirectoryPath::create();
   saveTpcdsTablesAsParquet();
   tpcdsBuilder_.initialize(tempDirectory_->path);
 }

 void assertQuery(
     int queryId,
     std::optional<std::vector<uint32_t>> sortingKeys = {}) const {
   auto tpcdsPlan = tpcdsBuilder_.getQueryPlan(queryId);
   auto duckDbSql = duckDb_->getTpcdsQuery(queryId);
   assertQuery(tpcdsPlan, duckDbSql, sortingKeys);
 }

 void TearDown() {
   connector::unregisterConnector(kHiveConnectorId);
   unregisterParquetReaderFactory();
 }

private:
 /// Write TPC-DS tables as a Parquet file to temp directory in hive-style
 /// partition
 void saveTpcdsTablesAsParquet() {
   constexpr int kRowGroupSize = 10'000;
   const auto tableNames = tpcdsBuilder_.getTableNames();
   for (const auto& tableName : tableNames) {
     auto tableDirectory =
         fmt::format("{}/{}", tempDirectory_->path, tableName);
     fs::create_directory(tableDirectory);
     auto filePath = fmt::format("{}/file.parquet", tableDirectory);
     auto query = fmt::format(
         fmt::runtime(kDuckDbParquetWriteSQL_.at(tableName)),
         tableName,
         filePath,
         kRowGroupSize);
     duckDb_->execute(query);
   }
 }

 std::shared_ptr<Task> assertQuery(
     const TpcdsPlan& tpcdsPlan,
     const std::string& duckQuery,
     std::optional<std::vector<uint32_t>> sortingKeys) const {
   bool noMoreSplits = false;
   constexpr int kNumSplits = 10;
   constexpr int kNumDrivers = 4;
   auto addSplits = [&](Task* task) {
     if (!noMoreSplits) {
       for (const auto& entry : tpcdsPlan.dataFiles) {
         for (const auto& path : entry.second) {
           auto const splits = HiveConnectorTestBase::makeHiveConnectorSplits(
               path, kNumSplits, tpcdsPlan.dataFileFormat);
           for (const auto& split : splits) {
             task->addSplit(entry.first, Split(split));
           }
         }
         task->noMoreSplits(entry.first);
       }
     }
     noMoreSplits = true;
   };
   CursorParameters params;
   params.maxDrivers = kNumDrivers;
   params.planNode = tpcdsPlan.plan;
   return exec::test::assertQuery(
       params, addSplits, duckQuery, *duckDb_, sortingKeys);
 }

 const ParquetReaderType parquetReaderType_;
 std::shared_ptr<DuckDbQueryRunner> duckDb_ = nullptr;
 std::shared_ptr<TempDirectoryPath> tempDirectory_ = nullptr;
 TpcdsQueryBuilder tpcdsBuilder_ =
     TpcdsQueryBuilder(dwio::common::FileFormat::PARQUET);
 const std::unordered_map<std::string, std::string> kDuckDbParquetWriteSQL_ = {
     std::make_pair("customer", R"(COPY (SELECT * FROM {}) TO '{}'(FORMAT 'parquet', CODEC 'ZSTD', ROW_GROUP_SIZE {}))"),
     std::make_pair("web_page", R"(COPY (SELECT * FROM {}) TO '{}'(FORMAT 'parquet', CODEC 'ZSTD', ROW_GROUP_SIZE {}))"),
     std::make_pair("store_sales", R"(COPY (SELECT * FROM {}) TO '{}'(FORMAT 'parquet', CODEC 'ZSTD', ROW_GROUP_SIZE {}))"),
     std::make_pair("household_demographics", R"(COPY (SELECT * FROM {}) TO '{}'(FORMAT 'parquet', CODEC 'ZSTD', ROW_GROUP_SIZE {}))"),
     std::make_pair("catalog_page", R"(COPY (SELECT * FROM {}) TO '{}'(FORMAT 'parquet', CODEC 'ZSTD', ROW_GROUP_SIZE {}))"),
     std::make_pair("web_site", R"(COPY (SELECT * FROM {}) TO '{}'(FORMAT 'parquet', CODEC 'ZSTD', ROW_GROUP_SIZE {}))"),
     std::make_pair("customer_demographics", R"(COPY (SELECT * FROM {}) TO '{}'(FORMAT 'parquet', CODEC 'ZSTD', ROW_GROUP_SIZE {}))"),
     std::make_pair("item", R"(COPY (SELECT * FROM {}) TO '{}'(FORMAT 'parquet', CODEC 'ZSTD', ROW_GROUP_SIZE {}))"),
     std::make_pair("warehouse", R"(COPY (SELECT * FROM {}) TO '{}'(FORMAT 'parquet', CODEC 'ZSTD', ROW_GROUP_SIZE {}))"),
     std::make_pair("store_returns", R"(COPY (SELECT * FROM {}) TO '{}'(FORMAT 'parquet', CODEC 'ZSTD', ROW_GROUP_SIZE {}))"),
     std::make_pair("ship_mode", R"(COPY (SELECT * FROM {}) TO '{}'(FORMAT 'parquet', CODEC 'ZSTD', ROW_GROUP_SIZE {}))"),
     std::make_pair("income_band", R"(COPY (SELECT * FROM {}) TO '{}'(FORMAT 'parquet', CODEC 'ZSTD', ROW_GROUP_SIZE {}))"),
     std::make_pair("time_dim", R"(COPY (SELECT * FROM {}) TO '{}'(FORMAT 'parquet', CODEC 'ZSTD', ROW_GROUP_SIZE {}))"),
     std::make_pair("catalog_returns", R"(COPY (SELECT * FROM {}) TO '{}'(FORMAT 'parquet', CODEC 'ZSTD', ROW_GROUP_SIZE {}))"),
     std::make_pair("reason", R"(COPY (SELECT * FROM {}) TO '{}'(FORMAT 'parquet', CODEC 'ZSTD', ROW_GROUP_SIZE {}))"),
     std::make_pair("store", R"(COPY (SELECT * FROM {}) TO '{}'(FORMAT 'parquet', CODEC 'ZSTD', ROW_GROUP_SIZE {}))"),
     std::make_pair("inventory", R"(COPY (SELECT * FROM {}) TO '{}'(FORMAT 'parquet', CODEC 'ZSTD', ROW_GROUP_SIZE {}))"),
     std::make_pair("web_sales", R"(COPY (SELECT * FROM {}) TO '{}'(FORMAT 'parquet', CODEC 'ZSTD', ROW_GROUP_SIZE {}))"),
     std::make_pair("date_dim", R"(COPY (SELECT * FROM {}) TO '{}'(FORMAT 'parquet', CODEC 'ZSTD', ROW_GROUP_SIZE {}))"),
     std::make_pair("call_center", R"(COPY (SELECT * FROM {}) TO '{}'(FORMAT 'parquet', CODEC 'ZSTD', ROW_GROUP_SIZE {}))"),
     std::make_pair("web_returns", R"(COPY (SELECT * FROM {}) TO '{}'(FORMAT 'parquet', CODEC 'ZSTD', ROW_GROUP_SIZE {}))"),
     std::make_pair("promotion", R"(COPY (SELECT * FROM {}) TO '{}'(FORMAT 'parquet', CODEC 'ZSTD', ROW_GROUP_SIZE {}))"),
     std::make_pair("customer_address", R"(COPY (SELECT * FROM {}) TO '{}'(FORMAT 'parquet', CODEC 'ZSTD', ROW_GROUP_SIZE {}))"),
     std::make_pair("catalog_sales", R"(COPY (SELECT * FROM {}) TO '{}'(FORMAT 'parquet', CODEC 'ZSTD', ROW_GROUP_SIZE {}))"),
 };
};

} // namespace
} // namespace facebook::velox::exec::test