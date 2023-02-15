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
#include "velox/exec/tests/utils/TpcdsQueryBuilder.h"

#include "velox/common/base/Fs.h"
#include "velox/dwio/common/ReaderFactory.h"

namespace facebook::velox::exec::test {

void TpcdsQueryBuilder::initialize(const std::string& dataPath) {
 for (const auto& [tableName, columns] : kTables_) {
   const fs::path tablePath{dataPath + "/" + tableName};
   for (auto const& dirEntry : fs::directory_iterator{tablePath}) {
     if (!dirEntry.is_regular_file()) {
       continue;
     }
     // Ignore hidden files.
     if (dirEntry.path().filename().c_str()[0] == '.') {
       continue;
     }
     if (tableMetadata_[tableName].dataFiles.empty()) {
       dwio::common::ReaderOptions readerOptions{pool_.get()};
       readerOptions.setFileFormat(format_);
       auto input = std::make_unique<dwio::common::BufferedInput>(
           std::make_shared<LocalReadFile>(dirEntry.path().string()),
           readerOptions.getMemoryPool());
       std::unique_ptr<dwio::common::Reader> reader =
           dwio::common::getReaderFactory(readerOptions.getFileFormat())
               ->createReader(std::move(input), readerOptions);
       const auto fileType = reader->rowType();
       const auto fileColumnNames = fileType->names();
       // There can be extra columns in the file towards the end.
       VELOX_CHECK_GE(fileColumnNames.size(), columns.size());
       std::unordered_map<std::string, std::string> fileColumnNamesMap(
           columns.size());
       std::transform(
           columns.begin(),
           columns.end(),
           fileColumnNames.begin(),
           std::inserter(fileColumnNamesMap, fileColumnNamesMap.begin()),
           [](std::string a, std::string b) { return std::make_pair(a, b); });
       auto columnNames = columns;
       auto types = fileType->children();
       types.resize(columnNames.size());
       tableMetadata_[tableName].type =
           std::make_shared<RowType>(std::move(columnNames), std::move(types));
       tableMetadata_[tableName].fileColumnNames =
           std::move(fileColumnNamesMap);
     }
     tableMetadata_[tableName].dataFiles.push_back(dirEntry.path());
   }
 }
}

const std::vector<std::string>& TpcdsQueryBuilder::getTableNames() {
 return kTableNames_;
}

TpcdsPlan TpcdsQueryBuilder::getQueryPlan(int queryId) const {
 switch (queryId) {
   case 1:
     return getQ1Plan();
   default:
     VELOX_NYI("TPC-DS query {} is not supported yet", queryId);
 }
}

TpcdsPlan TpcdsQueryBuilder::getQ1Plan() const {
 auto planNodeIdGenerator = std::make_shared<core::PlanNodeIdGenerator>();
 core::PlanNodeId dateDimPlanNodeId;
 core::PlanNodeId dateDimPlanNodeId2;
 core::PlanNodeId storeReturnsPlanNodeId;
 core::PlanNodeId storeReturnsPlanNodeId2;
 core::PlanNodeId storePlanNodeId;
 core::PlanNodeId customerPlanNodeId;

 auto customerTotalReturn =
     PlanBuilder(planNodeIdGenerator)
         .tableScan(
             kStoreReturns,
             getRowType(kStoreReturns, {"sr_returned_date_sk", "sr_customer_sk", "sr_return_amt", "sr_store_sk"}),
             getFileColumnNames(kStoreReturns),
             {})
         .capturePlanNodeId(storeReturnsPlanNodeId)
         .hashJoin(
             {"sr_returned_date_sk"},
             {"d_date_sk"},
             PlanBuilder(planNodeIdGenerator)
                 .tableScan(
                     kDateDim,
                     getRowType(kDateDim, {"d_date_sk", "d_year"}),
                     getFileColumnNames(kDateDim),
                     {"d_year = 2000::INTEGER"})
                 .capturePlanNodeId(dateDimPlanNodeId)
                 .planNode(),
             "",
             {"sr_customer_sk", "sr_store_sk", "sr_return_amt"})
         .partialAggregation(
             {"sr_customer_sk", "sr_store_sk"},
             {"sum(sr_return_amt) AS ctr_total_return"})
         .localPartition({"sr_customer_sk", "sr_store_sk"})
         .finalAggregation()
         .project({"sr_customer_sk AS ctr_customer_sk", "sr_store_sk AS ctr_store_sk", "ctr_total_return"});

 auto avgTotalReturn =
     PlanBuilder(planNodeIdGenerator)
         .tableScan(
             kStoreReturns,
             getRowType(kStoreReturns, {"sr_returned_date_sk", "sr_customer_sk", "sr_return_amt", "sr_store_sk"}),
             getFileColumnNames(kStoreReturns),
             {})
         .capturePlanNodeId(storeReturnsPlanNodeId2)
         .hashJoin(
             {"sr_returned_date_sk"},
             {"d_date_sk"},
             PlanBuilder(planNodeIdGenerator)
                 .tableScan(
                     kDateDim,
                     getRowType(kDateDim, {"d_date_sk", "d_year"}),
                     getFileColumnNames(kDateDim),
                     {"d_year = 2000::INTEGER"})
                 .capturePlanNodeId(dateDimPlanNodeId2)
                 .planNode(),
             "",
             {"sr_customer_sk", "sr_store_sk", "sr_return_amt"})
         .partialAggregation(
             {"sr_customer_sk", "sr_store_sk"},
             {"sum(sr_return_amt) AS ctr_total_return"})
         .intermediateAggregation()
         .partialAggregation(
             {"sr_store_sk"},
             {"avg(ctr_total_return) AS avg_ctr_total_return"})
         .localPartition({"sr_store_sk"})
         .finalAggregation()
         .project({"sr_store_sk as ctr_store_sk", "avg_ctr_total_return * 1.2 as avg_ctr_total_return"})
         .planNode();

 auto finalPlan =
     customerTotalReturn
         .hashJoin(
             {"ctr_store_sk"},
             {"s_store_sk"},
             PlanBuilder(planNodeIdGenerator)
                 .tableScan(
                     kStore,
                     getRowType(kStore, {"s_store_sk", "s_state"}),
                     getFileColumnNames(kStore),
                     {"s_state = 'TN'"})
                 .capturePlanNodeId(storePlanNodeId)
                 .planNode(),
             "",
             {"ctr_store_sk", "ctr_total_return", "ctr_customer_sk"})
         .hashJoin(
             {"ctr_store_sk"},
             {"ctr_store_sk"},
             avgTotalReturn,
             "ctr_total_return > avg_ctr_total_return",
             {"ctr_customer_sk"})
         .hashJoin(
             {"ctr_customer_sk"},
             {"c_customer_sk"},
             PlanBuilder(planNodeIdGenerator)
                 .tableScan(
                     kCustomer,
                     getRowType(kCustomer, {"c_customer_sk", "c_customer_id"}),
                     getFileColumnNames(kCustomer),
                     {})
                 .capturePlanNodeId(customerPlanNodeId)
                 .planNode(),
             "",
             {"c_customer_id"})
         .topN({"c_customer_id"}, 100, false)
         .planNode();

 TpcdsPlan context;
 context.plan = std::move(finalPlan);
 context.dataFiles[dateDimPlanNodeId] = getTableFilePaths(kDateDim);
 context.dataFiles[dateDimPlanNodeId2] = getTableFilePaths(kDateDim);
 context.dataFiles[storeReturnsPlanNodeId] = getTableFilePaths(kStoreReturns);
 context.dataFiles[storeReturnsPlanNodeId2] = getTableFilePaths(kStoreReturns);
 context.dataFiles[storePlanNodeId] = getTableFilePaths(kStore);
 context.dataFiles[customerPlanNodeId] = getTableFilePaths(kCustomer);
 context.dataFileFormat = format_;

 return context;
}


const std::vector<std::string> TpcdsQueryBuilder::kTableNames_ = {
    kCallCenter,
    kCatalogPage,
    kCatalogReturns,
    kCatalogSales,
    kCustomer,
    kCustomerAddress,
    kCustomerDemographics,
    kDateDim,
    kHouseholdDemographics,
    kIncomeBand,
    kInventory,
    kItem,
    kPromotion,
    kReason,
    kShipMode,
    kStore,
    kStoreReturns,
    kStoreSales,
    kTimeDim,
    kWarehouse,
    kWebPage,
    kWebReturns,
    kWebSales,
    kWebSite};

const std::vector<std::string> kCustomerColumns_ = {"c_customer_sk", "c_customer_id", "c_current_cdemo_sk", "c_current_hdemo_sk", "c_current_addr_sk", "c_first_shipto_date_sk", "c_first_sales_date_sk", "c_salutation", "c_first_name", "c_last_name", "c_preferred_cust_flag", "c_birth_day", "c_birth_month", "c_birth_year", "c_birth_country", "c_login", "c_email_address", "c_last_review_date_sk"};
const std::vector<std::string> kWebPageColumns_ = {"wp_web_page_sk", "wp_web_page_id", "wp_rec_start_date", "wp_rec_end_date", "wp_creation_date_sk", "wp_access_date_sk", "wp_autogen_flag", "wp_customer_sk", "wp_url", "wp_type", "wp_char_count", "wp_link_count", "wp_image_count", "wp_max_ad_count"};
const std::vector<std::string> kStoreSalesColumns_ = {"ss_sold_date_sk", "ss_sold_time_sk", "ss_item_sk", "ss_customer_sk", "ss_cdemo_sk", "ss_hdemo_sk", "ss_addr_sk", "ss_store_sk", "ss_promo_sk", "ss_ticket_number", "ss_quantity", "ss_wholesale_cost", "ss_list_price", "ss_sales_price", "ss_ext_discount_amt", "ss_ext_sales_price", "ss_ext_wholesale_cost", "ss_ext_list_price", "ss_ext_tax", "ss_coupon_amt", "ss_net_paid", "ss_net_paid_inc_tax", "ss_net_profit"};
const std::vector<std::string> kHouseholdDemographicsColumns_ = {"hd_demo_sk", "hd_income_band_sk", "hd_buy_potential", "hd_dep_count", "hd_vehicle_count"};
const std::vector<std::string> kCatalogPageColumns_ = {"cp_catalog_page_sk", "cp_catalog_page_id", "cp_start_date_sk", "cp_end_date_sk", "cp_department", "cp_catalog_number", "cp_catalog_page_number", "cp_description", "cp_type"};
const std::vector<std::string> kWebSiteColumns_ = {"web_site_sk", "web_site_id", "web_rec_start_date", "web_rec_end_date", "web_name", "web_open_date_sk", "web_close_date_sk", "web_class", "web_manager", "web_mkt_id", "web_mkt_class", "web_mkt_desc", "web_market_manager", "web_company_id", "web_company_name", "web_street_number", "web_street_name", "web_street_type", "web_suite_number", "web_city", "web_county", "web_state", "web_zip", "web_country", "web_gmt_offset", "web_tax_percentage"};
const std::vector<std::string> kCustomerDemographicsColumns_ = {"cd_demo_sk", "cd_gender", "cd_marital_status", "cd_education_status", "cd_purchase_estimate", "cd_credit_rating", "cd_dep_count", "cd_dep_employed_count", "cd_dep_college_count"};
const std::vector<std::string> kItemColumns_ = {"i_item_sk", "i_item_id", "i_rec_start_date", "i_rec_end_date", "i_item_desc", "i_current_price", "i_wholesale_cost", "i_brand_id", "i_brand", "i_class_id", "i_class", "i_category_id", "i_category", "i_manufact_id", "i_manufact", "i_size", "i_formulation", "i_color", "i_units", "i_container", "i_manager_id", "i_product_name"};
const std::vector<std::string> kWarehouseColumns_ = {"w_warehouse_sk", "w_warehouse_id", "w_warehouse_name", "w_warehouse_sq_ft", "w_street_number", "w_street_name", "w_street_type", "w_suite_number", "w_city", "w_county", "w_state", "w_zip", "w_country", "w_gmt_offset"};
const std::vector<std::string> kStoreReturnsColumns_ = {"sr_returned_date_sk", "sr_return_time_sk", "sr_item_sk", "sr_customer_sk", "sr_cdemo_sk", "sr_hdemo_sk", "sr_addr_sk", "sr_store_sk", "sr_reason_sk", "sr_ticket_number", "sr_return_quantity", "sr_return_amt", "sr_return_tax", "sr_return_amt_inc_tax", "sr_fee", "sr_return_ship_cost", "sr_refunded_cash", "sr_reversed_charge", "sr_store_credit", "sr_net_loss"};
const std::vector<std::string> kShipModeColumns_ = {"sm_ship_mode_sk", "sm_ship_mode_id", "sm_type", "sm_code", "sm_carrier", "sm_contract"};
const std::vector<std::string> kIncomeBandColumns_ = {"ib_income_band_sk", "ib_lower_bound", "ib_upper_bound"};
const std::vector<std::string> kTimeDimColumns_ = {"t_time_sk", "t_time_id", "t_time", "t_hour", "t_minute", "t_second", "t_am_pm", "t_shift", "t_sub_shift", "t_meal_time"};
const std::vector<std::string> kCatalogReturnsColumns_ = {"cr_returned_date_sk", "cr_returned_time_sk", "cr_item_sk", "cr_refunded_customer_sk", "cr_refunded_cdemo_sk", "cr_refunded_hdemo_sk", "cr_refunded_addr_sk", "cr_returning_customer_sk", "cr_returning_cdemo_sk", "cr_returning_hdemo_sk", "cr_returning_addr_sk", "cr_call_center_sk", "cr_catalog_page_sk", "cr_ship_mode_sk", "cr_warehouse_sk", "cr_reason_sk", "cr_order_number", "cr_return_quantity", "cr_return_amount", "cr_return_tax", "cr_return_amt_inc_tax", "cr_fee", "cr_return_ship_cost", "cr_refunded_cash", "cr_reversed_charge", "cr_store_credit", "cr_net_loss"};
const std::vector<std::string> kReasonColumns_ = {"r_reason_sk", "r_reason_id", "r_reason_desc"};
const std::vector<std::string> kStoreColumns_ = {"s_store_sk", "s_store_id", "s_rec_start_date", "s_rec_end_date", "s_closed_date_sk", "s_store_name", "s_number_employees", "s_floor_space", "s_hours", "s_manager", "s_market_id", "s_geography_class", "s_market_desc", "s_market_manager", "s_division_id", "s_division_name", "s_company_id", "s_company_name", "s_street_number", "s_street_name", "s_street_type", "s_suite_number", "s_city", "s_county", "s_state", "s_zip", "s_country", "s_gmt_offset", "s_tax_precentage"};
const std::vector<std::string> kInventoryColumns_ = {"inv_date_sk", "inv_item_sk", "inv_warehouse_sk", "inv_quantity_on_hand"};
const std::vector<std::string> kWebSalesColumns_ = {"ws_sold_date_sk", "ws_sold_time_sk", "ws_ship_date_sk", "ws_item_sk", "ws_bill_customer_sk", "ws_bill_cdemo_sk", "ws_bill_hdemo_sk", "ws_bill_addr_sk", "ws_ship_customer_sk", "ws_ship_cdemo_sk", "ws_ship_hdemo_sk", "ws_ship_addr_sk", "ws_web_page_sk", "ws_web_site_sk", "ws_ship_mode_sk", "ws_warehouse_sk", "ws_promo_sk", "ws_order_number", "ws_quantity", "ws_wholesale_cost", "ws_list_price", "ws_sales_price", "ws_ext_discount_amt", "ws_ext_sales_price", "ws_ext_wholesale_cost", "ws_ext_list_price", "ws_ext_tax", "ws_coupon_amt", "ws_ext_ship_cost", "ws_net_paid", "ws_net_paid_inc_tax", "ws_net_paid_inc_ship", "ws_net_paid_inc_ship_tax", "ws_net_profit"};
const std::vector<std::string> kDateDimColumns_ = {"d_date_sk", "d_date_id", "d_date", "d_month_seq", "d_week_seq", "d_quarter_seq", "d_year", "d_dow", "d_moy", "d_dom", "d_qoy", "d_fy_year", "d_fy_quarter_seq", "d_fy_week_seq", "d_day_name", "d_quarter_name", "d_holiday", "d_weekend", "d_following_holiday", "d_first_dom", "d_last_dom", "d_same_day_ly", "d_same_day_lq", "d_current_day", "d_current_week", "d_current_month", "d_current_quarter", "d_current_year"};
const std::vector<std::string> kCallCenterColumns_ = {"cc_call_center_sk", "cc_call_center_id", "cc_rec_start_date", "cc_rec_end_date", "cc_closed_date_sk", "cc_open_date_sk", "cc_name", "cc_class", "cc_employees", "cc_sq_ft", "cc_hours", "cc_manager", "cc_mkt_id", "cc_mkt_class", "cc_mkt_desc", "cc_market_manager", "cc_division", "cc_division_name", "cc_company", "cc_company_name", "cc_street_number", "cc_street_name", "cc_street_type", "cc_suite_number", "cc_city", "cc_county", "cc_state", "cc_zip", "cc_country", "cc_gmt_offset", "cc_tax_percentage"};
const std::vector<std::string> kWebReturnsColumns_ = {"wr_returned_date_sk", "wr_returned_time_sk", "wr_item_sk", "wr_refunded_customer_sk", "wr_refunded_cdemo_sk", "wr_refunded_hdemo_sk", "wr_refunded_addr_sk", "wr_returning_customer_sk", "wr_returning_cdemo_sk", "wr_returning_hdemo_sk", "wr_returning_addr_sk", "wr_web_page_sk", "wr_reason_sk", "wr_order_number", "wr_return_quantity", "wr_return_amt", "wr_return_tax", "wr_return_amt_inc_tax", "wr_fee", "wr_return_ship_cost", "wr_refunded_cash", "wr_reversed_charge", "wr_account_credit", "wr_net_loss"};
const std::vector<std::string> kPromotionColumns_ = {"p_promo_sk", "p_promo_id", "p_start_date_sk", "p_end_date_sk", "p_item_sk", "p_cost", "p_response_target", "p_promo_name", "p_channel_dmail", "p_channel_email", "p_channel_catalog", "p_channel_tv", "p_channel_radio", "p_channel_press", "p_channel_event", "p_channel_demo", "p_channel_details", "p_purpose", "p_discount_active"};
const std::vector<std::string> kCustomerAddressColumns_ = {"ca_address_sk", "ca_address_id", "ca_street_number", "ca_street_name", "ca_street_type", "ca_suite_number", "ca_city", "ca_county", "ca_state", "ca_zip", "ca_country", "ca_gmt_offset", "ca_location_type"};
const std::vector<std::string> kCatalogSalesColumns_ = {"cs_sold_date_sk", "cs_sold_time_sk", "cs_ship_date_sk", "cs_bill_customer_sk", "cs_bill_cdemo_sk", "cs_bill_hdemo_sk", "cs_bill_addr_sk", "cs_ship_customer_sk", "cs_ship_cdemo_sk", "cs_ship_hdemo_sk", "cs_ship_addr_sk", "cs_call_center_sk", "cs_catalog_page_sk", "cs_ship_mode_sk", "cs_warehouse_sk", "cs_item_sk", "cs_promo_sk", "cs_order_number", "cs_quantity", "cs_wholesale_cost", "cs_list_price", "cs_sales_price", "cs_ext_discount_amt", "cs_ext_sales_price", "cs_ext_wholesale_cost", "cs_ext_list_price", "cs_ext_tax", "cs_coupon_amt", "cs_ext_ship_cost", "cs_net_paid", "cs_net_paid_inc_tax", "cs_net_paid_inc_ship", "cs_net_paid_inc_ship_tax", "cs_net_profit"};

const std::unordered_map<std::string, std::vector<std::string>>
   TpcdsQueryBuilder::kTables_ = {
        std::make_pair(kCustomer, kCustomerColumns_),
        std::make_pair(kWebPage, kWebPageColumns_),
        std::make_pair(kStoreSales, kStoreSalesColumns_),
        std::make_pair(kHouseholdDemographics, kHouseholdDemographicsColumns_),
        std::make_pair(kCatalogPage, kCatalogPageColumns_),
        std::make_pair(kWebSite, kWebSiteColumns_),
        std::make_pair(kCustomerDemographics, kCustomerDemographicsColumns_),
        std::make_pair(kItem, kItemColumns_),
        std::make_pair(kWarehouse, kWarehouseColumns_),
        std::make_pair(kStoreReturns, kStoreReturnsColumns_),
        std::make_pair(kShipMode, kShipModeColumns_),
        std::make_pair(kIncomeBand, kIncomeBandColumns_),
        std::make_pair(kTimeDim, kTimeDimColumns_),
        std::make_pair(kCatalogReturns, kCatalogReturnsColumns_),
        std::make_pair(kReason, kReasonColumns_),
        std::make_pair(kStore, kStoreColumns_),
        std::make_pair(kInventory, kInventoryColumns_),
        std::make_pair(kWebSales, kWebSalesColumns_),
        std::make_pair(kDateDim, kDateDimColumns_),
        std::make_pair(kCallCenter, kCallCenterColumns_),
        std::make_pair(kWebReturns, kWebReturnsColumns_),
        std::make_pair(kPromotion, kPromotionColumns_),
        std::make_pair(kCustomerAddress, kCustomerAddressColumns_),
        std::make_pair(kCatalogSales, kCatalogSalesColumns_),
};

} // namespace facebook::velox::exec::test
