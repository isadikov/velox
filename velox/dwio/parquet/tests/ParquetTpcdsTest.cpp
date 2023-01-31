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

#include "velox/common/base/tests/GTestUtils.h"
#include "velox/dwio/parquet/RegisterParquetReader.h"
#include "velox/dwio/parquet/tests/ParquetTpcdsTestBase.h"

class MultiParquetTpcdsTest
   : public ParquetTpcdsTestBase,
     public testing::WithParamInterface<ParquetReaderType> {
public:
 MultiParquetTpcdsTest() : ParquetTpcdsTestBase(GetParam()) {}
};

TEST_P(MultiParquetTpcdsTest, Q1) {
 assertQuery(1);
}

VELOX_INSTANTIATE_TEST_SUITE_P(
    ParquetTpcdsTestBase,
    MultiParquetTpcdsTest,
    testing::ValuesIn({ParquetReaderType::DUCKDB, ParquetReaderType::NATIVE}));

int main(int argc, char** argv) {
 testing::InitGoogleTest(&argc, argv);
 folly::init(&argc, &argv, false);
 return RUN_ALL_TESTS();
}
