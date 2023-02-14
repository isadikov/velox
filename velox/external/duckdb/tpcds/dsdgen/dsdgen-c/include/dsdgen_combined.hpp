#include <stdio.h>
#include <ctype.h>
#include <math.h>


// mathops.h

namespace __mathops__ {

/*
 * Legal Notice
 *
 * This document and associated source code (the "Work") is a part of a
 * benchmark specification maintained by the TPC.
 *
 * The TPC reserves all right, title, and interest to the Work as provided
 * under U.S. and international laws, including without limitation all patent
 * and trademark rights therein.
 *
 * No Warranty
 *
 * 1.1 TO THE MAXIMUM EXTENT PERMITTED BY APPLICABLE LAW, THE INFORMATION
 *     CONTAINED HEREIN IS PROVIDED "AS IS" AND WITH ALL FAULTS, AND THE
 *     AUTHORS AND DEVELOPERS OF THE WORK HEREBY DISCLAIM ALL OTHER
 *     WARRANTIES AND CONDITIONS, EITHER EXPRESS, IMPLIED OR STATUTORY,
 *     INCLUDING, BUT NOT LIMITED TO, ANY (IF ANY) IMPLIED WARRANTIES,
 *     DUTIES OR CONDITIONS OF MERCHANTABILITY, OF FITNESS FOR A PARTICULAR
 *     PURPOSE, OF ACCURACY OR COMPLETENESS OF RESPONSES, OF RESULTS, OF
 *     WORKMANLIKE EFFORT, OF LACK OF VIRUSES, AND OF LACK OF NEGLIGENCE.
 *     ALSO, THERE IS NO WARRANTY OR CONDITION OF TITLE, QUIET ENJOYMENT,
 *     QUIET POSSESSION, CORRESPONDENCE TO DESCRIPTION OR NON-INFRINGEMENT
 *     WITH REGARD TO THE WORK.
 * 1.2 IN NO EVENT WILL ANY AUTHOR OR DEVELOPER OF THE WORK BE LIABLE TO
 *     ANY OTHER PARTY FOR ANY DAMAGES, INCLUDING BUT NOT LIMITED TO THE
 *     COST OF PROCURING SUBSTITUTE GOODS OR SERVICES, LOST PROFITS, LOSS
 *     OF USE, LOSS OF DATA, OR ANY INCIDENTAL, CONSEQUENTIAL, DIRECT,
 *     INDIRECT, OR SPECIAL DAMAGES WHETHER UNDER CONTRACT, TORT, WARRANTY,
 *     OR OTHERWISE, ARISING IN ANY WAY OUT OF THIS OR ANY OTHER AGREEMENT
 *     RELATING TO THE WORK, WHETHER OR NOT SUCH AUTHOR OR DEVELOPER HAD
 *     ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES.
 *
 * Contributors:
 * Gradient Systems
 */
#define OP_PLUS    0x00001
#define OP_MINUS   0x00002
#define OP_MULT    0x00004
#define OP_DIV     0x00008
#define OP_MOD     0x00010
#define OP_XOR     0x00020
#define OP_PAREN   0x00040
#define OP_BRACKET 0x00080
#define OP_NEST    0x00100 /* a --> (a) */
#define OP_NEG     0x00200
#define OP_ADDR    0x00400 /* get an address */
#define OP_PTR     0x00800 /* reference through a pointer */
#define OP_FUNC    0x01000 /* user function/macro */
#define OP_UNIQUE  0x02000 /* built in functions start here */
#define OP_TEXT    0x04000
#define OP_RANDOM  0x08000
#define OP_RANGE   0x10000
#define OP_USER    0x20000 /* user defined function */

} // __mathops__


// constants.h

namespace __constants__ {

/*
 * Legal Notice
 *
 * This document and associated source code (the "Work") is a part of a
 * benchmark specification maintained by the TPC.
 *
 * The TPC reserves all right, title, and interest to the Work as provided
 * under U.S. and international laws, including without limitation all patent
 * and trademark rights therein.
 *
 * No Warranty
 *
 * 1.1 TO THE MAXIMUM EXTENT PERMITTED BY APPLICABLE LAW, THE INFORMATION
 *     CONTAINED HEREIN IS PROVIDED "AS IS" AND WITH ALL FAULTS, AND THE
 *     AUTHORS AND DEVELOPERS OF THE WORK HEREBY DISCLAIM ALL OTHER
 *     WARRANTIES AND CONDITIONS, EITHER EXPRESS, IMPLIED OR STATUTORY,
 *     INCLUDING, BUT NOT LIMITED TO, ANY (IF ANY) IMPLIED WARRANTIES,
 *     DUTIES OR CONDITIONS OF MERCHANTABILITY, OF FITNESS FOR A PARTICULAR
 *     PURPOSE, OF ACCURACY OR COMPLETENESS OF RESPONSES, OF RESULTS, OF
 *     WORKMANLIKE EFFORT, OF LACK OF VIRUSES, AND OF LACK OF NEGLIGENCE.
 *     ALSO, THERE IS NO WARRANTY OR CONDITION OF TITLE, QUIET ENJOYMENT,
 *     QUIET POSSESSION, CORRESPONDENCE TO DESCRIPTION OR NON-INFRINGEMENT
 *     WITH REGARD TO THE WORK.
 * 1.2 IN NO EVENT WILL ANY AUTHOR OR DEVELOPER OF THE WORK BE LIABLE TO
 *     ANY OTHER PARTY FOR ANY DAMAGES, INCLUDING BUT NOT LIMITED TO THE
 *     COST OF PROCURING SUBSTITUTE GOODS OR SERVICES, LOST PROFITS, LOSS
 *     OF USE, LOSS OF DATA, OR ANY INCIDENTAL, CONSEQUENTIAL, DIRECT,
 *     INDIRECT, OR SPECIAL DAMAGES WHETHER UNDER CONTRACT, TORT, WARRANTY,
 *     OR OTHERWISE, ARISING IN ANY WAY OUT OF THIS OR ANY OTHER AGREEMENT
 *     RELATING TO THE WORK, WHETHER OR NOT SUCH AUTHOR OR DEVELOPER HAD
 *     ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES.
 *
 * Contributors:
 * Gradient Systems
 */
#ifndef CONSTANTS_H
#define CONSTANTS_H
/***
*** Multi-table/Global Defines
***/
#define DATA_START_DATE "1998-01-01" /* earliest date in the data set */
#define DATA_END_DATE   "2003-12-31" /* latest date in the data set */
#define LINES_PER_ORDER 16           /* max number of lineitems per order for all channels */

/***
*** C_xxx Cutomer Defines
***/
#define C_PREFERRED_PCT 50

/***
 *** CC_xxx Call Center Defines
 ***/
#define CC_EMPLOYEE_MAX 7 /* rises ~ scale ^ 2 */

/***
 *** CP_xxx Catalog Page Defines
 ***/
#define CP_CATALOGS_PER_YEAR 18
#define CP_SK(c, s, p)       (c * s + p)

/***
*** CR_xxx Catalog Returns Defines
***/
#define CR_RETURN_PCT 10 /* percentage of catalog sales that are returned */

/***
*** CS_xxx Customer Sales Defines
***/
#define CS_QUANTITY_MAX    "100"
#define CS_MARKUP_MAX      "2.00"
#define CS_DISCOUNT_MAX    "1.00"
#define CS_WHOLESALE_MAX   "100.00"
#define CS_COUPON_MAX      "0.50"
#define CS_MIN_SHIP_DELAY  2  /* minimum days from order to ship */
#define CS_MAX_SHIP_DELAY  90 /* maximum days from order to ship */
#define CS_ITEMS_PER_ORDER 10 /* number of items in each order */
#define CS_GIFT_PCT        10 /* ship-to != bill-to */

/*
 * DATE SETTINGS
 *
 * The benchmarks sense of "today". Should this be a sliding scale/parameter?
 */
#define CURRENT_YEAR        2003
#define CURRENT_MONTH       1
#define CURRENT_DAY         8
#define CURRENT_QUARTER     1
#define CURRENT_WEEK        2
#define DATE_MINIMUM        "1998-01-01"
#define DATE_MAXIMUM        "2002-12-31"
#define YEAR_MINIMUM        1998
#define YEAR_MAXIMUM        2002
#define WAREHOUSE_LOAD_DATE "2001-07-18"
#define UPDATE_INTERVAL     30 /* refresh interval in days */
#define TODAYS_DATE         "2003-01-08"

/***
 *** INV_xxx Inventory Defines
 ***/
#define INV_QUANTITY_MIN 0
#define INV_QUANTITY_MAX 1000

/***
 *** ITEM_xxx Item Defines
 ***/
#define ITEM_DESC_LEN          5
#define ITEM_NAME_LEN          10
#define ITEM_MANFACTURER_COUNT 1000 /* number of brands handled by a particular manufacturer */

/***
 *** PROMO_xxx Promotions Defines
 ***/
#define PROMO_NAME_LEN       5
#define PROMO_START_MIN      -720
#define PROMO_START_MAX      100
#define PROMO_START_MEAN     0
#define PROMO_LEN_MIN        1
#define PROMO_LEN_MAX        60
#define PROMO_LEN_MEAN       0
#define PROMO_DETAIL_LEN_MIN 20
#define PROMO_DETAIL_LEN_MAX 60

/***
*** SR_xxx Store Returns Defines
***/
#define SR_RETURN_PCT 10 /* percentage of store sales that are returned */

/***
*** SS_xxx Store Sales Defines
***/
#define SS_MIN_SHIP_DELAY 2  /* minimum days from order to ship */
#define SS_MAX_SHIP_DELAY 90 /* maximum days from order to ship */
#define SS_QUANTITY_MAX   "100"
#define SS_MARKUP_MAX     "1.00"
#define SS_DISCOUNT_MAX   "1.00"
#define SS_WHOLESALE_MAX  "100.00"
#define SS_COUPON_MAX     "0.50"

/***
*** WP_xxx Web Page Defines
***/
#define WP_AUTOGEN_PCT 30
#define WP_LINK_MIN    2
#define WP_LINK_MAX    25
#define WP_IMAGE_MIN   1
#define WP_IMAGE_MAX   7
#define WP_AD_MIN      0
#define WP_AD_MAX      4
#define WP_MAX_REC_DURATION                                                                                            \
	1000                     /* maximum time from start to end of record                                               \
	                          */
#define WP_IDLE_TIME_MAX 100 /* maximum time since last page access */

/***
*** W_xxx Warehouse Defines
***/
#define W_DESC_MIN 5
#define W_SQFT_MIN 50000
#define W_SQFT_MAX 1000000
#define W_NAME_MIN 10

/***
*** WR_xxx Web Returns Defines
***/
#define WR_RETURN_PCT   10 /* percentage of web sales that are returned */
#define WR_SHIP_LAG_MIN 2  /* lag time between receiving and returning */
#define WR_SHIP_LAG_MAX 12

/***
*** WEB_xxx Web Site Defines
***/
#define WEB_START_DATE                                                                                                 \
	DATE_MINIMUM                        /* range of open/close dates; actual dates can exceed these                    \
	                                       values */
#define WEB_END_DATE       DATE_MAXIMUM /* due to staggered start of each site */
#define WEB_DATE_STAGGER   17           /* time between site creation on leading/trailing edge */
#define WEB_PAGES_PER_SITE 123          /* number of pages on a web site */
/* some of the web sites are completely replaced in the date range. */
#define WEB_MORTALITY         50 /* percentage of sites that "die" between start and end */
#define WEB_IS_REPLACED(j)    ((j % (100 / WEB_MORTALITY)) == 0) /* does this site get replaced? */
#define WEB_IS_REPLACEMENT(j) ((j / (100 / WEB_MORTALITY)) % 2)  /* is this the replacement? */

/***
 *** SOURCE SCHEMA CONSTANTS
 ***/
#define DAYS_PER_UPDATE 3

/***
*** RS_xxx: Row and column sizes
***/
/* sizes used in various tables */
#define RS_BKEY 16
/* table-specific sizes */

#define RS_BRND_NAME              50
#define RS_C_SALUTATION           5
#define RS_C_FIRST_NAME           20
#define RS_C_LAST_NAME            30
#define RS_C_BIRTH_COUNTRY        20
#define RS_C_LOGIN                13
#define RS_C_PASSWORD             13
#define RS_C_EMAIL                50
#define RS_C_PRIMARY_MACHINE_ID   15
#define RS_C_SECONDARY_MACHINE_ID 15
#define RS_CA_SUITE_NUMBER        10
#define RS_CA_STREET_NAME         60
#define RS_CA_STREET_TYPE         15
#define RS_CA_CITY                60
#define RS_CA_COUNTY              30
#define RS_CA_STATE               2
#define RS_CA_COUNTRY             20
#define RS_CA_ZIP                 10
#define RS_CA_LOCATION_TYPE       20
#define RS_CATG_DESC              20
#define RS_CC_NAME                50
#define RS_CC_CLASS               50
#define RS_CC_HOURS               20
#define RS_CC_MANAGER             40
#define RS_CC_MARKET_MANAGER      40
#define RS_CC_MARKET_CLASS        50
#define RS_CC_MARKET_DESC         100
#define RS_CC_DIVISION_NAME       50
#define RS_CC_COMPANY_NAME        60
#define RS_CC_SUITE_NUM           10
#define RS_CC_STREET_NAME         60
#define RS_CC_STREET_TYPE         15
#define RS_CC_CITY                60
#define RS_CC_COUNTY              30
#define RS_CC_STATE               2
#define RS_CC_COUNTRY             20
#define RS_CC_ZIP                 10
#define RS_CD_GENDER              1
#define RS_CD_MARITAL_STATUS      1
#define RS_CD_EDUCATION_STATUS    20
#define RS_CD_CREDIT_RATING       10
#define RS_CP_DEPARTMENT          20
#define RS_CLAS_DESC              100
#define RS_CMPY_NAME              50
#define RS_CP_DESCRIPTION         100
#define RS_CP_TYPE                100
#define RS_CTGR_NAME              25
#define RS_CTGR_DESC              100
#define RS_CUST_CREDIT            100
#define RS_D_DAY_NAME             4
#define RS_D_QUARTER_NAME         4
#define RS_DVSN_NAME              50
#define RS_HD_BUY_POTENTIAL       7
#define RS_I_ITEM_DESC            200
#define RS_I_BRAND                50
#define RS_I_SUBCLASS             50
#define RS_I_CLASS                50
#define RS_I_SUBCATEGORY          50
#define RS_I_CATEGORY             50
#define RS_I_MANUFACT             50
#define RS_I_SIZE                 20
#define RS_I_FORMULATION          20
#define RS_I_FLAVOR               20
#define RS_I_UNITS                10
#define RS_I_CONTAINER            10
#define RS_I_PRODUCT_NAME         50
#define RS_MANF_NAME              50
#define RS_MNGR_NAME              50
#define RS_P_PROMO_NAME           50
#define RS_P_CHANNEL_DETAILS      100
#define RS_P_PURPOSE              15
#define RS_PB_DESCRIPTION         100
#define RS_PLIN_COMMENT           100
#define RS_PROD_NAME              100
#define RS_PROD_TYPE              100
#define RS_R_REASON_DESCRIPTION   100
#define RS_STORE_NAME             50
#define RS_STORE_HOURS            20
#define RS_S_STORE_MANAGER        40
#define RS_S_GEOGRAPHY_CLASS      100
#define RS_S_MARKET_DESC          100
#define RS_S_MARKET_MANAGER       40
#define RS_S_DIVISION_NAME        50
#define RS_S_COMPANY_NAME         50
#define RS_S_SUITE_NUM            10
#define RS_S_STREET_NAME          60
#define RS_S_STREET_TYPE          15
#define RS_S_CITY                 60
#define RS_S_STATE                2
#define RS_S_COUNTY               30
#define RS_S_COUNTRY              30
#define RS_S_ZIP                  10
#define RS_SM_TYPE                30
#define RS_SM_CODE                10
#define RS_SM_CONTRACT            20
#define RS_SM_CARRIER             20
#define RS_SBCT_NAME              100
#define RS_SBCT_DESC              100
#define RS_SUBC_NAME              100
#define RS_SUBC_DESC              100
#define RS_T_AM_PM                2
#define RS_T_SHIFT                20
#define RS_T_SUB_SHIFT            20
#define RS_T_MEAL_TIME            20
#define RS_W_WAREHOUSE_NAME       20
#define RS_W_STREET_NAME          60
#define RS_W_SUITE_NUM            10
#define RS_W_STREET_TYPE          15
#define RS_W_CITY                 60
#define RS_W_COUNTY               30
#define RS_W_STATE                2
#define RS_W_COUNTRY              20
#define RS_W_ZIP                  10
#define RS_WEB_MANAGER            50
#define RS_WEB_NAME               50
#define RS_WEB_CLASS              50
#define RS_WEB_MARKET_CLASS       50
#define RS_WEB_MARKET_DESC        100
#define RS_WEB_MARKET_MANAGER     40
#define RS_WEB_COMPANY_NAME       100
#define RS_WEB_SUITE_NUMBER       10
#define RS_WEB_STREET_NAME        60
#define RS_WEB_STREET_TYPE        15
#define RS_WEB_CITY               60
#define RS_WEB_COUNTY             30
#define RS_WEB_STATE              2
#define RS_WEB_COUNTRY            20
#define RS_WEB_ZIP                10
#define RS_WP_URL                 100
#define RS_WEB_TYPE               50
#define RS_WRHS_DESC              100
#define RS_WORD_COMMENT           100
#define RS_ZIPG_ZIP               5
#endif /* CONSTANTS_H */

} // __constants__


// tables.h

namespace __tables__ {

/*
 * THIS IS A GENERATED FILE
 * SEE COLUMNS.LIST
 */
#ifndef TABLES_H
#define TABLES_H
#define CALL_CENTER                0
#define CATALOG_PAGE               1
#define CATALOG_RETURNS            2
#define CATALOG_SALES              3
#define CUSTOMER                   4
#define CUSTOMER_ADDRESS           5
#define CUSTOMER_DEMOGRAPHICS      6
#define DATET                      7
#define HOUSEHOLD_DEMOGRAPHICS     8
#define INCOME_BAND                9
#define INVENTORY                  10
#define ITEM                       11
#define PROMOTION                  12
#define REASON                     13
#define SHIP_MODE                  14
#define STORE                      15
#define STORE_RETURNS              16
#define STORE_SALES                17
#define TIME                       18
#define WAREHOUSE                  19
#define WEB_PAGE                   20
#define WEB_RETURNS                21
#define WEB_SALES                  22
#define WEB_SITE                   23
#define DBGEN_VERSION              24
#define S_BRAND                    25
#define S_CUSTOMER_ADDRESS         26
#define S_CALL_CENTER              27
#define S_CATALOG                  28
#define S_CATALOG_ORDER            29
#define S_CATALOG_ORDER_LINEITEM   30
#define S_CATALOG_PAGE             31
#define S_CATALOG_PROMOTIONAL_ITEM 32
#define S_CATALOG_RETURNS          33
#define S_CATEGORY                 34
#define S_CLASS                    35
#define S_COMPANY                  36
#define S_CUSTOMER                 37
#define S_DIVISION                 38
#define S_INVENTORY                39
#define S_ITEM                     40
#define S_MANAGER                  41
#define S_MANUFACTURER             42
#define S_MARKET                   43
#define S_PRODUCT                  44
#define S_PROMOTION                45
#define S_PURCHASE                 46
#define S_PURCHASE_LINEITEM        47
#define S_REASON                   48
#define S_STORE                    49
#define S_STORE_PROMOTIONAL_ITEM   50
#define S_STORE_RETURNS            51
#define S_SUBCATEGORY              52
#define S_SUBCLASS                 53
#define S_WAREHOUSE                54
#define S_WEB_ORDER                55
#define S_WEB_ORDER_LINEITEM       56
#define S_WEB_PAGE                 57
#define S_WEB_PROMOTIONAL_ITEM     58
#define S_WEB_RETURNS              59
#define S_WEB_SITE                 60
#define S_ZIPG                     61
#define PSEUDO_TABLE_START         62
/* PSEUDO TABLES from here on; used in hierarchies */
#define ITEM_BRAND           62
#define ITEM_CLASS           63
#define ITEM_CATEGORY        64
#define DIVISIONS            65
#define COMPANY              66
#define CONCURRENT_WEB_SITES 67
#define ACTIVE_CITIES        68
#define ACTIVE_COUNTIES      69
#define ACTIVE_STATES        70
#define MAX_TABLE            70
#endif

} // __tables__


// columns.h

namespace __columns__ {

/*
 * THIS IS A GENERATED FILE
 * SEE COLUMNS.LIST
 */
#ifndef COLUMNS_H
#define COLUMNS_H
#define CALL_CENTER_START                              1
#define CC_CALL_CENTER_SK                              1
#define CC_CALL_CENTER_ID                              2
#define CC_REC_START_DATE_ID                           3
#define CC_REC_END_DATE_ID                             4
#define CC_CLOSED_DATE_ID                              5
#define CC_OPEN_DATE_ID                                6
#define CC_NAME                                        7
#define CC_CLASS                                       8
#define CC_EMPLOYEES                                   9
#define CC_SQ_FT                                       10
#define CC_HOURS                                       11
#define CC_MANAGER                                     12
#define CC_MARKET_ID                                   13
#define CC_MARKET_CLASS                                14
#define CC_MARKET_DESC                                 15
#define CC_MARKET_MANAGER                              16
#define CC_DIVISION                                    17
#define CC_DIVISION_NAME                               18
#define CC_COMPANY                                     19
#define CC_COMPANY_NAME                                20
#define CC_STREET_NUMBER                               21
#define CC_STREET_NAME                                 22
#define CC_STREET_TYPE                                 23
#define CC_SUITE_NUMBER                                24
#define CC_CITY                                        25
#define CC_COUNTY                                      26
#define CC_STATE                                       27
#define CC_ZIP                                         28
#define CC_COUNTRY                                     29
#define CC_GMT_OFFSET                                  30
#define CC_ADDRESS                                     31
#define CC_TAX_PERCENTAGE                              32
#define CC_SCD                                         33
#define CC_NULLS                                       34
#define CALL_CENTER_END                                34
#define CATALOG_PAGE_START                             35
#define CP_CATALOG_PAGE_SK                             35
#define CP_CATALOG_PAGE_ID                             36
#define CP_START_DATE_ID                               37
#define CP_END_DATE_ID                                 38
#define CP_PROMO_ID                                    39
#define CP_DEPARTMENT                                  40
#define CP_CATALOG_NUMBER                              41
#define CP_CATALOG_PAGE_NUMBER                         42
#define CP_DESCRIPTION                                 43
#define CP_TYPE                                        44
#define CP_NULLS                                       45
#define CATALOG_PAGE_END                               45
#define CATALOG_RETURNS_START                          46
#define CR_RETURNED_DATE_SK                            46
#define CR_RETURNED_TIME_SK                            47
#define CR_ITEM_SK                                     48
#define CR_REFUNDED_CUSTOMER_SK                        49
#define CR_REFUNDED_CDEMO_SK                           50
#define CR_REFUNDED_HDEMO_SK                           51
#define CR_REFUNDED_ADDR_SK                            52
#define CR_RETURNING_CUSTOMER_SK                       53
#define CR_RETURNING_CDEMO_SK                          54
#define CR_RETURNING_HDEMO_SK                          55
#define CR_RETURNING_ADDR_SK                           56
#define CR_CALL_CENTER_SK                              57
#define CR_CATALOG_PAGE_SK                             58
#define CR_SHIP_MODE_SK                                59
#define CR_WAREHOUSE_SK                                60
#define CR_REASON_SK                                   61
#define CR_ORDER_NUMBER                                62
#define CR_PRICING_QUANTITY                            63
#define CR_PRICING_NET_PAID                            64
#define CR_PRICING_EXT_TAX                             65
#define CR_PRICING_NET_PAID_INC_TAX                    66
#define CR_PRICING_FEE                                 67
#define CR_PRICING_EXT_SHIP_COST                       68
#define CR_PRICING_REFUNDED_CASH                       69
#define CR_PRICING_REVERSED_CHARGE                     70
#define CR_PRICING_STORE_CREDIT                        71
#define CR_PRICING_NET_LOSS                            72
#define CR_NULLS                                       73
#define CR_PRICING                                     74
#define CATALOG_RETURNS_END                            74
#define CATALOG_SALES_START                            75
#define CS_SOLD_DATE_SK                                75
#define CS_SOLD_TIME_SK                                76
#define CS_SHIP_DATE_SK                                77
#define CS_BILL_CUSTOMER_SK                            78
#define CS_BILL_CDEMO_SK                               79
#define CS_BILL_HDEMO_SK                               80
#define CS_BILL_ADDR_SK                                81
#define CS_SHIP_CUSTOMER_SK                            82
#define CS_SHIP_CDEMO_SK                               83
#define CS_SHIP_HDEMO_SK                               84
#define CS_SHIP_ADDR_SK                                85
#define CS_CALL_CENTER_SK                              86
#define CS_CATALOG_PAGE_SK                             87
#define CS_SHIP_MODE_SK                                88
#define CS_WAREHOUSE_SK                                89
#define CS_SOLD_ITEM_SK                                90
#define CS_PROMO_SK                                    91
#define CS_ORDER_NUMBER                                92
#define CS_PRICING_QUANTITY                            93
#define CS_PRICING_WHOLESALE_COST                      94
#define CS_PRICING_LIST_PRICE                          95
#define CS_PRICING_SALES_PRICE                         96
#define CS_PRICING_COUPON_AMT                          97
#define CS_PRICING_EXT_SALES_PRICE                     98
#define CS_PRICING_EXT_DISCOUNT_AMOUNT                 99
#define CS_PRICING_EXT_WHOLESALE_COST                  100
#define CS_PRICING_EXT_LIST_PRICE                      101
#define CS_PRICING_EXT_TAX                             102
#define CS_PRICING_EXT_SHIP_COST                       103
#define CS_PRICING_NET_PAID                            104
#define CS_PRICING_NET_PAID_INC_TAX                    105
#define CS_PRICING_NET_PAID_INC_SHIP                   106
#define CS_PRICING_NET_PAID_INC_SHIP_TAX               107
#define CS_PRICING_NET_PROFIT                          108
#define CS_PRICING                                     109
#define CS_PERMUTE                                     110
#define CS_NULLS                                       111
#define CR_IS_RETURNED                                 112
#define CS_PERMUTATION                                 113
#define CATALOG_SALES_END                              113
#define CUSTOMER_START                                 114
#define C_CUSTOMER_SK                                  114
#define C_CUSTOMER_ID                                  115
#define C_CURRENT_CDEMO_SK                             116
#define C_CURRENT_HDEMO_SK                             117
#define C_CURRENT_ADDR_SK                              118
#define C_FIRST_SHIPTO_DATE_ID                         119
#define C_FIRST_SALES_DATE_ID                          120
#define C_SALUTATION                                   121
#define C_FIRST_NAME                                   122
#define C_LAST_NAME                                    123
#define C_PREFERRED_CUST_FLAG                          124
#define C_BIRTH_DAY                                    125
#define C_BIRTH_MONTH                                  126
#define C_BIRTH_YEAR                                   127
#define C_BIRTH_COUNTRY                                128
#define C_LOGIN                                        129
#define C_EMAIL_ADDRESS                                130
#define C_LAST_REVIEW_DATE                             131
#define C_NULLS                                        132
#define CUSTOMER_END                                   132
#define CUSTOMER_ADDRESS_START                         133
#define CA_ADDRESS_SK                                  133
#define CA_ADDRESS_ID                                  134
#define CA_ADDRESS_STREET_NUM                          135
#define CA_ADDRESS_STREET_NAME1                        136
#define CA_ADDRESS_STREET_TYPE                         137
#define CA_ADDRESS_SUITE_NUM                           138
#define CA_ADDRESS_CITY                                139
#define CA_ADDRESS_COUNTY                              140
#define CA_ADDRESS_STATE                               141
#define CA_ADDRESS_ZIP                                 142
#define CA_ADDRESS_COUNTRY                             143
#define CA_ADDRESS_GMT_OFFSET                          144
#define CA_LOCATION_TYPE                               145
#define CA_NULLS                                       146
#define CA_ADDRESS                                     147
#define CA_ADDRESS_STREET_NAME2                        148
#define CUSTOMER_ADDRESS_END                           148
#define CUSTOMER_DEMOGRAPHICS_START                    149
#define CD_DEMO_SK                                     149
#define CD_GENDER                                      150
#define CD_MARITAL_STATUS                              151
#define CD_EDUCATION_STATUS                            152
#define CD_PURCHASE_ESTIMATE                           153
#define CD_CREDIT_RATING                               154
#define CD_DEP_COUNT                                   155
#define CD_DEP_EMPLOYED_COUNT                          156
#define CD_DEP_COLLEGE_COUNT                           157
#define CD_NULLS                                       158
#define CUSTOMER_DEMOGRAPHICS_END                      158
#define DATE_START                                     159
#define D_DATE_SK                                      159
#define D_DATE_ID                                      160
#define D_DATE                                         161
#define D_MONTH_SEQ                                    162
#define D_WEEK_SEQ                                     163
#define D_QUARTER_SEQ                                  164
#define D_YEAR                                         165
#define D_DOW                                          166
#define D_MOY                                          167
#define D_DOM                                          168
#define D_QOY                                          169
#define D_FY_YEAR                                      170
#define D_FY_QUARTER_SEQ                               171
#define D_FY_WEEK_SEQ                                  172
#define D_DAY_NAME                                     173
#define D_QUARTER_NAME                                 174
#define D_HOLIDAY                                      175
#define D_WEEKEND                                      176
#define D_FOLLOWING_HOLIDAY                            177
#define D_FIRST_DOM                                    178
#define D_LAST_DOM                                     179
#define D_SAME_DAY_LY                                  180
#define D_SAME_DAY_LQ                                  181
#define D_CURRENT_DAY                                  182
#define D_CURRENT_WEEK                                 183
#define D_CURRENT_MONTH                                184
#define D_CURRENT_QUARTER                              185
#define D_CURRENT_YEAR                                 186
#define D_NULLS                                        187
#define DATE_END                                       187
#define HOUSEHOLD_DEMOGRAPHICS_START                   188
#define HD_DEMO_SK                                     188
#define HD_INCOME_BAND_ID                              189
#define HD_BUY_POTENTIAL                               190
#define HD_DEP_COUNT                                   191
#define HD_VEHICLE_COUNT                               192
#define HD_NULLS                                       193
#define HOUSEHOLD_DEMOGRAPHICS_END                     193
#define INCOME_BAND_START                              194
#define IB_INCOME_BAND_ID                              194
#define IB_LOWER_BOUND                                 195
#define IB_UPPER_BOUND                                 196
#define IB_NULLS                                       197
#define INCOME_BAND_END                                197
#define INVENTORY_START                                198
#define INV_DATE_SK                                    198
#define INV_ITEM_SK                                    199
#define INV_WAREHOUSE_SK                               200
#define INV_QUANTITY_ON_HAND                           201
#define INV_NULLS                                      202
#define INVENTORY_END                                  202
#define ITEM_START                                     203
#define I_ITEM_SK                                      203
#define I_ITEM_ID                                      204
#define I_REC_START_DATE_ID                            205
#define I_REC_END_DATE_ID                              206
#define I_ITEM_DESC                                    207
#define I_CURRENT_PRICE                                208
#define I_WHOLESALE_COST                               209
#define I_BRAND_ID                                     210
#define I_BRAND                                        211
#define I_CLASS_ID                                     212
#define I_CLASS                                        213
#define I_CATEGORY_ID                                  214
#define I_CATEGORY                                     215
#define I_MANUFACT_ID                                  216
#define I_MANUFACT                                     217
#define I_SIZE                                         218
#define I_FORMULATION                                  219
#define I_COLOR                                        220
#define I_UNITS                                        221
#define I_CONTAINER                                    222
#define I_MANAGER_ID                                   223
#define I_PRODUCT_NAME                                 224
#define I_NULLS                                        225
#define I_SCD                                          226
#define I_PROMO_SK                                     227
#define ITEM_END                                       227
#define PROMOTION_START                                228
#define P_PROMO_SK                                     228
#define P_PROMO_ID                                     229
#define P_START_DATE_ID                                230
#define P_END_DATE_ID                                  231
#define P_ITEM_SK                                      232
#define P_COST                                         233
#define P_RESPONSE_TARGET                              234
#define P_PROMO_NAME                                   235
#define P_CHANNEL_DMAIL                                236
#define P_CHANNEL_EMAIL                                237
#define P_CHANNEL_CATALOG                              238
#define P_CHANNEL_TV                                   239
#define P_CHANNEL_RADIO                                240
#define P_CHANNEL_PRESS                                241
#define P_CHANNEL_EVENT                                242
#define P_CHANNEL_DEMO                                 243
#define P_CHANNEL_DETAILS                              244
#define P_PURPOSE                                      245
#define P_DISCOUNT_ACTIVE                              246
#define P_NULLS                                        247
#define PROMOTION_END                                  247
#define REASON_START                                   248
#define R_REASON_SK                                    248
#define R_REASON_ID                                    249
#define R_REASON_DESCRIPTION                           250
#define R_NULLS                                        251
#define REASON_END                                     251
#define SHIP_MODE_START                                252
#define SM_SHIP_MODE_SK                                252
#define SM_SHIP_MODE_ID                                253
#define SM_TYPE                                        254
#define SM_CODE                                        255
#define SM_CONTRACT                                    256
#define SM_CARRIER                                     257
#define SM_NULLS                                       258
#define SHIP_MODE_END                                  258
#define STORE_START                                    259
#define W_STORE_SK                                     259
#define W_STORE_ID                                     260
#define W_STORE_REC_START_DATE_ID                      261
#define W_STORE_REC_END_DATE_ID                        262
#define W_STORE_CLOSED_DATE_ID                         263
#define W_STORE_NAME                                   264
#define W_STORE_EMPLOYEES                              265
#define W_STORE_FLOOR_SPACE                            266
#define W_STORE_HOURS                                  267
#define W_STORE_MANAGER                                268
#define W_STORE_MARKET_ID                              269
#define W_STORE_TAX_PERCENTAGE                         270
#define W_STORE_GEOGRAPHY_CLASS                        271
#define W_STORE_MARKET_DESC                            272
#define W_STORE_MARKET_MANAGER                         273
#define W_STORE_DIVISION_ID                            274
#define W_STORE_DIVISION_NAME                          275
#define W_STORE_COMPANY_ID                             276
#define W_STORE_COMPANY_NAME                           277
#define W_STORE_ADDRESS_STREET_NUM                     278
#define W_STORE_ADDRESS_STREET_NAME1                   279
#define W_STORE_ADDRESS_STREET_TYPE                    280
#define W_STORE_ADDRESS_SUITE_NUM                      281
#define W_STORE_ADDRESS_CITY                           282
#define W_STORE_ADDRESS_COUNTY                         283
#define W_STORE_ADDRESS_STATE                          284
#define W_STORE_ADDRESS_ZIP                            285
#define W_STORE_ADDRESS_COUNTRY                        286
#define W_STORE_ADDRESS_GMT_OFFSET                     287
#define W_STORE_NULLS                                  288
#define W_STORE_TYPE                                   289
#define W_STORE_SCD                                    290
#define W_STORE_ADDRESS                                291
#define STORE_END                                      291
#define STORE_RETURNS_START                            292
#define SR_RETURNED_DATE_SK                            292
#define SR_RETURNED_TIME_SK                            293
#define SR_ITEM_SK                                     294
#define SR_CUSTOMER_SK                                 295
#define SR_CDEMO_SK                                    296
#define SR_HDEMO_SK                                    297
#define SR_ADDR_SK                                     298
#define SR_STORE_SK                                    299
#define SR_REASON_SK                                   300
#define SR_TICKET_NUMBER                               301
#define SR_PRICING_QUANTITY                            302
#define SR_PRICING_NET_PAID                            303
#define SR_PRICING_EXT_TAX                             304
#define SR_PRICING_NET_PAID_INC_TAX                    305
#define SR_PRICING_FEE                                 306
#define SR_PRICING_EXT_SHIP_COST                       307
#define SR_PRICING_REFUNDED_CASH                       308
#define SR_PRICING_REVERSED_CHARGE                     309
#define SR_PRICING_STORE_CREDIT                        310
#define SR_PRICING_NET_LOSS                            311
#define SR_PRICING                                     312
#define SR_NULLS                                       313
#define STORE_RETURNS_END                              313
#define STORE_SALES_START                              314
#define SS_SOLD_DATE_SK                                314
#define SS_SOLD_TIME_SK                                315
#define SS_SOLD_ITEM_SK                                316
#define SS_SOLD_CUSTOMER_SK                            317
#define SS_SOLD_CDEMO_SK                               318
#define SS_SOLD_HDEMO_SK                               319
#define SS_SOLD_ADDR_SK                                320
#define SS_SOLD_STORE_SK                               321
#define SS_SOLD_PROMO_SK                               322
#define SS_TICKET_NUMBER                               323
#define SS_PRICING_QUANTITY                            324
#define SS_PRICING_WHOLESALE_COST                      325
#define SS_PRICING_LIST_PRICE                          326
#define SS_PRICING_SALES_PRICE                         327
#define SS_PRICING_COUPON_AMT                          328
#define SS_PRICING_EXT_SALES_PRICE                     329
#define SS_PRICING_EXT_WHOLESALE_COST                  330
#define SS_PRICING_EXT_LIST_PRICE                      331
#define SS_PRICING_EXT_TAX                             332
#define SS_PRICING_NET_PAID                            333
#define SS_PRICING_NET_PAID_INC_TAX                    334
#define SS_PRICING_NET_PROFIT                          335
#define SR_IS_RETURNED                                 336
#define SS_PRICING                                     337
#define SS_NULLS                                       338
#define SS_PERMUTATION                                 339
#define STORE_SALES_END                                339
#define TIME_START                                     340
#define T_TIME_SK                                      340
#define T_TIME_ID                                      341
#define T_TIME                                         342
#define T_HOUR                                         343
#define T_MINUTE                                       344
#define T_SECOND                                       345
#define T_AM_PM                                        346
#define T_SHIFT                                        347
#define T_SUB_SHIFT                                    348
#define T_MEAL_TIME                                    349
#define T_NULLS                                        350
#define TIME_END                                       350
#define WAREHOUSE_START                                351
#define W_WAREHOUSE_SK                                 351
#define W_WAREHOUSE_ID                                 352
#define W_WAREHOUSE_NAME                               353
#define W_WAREHOUSE_SQ_FT                              354
#define W_ADDRESS_STREET_NUM                           355
#define W_ADDRESS_STREET_NAME1                         356
#define W_ADDRESS_STREET_TYPE                          357
#define W_ADDRESS_SUITE_NUM                            358
#define W_ADDRESS_CITY                                 359
#define W_ADDRESS_COUNTY                               360
#define W_ADDRESS_STATE                                361
#define W_ADDRESS_ZIP                                  362
#define W_ADDRESS_COUNTRY                              363
#define W_ADDRESS_GMT_OFFSET                           364
#define W_NULLS                                        365
#define W_WAREHOUSE_ADDRESS                            366
#define WAREHOUSE_END                                  366
#define WEB_PAGE_START                                 367
#define WP_PAGE_SK                                     367
#define WP_PAGE_ID                                     368
#define WP_REC_START_DATE_ID                           369
#define WP_REC_END_DATE_ID                             370
#define WP_CREATION_DATE_SK                            371
#define WP_ACCESS_DATE_SK                              372
#define WP_AUTOGEN_FLAG                                373
#define WP_CUSTOMER_SK                                 374
#define WP_URL                                         375
#define WP_TYPE                                        376
#define WP_CHAR_COUNT                                  377
#define WP_LINK_COUNT                                  378
#define WP_IMAGE_COUNT                                 379
#define WP_MAX_AD_COUNT                                380
#define WP_NULLS                                       381
#define WP_SCD                                         382
#define WEB_PAGE_END                                   382
#define WEB_RETURNS_START                              383
#define WR_RETURNED_DATE_SK                            383
#define WR_RETURNED_TIME_SK                            384
#define WR_ITEM_SK                                     385
#define WR_REFUNDED_CUSTOMER_SK                        386
#define WR_REFUNDED_CDEMO_SK                           387
#define WR_REFUNDED_HDEMO_SK                           388
#define WR_REFUNDED_ADDR_SK                            389
#define WR_RETURNING_CUSTOMER_SK                       390
#define WR_RETURNING_CDEMO_SK                          391
#define WR_RETURNING_HDEMO_SK                          392
#define WR_RETURNING_ADDR_SK                           393
#define WR_WEB_PAGE_SK                                 394
#define WR_REASON_SK                                   395
#define WR_ORDER_NUMBER                                396
#define WR_PRICING_QUANTITY                            397
#define WR_PRICING_NET_PAID                            398
#define WR_PRICING_EXT_TAX                             399
#define WR_PRICING_NET_PAID_INC_TAX                    400
#define WR_PRICING_FEE                                 401
#define WR_PRICING_EXT_SHIP_COST                       402
#define WR_PRICING_REFUNDED_CASH                       403
#define WR_PRICING_REVERSED_CHARGE                     404
#define WR_PRICING_STORE_CREDIT                        405
#define WR_PRICING_NET_LOSS                            406
#define WR_PRICING                                     407
#define WR_NULLS                                       408
#define WEB_RETURNS_END                                408
#define WEB_SALES_START                                409
#define WS_SOLD_DATE_SK                                409
#define WS_SOLD_TIME_SK                                410
#define WS_SHIP_DATE_SK                                411
#define WS_ITEM_SK                                     412
#define WS_BILL_CUSTOMER_SK                            413
#define WS_BILL_CDEMO_SK                               414
#define WS_BILL_HDEMO_SK                               415
#define WS_BILL_ADDR_SK                                416
#define WS_SHIP_CUSTOMER_SK                            417
#define WS_SHIP_CDEMO_SK                               418
#define WS_SHIP_HDEMO_SK                               419
#define WS_SHIP_ADDR_SK                                420
#define WS_WEB_PAGE_SK                                 421
#define WS_WEB_SITE_SK                                 422
#define WS_SHIP_MODE_SK                                423
#define WS_WAREHOUSE_SK                                424
#define WS_PROMO_SK                                    425
#define WS_ORDER_NUMBER                                426
#define WS_PRICING_QUANTITY                            427
#define WS_PRICING_WHOLESALE_COST                      428
#define WS_PRICING_LIST_PRICE                          429
#define WS_PRICING_SALES_PRICE                         430
#define WS_PRICING_EXT_DISCOUNT_AMT                    431
#define WS_PRICING_EXT_SALES_PRICE                     432
#define WS_PRICING_EXT_WHOLESALE_COST                  433
#define WS_PRICING_EXT_LIST_PRICE                      434
#define WS_PRICING_EXT_TAX                             435
#define WS_PRICING_COUPON_AMT                          436
#define WS_PRICING_EXT_SHIP_COST                       437
#define WS_PRICING_NET_PAID                            438
#define WS_PRICING_NET_PAID_INC_TAX                    439
#define WS_PRICING_NET_PAID_INC_SHIP                   440
#define WS_PRICING_NET_PAID_INC_SHIP_TAX               441
#define WS_PRICING_NET_PROFIT                          442
#define WS_PRICING                                     443
#define WS_NULLS                                       444
#define WR_IS_RETURNED                                 445
#define WS_PERMUTATION                                 446
#define WEB_SALES_END                                  446
#define WEB_SITE_START                                 447
#define WEB_SITE_SK                                    447
#define WEB_SITE_ID                                    448
#define WEB_REC_START_DATE_ID                          449
#define WEB_REC_END_DATE_ID                            450
#define WEB_NAME                                       451
#define WEB_OPEN_DATE                                  452
#define WEB_CLOSE_DATE                                 453
#define WEB_CLASS                                      454
#define WEB_MANAGER                                    455
#define WEB_MARKET_ID                                  456
#define WEB_MARKET_CLASS                               457
#define WEB_MARKET_DESC                                458
#define WEB_MARKET_MANAGER                             459
#define WEB_COMPANY_ID                                 460
#define WEB_COMPANY_NAME                               461
#define WEB_ADDRESS_STREET_NUM                         462
#define WEB_ADDRESS_STREET_NAME1                       463
#define WEB_ADDRESS_STREET_TYPE                        464
#define WEB_ADDRESS_SUITE_NUM                          465
#define WEB_ADDRESS_CITY                               466
#define WEB_ADDRESS_COUNTY                             467
#define WEB_ADDRESS_STATE                              468
#define WEB_ADDRESS_ZIP                                469
#define WEB_ADDRESS_COUNTRY                            470
#define WEB_ADDRESS_GMT_OFFSET                         471
#define WEB_TAX_PERCENTAGE                             472
#define WEB_NULLS                                      473
#define WEB_ADDRESS                                    474
#define WEB_SCD                                        475
#define WEB_SITE_END                                   475
#define DBGEN_VERSION_START                            476
#define DV_VERSION                                     476
#define DV_CREATE_DATE                                 477
#define DV_CREATE_TIME                                 478
#define DV_CMDLINE_ARGS                                479
#define VALIDATE_STREAM                                480
#define DBGEN_VERSION_END                              480
#define S_BRAND_START                                  481
#define S_BRAND_ID                                     481
#define S_BRAND_SUBCLASS_ID                            482
#define S_BRAND_MANAGER_ID                             483
#define S_BRAND_MANUFACTURER_ID                        484
#define S_BRAND_NAME                                   485
#define S_BRAND_END                                    485
#define S_CUSTOMER_ADDRESS_START                       486
#define S_CADR_ID                                      486
#define S_CADR_ADDRESS_STREET_NUMBER                   487
#define S_CADR_ADDRESS_STREET_NAME1                    488
#define S_CADR_ADDRESS_STREET_NAME2                    489
#define S_CADR_ADDRESS_STREET_TYPE                     490
#define S_CADR_ADDRESS_SUITE_NUM                       491
#define S_CADR_ADDRESS_CITY                            492
#define S_CADR_ADDRESS_COUNTY                          493
#define S_CADR_ADDRESS_STATE                           494
#define S_CADR_ADDRESS_ZIP                             495
#define S_CADR_ADDRESS_COUNTRY                         496
#define S_BADDR_ADDRESS                                497
#define S_CUSTOMER_ADDRESS_END                         497
#define S_CALL_CENTER_START                            498
#define S_CALL_CENTER_ID                               498
#define S_CALL_CENTER_DIVISION_ID                      499
#define S_CALL_CENTER_OPEN_DATE                        500
#define S_CALL_CENTER_CLOSED_DATE                      501
#define S_CALL_CENTER_NAME                             502
#define S_CALL_CENTER_CLASS                            503
#define S_CALL_CENTER_EMPLOYEES                        504
#define S_CALL_CENTER_SQFT                             505
#define S_CALL_CENTER_HOURS                            506
#define S_CALL_CENTER_MANAGER_ID                       507
#define S_CALL_CENTER_MARKET_ID                        508
#define S_CALL_CENTER_ADDRESS_ID                       509
#define S_CALL_CENTER_TAX_PERCENTAGE                   510
#define S_CALL_CENTER_SCD                              511
#define S_CALL_CENTER_END                              511
#define S_CATALOG_START                                512
#define S_CATALOG_NUMBER                               512
#define S_CATALOG_START_DATE                           513
#define S_CATALOG_END_DATE                             514
#define S_CATALOG_DESC                                 515
#define S_CATALOG_TYPE                                 516
#define S_CATALOG_END                                  516
#define S_CATALOG_ORDER_START                          517
#define S_CORD_ID                                      517
#define S_CORD_BILL_CUSTOMER_ID                        518
#define S_CORD_SHIP_CUSTOMER_ID                        519
#define S_CORD_ORDER_DATE                              520
#define S_CORD_ORDER_TIME                              521
#define S_CORD_SHIP_MODE_ID                            522
#define S_CORD_CALL_CENTER_ID                          523
#define S_CLIN_ITEM_ID                                 524
#define S_CORD_COMMENT                                 525
#define S_CATALOG_ORDER_END                            525
#define S_CATALOG_ORDER_LINEITEM_START                 526
#define S_CLIN_ORDER_ID                                526
#define S_CLIN_LINE_NUMBER                             527
#define S_CLIN_PROMOTION_ID                            528
#define S_CLIN_QUANTITY                                529
#define S_CLIN_COUPON_AMT                              530
#define S_CLIN_WAREHOUSE_ID                            531
#define S_CLIN_SHIP_DATE                               532
#define S_CLIN_CATALOG_ID                              533
#define S_CLIN_CATALOG_PAGE_ID                         534
#define S_CLIN_PRICING                                 535
#define S_CLIN_SHIP_COST                               536
#define S_CLIN_IS_RETURNED                             537
#define S_CLIN_PERMUTE                                 538
#define S_CATALOG_ORDER_LINEITEM_END                   538
#define S_CATALOG_PAGE_START                           539
#define S_CATALOG_PAGE_CATALOG_NUMBER                  539
#define S_CATALOG_PAGE_NUMBER                          540
#define S_CATALOG_PAGE_DEPARTMENT                      541
#define S_CP_ID                                        542
#define S_CP_START_DATE                                543
#define S_CP_END_DATE                                  544
#define S_CP_DESCRIPTION                               545
#define S_CP_TYPE                                      546
#define S_CATALOG_PAGE_END                             546
#define S_CATALOG_PROMOTIONAL_ITEM_START               547
#define S_CATALOG_PROMOTIONAL_ITEM_CATALOG_NUMBER      547
#define S_CATALOG_PROMOTIONAL_ITEM_CATALOG_PAGE_NUMBER 548
#define S_CATALOG_PROMOTIONAL_ITEM_ITEM_ID             549
#define S_CATALOG_PROMOTIONAL_ITEM_PROMOTION_ID        550
#define S_CATALOG_PROMOTIONAL_ITEM_END                 550
#define S_CATALOG_RETURNS_START                        551
#define S_CRET_CALL_CENTER_ID                          551
#define S_CRET_ORDER_ID                                552
#define S_CRET_LINE_NUMBER                             553
#define S_CRET_ITEM_ID                                 554
#define S_CRET_RETURN_CUSTOMER_ID                      555
#define S_CRET_REFUND_CUSTOMER_ID                      556
#define S_CRET_DATE                                    557
#define S_CRET_TIME                                    558
#define S_CRET_QUANTITY                                559
#define S_CRET_AMOUNT                                  560
#define S_CRET_TAX                                     561
#define S_CRET_FEE                                     562
#define S_CRET_SHIP_COST                               563
#define S_CRET_REFUNDED_CASH                           564
#define S_CRET_REVERSED_CHARGE                         565
#define S_CRET_MERCHANT_CREDIT                         566
#define S_CRET_REASON_ID                               567
#define S_CRET_PRICING                                 568
#define S_CRET_SHIPMODE_ID                             569
#define S_CRET_WAREHOUSE_ID                            570
#define S_CRET_CATALOG_PAGE_ID                         571
#define S_CATALOG_RETURNS_END                          571
#define S_CATEGORY_START                               572
#define S_CATEGORY_ID                                  572
#define S_CATEGORY_NAME                                573
#define S_CATEGORY_DESC                                574
#define S_CATEGORY_END                                 574
#define S_CLASS_START                                  575
#define S_CLASS_ID                                     575
#define S_CLASS_SUBCAT_ID                              576
#define S_CLASS_DESC                                   577
#define S_CLASS_END                                    577
#define S_COMPANY_START                                578
#define S_COMPANY_ID                                   578
#define S_COMPANY_NAME                                 579
#define S_COMPANY_END                                  579
#define S_CUSTOMER_START                               580
#define S_CUST_ID                                      580
#define S_CUST_SALUTATION                              581
#define S_CUST_LAST_NAME                               582
#define S_CUST_FIRST_NAME                              583
#define S_CUST_PREFERRED_FLAG                          584
#define S_CUST_BIRTH_DATE                              585
#define S_CUST_FIRST_PURCHASE_DATE                     586
#define S_CUST_FIRST_SHIPTO_DATE                       587
#define S_CUST_BIRTH_COUNTRY                           588
#define S_CUST_LOGIN                                   589
#define S_CUST_EMAIL                                   590
#define S_CUST_LAST_LOGIN                              591
#define S_CUST_LAST_REVIEW                             592
#define S_CUST_PRIMARY_MACHINE                         593
#define S_CUST_SECONDARY_MACHINE                       594
#define S_CUST_ADDRESS                                 595
#define S_CUST_ADDRESS_STREET_NUM                      596
#define S_CUST_ADDRESS_STREET_NAME1                    597
#define S_CUST_ADDRESS_STREET_NAME2                    598
#define S_CUST_ADDRESS_STREET_TYPE                     599
#define S_CUST_ADDRESS_SUITE_NUM                       600
#define S_CUST_ADDRESS_CITY                            601
#define S_CUST_ADDRESS_ZIP                             602
#define S_CUST_ADDRESS_COUNTY                          603
#define S_CUST_ADDRESS_STATE                           604
#define S_CUST_ADDRESS_COUNTRY                         605
#define S_CUST_LOCATION_TYPE                           606
#define S_CUST_GENDER                                  607
#define S_CUST_MARITAL_STATUS                          608
#define S_CUST_EDUCATION                               609
#define S_CUST_CREDIT_RATING                           610
#define S_CUST_PURCHASE_ESTIMATE                       611
#define S_CUST_BUY_POTENTIAL                           612
#define S_CUST_DEPENDENT_CNT                           613
#define S_CUST_EMPLOYED_CNT                            614
#define S_CUST_COLLEGE_CNT                             615
#define S_CUST_VEHICLE_CNT                             616
#define S_CUST_INCOME                                  617
#define S_CUSTOMER_END                                 617
#define S_DIVISION_START                               618
#define S_DIVISION_ID                                  618
#define S_DIVISION_COMPANY                             619
#define S_DIVISION_NAME                                620
#define S_DIVISION_END                                 620
#define S_INVENTORY_START                              621
#define S_INVN_WAREHOUSE                               621
#define S_INVN_ITEM                                    622
#define S_INVN_DATE                                    623
#define S_INVN_QUANTITY                                624
#define S_INVENTORY_END                                624
#define S_ITEM_START                                   625
#define S_ITEM_ID                                      625
#define S_ITEM_PERMUTE                                 626
#define S_ITEM_PRODUCT_ID                              627
#define S_ITEM_DESC                                    628
#define S_ITEM_LIST_PRICE                              629
#define S_ITEM_WHOLESALE_COST                          630
#define S_ITEM_MANAGER_ID                              631
#define S_ITEM_SIZE                                    632
#define S_ITEM_FORMULATION                             633
#define S_ITEM_FLAVOR                                  634
#define S_ITEM_UNITS                                   635
#define S_ITEM_CONTAINER                               636
#define S_ITEM_SCD                                     637
#define S_ITEM_END                                     637
#define S_MANAGER_START                                638
#define S_MANAGER_ID                                   638
#define S_MANAGER_NAME                                 639
#define S_MANAGER_END                                  639
#define S_MANUFACTURER_START                           640
#define S_MANUFACTURER_ID                              640
#define S_MANUFACTURER_NAME                            641
#define S_MANUFACTURER_END                             641
#define S_MARKET_START                                 642
#define S_MARKET_ID                                    642
#define S_MARKET_CLASS_NAME                            643
#define S_MARKET_DESC                                  644
#define S_MARKET_MANAGER_ID                            645
#define S_MARKET_END                                   645
#define S_PRODUCT_START                                646
#define S_PRODUCT_ID                                   646
#define S_PRODUCT_BRAND_ID                             647
#define S_PRODUCT_NAME                                 648
#define S_PRODUCT_TYPE                                 649
#define S_PRODUCT_END                                  649
#define S_PROMOTION_START                              650
#define S_PROMOTION_ID                                 650
#define S_PROMOTION_ITEM_ID                            651
#define S_PROMOTION_START_DATE                         652
#define S_PROMOTION_END_DATE                           653
#define S_PROMOTION_COST                               654
#define S_PROMOTION_RESPONSE_TARGET                    655
#define S_PROMOTION_DMAIL                              656
#define S_PROMOTION_EMAIL                              657
#define S_PROMOTION_CATALOG                            658
#define S_PROMOTION_TV                                 659
#define S_PROMOTION_RADIO                              660
#define S_PROMOTION_PRESS                              661
#define S_PROMOTION_EVENT                              662
#define S_PROMOTION_DEMO                               663
#define S_PROMOTION_DETAILS                            664
#define S_PROMOTION_PURPOSE                            665
#define S_PROMOTION_DISCOUNT_ACTIVE                    666
#define S_PROMOTION_DISCOUNT_PCT                       667
#define S_PROMOTION_NAME                               668
#define S_PROMOTION_BITFIELD                           669
#define S_PROMOTION_END                                669
#define S_PURCHASE_START                               670
#define S_PURCHASE_ID                                  670
#define S_PURCHASE_STORE_ID                            671
#define S_PURCHASE_CUSTOMER_ID                         672
#define S_PURCHASE_DATE                                673
#define S_PURCHASE_TIME                                674
#define S_PURCHASE_REGISTER                            675
#define S_PURCHASE_CLERK                               676
#define S_PURCHASE_COMMENT                             677
#define S_PURCHASE_PRICING                             678
#define S_PLINE_ITEM_ID                                679
#define S_PURCHASE_END                                 679
#define S_PURCHASE_LINEITEM_START                      680
#define S_PLINE_PURCHASE_ID                            680
#define S_PLINE_NUMBER                                 681
#define S_PLINE_PROMOTION_ID                           682
#define S_PLINE_SALE_PRICE                             683
#define S_PLINE_QUANTITY                               684
#define S_PLINE_COUPON_AMT                             685
#define S_PLINE_COMMENT                                686
#define S_PLINE_PRICING                                687
#define S_PLINE_IS_RETURNED                            688
#define S_PLINE_PERMUTE                                689
#define S_PURCHASE_LINEITEM_END                        689
#define S_REASON_START                                 690
#define S_REASON_ID                                    690
#define S_REASON_DESC                                  691
#define S_REASON_END                                   691
#define S_STORE_START                                  692
#define S_STORE_ID                                     692
#define S_STORE_ADDRESS_ID                             693
#define S_STORE_DIVISION_ID                            694
#define S_STORE_OPEN_DATE                              695
#define S_STORE_CLOSE_DATE                             696
#define S_STORE_NAME                                   697
#define S_STORE_CLASS                                  698
#define S_STORE_EMPLOYEES                              699
#define S_STORE_FLOOR_SPACE                            700
#define S_STORE_HOURS                                  701
#define S_STORE_MARKET_MANAGER_ID                      702
#define S_STORE_MANAGER_ID                             703
#define S_STORE_MARKET_ID                              704
#define S_STORE_GEOGRAPHY_CLASS                        705
#define S_STORE_TAX_PERCENTAGE                         706
#define S_STORE_END                                    706
#define S_STORE_PROMOTIONAL_ITEM_START                 707
#define S_SITM_PROMOTION_ID                            707
#define S_SITM_ITEM_ID                                 708
#define S_SITM_STORE_ID                                709
#define S_STORE_PROMOTIONAL_ITEM_END                   709
#define S_STORE_RETURNS_START                          710
#define S_SRET_STORE_ID                                710
#define S_SRET_PURCHASE_ID                             711
#define S_SRET_LINENUMBER                              712
#define S_SRET_ITEM_ID                                 713
#define S_SRET_CUSTOMER_ID                             714
#define S_SRET_RETURN_DATE                             715
#define S_SRET_RETURN_TIME                             716
#define S_SRET_TICKET_NUMBER                           717
#define S_SRET_RETURN_QUANTITY                         718
#define S_SRET_RETURN_AMT                              719
#define S_SRET_RETURN_TAX                              720
#define S_SRET_RETURN_FEE                              721
#define S_SRET_RETURN_SHIP_COST                        722
#define S_SRET_REFUNDED_CASH                           723
#define S_SRET_REVERSED_CHARGE                         724
#define S_SRET_MERCHANT_CREDIT                         725
#define S_SRET_REASON_ID                               726
#define S_SRET_PRICING                                 727
#define S_STORE_RETURNS_END                            727
#define S_SUBCATEGORY_START                            728
#define S_SBCT_ID                                      728
#define S_SBCT_CATEGORY_ID                             729
#define S_SBCT_NAME                                    730
#define S_SBCT_DESC                                    731
#define S_SUBCATEGORY_END                              731
#define S_SUBCLASS_START                               732
#define S_SUBC_ID                                      732
#define S_SUBC_CLASS_ID                                733
#define S_SUBC_NAME                                    734
#define S_SUBC_DESC                                    735
#define S_SUBCLASS_END                                 735
#define S_WAREHOUSE_START                              736
#define S_WRHS_ID                                      736
#define S_WRHS_DESC                                    737
#define S_WRHS_SQFT                                    738
#define S_WRHS_ADDRESS_ID                              739
#define S_WAREHOUSE_END                                739
#define S_WEB_ORDER_START                              740
#define S_WORD_ID                                      740
#define S_WORD_BILL_CUSTOMER_ID                        741
#define S_WORD_SHIP_CUSTOMER_ID                        742
#define S_WORD_ORDER_DATE                              743
#define S_WORD_ORDER_TIME                              744
#define S_WORD_SHIP_MODE_ID                            745
#define S_WORD_WEB_SITE_ID                             746
#define S_WORD_COMMENT                                 747
#define S_WLIN_ITEM_ID                                 748
#define S_WEB_ORDER_END                                748
#define S_WEB_ORDER_LINEITEM_START                     749
#define S_WLIN_ID                                      749
#define S_WLIN_LINE_NUMBER                             750
#define S_WLIN_PROMOTION_ID                            751
#define S_WLIN_QUANTITY                                752
#define S_WLIN_COUPON_AMT                              753
#define S_WLIN_WAREHOUSE_ID                            754
#define S_WLIN_SHIP_DATE                               755
#define S_WLIN_WEB_PAGE_ID                             756
#define S_WLIN_PRICING                                 757
#define S_WLIN_SHIP_COST                               758
#define S_WLIN_IS_RETURNED                             759
#define S_WLIN_PERMUTE                                 760
#define S_WEB_ORDER_LINEITEM_END                       760
#define S_WEB_PAGE_START                               761
#define S_WPAG_SITE_ID                                 761
#define S_WPAG_ID                                      762
#define S_WPAG_CREATE_DATE                             763
#define S_WPAG_ACCESS_DATE                             764
#define S_WPAG_AUTOGEN_FLAG                            765
#define S_WPAG_DEPARTMENT                              766
#define S_WPAG_URL                                     767
#define S_WPAG_TYPE                                    768
#define S_WPAG_CHAR_CNT                                769
#define S_WPAG_LINK_CNT                                770
#define S_WPAG_IMAGE_CNT                               771
#define S_WPAG_MAX_AD_CNT                              772
#define S_WPAG_PERMUTE                                 773
#define S_WEB_PAGE_END                                 773
#define S_WEB_PROMOTIONAL_ITEM_START                   774
#define S_WITM_SITE_ID                                 774
#define S_WITM_PAGE_ID                                 775
#define S_WITM_ITEM_ID                                 776
#define S_WITM_PROMOTION_ID                            777
#define S_WEB_PROMOTIONAL_ITEM_END                     777
#define S_WEB_RETURNS_START                            778
#define S_WRET_SITE_ID                                 778
#define S_WRET_ORDER_ID                                779
#define S_WRET_LINE_NUMBER                             780
#define S_WRET_ITEM_ID                                 781
#define S_WRET_RETURN_CUST_ID                          782
#define S_WRET_REFUND_CUST_ID                          783
#define S_WRET_RETURN_DATE                             784
#define S_WRET_RETURN_TIME                             785
#define S_WRET_REASON_ID                               786
#define S_WRET_PRICING                                 787
#define S_WEB_RETURNS_END                              787
#define S_WEB_SITE_START                               788
#define S_WSIT_ID                                      788
#define S_WSIT_OPEN_DATE                               789
#define S_WSIT_CLOSE_DATE                              790
#define S_WSIT_NAME                                    791
#define S_WSIT_ADDRESS_ID                              792
#define S_WSIT_DIVISION_ID                             793
#define S_WSIT_CLASS                                   794
#define S_WSIT_MANAGER_ID                              795
#define S_WSIT_MARKET_ID                               796
#define S_WSIT_TAX_PERCENTAGE                          797
#define S_WEB_SITE_END                                 797
#define S_ZIPG_START                                   798
#define S_ZIPG_ZIP                                     798
#define S_ZIPG_GMT                                     799
#define S_ZIPG_END                                     799
#define MAX_COLUMN                                     799
#endif

} // __columns__


// init.h

namespace __init__ {

/*
 * Legal Notice
 *
 * This document and associated source code (the "Work") is a part of a
 * benchmark specification maintained by the TPC.
 *
 * The TPC reserves all right, title, and interest to the Work as provided
 * under U.S. and international laws, including without limitation all patent
 * and trademark rights therein.
 *
 * No Warranty
 *
 * 1.1 TO THE MAXIMUM EXTENT PERMITTED BY APPLICABLE LAW, THE INFORMATION
 *     CONTAINED HEREIN IS PROVIDED "AS IS" AND WITH ALL FAULTS, AND THE
 *     AUTHORS AND DEVELOPERS OF THE WORK HEREBY DISCLAIM ALL OTHER
 *     WARRANTIES AND CONDITIONS, EITHER EXPRESS, IMPLIED OR STATUTORY,
 *     INCLUDING, BUT NOT LIMITED TO, ANY (IF ANY) IMPLIED WARRANTIES,
 *     DUTIES OR CONDITIONS OF MERCHANTABILITY, OF FITNESS FOR A PARTICULAR
 *     PURPOSE, OF ACCURACY OR COMPLETENESS OF RESPONSES, OF RESULTS, OF
 *     WORKMANLIKE EFFORT, OF LACK OF VIRUSES, AND OF LACK OF NEGLIGENCE.
 *     ALSO, THERE IS NO WARRANTY OR CONDITION OF TITLE, QUIET ENJOYMENT,
 *     QUIET POSSESSION, CORRESPONDENCE TO DESCRIPTION OR NON-INFRINGEMENT
 *     WITH REGARD TO THE WORK.
 * 1.2 IN NO EVENT WILL ANY AUTHOR OR DEVELOPER OF THE WORK BE LIABLE TO
 *     ANY OTHER PARTY FOR ANY DAMAGES, INCLUDING BUT NOT LIMITED TO THE
 *     COST OF PROCURING SUBSTITUTE GOODS OR SERVICES, LOST PROFITS, LOSS
 *     OF USE, LOSS OF DATA, OR ANY INCIDENTAL, CONSEQUENTIAL, DIRECT,
 *     INDIRECT, OR SPECIAL DAMAGES WHETHER UNDER CONTRACT, TORT, WARRANTY,
 *     OR OTHERWISE, ARISING IN ANY WAY OUT OF THIS OR ANY OTHER AGREEMENT
 *     RELATING TO THE WORK, WHETHER OR NOT SUCH AUTHOR OR DEVELOPER HAD
 *     ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES.
 *
 * Contributors:
 * Gradient Systems
 */

#ifndef DS_INIT_H
#define DS_INIT_H

struct InitConstants {
	static int init_rand_init;
	static int mk_address_init;
	static int setUpdateDateRange_init;
	static int mk_dbgen_version_init;
	static int getCatalogNumberFromPage_init;
	static int checkSeeds_init;
	static int dateScaling_init;
	static int mk_w_call_center_init;
	static int mk_w_catalog_page_init;
	static int mk_master_catalog_sales_init;
	static int dectostr_init;
	static int date_join_init;
	static int setSCDKeys_init;
	static int scd_join_init;
	static int matchSCDSK_init;
	static int skipDays_init;
	static int mk_w_catalog_returns_init;
	static int mk_detail_catalog_sales_init;
	static int mk_w_customer_init;
	static int mk_w_date_init;
	static int mk_w_inventory_init;
	static int mk_w_item_init;
	static int mk_w_promotion_init;
	static int mk_w_reason_init;
	static int mk_w_ship_mode_init;
	static int mk_w_store_returns_init;
	static int mk_master_store_sales_init;
	static int mk_w_store_init;
	static int mk_w_web_page_init;
	static int mk_w_web_returns_init;
	static int mk_master_init;
	static int mk_detail_init;
	static int mk_w_web_site_init;
	static int mk_cust_init;
	static int mk_order_init;
	static int mk_part_init;
	static int mk_supp_init;
	static int dbg_text_init;
	static int find_dist_init;
	static int cp_join_init;
	static int web_join_init;
	static int set_pricing_init;
	static int init_params_init;
	static int get_rowcount_init;

	static void Reset();
};

#endif

} // __init__


// config.h

namespace __config__ {

/*
 * Legal Notice
 *
 * This document and associated source code (the "Work") is a part of a
 * benchmark specification maintained by the TPC.
 *
 * The TPC reserves all right, title, and interest to the Work as provided
 * under U.S. and international laws, including without limitation all patent
 * and trademark rights therein.
 *
 * No Warranty
 *
 * 1.1 TO THE MAXIMUM EXTENT PERMITTED BY APPLICABLE LAW, THE INFORMATION
 *     CONTAINED HEREIN IS PROVIDED "AS IS" AND WITH ALL FAULTS, AND THE
 *     AUTHORS AND DEVELOPERS OF THE WORK HEREBY DISCLAIM ALL OTHER
 *     WARRANTIES AND CONDITIONS, EITHER EXPRESS, IMPLIED OR STATUTORY,
 *     INCLUDING, BUT NOT LIMITED TO, ANY (IF ANY) IMPLIED WARRANTIES,
 *     DUTIES OR CONDITIONS OF MERCHANTABILITY, OF FITNESS FOR A PARTICULAR
 *     PURPOSE, OF ACCURACY OR COMPLETENESS OF RESPONSES, OF RESULTS, OF
 *     WORKMANLIKE EFFORT, OF LACK OF VIRUSES, AND OF LACK OF NEGLIGENCE.
 *     ALSO, THERE IS NO WARRANTY OR CONDITION OF TITLE, QUIET ENJOYMENT,
 *     QUIET POSSESSION, CORRESPONDENCE TO DESCRIPTION OR NON-INFRINGEMENT
 *     WITH REGARD TO THE WORK.
 * 1.2 IN NO EVENT WILL ANY AUTHOR OR DEVELOPER OF THE WORK BE LIABLE TO
 *     ANY OTHER PARTY FOR ANY DAMAGES, INCLUDING BUT NOT LIMITED TO THE
 *     COST OF PROCURING SUBSTITUTE GOODS OR SERVICES, LOST PROFITS, LOSS
 *     OF USE, LOSS OF DATA, OR ANY INCIDENTAL, CONSEQUENTIAL, DIRECT,
 *     INDIRECT, OR SPECIAL DAMAGES WHETHER UNDER CONTRACT, TORT, WARRANTY,
 *     OR OTHERWISE, ARISING IN ANY WAY OUT OF THIS OR ANY OTHER AGREEMENT
 *     RELATING TO THE WORK, WHETHER OR NOT SUCH AUTHOR OR DEVELOPER HAD
 *     ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES.
 *
 * Contributors:
 * Gradient Systems
 */

#ifndef CONFIG_H
#define CONFIG_H

//#ifdef MACOS
#define SUPPORT_64BITS
#define HUGE_TYPE   int64_t
#define HUGE_FORMAT "%zu"
#define HUGE_COUNT  1
#define USE_STRING_H
#define USE_STDLIB_H
#define USE_LIMITS_H
#include <limits.h>
#define MAXINT INT_MAX

//#define FLEX
//#endif /* MACOS */

#ifdef NCR
#define STDLIB_HAS_GETOPT
#define USE_STRING_H
#define USE_VALUES_H
#ifdef SQLSERVER
#define WIN32
#else
/* the 64 bit defines are for the Metaware compiler */
#define SUPPORT_64BITS
#define HUGE_TYPE   long long
#define HUGE_COUNT  1
#define HUGE_FORMAT "%LLd"
#define int32_t     int
#endif /* SQLSERVER or MP/RAS */
#endif /* NCR */

#ifdef AIX
#define _ALL_SOURCE
#define USE_STRING_H
#define USE_LIMITS_H
/*
 * if the C compiler is 3.1 or later, then uncomment the
 * lines for 64 bit seed generation
 */
#define SUPPORT_64BITS
#define HUGE_TYPE   long long
#define HUGE_COUNT  1
#define HUGE_FORMAT "%lld"
#define STDLIB_HAS_GETOPT
#define USE_STDLIB_H
#define FLEX
#endif /* AIX */

#ifdef CYGWIN
#define USE_STRING_H
#define PATH_SEP '\\'
#define SUPPORT_64BITS
#define HUGE_TYPE   __int64
#define HUGE_COUNT  1
#define HUGE_FORMAT "%I64d"
#endif /* WIN32 */

#ifdef HPUX
#define SUPPORT_64BITS
#define HUGE_TYPE   long long int
#define HUGE_FORMAT "%lld"
#define HUGE_COUNT  1
#define USE_STRING_H
#define USE_VALUES_H
#define USE_STDLIB_H
#define FLEX
#endif /* HPUX */

#ifdef INTERIX
#define USE_LIMITS_H
#define SUPPORT_64BITS
#define HUGE_TYPE   long long int
#define HUGE_FORMAT "%lld"
#define HUGE_COUNT  1
#endif /* INTERIX */

#ifdef LINUX
#define SUPPORT_64BITS
#define HUGE_TYPE   int64_t
#define HUGE_FORMAT "%lld"
#define HUGE_COUNT  1
#define USE_STRING_H
#define USE_VALUES_H
#define USE_STDLIB_H
#define FLEX
#endif /* LINUX */

#ifdef SOLARIS
#define SUPPORT_64BITS
#define HUGE_TYPE   long long
#define HUGE_FORMAT "%lld"
#define HUGE_COUNT  1
#define USE_STRING_H
#define USE_VALUES_H
#define USE_STDLIB_H
#endif /* SOLARIS */

#ifdef SOL86
#define SUPPORT_64BITS
#define HUGE_TYPE   long long
#define HUGE_FORMAT "%lld"
#define HUGE_COUNT  1
#define USE_STRING_H
#define USE_VALUES_H
#define USE_STDLIB_H
#endif /* SOLARIS */

#ifdef WIN32
#define USE_STRING_H
#define USE_LIMITS_H
#define PATH_SEP '\\'
#define SUPPORT_64BITS
#define HUGE_TYPE   __int64
#define HUGE_COUNT  1
#define HUGE_FORMAT "%I64d"
#endif /* WIN32 */

/* preliminary defines for 64-bit windows compile */
#ifdef WIN64
#define USE_STRING_H
#define PATH_SEP '\\'
#define SUPPORT_64BITS
#define HUGE_TYPE   __int64
#define HUGE_COUNT  1
#define HUGE_FORMAT "%I64d"
#endif /* WIN32 */

#ifndef PATH_SEP
#define PATH_SEP '/'
#endif /* PATH_SEP */

#ifndef HUGE_TYPE
#error The code now requires 64b support
#endif

/***
 ** DATABASE DEFINES
 ***/
#ifdef _MYSQL
#define STR_QUOTES
#endif

using namespace __init__;

#endif /* CONFIG_H */

} // __config__


// porting.h

namespace __porting__ {

/*
 * Legal Notice
 *
 * This document and associated source code (the "Work") is a part of a
 * benchmark specification maintained by the TPC.
 *
 * The TPC reserves all right, title, and interest to the Work as provided
 * under U.S. and international laws, including without limitation all patent
 * and trademark rights therein.
 *
 * No Warranty
 *
 * 1.1 TO THE MAXIMUM EXTENT PERMITTED BY APPLICABLE LAW, THE INFORMATION
 *     CONTAINED HEREIN IS PROVIDED "AS IS" AND WITH ALL FAULTS, AND THE
 *     AUTHORS AND DEVELOPERS OF THE WORK HEREBY DISCLAIM ALL OTHER
 *     WARRANTIES AND CONDITIONS, EITHER EXPRESS, IMPLIED OR STATUTORY,
 *     INCLUDING, BUT NOT LIMITED TO, ANY (IF ANY) IMPLIED WARRANTIES,
 *     DUTIES OR CONDITIONS OF MERCHANTABILITY, OF FITNESS FOR A PARTICULAR
 *     PURPOSE, OF ACCURACY OR COMPLETENESS OF RESPONSES, OF RESULTS, OF
 *     WORKMANLIKE EFFORT, OF LACK OF VIRUSES, AND OF LACK OF NEGLIGENCE.
 *     ALSO, THERE IS NO WARRANTY OR CONDITION OF TITLE, QUIET ENJOYMENT,
 *     QUIET POSSESSION, CORRESPONDENCE TO DESCRIPTION OR NON-INFRINGEMENT
 *     WITH REGARD TO THE WORK.
 * 1.2 IN NO EVENT WILL ANY AUTHOR OR DEVELOPER OF THE WORK BE LIABLE TO
 *     ANY OTHER PARTY FOR ANY DAMAGES, INCLUDING BUT NOT LIMITED TO THE
 *     COST OF PROCURING SUBSTITUTE GOODS OR SERVICES, LOST PROFITS, LOSS
 *     OF USE, LOSS OF DATA, OR ANY INCIDENTAL, CONSEQUENTIAL, DIRECT,
 *     INDIRECT, OR SPECIAL DAMAGES WHETHER UNDER CONTRACT, TORT, WARRANTY,
 *     OR OTHERWISE, ARISING IN ANY WAY OUT OF THIS OR ANY OTHER AGREEMENT
 *     RELATING TO THE WORK, WHETHER OR NOT SUCH AUTHOR OR DEVELOPER HAD
 *     ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES.
 *
 * Contributors:
 * Gradient Systems
 */
#ifndef PORTING_H
#define PORTING_H

#include <string.h>
//#ifdef USE_STRING_H
//#include <string.h>
//#else
//#include <strings.h>
//#endif

#ifdef USE_VALUES_H
#include <values.h>
#endif

#ifdef USE_LIMITS_H
#include <limits.h>
#endif

#ifdef USE_STDLIB_H
#include <stdlib.h>
#endif

#ifndef WIN32
#include <sys/types.h>
#else
#define int32_t __int32
#define int64_t __int64
#endif

#ifdef WIN32
#include <sys/timeb.h>
#define timeb _timeb
#define ftime _ftime
#else
#include <sys/time.h>
#endif

using namespace __config__;

typedef HUGE_TYPE ds_key_t;

/*
 * add some functions that are not strictly ANSI standard
 */
#ifndef strdup
char *strdup(const char *);
#endif

#ifdef WIN32
#include <winsock2.h>
#include <windows.h>
#include <winbase.h>
#include <io.h>
#define random                rand
#define strncasecmp           _strnicmp
#define strcasecmp            _stricmp
#define strdup                _strdup
#define access                _access
#define isatty                _isatty
#define fileno                _fileno
#define F_OK                  0
#define MAXINT                INT_MAX
#define THREAD                __declspec(thread)
#define MIN_MULTI_NODE_ROWS   100000
#define MIN_MULTI_THREAD_ROWS 5000
#define THREAD                __declspec(thread)
/* Lines added by Chuck McDevitt for WIN32 support */
#ifndef _POSIX_
#ifndef S_ISREG
#define S_ISREG(m)  (((m)&_S_IFMT) == _S_IFREG)
#define S_ISFIFO(m) (((m)&_S_IFMT) == _S_IFIFO)
#endif
#endif
#endif /* WIN32 */

#ifdef _MSC_VER
#pragma comment(lib, "ws2_32.lib")
#endif

#ifdef INTERIX
#include <limits.h>
#define MAXINT INT_MAX
#endif /* INTERIX */

#ifdef AIX
#define MAXINT INT_MAX
#endif

#ifdef MACOS
#include <limits.h>
#define MAXINT INT_MAX
#endif /* MACOS */

#define INTERNAL(m)                                                                                                    \
	{ fprintf(stderr, "ERROR: %s\n\tFile: %s\n\tLine: %d\n", m, __FILE__, __LINE__); }

#define OPEN_CHECK(var, path)                                                                                          \
	if ((var) == NULL) {                                                                                               \
		fprintf(stderr, "Open failed for %s at %s:%d\n", path, __FILE__, __LINE__);                                    \
		exit(1);                                                                                                       \
	}

#ifdef MEM_TEST
#define MALLOC_CHECK(v)                                                                                                \
	if (v == NULL) {                                                                                                   \
		fprintf(stderr, "Malloc Failed at %d in %s\n", __LINE__, __FILE__);                                            \
		exit(1);                                                                                                       \
	} else {                                                                                                           \
		fprintf(stderr, "Add (%x) %d at %d in %s\n", sizeof(*v), v, __LINE__, __FILE__);                               \
	}
#else
#define MALLOC_CHECK(v)                                                                                                \
	if (v == NULL) {                                                                                                   \
		fprintf(stderr, "Malloc Failed at %d in %s\n", __LINE__, __FILE__);                                            \
		exit(1);                                                                                                       \
	}
#endif /* MEM_TEST */
#endif

} // __porting__


// w_catalog_page.h

namespace __w_catalog_page__ {

/*
 * Legal Notice
 *
 * This document and associated source code (the "Work") is a part of a
 * benchmark specification maintained by the TPC.
 *
 * The TPC reserves all right, title, and interest to the Work as provided
 * under U.S. and international laws, including without limitation all patent
 * and trademark rights therein.
 *
 * No Warranty
 *
 * 1.1 TO THE MAXIMUM EXTENT PERMITTED BY APPLICABLE LAW, THE INFORMATION
 *     CONTAINED HEREIN IS PROVIDED "AS IS" AND WITH ALL FAULTS, AND THE
 *     AUTHORS AND DEVELOPERS OF THE WORK HEREBY DISCLAIM ALL OTHER
 *     WARRANTIES AND CONDITIONS, EITHER EXPRESS, IMPLIED OR STATUTORY,
 *     INCLUDING, BUT NOT LIMITED TO, ANY (IF ANY) IMPLIED WARRANTIES,
 *     DUTIES OR CONDITIONS OF MERCHANTABILITY, OF FITNESS FOR A PARTICULAR
 *     PURPOSE, OF ACCURACY OR COMPLETENESS OF RESPONSES, OF RESULTS, OF
 *     WORKMANLIKE EFFORT, OF LACK OF VIRUSES, AND OF LACK OF NEGLIGENCE.
 *     ALSO, THERE IS NO WARRANTY OR CONDITION OF TITLE, QUIET ENJOYMENT,
 *     QUIET POSSESSION, CORRESPONDENCE TO DESCRIPTION OR NON-INFRINGEMENT
 *     WITH REGARD TO THE WORK.
 * 1.2 IN NO EVENT WILL ANY AUTHOR OR DEVELOPER OF THE WORK BE LIABLE TO
 *     ANY OTHER PARTY FOR ANY DAMAGES, INCLUDING BUT NOT LIMITED TO THE
 *     COST OF PROCURING SUBSTITUTE GOODS OR SERVICES, LOST PROFITS, LOSS
 *     OF USE, LOSS OF DATA, OR ANY INCIDENTAL, CONSEQUENTIAL, DIRECT,
 *     INDIRECT, OR SPECIAL DAMAGES WHETHER UNDER CONTRACT, TORT, WARRANTY,
 *     OR OTHERWISE, ARISING IN ANY WAY OUT OF THIS OR ANY OTHER AGREEMENT
 *     RELATING TO THE WORK, WHETHER OR NOT SUCH AUTHOR OR DEVELOPER HAD
 *     ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES.
 *
 * Contributors:
 * Gradient Systems
 */
#ifndef CATALOG_PAGE_H
#define CATALOG_PAGE_H

using namespace __constants__;
using namespace __porting__;

/*
 * CATALOG_PAGE table structure
 */
struct CATALOG_PAGE_TBL {
	ds_key_t cp_catalog_page_sk;
	char cp_catalog_page_id[RS_BKEY + 1];
	ds_key_t cp_start_date_id;
	ds_key_t cp_end_date_id;
	char cp_department[RS_CP_DEPARTMENT + 1];
	int cp_catalog_number;
	int cp_catalog_page_number;
	char cp_description[RS_CP_DESCRIPTION + 1];
	char *cp_type;
};

int mk_w_catalog_page(void *info_arr, ds_key_t index);

#endif

} // __w_catalog_page__


// w_web_page.h

namespace __w_web_page__ {

/*
 * Legal Notice
 *
 * This document and associated source code (the "Work") is a part of a
 * benchmark specification maintained by the TPC.
 *
 * The TPC reserves all right, title, and interest to the Work as provided
 * under U.S. and international laws, including without limitation all patent
 * and trademark rights therein.
 *
 * No Warranty
 *
 * 1.1 TO THE MAXIMUM EXTENT PERMITTED BY APPLICABLE LAW, THE INFORMATION
 *     CONTAINED HEREIN IS PROVIDED "AS IS" AND WITH ALL FAULTS, AND THE
 *     AUTHORS AND DEVELOPERS OF THE WORK HEREBY DISCLAIM ALL OTHER
 *     WARRANTIES AND CONDITIONS, EITHER EXPRESS, IMPLIED OR STATUTORY,
 *     INCLUDING, BUT NOT LIMITED TO, ANY (IF ANY) IMPLIED WARRANTIES,
 *     DUTIES OR CONDITIONS OF MERCHANTABILITY, OF FITNESS FOR A PARTICULAR
 *     PURPOSE, OF ACCURACY OR COMPLETENESS OF RESPONSES, OF RESULTS, OF
 *     WORKMANLIKE EFFORT, OF LACK OF VIRUSES, AND OF LACK OF NEGLIGENCE.
 *     ALSO, THERE IS NO WARRANTY OR CONDITION OF TITLE, QUIET ENJOYMENT,
 *     QUIET POSSESSION, CORRESPONDENCE TO DESCRIPTION OR NON-INFRINGEMENT
 *     WITH REGARD TO THE WORK.
 * 1.2 IN NO EVENT WILL ANY AUTHOR OR DEVELOPER OF THE WORK BE LIABLE TO
 *     ANY OTHER PARTY FOR ANY DAMAGES, INCLUDING BUT NOT LIMITED TO THE
 *     COST OF PROCURING SUBSTITUTE GOODS OR SERVICES, LOST PROFITS, LOSS
 *     OF USE, LOSS OF DATA, OR ANY INCIDENTAL, CONSEQUENTIAL, DIRECT,
 *     INDIRECT, OR SPECIAL DAMAGES WHETHER UNDER CONTRACT, TORT, WARRANTY,
 *     OR OTHERWISE, ARISING IN ANY WAY OUT OF THIS OR ANY OTHER AGREEMENT
 *     RELATING TO THE WORK, WHETHER OR NOT SUCH AUTHOR OR DEVELOPER HAD
 *     ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES.
 *
 * Contributors:
 * Gradient Systems
 */

using namespace __constants__;
using namespace __porting__;

/*
 * WEB_PAGE table structure
 */
struct W_WEB_PAGE_TBL {
	ds_key_t wp_page_sk;
	char wp_page_id[RS_BKEY + 1];
	char wp_site_id[RS_BKEY + 1];
	ds_key_t wp_rec_start_date_id;
	ds_key_t wp_rec_end_date_id;
	ds_key_t wp_creation_date_sk;
	ds_key_t wp_access_date_sk;
	int wp_autogen_flag;
	ds_key_t wp_customer_sk;
	char wp_url[RS_WP_URL + 1];
	char *wp_type;
	int wp_char_count;
	int wp_link_count;
	int wp_image_count;
	int wp_max_ad_count;
};

int mk_w_web_page(void *info_arr, ds_key_t kIndex);

} // __w_web_page__


// w_household_demographics.h

namespace __w_household_demographics__ {

/*
 * Legal Notice
 *
 * This document and associated source code (the "Work") is a part of a
 * benchmark specification maintained by the TPC.
 *
 * The TPC reserves all right, title, and interest to the Work as provided
 * under U.S. and international laws, including without limitation all patent
 * and trademark rights therein.
 *
 * No Warranty
 *
 * 1.1 TO THE MAXIMUM EXTENT PERMITTED BY APPLICABLE LAW, THE INFORMATION
 *     CONTAINED HEREIN IS PROVIDED "AS IS" AND WITH ALL FAULTS, AND THE
 *     AUTHORS AND DEVELOPERS OF THE WORK HEREBY DISCLAIM ALL OTHER
 *     WARRANTIES AND CONDITIONS, EITHER EXPRESS, IMPLIED OR STATUTORY,
 *     INCLUDING, BUT NOT LIMITED TO, ANY (IF ANY) IMPLIED WARRANTIES,
 *     DUTIES OR CONDITIONS OF MERCHANTABILITY, OF FITNESS FOR A PARTICULAR
 *     PURPOSE, OF ACCURACY OR COMPLETENESS OF RESPONSES, OF RESULTS, OF
 *     WORKMANLIKE EFFORT, OF LACK OF VIRUSES, AND OF LACK OF NEGLIGENCE.
 *     ALSO, THERE IS NO WARRANTY OR CONDITION OF TITLE, QUIET ENJOYMENT,
 *     QUIET POSSESSION, CORRESPONDENCE TO DESCRIPTION OR NON-INFRINGEMENT
 *     WITH REGARD TO THE WORK.
 * 1.2 IN NO EVENT WILL ANY AUTHOR OR DEVELOPER OF THE WORK BE LIABLE TO
 *     ANY OTHER PARTY FOR ANY DAMAGES, INCLUDING BUT NOT LIMITED TO THE
 *     COST OF PROCURING SUBSTITUTE GOODS OR SERVICES, LOST PROFITS, LOSS
 *     OF USE, LOSS OF DATA, OR ANY INCIDENTAL, CONSEQUENTIAL, DIRECT,
 *     INDIRECT, OR SPECIAL DAMAGES WHETHER UNDER CONTRACT, TORT, WARRANTY,
 *     OR OTHERWISE, ARISING IN ANY WAY OUT OF THIS OR ANY OTHER AGREEMENT
 *     RELATING TO THE WORK, WHETHER OR NOT SUCH AUTHOR OR DEVELOPER HAD
 *     ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES.
 *
 * Contributors:
 * Gradient Systems
 */
#ifndef W_HOUSEHOLD_DEMOGRAPHICS_H
#define W_HOUSEHOLD_DEMOGRAPHICS_H

using namespace __porting__;

/*
 * HOUSEHOLD_DEMOGRAPHICS table structure
 */
struct W_HOUSEHOLD_DEMOGRAPHICS_TBL {
	ds_key_t hd_demo_sk;
	ds_key_t hd_income_band_id;
	char *hd_buy_potential;
	int hd_dep_count;
	int hd_vehicle_count;
};

int mk_w_household_demographics(void *info_arr, ds_key_t kIndex);

#endif

} // __w_household_demographics__


// StringBuffer.h

namespace __StringBuffer__ {

/*
 * Legal Notice
 *
 * This document and associated source code (the "Work") is a part of a
 * benchmark specification maintained by the TPC.
 *
 * The TPC reserves all right, title, and interest to the Work as provided
 * under U.S. and international laws, including without limitation all patent
 * and trademark rights therein.
 *
 * No Warranty
 *
 * 1.1 TO THE MAXIMUM EXTENT PERMITTED BY APPLICABLE LAW, THE INFORMATION
 *     CONTAINED HEREIN IS PROVIDED "AS IS" AND WITH ALL FAULTS, AND THE
 *     AUTHORS AND DEVELOPERS OF THE WORK HEREBY DISCLAIM ALL OTHER
 *     WARRANTIES AND CONDITIONS, EITHER EXPRESS, IMPLIED OR STATUTORY,
 *     INCLUDING, BUT NOT LIMITED TO, ANY (IF ANY) IMPLIED WARRANTIES,
 *     DUTIES OR CONDITIONS OF MERCHANTABILITY, OF FITNESS FOR A PARTICULAR
 *     PURPOSE, OF ACCURACY OR COMPLETENESS OF RESPONSES, OF RESULTS, OF
 *     WORKMANLIKE EFFORT, OF LACK OF VIRUSES, AND OF LACK OF NEGLIGENCE.
 *     ALSO, THERE IS NO WARRANTY OR CONDITION OF TITLE, QUIET ENJOYMENT,
 *     QUIET POSSESSION, CORRESPONDENCE TO DESCRIPTION OR NON-INFRINGEMENT
 *     WITH REGARD TO THE WORK.
 * 1.2 IN NO EVENT WILL ANY AUTHOR OR DEVELOPER OF THE WORK BE LIABLE TO
 *     ANY OTHER PARTY FOR ANY DAMAGES, INCLUDING BUT NOT LIMITED TO THE
 *     COST OF PROCURING SUBSTITUTE GOODS OR SERVICES, LOST PROFITS, LOSS
 *     OF USE, LOSS OF DATA, OR ANY INCIDENTAL, CONSEQUENTIAL, DIRECT,
 *     INDIRECT, OR SPECIAL DAMAGES WHETHER UNDER CONTRACT, TORT, WARRANTY,
 *     OR OTHERWISE, ARISING IN ANY WAY OUT OF THIS OR ANY OTHER AGREEMENT
 *     RELATING TO THE WORK, WHETHER OR NOT SUCH AUTHOR OR DEVELOPER HAD
 *     ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES.
 *
 * Contributors:
 * Gradient Systems
 */

#ifndef STRING_BUFFER_H
#define STRING_BUFFER_H

#define SB_INIT 0x01

typedef struct STRING_BUFFER_T {
	int nFlags;
	int nBytesAllocated;
	int nBytesUsed;
	int nIncrement;
	char *pText;
} StringBuffer_t;

StringBuffer_t *InitBuffer(int nSize, int nIncrement);
int AddBuffer(StringBuffer_t *pBuf, char *pStr);
int ResetBuffer(StringBuffer_t *pBuf);
char *GetBuffer(StringBuffer_t *pBuf);
void FreeBuffer(StringBuffer_t *pBuf);
#endif

} // __StringBuffer__


// misc.h

namespace __misc__ {

/*
 * Legal Notice
 *
 * This document and associated source code (the "Work") is a part of a
 * benchmark specification maintained by the TPC.
 *
 * The TPC reserves all right, title, and interest to the Work as provided
 * under U.S. and international laws, including without limitation all patent
 * and trademark rights therein.
 *
 * No Warranty
 *
 * 1.1 TO THE MAXIMUM EXTENT PERMITTED BY APPLICABLE LAW, THE INFORMATION
 *     CONTAINED HEREIN IS PROVIDED "AS IS" AND WITH ALL FAULTS, AND THE
 *     AUTHORS AND DEVELOPERS OF THE WORK HEREBY DISCLAIM ALL OTHER
 *     WARRANTIES AND CONDITIONS, EITHER EXPRESS, IMPLIED OR STATUTORY,
 *     INCLUDING, BUT NOT LIMITED TO, ANY (IF ANY) IMPLIED WARRANTIES,
 *     DUTIES OR CONDITIONS OF MERCHANTABILITY, OF FITNESS FOR A PARTICULAR
 *     PURPOSE, OF ACCURACY OR COMPLETENESS OF RESPONSES, OF RESULTS, OF
 *     WORKMANLIKE EFFORT, OF LACK OF VIRUSES, AND OF LACK OF NEGLIGENCE.
 *     ALSO, THERE IS NO WARRANTY OR CONDITION OF TITLE, QUIET ENJOYMENT,
 *     QUIET POSSESSION, CORRESPONDENCE TO DESCRIPTION OR NON-INFRINGEMENT
 *     WITH REGARD TO THE WORK.
 * 1.2 IN NO EVENT WILL ANY AUTHOR OR DEVELOPER OF THE WORK BE LIABLE TO
 *     ANY OTHER PARTY FOR ANY DAMAGES, INCLUDING BUT NOT LIMITED TO THE
 *     COST OF PROCURING SUBSTITUTE GOODS OR SERVICES, LOST PROFITS, LOSS
 *     OF USE, LOSS OF DATA, OR ANY INCIDENTAL, CONSEQUENTIAL, DIRECT,
 *     INDIRECT, OR SPECIAL DAMAGES WHETHER UNDER CONTRACT, TORT, WARRANTY,
 *     OR OTHERWISE, ARISING IN ANY WAY OUT OF THIS OR ANY OTHER AGREEMENT
 *     RELATING TO THE WORK, WHETHER OR NOT SUCH AUTHOR OR DEVELOPER HAD
 *     ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES.
 *
 * Contributors:
 * Gradient Systems
 */
#ifndef MISC_H
#define MISC_H
int prep_direct(int dialect);
int close_direct(int dialect);
int pick_tbl(char *dname);
int itostr(char *dest, int i);
int char_op(char *dest, int op, char *s1, char *s2);
char *gen_text(char *dest, int min, int max, int stream);
int int_op(int *dest, int op, int arg1, int arg2);

char *env_config(char *var, char *dflt);
int a_rnd(int min, int max, int column, char *dest);
#endif

} // __misc__


// grammar_support.h

namespace __grammar_support__ {

/*
 * Legal Notice
 *
 * This document and associated source code (the "Work") is a part of a
 * benchmark specification maintained by the TPC.
 *
 * The TPC reserves all right, title, and interest to the Work as provided
 * under U.S. and international laws, including without limitation all patent
 * and trademark rights therein.
 *
 * No Warranty
 *
 * 1.1 TO THE MAXIMUM EXTENT PERMITTED BY APPLICABLE LAW, THE INFORMATION
 *     CONTAINED HEREIN IS PROVIDED "AS IS" AND WITH ALL FAULTS, AND THE
 *     AUTHORS AND DEVELOPERS OF THE WORK HEREBY DISCLAIM ALL OTHER
 *     WARRANTIES AND CONDITIONS, EITHER EXPRESS, IMPLIED OR STATUTORY,
 *     INCLUDING, BUT NOT LIMITED TO, ANY (IF ANY) IMPLIED WARRANTIES,
 *     DUTIES OR CONDITIONS OF MERCHANTABILITY, OF FITNESS FOR A PARTICULAR
 *     PURPOSE, OF ACCURACY OR COMPLETENESS OF RESPONSES, OF RESULTS, OF
 *     WORKMANLIKE EFFORT, OF LACK OF VIRUSES, AND OF LACK OF NEGLIGENCE.
 *     ALSO, THERE IS NO WARRANTY OR CONDITION OF TITLE, QUIET ENJOYMENT,
 *     QUIET POSSESSION, CORRESPONDENCE TO DESCRIPTION OR NON-INFRINGEMENT
 *     WITH REGARD TO THE WORK.
 * 1.2 IN NO EVENT WILL ANY AUTHOR OR DEVELOPER OF THE WORK BE LIABLE TO
 *     ANY OTHER PARTY FOR ANY DAMAGES, INCLUDING BUT NOT LIMITED TO THE
 *     COST OF PROCURING SUBSTITUTE GOODS OR SERVICES, LOST PROFITS, LOSS
 *     OF USE, LOSS OF DATA, OR ANY INCIDENTAL, CONSEQUENTIAL, DIRECT,
 *     INDIRECT, OR SPECIAL DAMAGES WHETHER UNDER CONTRACT, TORT, WARRANTY,
 *     OR OTHERWISE, ARISING IN ANY WAY OUT OF THIS OR ANY OTHER AGREEMENT
 *     RELATING TO THE WORK, WHETHER OR NOT SUCH AUTHOR OR DEVELOPER HAD
 *     ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES.
 *
 * Contributors:
 * Gradient Systems
 */

#ifndef GRAMMAR_SUPPORT_H
#define GRAMMAR_SUPPORT_H
/*
 * entry in the file stack used to manage multiple input file and include files
 */
typedef struct FILE_REF_T {
	FILE *file;
	char *name;
	int line_number;
	void *pContext;
	struct FILE_REF_T *pNext;
#if defined(MKS) || defined(FLEX)
	void *pLexState;
#endif
} file_ref_t;

extern file_ref_t *pCurrentFile;

int yywarn(char *str);
void yyerror(char *msg, ...);
int setup(void);
int include_file(char *fn, void *pContext);
void GetErrorCounts(int *nError, int *nWarning);
#endif

} // __grammar_support__


// w_reason.h

namespace __w_reason__ {

/*
 * Legal Notice
 *
 * This document and associated source code (the "Work") is a part of a
 * benchmark specification maintained by the TPC.
 *
 * The TPC reserves all right, title, and interest to the Work as provided
 * under U.S. and international laws, including without limitation all patent
 * and trademark rights therein.
 *
 * No Warranty
 *
 * 1.1 TO THE MAXIMUM EXTENT PERMITTED BY APPLICABLE LAW, THE INFORMATION
 *     CONTAINED HEREIN IS PROVIDED "AS IS" AND WITH ALL FAULTS, AND THE
 *     AUTHORS AND DEVELOPERS OF THE WORK HEREBY DISCLAIM ALL OTHER
 *     WARRANTIES AND CONDITIONS, EITHER EXPRESS, IMPLIED OR STATUTORY,
 *     INCLUDING, BUT NOT LIMITED TO, ANY (IF ANY) IMPLIED WARRANTIES,
 *     DUTIES OR CONDITIONS OF MERCHANTABILITY, OF FITNESS FOR A PARTICULAR
 *     PURPOSE, OF ACCURACY OR COMPLETENESS OF RESPONSES, OF RESULTS, OF
 *     WORKMANLIKE EFFORT, OF LACK OF VIRUSES, AND OF LACK OF NEGLIGENCE.
 *     ALSO, THERE IS NO WARRANTY OR CONDITION OF TITLE, QUIET ENJOYMENT,
 *     QUIET POSSESSION, CORRESPONDENCE TO DESCRIPTION OR NON-INFRINGEMENT
 *     WITH REGARD TO THE WORK.
 * 1.2 IN NO EVENT WILL ANY AUTHOR OR DEVELOPER OF THE WORK BE LIABLE TO
 *     ANY OTHER PARTY FOR ANY DAMAGES, INCLUDING BUT NOT LIMITED TO THE
 *     COST OF PROCURING SUBSTITUTE GOODS OR SERVICES, LOST PROFITS, LOSS
 *     OF USE, LOSS OF DATA, OR ANY INCIDENTAL, CONSEQUENTIAL, DIRECT,
 *     INDIRECT, OR SPECIAL DAMAGES WHETHER UNDER CONTRACT, TORT, WARRANTY,
 *     OR OTHERWISE, ARISING IN ANY WAY OUT OF THIS OR ANY OTHER AGREEMENT
 *     RELATING TO THE WORK, WHETHER OR NOT SUCH AUTHOR OR DEVELOPER HAD
 *     ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES.
 *
 * Contributors:
 * Gradient Systems
 */
#ifndef W_REASON_H
#define W_REASON_H

using namespace __constants__;
using namespace __porting__;

/*
 * REASON table structure
 */
struct W_REASON_TBL {
	ds_key_t r_reason_sk;
	char r_reason_id[RS_BKEY + 1];
	char *r_reason_description;
};

int mk_w_reason(void *info_arr, ds_key_t kIndex);

#endif

} // __w_reason__


// load.h

namespace __load__ {

/*
 * Legal Notice
 *
 * This document and associated source code (the "Work") is a part of a
 * benchmark specification maintained by the TPC.
 *
 * The TPC reserves all right, title, and interest to the Work as provided
 * under U.S. and international laws, including without limitation all patent
 * and trademark rights therein.
 *
 * No Warranty
 *
 * 1.1 TO THE MAXIMUM EXTENT PERMITTED BY APPLICABLE LAW, THE INFORMATION
 *     CONTAINED HEREIN IS PROVIDED "AS IS" AND WITH ALL FAULTS, AND THE
 *     AUTHORS AND DEVELOPERS OF THE WORK HEREBY DISCLAIM ALL OTHER
 *     WARRANTIES AND CONDITIONS, EITHER EXPRESS, IMPLIED OR STATUTORY,
 *     INCLUDING, BUT NOT LIMITED TO, ANY (IF ANY) IMPLIED WARRANTIES,
 *     DUTIES OR CONDITIONS OF MERCHANTABILITY, OF FITNESS FOR A PARTICULAR
 *     PURPOSE, OF ACCURACY OR COMPLETENESS OF RESPONSES, OF RESULTS, OF
 *     WORKMANLIKE EFFORT, OF LACK OF VIRUSES, AND OF LACK OF NEGLIGENCE.
 *     ALSO, THERE IS NO WARRANTY OR CONDITION OF TITLE, QUIET ENJOYMENT,
 *     QUIET POSSESSION, CORRESPONDENCE TO DESCRIPTION OR NON-INFRINGEMENT
 *     WITH REGARD TO THE WORK.
 * 1.2 IN NO EVENT WILL ANY AUTHOR OR DEVELOPER OF THE WORK BE LIABLE TO
 *     ANY OTHER PARTY FOR ANY DAMAGES, INCLUDING BUT NOT LIMITED TO THE
 *     COST OF PROCURING SUBSTITUTE GOODS OR SERVICES, LOST PROFITS, LOSS
 *     OF USE, LOSS OF DATA, OR ANY INCIDENTAL, CONSEQUENTIAL, DIRECT,
 *     INDIRECT, OR SPECIAL DAMAGES WHETHER UNDER CONTRACT, TORT, WARRANTY,
 *     OR OTHERWISE, ARISING IN ANY WAY OUT OF THIS OR ANY OTHER AGREEMENT
 *     RELATING TO THE WORK, WHETHER OR NOT SUCH AUTHOR OR DEVELOPER HAD
 *     ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES.
 *
 * Contributors:
 * Gradient Systems
 */
#ifndef LOAD_H
#define LOAD_H
using namespace __tables__;
void load_init(void);
void load_close(void);
int create_table(int nTable);
#endif

} // __load__


// dbgen_version.h

namespace __dbgen_version__ {

using namespace __porting__;
/*
 * Legal Notice
 *
 * This document and associated source code (the "Work") is a part of a
 * benchmark specification maintained by the TPC.
 *
 * The TPC reserves all right, title, and interest to the Work as provided
 * under U.S. and international laws, including without limitation all patent
 * and trademark rights therein.
 *
 * No Warranty
 *
 * 1.1 TO THE MAXIMUM EXTENT PERMITTED BY APPLICABLE LAW, THE INFORMATION
 *     CONTAINED HEREIN IS PROVIDED "AS IS" AND WITH ALL FAULTS, AND THE
 *     AUTHORS AND DEVELOPERS OF THE WORK HEREBY DISCLAIM ALL OTHER
 *     WARRANTIES AND CONDITIONS, EITHER EXPRESS, IMPLIED OR STATUTORY,
 *     INCLUDING, BUT NOT LIMITED TO, ANY (IF ANY) IMPLIED WARRANTIES,
 *     DUTIES OR CONDITIONS OF MERCHANTABILITY, OF FITNESS FOR A PARTICULAR
 *     PURPOSE, OF ACCURACY OR COMPLETENESS OF RESPONSES, OF RESULTS, OF
 *     WORKMANLIKE EFFORT, OF LACK OF VIRUSES, AND OF LACK OF NEGLIGENCE.
 *     ALSO, THERE IS NO WARRANTY OR CONDITION OF TITLE, QUIET ENJOYMENT,
 *     QUIET POSSESSION, CORRESPONDENCE TO DESCRIPTION OR NON-INFRINGEMENT
 *     WITH REGARD TO THE WORK.
 * 1.2 IN NO EVENT WILL ANY AUTHOR OR DEVELOPER OF THE WORK BE LIABLE TO
 *     ANY OTHER PARTY FOR ANY DAMAGES, INCLUDING BUT NOT LIMITED TO THE
 *     COST OF PROCURING SUBSTITUTE GOODS OR SERVICES, LOST PROFITS, LOSS
 *     OF USE, LOSS OF DATA, OR ANY INCIDENTAL, CONSEQUENTIAL, DIRECT,
 *     INDIRECT, OR SPECIAL DAMAGES WHETHER UNDER CONTRACT, TORT, WARRANTY,
 *     OR OTHERWISE, ARISING IN ANY WAY OUT OF THIS OR ANY OTHER AGREEMENT
 *     RELATING TO THE WORK, WHETHER OR NOT SUCH AUTHOR OR DEVELOPER HAD
 *     ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES.
 *
 * Contributors:
 * Gradient Systems
 */
#ifndef DBGEN_VERSION_H
#define DBGEN_VERSION_H

#define RS_VERSION_LENGTH    100
#define RS_CMDLINARGS_LENGTH 200

struct DBGEN_VERSION_TBL {
	char szVersion[RS_VERSION_LENGTH + 1];
	char szDate[26];
	char szTime[26];
	char szCmdLineArgs[RS_CMDLINARGS_LENGTH + 1];
};

int mk_dbgen_version(void *pDest, ds_key_t kIndex);
int pr_dbgen_version(void *pSrc);
int ld_dbgen_version(void *pSrc);
#endif

} // __dbgen_version__


// release.h

namespace __release__ {

/*
 * Legal Notice
 *
 * This document and associated source code (the "Work") is a part of a
 * benchmark specification maintained by the TPC.
 *
 * The TPC reserves all right, title, and interest to the Work as provided
 * under U.S. and international laws, including without limitation all patent
 * and trademark rights therein.
 *
 * No Warranty
 *
 * 1.1 TO THE MAXIMUM EXTENT PERMITTED BY APPLICABLE LAW, THE INFORMATION
 *     CONTAINED HEREIN IS PROVIDED "AS IS" AND WITH ALL FAULTS, AND THE
 *     AUTHORS AND DEVELOPERS OF THE WORK HEREBY DISCLAIM ALL OTHER
 *     WARRANTIES AND CONDITIONS, EITHER EXPRESS, IMPLIED OR STATUTORY,
 *     INCLUDING, BUT NOT LIMITED TO, ANY (IF ANY) IMPLIED WARRANTIES,
 *     DUTIES OR CONDITIONS OF MERCHANTABILITY, OF FITNESS FOR A PARTICULAR
 *     PURPOSE, OF ACCURACY OR COMPLETENESS OF RESPONSES, OF RESULTS, OF
 *     WORKMANLIKE EFFORT, OF LACK OF VIRUSES, AND OF LACK OF NEGLIGENCE.
 *     ALSO, THERE IS NO WARRANTY OR CONDITION OF TITLE, QUIET ENJOYMENT,
 *     QUIET POSSESSION, CORRESPONDENCE TO DESCRIPTION OR NON-INFRINGEMENT
 *     WITH REGARD TO THE WORK.
 * 1.2 IN NO EVENT WILL ANY AUTHOR OR DEVELOPER OF THE WORK BE LIABLE TO
 *     ANY OTHER PARTY FOR ANY DAMAGES, INCLUDING BUT NOT LIMITED TO THE
 *     COST OF PROCURING SUBSTITUTE GOODS OR SERVICES, LOST PROFITS, LOSS
 *     OF USE, LOSS OF DATA, OR ANY INCIDENTAL, CONSEQUENTIAL, DIRECT,
 *     INDIRECT, OR SPECIAL DAMAGES WHETHER UNDER CONTRACT, TORT, WARRANTY,
 *     OR OTHERWISE, ARISING IN ANY WAY OUT OF THIS OR ANY OTHER AGREEMENT
 *     RELATING TO THE WORK, WHETHER OR NOT SUCH AUTHOR OR DEVELOPER HAD
 *     ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES.
 *
 * Contributors:
 * Gradient Systems
 */
#ifndef RELEASE_H
#define RELEASE_H

/***
 *** RELEASE INFORMATION
 ***/
#define VERSION      2
#define RELEASE      10
#define MODIFICATION 0
#define PATCH        ""
#define COPYRIGHT    "Transaction Processing Performance Council (TPC)"
#define C_DATES      "2001 - 2018"

int printReleaseInfo(const char *param, const char *val);

#endif
} // __release__


// r_params.h

namespace __r_params__ {

/*
 * Legal Notice
 *
 * This document and associated source code (the "Work") is a part of a
 * benchmark specification maintained by the TPC.
 *
 * The TPC reserves all right, title, and interest to the Work as provided
 * under U.S. and international laws, including without limitation all patent
 * and trademark rights therein.
 *
 * No Warranty
 *
 * 1.1 TO THE MAXIMUM EXTENT PERMITTED BY APPLICABLE LAW, THE INFORMATION
 *     CONTAINED HEREIN IS PROVIDED "AS IS" AND WITH ALL FAULTS, AND THE
 *     AUTHORS AND DEVELOPERS OF THE WORK HEREBY DISCLAIM ALL OTHER
 *     WARRANTIES AND CONDITIONS, EITHER EXPRESS, IMPLIED OR STATUTORY,
 *     INCLUDING, BUT NOT LIMITED TO, ANY (IF ANY) IMPLIED WARRANTIES,
 *     DUTIES OR CONDITIONS OF MERCHANTABILITY, OF FITNESS FOR A PARTICULAR
 *     PURPOSE, OF ACCURACY OR COMPLETENESS OF RESPONSES, OF RESULTS, OF
 *     WORKMANLIKE EFFORT, OF LACK OF VIRUSES, AND OF LACK OF NEGLIGENCE.
 *     ALSO, THERE IS NO WARRANTY OR CONDITION OF TITLE, QUIET ENJOYMENT,
 *     QUIET POSSESSION, CORRESPONDENCE TO DESCRIPTION OR NON-INFRINGEMENT
 *     WITH REGARD TO THE WORK.
 * 1.2 IN NO EVENT WILL ANY AUTHOR OR DEVELOPER OF THE WORK BE LIABLE TO
 *     ANY OTHER PARTY FOR ANY DAMAGES, INCLUDING BUT NOT LIMITED TO THE
 *     COST OF PROCURING SUBSTITUTE GOODS OR SERVICES, LOST PROFITS, LOSS
 *     OF USE, LOSS OF DATA, OR ANY INCIDENTAL, CONSEQUENTIAL, DIRECT,
 *     INDIRECT, OR SPECIAL DAMAGES WHETHER UNDER CONTRACT, TORT, WARRANTY,
 *     OR OTHERWISE, ARISING IN ANY WAY OUT OF THIS OR ANY OTHER AGREEMENT
 *     RELATING TO THE WORK, WHETHER OR NOT SUCH AUTHOR OR DEVELOPER HAD
 *     ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES.
 *
 * Contributors:
 * Gradient Systems
 */

#ifndef R_PARAMS_H
#define R_PARAMS_H
#define OPT_NONE  0x00
#define OPT_FLG   0x01  /* option is a flag; no parameter */
#define OPT_INT   0x02  /* argument is an integer */
#define OPT_STR   0x04  /* argument is a string */
#define OPT_NOP   0x08  /* flags non-operational options */
#define OPT_SUB   0x10  /* sub-option defined */
#define OPT_ADV   0x20  /* advanced option */
#define OPT_SET   0x40  /* not changeable -- used for default/file/command precedence */
#define OPT_DFLT  0x80  /* param set to non-zero default */
#define OPT_MULTI 0x100 /* param may be set repeatedly */
#define OPT_HIDE  0x200 /* hidden option -- not listed in usage */
#define TYPE_MASK 0x07

typedef struct OPTION_T {
	const char *name;
	int flags;
	int index;
	const char *usage;
	int (*action)(const char *szPName, const char *optarg);
	const char *dflt;
} option_t;
#endif
/*
 * function declarations
 */
int process_options(int count, const char **args);
char *get_str(const char *var);
void set_str(const char *param, const char *value);
int get_int(const char *var);
void set_int(const char *var, const char *val);
double get_dbl(const char *var);
int is_set(const char *flag);
void clr_flg(const char *flag);
int find_table(const char *szParamName, const char *tname);
int read_file(const char *param_name, const char *arg);
int usage(const char *param_name, const char *msg);
char *GetParamName(int nParam);
char *GetParamValue(int nParam);
int load_param(int nParam, const char *value);
int fnd_param(const char *name);
int init_params(void);
int set_option(const char *pname, const char *value);
void load_params(void);
int IsIntParam(const char *szName);
int IsStrParam(const char *szName);

} // __r_params__


// dist.h

namespace __dist__ {

/*
 * Legal Notice
 *
 * This document and associated source code (the "Work") is a part of a
 * benchmark specification maintained by the TPC.
 *
 * The TPC reserves all right, title, and interest to the Work as provided
 * under U.S. and international laws, including without limitation all patent
 * and trademark rights therein.
 *
 * No Warranty
 *
 * 1.1 TO THE MAXIMUM EXTENT PERMITTED BY APPLICABLE LAW, THE INFORMATION
 *     CONTAINED HEREIN IS PROVIDED "AS IS" AND WITH ALL FAULTS, AND THE
 *     AUTHORS AND DEVELOPERS OF THE WORK HEREBY DISCLAIM ALL OTHER
 *     WARRANTIES AND CONDITIONS, EITHER EXPRESS, IMPLIED OR STATUTORY,
 *     INCLUDING, BUT NOT LIMITED TO, ANY (IF ANY) IMPLIED WARRANTIES,
 *     DUTIES OR CONDITIONS OF MERCHANTABILITY, OF FITNESS FOR A PARTICULAR
 *     PURPOSE, OF ACCURACY OR COMPLETENESS OF RESPONSES, OF RESULTS, OF
 *     WORKMANLIKE EFFORT, OF LACK OF VIRUSES, AND OF LACK OF NEGLIGENCE.
 *     ALSO, THERE IS NO WARRANTY OR CONDITION OF TITLE, QUIET ENJOYMENT,
 *     QUIET POSSESSION, CORRESPONDENCE TO DESCRIPTION OR NON-INFRINGEMENT
 *     WITH REGARD TO THE WORK.
 * 1.2 IN NO EVENT WILL ANY AUTHOR OR DEVELOPER OF THE WORK BE LIABLE TO
 *     ANY OTHER PARTY FOR ANY DAMAGES, INCLUDING BUT NOT LIMITED TO THE
 *     COST OF PROCURING SUBSTITUTE GOODS OR SERVICES, LOST PROFITS, LOSS
 *     OF USE, LOSS OF DATA, OR ANY INCIDENTAL, CONSEQUENTIAL, DIRECT,
 *     INDIRECT, OR SPECIAL DAMAGES WHETHER UNDER CONTRACT, TORT, WARRANTY,
 *     OR OTHERWISE, ARISING IN ANY WAY OUT OF THIS OR ANY OTHER AGREEMENT
 *     RELATING TO THE WORK, WHETHER OR NOT SUCH AUTHOR OR DEVELOPER HAD
 *     ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES.
 *
 * Contributors:
 * Gradient Systems
 */
#ifndef R_DIST_H
#define R_DIST_H

#define D_NAME_LEN 20

typedef struct DIST_T {
	int *type_vector;
	int **weight_sets;
	int *maximums;
	int **value_sets;
	char *strings;
	char *names;
	int size;
} dist_t;

typedef struct D_IDX_T {
	char name[D_NAME_LEN + 1];
	int index;
	int nAllocatedLength;
	int nRemainingStrSpace;
	int offset;
	int str_space;
	int name_space;
	int length;
	int w_width;
	int v_width;
	int flags;
	dist_t *dist;
} d_idx_t;

typedef struct DISTINDEX_T {
	int nDistCount;
	int nAllocatedCount;
	d_idx_t *pEntries;
} distindex_t;

/* must match WriteDist() in dcomp.c */
#define IDX_SIZE (D_NAME_LEN + 7 * sizeof(int))

int dist_op(void *dest, int op, const char *d_name, int vset, int wset, int stream);
#define pick_distribution(dest, dist, v, w, s) dist_op(dest, 0, dist, v, w, s)
#define dist_member(dest, dist, v, w)          dist_op(dest, 1, dist, v, w, 0)
#define dist_max(dist, w)                      dist->maximums[w - 1]
int dist_weight(int *dest, const char *d, int index, int wset);
int distsize(const char *szDistname);
int dist_type(const char *szDistName, int vset);
d_idx_t *find_dist(const char *name);
int IntegrateDist(const char *szDistName, int nPct, int nStartIndex, int nWeightSet);
void dump_dist(const char *szName);
int dist_active(const char *szName, int nWeightSet);
int DistNameIndex(const char *szDist, int nNameType, const char *szName);
int DistSizeToShiftWidth(const char *szDist, int nWeightSet);
int MatchDistWeight(void *dest, const char *szDist, int nWeight, int nWeightSet, int ValueSet);
int findDistValue(const char *szValue, const char *szDistName, int ValueSet);
int di_compare(const void *op1, const void *op2);

#define DIST_UNIFORM     0x0001
#define DIST_EXPONENTIAL 0x0002
/* sales and returns are special; they must match calendar.dst */
#define DIST_SALES     3
#define DIST_RETURNS   5
#define DIST_CHAR      0x0004
#define DIST_INT       0x0008
#define DIST_NAMES_SET 0xff00

/* DistNameIndex needs to know what sort of name we are trying to match */
#define VALUE_NAME  0x0000
#define WEIGHT_NAME 0x0001

#endif /* R_DIST_H */

} // __dist__


// address.h

namespace __address__ {

/*
 * Legal Notice
 *
 * This document and associated source code (the "Work") is a part of a
 * benchmark specification maintained by the TPC.
 *
 * The TPC reserves all right, title, and interest to the Work as provided
 * under U.S. and international laws, including without limitation all patent
 * and trademark rights therein.
 *
 * No Warranty
 *
 * 1.1 TO THE MAXIMUM EXTENT PERMITTED BY APPLICABLE LAW, THE INFORMATION
 *     CONTAINED HEREIN IS PROVIDED "AS IS" AND WITH ALL FAULTS, AND THE
 *     AUTHORS AND DEVELOPERS OF THE WORK HEREBY DISCLAIM ALL OTHER
 *     WARRANTIES AND CONDITIONS, EITHER EXPRESS, IMPLIED OR STATUTORY,
 *     INCLUDING, BUT NOT LIMITED TO, ANY (IF ANY) IMPLIED WARRANTIES,
 *     DUTIES OR CONDITIONS OF MERCHANTABILITY, OF FITNESS FOR A PARTICULAR
 *     PURPOSE, OF ACCURACY OR COMPLETENESS OF RESPONSES, OF RESULTS, OF
 *     WORKMANLIKE EFFORT, OF LACK OF VIRUSES, AND OF LACK OF NEGLIGENCE.
 *     ALSO, THERE IS NO WARRANTY OR CONDITION OF TITLE, QUIET ENJOYMENT,
 *     QUIET POSSESSION, CORRESPONDENCE TO DESCRIPTION OR NON-INFRINGEMENT
 *     WITH REGARD TO THE WORK.
 * 1.2 IN NO EVENT WILL ANY AUTHOR OR DEVELOPER OF THE WORK BE LIABLE TO
 *     ANY OTHER PARTY FOR ANY DAMAGES, INCLUDING BUT NOT LIMITED TO THE
 *     COST OF PROCURING SUBSTITUTE GOODS OR SERVICES, LOST PROFITS, LOSS
 *     OF USE, LOSS OF DATA, OR ANY INCIDENTAL, CONSEQUENTIAL, DIRECT,
 *     INDIRECT, OR SPECIAL DAMAGES WHETHER UNDER CONTRACT, TORT, WARRANTY,
 *     OR OTHERWISE, ARISING IN ANY WAY OUT OF THIS OR ANY OTHER AGREEMENT
 *     RELATING TO THE WORK, WHETHER OR NOT SUCH AUTHOR OR DEVELOPER HAD
 *     ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES.
 *
 * Contributors:
 * Gradient Systems
 */

#ifndef DS_ADDRESS_H
#define DS_ADDRESS_H

using namespace __constants__;

typedef struct DS_ADDR_T {
	char suite_num[RS_CC_SUITE_NUM + 1];
	int street_num;
	char *street_name1;
	char *street_name2;
	char *street_type;
	char *city;
	char *county;
	char *state;
	char country[RS_CC_COUNTRY + 1];
	int zip;
	int plus4;
	int gmt_offset;
} ds_addr_t;

#define DS_ADDR_SUITE_NUM    0
#define DS_ADDR_STREET_NUM   1
#define DS_ADDR_STREET_NAME1 2
#define DS_ADDR_STREET_NAME2 3
#define DS_ADDR_STREET_TYPE  4
#define DS_ADDR_CITY         5
#define DS_ADDR_COUNTY       6
#define DS_ADDR_STATE        7
#define DS_ADDR_COUNTRY      8
#define DS_ADDR_ZIP          9
#define DS_ADDR_PLUS4        10
#define DS_ADDR_GMT_OFFSET   11

int mk_address(ds_addr_t *pDest, int nColumn);
int mk_streetnumber(int nTable, int *dest);
int mk_suitenumber(int nTable, char *dest);
int mk_streetname(int nTable, char *dest);
int mk_city(int nTable, char **dest);
int city_hash(int nTable, char *name);
int mk_zipcode(int nTable, char *dest, int nRegion, char *city);
// void printAddressPart(FILE *fp, ds_addr_t *pAddr, int nAddressPart);
void resetCountCount(void);

#endif

} // __address__


// tdef_functions.h

namespace __tdef_functions__ {

using namespace __porting__;
/*
 * Legal Notice
 *
 * This document and associated source code (the "Work") is a part of a
 * benchmark specification maintained by the TPC.
 *
 * The TPC reserves all right, title, and interest to the Work as provided
 * under U.S. and international laws, including without limitation all patent
 * and trademark rights therein.
 *
 * No Warranty
 *
 * 1.1 TO THE MAXIMUM EXTENT PERMITTED BY APPLICABLE LAW, THE INFORMATION
 *     CONTAINED HEREIN IS PROVIDED "AS IS" AND WITH ALL FAULTS, AND THE
 *     AUTHORS AND DEVELOPERS OF THE WORK HEREBY DISCLAIM ALL OTHER
 *     WARRANTIES AND CONDITIONS, EITHER EXPRESS, IMPLIED OR STATUTORY,
 *     INCLUDING, BUT NOT LIMITED TO, ANY (IF ANY) IMPLIED WARRANTIES,
 *     DUTIES OR CONDITIONS OF MERCHANTABILITY, OF FITNESS FOR A PARTICULAR
 *     PURPOSE, OF ACCURACY OR COMPLETENESS OF RESPONSES, OF RESULTS, OF
 *     WORKMANLIKE EFFORT, OF LACK OF VIRUSES, AND OF LACK OF NEGLIGENCE.
 *     ALSO, THERE IS NO WARRANTY OR CONDITION OF TITLE, QUIET ENJOYMENT,
 *     QUIET POSSESSION, CORRESPONDENCE TO DESCRIPTION OR NON-INFRINGEMENT
 *     WITH REGARD TO THE WORK.
 * 1.2 IN NO EVENT WILL ANY AUTHOR OR DEVELOPER OF THE WORK BE LIABLE TO
 *     ANY OTHER PARTY FOR ANY DAMAGES, INCLUDING BUT NOT LIMITED TO THE
 *     COST OF PROCURING SUBSTITUTE GOODS OR SERVICES, LOST PROFITS, LOSS
 *     OF USE, LOSS OF DATA, OR ANY INCIDENTAL, CONSEQUENTIAL, DIRECT,
 *     INDIRECT, OR SPECIAL DAMAGES WHETHER UNDER CONTRACT, TORT, WARRANTY,
 *     OR OTHERWISE, ARISING IN ANY WAY OUT OF THIS OR ANY OTHER AGREEMENT
 *     RELATING TO THE WORK, WHETHER OR NOT SUCH AUTHOR OR DEVELOPER HAD
 *     ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES.
 *
 * Contributors:
 * Gradient Systems
 */
#ifndef TDEF_FUNCTIONS_H
#define TDEF_FUNCTIONS_H
using namespace __tables__;

/*
* table functions.
* NOTE: This table contains the function declarations in the table descriptions;
it must be kept in sync with the
*    declararions of assocaited constants, found in tdefs.h

*/
typedef struct TABLE_FUNC_T {
	char *name;                       /* -- name of the table; */
	int (*builder)(void *, ds_key_t); /* -- function to prep output */
	int (*loader[2])(void *);         /* -- functions to present output */
	                                  /* -- data validation function */
	int (*validate)(int nTable, ds_key_t kRow, int *Permutation);
} table_func_t;

extern table_func_t w_tdef_funcs[MAX_TABLE];
extern table_func_t s_tdef_funcs[MAX_TABLE];
extern table_func_t *tdef_funcs;

int validateGeneric(int nTable, ds_key_t kRow, int *Permutation);
int validateSCD(int nTable, ds_key_t kRow, int *Permutation);

#endif /* TDEF_FUNCTIONS_H */
extern table_func_t s_tdef_funcs[];
extern table_func_t w_tdef_funcs[];

table_func_t *getTdefFunctionsByNumber(int nTable);

} // __tdef_functions__


// tpcds.idx.h

namespace __tpcds_idx__ {

/*
THIS IS AN AUTOMATICALLY GENERATED FILE
DO NOT EDIT

See distcomp.c for details
*/

/* aliases for values/weights in the first_names distribution */
#define first_names_name    1
#define first_names_male    1
#define first_names_female  2
#define first_names_unified 3

/* aliases for values/weights in the last_names distribution */
/* NONE DEFINED */

/* aliases for values/weights in the calendar distribution */
#define calendar_day_seq      1
#define calendar_month_name   2
#define calendar_date         3
#define calendar_season       4
#define calendar_month_num    5
#define calendar_quarter      6
#define calendar_fom          7
#define calendar_holiday      8
#define calendar_uniform      1
#define calendar_uniform_leap 2
#define calendar_sales        3
#define calendar_sales_leap   4
#define calendar_returns      5
#define calendar_returns_leap 6
#define calendar_skewed       7
#define calendar_low          8
#define calendar_medium       9
#define calendar_high         10

/* aliases for values/weights in the week_info distribution */
/* NONE DEFINED */

/* aliases for values/weights in the fips_county distribution */
#define fips_county_fips       1
#define fips_county_county     2
#define fips_county_st         3
#define fips_county_state      4
#define fips_county_zone       5
#define fips_county_gmt        6
#define fips_county_uniform    1
#define fips_county_population 2
#define fips_county_tz         3
#define fips_county_tz90       4
#define fips_county_tz9        5
#define fips_county_tz1        6

/* aliases for values/weights in the street_names distribution */
/* NONE DEFINED */

/* aliases for values/weights in the street_type distribution */
/* NONE DEFINED */

/* aliases for values/weights in the adjectives distribution */
/* NONE DEFINED */

/* aliases for values/weights in the adverbs distribution */
/* NONE DEFINED */

/* aliases for values/weights in the articles distribution */
/* NONE DEFINED */

/* aliases for values/weights in the nouns distribution */
/* NONE DEFINED */

/* aliases for values/weights in the prepositions distribution */
/* NONE DEFINED */

/* aliases for values/weights in the verbs distribution */
/* NONE DEFINED */

/* aliases for values/weights in the auxiliaries distribution */
/* NONE DEFINED */

/* aliases for values/weights in the terminators distribution */
/* NONE DEFINED */

/* aliases for values/weights in the sentences distribution */
/* NONE DEFINED */

/* aliases for values/weights in the syllables distribution */
/* NONE DEFINED */

/* aliases for values/weights in the cities distribution */
#define cities_name    1
#define cities_usgs    1
#define cities_uniform 2
#define cities_large   3
#define cities_medium  4
#define cities_small   5
#define cities_unified 6

/* aliases for values/weights in the categories distribution */
/* NONE DEFINED */

/* aliases for values/weights in the women_class distribution */
/* NONE DEFINED */

/* aliases for values/weights in the men_class distribution */
/* NONE DEFINED */

/* aliases for values/weights in the children_class distribution */
/* NONE DEFINED */

/* aliases for values/weights in the shoe_class distribution */
/* NONE DEFINED */

/* aliases for values/weights in the music_class distribution */
/* NONE DEFINED */

/* aliases for values/weights in the jewelry_class distribution */
/* NONE DEFINED */

/* aliases for values/weights in the home_class distribution */
/* NONE DEFINED */

/* aliases for values/weights in the sport_class distribution */
/* NONE DEFINED */

/* aliases for values/weights in the book_class distribution */
/* NONE DEFINED */

/* aliases for values/weights in the electronic_class distribution */
/* NONE DEFINED */

/* aliases for values/weights in the sizes distribution */
/* NONE DEFINED */

/* aliases for values/weights in the units distribution */
/* NONE DEFINED */

/* aliases for values/weights in the container distribution */
/* NONE DEFINED */

/* aliases for values/weights in the colors distribution */
#define colors_name    1
#define colors_uniform 1
#define colors_skewed  2
#define colors_low     3
#define colors_medium  4
#define colors_high    5

/* aliases for values/weights in the brand_syllables distribution */
/* NONE DEFINED */

/* aliases for values/weights in the i_current_price distribution */
#define i_current_price_index      1
#define i_current_price_low_bound  2
#define i_current_price_high_bound 3
#define i_current_price_skew       1
#define i_current_price_high       2
#define i_current_price_medium     3
#define i_current_price_low        4

/* aliases for values/weights in the i_manufact_id distribution */
/* NONE DEFINED */

/* aliases for values/weights in the i_manager_id distribution */
/* NONE DEFINED */

/* aliases for values/weights in the rowcounts distribution */
/* NONE DEFINED */

/* aliases for values/weights in the gender distribution */
/* NONE DEFINED */

/* aliases for values/weights in the marital_status distribution */
/* NONE DEFINED */

/* aliases for values/weights in the education distribution */
/* NONE DEFINED */

/* aliases for values/weights in the purchase_band distribution */
/* NONE DEFINED */

/* aliases for values/weights in the buy_potential distribution */
/* NONE DEFINED */

/* aliases for values/weights in the credit_rating distribution */
/* NONE DEFINED */

/* aliases for values/weights in the income_band distribution */
/* NONE DEFINED */

/* aliases for values/weights in the dependent_count distribution */
/* NONE DEFINED */

/* aliases for values/weights in the vehicle_count distribution */
/* NONE DEFINED */

/* aliases for values/weights in the promo_purpose distribution */
/* NONE DEFINED */

/* aliases for values/weights in the return_reasons distribution */
/* NONE DEFINED */

/* aliases for values/weights in the store_type distribution */
/* NONE DEFINED */

/* aliases for values/weights in the geography_class distribution */
/* NONE DEFINED */

/* aliases for values/weights in the divisions distribution */
/* NONE DEFINED */

/* aliases for values/weights in the stores distribution */
/* NONE DEFINED */

/* aliases for values/weights in the hours distribution */
/* NONE DEFINED */

/* aliases for values/weights in the call_centers distribution */
/* NONE DEFINED */

/* aliases for values/weights in the call_center_hours distribution */
/* NONE DEFINED */

/* aliases for values/weights in the call_center_class distribution */
/* NONE DEFINED */

/* aliases for values/weights in the salutations distribution */
/* NONE DEFINED */

/* aliases for values/weights in the ship_mode_code distribution */
/* NONE DEFINED */

/* aliases for values/weights in the ship_mode_type distribution */
/* NONE DEFINED */

/* aliases for values/weights in the ship_mode_carrier distribution */
/* NONE DEFINED */

/* aliases for values/weights in the web_page_use distribution */
/* NONE DEFINED */

/* aliases for values/weights in the web_page_type distribution */
/* NONE DEFINED */

/* aliases for values/weights in the catalog_page_type distribution */
/* NONE DEFINED */

/* aliases for values/weights in the location_type distribution */
/* NONE DEFINED */

/* aliases for values/weights in the top_domains distribution */
/* NONE DEFINED */

/* aliases for values/weights in the countries distribution */
/* NONE DEFINED */

} // __tpcds_idx__


// skip_days.h

namespace __skip_days__ {

#ifndef R_SKIP_DAYS_H
#define R_SKIP_DAYS_H

using namespace __config__;
using namespace __porting__;

ds_key_t skipDays(int nTable, ds_key_t *pRemainder);

#endif

} // __skip_days__


// error_msg.h

namespace __error_msg__ {

/*
 * Legal Notice
 *
 * This document and associated source code (the "Work") is a part of a
 * benchmark specification maintained by the TPC.
 *
 * The TPC reserves all right, title, and interest to the Work as provided
 * under U.S. and international laws, including without limitation all patent
 * and trademark rights therein.
 *
 * No Warranty
 *
 * 1.1 TO THE MAXIMUM EXTENT PERMITTED BY APPLICABLE LAW, THE INFORMATION
 *     CONTAINED HEREIN IS PROVIDED "AS IS" AND WITH ALL FAULTS, AND THE
 *     AUTHORS AND DEVELOPERS OF THE WORK HEREBY DISCLAIM ALL OTHER
 *     WARRANTIES AND CONDITIONS, EITHER EXPRESS, IMPLIED OR STATUTORY,
 *     INCLUDING, BUT NOT LIMITED TO, ANY (IF ANY) IMPLIED WARRANTIES,
 *     DUTIES OR CONDITIONS OF MERCHANTABILITY, OF FITNESS FOR A PARTICULAR
 *     PURPOSE, OF ACCURACY OR COMPLETENESS OF RESPONSES, OF RESULTS, OF
 *     WORKMANLIKE EFFORT, OF LACK OF VIRUSES, AND OF LACK OF NEGLIGENCE.
 *     ALSO, THERE IS NO WARRANTY OR CONDITION OF TITLE, QUIET ENJOYMENT,
 *     QUIET POSSESSION, CORRESPONDENCE TO DESCRIPTION OR NON-INFRINGEMENT
 *     WITH REGARD TO THE WORK.
 * 1.2 IN NO EVENT WILL ANY AUTHOR OR DEVELOPER OF THE WORK BE LIABLE TO
 *     ANY OTHER PARTY FOR ANY DAMAGES, INCLUDING BUT NOT LIMITED TO THE
 *     COST OF PROCURING SUBSTITUTE GOODS OR SERVICES, LOST PROFITS, LOSS
 *     OF USE, LOSS OF DATA, OR ANY INCIDENTAL, CONSEQUENTIAL, DIRECT,
 *     INDIRECT, OR SPECIAL DAMAGES WHETHER UNDER CONTRACT, TORT, WARRANTY,
 *     OR OTHERWISE, ARISING IN ANY WAY OUT OF THIS OR ANY OTHER AGREEMENT
 *     RELATING TO THE WORK, WHETHER OR NOT SUCH AUTHOR OR DEVELOPER HAD
 *     ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES.
 *
 * Contributors:
 * Gradient Systems
 */
#define QERR_OK                    0
#define QERR_NO_FILE               -1
#define QERR_LINE_TOO_LONG         -2
#define QERR_NO_MEMORY             -3
#define QERR_SYNTAX                -4
#define QERR_RANGE_ERROR           -5
#define QERR_NON_UNIQUE            -6
#define QERR_BAD_NAME              -7
#define QERR_DEFINE_OVERFLOW       -8
#define QERR_INVALID_TAG           -9
#define QERR_READ_FAILED           -10
#define QERR_TEMPLATE_OVERFLOW     -11
#define QERR_ONE_WORKLOAD          -12
#define QERR_CLASS_REDEFINE        -13
#define QERR_DUP_QUERY             -14
#define QERR_OPEN_FAILED           -15
#define QERR_NOT_IMPLEMENTED       -16
#define QERR_STR_TRUNCATED         -17
#define QERR_BAD_STRING            -18
#define QERR_WRITE_FAILED          -19
#define QERR_NO_TYPE               -20
#define QERR_NO_WEIGHT             -21
#define QERR_NO_LIMIT              -22
#define QERR_BAD_PERCENT           -23
#define QERR_ROWCOUNT_NAME         -24
#define QERR_NO_EXPR               -25
#define QERR_NO_INIT               -26
#define QERR_NO_NORMAL_RANGE       -27
#define QERR_UNBALANCED            -28
#define QERR_INCLUDE_OVERFLOW      -29
#define QERR_BAD_PARAMS            -30
#define DBGEN_ERROR_HIERACHY_ORDER -31
#define QERR_NAMES_EARLY           -32
#define QERR_ARG_OVERFLOW          -33
#define QERR_INVALID_ARG           -34
#define QERR_RANGE_LIST            -35
#define QERR_BAD_SCALE             -36
#define QERR_BAD_PARAM             -37
#define QERR_BAD_JOIN              -38
#define QERR_TABLE_NOP             -39
#define QERR_TABLE_CHILD           -40
#define QERR_CMDLINE_TOO_LONG      -41
#define QERR_NO_QUERYLIST          -42
#define QERR_QUERY_RANGE           -43
#define QERR_MODIFIED_PARAM        -44
#define QERR_RANGE_OVERRUN         -45
#define QERR_QUALIFICATION_SCALE   -46
#define QERR_TABLE_UPDATE          -47
#define MAX_ERROR                  47

typedef struct ERR_MSG_T {
	int flags;
	const char *prompt;
} err_msg_t;

/*  Flag determine formating */
#define EFLG_NO_ARG   0x0000
#define EFLG_STR_ARG  0x0001
#define EFLG_ARG_MASK 0x0001

#define EFLG_SYSTEM 0x0002

int ReportError(int nError, const char *arg, int bExit);
int ReportErrorNoLine(int nError, const char *arg, int bExit);
void SetErrorGlobals(char *szFileName, int *pnLineNumber);

} // __error_msg__


// w_customer.h

namespace __w_customer__ {

/*
 * Legal Notice
 *
 * This document and associated source code (the "Work") is a part of a
 * benchmark specification maintained by the TPC.
 *
 * The TPC reserves all right, title, and interest to the Work as provided
 * under U.S. and international laws, including without limitation all patent
 * and trademark rights therein.
 *
 * No Warranty
 *
 * 1.1 TO THE MAXIMUM EXTENT PERMITTED BY APPLICABLE LAW, THE INFORMATION
 *     CONTAINED HEREIN IS PROVIDED "AS IS" AND WITH ALL FAULTS, AND THE
 *     AUTHORS AND DEVELOPERS OF THE WORK HEREBY DISCLAIM ALL OTHER
 *     WARRANTIES AND CONDITIONS, EITHER EXPRESS, IMPLIED OR STATUTORY,
 *     INCLUDING, BUT NOT LIMITED TO, ANY (IF ANY) IMPLIED WARRANTIES,
 *     DUTIES OR CONDITIONS OF MERCHANTABILITY, OF FITNESS FOR A PARTICULAR
 *     PURPOSE, OF ACCURACY OR COMPLETENESS OF RESPONSES, OF RESULTS, OF
 *     WORKMANLIKE EFFORT, OF LACK OF VIRUSES, AND OF LACK OF NEGLIGENCE.
 *     ALSO, THERE IS NO WARRANTY OR CONDITION OF TITLE, QUIET ENJOYMENT,
 *     QUIET POSSESSION, CORRESPONDENCE TO DESCRIPTION OR NON-INFRINGEMENT
 *     WITH REGARD TO THE WORK.
 * 1.2 IN NO EVENT WILL ANY AUTHOR OR DEVELOPER OF THE WORK BE LIABLE TO
 *     ANY OTHER PARTY FOR ANY DAMAGES, INCLUDING BUT NOT LIMITED TO THE
 *     COST OF PROCURING SUBSTITUTE GOODS OR SERVICES, LOST PROFITS, LOSS
 *     OF USE, LOSS OF DATA, OR ANY INCIDENTAL, CONSEQUENTIAL, DIRECT,
 *     INDIRECT, OR SPECIAL DAMAGES WHETHER UNDER CONTRACT, TORT, WARRANTY,
 *     OR OTHERWISE, ARISING IN ANY WAY OUT OF THIS OR ANY OTHER AGREEMENT
 *     RELATING TO THE WORK, WHETHER OR NOT SUCH AUTHOR OR DEVELOPER HAD
 *     ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES.
 *
 * Contributors:
 * Gradient Systems
 */
#ifndef W_CUSTOMER_H
#define W_CUSTOMER_H

using namespace __constants__;
using namespace __porting__;

/*
 * CUSTOMER table structure
 */
struct W_CUSTOMER_TBL {
	ds_key_t c_customer_sk;
	char c_customer_id[RS_BKEY + 1];
	ds_key_t c_current_cdemo_sk;
	ds_key_t c_current_hdemo_sk;
	ds_key_t c_current_addr_sk;
	int c_first_shipto_date_id;
	int c_first_sales_date_id;
	char *c_salutation;
	char *c_first_name;
	char *c_last_name;
	int c_preferred_cust_flag;
	int c_birth_day;
	int c_birth_month;
	int c_birth_year;
	char *c_birth_country;
	char c_login[RS_C_LOGIN + 1];
	char c_email_address[RS_C_EMAIL + 1];
	int c_last_review_date;
};

int mk_w_customer(void *info_arr, ds_key_t kIndex);

#endif

} // __w_customer__


// w_datetbl.h

namespace __w_datetbl__ {

/*
 * Legal Notice
 *
 * This document and associated source code (the "Work") is a part of a
 * benchmark specification maintained by the TPC.
 *
 * The TPC reserves all right, title, and interest to the Work as provided
 * under U.S. and international laws, including without limitation all patent
 * and trademark rights therein.
 *
 * No Warranty
 *
 * 1.1 TO THE MAXIMUM EXTENT PERMITTED BY APPLICABLE LAW, THE INFORMATION
 *     CONTAINED HEREIN IS PROVIDED "AS IS" AND WITH ALL FAULTS, AND THE
 *     AUTHORS AND DEVELOPERS OF THE WORK HEREBY DISCLAIM ALL OTHER
 *     WARRANTIES AND CONDITIONS, EITHER EXPRESS, IMPLIED OR STATUTORY,
 *     INCLUDING, BUT NOT LIMITED TO, ANY (IF ANY) IMPLIED WARRANTIES,
 *     DUTIES OR CONDITIONS OF MERCHANTABILITY, OF FITNESS FOR A PARTICULAR
 *     PURPOSE, OF ACCURACY OR COMPLETENESS OF RESPONSES, OF RESULTS, OF
 *     WORKMANLIKE EFFORT, OF LACK OF VIRUSES, AND OF LACK OF NEGLIGENCE.
 *     ALSO, THERE IS NO WARRANTY OR CONDITION OF TITLE, QUIET ENJOYMENT,
 *     QUIET POSSESSION, CORRESPONDENCE TO DESCRIPTION OR NON-INFRINGEMENT
 *     WITH REGARD TO THE WORK.
 * 1.2 IN NO EVENT WILL ANY AUTHOR OR DEVELOPER OF THE WORK BE LIABLE TO
 *     ANY OTHER PARTY FOR ANY DAMAGES, INCLUDING BUT NOT LIMITED TO THE
 *     COST OF PROCURING SUBSTITUTE GOODS OR SERVICES, LOST PROFITS, LOSS
 *     OF USE, LOSS OF DATA, OR ANY INCIDENTAL, CONSEQUENTIAL, DIRECT,
 *     INDIRECT, OR SPECIAL DAMAGES WHETHER UNDER CONTRACT, TORT, WARRANTY,
 *     OR OTHERWISE, ARISING IN ANY WAY OUT OF THIS OR ANY OTHER AGREEMENT
 *     RELATING TO THE WORK, WHETHER OR NOT SUCH AUTHOR OR DEVELOPER HAD
 *     ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES.
 *
 * Contributors:
 * Gradient Systems
 */
/*
 * DATE table structure
 */
#ifndef W_DATETBL_H
#define W_DATETBL_H

using namespace __constants__;
using namespace __porting__;

struct W_DATE_TBL {
	ds_key_t d_date_sk;
	char d_date_id[RS_BKEY + 1];
	/* this is generated at output from d_date_sk */
	/* date_t		d_date; */
	int d_month_seq;
	int d_week_seq;
	int d_quarter_seq;
	int d_year;
	int d_dow;
	int d_moy;
	int d_dom;
	int d_qoy;
	int d_fy_year;
	int d_fy_quarter_seq;
	int d_fy_week_seq;
	char *d_day_name;
	/* char		d_quarter_name[RS_D_QUARTER_NAME + 1]; derived at print time */
	int d_holiday;
	int d_weekend;
	int d_following_holiday;
	int d_first_dom;
	int d_last_dom;
	int d_same_day_ly;
	int d_same_day_lq;
	int d_current_day;
	int d_current_week;
	int d_current_month;
	int d_current_quarter;
	int d_current_year;
};

int mk_w_date(void *info_arr, ds_key_t kIndex);

int vld_w_date(int nTable, ds_key_t kRow, int *Permutation);
#endif

} // __w_datetbl__


// grammar.h

namespace __grammar__ {

/*
 * Legal Notice
 *
 * This document and associated source code (the "Work") is a part of a
 * benchmark specification maintained by the TPC.
 *
 * The TPC reserves all right, title, and interest to the Work as provided
 * under U.S. and international laws, including without limitation all patent
 * and trademark rights therein.
 *
 * No Warranty
 *
 * 1.1 TO THE MAXIMUM EXTENT PERMITTED BY APPLICABLE LAW, THE INFORMATION
 *     CONTAINED HEREIN IS PROVIDED "AS IS" AND WITH ALL FAULTS, AND THE
 *     AUTHORS AND DEVELOPERS OF THE WORK HEREBY DISCLAIM ALL OTHER
 *     WARRANTIES AND CONDITIONS, EITHER EXPRESS, IMPLIED OR STATUTORY,
 *     INCLUDING, BUT NOT LIMITED TO, ANY (IF ANY) IMPLIED WARRANTIES,
 *     DUTIES OR CONDITIONS OF MERCHANTABILITY, OF FITNESS FOR A PARTICULAR
 *     PURPOSE, OF ACCURACY OR COMPLETENESS OF RESPONSES, OF RESULTS, OF
 *     WORKMANLIKE EFFORT, OF LACK OF VIRUSES, AND OF LACK OF NEGLIGENCE.
 *     ALSO, THERE IS NO WARRANTY OR CONDITION OF TITLE, QUIET ENJOYMENT,
 *     QUIET POSSESSION, CORRESPONDENCE TO DESCRIPTION OR NON-INFRINGEMENT
 *     WITH REGARD TO THE WORK.
 * 1.2 IN NO EVENT WILL ANY AUTHOR OR DEVELOPER OF THE WORK BE LIABLE TO
 *     ANY OTHER PARTY FOR ANY DAMAGES, INCLUDING BUT NOT LIMITED TO THE
 *     COST OF PROCURING SUBSTITUTE GOODS OR SERVICES, LOST PROFITS, LOSS
 *     OF USE, LOSS OF DATA, OR ANY INCIDENTAL, CONSEQUENTIAL, DIRECT,
 *     INDIRECT, OR SPECIAL DAMAGES WHETHER UNDER CONTRACT, TORT, WARRANTY,
 *     OR OTHERWISE, ARISING IN ANY WAY OUT OF THIS OR ANY OTHER AGREEMENT
 *     RELATING TO THE WORK, WHETHER OR NOT SUCH AUTHOR OR DEVELOPER HAD
 *     ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES.
 *
 * Contributors:
 * Gradient Systems
 */
#ifndef GRAMMAR_H
#define GRAMMAR_H

typedef struct TOKEN_T {
	int index;
	char word[40];
	int (*handler)(char *s, struct TOKEN_T *t);
} token_t;

#define COMMENT_CHAR '-'
#define STMT_END     ';'
int ParseFile(char *szPath);
int FindToken(char *name);
void SetTokens(token_t *t);
char *ProcessStr(char *stmt, token_t *pTokens);
char *SafeStrtok(char *string, char *delims);
extern token_t *pTokens;

#endif /* GRAMMAR_H */

} // __grammar__


// w_income_band.h

namespace __w_income_band__ {

/*
 * Legal Notice
 *
 * This document and associated source code (the "Work") is a part of a
 * benchmark specification maintained by the TPC.
 *
 * The TPC reserves all right, title, and interest to the Work as provided
 * under U.S. and international laws, including without limitation all patent
 * and trademark rights therein.
 *
 * No Warranty
 *
 * 1.1 TO THE MAXIMUM EXTENT PERMITTED BY APPLICABLE LAW, THE INFORMATION
 *     CONTAINED HEREIN IS PROVIDED "AS IS" AND WITH ALL FAULTS, AND THE
 *     AUTHORS AND DEVELOPERS OF THE WORK HEREBY DISCLAIM ALL OTHER
 *     WARRANTIES AND CONDITIONS, EITHER EXPRESS, IMPLIED OR STATUTORY,
 *     INCLUDING, BUT NOT LIMITED TO, ANY (IF ANY) IMPLIED WARRANTIES,
 *     DUTIES OR CONDITIONS OF MERCHANTABILITY, OF FITNESS FOR A PARTICULAR
 *     PURPOSE, OF ACCURACY OR COMPLETENESS OF RESPONSES, OF RESULTS, OF
 *     WORKMANLIKE EFFORT, OF LACK OF VIRUSES, AND OF LACK OF NEGLIGENCE.
 *     ALSO, THERE IS NO WARRANTY OR CONDITION OF TITLE, QUIET ENJOYMENT,
 *     QUIET POSSESSION, CORRESPONDENCE TO DESCRIPTION OR NON-INFRINGEMENT
 *     WITH REGARD TO THE WORK.
 * 1.2 IN NO EVENT WILL ANY AUTHOR OR DEVELOPER OF THE WORK BE LIABLE TO
 *     ANY OTHER PARTY FOR ANY DAMAGES, INCLUDING BUT NOT LIMITED TO THE
 *     COST OF PROCURING SUBSTITUTE GOODS OR SERVICES, LOST PROFITS, LOSS
 *     OF USE, LOSS OF DATA, OR ANY INCIDENTAL, CONSEQUENTIAL, DIRECT,
 *     INDIRECT, OR SPECIAL DAMAGES WHETHER UNDER CONTRACT, TORT, WARRANTY,
 *     OR OTHERWISE, ARISING IN ANY WAY OUT OF THIS OR ANY OTHER AGREEMENT
 *     RELATING TO THE WORK, WHETHER OR NOT SUCH AUTHOR OR DEVELOPER HAD
 *     ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES.
 *
 * Contributors:
 * Gradient Systems
 */

using namespace __porting__;

/*
 * INCOME_BAND table structure
 */
struct W_INCOME_BAND_TBL {
	int ib_income_band_id;
	int ib_lower_bound;
	int ib_upper_bound;
};

int mk_w_income_band(void *info_arr, ds_key_t kIndex);

} // __w_income_band__


// decimal.h

namespace __decimal__ {

/*
 * Legal Notice
 *
 * This document and associated source code (the "Work") is a part of a
 * benchmark specification maintained by the TPC.
 *
 * The TPC reserves all right, title, and interest to the Work as provided
 * under U.S. and international laws, including without limitation all patent
 * and trademark rights therein.
 *
 * No Warranty
 *
 * 1.1 TO THE MAXIMUM EXTENT PERMITTED BY APPLICABLE LAW, THE INFORMATION
 *     CONTAINED HEREIN IS PROVIDED "AS IS" AND WITH ALL FAULTS, AND THE
 *     AUTHORS AND DEVELOPERS OF THE WORK HEREBY DISCLAIM ALL OTHER
 *     WARRANTIES AND CONDITIONS, EITHER EXPRESS, IMPLIED OR STATUTORY,
 *     INCLUDING, BUT NOT LIMITED TO, ANY (IF ANY) IMPLIED WARRANTIES,
 *     DUTIES OR CONDITIONS OF MERCHANTABILITY, OF FITNESS FOR A PARTICULAR
 *     PURPOSE, OF ACCURACY OR COMPLETENESS OF RESPONSES, OF RESULTS, OF
 *     WORKMANLIKE EFFORT, OF LACK OF VIRUSES, AND OF LACK OF NEGLIGENCE.
 *     ALSO, THERE IS NO WARRANTY OR CONDITION OF TITLE, QUIET ENJOYMENT,
 *     QUIET POSSESSION, CORRESPONDENCE TO DESCRIPTION OR NON-INFRINGEMENT
 *     WITH REGARD TO THE WORK.
 * 1.2 IN NO EVENT WILL ANY AUTHOR OR DEVELOPER OF THE WORK BE LIABLE TO
 *     ANY OTHER PARTY FOR ANY DAMAGES, INCLUDING BUT NOT LIMITED TO THE
 *     COST OF PROCURING SUBSTITUTE GOODS OR SERVICES, LOST PROFITS, LOSS
 *     OF USE, LOSS OF DATA, OR ANY INCIDENTAL, CONSEQUENTIAL, DIRECT,
 *     INDIRECT, OR SPECIAL DAMAGES WHETHER UNDER CONTRACT, TORT, WARRANTY,
 *     OR OTHERWISE, ARISING IN ANY WAY OUT OF THIS OR ANY OTHER AGREEMENT
 *     RELATING TO THE WORK, WHETHER OR NOT SUCH AUTHOR OR DEVELOPER HAD
 *     ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES.
 *
 * Contributors:
 * Gradient Systems
 */
#ifndef R_DECIMAL_H
#define R_DECIMAL_H
using namespace __config__;
using namespace __porting__;
using namespace __mathops__;
#include <stdio.h>

/*
 * a precise decimal data type, using scaled integer
 * arithmetic.
 */
typedef struct DECIMAL_T {
	int flags;
	int precision;
	int scale;
	ds_key_t number;
} decimal_t;

#define FL_INIT 0x0004

decimal_t *mk_decimal(int s, int p);

int itodec(decimal_t *dest, int i);
int ftodec(decimal_t *d, double f);
int strtodec(decimal_t *d, char *src);

int dectostr(char *dest, decimal_t *d);
int dectof(double *dest, decimal_t *);
#define dectoi(d) atoi(d->number)

int decimal_t_op(decimal_t *dest, int o, decimal_t *d1, decimal_t *d2);
void print_decimal(int nColumn, decimal_t *d, int s);
void set_precision(decimal_t *d, int sie, int precision);
#define NegateDecimal(d) (d)->number *= -1
#endif /* R_DECIMAL_H */

} // __decimal__


// date.h

namespace __date__ {

/*
 * Legal Notice
 *
 * This document and associated source code (the "Work") is a part of a
 * benchmark specification maintained by the TPC.
 *
 * The TPC reserves all right, title, and interest to the Work as provided
 * under U.S. and international laws, including without limitation all patent
 * and trademark rights therein.
 *
 * No Warranty
 *
 * 1.1 TO THE MAXIMUM EXTENT PERMITTED BY APPLICABLE LAW, THE INFORMATION
 *     CONTAINED HEREIN IS PROVIDED "AS IS" AND WITH ALL FAULTS, AND THE
 *     AUTHORS AND DEVELOPERS OF THE WORK HEREBY DISCLAIM ALL OTHER
 *     WARRANTIES AND CONDITIONS, EITHER EXPRESS, IMPLIED OR STATUTORY,
 *     INCLUDING, BUT NOT LIMITED TO, ANY (IF ANY) IMPLIED WARRANTIES,
 *     DUTIES OR CONDITIONS OF MERCHANTABILITY, OF FITNESS FOR A PARTICULAR
 *     PURPOSE, OF ACCURACY OR COMPLETENESS OF RESPONSES, OF RESULTS, OF
 *     WORKMANLIKE EFFORT, OF LACK OF VIRUSES, AND OF LACK OF NEGLIGENCE.
 *     ALSO, THERE IS NO WARRANTY OR CONDITION OF TITLE, QUIET ENJOYMENT,
 *     QUIET POSSESSION, CORRESPONDENCE TO DESCRIPTION OR NON-INFRINGEMENT
 *     WITH REGARD TO THE WORK.
 * 1.2 IN NO EVENT WILL ANY AUTHOR OR DEVELOPER OF THE WORK BE LIABLE TO
 *     ANY OTHER PARTY FOR ANY DAMAGES, INCLUDING BUT NOT LIMITED TO THE
 *     COST OF PROCURING SUBSTITUTE GOODS OR SERVICES, LOST PROFITS, LOSS
 *     OF USE, LOSS OF DATA, OR ANY INCIDENTAL, CONSEQUENTIAL, DIRECT,
 *     INDIRECT, OR SPECIAL DAMAGES WHETHER UNDER CONTRACT, TORT, WARRANTY,
 *     OR OTHERWISE, ARISING IN ANY WAY OUT OF THIS OR ANY OTHER AGREEMENT
 *     RELATING TO THE WORK, WHETHER OR NOT SUCH AUTHOR OR DEVELOPER HAD
 *     ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES.
 *
 * Contributors:
 * Gradient Systems
 */
#ifndef R_DATE_H
#define R_DATE_H

using namespace __mathops__;

typedef struct DATE_T {
	int flags;
	int year;
	int month;
	int day;
	int julian;
} date_t;

date_t *mk_date(void);

int jtodt(date_t *dest, int i);
int strtodt(date_t *dest, char *s);
int strtotime(char *str);

char *dttostr(date_t *d);
int dttoj(date_t *d);

int date_t_op(date_t *dest, int o, date_t *d1, date_t *d2);
int set_dow(date_t *d);
int is_leap(int year);
int day_number(date_t *d);
int date_part(date_t *d, int p);
int set_outfile(int i);
int getDateWeightFromJulian(int jDay, int nDistribution);
#define CENTURY_SHIFT 20 /* years before this are assumed to be 2000's */
/*
 * DATE OPERATORS
 */
#define OP_FIRST_DOM 0x01 /* get date of first day of current month */
#define OP_LAST_DOM  0x02 /* get date of last day of current month; LY == 2/28) */
#define OP_SAME_LY   0x03 /* get date for same day/month, last year */
#define OP_SAME_LQ   0x04 /* get date for same offset in the prior quarter */

extern char *weekday_names[];

#endif /* R_DATE_H */

} // __date__


// sparse.h

namespace __sparse__ {

using namespace __porting__;
/*
 * Legal Notice
 *
 * This document and associated source code (the "Work") is a part of a
 * benchmark specification maintained by the TPC.
 *
 * The TPC reserves all right, title, and interest to the Work as provided
 * under U.S. and international laws, including without limitation all patent
 * and trademark rights therein.
 *
 * No Warranty
 *
 * 1.1 TO THE MAXIMUM EXTENT PERMITTED BY APPLICABLE LAW, THE INFORMATION
 *     CONTAINED HEREIN IS PROVIDED "AS IS" AND WITH ALL FAULTS, AND THE
 *     AUTHORS AND DEVELOPERS OF THE WORK HEREBY DISCLAIM ALL OTHER
 *     WARRANTIES AND CONDITIONS, EITHER EXPRESS, IMPLIED OR STATUTORY,
 *     INCLUDING, BUT NOT LIMITED TO, ANY (IF ANY) IMPLIED WARRANTIES,
 *     DUTIES OR CONDITIONS OF MERCHANTABILITY, OF FITNESS FOR A PARTICULAR
 *     PURPOSE, OF ACCURACY OR COMPLETENESS OF RESPONSES, OF RESULTS, OF
 *     WORKMANLIKE EFFORT, OF LACK OF VIRUSES, AND OF LACK OF NEGLIGENCE.
 *     ALSO, THERE IS NO WARRANTY OR CONDITION OF TITLE, QUIET ENJOYMENT,
 *     QUIET POSSESSION, CORRESPONDENCE TO DESCRIPTION OR NON-INFRINGEMENT
 *     WITH REGARD TO THE WORK.
 * 1.2 IN NO EVENT WILL ANY AUTHOR OR DEVELOPER OF THE WORK BE LIABLE TO
 *     ANY OTHER PARTY FOR ANY DAMAGES, INCLUDING BUT NOT LIMITED TO THE
 *     COST OF PROCURING SUBSTITUTE GOODS OR SERVICES, LOST PROFITS, LOSS
 *     OF USE, LOSS OF DATA, OR ANY INCIDENTAL, CONSEQUENTIAL, DIRECT,
 *     INDIRECT, OR SPECIAL DAMAGES WHETHER UNDER CONTRACT, TORT, WARRANTY,
 *     OR OTHERWISE, ARISING IN ANY WAY OUT OF THIS OR ANY OTHER AGREEMENT
 *     RELATING TO THE WORK, WHETHER OR NOT SUCH AUTHOR OR DEVELOPER HAD
 *     ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES.
 *
 * Contributors:
 * Gradient Systems
 */
int initSparseKeys(int nTable);                    /* populate the set of valid keys */
ds_key_t randomSparseKey(int nTable, int nColumn); /* select a random sparse key */

} // __sparse__


// nulls.h

namespace __nulls__ {

using namespace __porting__;
/*
 * Legal Notice
 *
 * This document and associated source code (the "Work") is a part of a
 * benchmark specification maintained by the TPC.
 *
 * The TPC reserves all right, title, and interest to the Work as provided
 * under U.S. and international laws, including without limitation all patent
 * and trademark rights therein.
 *
 * No Warranty
 *
 * 1.1 TO THE MAXIMUM EXTENT PERMITTED BY APPLICABLE LAW, THE INFORMATION
 *     CONTAINED HEREIN IS PROVIDED "AS IS" AND WITH ALL FAULTS, AND THE
 *     AUTHORS AND DEVELOPERS OF THE WORK HEREBY DISCLAIM ALL OTHER
 *     WARRANTIES AND CONDITIONS, EITHER EXPRESS, IMPLIED OR STATUTORY,
 *     INCLUDING, BUT NOT LIMITED TO, ANY (IF ANY) IMPLIED WARRANTIES,
 *     DUTIES OR CONDITIONS OF MERCHANTABILITY, OF FITNESS FOR A PARTICULAR
 *     PURPOSE, OF ACCURACY OR COMPLETENESS OF RESPONSES, OF RESULTS, OF
 *     WORKMANLIKE EFFORT, OF LACK OF VIRUSES, AND OF LACK OF NEGLIGENCE.
 *     ALSO, THERE IS NO WARRANTY OR CONDITION OF TITLE, QUIET ENJOYMENT,
 *     QUIET POSSESSION, CORRESPONDENCE TO DESCRIPTION OR NON-INFRINGEMENT
 *     WITH REGARD TO THE WORK.
 * 1.2 IN NO EVENT WILL ANY AUTHOR OR DEVELOPER OF THE WORK BE LIABLE TO
 *     ANY OTHER PARTY FOR ANY DAMAGES, INCLUDING BUT NOT LIMITED TO THE
 *     COST OF PROCURING SUBSTITUTE GOODS OR SERVICES, LOST PROFITS, LOSS
 *     OF USE, LOSS OF DATA, OR ANY INCIDENTAL, CONSEQUENTIAL, DIRECT,
 *     INDIRECT, OR SPECIAL DAMAGES WHETHER UNDER CONTRACT, TORT, WARRANTY,
 *     OR OTHERWISE, ARISING IN ANY WAY OUT OF THIS OR ANY OTHER AGREEMENT
 *     RELATING TO THE WORK, WHETHER OR NOT SUCH AUTHOR OR DEVELOPER HAD
 *     ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES.
 *
 * Contributors:
 * Gradient Systems
 */

#ifndef R_NULLCHECK_H
#define R_NULLCHECK_H

int nullCheck(int nColumn);
void nullSet(ds_key_t *pDest, int nStream);

#endif

} // __nulls__


// permute.h

namespace __permute__ {

using namespace __porting__;
/*
 * Legal Notice
 *
 * This document and associated source code (the "Work") is a part of a
 * benchmark specification maintained by the TPC.
 *
 * The TPC reserves all right, title, and interest to the Work as provided
 * under U.S. and international laws, including without limitation all patent
 * and trademark rights therein.
 *
 * No Warranty
 *
 * 1.1 TO THE MAXIMUM EXTENT PERMITTED BY APPLICABLE LAW, THE INFORMATION
 *     CONTAINED HEREIN IS PROVIDED "AS IS" AND WITH ALL FAULTS, AND THE
 *     AUTHORS AND DEVELOPERS OF THE WORK HEREBY DISCLAIM ALL OTHER
 *     WARRANTIES AND CONDITIONS, EITHER EXPRESS, IMPLIED OR STATUTORY,
 *     INCLUDING, BUT NOT LIMITED TO, ANY (IF ANY) IMPLIED WARRANTIES,
 *     DUTIES OR CONDITIONS OF MERCHANTABILITY, OF FITNESS FOR A PARTICULAR
 *     PURPOSE, OF ACCURACY OR COMPLETENESS OF RESPONSES, OF RESULTS, OF
 *     WORKMANLIKE EFFORT, OF LACK OF VIRUSES, AND OF LACK OF NEGLIGENCE.
 *     ALSO, THERE IS NO WARRANTY OR CONDITION OF TITLE, QUIET ENJOYMENT,
 *     QUIET POSSESSION, CORRESPONDENCE TO DESCRIPTION OR NON-INFRINGEMENT
 *     WITH REGARD TO THE WORK.
 * 1.2 IN NO EVENT WILL ANY AUTHOR OR DEVELOPER OF THE WORK BE LIABLE TO
 *     ANY OTHER PARTY FOR ANY DAMAGES, INCLUDING BUT NOT LIMITED TO THE
 *     COST OF PROCURING SUBSTITUTE GOODS OR SERVICES, LOST PROFITS, LOSS
 *     OF USE, LOSS OF DATA, OR ANY INCIDENTAL, CONSEQUENTIAL, DIRECT,
 *     INDIRECT, OR SPECIAL DAMAGES WHETHER UNDER CONTRACT, TORT, WARRANTY,
 *     OR OTHERWISE, ARISING IN ANY WAY OUT OF THIS OR ANY OTHER AGREEMENT
 *     RELATING TO THE WORK, WHETHER OR NOT SUCH AUTHOR OR DEVELOPER HAD
 *     ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES.
 *
 * Contributors:
 * Gradient Systems
 */
int *makePermutation(int *pNumberSet, int nSize, int nStream);
ds_key_t *makeKeyPermutation(ds_key_t *pNumberSet, ds_key_t nSize, int nStream);
#define getPermutationEntry(pPermutation, nIndex) (pPermutation[nIndex - 1] + 1)

} // __permute__


// genrand.h

namespace __genrand__ {

/*
 * Legal Notice
 *
 * This document and associated source code (the "Work") is a part of a
 * benchmark specification maintained by the TPC.
 *
 * The TPC reserves all right, title, and interest to the Work as provided
 * under U.S. and international laws, including without limitation all patent
 * and trademark rights therein.
 *
 * No Warranty
 *
 * 1.1 TO THE MAXIMUM EXTENT PERMITTED BY APPLICABLE LAW, THE INFORMATION
 *     CONTAINED HEREIN IS PROVIDED "AS IS" AND WITH ALL FAULTS, AND THE
 *     AUTHORS AND DEVELOPERS OF THE WORK HEREBY DISCLAIM ALL OTHER
 *     WARRANTIES AND CONDITIONS, EITHER EXPRESS, IMPLIED OR STATUTORY,
 *     INCLUDING, BUT NOT LIMITED TO, ANY (IF ANY) IMPLIED WARRANTIES,
 *     DUTIES OR CONDITIONS OF MERCHANTABILITY, OF FITNESS FOR A PARTICULAR
 *     PURPOSE, OF ACCURACY OR COMPLETENESS OF RESPONSES, OF RESULTS, OF
 *     WORKMANLIKE EFFORT, OF LACK OF VIRUSES, AND OF LACK OF NEGLIGENCE.
 *     ALSO, THERE IS NO WARRANTY OR CONDITION OF TITLE, QUIET ENJOYMENT,
 *     QUIET POSSESSION, CORRESPONDENCE TO DESCRIPTION OR NON-INFRINGEMENT
 *     WITH REGARD TO THE WORK.
 * 1.2 IN NO EVENT WILL ANY AUTHOR OR DEVELOPER OF THE WORK BE LIABLE TO
 *     ANY OTHER PARTY FOR ANY DAMAGES, INCLUDING BUT NOT LIMITED TO THE
 *     COST OF PROCURING SUBSTITUTE GOODS OR SERVICES, LOST PROFITS, LOSS
 *     OF USE, LOSS OF DATA, OR ANY INCIDENTAL, CONSEQUENTIAL, DIRECT,
 *     INDIRECT, OR SPECIAL DAMAGES WHETHER UNDER CONTRACT, TORT, WARRANTY,
 *     OR OTHERWISE, ARISING IN ANY WAY OUT OF THIS OR ANY OTHER AGREEMENT
 *     RELATING TO THE WORK, WHETHER OR NOT SUCH AUTHOR OR DEVELOPER HAD
 *     ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES.
 *
 * Contributors:
 * Gradient Systems
 */
#ifndef GENRAND_H
#define GENRAND_H

using namespace __decimal__;
using namespace __date__;
using namespace __dist__;
using namespace __address__;
#define JMS 1

typedef struct RNG_T {
	int nUsed;
	int nUsedPerRow;
	long nSeed;
	long nInitialSeed; /* used to allow skip_row() to back up */
	int nColumn;       /* column where this stream is used */
	int nTable;        /* table where this stream is used */
	int nDuplicateOf;  /* duplicate streams allow independent tables to share
	                      data streams */
#ifdef JMS
	ds_key_t nTotal;
#endif
} rng_t;
extern rng_t Streams[];

#define FL_SEED_OVERRUN 0x0001

#define ALPHANUM "abcdefghijklmnopqrstuvxyzABCDEFGHIJKLMNOPQRSTUVXYZ0123456789"
#define DIGITS   "0123456789"

#define RNG_SEED 19620718

int genrand_integer(int *dest, int dist, int min, int max, int mean, int stream);
int genrand_decimal(decimal_t *dest, int dist, decimal_t *min, decimal_t *max, decimal_t *mean, int stream);
int genrand_date(date_t *dest, int dist, date_t *min, date_t *max, date_t *mean, int stream);
ds_key_t genrand_key(ds_key_t *dest, int dist, ds_key_t min, ds_key_t max, ds_key_t mean, int stream);
int gen_charset(char *dest, char *set, int min, int max, int stream);
int dump_seeds_ds(int tbl);
void init_rand(void);
void skip_random(int s, ds_key_t count);
int RNGReset(int nTable);
long next_random(int nStream);
void genrand_email(char *pEmail, char *pFirst, char *pLast, int nColumn);
void genrand_ipaddr(char *pDest, int nColumn);
int genrand_url(char *pDest, int nColumn);
int setSeed(int nStream, int nValue);
void resetSeeds(int nTable);

#endif

} // __genrand__


// streams.h

namespace __streams__ {

using namespace __genrand__;
/*
 * THIS IS A GENERATED FILE
 * SEE COLUMNS.LIST
 */
#ifndef STREAMS_H
#define STREAMS_H
rng_t Streams[] = {
    {0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, CC_CALL_CENTER_SK, CALL_CENTER, CC_CALL_CENTER_SK},
    {0, 15, 0, 0, CC_CALL_CENTER_ID, CALL_CENTER, CC_CALL_CENTER_ID},
    {0, 10, 0, 0, CC_REC_START_DATE_ID, CALL_CENTER, CC_REC_START_DATE_ID},
    {0, 1, 0, 0, CC_REC_END_DATE_ID, CALL_CENTER, CC_REC_END_DATE_ID},
    {0, 4, 0, 0, CC_CLOSED_DATE_ID, CALL_CENTER, CC_CLOSED_DATE_ID},
    {0, 10, 0, 0, CC_OPEN_DATE_ID, CALL_CENTER, CC_OPEN_DATE_ID},
    {0, 0, 0, 0, CC_NAME, CALL_CENTER, CC_NAME},
    {0, 2, 0, 0, CC_CLASS, CALL_CENTER, CC_CLASS},
    {0, 1, 0, 0, CC_EMPLOYEES, CALL_CENTER, CC_EMPLOYEES},
    {0, 1, 0, 0, CC_SQ_FT, CALL_CENTER, CC_SQ_FT},
    {0, 1, 0, 0, CC_HOURS, CALL_CENTER, CC_HOURS},
    {0, 2, 0, 0, CC_MANAGER, CALL_CENTER, CC_MANAGER},
    {0, 1, 0, 0, CC_MARKET_ID, CALL_CENTER, CC_MARKET_ID},
    {0, 50, 0, 0, CC_MARKET_CLASS, CALL_CENTER, CC_MARKET_CLASS},
    {0, 50, 0, 0, CC_MARKET_DESC, CALL_CENTER, CC_MARKET_DESC},
    {0, 2, 0, 0, CC_MARKET_MANAGER, CALL_CENTER, CC_MARKET_MANAGER},
    {0, 2, 0, 0, CC_DIVISION, CALL_CENTER, CC_DIVISION},
    {0, 2, 0, 0, CC_DIVISION_NAME, CALL_CENTER, CC_DIVISION_NAME},
    {0, 2, 0, 0, CC_COMPANY, CALL_CENTER, CC_COMPANY},
    {0, 2, 0, 0, CC_COMPANY_NAME, CALL_CENTER, CC_COMPANY_NAME},
    {0, 0, 0, 0, CC_STREET_NUMBER, CALL_CENTER, CC_STREET_NUMBER},
    {0, 0, 0, 0, CC_STREET_NAME, CALL_CENTER, CC_STREET_NAME},
    {0, 0, 0, 0, CC_STREET_TYPE, CALL_CENTER, CC_STREET_TYPE},
    {0, 0, 0, 0, CC_SUITE_NUMBER, CALL_CENTER, CC_SUITE_NUMBER},
    {0, 0, 0, 0, CC_CITY, CALL_CENTER, CC_CITY},
    {0, 0, 0, 0, CC_COUNTY, CALL_CENTER, CC_COUNTY},
    {0, 0, 0, 0, CC_STATE, CALL_CENTER, CC_STATE},
    {0, 0, 0, 0, CC_ZIP, CALL_CENTER, CC_ZIP},
    {0, 0, 0, 0, CC_COUNTRY, CALL_CENTER, CC_COUNTRY},
    {0, 0, 0, 0, CC_GMT_OFFSET, CALL_CENTER, CC_GMT_OFFSET},
    {0, 15, 0, 0, CC_ADDRESS, CALL_CENTER, CC_ADDRESS},
    {0, 1, 0, 0, CC_TAX_PERCENTAGE, CALL_CENTER, CC_TAX_PERCENTAGE},
    {0, 1, 0, 0, CC_SCD, CALL_CENTER, CC_SCD},
    {0, 2, 0, 0, CC_NULLS, CALL_CENTER, CC_NULLS},
    {0, 1, 0, 0, CP_CATALOG_PAGE_SK, CATALOG_PAGE, CP_CATALOG_PAGE_SK},
    {0, 1, 0, 0, CP_CATALOG_PAGE_ID, CATALOG_PAGE, CP_CATALOG_PAGE_ID},
    {0, 1, 0, 0, CP_START_DATE_ID, CATALOG_PAGE, CP_START_DATE_ID},
    {0, 1, 0, 0, CP_END_DATE_ID, CATALOG_PAGE, CP_END_DATE_ID},
    {0, 1, 0, 0, CP_PROMO_ID, CATALOG_PAGE, CP_PROMO_ID},
    {0, 1, 0, 0, CP_DEPARTMENT, CATALOG_PAGE, CP_DEPARTMENT},
    {0, 1, 0, 0, CP_CATALOG_NUMBER, CATALOG_PAGE, CP_CATALOG_NUMBER},
    {0, 1, 0, 0, CP_CATALOG_PAGE_NUMBER, CATALOG_PAGE, CP_CATALOG_PAGE_NUMBER},
    {0, 100, 0, 0, CP_DESCRIPTION, CATALOG_PAGE, S_CP_DESCRIPTION},
    {0, 1, 0, 0, CP_TYPE, CATALOG_PAGE, CP_TYPE},
    {0, 2, 0, 0, CP_NULLS, CATALOG_PAGE, CP_NULLS},
    {0, 28, 0, 0, CR_RETURNED_DATE_SK, CATALOG_RETURNS, CR_RETURNED_DATE_SK},
    {0, 28, 0, 0, CR_RETURNED_TIME_SK, CATALOG_RETURNS, CR_RETURNED_TIME_SK},
    {0, 14, 0, 0, CR_ITEM_SK, CATALOG_RETURNS, CR_ITEM_SK},
    {0, 14, 0, 0, CR_REFUNDED_CUSTOMER_SK, CATALOG_RETURNS, CR_REFUNDED_CUSTOMER_SK},
    {0, 14, 0, 0, CR_REFUNDED_CDEMO_SK, CATALOG_RETURNS, CR_REFUNDED_CDEMO_SK},
    {0, 14, 0, 0, CR_REFUNDED_HDEMO_SK, CATALOG_RETURNS, CR_REFUNDED_HDEMO_SK},
    {0, 14, 0, 0, CR_REFUNDED_ADDR_SK, CATALOG_RETURNS, CR_REFUNDED_ADDR_SK},
    {0, 28, 0, 0, CR_RETURNING_CUSTOMER_SK, CATALOG_RETURNS, CR_RETURNING_CUSTOMER_SK},
    {0, 14, 0, 0, CR_RETURNING_CDEMO_SK, CATALOG_RETURNS, CR_RETURNING_CDEMO_SK},
    {0, 14, 0, 0, CR_RETURNING_HDEMO_SK, CATALOG_RETURNS, CR_RETURNING_HDEMO_SK},
    {0, 14, 0, 0, CR_RETURNING_ADDR_SK, CATALOG_RETURNS, CR_RETURNING_ADDR_SK},
    {0, 0, 0, 0, CR_CALL_CENTER_SK, CATALOG_RETURNS, CR_CALL_CENTER_SK},
    {0, 14, 0, 0, CR_CATALOG_PAGE_SK, CATALOG_RETURNS, CR_CATALOG_PAGE_SK},
    {0, 14, 0, 0, CR_SHIP_MODE_SK, CATALOG_RETURNS, CR_SHIP_MODE_SK},
    {0, 14, 0, 0, CR_WAREHOUSE_SK, CATALOG_RETURNS, CR_WAREHOUSE_SK},
    {0, 14, 0, 0, CR_REASON_SK, CATALOG_RETURNS, CR_REASON_SK},
    {0, 0, 0, 0, CR_ORDER_NUMBER, CATALOG_RETURNS, CR_ORDER_NUMBER},
    {0, 0, 0, 0, CR_PRICING_QUANTITY, CATALOG_RETURNS, CR_PRICING_QUANTITY},
    {0, 0, 0, 0, CR_PRICING_NET_PAID, CATALOG_RETURNS, CR_PRICING_NET_PAID},
    {0, 0, 0, 0, CR_PRICING_EXT_TAX, CATALOG_RETURNS, CR_PRICING_EXT_TAX},
    {0, 0, 0, 0, CR_PRICING_NET_PAID_INC_TAX, CATALOG_RETURNS, CR_PRICING_NET_PAID_INC_TAX},
    {0, 0, 0, 0, CR_PRICING_FEE, CATALOG_RETURNS, CR_PRICING_FEE},
    {0, 0, 0, 0, CR_PRICING_EXT_SHIP_COST, CATALOG_RETURNS, CR_PRICING_EXT_SHIP_COST},
    {0, 0, 0, 0, CR_PRICING_REFUNDED_CASH, CATALOG_RETURNS, CR_PRICING_REFUNDED_CASH},
    {0, 0, 0, 0, CR_PRICING_REVERSED_CHARGE, CATALOG_RETURNS, CR_PRICING_REVERSED_CHARGE},
    {0, 0, 0, 0, CR_PRICING_STORE_CREDIT, CATALOG_RETURNS, CR_PRICING_STORE_CREDIT},
    {0, 0, 0, 0, CR_PRICING_NET_LOSS, CATALOG_RETURNS, CR_PRICING_NET_LOSS},
    {0, 28, 0, 0, CR_NULLS, CATALOG_RETURNS, CR_NULLS},
    {0, 70, 0, 0, CR_PRICING, CATALOG_RETURNS, CR_PRICING},
    {0, 1, 0, 0, CS_SOLD_DATE_SK, CATALOG_SALES, CS_SOLD_DATE_SK},
    {0, 2, 0, 0, CS_SOLD_TIME_SK, CATALOG_SALES, CS_SOLD_TIME_SK},
    {0, 14, 0, 0, CS_SHIP_DATE_SK, CATALOG_SALES, CS_SHIP_DATE_SK},
    {0, 1, 0, 0, CS_BILL_CUSTOMER_SK, CATALOG_SALES, CS_BILL_CUSTOMER_SK},
    {0, 1, 0, 0, CS_BILL_CDEMO_SK, CATALOG_SALES, CS_BILL_CDEMO_SK},
    {0, 1, 0, 0, CS_BILL_HDEMO_SK, CATALOG_SALES, CS_BILL_HDEMO_SK},
    {0, 1, 0, 0, CS_BILL_ADDR_SK, CATALOG_SALES, CS_BILL_ADDR_SK},
    {0, 2, 0, 0, CS_SHIP_CUSTOMER_SK, CATALOG_SALES, CS_SHIP_CUSTOMER_SK},
    {0, 1, 0, 0, CS_SHIP_CDEMO_SK, CATALOG_SALES, CS_SHIP_CDEMO_SK},
    {0, 1, 0, 0, CS_SHIP_HDEMO_SK, CATALOG_SALES, CS_SHIP_HDEMO_SK},
    {0, 1, 0, 0, CS_SHIP_ADDR_SK, CATALOG_SALES, CS_SHIP_ADDR_SK},
    {0, 1, 0, 0, CS_CALL_CENTER_SK, CATALOG_SALES, CS_CALL_CENTER_SK},
    {0, 42, 0, 0, CS_CATALOG_PAGE_SK, CATALOG_SALES, CS_CATALOG_PAGE_SK},
    {0, 14, 0, 0, CS_SHIP_MODE_SK, CATALOG_SALES, CS_SHIP_MODE_SK},
    {0, 14, 0, 0, CS_WAREHOUSE_SK, CATALOG_SALES, CS_WAREHOUSE_SK},
    {0, 1, 0, 0, CS_SOLD_ITEM_SK, CATALOG_SALES, CS_SOLD_ITEM_SK},
    {0, 14, 0, 0, CS_PROMO_SK, CATALOG_SALES, CS_PROMO_SK},
    {0, 1, 0, 0, CS_ORDER_NUMBER, CATALOG_SALES, CS_ORDER_NUMBER},
    {0, 0, 0, 0, CS_PRICING_QUANTITY, CATALOG_SALES, CS_PRICING_QUANTITY},
    {0, 0, 0, 0, CS_PRICING_WHOLESALE_COST, CATALOG_SALES, CS_PRICING_WHOLESALE_COST},
    {0, 0, 0, 0, CS_PRICING_LIST_PRICE, CATALOG_SALES, CS_PRICING_LIST_PRICE},
    {0, 0, 0, 0, CS_PRICING_SALES_PRICE, CATALOG_SALES, CS_PRICING_SALES_PRICE},
    {0, 0, 0, 0, CS_PRICING_COUPON_AMT, CATALOG_SALES, CS_PRICING_COUPON_AMT},
    {0, 0, 0, 0, CS_PRICING_EXT_SALES_PRICE, CATALOG_SALES, CS_PRICING_EXT_SALES_PRICE},
    {0, 0, 0, 0, CS_PRICING_EXT_DISCOUNT_AMOUNT, CATALOG_SALES, CS_PRICING_EXT_DISCOUNT_AMOUNT},
    {0, 0, 0, 0, CS_PRICING_EXT_WHOLESALE_COST, CATALOG_SALES, CS_PRICING_EXT_WHOLESALE_COST},
    {0, 0, 0, 0, CS_PRICING_EXT_LIST_PRICE, CATALOG_SALES, CS_PRICING_EXT_LIST_PRICE},
    {0, 0, 0, 0, CS_PRICING_EXT_TAX, CATALOG_SALES, CS_PRICING_EXT_TAX},
    {0, 0, 0, 0, CS_PRICING_EXT_SHIP_COST, CATALOG_SALES, CS_PRICING_EXT_SHIP_COST},
    {0, 0, 0, 0, CS_PRICING_NET_PAID, CATALOG_SALES, CS_PRICING_NET_PAID},
    {0, 0, 0, 0, CS_PRICING_NET_PAID_INC_TAX, CATALOG_SALES, CS_PRICING_NET_PAID_INC_TAX},
    {0, 0, 0, 0, CS_PRICING_NET_PAID_INC_SHIP, CATALOG_SALES, CS_PRICING_NET_PAID_INC_SHIP},
    {0, 0, 0, 0, CS_PRICING_NET_PAID_INC_SHIP_TAX, CATALOG_SALES, CS_PRICING_NET_PAID_INC_SHIP_TAX},
    {0, 0, 0, 0, CS_PRICING_NET_PROFIT, CATALOG_SALES, CS_PRICING_NET_PROFIT},
    {0, 112, 0, 0, CS_PRICING, CATALOG_SALES, CS_PRICING},
    {0, 0, 0, 0, CS_PERMUTE, CATALOG_SALES, CS_PERMUTE},
    {0, 28, 0, 0, CS_NULLS, CATALOG_SALES, CS_NULLS},
    {0, 14, 0, 0, CR_IS_RETURNED, CATALOG_SALES, CR_IS_RETURNED},
    {0, 0, 0, 0, CS_PERMUTATION, CATALOG_SALES, CS_PERMUTATION},
    {0, 1, 0, 0, C_CUSTOMER_SK, CUSTOMER, C_CUSTOMER_SK},
    {0, 1, 0, 0, C_CUSTOMER_ID, CUSTOMER, C_CUSTOMER_ID},
    {0, 1, 0, 0, C_CURRENT_CDEMO_SK, CUSTOMER, C_CURRENT_CDEMO_SK},
    {0, 1, 0, 0, C_CURRENT_HDEMO_SK, CUSTOMER, C_CURRENT_HDEMO_SK},
    {0, 1, 0, 0, C_CURRENT_ADDR_SK, CUSTOMER, C_CURRENT_ADDR_SK},
    {0, 0, 0, 0, C_FIRST_SHIPTO_DATE_ID, CUSTOMER, C_FIRST_SHIPTO_DATE_ID},
    {0, 1, 0, 0, C_FIRST_SALES_DATE_ID, CUSTOMER, C_FIRST_SALES_DATE_ID},
    {0, 1, 0, 0, C_SALUTATION, CUSTOMER, C_SALUTATION},
    {0, 1, 0, 0, C_FIRST_NAME, CUSTOMER, C_FIRST_NAME},
    {0, 1, 0, 0, C_LAST_NAME, CUSTOMER, C_LAST_NAME},
    {0, 2, 0, 0, C_PREFERRED_CUST_FLAG, CUSTOMER, C_PREFERRED_CUST_FLAG},
    {0, 1, 0, 0, C_BIRTH_DAY, CUSTOMER, C_BIRTH_DAY},
    {0, 0, 0, 0, C_BIRTH_MONTH, CUSTOMER, C_BIRTH_MONTH},
    {0, 0, 0, 0, C_BIRTH_YEAR, CUSTOMER, C_BIRTH_YEAR},
    {0, 1, 0, 0, C_BIRTH_COUNTRY, CUSTOMER, C_BIRTH_COUNTRY},
    {0, 1, 0, 0, C_LOGIN, CUSTOMER, C_LOGIN},
    {0, 23, 0, 0, C_EMAIL_ADDRESS, CUSTOMER, C_EMAIL_ADDRESS},
    {0, 1, 0, 0, C_LAST_REVIEW_DATE, CUSTOMER, C_LAST_REVIEW_DATE},
    {0, 2, 0, 0, C_NULLS, CUSTOMER, C_NULLS},
    {0, 1, 0, 0, CA_ADDRESS_SK, CUSTOMER_ADDRESS, CA_ADDRESS_SK},
    {0, 1, 0, 0, CA_ADDRESS_ID, CUSTOMER_ADDRESS, CA_ADDRESS_ID},
    {0, 1, 0, 0, CA_ADDRESS_STREET_NUM, CUSTOMER_ADDRESS, CA_ADDRESS_STREET_NUM},
    {0, 1, 0, 0, CA_ADDRESS_STREET_NAME1, CUSTOMER_ADDRESS, CA_ADDRESS_STREET_NAME1},
    {0, 1, 0, 0, CA_ADDRESS_STREET_TYPE, CUSTOMER_ADDRESS, CA_ADDRESS_STREET_TYPE},
    {0, 1, 0, 0, CA_ADDRESS_SUITE_NUM, CUSTOMER_ADDRESS, CA_ADDRESS_SUITE_NUM},
    {0, 1, 0, 0, CA_ADDRESS_CITY, CUSTOMER_ADDRESS, CA_ADDRESS_CITY},
    {0, 1, 0, 0, CA_ADDRESS_COUNTY, CUSTOMER_ADDRESS, CA_ADDRESS_COUNTY},
    {0, 1, 0, 0, CA_ADDRESS_STATE, CUSTOMER_ADDRESS, CA_ADDRESS_STATE},
    {0, 1, 0, 0, CA_ADDRESS_ZIP, CUSTOMER_ADDRESS, CA_ADDRESS_ZIP},
    {0, 1, 0, 0, CA_ADDRESS_COUNTRY, CUSTOMER_ADDRESS, CA_ADDRESS_COUNTRY},
    {0, 1, 0, 0, CA_ADDRESS_GMT_OFFSET, CUSTOMER_ADDRESS, CA_ADDRESS_GMT_OFFSET},
    {0, 1, 0, 0, CA_LOCATION_TYPE, CUSTOMER_ADDRESS, CA_LOCATION_TYPE},
    {0, 2, 0, 0, CA_NULLS, CUSTOMER_ADDRESS, CA_NULLS},
    {0, 7, 0, 0, CA_ADDRESS, CUSTOMER_ADDRESS, CA_ADDRESS},
    {0, 1, 0, 0, CA_ADDRESS_STREET_NAME2, CUSTOMER_ADDRESS, CA_ADDRESS_STREET_NAME2},
    {0, 1, 0, 0, CD_DEMO_SK, CUSTOMER_DEMOGRAPHICS, CD_DEMO_SK},
    {0, 1, 0, 0, CD_GENDER, CUSTOMER_DEMOGRAPHICS, CD_GENDER},
    {0, 1, 0, 0, CD_MARITAL_STATUS, CUSTOMER_DEMOGRAPHICS, CD_MARITAL_STATUS},
    {0, 1, 0, 0, CD_EDUCATION_STATUS, CUSTOMER_DEMOGRAPHICS, CD_EDUCATION_STATUS},
    {0, 1, 0, 0, CD_PURCHASE_ESTIMATE, CUSTOMER_DEMOGRAPHICS, CD_PURCHASE_ESTIMATE},
    {0, 1, 0, 0, CD_CREDIT_RATING, CUSTOMER_DEMOGRAPHICS, CD_CREDIT_RATING},
    {0, 1, 0, 0, CD_DEP_COUNT, CUSTOMER_DEMOGRAPHICS, CD_DEP_COUNT},
    {0, 1, 0, 0, CD_DEP_EMPLOYED_COUNT, CUSTOMER_DEMOGRAPHICS, CD_DEP_EMPLOYED_COUNT},
    {0, 1, 0, 0, CD_DEP_COLLEGE_COUNT, CUSTOMER_DEMOGRAPHICS, CD_DEP_COLLEGE_COUNT},
    {0, 2, 0, 0, CD_NULLS, CUSTOMER_DEMOGRAPHICS, CD_NULLS},
    {0, 0, 0, 0, D_DATE_SK, DATET, D_DATE_SK},
    {0, 0, 0, 0, D_DATE_ID, DATET, D_DATE_ID},
    {0, 0, 0, 0, D_DATE, DATET, D_DATE},
    {0, 0, 0, 0, D_MONTH_SEQ, DATET, D_MONTH_SEQ},
    {0, 0, 0, 0, D_WEEK_SEQ, DATET, D_WEEK_SEQ},
    {0, 0, 0, 0, D_QUARTER_SEQ, DATET, D_QUARTER_SEQ},
    {0, 0, 0, 0, D_YEAR, DATET, D_YEAR},
    {0, 0, 0, 0, D_DOW, DATET, D_DOW},
    {0, 0, 0, 0, D_MOY, DATET, D_MOY},
    {0, 0, 0, 0, D_DOM, DATET, D_DOM},
    {0, 0, 0, 0, D_QOY, DATET, D_QOY},
    {0, 0, 0, 0, D_FY_YEAR, DATET, D_FY_YEAR},
    {0, 0, 0, 0, D_FY_QUARTER_SEQ, DATET, D_FY_QUARTER_SEQ},
    {0, 0, 0, 0, D_FY_WEEK_SEQ, DATET, D_FY_WEEK_SEQ},
    {0, 0, 0, 0, D_DAY_NAME, DATET, D_DAY_NAME},
    {0, 0, 0, 0, D_QUARTER_NAME, DATET, D_QUARTER_NAME},
    {0, 0, 0, 0, D_HOLIDAY, DATET, D_HOLIDAY},
    {0, 0, 0, 0, D_WEEKEND, DATET, D_WEEKEND},
    {0, 0, 0, 0, D_FOLLOWING_HOLIDAY, DATET, D_FOLLOWING_HOLIDAY},
    {0, 0, 0, 0, D_FIRST_DOM, DATET, D_FIRST_DOM},
    {0, 0, 0, 0, D_LAST_DOM, DATET, D_LAST_DOM},
    {0, 0, 0, 0, D_SAME_DAY_LY, DATET, D_SAME_DAY_LY},
    {0, 0, 0, 0, D_SAME_DAY_LQ, DATET, D_SAME_DAY_LQ},
    {0, 0, 0, 0, D_CURRENT_DAY, DATET, D_CURRENT_DAY},
    {0, 0, 0, 0, D_CURRENT_WEEK, DATET, D_CURRENT_WEEK},
    {0, 0, 0, 0, D_CURRENT_MONTH, DATET, D_CURRENT_MONTH},
    {0, 0, 0, 0, D_CURRENT_QUARTER, DATET, D_CURRENT_QUARTER},
    {0, 0, 0, 0, D_CURRENT_YEAR, DATET, D_CURRENT_YEAR},
    {0, 2, 0, 0, D_NULLS, DATET, D_NULLS},
    {0, 1, 0, 0, HD_DEMO_SK, HOUSEHOLD_DEMOGRAPHICS, HD_DEMO_SK},
    {0, 1, 0, 0, HD_INCOME_BAND_ID, HOUSEHOLD_DEMOGRAPHICS, HD_INCOME_BAND_ID},
    {0, 1, 0, 0, HD_BUY_POTENTIAL, HOUSEHOLD_DEMOGRAPHICS, HD_BUY_POTENTIAL},
    {0, 1, 0, 0, HD_DEP_COUNT, HOUSEHOLD_DEMOGRAPHICS, HD_DEP_COUNT},
    {0, 1, 0, 0, HD_VEHICLE_COUNT, HOUSEHOLD_DEMOGRAPHICS, HD_VEHICLE_COUNT},
    {0, 2, 0, 0, HD_NULLS, HOUSEHOLD_DEMOGRAPHICS, HD_NULLS},
    {0, 1, 0, 0, IB_INCOME_BAND_ID, INCOME_BAND, IB_INCOME_BAND_ID},
    {0, 1, 0, 0, IB_LOWER_BOUND, INCOME_BAND, IB_LOWER_BOUND},
    {0, 1, 0, 0, IB_UPPER_BOUND, INCOME_BAND, IB_UPPER_BOUND},
    {0, 2, 0, 0, IB_NULLS, INCOME_BAND, IB_NULLS},
    {0, 1, 0, 0, INV_DATE_SK, INVENTORY, INV_DATE_SK},
    {0, 1, 0, 0, INV_ITEM_SK, INVENTORY, INV_ITEM_SK},
    {0, 1, 0, 0, INV_WAREHOUSE_SK, INVENTORY, INV_WAREHOUSE_SK},
    {0, 1, 0, 0, INV_QUANTITY_ON_HAND, INVENTORY, INV_QUANTITY_ON_HAND},
    {0, 2, 0, 0, INV_NULLS, INVENTORY, INV_NULLS},
    {0, 1, 0, 0, I_ITEM_SK, ITEM, I_ITEM_SK},
    {0, 1, 0, 0, I_ITEM_ID, ITEM, I_ITEM_ID},
    {0, 1, 0, 0, I_REC_START_DATE_ID, ITEM, I_REC_START_DATE_ID},
    {0, 2, 0, 0, I_REC_END_DATE_ID, ITEM, I_REC_END_DATE_ID},
    {0, 200, 0, 0, I_ITEM_DESC, ITEM, S_ITEM_DESC},
    {0, 2, 0, 0, I_CURRENT_PRICE, ITEM, I_CURRENT_PRICE},
    {0, 1, 0, 0, I_WHOLESALE_COST, ITEM, I_WHOLESALE_COST},
    {0, 1, 0, 0, I_BRAND_ID, ITEM, I_BRAND_ID},
    {0, 1, 0, 0, I_BRAND, ITEM, I_BRAND},
    {0, 1, 0, 0, I_CLASS_ID, ITEM, I_CLASS_ID},
    {0, 1, 0, 0, I_CLASS, ITEM, I_CLASS},
    {0, 1, 0, 0, I_CATEGORY_ID, ITEM, I_CATEGORY_ID},
    {0, 1, 0, 0, I_CATEGORY, ITEM, I_CATEGORY},
    {0, 2, 0, 0, I_MANUFACT_ID, ITEM, I_MANUFACT_ID},
    {0, 1, 0, 0, I_MANUFACT, ITEM, I_MANUFACT},
    {0, 1, 0, 0, I_SIZE, ITEM, I_SIZE},
    {0, 50, 0, 0, I_FORMULATION, ITEM, I_FORMULATION},
    {0, 1, 0, 0, I_COLOR, ITEM, I_COLOR},
    {0, 1, 0, 0, I_UNITS, ITEM, I_UNITS},
    {0, 1, 0, 0, I_CONTAINER, ITEM, I_CONTAINER},
    {0, 2, 0, 0, I_MANAGER_ID, ITEM, I_MANAGER_ID},
    {0, 1, 0, 0, I_PRODUCT_NAME, ITEM, I_PRODUCT_NAME},
    {0, 2, 0, 0, I_NULLS, ITEM, I_NULLS},
    {0, 1, 0, 0, I_SCD, ITEM, I_SCD},
    {0, 2, 0, 0, I_PROMO_SK, ITEM, I_PROMO_SK},
    {0, 1, 0, 0, P_PROMO_SK, PROMOTION, P_PROMO_SK},
    {0, 1, 0, 0, P_PROMO_ID, PROMOTION, P_PROMO_ID},
    {0, 1, 0, 0, P_START_DATE_ID, PROMOTION, P_START_DATE_ID},
    {0, 1, 0, 0, P_END_DATE_ID, PROMOTION, P_END_DATE_ID},
    {0, 1, 0, 0, P_ITEM_SK, PROMOTION, P_ITEM_SK},
    {0, 1, 0, 0, P_COST, PROMOTION, P_COST},
    {0, 1, 0, 0, P_RESPONSE_TARGET, PROMOTION, P_RESPONSE_TARGET},
    {0, 1, 0, 0, P_PROMO_NAME, PROMOTION, P_PROMO_NAME},
    {0, 1, 0, 0, P_CHANNEL_DMAIL, PROMOTION, P_CHANNEL_DMAIL},
    {0, 1, 0, 0, P_CHANNEL_EMAIL, PROMOTION, P_CHANNEL_EMAIL},
    {0, 1, 0, 0, P_CHANNEL_CATALOG, PROMOTION, P_CHANNEL_CATALOG},
    {0, 1, 0, 0, P_CHANNEL_TV, PROMOTION, P_CHANNEL_TV},
    {0, 1, 0, 0, P_CHANNEL_RADIO, PROMOTION, P_CHANNEL_RADIO},
    {0, 1, 0, 0, P_CHANNEL_PRESS, PROMOTION, P_CHANNEL_PRESS},
    {0, 1, 0, 0, P_CHANNEL_EVENT, PROMOTION, P_CHANNEL_EVENT},
    {0, 1, 0, 0, P_CHANNEL_DEMO, PROMOTION, P_CHANNEL_DEMO},
    {0, 100, 0, 0, P_CHANNEL_DETAILS, PROMOTION, P_CHANNEL_DETAILS},
    {0, 1, 0, 0, P_PURPOSE, PROMOTION, P_PURPOSE},
    {0, 1, 0, 0, P_DISCOUNT_ACTIVE, PROMOTION, P_DISCOUNT_ACTIVE},
    {0, 2, 0, 0, P_NULLS, PROMOTION, P_NULLS},
    {0, 1, 0, 0, R_REASON_SK, REASON, R_REASON_SK},
    {0, 1, 0, 0, R_REASON_ID, REASON, R_REASON_ID},
    {0, 1, 0, 0, R_REASON_DESCRIPTION, REASON, R_REASON_DESCRIPTION},
    {0, 2, 0, 0, R_NULLS, REASON, R_NULLS},
    {0, 1, 0, 0, SM_SHIP_MODE_SK, SHIP_MODE, SM_SHIP_MODE_SK},
    {0, 1, 0, 0, SM_SHIP_MODE_ID, SHIP_MODE, SM_SHIP_MODE_ID},
    {0, 1, 0, 0, SM_TYPE, SHIP_MODE, SM_TYPE},
    {0, 1, 0, 0, SM_CODE, SHIP_MODE, SM_CODE},
    {0, 21, 0, 0, SM_CONTRACT, SHIP_MODE, SM_CONTRACT},
    {0, 1, 0, 0, SM_CARRIER, SHIP_MODE, SM_CARRIER},
    {0, 2, 0, 0, SM_NULLS, SHIP_MODE, SM_NULLS},
    {0, 1, 0, 0, W_STORE_SK, STORE, W_STORE_SK},
    {0, 1, 0, 0, W_STORE_ID, STORE, W_STORE_ID},
    {0, 1, 0, 0, W_STORE_REC_START_DATE_ID, STORE, W_STORE_REC_START_DATE_ID},
    {0, 2, 0, 0, W_STORE_REC_END_DATE_ID, STORE, W_STORE_REC_END_DATE_ID},
    {0, 2, 0, 0, W_STORE_CLOSED_DATE_ID, STORE, W_STORE_CLOSED_DATE_ID},
    {0, 0, 0, 0, W_STORE_NAME, STORE, W_STORE_NAME},
    {0, 1, 0, 0, W_STORE_EMPLOYEES, STORE, W_STORE_EMPLOYEES},
    {0, 1, 0, 0, W_STORE_FLOOR_SPACE, STORE, W_STORE_FLOOR_SPACE},
    {0, 1, 0, 0, W_STORE_HOURS, STORE, W_STORE_HOURS},
    {0, 2, 0, 0, W_STORE_MANAGER, STORE, W_STORE_MANAGER},
    {0, 1, 0, 0, W_STORE_MARKET_ID, STORE, W_STORE_MARKET_ID},
    {0, 1, 0, 0, W_STORE_TAX_PERCENTAGE, STORE, W_STORE_TAX_PERCENTAGE},
    {0, 1, 0, 0, W_STORE_GEOGRAPHY_CLASS, STORE, W_STORE_GEOGRAPHY_CLASS},
    {0, 100, 0, 0, W_STORE_MARKET_DESC, STORE, W_STORE_MARKET_DESC},
    {0, 2, 0, 0, W_STORE_MARKET_MANAGER, STORE, W_STORE_MARKET_MANAGER},
    {0, 1, 0, 0, W_STORE_DIVISION_ID, STORE, W_STORE_DIVISION_ID},
    {0, 1, 0, 0, W_STORE_DIVISION_NAME, STORE, W_STORE_DIVISION_NAME},
    {0, 1, 0, 0, W_STORE_COMPANY_ID, STORE, W_STORE_COMPANY_ID},
    {0, 1, 0, 0, W_STORE_COMPANY_NAME, STORE, W_STORE_COMPANY_NAME},
    {0, 1, 0, 0, W_STORE_ADDRESS_STREET_NUM, STORE, W_STORE_ADDRESS_STREET_NUM},
    {0, 1, 0, 0, W_STORE_ADDRESS_STREET_NAME1, STORE, W_STORE_ADDRESS_STREET_NAME1},
    {0, 1, 0, 0, W_STORE_ADDRESS_STREET_TYPE, STORE, W_STORE_ADDRESS_STREET_TYPE},
    {0, 1, 0, 0, W_STORE_ADDRESS_SUITE_NUM, STORE, W_STORE_ADDRESS_SUITE_NUM},
    {0, 1, 0, 0, W_STORE_ADDRESS_CITY, STORE, W_STORE_ADDRESS_CITY},
    {0, 1, 0, 0, W_STORE_ADDRESS_COUNTY, STORE, W_STORE_ADDRESS_COUNTY},
    {0, 1, 0, 0, W_STORE_ADDRESS_STATE, STORE, W_STORE_ADDRESS_STATE},
    {0, 1, 0, 0, W_STORE_ADDRESS_ZIP, STORE, W_STORE_ADDRESS_ZIP},
    {0, 1, 0, 0, W_STORE_ADDRESS_COUNTRY, STORE, W_STORE_ADDRESS_COUNTRY},
    {0, 1, 0, 0, W_STORE_ADDRESS_GMT_OFFSET, STORE, W_STORE_ADDRESS_GMT_OFFSET},
    {0, 2, 0, 0, W_STORE_NULLS, STORE, W_STORE_NULLS},
    {0, 1, 0, 0, W_STORE_TYPE, STORE, W_STORE_TYPE},
    {0, 1, 0, 0, W_STORE_SCD, STORE, W_STORE_SCD},
    {0, 7, 0, 0, W_STORE_ADDRESS, STORE, W_STORE_ADDRESS},
    {0, 32, 0, 0, SR_RETURNED_DATE_SK, STORE_RETURNS, SR_RETURNED_DATE_SK},
    {0, 32, 0, 0, SR_RETURNED_TIME_SK, STORE_RETURNS, SR_RETURNED_TIME_SK},
    {0, 16, 0, 0, SR_ITEM_SK, STORE_RETURNS, SR_ITEM_SK},
    {0, 16, 0, 0, SR_CUSTOMER_SK, STORE_RETURNS, SR_CUSTOMER_SK},
    {0, 16, 0, 0, SR_CDEMO_SK, STORE_RETURNS, SR_CDEMO_SK},
    {0, 16, 0, 0, SR_HDEMO_SK, STORE_RETURNS, SR_HDEMO_SK},
    {0, 16, 0, 0, SR_ADDR_SK, STORE_RETURNS, SR_ADDR_SK},
    {0, 16, 0, 0, SR_STORE_SK, STORE_RETURNS, SR_STORE_SK},
    {0, 16, 0, 0, SR_REASON_SK, STORE_RETURNS, SR_REASON_SK},
    {0, 16, 0, 0, SR_TICKET_NUMBER, STORE_RETURNS, SR_TICKET_NUMBER},
    {0, 0, 0, 0, SR_PRICING_QUANTITY, STORE_RETURNS, SR_PRICING_QUANTITY},
    {0, 0, 0, 0, SR_PRICING_NET_PAID, STORE_RETURNS, SR_PRICING_NET_PAID},
    {0, 0, 0, 0, SR_PRICING_EXT_TAX, STORE_RETURNS, SR_PRICING_EXT_TAX},
    {0, 0, 0, 0, SR_PRICING_NET_PAID_INC_TAX, STORE_RETURNS, SR_PRICING_NET_PAID_INC_TAX},
    {0, 0, 0, 0, SR_PRICING_FEE, STORE_RETURNS, SR_PRICING_FEE},
    {0, 0, 0, 0, SR_PRICING_EXT_SHIP_COST, STORE_RETURNS, SR_PRICING_EXT_SHIP_COST},
    {0, 0, 0, 0, SR_PRICING_REFUNDED_CASH, STORE_RETURNS, SR_PRICING_REFUNDED_CASH},
    {0, 0, 0, 0, SR_PRICING_REVERSED_CHARGE, STORE_RETURNS, SR_PRICING_REVERSED_CHARGE},
    {0, 0, 0, 0, SR_PRICING_STORE_CREDIT, STORE_RETURNS, SR_PRICING_STORE_CREDIT},
    {0, 0, 0, 0, SR_PRICING_NET_LOSS, STORE_RETURNS, SR_PRICING_NET_LOSS},
    {0, 80, 0, 0, SR_PRICING, STORE_RETURNS, SR_PRICING},
    {0, 32, 0, 0, SR_NULLS, STORE_RETURNS, SR_NULLS},
    {0, 2, 0, 0, SS_SOLD_DATE_SK, STORE_SALES, SS_SOLD_DATE_SK},
    {0, 2, 0, 0, SS_SOLD_TIME_SK, STORE_SALES, SS_SOLD_TIME_SK},
    {0, 1, 0, 0, SS_SOLD_ITEM_SK, STORE_SALES, SS_SOLD_ITEM_SK},
    {0, 1, 0, 0, SS_SOLD_CUSTOMER_SK, STORE_SALES, SS_SOLD_CUSTOMER_SK},
    {0, 1, 0, 0, SS_SOLD_CDEMO_SK, STORE_SALES, SS_SOLD_CDEMO_SK},
    {0, 1, 0, 0, SS_SOLD_HDEMO_SK, STORE_SALES, SS_SOLD_HDEMO_SK},
    {0, 1, 0, 0, SS_SOLD_ADDR_SK, STORE_SALES, SS_SOLD_ADDR_SK},
    {0, 1, 0, 0, SS_SOLD_STORE_SK, STORE_SALES, SS_SOLD_STORE_SK},
    {0, 16, 0, 0, SS_SOLD_PROMO_SK, STORE_SALES, SS_SOLD_PROMO_SK},
    {0, 1, 0, 0, SS_TICKET_NUMBER, STORE_SALES, SS_TICKET_NUMBER},
    {0, 1, 0, 0, SS_PRICING_QUANTITY, STORE_SALES, SS_PRICING_QUANTITY},
    {0, 0, 0, 0, SS_PRICING_WHOLESALE_COST, STORE_SALES, SS_PRICING_WHOLESALE_COST},
    {0, 0, 0, 0, SS_PRICING_LIST_PRICE, STORE_SALES, SS_PRICING_LIST_PRICE},
    {0, 0, 0, 0, SS_PRICING_SALES_PRICE, STORE_SALES, SS_PRICING_SALES_PRICE},
    {0, 0, 0, 0, SS_PRICING_COUPON_AMT, STORE_SALES, SS_PRICING_COUPON_AMT},
    {0, 0, 0, 0, SS_PRICING_EXT_SALES_PRICE, STORE_SALES, SS_PRICING_EXT_SALES_PRICE},
    {0, 0, 0, 0, SS_PRICING_EXT_WHOLESALE_COST, STORE_SALES, SS_PRICING_EXT_WHOLESALE_COST},
    {0, 0, 0, 0, SS_PRICING_EXT_LIST_PRICE, STORE_SALES, SS_PRICING_EXT_LIST_PRICE},
    {0, 0, 0, 0, SS_PRICING_EXT_TAX, STORE_SALES, SS_PRICING_EXT_TAX},
    {0, 0, 0, 0, SS_PRICING_NET_PAID, STORE_SALES, SS_PRICING_NET_PAID},
    {0, 0, 0, 0, SS_PRICING_NET_PAID_INC_TAX, STORE_SALES, SS_PRICING_NET_PAID_INC_TAX},
    {0, 0, 0, 0, SS_PRICING_NET_PROFIT, STORE_SALES, SS_PRICING_NET_PROFIT},
    {0, 16, 0, 0, SR_IS_RETURNED, STORE_SALES, SR_IS_RETURNED},
    {0, 128, 0, 0, SS_PRICING, STORE_SALES, SS_PRICING},
    {0, 32, 0, 0, SS_NULLS, STORE_SALES, SS_NULLS},
    {0, 0, 0, 0, SS_PERMUTATION, STORE_SALES, SS_PERMUTATION},
    {0, 1, 0, 0, T_TIME_SK, TIME, T_TIME_SK},
    {0, 1, 0, 0, T_TIME_ID, TIME, T_TIME_ID},
    {0, 1, 0, 0, T_TIME, TIME, T_TIME},
    {0, 1, 0, 0, T_HOUR, TIME, T_HOUR},
    {0, 1, 0, 0, T_MINUTE, TIME, T_MINUTE},
    {0, 1, 0, 0, T_SECOND, TIME, T_SECOND},
    {0, 1, 0, 0, T_AM_PM, TIME, T_AM_PM},
    {0, 1, 0, 0, T_SHIFT, TIME, T_SHIFT},
    {0, 1, 0, 0, T_SUB_SHIFT, TIME, T_SUB_SHIFT},
    {0, 1, 0, 0, T_MEAL_TIME, TIME, T_MEAL_TIME},
    {0, 2, 0, 0, T_NULLS, TIME, T_NULLS},
    {0, 1, 0, 0, W_WAREHOUSE_SK, WAREHOUSE, W_WAREHOUSE_SK},
    {0, 1, 0, 0, W_WAREHOUSE_ID, WAREHOUSE, W_WAREHOUSE_ID},
    {0, 80, 0, 0, W_WAREHOUSE_NAME, WAREHOUSE, W_WAREHOUSE_NAME},
    {0, 1, 0, 0, W_WAREHOUSE_SQ_FT, WAREHOUSE, W_WAREHOUSE_SQ_FT},
    {0, 1, 0, 0, W_ADDRESS_STREET_NUM, WAREHOUSE, W_ADDRESS_STREET_NUM},
    {0, 1, 0, 0, W_ADDRESS_STREET_NAME1, WAREHOUSE, W_ADDRESS_STREET_NAME1},
    {0, 1, 0, 0, W_ADDRESS_STREET_TYPE, WAREHOUSE, W_ADDRESS_STREET_TYPE},
    {0, 1, 0, 0, W_ADDRESS_SUITE_NUM, WAREHOUSE, W_ADDRESS_SUITE_NUM},
    {0, 1, 0, 0, W_ADDRESS_CITY, WAREHOUSE, W_ADDRESS_CITY},
    {0, 1, 0, 0, W_ADDRESS_COUNTY, WAREHOUSE, W_ADDRESS_COUNTY},
    {0, 1, 0, 0, W_ADDRESS_STATE, WAREHOUSE, W_ADDRESS_STATE},
    {0, 1, 0, 0, W_ADDRESS_ZIP, WAREHOUSE, W_ADDRESS_ZIP},
    {0, 1, 0, 0, W_ADDRESS_COUNTRY, WAREHOUSE, W_ADDRESS_COUNTRY},
    {0, 1, 0, 0, W_ADDRESS_GMT_OFFSET, WAREHOUSE, W_ADDRESS_GMT_OFFSET},
    {0, 2, 0, 0, W_NULLS, WAREHOUSE, W_NULLS},
    {0, 7, 0, 0, W_WAREHOUSE_ADDRESS, WAREHOUSE, W_WAREHOUSE_ADDRESS},
    {0, 1, 0, 0, WP_PAGE_SK, WEB_PAGE, WP_PAGE_SK},
    {0, 1, 0, 0, WP_PAGE_ID, WEB_PAGE, WP_PAGE_ID},
    {0, 1, 0, 0, WP_REC_START_DATE_ID, WEB_PAGE, WP_REC_START_DATE_ID},
    {0, 1, 0, 0, WP_REC_END_DATE_ID, WEB_PAGE, WP_REC_END_DATE_ID},
    {0, 2, 0, 0, WP_CREATION_DATE_SK, WEB_PAGE, WP_CREATION_DATE_SK},
    {0, 1, 0, 0, WP_ACCESS_DATE_SK, WEB_PAGE, WP_ACCESS_DATE_SK},
    {0, 1, 0, 0, WP_AUTOGEN_FLAG, WEB_PAGE, WP_AUTOGEN_FLAG},
    {0, 1, 0, 0, WP_CUSTOMER_SK, WEB_PAGE, WP_CUSTOMER_SK},
    {0, 1, 0, 0, WP_URL, WEB_PAGE, WP_URL},
    {0, 1, 0, 0, WP_TYPE, WEB_PAGE, WP_TYPE},
    {0, 1, 0, 0, WP_CHAR_COUNT, WEB_PAGE, WP_CHAR_COUNT},
    {0, 1, 0, 0, WP_LINK_COUNT, WEB_PAGE, WP_LINK_COUNT},
    {0, 1, 0, 0, WP_IMAGE_COUNT, WEB_PAGE, WP_IMAGE_COUNT},
    {0, 1, 0, 0, WP_MAX_AD_COUNT, WEB_PAGE, WP_MAX_AD_COUNT},
    {0, 2, 0, 0, WP_NULLS, WEB_PAGE, WP_NULLS},
    {0, 1, 0, 0, WP_SCD, WEB_PAGE, WP_SCD},
    {0, 32, 0, 0, WR_RETURNED_DATE_SK, WEB_RETURNS, WR_RETURNED_DATE_SK},
    {0, 32, 0, 0, WR_RETURNED_TIME_SK, WEB_RETURNS, WR_RETURNED_TIME_SK},
    {0, 16, 0, 0, WR_ITEM_SK, WEB_RETURNS, WR_ITEM_SK},
    {0, 16, 0, 0, WR_REFUNDED_CUSTOMER_SK, WEB_RETURNS, WR_REFUNDED_CUSTOMER_SK},
    {0, 16, 0, 0, WR_REFUNDED_CDEMO_SK, WEB_RETURNS, WR_REFUNDED_CDEMO_SK},
    {0, 16, 0, 0, WR_REFUNDED_HDEMO_SK, WEB_RETURNS, WR_REFUNDED_HDEMO_SK},
    {0, 16, 0, 0, WR_REFUNDED_ADDR_SK, WEB_RETURNS, WR_REFUNDED_ADDR_SK},
    {0, 16, 0, 0, WR_RETURNING_CUSTOMER_SK, WEB_RETURNS, WR_RETURNING_CUSTOMER_SK},
    {0, 16, 0, 0, WR_RETURNING_CDEMO_SK, WEB_RETURNS, WR_RETURNING_CDEMO_SK},
    {0, 16, 0, 0, WR_RETURNING_HDEMO_SK, WEB_RETURNS, WR_RETURNING_HDEMO_SK},
    {0, 16, 0, 0, WR_RETURNING_ADDR_SK, WEB_RETURNS, WR_RETURNING_ADDR_SK},
    {0, 16, 0, 0, WR_WEB_PAGE_SK, WEB_RETURNS, WR_WEB_PAGE_SK},
    {0, 16, 0, 0, WR_REASON_SK, WEB_RETURNS, WR_REASON_SK},
    {0, 0, 0, 0, WR_ORDER_NUMBER, WEB_RETURNS, WR_ORDER_NUMBER},
    {0, 0, 0, 0, WR_PRICING_QUANTITY, WEB_RETURNS, WR_PRICING_QUANTITY},
    {0, 0, 0, 0, WR_PRICING_NET_PAID, WEB_RETURNS, WR_PRICING_NET_PAID},
    {0, 0, 0, 0, WR_PRICING_EXT_TAX, WEB_RETURNS, WR_PRICING_EXT_TAX},
    {0, 0, 0, 0, WR_PRICING_NET_PAID_INC_TAX, WEB_RETURNS, WR_PRICING_NET_PAID_INC_TAX},
    {0, 0, 0, 0, WR_PRICING_FEE, WEB_RETURNS, WR_PRICING_FEE},
    {0, 0, 0, 0, WR_PRICING_EXT_SHIP_COST, WEB_RETURNS, WR_PRICING_EXT_SHIP_COST},
    {0, 0, 0, 0, WR_PRICING_REFUNDED_CASH, WEB_RETURNS, WR_PRICING_REFUNDED_CASH},
    {0, 0, 0, 0, WR_PRICING_REVERSED_CHARGE, WEB_RETURNS, WR_PRICING_REVERSED_CHARGE},
    {0, 0, 0, 0, WR_PRICING_STORE_CREDIT, WEB_RETURNS, WR_PRICING_STORE_CREDIT},
    {0, 0, 0, 0, WR_PRICING_NET_LOSS, WEB_RETURNS, WR_PRICING_NET_LOSS},
    {0, 80, 0, 0, WR_PRICING, WEB_RETURNS, WR_PRICING},
    {0, 32, 0, 0, WR_NULLS, WEB_RETURNS, WR_NULLS},
    {0, 2, 0, 0, WS_SOLD_DATE_SK, WEB_SALES, WS_SOLD_DATE_SK},
    {0, 2, 0, 0, WS_SOLD_TIME_SK, WEB_SALES, WS_SOLD_TIME_SK},
    {0, 16, 0, 0, WS_SHIP_DATE_SK, WEB_SALES, WS_SHIP_DATE_SK},
    {0, 1, 0, 0, WS_ITEM_SK, WEB_SALES, WS_ITEM_SK},
    {0, 1, 0, 0, WS_BILL_CUSTOMER_SK, WEB_SALES, WS_BILL_CUSTOMER_SK},
    {0, 1, 0, 0, WS_BILL_CDEMO_SK, WEB_SALES, WS_BILL_CDEMO_SK},
    {0, 1, 0, 0, WS_BILL_HDEMO_SK, WEB_SALES, WS_BILL_HDEMO_SK},
    {0, 1, 0, 0, WS_BILL_ADDR_SK, WEB_SALES, WS_BILL_ADDR_SK},
    {0, 2, 0, 0, WS_SHIP_CUSTOMER_SK, WEB_SALES, WS_SHIP_CUSTOMER_SK},
    {0, 2, 0, 0, WS_SHIP_CDEMO_SK, WEB_SALES, WS_SHIP_CDEMO_SK},
    {0, 1, 0, 0, WS_SHIP_HDEMO_SK, WEB_SALES, WS_SHIP_HDEMO_SK},
    {0, 1, 0, 0, WS_SHIP_ADDR_SK, WEB_SALES, WS_SHIP_ADDR_SK},
    {0, 16, 0, 0, WS_WEB_PAGE_SK, WEB_SALES, WS_WEB_PAGE_SK},
    {0, 16, 0, 0, WS_WEB_SITE_SK, WEB_SALES, WS_WEB_SITE_SK},
    {0, 16, 0, 0, WS_SHIP_MODE_SK, WEB_SALES, WS_SHIP_MODE_SK},
    {0, 16, 0, 0, WS_WAREHOUSE_SK, WEB_SALES, WS_WAREHOUSE_SK},
    {0, 16, 0, 0, WS_PROMO_SK, WEB_SALES, WS_PROMO_SK},
    {0, 1, 0, 0, WS_ORDER_NUMBER, WEB_SALES, WS_ORDER_NUMBER},
    {0, 1, 0, 0, WS_PRICING_QUANTITY, WEB_SALES, WS_PRICING_QUANTITY},
    {0, 1, 0, 0, WS_PRICING_WHOLESALE_COST, WEB_SALES, WS_PRICING_WHOLESALE_COST},
    {0, 0, 0, 0, WS_PRICING_LIST_PRICE, WEB_SALES, WS_PRICING_LIST_PRICE},
    {0, 0, 0, 0, WS_PRICING_SALES_PRICE, WEB_SALES, WS_PRICING_SALES_PRICE},
    {0, 0, 0, 0, WS_PRICING_EXT_DISCOUNT_AMT, WEB_SALES, WS_PRICING_EXT_DISCOUNT_AMT},
    {0, 0, 0, 0, WS_PRICING_EXT_SALES_PRICE, WEB_SALES, WS_PRICING_EXT_SALES_PRICE},
    {0, 0, 0, 0, WS_PRICING_EXT_WHOLESALE_COST, WEB_SALES, WS_PRICING_EXT_WHOLESALE_COST},
    {0, 0, 0, 0, WS_PRICING_EXT_LIST_PRICE, WEB_SALES, WS_PRICING_EXT_LIST_PRICE},
    {0, 0, 0, 0, WS_PRICING_EXT_TAX, WEB_SALES, WS_PRICING_EXT_TAX},
    {0, 0, 0, 0, WS_PRICING_COUPON_AMT, WEB_SALES, WS_PRICING_COUPON_AMT},
    {0, 0, 0, 0, WS_PRICING_EXT_SHIP_COST, WEB_SALES, WS_PRICING_EXT_SHIP_COST},
    {0, 0, 0, 0, WS_PRICING_NET_PAID, WEB_SALES, WS_PRICING_NET_PAID},
    {0, 0, 0, 0, WS_PRICING_NET_PAID_INC_TAX, WEB_SALES, WS_PRICING_NET_PAID_INC_TAX},
    {0, 0, 0, 0, WS_PRICING_NET_PAID_INC_SHIP, WEB_SALES, WS_PRICING_NET_PAID_INC_SHIP},
    {0, 0, 0, 0, WS_PRICING_NET_PAID_INC_SHIP_TAX, WEB_SALES, WS_PRICING_NET_PAID_INC_SHIP_TAX},
    {0, 0, 0, 0, WS_PRICING_NET_PROFIT, WEB_SALES, WS_PRICING_NET_PROFIT},
    {0, 128, 0, 0, WS_PRICING, WEB_SALES, WS_PRICING},
    {0, 32, 0, 0, WS_NULLS, WEB_SALES, WS_NULLS},
    {0, 16, 0, 0, WR_IS_RETURNED, WEB_SALES, WR_IS_RETURNED},
    {0, 0, 0, 0, WS_PERMUTATION, WEB_SALES, WS_PERMUTATION},
    {0, 1, 0, 0, WEB_SITE_SK, WEB_SITE, WEB_SITE_SK},
    {0, 1, 0, 0, WEB_SITE_ID, WEB_SITE, WEB_SITE_ID},
    {0, 1, 0, 0, WEB_REC_START_DATE_ID, WEB_SITE, WEB_REC_START_DATE_ID},
    {0, 1, 0, 0, WEB_REC_END_DATE_ID, WEB_SITE, WEB_REC_END_DATE_ID},
    {0, 1, 0, 0, WEB_NAME, WEB_SITE, WEB_NAME},
    {0, 1, 0, 0, WEB_OPEN_DATE, WEB_SITE, WEB_OPEN_DATE},
    {0, 1, 0, 0, WEB_CLOSE_DATE, WEB_SITE, WEB_CLOSE_DATE},
    {0, 1, 0, 0, WEB_CLASS, WEB_SITE, WEB_CLASS},
    {0, 2, 0, 0, WEB_MANAGER, WEB_SITE, WEB_MANAGER},
    {0, 1, 0, 0, WEB_MARKET_ID, WEB_SITE, WEB_MARKET_ID},
    {0, 20, 0, 0, WEB_MARKET_CLASS, WEB_SITE, WEB_MARKET_CLASS},
    {0, 100, 0, 0, WEB_MARKET_DESC, WEB_SITE, WEB_MARKET_DESC},
    {0, 2, 0, 0, WEB_MARKET_MANAGER, WEB_SITE, WEB_MARKET_MANAGER},
    {0, 1, 0, 0, WEB_COMPANY_ID, WEB_SITE, WEB_COMPANY_ID},
    {0, 1, 0, 0, WEB_COMPANY_NAME, WEB_SITE, WEB_COMPANY_NAME},
    {0, 1, 0, 0, WEB_ADDRESS_STREET_NUM, WEB_SITE, WEB_ADDRESS_STREET_NUM},
    {0, 1, 0, 0, WEB_ADDRESS_STREET_NAME1, WEB_SITE, WEB_ADDRESS_STREET_NAME1},
    {0, 1, 0, 0, WEB_ADDRESS_STREET_TYPE, WEB_SITE, WEB_ADDRESS_STREET_TYPE},
    {0, 1, 0, 0, WEB_ADDRESS_SUITE_NUM, WEB_SITE, WEB_ADDRESS_SUITE_NUM},
    {0, 1, 0, 0, WEB_ADDRESS_CITY, WEB_SITE, WEB_ADDRESS_CITY},
    {0, 1, 0, 0, WEB_ADDRESS_COUNTY, WEB_SITE, WEB_ADDRESS_COUNTY},
    {0, 1, 0, 0, WEB_ADDRESS_STATE, WEB_SITE, WEB_ADDRESS_STATE},
    {0, 1, 0, 0, WEB_ADDRESS_ZIP, WEB_SITE, WEB_ADDRESS_ZIP},
    {0, 1, 0, 0, WEB_ADDRESS_COUNTRY, WEB_SITE, WEB_ADDRESS_COUNTRY},
    {0, 1, 0, 0, WEB_ADDRESS_GMT_OFFSET, WEB_SITE, WEB_ADDRESS_GMT_OFFSET},
    {0, 1, 0, 0, WEB_TAX_PERCENTAGE, WEB_SITE, WEB_TAX_PERCENTAGE},
    {0, 2, 0, 0, WEB_NULLS, WEB_SITE, WEB_NULLS},
    {0, 7, 0, 0, WEB_ADDRESS, WEB_SITE, WEB_ADDRESS},
    {0, 70, 0, 0, WEB_SCD, WEB_SITE, WEB_SCD},
    {0, 0, 0, 0, DV_VERSION, DBGEN_VERSION, DV_VERSION},
    {0, 0, 0, 0, DV_CREATE_DATE, DBGEN_VERSION, DV_CREATE_DATE},
    {0, 0, 0, 0, DV_CREATE_TIME, DBGEN_VERSION, DV_CREATE_TIME},
    {0, 0, 0, 0, DV_CMDLINE_ARGS, DBGEN_VERSION, DV_CMDLINE_ARGS},
    {0, 0, 0, 0, VALIDATE_STREAM, DBGEN_VERSION, VALIDATE_STREAM},
    {0, 0, 0, 0, S_BRAND_ID, S_BRAND, S_BRAND_ID},
    {0, 0, 0, 0, S_BRAND_SUBCLASS_ID, S_BRAND, S_BRAND_SUBCLASS_ID},
    {0, 1, 0, 0, S_BRAND_MANAGER_ID, S_BRAND, S_BRAND_MANAGER_ID},
    {0, 1, 0, 0, S_BRAND_MANUFACTURER_ID, S_BRAND, S_BRAND_MANUFACTURER_ID},
    {0, 6, 0, 0, S_BRAND_NAME, S_BRAND, S_BRAND_NAME},
    {0, 0, 0, 0, S_CADR_ID, S_CUSTOMER_ADDRESS, S_CADR_ID},
    {0, 1, 0, 0, S_CADR_ADDRESS_STREET_NUMBER, S_CUSTOMER_ADDRESS, S_CADR_ADDRESS_STREET_NUMBER},
    {0, 1, 0, 0, S_CADR_ADDRESS_STREET_NAME1, S_CUSTOMER_ADDRESS, S_CADR_ADDRESS_STREET_NAME1},
    {0, 1, 0, 0, S_CADR_ADDRESS_STREET_NAME2, S_CUSTOMER_ADDRESS, S_CADR_ADDRESS_STREET_NAME2},
    {0, 1, 0, 0, S_CADR_ADDRESS_STREET_TYPE, S_CUSTOMER_ADDRESS, S_CADR_ADDRESS_STREET_TYPE},
    {0, 1, 0, 0, S_CADR_ADDRESS_SUITE_NUM, S_CUSTOMER_ADDRESS, S_CADR_ADDRESS_SUITE_NUM},
    {0, 1, 0, 0, S_CADR_ADDRESS_CITY, S_CUSTOMER_ADDRESS, S_CADR_ADDRESS_CITY},
    {0, 1, 0, 0, S_CADR_ADDRESS_COUNTY, S_CUSTOMER_ADDRESS, S_CADR_ADDRESS_COUNTY},
    {0, 1, 0, 0, S_CADR_ADDRESS_STATE, S_CUSTOMER_ADDRESS, S_CADR_ADDRESS_STATE},
    {0, 1, 0, 0, S_CADR_ADDRESS_ZIP, S_CUSTOMER_ADDRESS, S_CADR_ADDRESS_ZIP},
    {0, 1, 0, 0, S_CADR_ADDRESS_COUNTRY, S_CUSTOMER_ADDRESS, S_CADR_ADDRESS_COUNTRY},
    {0, 7, 0, 0, S_BADDR_ADDRESS, S_CUSTOMER_ADDRESS, CA_ADDRESS},
    {0, 1, 0, 0, S_CALL_CENTER_ID, S_CALL_CENTER, S_CALL_CENTER_ID},
    {0, 1, 0, 0, S_CALL_CENTER_DIVISION_ID, S_CALL_CENTER, S_CALL_CENTER_DIVISION_ID},
    {0, 1, 0, 0, S_CALL_CENTER_OPEN_DATE, S_CALL_CENTER, S_CALL_CENTER_OPEN_DATE},
    {0, 0, 0, 0, S_CALL_CENTER_CLOSED_DATE, S_CALL_CENTER, S_CALL_CENTER_CLOSED_DATE},
    {0, 0, 0, 0, S_CALL_CENTER_NAME, S_CALL_CENTER, S_CALL_CENTER_NAME},
    {0, 0, 0, 0, S_CALL_CENTER_CLASS, S_CALL_CENTER, S_CALL_CENTER_CLASS},
    {0, 1, 0, 0, S_CALL_CENTER_EMPLOYEES, S_CALL_CENTER, S_CALL_CENTER_EMPLOYEES},
    {0, 1, 0, 0, S_CALL_CENTER_SQFT, S_CALL_CENTER, S_CALL_CENTER_SQFT},
    {0, 1, 0, 0, S_CALL_CENTER_HOURS, S_CALL_CENTER, S_CALL_CENTER_HOURS},
    {0, 1, 0, 0, S_CALL_CENTER_MANAGER_ID, S_CALL_CENTER, S_CALL_CENTER_MANAGER_ID},
    {0, 1, 0, 0, S_CALL_CENTER_MARKET_ID, S_CALL_CENTER, S_CALL_CENTER_MARKET_ID},
    {0, 1, 0, 0, S_CALL_CENTER_ADDRESS_ID, S_CALL_CENTER, S_CALL_CENTER_ADDRESS_ID},
    {0, 1, 0, 0, S_CALL_CENTER_TAX_PERCENTAGE, S_CALL_CENTER, S_CALL_CENTER_TAX_PERCENTAGE},
    {0, 1, 0, 0, S_CALL_CENTER_SCD, S_CALL_CENTER, S_CALL_CENTER_SCD},
    {0, 0, 0, 0, S_CATALOG_NUMBER, S_CATALOG, S_CATALOG_NUMBER},
    {0, 1, 0, 0, S_CATALOG_START_DATE, S_CATALOG, S_CATALOG_START_DATE},
    {0, 1, 0, 0, S_CATALOG_END_DATE, S_CATALOG, S_CATALOG_END_DATE},
    {0, 10, 0, 0, S_CATALOG_DESC, S_CATALOG, S_CATALOG_DESC},
    {0, 1, 0, 0, S_CATALOG_TYPE, S_CATALOG, S_CATALOG_TYPE},
    {0, 0, 0, 0, S_CORD_ID, S_CATALOG_ORDER, S_CORD_ID},
    {0, 1, 0, 0, S_CORD_BILL_CUSTOMER_ID, S_CATALOG_ORDER, S_CORD_BILL_CUSTOMER_ID},
    {0, 2, 0, 0, S_CORD_SHIP_CUSTOMER_ID, S_CATALOG_ORDER, S_CORD_SHIP_CUSTOMER_ID},
    {0, 1, 0, 0, S_CORD_ORDER_DATE, S_CATALOG_ORDER, S_CORD_ORDER_DATE},
    {0, 1, 0, 0, S_CORD_ORDER_TIME, S_CATALOG_ORDER, S_CORD_ORDER_TIME},
    {0, 1, 0, 0, S_CORD_SHIP_MODE_ID, S_CATALOG_ORDER, S_CORD_SHIP_MODE_ID},
    {0, 1, 0, 0, S_CORD_CALL_CENTER_ID, S_CATALOG_ORDER, S_CORD_CALL_CENTER_ID},
    {0, 1, 0, 0, S_CLIN_ITEM_ID, S_CATALOG_ORDER, S_CLIN_ITEM_ID},
    {0, 100, 0, 0, S_CORD_COMMENT, S_CATALOG_ORDER, S_CORD_COMMENT},
    {0, 1, 0, 0, S_CLIN_ORDER_ID, S_CATALOG_ORDER_LINEITEM, S_CLIN_ORDER_ID},
    {0, 0, 0, 0, S_CLIN_LINE_NUMBER, S_CATALOG_ORDER_LINEITEM, S_CLIN_LINE_NUMBER},
    {0, 1, 0, 0, S_CLIN_PROMOTION_ID, S_CATALOG_ORDER_LINEITEM, S_CLIN_PROMOTION_ID},
    {0, 1, 0, 0, S_CLIN_QUANTITY, S_CATALOG_ORDER_LINEITEM, S_CLIN_QUANTITY},
    {0, 1, 0, 0, S_CLIN_COUPON_AMT, S_CATALOG_ORDER_LINEITEM, S_CLIN_COUPON_AMT},
    {0, 1, 0, 0, S_CLIN_WAREHOUSE_ID, S_CATALOG_ORDER_LINEITEM, S_CLIN_WAREHOUSE_ID},
    {0, 1, 0, 0, S_CLIN_SHIP_DATE, S_CATALOG_ORDER_LINEITEM, S_CLIN_SHIP_DATE},
    {0, 1, 0, 0, S_CLIN_CATALOG_ID, S_CATALOG_ORDER_LINEITEM, S_CLIN_CATALOG_ID},
    {0, 2, 0, 0, S_CLIN_CATALOG_PAGE_ID, S_CATALOG_ORDER_LINEITEM, S_CLIN_CATALOG_PAGE_ID},
    {0, 8, 0, 0, S_CLIN_PRICING, S_CATALOG_ORDER_LINEITEM, S_CLIN_PRICING},
    {0, 0, 0, 0, S_CLIN_SHIP_COST, S_CATALOG_ORDER_LINEITEM, S_CLIN_SHIP_COST},
    {0, 1, 0, 0, S_CLIN_IS_RETURNED, S_CATALOG_ORDER_LINEITEM, S_CLIN_IS_RETURNED},
    {0, 0, 0, 0, S_CLIN_PERMUTE, S_CATALOG_ORDER_LINEITEM, S_CLIN_PERMUTE},
    {0, 0, 0, 0, S_CATALOG_PAGE_CATALOG_NUMBER, S_CATALOG_PAGE, S_CATALOG_PAGE_CATALOG_NUMBER},
    {0, 0, 0, 0, S_CATALOG_PAGE_NUMBER, S_CATALOG_PAGE, S_CATALOG_PAGE_NUMBER},
    {0, 1, 0, 0, S_CATALOG_PAGE_DEPARTMENT, S_CATALOG_PAGE, S_CATALOG_PAGE_DEPARTMENT},
    {0, 1, 0, 0, S_CP_ID, S_CATALOG_PAGE, S_CP_ID},
    {0, 1, 0, 0, S_CP_START_DATE, S_CATALOG_PAGE, S_CP_START_DATE},
    {0, 1, 0, 0, S_CP_END_DATE, S_CATALOG_PAGE, S_CP_END_DATE},
    {0, 100, 0, 0, S_CP_DESCRIPTION, S_CATALOG_PAGE, CP_DESCRIPTION},
    {0, 1, 0, 0, S_CP_TYPE, S_CATALOG_PAGE, S_CP_TYPE},
    {0, 1, 0, 0, S_CATALOG_PROMOTIONAL_ITEM_CATALOG_NUMBER, S_CATALOG_PROMOTIONAL_ITEM,
     S_CATALOG_PROMOTIONAL_ITEM_CATALOG_NUMBER},
    {0, 1, 0, 0, S_CATALOG_PROMOTIONAL_ITEM_CATALOG_PAGE_NUMBER, S_CATALOG_PROMOTIONAL_ITEM,
     S_CATALOG_PROMOTIONAL_ITEM_CATALOG_PAGE_NUMBER},
    {0, 1, 0, 0, S_CATALOG_PROMOTIONAL_ITEM_ITEM_ID, S_CATALOG_PROMOTIONAL_ITEM, S_CATALOG_PROMOTIONAL_ITEM_ITEM_ID},
    {0, 0, 0, 0, S_CATALOG_PROMOTIONAL_ITEM_PROMOTION_ID, S_CATALOG_PROMOTIONAL_ITEM,
     S_CATALOG_PROMOTIONAL_ITEM_PROMOTION_ID},
    {0, 9, 0, 0, S_CRET_CALL_CENTER_ID, S_CATALOG_RETURNS, S_CRET_CALL_CENTER_ID},
    {0, 0, 0, 0, S_CRET_ORDER_ID, S_CATALOG_RETURNS, S_CRET_ORDER_ID},
    {0, 0, 0, 0, S_CRET_LINE_NUMBER, S_CATALOG_RETURNS, S_CRET_LINE_NUMBER},
    {0, 0, 0, 0, S_CRET_ITEM_ID, S_CATALOG_RETURNS, S_CRET_ITEM_ID},
    {0, 0, 0, 0, S_CRET_RETURN_CUSTOMER_ID, S_CATALOG_RETURNS, S_CRET_RETURN_CUSTOMER_ID},
    {0, 0, 0, 0, S_CRET_REFUND_CUSTOMER_ID, S_CATALOG_RETURNS, S_CRET_REFUND_CUSTOMER_ID},
    {0, 9, 0, 0, S_CRET_DATE, S_CATALOG_RETURNS, S_CRET_DATE},
    {0, 18, 0, 0, S_CRET_TIME, S_CATALOG_RETURNS, S_CRET_TIME},
    {0, 0, 0, 0, S_CRET_QUANTITY, S_CATALOG_RETURNS, S_CRET_QUANTITY},
    {0, 0, 0, 0, S_CRET_AMOUNT, S_CATALOG_RETURNS, S_CRET_AMOUNT},
    {0, 0, 0, 0, S_CRET_TAX, S_CATALOG_RETURNS, S_CRET_TAX},
    {0, 0, 0, 0, S_CRET_FEE, S_CATALOG_RETURNS, S_CRET_FEE},
    {0, 0, 0, 0, S_CRET_SHIP_COST, S_CATALOG_RETURNS, S_CRET_SHIP_COST},
    {0, 0, 0, 0, S_CRET_REFUNDED_CASH, S_CATALOG_RETURNS, S_CRET_REFUNDED_CASH},
    {0, 0, 0, 0, S_CRET_REVERSED_CHARGE, S_CATALOG_RETURNS, S_CRET_REVERSED_CHARGE},
    {0, 0, 0, 0, S_CRET_MERCHANT_CREDIT, S_CATALOG_RETURNS, S_CRET_MERCHANT_CREDIT},
    {0, 9, 0, 0, S_CRET_REASON_ID, S_CATALOG_RETURNS, S_CRET_REASON_ID},
    {0, 72, 0, 0, S_CRET_PRICING, S_CATALOG_RETURNS, S_CRET_PRICING},
    {0, 9, 0, 0, S_CRET_SHIPMODE_ID, S_CATALOG_RETURNS, S_CRET_SHIPMODE_ID},
    {0, 9, 0, 0, S_CRET_WAREHOUSE_ID, S_CATALOG_RETURNS, S_CRET_WAREHOUSE_ID},
    {0, 0, 0, 0, S_CRET_CATALOG_PAGE_ID, S_CATALOG_RETURNS, S_CRET_CATALOG_PAGE_ID},
    {0, 0, 0, 0, S_CATEGORY_ID, S_CATEGORY, S_CATEGORY_ID},
    {0, 0, 0, 0, S_CATEGORY_NAME, S_CATEGORY, S_CATEGORY_NAME},
    {0, 10, 0, 0, S_CATEGORY_DESC, S_CATEGORY, S_CATEGORY_DESC},
    {0, 0, 0, 0, S_CLASS_ID, S_CLASS, S_CLASS_ID},
    {0, 1, 0, 0, S_CLASS_SUBCAT_ID, S_CLASS, S_CLASS_SUBCAT_ID},
    {0, 10, 0, 0, S_CLASS_DESC, S_CLASS, S_CLASS_DESC},
    {0, 0, 0, 0, S_COMPANY_ID, S_COMPANY, S_COMPANY_ID},
    {0, 0, 0, 0, S_COMPANY_NAME, S_COMPANY, S_COMPANY_NAME},
    {0, 0, 0, 0, S_CUST_ID, S_CUSTOMER, S_CUST_ID},
    {0, 1, 0, 0, S_CUST_SALUTATION, S_CUSTOMER, S_CUST_SALUTATION},
    {0, 1, 0, 0, S_CUST_LAST_NAME, S_CUSTOMER, S_CUST_LAST_NAME},
    {0, 1, 0, 0, S_CUST_FIRST_NAME, S_CUSTOMER, S_CUST_FIRST_NAME},
    {0, 1, 0, 0, S_CUST_PREFERRED_FLAG, S_CUSTOMER, S_CUST_PREFERRED_FLAG},
    {0, 1, 0, 0, S_CUST_BIRTH_DATE, S_CUSTOMER, S_CUST_BIRTH_DATE},
    {0, 1, 0, 0, S_CUST_FIRST_PURCHASE_DATE, S_CUSTOMER, S_CUST_FIRST_PURCHASE_DATE},
    {0, 1, 0, 0, S_CUST_FIRST_SHIPTO_DATE, S_CUSTOMER, S_CUST_FIRST_SHIPTO_DATE},
    {0, 1, 0, 0, S_CUST_BIRTH_COUNTRY, S_CUSTOMER, S_CUST_BIRTH_COUNTRY},
    {0, 25, 0, 0, S_CUST_LOGIN, S_CUSTOMER, S_CUST_LOGIN},
    {0, 23, 0, 0, S_CUST_EMAIL, S_CUSTOMER, S_CUST_EMAIL},
    {0, 1, 0, 0, S_CUST_LAST_LOGIN, S_CUSTOMER, S_CUST_LAST_LOGIN},
    {0, 1, 0, 0, S_CUST_LAST_REVIEW, S_CUSTOMER, S_CUST_LAST_REVIEW},
    {0, 4, 0, 0, S_CUST_PRIMARY_MACHINE, S_CUSTOMER, S_CUST_PRIMARY_MACHINE},
    {0, 4, 0, 0, S_CUST_SECONDARY_MACHINE, S_CUSTOMER, S_CUST_SECONDARY_MACHINE},
    {0, 7, 0, 0, S_CUST_ADDRESS, S_CUSTOMER, S_CUST_ADDRESS},
    {0, 1, 0, 0, S_CUST_ADDRESS_STREET_NUM, S_CUSTOMER, S_CUST_ADDRESS_STREET_NUM},
    {0, 1, 0, 0, S_CUST_ADDRESS_STREET_NAME1, S_CUSTOMER, S_CUST_ADDRESS_STREET_NAME1},
    {0, 1, 0, 0, S_CUST_ADDRESS_STREET_NAME2, S_CUSTOMER, S_CUST_ADDRESS_STREET_NAME2},
    {0, 1, 0, 0, S_CUST_ADDRESS_STREET_TYPE, S_CUSTOMER, S_CUST_ADDRESS_STREET_TYPE},
    {0, 1, 0, 0, S_CUST_ADDRESS_SUITE_NUM, S_CUSTOMER, S_CUST_ADDRESS_SUITE_NUM},
    {0, 1, 0, 0, S_CUST_ADDRESS_CITY, S_CUSTOMER, S_CUST_ADDRESS_CITY},
    {0, 1, 0, 0, S_CUST_ADDRESS_ZIP, S_CUSTOMER, S_CUST_ADDRESS_ZIP},
    {0, 1, 0, 0, S_CUST_ADDRESS_COUNTY, S_CUSTOMER, S_CUST_ADDRESS_COUNTY},
    {0, 1, 0, 0, S_CUST_ADDRESS_STATE, S_CUSTOMER, S_CUST_ADDRESS_STATE},
    {0, 1, 0, 0, S_CUST_ADDRESS_COUNTRY, S_CUSTOMER, S_CUST_ADDRESS_COUNTRY},
    {0, 1, 0, 0, S_CUST_LOCATION_TYPE, S_CUSTOMER, S_CUST_LOCATION_TYPE},
    {0, 1, 0, 0, S_CUST_GENDER, S_CUSTOMER, S_CUST_GENDER},
    {0, 1, 0, 0, S_CUST_MARITAL_STATUS, S_CUSTOMER, S_CUST_MARITAL_STATUS},
    {0, 1, 0, 0, S_CUST_EDUCATION, S_CUSTOMER, S_CUST_EDUCATION},
    {0, 1, 0, 0, S_CUST_CREDIT_RATING, S_CUSTOMER, S_CUST_CREDIT_RATING},
    {0, 1, 0, 0, S_CUST_PURCHASE_ESTIMATE, S_CUSTOMER, S_CUST_PURCHASE_ESTIMATE},
    {0, 1, 0, 0, S_CUST_BUY_POTENTIAL, S_CUSTOMER, S_CUST_BUY_POTENTIAL},
    {0, 1, 0, 0, S_CUST_DEPENDENT_CNT, S_CUSTOMER, S_CUST_DEPENDENT_CNT},
    {0, 1, 0, 0, S_CUST_EMPLOYED_CNT, S_CUSTOMER, S_CUST_EMPLOYED_CNT},
    {0, 1, 0, 0, S_CUST_COLLEGE_CNT, S_CUSTOMER, S_CUST_COLLEGE_CNT},
    {0, 1, 0, 0, S_CUST_VEHICLE_CNT, S_CUSTOMER, S_CUST_VEHICLE_CNT},
    {0, 1, 0, 0, S_CUST_INCOME, S_CUSTOMER, S_CUST_INCOME},
    {0, 0, 0, 0, S_DIVISION_ID, S_DIVISION, S_DIVISION_ID},
    {0, 0, 0, 0, S_DIVISION_COMPANY, S_DIVISION, S_DIVISION_COMPANY},
    {0, 0, 0, 0, S_DIVISION_NAME, S_DIVISION, S_DIVISION_NAME},
    {0, 1, 0, 0, S_INVN_WAREHOUSE, S_INVENTORY, S_INVN_WAREHOUSE},
    {0, 1, 0, 0, S_INVN_ITEM, S_INVENTORY, S_INVN_ITEM},
    {0, 2, 0, 0, S_INVN_DATE, S_INVENTORY, S_INVN_DATE},
    {0, 1, 0, 0, S_INVN_QUANTITY, S_INVENTORY, S_INVN_QUANTITY},
    {0, 1, 0, 0, S_ITEM_ID, S_ITEM, S_ITEM_ID},
    {0, 0, 0, 0, S_ITEM_PERMUTE, S_ITEM, S_ITEM_PERMUTE},
    {0, 1, 0, 0, S_ITEM_PRODUCT_ID, S_ITEM, S_ITEM_PRODUCT_ID},
    {0, 200, 0, 0, S_ITEM_DESC, S_ITEM, I_ITEM_DESC},
    {0, 2, 0, 0, S_ITEM_LIST_PRICE, S_ITEM, I_CURRENT_PRICE},
    {0, 1, 0, 0, S_ITEM_WHOLESALE_COST, S_ITEM, I_WHOLESALE_COST},
    {0, 1, 0, 0, S_ITEM_MANAGER_ID, S_ITEM, I_MANAGER_ID},
    {0, 1, 0, 0, S_ITEM_SIZE, S_ITEM, I_SIZE},
    {0, 50, 0, 0, S_ITEM_FORMULATION, S_ITEM, I_FORMULATION},
    {0, 1, 0, 0, S_ITEM_FLAVOR, S_ITEM, I_COLOR},
    {0, 1, 0, 0, S_ITEM_UNITS, S_ITEM, I_UNITS},
    {0, 1, 0, 0, S_ITEM_CONTAINER, S_ITEM, I_CONTAINER},
    {0, 1, 0, 0, S_ITEM_SCD, S_ITEM, I_SCD},
    {0, 0, 0, 0, S_MANAGER_ID, S_MANAGER, S_MANAGER_ID},
    {0, 2, 0, 0, S_MANAGER_NAME, S_MANAGER, S_MANAGER_NAME},
    {0, 0, 0, 0, S_MANUFACTURER_ID, S_MANUFACTURER, S_MANUFACTURER_ID},
    {0, 0, 0, 0, S_MANUFACTURER_NAME, S_MANUFACTURER, S_MANUFACTURER_NAME},
    {0, 0, 0, 0, S_MARKET_ID, S_MARKET, S_MARKET_ID},
    {0, 0, 0, 0, S_MARKET_CLASS_NAME, S_MARKET, S_MARKET_CLASS_NAME},
    {0, 10, 0, 0, S_MARKET_DESC, S_MARKET, S_MARKET_DESC},
    {0, 1, 0, 0, S_MARKET_MANAGER_ID, S_MARKET, S_MARKET_MANAGER_ID},
    {0, 0, 0, 0, S_PRODUCT_ID, S_PRODUCT, S_PRODUCT_ID},
    {0, 1, 0, 0, S_PRODUCT_BRAND_ID, S_PRODUCT, S_PRODUCT_BRAND_ID},
    {0, 0, 0, 0, S_PRODUCT_NAME, S_PRODUCT, S_PRODUCT_NAME},
    {0, 1, 0, 0, S_PRODUCT_TYPE, S_PRODUCT, S_PRODUCT_TYPE},
    {0, 1, 0, 0, S_PROMOTION_ID, S_PROMOTION, S_PROMOTION_ID},
    {0, 1, 0, 0, S_PROMOTION_ITEM_ID, S_PROMOTION, S_PROMOTION_ITEM_ID},
    {0, 1, 0, 0, S_PROMOTION_START_DATE, S_PROMOTION, S_PROMOTION_START_DATE},
    {0, 1, 0, 0, S_PROMOTION_END_DATE, S_PROMOTION, S_PROMOTION_END_DATE},
    {0, 1, 0, 0, S_PROMOTION_COST, S_PROMOTION, S_PROMOTION_COST},
    {0, 1, 0, 0, S_PROMOTION_RESPONSE_TARGET, S_PROMOTION, S_PROMOTION_RESPONSE_TARGET},
    {0, 0, 0, 0, S_PROMOTION_DMAIL, S_PROMOTION, S_PROMOTION_DMAIL},
    {0, 0, 0, 0, S_PROMOTION_EMAIL, S_PROMOTION, S_PROMOTION_EMAIL},
    {0, 0, 0, 0, S_PROMOTION_CATALOG, S_PROMOTION, S_PROMOTION_CATALOG},
    {0, 0, 0, 0, S_PROMOTION_TV, S_PROMOTION, S_PROMOTION_TV},
    {0, 0, 0, 0, S_PROMOTION_RADIO, S_PROMOTION, S_PROMOTION_RADIO},
    {0, 0, 0, 0, S_PROMOTION_PRESS, S_PROMOTION, S_PROMOTION_PRESS},
    {0, 0, 0, 0, S_PROMOTION_EVENT, S_PROMOTION, S_PROMOTION_EVENT},
    {0, 0, 0, 0, S_PROMOTION_DEMO, S_PROMOTION, S_PROMOTION_DEMO},
    {0, 100, 0, 0, S_PROMOTION_DETAILS, S_PROMOTION, P_CHANNEL_DETAILS},
    {0, 1, 0, 0, S_PROMOTION_PURPOSE, S_PROMOTION, S_PROMOTION_PURPOSE},
    {0, 1, 0, 0, S_PROMOTION_DISCOUNT_ACTIVE, S_PROMOTION, S_PROMOTION_DISCOUNT_ACTIVE},
    {0, 1, 0, 0, S_PROMOTION_DISCOUNT_PCT, S_PROMOTION, S_PROMOTION_DISCOUNT_PCT},
    {0, 0, 0, 0, S_PROMOTION_NAME, S_PROMOTION, S_PROMOTION_NAME},
    {0, 1, 0, 0, S_PROMOTION_BITFIELD, S_PROMOTION, S_PROMOTION_BITFIELD},
    {0, 0, 0, 0, S_PURCHASE_ID, S_PURCHASE, S_PURCHASE_ID},
    {0, 1, 0, 0, S_PURCHASE_STORE_ID, S_PURCHASE, S_PURCHASE_STORE_ID},
    {0, 1, 0, 0, S_PURCHASE_CUSTOMER_ID, S_PURCHASE, S_PURCHASE_CUSTOMER_ID},
    {0, 1, 0, 0, S_PURCHASE_DATE, S_PURCHASE, S_PURCHASE_DATE},
    {0, 1, 0, 0, S_PURCHASE_TIME, S_PURCHASE, S_PURCHASE_TIME},
    {0, 1, 0, 0, S_PURCHASE_REGISTER, S_PURCHASE, S_PURCHASE_REGISTER},
    {0, 1, 0, 0, S_PURCHASE_CLERK, S_PURCHASE, S_PURCHASE_CLERK},
    {0, 100, 0, 0, S_PURCHASE_COMMENT, S_PURCHASE, S_PURCHASE_COMMENT},
    {0, 7, 0, 0, S_PURCHASE_PRICING, S_PURCHASE, S_PURCHASE_PRICING},
    {0, 1, 0, 0, S_PLINE_ITEM_ID, S_PURCHASE, S_PLINE_ITEM_ID},
    {0, 12, 0, 0, S_PLINE_PURCHASE_ID, S_PURCHASE_LINEITEM, S_PLINE_PURCHASE_ID},
    {0, 12, 0, 0, S_PLINE_NUMBER, S_PURCHASE_LINEITEM, S_PLINE_NUMBER},
    {0, 12, 0, 0, S_PLINE_PROMOTION_ID, S_PURCHASE_LINEITEM, S_PLINE_PROMOTION_ID},
    {0, 12, 0, 0, S_PLINE_SALE_PRICE, S_PURCHASE_LINEITEM, S_PLINE_SALE_PRICE},
    {0, 12, 0, 0, S_PLINE_QUANTITY, S_PURCHASE_LINEITEM, S_PLINE_QUANTITY},
    {0, 12, 0, 0, S_PLINE_COUPON_AMT, S_PURCHASE_LINEITEM, S_PLINE_COUPON_AMT},
    {0, 1200, 0, 0, S_PLINE_COMMENT, S_PURCHASE_LINEITEM, S_PLINE_COMMENT},
    {0, 96, 0, 0, S_PLINE_PRICING, S_PURCHASE_LINEITEM, S_PLINE_PRICING},
    {0, 12, 0, 0, S_PLINE_IS_RETURNED, S_PURCHASE_LINEITEM, S_PLINE_IS_RETURNED},
    {0, 0, 0, 0, S_PLINE_PERMUTE, S_PURCHASE_LINEITEM, S_PLINE_PERMUTE},
    {0, 0, 0, 0, S_REASON_ID, S_REASON, S_REASON_ID},
    {0, 10, 0, 0, S_REASON_DESC, S_REASON, S_REASON_DESC},
    {0, 1, 0, 0, S_STORE_ID, S_STORE, S_STORE_ID},
    {0, 1, 0, 0, S_STORE_ADDRESS_ID, S_STORE, S_STORE_ADDRESS_ID},
    {0, 1, 0, 0, S_STORE_DIVISION_ID, S_STORE, S_STORE_DIVISION_ID},
    {0, 1, 0, 0, S_STORE_OPEN_DATE, S_STORE, S_STORE_OPEN_DATE},
    {0, 1, 0, 0, S_STORE_CLOSE_DATE, S_STORE, S_STORE_CLOSE_DATE},
    {0, 0, 0, 0, S_STORE_NAME, S_STORE, S_STORE_NAME},
    {0, 0, 0, 0, S_STORE_CLASS, S_STORE, S_STORE_CLASS},
    {0, 1, 0, 0, S_STORE_EMPLOYEES, S_STORE, S_STORE_EMPLOYEES},
    {0, 1, 0, 0, S_STORE_FLOOR_SPACE, S_STORE, S_STORE_FLOOR_SPACE},
    {0, 1, 0, 0, S_STORE_HOURS, S_STORE, S_STORE_HOURS},
    {0, 0, 0, 0, S_STORE_MARKET_MANAGER_ID, S_STORE, S_STORE_MARKET_MANAGER_ID},
    {0, 1, 0, 0, S_STORE_MANAGER_ID, S_STORE, S_STORE_MANAGER_ID},
    {0, 1, 0, 0, S_STORE_MARKET_ID, S_STORE, S_STORE_MARKET_ID},
    {0, 1, 0, 0, S_STORE_GEOGRAPHY_CLASS, S_STORE, S_STORE_GEOGRAPHY_CLASS},
    {0, 1, 0, 0, S_STORE_TAX_PERCENTAGE, S_STORE, S_STORE_TAX_PERCENTAGE},
    {0, 1, 0, 0, S_SITM_PROMOTION_ID, S_STORE_PROMOTIONAL_ITEM, S_SITM_PROMOTION_ID},
    {0, 1, 0, 0, S_SITM_ITEM_ID, S_STORE_PROMOTIONAL_ITEM, S_SITM_ITEM_ID},
    {0, 1, 0, 0, S_SITM_STORE_ID, S_STORE_PROMOTIONAL_ITEM, S_SITM_STORE_ID},
    {0, 0, 0, 0, S_SRET_STORE_ID, S_STORE_RETURNS, S_SRET_STORE_ID},
    {0, 0, 0, 0, S_SRET_PURCHASE_ID, S_STORE_RETURNS, S_SRET_PURCHASE_ID},
    {0, 0, 0, 0, S_SRET_LINENUMBER, S_STORE_RETURNS, S_SRET_LINENUMBER},
    {0, 0, 0, 0, S_SRET_ITEM_ID, S_STORE_RETURNS, S_SRET_ITEM_ID},
    {0, 0, 0, 0, S_SRET_CUSTOMER_ID, S_STORE_RETURNS, S_SRET_CUSTOMER_ID},
    {0, 24, 0, 0, S_SRET_RETURN_DATE, S_STORE_RETURNS, S_SRET_RETURN_DATE},
    {0, 12, 0, 0, S_SRET_RETURN_TIME, S_STORE_RETURNS, S_SRET_RETURN_TIME},
    {0, 0, 0, 0, S_SRET_TICKET_NUMBER, S_STORE_RETURNS, S_SRET_TICKET_NUMBER},
    {0, 0, 0, 0, S_SRET_RETURN_QUANTITY, S_STORE_RETURNS, S_SRET_RETURN_QUANTITY},
    {0, 0, 0, 0, S_SRET_RETURN_AMT, S_STORE_RETURNS, S_SRET_RETURN_AMT},
    {0, 0, 0, 0, S_SRET_RETURN_TAX, S_STORE_RETURNS, S_SRET_RETURN_TAX},
    {0, 0, 0, 0, S_SRET_RETURN_FEE, S_STORE_RETURNS, S_SRET_RETURN_FEE},
    {0, 0, 0, 0, S_SRET_RETURN_SHIP_COST, S_STORE_RETURNS, S_SRET_RETURN_SHIP_COST},
    {0, 0, 0, 0, S_SRET_REFUNDED_CASH, S_STORE_RETURNS, S_SRET_REFUNDED_CASH},
    {0, 0, 0, 0, S_SRET_REVERSED_CHARGE, S_STORE_RETURNS, S_SRET_REVERSED_CHARGE},
    {0, 0, 0, 0, S_SRET_MERCHANT_CREDIT, S_STORE_RETURNS, S_SRET_MERCHANT_CREDIT},
    {0, 12, 0, 0, S_SRET_REASON_ID, S_STORE_RETURNS, S_SRET_REASON_ID},
    {0, 84, 0, 0, S_SRET_PRICING, S_STORE_RETURNS, S_SRET_PRICING},
    {0, 0, 0, 0, S_SBCT_ID, S_SUBCATEGORY, S_SBCT_ID},
    {0, 1, 0, 0, S_SBCT_CATEGORY_ID, S_SUBCATEGORY, S_SBCT_CATEGORY_ID},
    {0, 0, 0, 0, S_SBCT_NAME, S_SUBCATEGORY, S_SBCT_NAME},
    {0, 10, 0, 0, S_SBCT_DESC, S_SUBCATEGORY, S_SBCT_DESC},
    {0, 0, 0, 0, S_SUBC_ID, S_SUBCLASS, S_SUBC_ID},
    {0, 1, 0, 0, S_SUBC_CLASS_ID, S_SUBCLASS, S_SUBC_CLASS_ID},
    {0, 0, 0, 0, S_SUBC_NAME, S_SUBCLASS, S_SUBC_NAME},
    {0, 10, 0, 0, S_SUBC_DESC, S_SUBCLASS, S_SUBC_DESC},
    {0, 1, 0, 0, S_WRHS_ID, S_WAREHOUSE, S_WRHS_ID},
    {0, 10, 0, 0, S_WRHS_DESC, S_WAREHOUSE, S_WRHS_DESC},
    {0, 1, 0, 0, S_WRHS_SQFT, S_WAREHOUSE, S_WRHS_SQFT},
    {0, 1, 0, 0, S_WRHS_ADDRESS_ID, S_WAREHOUSE, S_WRHS_ADDRESS_ID},
    {0, 1, 0, 0, S_WORD_ID, S_WEB_ORDER, S_WORD_ID},
    {0, 1, 0, 0, S_WORD_BILL_CUSTOMER_ID, S_WEB_ORDER, S_WORD_BILL_CUSTOMER_ID},
    {0, 2, 0, 0, S_WORD_SHIP_CUSTOMER_ID, S_WEB_ORDER, S_WORD_SHIP_CUSTOMER_ID},
    {0, 1, 0, 0, S_WORD_ORDER_DATE, S_WEB_ORDER, S_WORD_ORDER_DATE},
    {0, 1, 0, 0, S_WORD_ORDER_TIME, S_WEB_ORDER, S_WORD_ORDER_TIME},
    {0, 1, 0, 0, S_WORD_SHIP_MODE_ID, S_WEB_ORDER, S_WORD_SHIP_MODE_ID},
    {0, 1, 0, 0, S_WORD_WEB_SITE_ID, S_WEB_ORDER, S_WORD_WEB_SITE_ID},
    {0, 100, 0, 0, S_WORD_COMMENT, S_WEB_ORDER, S_WORD_COMMENT},
    {0, 1, 0, 0, S_WLIN_ITEM_ID, S_WEB_ORDER, S_WLIN_ITEM_ID},
    {0, 12, 0, 0, S_WLIN_ID, S_WEB_ORDER_LINEITEM, S_WLIN_ID},
    {0, 0, 0, 0, S_WLIN_LINE_NUMBER, S_WEB_ORDER_LINEITEM, S_WLIN_LINE_NUMBER},
    {0, 12, 0, 0, S_WLIN_PROMOTION_ID, S_WEB_ORDER_LINEITEM, S_WLIN_PROMOTION_ID},
    {0, 12, 0, 0, S_WLIN_QUANTITY, S_WEB_ORDER_LINEITEM, S_WLIN_QUANTITY},
    {0, 12, 0, 0, S_WLIN_COUPON_AMT, S_WEB_ORDER_LINEITEM, S_WLIN_COUPON_AMT},
    {0, 12, 0, 0, S_WLIN_WAREHOUSE_ID, S_WEB_ORDER_LINEITEM, S_WLIN_WAREHOUSE_ID},
    {0, 12, 0, 0, S_WLIN_SHIP_DATE, S_WEB_ORDER_LINEITEM, S_WLIN_SHIP_DATE},
    {0, 12, 0, 0, S_WLIN_WEB_PAGE_ID, S_WEB_ORDER_LINEITEM, S_WLIN_WEB_PAGE_ID},
    {0, 96, 0, 0, S_WLIN_PRICING, S_WEB_ORDER_LINEITEM, S_WLIN_PRICING},
    {0, 0, 0, 0, S_WLIN_SHIP_COST, S_WEB_ORDER_LINEITEM, S_WLIN_SHIP_COST},
    {0, 12, 0, 0, S_WLIN_IS_RETURNED, S_WEB_ORDER_LINEITEM, S_WLIN_IS_RETURNED},
    {0, 0, 0, 0, S_WLIN_PERMUTE, S_WEB_ORDER_LINEITEM, S_WLIN_PERMUTE},
    {0, 1, 0, 0, S_WPAG_SITE_ID, S_WEB_PAGE, S_WPAG_SITE_ID},
    {0, 1, 0, 0, S_WPAG_ID, S_WEB_PAGE, S_WPAG_ID},
    {0, 1, 0, 0, S_WPAG_CREATE_DATE, S_WEB_PAGE, S_WPAG_CREATE_DATE},
    {0, 1, 0, 0, S_WPAG_ACCESS_DATE, S_WEB_PAGE, S_WPAG_ACCESS_DATE},
    {0, 1, 0, 0, S_WPAG_AUTOGEN_FLAG, S_WEB_PAGE, S_WPAG_AUTOGEN_FLAG},
    {0, 1, 0, 0, S_WPAG_DEPARTMENT, S_WEB_PAGE, S_WPAG_DEPARTMENT},
    {0, 1, 0, 0, S_WPAG_URL, S_WEB_PAGE, S_WPAG_URL},
    {0, 1, 0, 0, S_WPAG_TYPE, S_WEB_PAGE, S_WPAG_TYPE},
    {0, 1, 0, 0, S_WPAG_CHAR_CNT, S_WEB_PAGE, S_WPAG_CHAR_CNT},
    {0, 1, 0, 0, S_WPAG_LINK_CNT, S_WEB_PAGE, S_WPAG_LINK_CNT},
    {0, 1, 0, 0, S_WPAG_IMAGE_CNT, S_WEB_PAGE, S_WPAG_IMAGE_CNT},
    {0, 1, 0, 0, S_WPAG_MAX_AD_CNT, S_WEB_PAGE, S_WPAG_MAX_AD_CNT},
    {0, 0, 0, 0, S_WPAG_PERMUTE, S_WEB_PAGE, S_WPAG_PERMUTE},
    {0, 1, 0, 0, S_WITM_SITE_ID, S_WEB_PROMOTIONAL_ITEM, S_WITM_SITE_ID},
    {0, 1, 0, 0, S_WITM_PAGE_ID, S_WEB_PROMOTIONAL_ITEM, S_WITM_PAGE_ID},
    {0, 1, 0, 0, S_WITM_ITEM_ID, S_WEB_PROMOTIONAL_ITEM, S_WITM_ITEM_ID},
    {0, 1, 0, 0, S_WITM_PROMOTION_ID, S_WEB_PROMOTIONAL_ITEM, S_WITM_PROMOTION_ID},
    {0, 0, 0, 0, S_WRET_SITE_ID, S_WEB_RETURNS, S_WRET_SITE_ID},
    {0, 0, 0, 0, S_WRET_ORDER_ID, S_WEB_RETURNS, S_WRET_ORDER_ID},
    {0, 0, 0, 0, S_WRET_LINE_NUMBER, S_WEB_RETURNS, S_WRET_LINE_NUMBER},
    {0, 0, 0, 0, S_WRET_ITEM_ID, S_WEB_RETURNS, S_WRET_ITEM_ID},
    {0, 0, 0, 0, S_WRET_RETURN_CUST_ID, S_WEB_RETURNS, S_WRET_RETURN_CUST_ID},
    {0, 0, 0, 0, S_WRET_REFUND_CUST_ID, S_WEB_RETURNS, S_WRET_REFUND_CUST_ID},
    {0, 24, 0, 0, S_WRET_RETURN_DATE, S_WEB_RETURNS, S_WRET_RETURN_DATE},
    {0, 12, 0, 0, S_WRET_RETURN_TIME, S_WEB_RETURNS, S_WRET_RETURN_TIME},
    {0, 12, 0, 0, S_WRET_REASON_ID, S_WEB_RETURNS, S_WRET_REASON_ID},
    {0, 84, 0, 0, S_WRET_PRICING, S_WEB_RETURNS, S_WRET_PRICING},
    {0, 1, 0, 0, S_WSIT_ID, S_WEB_SITE, S_WSIT_ID},
    {0, 1, 0, 0, S_WSIT_OPEN_DATE, S_WEB_SITE, S_WSIT_OPEN_DATE},
    {0, 1, 0, 0, S_WSIT_CLOSE_DATE, S_WEB_SITE, S_WSIT_CLOSE_DATE},
    {0, 0, 0, 0, S_WSIT_NAME, S_WEB_SITE, S_WSIT_NAME},
    {0, 1, 0, 0, S_WSIT_ADDRESS_ID, S_WEB_SITE, S_WSIT_ADDRESS_ID},
    {0, 1, 0, 0, S_WSIT_DIVISION_ID, S_WEB_SITE, S_WSIT_DIVISION_ID},
    {0, 1, 0, 0, S_WSIT_CLASS, S_WEB_SITE, S_WSIT_CLASS},
    {0, 1, 0, 0, S_WSIT_MANAGER_ID, S_WEB_SITE, S_WSIT_MANAGER_ID},
    {0, 1, 0, 0, S_WSIT_MARKET_ID, S_WEB_SITE, S_WSIT_MARKET_ID},
    {0, 1, 0, 0, S_WSIT_TAX_PERCENTAGE, S_WEB_SITE, S_WSIT_TAX_PERCENTAGE},
    {0, 0, 0, 0, S_ZIPG_ZIP, S_ZIPG, S_ZIPG_ZIP},
    {0, 0, 0, 0, S_ZIPG_GMT, S_ZIPG, S_ZIPG_GMT},
    {-1, -1, -1, -1, -1, -1, -1}};
#endif

} // __streams__


// scaling.h

namespace __scaling__ {

using namespace __porting__;
/*
 * Legal Notice
 *
 * This document and associated source code (the "Work") is a part of a
 * benchmark specification maintained by the TPC.
 *
 * The TPC reserves all right, title, and interest to the Work as provided
 * under U.S. and international laws, including without limitation all patent
 * and trademark rights therein.
 *
 * No Warranty
 *
 * 1.1 TO THE MAXIMUM EXTENT PERMITTED BY APPLICABLE LAW, THE INFORMATION
 *     CONTAINED HEREIN IS PROVIDED "AS IS" AND WITH ALL FAULTS, AND THE
 *     AUTHORS AND DEVELOPERS OF THE WORK HEREBY DISCLAIM ALL OTHER
 *     WARRANTIES AND CONDITIONS, EITHER EXPRESS, IMPLIED OR STATUTORY,
 *     INCLUDING, BUT NOT LIMITED TO, ANY (IF ANY) IMPLIED WARRANTIES,
 *     DUTIES OR CONDITIONS OF MERCHANTABILITY, OF FITNESS FOR A PARTICULAR
 *     PURPOSE, OF ACCURACY OR COMPLETENESS OF RESPONSES, OF RESULTS, OF
 *     WORKMANLIKE EFFORT, OF LACK OF VIRUSES, AND OF LACK OF NEGLIGENCE.
 *     ALSO, THERE IS NO WARRANTY OR CONDITION OF TITLE, QUIET ENJOYMENT,
 *     QUIET POSSESSION, CORRESPONDENCE TO DESCRIPTION OR NON-INFRINGEMENT
 *     WITH REGARD TO THE WORK.
 * 1.2 IN NO EVENT WILL ANY AUTHOR OR DEVELOPER OF THE WORK BE LIABLE TO
 *     ANY OTHER PARTY FOR ANY DAMAGES, INCLUDING BUT NOT LIMITED TO THE
 *     COST OF PROCURING SUBSTITUTE GOODS OR SERVICES, LOST PROFITS, LOSS
 *     OF USE, LOSS OF DATA, OR ANY INCIDENTAL, CONSEQUENTIAL, DIRECT,
 *     INDIRECT, OR SPECIAL DAMAGES WHETHER UNDER CONTRACT, TORT, WARRANTY,
 *     OR OTHERWISE, ARISING IN ANY WAY OUT OF THIS OR ANY OTHER AGREEMENT
 *     RELATING TO THE WORK, WHETHER OR NOT SUCH AUTHOR OR DEVELOPER HAD
 *     ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES.
 *
 * Contributors:
 * Gradient Systems
 */
#ifndef SCALING_H
#define SCALING_H

ds_key_t get_rowcount(int table);
ds_key_t getIDCount(int nTable);
int getUpdateID(ds_key_t *pDest, int nTable, int nColumn);
int getScaleSlot(int nTargetGB);
int getSkewedJulianDate(int nWeight, int nColumn);
ds_key_t dateScaling(int nColumn, ds_key_t jDate);
int getUpdateDate(int nTable, ds_key_t kRowcount);
void setUpdateDates(void);
void setUpdateScaling(int nTable);
ds_key_t getUpdateBase(int nTable);

#endif

} // __scaling__


// parallel.h

namespace __parallel__ {

using namespace __porting__;
using namespace __streams__;
/*
 * Legal Notice
 *
 * This document and associated source code (the "Work") is a part of a
 * benchmark specification maintained by the TPC.
 *
 * The TPC reserves all right, title, and interest to the Work as provided
 * under U.S. and international laws, including without limitation all patent
 * and trademark rights therein.
 *
 * No Warranty
 *
 * 1.1 TO THE MAXIMUM EXTENT PERMITTED BY APPLICABLE LAW, THE INFORMATION
 *     CONTAINED HEREIN IS PROVIDED "AS IS" AND WITH ALL FAULTS, AND THE
 *     AUTHORS AND DEVELOPERS OF THE WORK HEREBY DISCLAIM ALL OTHER
 *     WARRANTIES AND CONDITIONS, EITHER EXPRESS, IMPLIED OR STATUTORY,
 *     INCLUDING, BUT NOT LIMITED TO, ANY (IF ANY) IMPLIED WARRANTIES,
 *     DUTIES OR CONDITIONS OF MERCHANTABILITY, OF FITNESS FOR A PARTICULAR
 *     PURPOSE, OF ACCURACY OR COMPLETENESS OF RESPONSES, OF RESULTS, OF
 *     WORKMANLIKE EFFORT, OF LACK OF VIRUSES, AND OF LACK OF NEGLIGENCE.
 *     ALSO, THERE IS NO WARRANTY OR CONDITION OF TITLE, QUIET ENJOYMENT,
 *     QUIET POSSESSION, CORRESPONDENCE TO DESCRIPTION OR NON-INFRINGEMENT
 *     WITH REGARD TO THE WORK.
 * 1.2 IN NO EVENT WILL ANY AUTHOR OR DEVELOPER OF THE WORK BE LIABLE TO
 *     ANY OTHER PARTY FOR ANY DAMAGES, INCLUDING BUT NOT LIMITED TO THE
 *     COST OF PROCURING SUBSTITUTE GOODS OR SERVICES, LOST PROFITS, LOSS
 *     OF USE, LOSS OF DATA, OR ANY INCIDENTAL, CONSEQUENTIAL, DIRECT,
 *     INDIRECT, OR SPECIAL DAMAGES WHETHER UNDER CONTRACT, TORT, WARRANTY,
 *     OR OTHERWISE, ARISING IN ANY WAY OUT OF THIS OR ANY OTHER AGREEMENT
 *     RELATING TO THE WORK, WHETHER OR NOT SUCH AUTHOR OR DEVELOPER HAD
 *     ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES.
 *
 * Contributors:
 * Gradient Systems
 */
#ifndef PARALLEL_H
#define PARALLEL_H

int split_work(int nTable, ds_key_t *pkFirstRow, ds_key_t *pkRowCount);
int row_stop(int tbl);
int row_skip(int tbl, ds_key_t count);

#endif /* PARALLEL_H */

} // __parallel__


// w_customer_demographics.h

namespace __w_customer_demographics__ {

/*
 * Legal Notice
 *
 * This document and associated source code (the "Work") is a part of a
 * benchmark specification maintained by the TPC.
 *
 * The TPC reserves all right, title, and interest to the Work as provided
 * under U.S. and international laws, including without limitation all patent
 * and trademark rights therein.
 *
 * No Warranty
 *
 * 1.1 TO THE MAXIMUM EXTENT PERMITTED BY APPLICABLE LAW, THE INFORMATION
 *     CONTAINED HEREIN IS PROVIDED "AS IS" AND WITH ALL FAULTS, AND THE
 *     AUTHORS AND DEVELOPERS OF THE WORK HEREBY DISCLAIM ALL OTHER
 *     WARRANTIES AND CONDITIONS, EITHER EXPRESS, IMPLIED OR STATUTORY,
 *     INCLUDING, BUT NOT LIMITED TO, ANY (IF ANY) IMPLIED WARRANTIES,
 *     DUTIES OR CONDITIONS OF MERCHANTABILITY, OF FITNESS FOR A PARTICULAR
 *     PURPOSE, OF ACCURACY OR COMPLETENESS OF RESPONSES, OF RESULTS, OF
 *     WORKMANLIKE EFFORT, OF LACK OF VIRUSES, AND OF LACK OF NEGLIGENCE.
 *     ALSO, THERE IS NO WARRANTY OR CONDITION OF TITLE, QUIET ENJOYMENT,
 *     QUIET POSSESSION, CORRESPONDENCE TO DESCRIPTION OR NON-INFRINGEMENT
 *     WITH REGARD TO THE WORK.
 * 1.2 IN NO EVENT WILL ANY AUTHOR OR DEVELOPER OF THE WORK BE LIABLE TO
 *     ANY OTHER PARTY FOR ANY DAMAGES, INCLUDING BUT NOT LIMITED TO THE
 *     COST OF PROCURING SUBSTITUTE GOODS OR SERVICES, LOST PROFITS, LOSS
 *     OF USE, LOSS OF DATA, OR ANY INCIDENTAL, CONSEQUENTIAL, DIRECT,
 *     INDIRECT, OR SPECIAL DAMAGES WHETHER UNDER CONTRACT, TORT, WARRANTY,
 *     OR OTHERWISE, ARISING IN ANY WAY OUT OF THIS OR ANY OTHER AGREEMENT
 *     RELATING TO THE WORK, WHETHER OR NOT SUCH AUTHOR OR DEVELOPER HAD
 *     ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES.
 *
 * Contributors:
 * Gradient Systems
 */
#ifndef W_CUSTOMER_DEMOGRAPHICS_H
#define W_CUSTOMER_DEMOGRAPHICS_H

using namespace __porting__;

/***
*** CD_xxx Customer Demographcis Defines
***/
#define CD_MAX_CHILDREN 7
#define CD_MAX_EMPLOYED 7
#define CD_MAX_COLLEGE  7

/*
 * CUSTOMER_DEMOGRAPHICS table structure
 */
struct W_CUSTOMER_DEMOGRAPHICS_TBL {
	ds_key_t cd_demo_sk;
	char *cd_gender;
	char *cd_marital_status;
	char *cd_education_status;
	int cd_purchase_estimate;
	char *cd_credit_rating;
	int cd_dep_count;
	int cd_dep_employed_count;
	int cd_dep_college_count;
};

int mk_w_customer_demographics(void *info_arr, ds_key_t kIndex);

#endif

} // __w_customer_demographics__


// w_timetbl.h

namespace __w_timetbl__ {

/*
 * Legal Notice
 *
 * This document and associated source code (the "Work") is a part of a
 * benchmark specification maintained by the TPC.
 *
 * The TPC reserves all right, title, and interest to the Work as provided
 * under U.S. and international laws, including without limitation all patent
 * and trademark rights therein.
 *
 * No Warranty
 *
 * 1.1 TO THE MAXIMUM EXTENT PERMITTED BY APPLICABLE LAW, THE INFORMATION
 *     CONTAINED HEREIN IS PROVIDED "AS IS" AND WITH ALL FAULTS, AND THE
 *     AUTHORS AND DEVELOPERS OF THE WORK HEREBY DISCLAIM ALL OTHER
 *     WARRANTIES AND CONDITIONS, EITHER EXPRESS, IMPLIED OR STATUTORY,
 *     INCLUDING, BUT NOT LIMITED TO, ANY (IF ANY) IMPLIED WARRANTIES,
 *     DUTIES OR CONDITIONS OF MERCHANTABILITY, OF FITNESS FOR A PARTICULAR
 *     PURPOSE, OF ACCURACY OR COMPLETENESS OF RESPONSES, OF RESULTS, OF
 *     WORKMANLIKE EFFORT, OF LACK OF VIRUSES, AND OF LACK OF NEGLIGENCE.
 *     ALSO, THERE IS NO WARRANTY OR CONDITION OF TITLE, QUIET ENJOYMENT,
 *     QUIET POSSESSION, CORRESPONDENCE TO DESCRIPTION OR NON-INFRINGEMENT
 *     WITH REGARD TO THE WORK.
 * 1.2 IN NO EVENT WILL ANY AUTHOR OR DEVELOPER OF THE WORK BE LIABLE TO
 *     ANY OTHER PARTY FOR ANY DAMAGES, INCLUDING BUT NOT LIMITED TO THE
 *     COST OF PROCURING SUBSTITUTE GOODS OR SERVICES, LOST PROFITS, LOSS
 *     OF USE, LOSS OF DATA, OR ANY INCIDENTAL, CONSEQUENTIAL, DIRECT,
 *     INDIRECT, OR SPECIAL DAMAGES WHETHER UNDER CONTRACT, TORT, WARRANTY,
 *     OR OTHERWISE, ARISING IN ANY WAY OUT OF THIS OR ANY OTHER AGREEMENT
 *     RELATING TO THE WORK, WHETHER OR NOT SUCH AUTHOR OR DEVELOPER HAD
 *     ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES.
 *
 * Contributors:
 * Gradient Systems
 */
/*
 * TIME table structure
 */
#ifndef W_TIME_TBL_H
#define W_TIME_TBL_H

using namespace __constants__;
using namespace __porting__;

struct W_TIME_TBL {
	ds_key_t t_time_sk;
	char t_time_id[RS_BKEY + 1];
	int t_time;
	int t_hour;
	int t_minute;
	int t_second;
	char *t_am_pm;
	char *t_shift;
	char *t_sub_shift;
	char *t_meal_time;
};

int mk_w_time(void *info_arr, ds_key_t kIndex);

#endif

} // __w_timetbl__


// w_ship_mode.h

namespace __w_ship_mode__ {

/*
 * Legal Notice
 *
 * This document and associated source code (the "Work") is a part of a
 * benchmark specification maintained by the TPC.
 *
 * The TPC reserves all right, title, and interest to the Work as provided
 * under U.S. and international laws, including without limitation all patent
 * and trademark rights therein.
 *
 * No Warranty
 *
 * 1.1 TO THE MAXIMUM EXTENT PERMITTED BY APPLICABLE LAW, THE INFORMATION
 *     CONTAINED HEREIN IS PROVIDED "AS IS" AND WITH ALL FAULTS, AND THE
 *     AUTHORS AND DEVELOPERS OF THE WORK HEREBY DISCLAIM ALL OTHER
 *     WARRANTIES AND CONDITIONS, EITHER EXPRESS, IMPLIED OR STATUTORY,
 *     INCLUDING, BUT NOT LIMITED TO, ANY (IF ANY) IMPLIED WARRANTIES,
 *     DUTIES OR CONDITIONS OF MERCHANTABILITY, OF FITNESS FOR A PARTICULAR
 *     PURPOSE, OF ACCURACY OR COMPLETENESS OF RESPONSES, OF RESULTS, OF
 *     WORKMANLIKE EFFORT, OF LACK OF VIRUSES, AND OF LACK OF NEGLIGENCE.
 *     ALSO, THERE IS NO WARRANTY OR CONDITION OF TITLE, QUIET ENJOYMENT,
 *     QUIET POSSESSION, CORRESPONDENCE TO DESCRIPTION OR NON-INFRINGEMENT
 *     WITH REGARD TO THE WORK.
 * 1.2 IN NO EVENT WILL ANY AUTHOR OR DEVELOPER OF THE WORK BE LIABLE TO
 *     ANY OTHER PARTY FOR ANY DAMAGES, INCLUDING BUT NOT LIMITED TO THE
 *     COST OF PROCURING SUBSTITUTE GOODS OR SERVICES, LOST PROFITS, LOSS
 *     OF USE, LOSS OF DATA, OR ANY INCIDENTAL, CONSEQUENTIAL, DIRECT,
 *     INDIRECT, OR SPECIAL DAMAGES WHETHER UNDER CONTRACT, TORT, WARRANTY,
 *     OR OTHERWISE, ARISING IN ANY WAY OUT OF THIS OR ANY OTHER AGREEMENT
 *     RELATING TO THE WORK, WHETHER OR NOT SUCH AUTHOR OR DEVELOPER HAD
 *     ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES.
 *
 * Contributors:
 * Gradient Systems
 */
#ifndef W_SHIP_MODE_H
#define W_SHIP_MODE_H

using namespace __constants__;
using namespace __porting__;

/*
 * SHIP_MODE table structure
 */
struct W_SHIP_MODE_TBL {
	ds_key_t sm_ship_mode_sk;
	char sm_ship_mode_id[RS_BKEY + 1];
	char *sm_type;
	char *sm_code;
	char *sm_carrier;
	char sm_contract[RS_SM_CONTRACT + 1];
};

int mk_w_ship_mode(void *info_arr, ds_key_t kIndex);
#endif

} // __w_ship_mode__


// w_inventory.h

namespace __w_inventory__ {

/*
 * Legal Notice
 *
 * This document and associated source code (the "Work") is a part of a
 * benchmark specification maintained by the TPC.
 *
 * The TPC reserves all right, title, and interest to the Work as provided
 * under U.S. and international laws, including without limitation all patent
 * and trademark rights therein.
 *
 * No Warranty
 *
 * 1.1 TO THE MAXIMUM EXTENT PERMITTED BY APPLICABLE LAW, THE INFORMATION
 *     CONTAINED HEREIN IS PROVIDED "AS IS" AND WITH ALL FAULTS, AND THE
 *     AUTHORS AND DEVELOPERS OF THE WORK HEREBY DISCLAIM ALL OTHER
 *     WARRANTIES AND CONDITIONS, EITHER EXPRESS, IMPLIED OR STATUTORY,
 *     INCLUDING, BUT NOT LIMITED TO, ANY (IF ANY) IMPLIED WARRANTIES,
 *     DUTIES OR CONDITIONS OF MERCHANTABILITY, OF FITNESS FOR A PARTICULAR
 *     PURPOSE, OF ACCURACY OR COMPLETENESS OF RESPONSES, OF RESULTS, OF
 *     WORKMANLIKE EFFORT, OF LACK OF VIRUSES, AND OF LACK OF NEGLIGENCE.
 *     ALSO, THERE IS NO WARRANTY OR CONDITION OF TITLE, QUIET ENJOYMENT,
 *     QUIET POSSESSION, CORRESPONDENCE TO DESCRIPTION OR NON-INFRINGEMENT
 *     WITH REGARD TO THE WORK.
 * 1.2 IN NO EVENT WILL ANY AUTHOR OR DEVELOPER OF THE WORK BE LIABLE TO
 *     ANY OTHER PARTY FOR ANY DAMAGES, INCLUDING BUT NOT LIMITED TO THE
 *     COST OF PROCURING SUBSTITUTE GOODS OR SERVICES, LOST PROFITS, LOSS
 *     OF USE, LOSS OF DATA, OR ANY INCIDENTAL, CONSEQUENTIAL, DIRECT,
 *     INDIRECT, OR SPECIAL DAMAGES WHETHER UNDER CONTRACT, TORT, WARRANTY,
 *     OR OTHERWISE, ARISING IN ANY WAY OUT OF THIS OR ANY OTHER AGREEMENT
 *     RELATING TO THE WORK, WHETHER OR NOT SUCH AUTHOR OR DEVELOPER HAD
 *     ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES.
 *
 * Contributors:
 * Gradient Systems
 */

using namespace __porting__;

/*
 * INVENTORY table structure
 */
struct W_INVENTORY_TBL {
	ds_key_t inv_date_sk;
	ds_key_t inv_item_sk;
	ds_key_t inv_warehouse_sk;
	int inv_quantity_on_hand;
};

int mk_w_inventory(void *info_arr, ds_key_t kIndex);

ds_key_t sc_w_inventory(int nScale);

} // __w_inventory__


// w_warehouse.h

namespace __w_warehouse__ {

/*
 * Legal Notice
 *
 * This document and associated source code (the "Work") is a part of a
 * benchmark specification maintained by the TPC.
 *
 * The TPC reserves all right, title, and interest to the Work as provided
 * under U.S. and international laws, including without limitation all patent
 * and trademark rights therein.
 *
 * No Warranty
 *
 * 1.1 TO THE MAXIMUM EXTENT PERMITTED BY APPLICABLE LAW, THE INFORMATION
 *     CONTAINED HEREIN IS PROVIDED "AS IS" AND WITH ALL FAULTS, AND THE
 *     AUTHORS AND DEVELOPERS OF THE WORK HEREBY DISCLAIM ALL OTHER
 *     WARRANTIES AND CONDITIONS, EITHER EXPRESS, IMPLIED OR STATUTORY,
 *     INCLUDING, BUT NOT LIMITED TO, ANY (IF ANY) IMPLIED WARRANTIES,
 *     DUTIES OR CONDITIONS OF MERCHANTABILITY, OF FITNESS FOR A PARTICULAR
 *     PURPOSE, OF ACCURACY OR COMPLETENESS OF RESPONSES, OF RESULTS, OF
 *     WORKMANLIKE EFFORT, OF LACK OF VIRUSES, AND OF LACK OF NEGLIGENCE.
 *     ALSO, THERE IS NO WARRANTY OR CONDITION OF TITLE, QUIET ENJOYMENT,
 *     QUIET POSSESSION, CORRESPONDENCE TO DESCRIPTION OR NON-INFRINGEMENT
 *     WITH REGARD TO THE WORK.
 * 1.2 IN NO EVENT WILL ANY AUTHOR OR DEVELOPER OF THE WORK BE LIABLE TO
 *     ANY OTHER PARTY FOR ANY DAMAGES, INCLUDING BUT NOT LIMITED TO THE
 *     COST OF PROCURING SUBSTITUTE GOODS OR SERVICES, LOST PROFITS, LOSS
 *     OF USE, LOSS OF DATA, OR ANY INCIDENTAL, CONSEQUENTIAL, DIRECT,
 *     INDIRECT, OR SPECIAL DAMAGES WHETHER UNDER CONTRACT, TORT, WARRANTY,
 *     OR OTHERWISE, ARISING IN ANY WAY OUT OF THIS OR ANY OTHER AGREEMENT
 *     RELATING TO THE WORK, WHETHER OR NOT SUCH AUTHOR OR DEVELOPER HAD
 *     ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES.
 *
 * Contributors:
 * Gradient Systems
 */
#ifndef W_WAREHOUSE_H
#define W_WAREHOUSE_H

using namespace __address__;
using namespace __porting__;

/*
 * WAREHOUSE table structure
 */
struct W_WAREHOUSE_TBL {
	ds_key_t w_warehouse_sk;
	char w_warehouse_id[RS_BKEY + 1];
	char w_warehouse_name[RS_W_WAREHOUSE_NAME + 1];
	int w_warehouse_sq_ft;
	ds_addr_t w_address;
};

int mk_w_warehouse(void *info_arr, ds_key_t kIndex);

#endif

} // __w_warehouse__


// w_customer_address.h

namespace __w_customer_address__ {

/*
 * Legal Notice
 *
 * This document and associated source code (the "Work") is a part of a
 * benchmark specification maintained by the TPC.
 *
 * The TPC reserves all right, title, and interest to the Work as provided
 * under U.S. and international laws, including without limitation all patent
 * and trademark rights therein.
 *
 * No Warranty
 *
 * 1.1 TO THE MAXIMUM EXTENT PERMITTED BY APPLICABLE LAW, THE INFORMATION
 *     CONTAINED HEREIN IS PROVIDED "AS IS" AND WITH ALL FAULTS, AND THE
 *     AUTHORS AND DEVELOPERS OF THE WORK HEREBY DISCLAIM ALL OTHER
 *     WARRANTIES AND CONDITIONS, EITHER EXPRESS, IMPLIED OR STATUTORY,
 *     INCLUDING, BUT NOT LIMITED TO, ANY (IF ANY) IMPLIED WARRANTIES,
 *     DUTIES OR CONDITIONS OF MERCHANTABILITY, OF FITNESS FOR A PARTICULAR
 *     PURPOSE, OF ACCURACY OR COMPLETENESS OF RESPONSES, OF RESULTS, OF
 *     WORKMANLIKE EFFORT, OF LACK OF VIRUSES, AND OF LACK OF NEGLIGENCE.
 *     ALSO, THERE IS NO WARRANTY OR CONDITION OF TITLE, QUIET ENJOYMENT,
 *     QUIET POSSESSION, CORRESPONDENCE TO DESCRIPTION OR NON-INFRINGEMENT
 *     WITH REGARD TO THE WORK.
 * 1.2 IN NO EVENT WILL ANY AUTHOR OR DEVELOPER OF THE WORK BE LIABLE TO
 *     ANY OTHER PARTY FOR ANY DAMAGES, INCLUDING BUT NOT LIMITED TO THE
 *     COST OF PROCURING SUBSTITUTE GOODS OR SERVICES, LOST PROFITS, LOSS
 *     OF USE, LOSS OF DATA, OR ANY INCIDENTAL, CONSEQUENTIAL, DIRECT,
 *     INDIRECT, OR SPECIAL DAMAGES WHETHER UNDER CONTRACT, TORT, WARRANTY,
 *     OR OTHERWISE, ARISING IN ANY WAY OUT OF THIS OR ANY OTHER AGREEMENT
 *     RELATING TO THE WORK, WHETHER OR NOT SUCH AUTHOR OR DEVELOPER HAD
 *     ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES.
 *
 * Contributors:
 * Gradient Systems
 */
#ifndef W_CUSTOMER_ADDRESS_H
#define W_CUSTOMER_ADDRESS_H
using namespace __constants__;
using namespace __address__;
using namespace __porting__;

/*
 * CUSTOMER_ADDRESS table structure
 */
struct W_CUSTOMER_ADDRESS_TBL {
	ds_key_t ca_addr_sk;
	char ca_addr_id[RS_BKEY + 1];
	ds_addr_t ca_address;
	char *ca_location_type;
};

int mk_w_customer_address(void *info_arr, ds_key_t kIndex);

#endif

} // __w_customer_address__


// tdefs.h

namespace __tdefs__ {

/*
 * Legal Notice
 *
 * This document and associated source code (the "Work") is a part of a
 * benchmark specification maintained by the TPC.
 *
 * The TPC reserves all right, title, and interest to the Work as provided
 * under U.S. and international laws, including without limitation all patent
 * and trademark rights therein.
 *
 * No Warranty
 *
 * 1.1 TO THE MAXIMUM EXTENT PERMITTED BY APPLICABLE LAW, THE INFORMATION
 *     CONTAINED HEREIN IS PROVIDED "AS IS" AND WITH ALL FAULTS, AND THE
 *     AUTHORS AND DEVELOPERS OF THE WORK HEREBY DISCLAIM ALL OTHER
 *     WARRANTIES AND CONDITIONS, EITHER EXPRESS, IMPLIED OR STATUTORY,
 *     INCLUDING, BUT NOT LIMITED TO, ANY (IF ANY) IMPLIED WARRANTIES,
 *     DUTIES OR CONDITIONS OF MERCHANTABILITY, OF FITNESS FOR A PARTICULAR
 *     PURPOSE, OF ACCURACY OR COMPLETENESS OF RESPONSES, OF RESULTS, OF
 *     WORKMANLIKE EFFORT, OF LACK OF VIRUSES, AND OF LACK OF NEGLIGENCE.
 *     ALSO, THERE IS NO WARRANTY OR CONDITION OF TITLE, QUIET ENJOYMENT,
 *     QUIET POSSESSION, CORRESPONDENCE TO DESCRIPTION OR NON-INFRINGEMENT
 *     WITH REGARD TO THE WORK.
 * 1.2 IN NO EVENT WILL ANY AUTHOR OR DEVELOPER OF THE WORK BE LIABLE TO
 *     ANY OTHER PARTY FOR ANY DAMAGES, INCLUDING BUT NOT LIMITED TO THE
 *     COST OF PROCURING SUBSTITUTE GOODS OR SERVICES, LOST PROFITS, LOSS
 *     OF USE, LOSS OF DATA, OR ANY INCIDENTAL, CONSEQUENTIAL, DIRECT,
 *     INDIRECT, OR SPECIAL DAMAGES WHETHER UNDER CONTRACT, TORT, WARRANTY,
 *     OR OTHERWISE, ARISING IN ANY WAY OUT OF THIS OR ANY OTHER AGREEMENT
 *     RELATING TO THE WORK, WHETHER OR NOT SUCH AUTHOR OR DEVELOPER HAD
 *     ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES.
 *
 * Contributors:
 * Gradient Systems
 */
#ifndef TDEFS_H
#define TDEFS_H

#include <stdio.h>
using namespace __tables__;
using namespace __columns__;
using namespace __tdef_functions__;

/*
 * Flag field definitions used in tdefs[]
 */
#define FL_NONE       0x0000 /* this table is not defined */
#define FL_NOP        0x0001 /* this table is not defined */
#define FL_DATE_BASED 0x0002 /* this table is produced in date order */
#define FL_CHILD      0x0004 /* this table is the child in a parent/child link */
#define FL_OPEN       0x0008 /* this table has a valid output destination */
#define FL_DUP_NAME   0x0010 /* to keep find_table() from complaining twice */
#define FL_TYPE_2                                                                                                      \
	0x0020               /* this dimension keeps history -- rowcount shows unique entities                             \
	                        (not including revisions) */
#define FL_SMALL  0x0040 /* this table has low rowcount; used by address.c */
#define FL_SPARSE 0x0080
/* unused 0x0100 */
#define FL_NO_UPDATE  0x0200 /* this table is not altered by the update process */
#define FL_SOURCE_DDL 0x0400 /* table in the souce schema */
#define FL_JOIN_ERROR 0x0800 /* join called without an explicit rule */
#define FL_PARENT     0x1000 /* this table has a child in nParam */
#define FL_FACT_TABLE 0x2000
#define FL_PASSTHRU   0x4000 /* verify routine uses warehouse without change */
#define FL_VPRINT     0x8000 /* verify routine includes print function */

/*
 * general table descriptions.
 * NOTE: This table contains the constant elements in the table descriptions; it
 * must be kept in sync with the declararions of assocaited functions, found in
 * tdef_functions.h
 */
typedef struct TDEF_T {
	char *name;        /* -- name of the table; */
	char *abreviation; /* -- shorthand name of the table */
	int flags;         /* -- control table options */
	int nFirstColumn;  /* -- first column/RNG for this table */
	int nLastColumn;   /* -- last column/RNG for this table */
	int nTableIndex;   /* used for rowcount calculations */
	int nParam;        /* -- additional table param (revision count, child number,
	                      etc.) */
	FILE *outfile;     /* -- output destination */
	int nUpdateSize;   /* -- percentage of base rowcount in each update set (basis
	                      points) */
	int nNewRowPct;
	int nNullPct;            /* percentage of rows with nulls (basis points) */
	ds_key_t kNullBitMap;    /* colums that should be NULL in the current row */
	ds_key_t kNotNullBitMap; /* columns that are defined NOT NULL */
	ds_key_t *arSparseKeys;  /* sparse key set for table; used if FL_SPARSE is set */
} tdef;

/*
extern tdef *tdefs;
extern tdef w_tdefs[];
extern tdef s_tdefs[];
*/

#define tdefIsFlagSet(t, f) (tdefs[t].flags & f)
ds_key_t GetRowcountByName(char *szName);
int GetTableNumber(char *szName);
char *getTableNameByID(int id);
int getTableFromColumn(int id);
int initSpareKeys(int id);
tdef *getSimpleTdefsByNumber(int nTable);
tdef *getTdefsByNumber(int nTable);

#endif

} // __tdefs__


// dcomp.h

namespace __dcomp__ {

/*
 * Legal Notice
 *
 * This document and associated source code (the "Work") is a part of a
 * benchmark specification maintained by the TPC.
 *
 * The TPC reserves all right, title, and interest to the Work as provided
 * under U.S. and international laws, including without limitation all patent
 * and trademark rights therein.
 *
 * No Warranty
 *
 * 1.1 TO THE MAXIMUM EXTENT PERMITTED BY APPLICABLE LAW, THE INFORMATION
 *     CONTAINED HEREIN IS PROVIDED "AS IS" AND WITH ALL FAULTS, AND THE
 *     AUTHORS AND DEVELOPERS OF THE WORK HEREBY DISCLAIM ALL OTHER
 *     WARRANTIES AND CONDITIONS, EITHER EXPRESS, IMPLIED OR STATUTORY,
 *     INCLUDING, BUT NOT LIMITED TO, ANY (IF ANY) IMPLIED WARRANTIES,
 *     DUTIES OR CONDITIONS OF MERCHANTABILITY, OF FITNESS FOR A PARTICULAR
 *     PURPOSE, OF ACCURACY OR COMPLETENESS OF RESPONSES, OF RESULTS, OF
 *     WORKMANLIKE EFFORT, OF LACK OF VIRUSES, AND OF LACK OF NEGLIGENCE.
 *     ALSO, THERE IS NO WARRANTY OR CONDITION OF TITLE, QUIET ENJOYMENT,
 *     QUIET POSSESSION, CORRESPONDENCE TO DESCRIPTION OR NON-INFRINGEMENT
 *     WITH REGARD TO THE WORK.
 * 1.2 IN NO EVENT WILL ANY AUTHOR OR DEVELOPER OF THE WORK BE LIABLE TO
 *     ANY OTHER PARTY FOR ANY DAMAGES, INCLUDING BUT NOT LIMITED TO THE
 *     COST OF PROCURING SUBSTITUTE GOODS OR SERVICES, LOST PROFITS, LOSS
 *     OF USE, LOSS OF DATA, OR ANY INCIDENTAL, CONSEQUENTIAL, DIRECT,
 *     INDIRECT, OR SPECIAL DAMAGES WHETHER UNDER CONTRACT, TORT, WARRANTY,
 *     OR OTHERWISE, ARISING IN ANY WAY OUT OF THIS OR ANY OTHER AGREEMENT
 *     RELATING TO THE WORK, WHETHER OR NOT SUCH AUTHOR OR DEVELOPER HAD
 *     ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES.
 *
 * Contributors:
 * Gradient Systems
 */
#ifndef DCOMP_H
#define DCOMP_H

using namespace __config__;
using namespace __porting__;
using namespace __grammar__;
using namespace __dist__;

/*
 * query template grammar definition
 */
#define TKN_UNKNOWN 0
#define TKN_CREATE  1
#define TKN_WEIGHTS 2
#define TKN_TYPES   3
#define TKN_INCLUDE 4
#define TKN_SET     5
#define TKN_VARCHAR 6
#define TKN_INT     7
#define TKN_ADD     8
#define TKN_DATE    9
#define TKN_DECIMAL 10
#define TKN_NAMES   11
#define MAX_TOKEN   11

int ProcessDistribution(char *s, token_t *t);
int ProcessTypes(char *s, token_t *t);
int ProcessInclude(char *s, token_t *t);
int ProcessSet(char *s, token_t *t);
int ProcessAdd(char *s, token_t *t);

#ifdef DECLARER
token_t dcomp_tokens[MAX_TOKEN + 2] = {{TKN_UNKNOWN, "", NULL},
                                       {TKN_CREATE, "create", ProcessDistribution},
                                       {TKN_WEIGHTS, "weights", NULL},
                                       {TKN_TYPES, "types", NULL},
                                       {TKN_INCLUDE, "#include", ProcessInclude},
                                       {TKN_SET, "set", ProcessSet},
                                       {TKN_VARCHAR, "varchar", NULL},
                                       {TKN_INT, "int", NULL},
                                       {TKN_ADD, "add", ProcessAdd},
                                       {TKN_DATE, "date", NULL},
                                       {TKN_DECIMAL, "decimal", NULL},
                                       {TKN_NAMES, "names", NULL},
                                       {-1, "", NULL}};
#else
extern token_t tokens[];
#endif

#endif /* DCOMP_H */

} // __dcomp__


// w_web_site.h

namespace __w_web_site__ {

/*
 * Legal Notice
 *
 * This document and associated source code (the "Work") is a part of a
 * benchmark specification maintained by the TPC.
 *
 * The TPC reserves all right, title, and interest to the Work as provided
 * under U.S. and international laws, including without limitation all patent
 * and trademark rights therein.
 *
 * No Warranty
 *
 * 1.1 TO THE MAXIMUM EXTENT PERMITTED BY APPLICABLE LAW, THE INFORMATION
 *     CONTAINED HEREIN IS PROVIDED "AS IS" AND WITH ALL FAULTS, AND THE
 *     AUTHORS AND DEVELOPERS OF THE WORK HEREBY DISCLAIM ALL OTHER
 *     WARRANTIES AND CONDITIONS, EITHER EXPRESS, IMPLIED OR STATUTORY,
 *     INCLUDING, BUT NOT LIMITED TO, ANY (IF ANY) IMPLIED WARRANTIES,
 *     DUTIES OR CONDITIONS OF MERCHANTABILITY, OF FITNESS FOR A PARTICULAR
 *     PURPOSE, OF ACCURACY OR COMPLETENESS OF RESPONSES, OF RESULTS, OF
 *     WORKMANLIKE EFFORT, OF LACK OF VIRUSES, AND OF LACK OF NEGLIGENCE.
 *     ALSO, THERE IS NO WARRANTY OR CONDITION OF TITLE, QUIET ENJOYMENT,
 *     QUIET POSSESSION, CORRESPONDENCE TO DESCRIPTION OR NON-INFRINGEMENT
 *     WITH REGARD TO THE WORK.
 * 1.2 IN NO EVENT WILL ANY AUTHOR OR DEVELOPER OF THE WORK BE LIABLE TO
 *     ANY OTHER PARTY FOR ANY DAMAGES, INCLUDING BUT NOT LIMITED TO THE
 *     COST OF PROCURING SUBSTITUTE GOODS OR SERVICES, LOST PROFITS, LOSS
 *     OF USE, LOSS OF DATA, OR ANY INCIDENTAL, CONSEQUENTIAL, DIRECT,
 *     INDIRECT, OR SPECIAL DAMAGES WHETHER UNDER CONTRACT, TORT, WARRANTY,
 *     OR OTHERWISE, ARISING IN ANY WAY OUT OF THIS OR ANY OTHER AGREEMENT
 *     RELATING TO THE WORK, WHETHER OR NOT SUCH AUTHOR OR DEVELOPER HAD
 *     ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES.
 *
 * Contributors:
 * Gradient Systems
 */
#ifndef W_WEB_SITE_H
#define W_WEB_SITE_H

using namespace __address__;
using namespace __constants__;
using namespace __decimal__;

#define WEB_MIN_TAX_PERCENTAGE "0.00"
#define WEB_MAX_TAX_PERCENTAGE "0.12"

/*
 * WEB_SITE table structure
 */
struct W_WEB_SITE_TBL {
	ds_key_t web_site_sk;
	char web_site_id[RS_BKEY + 1];
	ds_key_t web_rec_start_date_id;
	ds_key_t web_rec_end_date_id;
	char web_name[RS_WEB_NAME + 1];
	ds_key_t web_open_date;
	ds_key_t web_close_date;
	char web_class[RS_WEB_CLASS + 1];
	char web_manager[RS_WEB_MANAGER + 1];
	int web_market_id;
	char web_market_class[RS_WEB_MARKET_CLASS + 1];
	char web_market_desc[RS_WEB_MARKET_DESC + 1];
	char web_market_manager[RS_WEB_MARKET_MANAGER + 1];
	int web_company_id;
	char web_company_name[RS_WEB_COMPANY_NAME + 1];
	ds_addr_t web_address;
	decimal_t web_tax_percentage;
};

int mk_w_web_site(void *info_arr, ds_key_t kIndex);
#endif

} // __w_web_site__


// w_item.h

namespace __w_item__ {

/*
 * Legal Notice
 *
 * This document and associated source code (the "Work") is a part of a
 * benchmark specification maintained by the TPC.
 *
 * The TPC reserves all right, title, and interest to the Work as provided
 * under U.S. and international laws, including without limitation all patent
 * and trademark rights therein.
 *
 * No Warranty
 *
 * 1.1 TO THE MAXIMUM EXTENT PERMITTED BY APPLICABLE LAW, THE INFORMATION
 *     CONTAINED HEREIN IS PROVIDED "AS IS" AND WITH ALL FAULTS, AND THE
 *     AUTHORS AND DEVELOPERS OF THE WORK HEREBY DISCLAIM ALL OTHER
 *     WARRANTIES AND CONDITIONS, EITHER EXPRESS, IMPLIED OR STATUTORY,
 *     INCLUDING, BUT NOT LIMITED TO, ANY (IF ANY) IMPLIED WARRANTIES,
 *     DUTIES OR CONDITIONS OF MERCHANTABILITY, OF FITNESS FOR A PARTICULAR
 *     PURPOSE, OF ACCURACY OR COMPLETENESS OF RESPONSES, OF RESULTS, OF
 *     WORKMANLIKE EFFORT, OF LACK OF VIRUSES, AND OF LACK OF NEGLIGENCE.
 *     ALSO, THERE IS NO WARRANTY OR CONDITION OF TITLE, QUIET ENJOYMENT,
 *     QUIET POSSESSION, CORRESPONDENCE TO DESCRIPTION OR NON-INFRINGEMENT
 *     WITH REGARD TO THE WORK.
 * 1.2 IN NO EVENT WILL ANY AUTHOR OR DEVELOPER OF THE WORK BE LIABLE TO
 *     ANY OTHER PARTY FOR ANY DAMAGES, INCLUDING BUT NOT LIMITED TO THE
 *     COST OF PROCURING SUBSTITUTE GOODS OR SERVICES, LOST PROFITS, LOSS
 *     OF USE, LOSS OF DATA, OR ANY INCIDENTAL, CONSEQUENTIAL, DIRECT,
 *     INDIRECT, OR SPECIAL DAMAGES WHETHER UNDER CONTRACT, TORT, WARRANTY,
 *     OR OTHERWISE, ARISING IN ANY WAY OUT OF THIS OR ANY OTHER AGREEMENT
 *     RELATING TO THE WORK, WHETHER OR NOT SUCH AUTHOR OR DEVELOPER HAD
 *     ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES.
 *
 * Contributors:
 * Gradient Systems
 */
#ifndef W_ITEM_H
#define W_ITEM_H

using namespace __constants__;
using namespace __porting__;
using namespace __decimal__;

#define I_PROMO_PERCENTAGE    20 /* percent of items that have associated promotions */
#define MIN_ITEM_MARKDOWN_PCT "0.30"
#define MAX_ITEM_MARKDOWN_PCT "0.90"

/*
 * ITEM table structure
 */
struct W_ITEM_TBL {
	ds_key_t i_item_sk;
	char i_item_id[RS_BKEY + 1];
	ds_key_t i_rec_start_date_id;
	ds_key_t i_rec_end_date_id;
	char i_item_desc[RS_I_ITEM_DESC + 1];
	decimal_t i_current_price; /* list price */
	decimal_t i_wholesale_cost;
	ds_key_t i_brand_id;
	char i_brand[RS_I_BRAND + 1];
	ds_key_t i_class_id;
	char *i_class;
	ds_key_t i_category_id;
	char *i_category;
	ds_key_t i_manufact_id;
	char i_manufact[RS_I_MANUFACT + 1];
	char *i_size;
	char i_formulation[RS_I_FORMULATION + 1];
	char *i_color;
	char *i_units;
	char *i_container;
	ds_key_t i_manager_id;
	char i_product_name[RS_I_PRODUCT_NAME + 1];
	ds_key_t i_promo_sk;
};

int mk_w_item(void *info_arr, ds_key_t kIndex);
int vld_w_item(int nTable, ds_key_t kRow, int *Permutation);
#endif

} // __w_item__


// w_promotion.h

namespace __w_promotion__ {

/*
 * Legal Notice
 *
 * This document and associated source code (the "Work") is a part of a
 * benchmark specification maintained by the TPC.
 *
 * The TPC reserves all right, title, and interest to the Work as provided
 * under U.S. and international laws, including without limitation all patent
 * and trademark rights therein.
 *
 * No Warranty
 *
 * 1.1 TO THE MAXIMUM EXTENT PERMITTED BY APPLICABLE LAW, THE INFORMATION
 *     CONTAINED HEREIN IS PROVIDED "AS IS" AND WITH ALL FAULTS, AND THE
 *     AUTHORS AND DEVELOPERS OF THE WORK HEREBY DISCLAIM ALL OTHER
 *     WARRANTIES AND CONDITIONS, EITHER EXPRESS, IMPLIED OR STATUTORY,
 *     INCLUDING, BUT NOT LIMITED TO, ANY (IF ANY) IMPLIED WARRANTIES,
 *     DUTIES OR CONDITIONS OF MERCHANTABILITY, OF FITNESS FOR A PARTICULAR
 *     PURPOSE, OF ACCURACY OR COMPLETENESS OF RESPONSES, OF RESULTS, OF
 *     WORKMANLIKE EFFORT, OF LACK OF VIRUSES, AND OF LACK OF NEGLIGENCE.
 *     ALSO, THERE IS NO WARRANTY OR CONDITION OF TITLE, QUIET ENJOYMENT,
 *     QUIET POSSESSION, CORRESPONDENCE TO DESCRIPTION OR NON-INFRINGEMENT
 *     WITH REGARD TO THE WORK.
 * 1.2 IN NO EVENT WILL ANY AUTHOR OR DEVELOPER OF THE WORK BE LIABLE TO
 *     ANY OTHER PARTY FOR ANY DAMAGES, INCLUDING BUT NOT LIMITED TO THE
 *     COST OF PROCURING SUBSTITUTE GOODS OR SERVICES, LOST PROFITS, LOSS
 *     OF USE, LOSS OF DATA, OR ANY INCIDENTAL, CONSEQUENTIAL, DIRECT,
 *     INDIRECT, OR SPECIAL DAMAGES WHETHER UNDER CONTRACT, TORT, WARRANTY,
 *     OR OTHERWISE, ARISING IN ANY WAY OUT OF THIS OR ANY OTHER AGREEMENT
 *     RELATING TO THE WORK, WHETHER OR NOT SUCH AUTHOR OR DEVELOPER HAD
 *     ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES.
 *
 * Contributors:
 * Gradient Systems
 */
#ifndef W_PROMOTION_H
#define W_PROMOTION_H

using namespace __constants__;
using namespace __decimal__;
using namespace __porting__;

/*
 * PROMOTION table structure
 */
struct W_PROMOTION_TBL {
	ds_key_t p_promo_sk;
	char p_promo_id[RS_BKEY + 1];
	ds_key_t p_start_date_id;
	ds_key_t p_end_date_id;
	ds_key_t p_item_sk;
	decimal_t p_cost;
	int p_response_target;
	char p_promo_name[RS_P_PROMO_NAME + 1];
	int p_channel_dmail;
	int p_channel_email;
	int p_channel_catalog;
	int p_channel_tv;
	int p_channel_radio;
	int p_channel_press;
	int p_channel_event;
	int p_channel_demo;
	char p_channel_details[RS_P_CHANNEL_DETAILS + 1];
	char *p_purpose;
	int p_discount_active;
};

int mk_w_promotion(void *info_arr, ds_key_t kIndex);

#endif

} // __w_promotion__


// scd.h

namespace __scd__ {

/*
 * Legal Notice
 *
 * This document and associated source code (the "Work") is a part of a
 * benchmark specification maintained by the TPC.
 *
 * The TPC reserves all right, title, and interest to the Work as provided
 * under U.S. and international laws, including without limitation all patent
 * and trademark rights therein.
 *
 * No Warranty
 *
 * 1.1 TO THE MAXIMUM EXTENT PERMITTED BY APPLICABLE LAW, THE INFORMATION
 *     CONTAINED HEREIN IS PROVIDED "AS IS" AND WITH ALL FAULTS, AND THE
 *     AUTHORS AND DEVELOPERS OF THE WORK HEREBY DISCLAIM ALL OTHER
 *     WARRANTIES AND CONDITIONS, EITHER EXPRESS, IMPLIED OR STATUTORY,
 *     INCLUDING, BUT NOT LIMITED TO, ANY (IF ANY) IMPLIED WARRANTIES,
 *     DUTIES OR CONDITIONS OF MERCHANTABILITY, OF FITNESS FOR A PARTICULAR
 *     PURPOSE, OF ACCURACY OR COMPLETENESS OF RESPONSES, OF RESULTS, OF
 *     WORKMANLIKE EFFORT, OF LACK OF VIRUSES, AND OF LACK OF NEGLIGENCE.
 *     ALSO, THERE IS NO WARRANTY OR CONDITION OF TITLE, QUIET ENJOYMENT,
 *     QUIET POSSESSION, CORRESPONDENCE TO DESCRIPTION OR NON-INFRINGEMENT
 *     WITH REGARD TO THE WORK.
 * 1.2 IN NO EVENT WILL ANY AUTHOR OR DEVELOPER OF THE WORK BE LIABLE TO
 *     ANY OTHER PARTY FOR ANY DAMAGES, INCLUDING BUT NOT LIMITED TO THE
 *     COST OF PROCURING SUBSTITUTE GOODS OR SERVICES, LOST PROFITS, LOSS
 *     OF USE, LOSS OF DATA, OR ANY INCIDENTAL, CONSEQUENTIAL, DIRECT,
 *     INDIRECT, OR SPECIAL DAMAGES WHETHER UNDER CONTRACT, TORT, WARRANTY,
 *     OR OTHERWISE, ARISING IN ANY WAY OUT OF THIS OR ANY OTHER AGREEMENT
 *     RELATING TO THE WORK, WHETHER OR NOT SUCH AUTHOR OR DEVELOPER HAD
 *     ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES.
 *
 * Contributors:
 * Gradient Systems
 */
#ifndef SCD_H
#define SCD_H

using namespace __decimal__;
using namespace __tables__;

extern char arBKeys[MAX_TABLE][17];
int setSCDKeys(int nTableID, ds_key_t hgIndex, char *szBKey, ds_key_t *hgBeginDateKey, ds_key_t *hgEndDateKey);
ds_key_t scd_join(int tbl, int col, ds_key_t jDate);
ds_key_t matchSCDSK(ds_key_t kUnique, ds_key_t jDate, int nTable);
ds_key_t getSKFromID(ds_key_t kID, int nColumn);
ds_key_t getFirstSK(ds_key_t kID);
/*
 * handle the partial change of a history keeping record
 * TODO: remove the macros in favor of straight fucntion calls
 */
#define SCD_INT  0
#define SCD_CHAR 1
#define SCD_DEC  2
#define SCD_KEY  3
#define SCD_PTR  4
void changeSCD(int nDataType, void *pNewData, void *pOldData, int *nFlags, int bFirst);
int validateSCD(int nTable, ds_key_t kRow, int *Permutation);
void printValidation(int nTable, ds_key_t kRow);
#endif

} // __scd__


// pricing.h

namespace __pricing__ {

/*
 * Legal Notice
 *
 * This document and associated source code (the "Work") is a part of a
 * benchmark specification maintained by the TPC.
 *
 * The TPC reserves all right, title, and interest to the Work as provided
 * under U.S. and international laws, including without limitation all patent
 * and trademark rights therein.
 *
 * No Warranty
 *
 * 1.1 TO THE MAXIMUM EXTENT PERMITTED BY APPLICABLE LAW, THE INFORMATION
 *     CONTAINED HEREIN IS PROVIDED "AS IS" AND WITH ALL FAULTS, AND THE
 *     AUTHORS AND DEVELOPERS OF THE WORK HEREBY DISCLAIM ALL OTHER
 *     WARRANTIES AND CONDITIONS, EITHER EXPRESS, IMPLIED OR STATUTORY,
 *     INCLUDING, BUT NOT LIMITED TO, ANY (IF ANY) IMPLIED WARRANTIES,
 *     DUTIES OR CONDITIONS OF MERCHANTABILITY, OF FITNESS FOR A PARTICULAR
 *     PURPOSE, OF ACCURACY OR COMPLETENESS OF RESPONSES, OF RESULTS, OF
 *     WORKMANLIKE EFFORT, OF LACK OF VIRUSES, AND OF LACK OF NEGLIGENCE.
 *     ALSO, THERE IS NO WARRANTY OR CONDITION OF TITLE, QUIET ENJOYMENT,
 *     QUIET POSSESSION, CORRESPONDENCE TO DESCRIPTION OR NON-INFRINGEMENT
 *     WITH REGARD TO THE WORK.
 * 1.2 IN NO EVENT WILL ANY AUTHOR OR DEVELOPER OF THE WORK BE LIABLE TO
 *     ANY OTHER PARTY FOR ANY DAMAGES, INCLUDING BUT NOT LIMITED TO THE
 *     COST OF PROCURING SUBSTITUTE GOODS OR SERVICES, LOST PROFITS, LOSS
 *     OF USE, LOSS OF DATA, OR ANY INCIDENTAL, CONSEQUENTIAL, DIRECT,
 *     INDIRECT, OR SPECIAL DAMAGES WHETHER UNDER CONTRACT, TORT, WARRANTY,
 *     OR OTHERWISE, ARISING IN ANY WAY OUT OF THIS OR ANY OTHER AGREEMENT
 *     RELATING TO THE WORK, WHETHER OR NOT SUCH AUTHOR OR DEVELOPER HAD
 *     ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES.
 *
 * Contributors:
 * Gradient Systems
 */
#ifndef PRICING_H
#define PRICING_H
using namespace __decimal__;

typedef struct DS_PRICING_T {
	decimal_t wholesale_cost;
	decimal_t list_price;
	decimal_t sales_price;
	int quantity;
	decimal_t ext_discount_amt;
	decimal_t ext_sales_price;
	decimal_t ext_wholesale_cost;
	decimal_t ext_list_price;
	decimal_t tax_pct;
	decimal_t ext_tax;
	decimal_t coupon_amt;
	decimal_t ship_cost;
	decimal_t ext_ship_cost;
	decimal_t net_paid;
	decimal_t net_paid_inc_tax;
	decimal_t net_paid_inc_ship;
	decimal_t net_paid_inc_ship_tax;
	decimal_t net_profit;
	decimal_t refunded_cash;
	decimal_t reversed_charge;
	decimal_t store_credit;
	decimal_t fee;
	decimal_t net_loss;
} ds_pricing_t;

typedef struct DS_LIMITS_T {
	int nId;
	char *szQuantity;
	char *szMarkUp;
	char *szDiscount;
	char *szWholesale;
	char *szCoupon;
} ds_limits_t;

void set_pricing(int nTabId, ds_pricing_t *pPricing);
#endif

} // __pricing__


// append_info.h

namespace __append_info__ {

#ifndef R_APPEND_H
#define R_APPEND_H

#include <stdbool.h>
#include <stdlib.h>

using namespace __decimal__;

typedef void *append_info;

append_info *append_info_get(void *info_list, int table_id);

void append_row_start(append_info info);
void append_row_end(append_info info);

void append_varchar(append_info info, const char *value);
void append_key(append_info info, int64_t value);
void append_date(append_info info, int64_t value);
void append_integer(append_info info, int32_t value);
void append_decimal(append_info info, decimal_t *val);
void append_boolean(append_info info, int32_t val);

#endif

} // __append_info__


// w_store.h

namespace __w_store__ {

/*
 * Legal Notice
 *
 * This document and associated source code (the "Work") is a part of a
 * benchmark specification maintained by the TPC.
 *
 * The TPC reserves all right, title, and interest to the Work as provided
 * under U.S. and international laws, including without limitation all patent
 * and trademark rights therein.
 *
 * No Warranty
 *
 * 1.1 TO THE MAXIMUM EXTENT PERMITTED BY APPLICABLE LAW, THE INFORMATION
 *     CONTAINED HEREIN IS PROVIDED "AS IS" AND WITH ALL FAULTS, AND THE
 *     AUTHORS AND DEVELOPERS OF THE WORK HEREBY DISCLAIM ALL OTHER
 *     WARRANTIES AND CONDITIONS, EITHER EXPRESS, IMPLIED OR STATUTORY,
 *     INCLUDING, BUT NOT LIMITED TO, ANY (IF ANY) IMPLIED WARRANTIES,
 *     DUTIES OR CONDITIONS OF MERCHANTABILITY, OF FITNESS FOR A PARTICULAR
 *     PURPOSE, OF ACCURACY OR COMPLETENESS OF RESPONSES, OF RESULTS, OF
 *     WORKMANLIKE EFFORT, OF LACK OF VIRUSES, AND OF LACK OF NEGLIGENCE.
 *     ALSO, THERE IS NO WARRANTY OR CONDITION OF TITLE, QUIET ENJOYMENT,
 *     QUIET POSSESSION, CORRESPONDENCE TO DESCRIPTION OR NON-INFRINGEMENT
 *     WITH REGARD TO THE WORK.
 * 1.2 IN NO EVENT WILL ANY AUTHOR OR DEVELOPER OF THE WORK BE LIABLE TO
 *     ANY OTHER PARTY FOR ANY DAMAGES, INCLUDING BUT NOT LIMITED TO THE
 *     COST OF PROCURING SUBSTITUTE GOODS OR SERVICES, LOST PROFITS, LOSS
 *     OF USE, LOSS OF DATA, OR ANY INCIDENTAL, CONSEQUENTIAL, DIRECT,
 *     INDIRECT, OR SPECIAL DAMAGES WHETHER UNDER CONTRACT, TORT, WARRANTY,
 *     OR OTHERWISE, ARISING IN ANY WAY OUT OF THIS OR ANY OTHER AGREEMENT
 *     RELATING TO THE WORK, WHETHER OR NOT SUCH AUTHOR OR DEVELOPER HAD
 *     ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES.
 *
 * Contributors:
 * Gradient Systems
 */
#ifndef W_STORE_H
#define W_STORE_H

using namespace __address__;
using namespace __decimal__;

#define RS_W_STORE_NAME          50
#define RS_W_STORE_MGR           40
#define RS_W_MARKET_MGR          40
#define RS_W_MARKET_DESC         100
#define STORE_MIN_TAX_PERCENTAGE "0.00"
#define STORE_MAX_TAX_PERCENTAGE "0.11"

/*
 * STORE table structure
 */
struct W_STORE_TBL {
	ds_key_t store_sk;
	char store_id[RS_BKEY + 1];
	ds_key_t rec_start_date_id;
	ds_key_t rec_end_date_id;
	ds_key_t closed_date_id;
	char store_name[RS_W_STORE_NAME + 1];
	int employees;
	int floor_space;
	char *hours;
	char store_manager[RS_W_STORE_MGR + 1];
	int market_id;
	decimal_t dTaxPercentage;
	char *geography_class;
	char market_desc[RS_W_MARKET_DESC + 1];
	char market_manager[RS_W_MARKET_MGR + 1];
	ds_key_t division_id;
	char *division_name;
	ds_key_t company_id;
	char *company_name;
	ds_addr_t address;
};

/***
 *** STORE_xxx Store Defines
 ***/
#define STORE_MIN_DAYS_OPEN  5
#define STORE_MAX_DAYS_OPEN  500
#define STORE_CLOSED_PCT     30
#define STORE_MIN_REV_GROWTH "-0.05"
#define STORE_MAX_REV_GROWTH "0.50"
#define STORE_DESC_MIN       15

int mk_w_store(void *info_arr, ds_key_t kIndex);

#endif

} // __w_store__


// w_tdefs.h

namespace __w_tdefs__ {

using namespace __tdefs__;
/*
 * Legal Notice
 *
 * This document and associated source code (the "Work") is a part of a
 * benchmark specification maintained by the TPC.
 *
 * The TPC reserves all right, title, and interest to the Work as provided
 * under U.S. and international laws, including without limitation all patent
 * and trademark rights therein.
 *
 * No Warranty
 *
 * 1.1 TO THE MAXIMUM EXTENT PERMITTED BY APPLICABLE LAW, THE INFORMATION
 *     CONTAINED HEREIN IS PROVIDED "AS IS" AND WITH ALL FAULTS, AND THE
 *     AUTHORS AND DEVELOPERS OF THE WORK HEREBY DISCLAIM ALL OTHER
 *     WARRANTIES AND CONDITIONS, EITHER EXPRESS, IMPLIED OR STATUTORY,
 *     INCLUDING, BUT NOT LIMITED TO, ANY (IF ANY) IMPLIED WARRANTIES,
 *     DUTIES OR CONDITIONS OF MERCHANTABILITY, OF FITNESS FOR A PARTICULAR
 *     PURPOSE, OF ACCURACY OR COMPLETENESS OF RESPONSES, OF RESULTS, OF
 *     WORKMANLIKE EFFORT, OF LACK OF VIRUSES, AND OF LACK OF NEGLIGENCE.
 *     ALSO, THERE IS NO WARRANTY OR CONDITION OF TITLE, QUIET ENJOYMENT,
 *     QUIET POSSESSION, CORRESPONDENCE TO DESCRIPTION OR NON-INFRINGEMENT
 *     WITH REGARD TO THE WORK.
 * 1.2 IN NO EVENT WILL ANY AUTHOR OR DEVELOPER OF THE WORK BE LIABLE TO
 *     ANY OTHER PARTY FOR ANY DAMAGES, INCLUDING BUT NOT LIMITED TO THE
 *     COST OF PROCURING SUBSTITUTE GOODS OR SERVICES, LOST PROFITS, LOSS
 *     OF USE, LOSS OF DATA, OR ANY INCIDENTAL, CONSEQUENTIAL, DIRECT,
 *     INDIRECT, OR SPECIAL DAMAGES WHETHER UNDER CONTRACT, TORT, WARRANTY,
 *     OR OTHERWISE, ARISING IN ANY WAY OUT OF THIS OR ANY OTHER AGREEMENT
 *     RELATING TO THE WORK, WHETHER OR NOT SUCH AUTHOR OR DEVELOPER HAD
 *     ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES.
 *
 * Contributors:
 * Gradient Systems
 */
#ifndef W_TDEFS_H
#define W_TDEFS_H
tdef w_tdefs[] = {
    {"call_center", "cc", FL_TYPE_2 | FL_SMALL, CALL_CENTER_START, CALL_CENTER_END, CALL_CENTER, -1, NULL, 0, 0, 100, 0,
     0x0B, NULL},
    {"catalog_page", "cp", 0, CATALOG_PAGE_START, CATALOG_PAGE_END, CATALOG_PAGE, -1, NULL, 0, 0, 200, 0, 0x03, NULL},
    {"catalog_returns", "cr", FL_CHILD, CATALOG_RETURNS_START, CATALOG_RETURNS_END, CATALOG_RETURNS, -1, NULL, 0, 0,
     400, 0, 0x10007, NULL},
    {"catalog_sales", "cs", FL_PARENT | FL_DATE_BASED | FL_VPRINT, CATALOG_SALES_START, CATALOG_SALES_END,
     CATALOG_SALES, CATALOG_RETURNS, NULL, 0, 0, 100, 0, 0x28000, NULL},
    {"customer", "cu", 0, CUSTOMER_START, CUSTOMER_END, CUSTOMER, -1, NULL, 0, 0, 700, 0, 0x13, NULL},
    {"customer_address", "ca", 0, CUSTOMER_ADDRESS_START, CUSTOMER_ADDRESS_END, CUSTOMER_ADDRESS, -1, NULL, 0, 0, 600,
     0, 0x03, NULL},
    {"customer_demographics", "cd", 0, CUSTOMER_DEMOGRAPHICS_START, CUSTOMER_DEMOGRAPHICS_END, CUSTOMER_DEMOGRAPHICS,
     823200, NULL, 0, 0, 0, 0, 0x1, NULL},
    {"date_dim", "da", 0, DATE_START, DATE_END, DATET, -1, NULL, 0, 0, 0, 0, 0x03, NULL},
    {"household_demographics", "hd", 0, HOUSEHOLD_DEMOGRAPHICS_START, HOUSEHOLD_DEMOGRAPHICS_END,
     HOUSEHOLD_DEMOGRAPHICS, 7200, NULL, 0, 0, 0, 0, 0x01, NULL},
    {"income_band", "ib", 0, INCOME_BAND_START, INCOME_BAND_END, INCOME_BAND, -1, NULL, 0, 0, 0, 0, 0x1, NULL},
    {"inventory", "inv", FL_DATE_BASED, INVENTORY_START, INVENTORY_END, INVENTORY, -1, NULL, 0, 0, 1000, 0, 0x07, NULL},
    {"item", "it", FL_TYPE_2, ITEM_START, ITEM_END, ITEM, -1, NULL, 0, 0, 50, 0, 0x0B, NULL},
    {"promotion", "pr", 0, PROMOTION_START, PROMOTION_END, PROMOTION, -1, NULL, 0, 0, 200, 0, 0x03, NULL},
    {"reason", "re", 0, REASON_START, REASON_END, REASON, -1, NULL, 0, 0, 0, 0, 0x03, NULL},
    {"ship_mode", "sm", 0, SHIP_MODE_START, SHIP_MODE_END, SHIP_MODE, -1, NULL, 0, 0, 0, 0, 0x03, NULL},
    {"store", "st", FL_TYPE_2 | FL_SMALL, STORE_START, STORE_END, STORE, -1, NULL, 0, 0, 100, 0, 0xB, NULL},
    {"store_returns", "sr", FL_CHILD, STORE_RETURNS_START, STORE_RETURNS_END, STORE_RETURNS, -1, NULL, 0, 0, 700, 0,
     0x204, NULL},
    {"store_sales", "ss", FL_PARENT | FL_DATE_BASED | FL_VPRINT, STORE_SALES_START, STORE_SALES_END, STORE_SALES,
     STORE_RETURNS, NULL, 0, 0, 900, 0, 0x204, NULL},
    {"time_dim", "ti", 0, TIME_START, TIME_END, TIME, -1, NULL, 0, 0, 0, 0, 0x03, NULL},
    {"warehouse", "wa", FL_SMALL, WAREHOUSE_START, WAREHOUSE_END, WAREHOUSE, -1, NULL, 0, 0, 200, 0, 0x03, NULL},
    {"web_page", "wp", FL_TYPE_2, WEB_PAGE_START, WEB_PAGE_END, WEB_PAGE, -1, NULL, 0, 0, 250, 0, 0x0B, NULL},
    {"web_returns", "wr", FL_CHILD, WEB_RETURNS_START, WEB_RETURNS_END, WEB_RETURNS, -1, NULL, 0, 0, 900, 0, 0x2004,
     NULL},
    {"web_sales", "ws", FL_VPRINT | FL_PARENT | FL_DATE_BASED, WEB_SALES_START, WEB_SALES_END, WEB_SALES, WEB_RETURNS,
     NULL, 0, 0, 5, 1100, 0x20008, NULL},
    {"web_site", "web", FL_TYPE_2 | FL_SMALL, WEB_SITE_START, WEB_SITE_END, WEB_SITE, -1, NULL, 0, 0, 100, 0, 0x0B,
     NULL},
    {"dbgen_version", "dv", 0, DBGEN_VERSION_START, DBGEN_VERSION_END, DBGEN_VERSION, -1, NULL, 0, 0, 0, 0, 0, NULL},
    {NULL}};
#endif

} // __w_tdefs__


// s_tdefs.h

namespace __s_tdefs__ {

using namespace __tdefs__;
/*
 * Legal Notice
 *
 * This document and associated source code (the "Work") is a part of a
 * benchmark specification maintained by the TPC.
 *
 * The TPC reserves all right, title, and interest to the Work as provided
 * under U.S. and international laws, including without limitation all patent
 * and trademark rights therein.
 *
 * No Warranty
 *
 * 1.1 TO THE MAXIMUM EXTENT PERMITTED BY APPLICABLE LAW, THE INFORMATION
 *     CONTAINED HEREIN IS PROVIDED "AS IS" AND WITH ALL FAULTS, AND THE
 *     AUTHORS AND DEVELOPERS OF THE WORK HEREBY DISCLAIM ALL OTHER
 *     WARRANTIES AND CONDITIONS, EITHER EXPRESS, IMPLIED OR STATUTORY,
 *     INCLUDING, BUT NOT LIMITED TO, ANY (IF ANY) IMPLIED WARRANTIES,
 *     DUTIES OR CONDITIONS OF MERCHANTABILITY, OF FITNESS FOR A PARTICULAR
 *     PURPOSE, OF ACCURACY OR COMPLETENESS OF RESPONSES, OF RESULTS, OF
 *     WORKMANLIKE EFFORT, OF LACK OF VIRUSES, AND OF LACK OF NEGLIGENCE.
 *     ALSO, THERE IS NO WARRANTY OR CONDITION OF TITLE, QUIET ENJOYMENT,
 *     QUIET POSSESSION, CORRESPONDENCE TO DESCRIPTION OR NON-INFRINGEMENT
 *     WITH REGARD TO THE WORK.
 * 1.2 IN NO EVENT WILL ANY AUTHOR OR DEVELOPER OF THE WORK BE LIABLE TO
 *     ANY OTHER PARTY FOR ANY DAMAGES, INCLUDING BUT NOT LIMITED TO THE
 *     COST OF PROCURING SUBSTITUTE GOODS OR SERVICES, LOST PROFITS, LOSS
 *     OF USE, LOSS OF DATA, OR ANY INCIDENTAL, CONSEQUENTIAL, DIRECT,
 *     INDIRECT, OR SPECIAL DAMAGES WHETHER UNDER CONTRACT, TORT, WARRANTY,
 *     OR OTHERWISE, ARISING IN ANY WAY OUT OF THIS OR ANY OTHER AGREEMENT
 *     RELATING TO THE WORK, WHETHER OR NOT SUCH AUTHOR OR DEVELOPER HAD
 *     ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES.
 *
 * Contributors:
 * Gradient Systems
 */
tdef s_tdefs[] = {
    {"s_brand", "s_br", FL_NOP | FL_SOURCE_DDL, S_BRAND_START, S_BRAND_END, S_BRAND, -1, NULL, 0, 0, 0, 0x0, 0x0, NULL},
    {"s_customer_address", "s_ca", FL_SOURCE_DDL | FL_PASSTHRU, S_CUSTOMER_ADDRESS_START, S_CUSTOMER_ADDRESS_END,
     S_CUSTOMER_ADDRESS, -1, NULL, 0, 0, 0, 0x0, 0x01, NULL},
    {"s_call_center", "s_cc", FL_SOURCE_DDL, S_CALL_CENTER_START, S_CALL_CENTER_END, S_CALL_CENTER, -1, NULL, 0, 0, 0,
     0x0, 0x02, NULL},
    {"s_catalog", "s_ct", FL_SOURCE_DDL | FL_NOP, S_CATALOG_START, S_CATALOG_END, S_CATALOG, -1, NULL, 0, 0, 0, 0x0,
     0x0, NULL},
    {"s_catalog_order", "s_cord", FL_SOURCE_DDL | FL_PARENT | FL_DATE_BASED, S_CATALOG_ORDER_START, S_CATALOG_ORDER_END,
     S_CATALOG_ORDER, S_CATALOG_ORDER_LINEITEM, NULL, 0, 0, 0, 0x0, 0x01, NULL},
    {"s_catalog_order_lineitem", "s_cl", FL_SOURCE_DDL | FL_CHILD | FL_PARENT, S_CATALOG_ORDER_LINEITEM_START,
     S_CATALOG_ORDER_LINEITEM_END, S_CATALOG_ORDER_LINEITEM, S_CATALOG_RETURNS, NULL, 0, 0, 0, 0x0, 0x07, NULL},
    {"s_catalog_page", "s_cp", FL_SOURCE_DDL | FL_PASSTHRU, S_CATALOG_PAGE_START, S_CATALOG_PAGE_END, S_CATALOG_PAGE,
     -1, NULL, 0, 0, 0, 0x0, 0x033, NULL},
    {"s_catalog_promotional_item", "s_ci", FL_NOP | FL_SOURCE_DDL, S_CATALOG_PROMOTIONAL_ITEM_START,
     S_CATALOG_PROMOTIONAL_ITEM_END, S_CATALOG_PROMOTIONAL_ITEM, -1, NULL, 0, 0, 0, 0x0, 0x0, NULL},
    {"s_catalog_returns", "s_cr", FL_SOURCE_DDL | FL_CHILD, S_CATALOG_RETURNS_START, S_CATALOG_RETURNS_END,
     S_CATALOG_RETURNS, -1, NULL, 0, 0, 0, 0x0, 0x0E, NULL},
    {"s_category", "s_cg", FL_NOP | FL_SOURCE_DDL, S_CATEGORY_START, S_CATEGORY_END, S_CATEGORY, -1, NULL, 0, 0, 0, 0x0,
     0x0, NULL},
    {"s_class", "s_cl", FL_NOP | FL_SOURCE_DDL, S_CLASS_START, S_CLASS_END, S_CLASS, -1, NULL, 0, 0, 0, 0x0, 0x0, NULL},
    {"s_company", "s_co", FL_NOP | FL_SOURCE_DDL, S_COMPANY_START, S_COMPANY_END, S_COMPANY, -1, NULL, 0, 0, 0, 0x0,
     0x0, NULL},
    {"s_customer", "s_cu", FL_SOURCE_DDL, S_CUSTOMER_START, S_CUSTOMER_END, S_CUSTOMER, -1, NULL, 0, 0, 0, 0x0, 0x01,
     NULL},
    {"s_division", "s_di", FL_NOP | FL_SOURCE_DDL, S_DIVISION_START, S_DIVISION_END, S_DIVISION, -1, NULL, 0, 0, 0, 0x0,
     0x0, NULL},
    {"s_inventory", "s_in", FL_SOURCE_DDL | FL_DATE_BASED, S_INVENTORY_START, S_INVENTORY_END, S_INVENTORY, -1, NULL, 0,
     0, 0, 0x0, 0x07, NULL},
    {"s_item", "s_it", FL_SOURCE_DDL, S_ITEM_START, S_ITEM_END, S_ITEM, -1, NULL, 0, 0, 0, 0x0, 0x01, NULL},
    {"s_manager", "s_mg", FL_NOP | FL_SOURCE_DDL, S_MANAGER_START, S_MANAGER_END, S_MANAGER, -1, NULL, 0, 0, 0, 0x0,
     0x0, NULL},
    {"s_manufacturer", "s_mn", FL_NOP | FL_SOURCE_DDL, S_MANUFACTURER_START, S_MANUFACTURER_END, S_MANUFACTURER, -1,
     NULL, 0, 0, 0, 0x0, 0x0, NULL},
    {"s_market", "s_mk", FL_NOP | FL_SOURCE_DDL, S_MARKET_START, S_MARKET_END, S_MARKET, -1, NULL, 0, 0, 0, 0x0, 0x0,
     NULL},
    {"s_product", "s_pr", FL_NOP | FL_SOURCE_DDL, S_PRODUCT_START, S_PRODUCT_END, S_PRODUCT, -1, NULL, 0, 0, 0, 0x0,
     0x0, NULL},
    {"s_promotion", "s_pm", FL_SOURCE_DDL | FL_PASSTHRU, S_PROMOTION_START, S_PROMOTION_END, S_PROMOTION, -1, NULL, 0,
     0, 0, 0x0, 0x01, NULL},
    {"s_purchase", "s_pu", FL_SOURCE_DDL | FL_PARENT | FL_DATE_BASED, S_PURCHASE_START, S_PURCHASE_END, S_PURCHASE,
     S_PURCHASE_LINEITEM, NULL, 0, 0, 0, 0x0, 0x01, NULL},
    {"s_purchase_lineitem", "s_pl", FL_SOURCE_DDL | FL_CHILD | FL_PARENT, S_PURCHASE_LINEITEM_START,
     S_PURCHASE_LINEITEM_END, S_PURCHASE_LINEITEM, S_STORE_RETURNS, NULL, 0, 0, 0, 0x0, 0x07, NULL},
    {"s_reason", "s_re", FL_NOP | FL_SOURCE_DDL, S_REASON_START, S_REASON_END, S_REASON, -1, NULL, 0, 0, 0, 0x0, 0x0,
     NULL},
    {"s_store", "s_st", FL_SOURCE_DDL, S_STORE_START, S_STORE_END, S_STORE, -1, NULL, 0, 0, 0, 0x0, 0x01, NULL},
    {"s_store_promotional_item", "s_sp", FL_NOP | FL_SOURCE_DDL, S_STORE_PROMOTIONAL_ITEM_START,
     S_STORE_PROMOTIONAL_ITEM_END, S_STORE_PROMOTIONAL_ITEM, -1, NULL, 0, 0, 0, 0x0, 0x0, NULL},
    {"s_store_returns", "s_sr", FL_SOURCE_DDL | FL_CHILD, S_STORE_RETURNS_START, S_STORE_RETURNS_END, S_STORE_RETURNS,
     -1, NULL, 0, 0, 0, 0x0, 0x0E, NULL},
    {"s_subcategory", "s_ct", FL_NOP | FL_SOURCE_DDL, S_SUBCATEGORY_START, S_SUBCATEGORY_END, S_SUBCATEGORY, -1, NULL,
     0, 0, 0, 0x0, 0x0, NULL},
    {"s_subclass", "s_sc", FL_NOP | FL_SOURCE_DDL, S_SUBCLASS_START, S_SUBCLASS_END, S_SUBCLASS, -1, NULL, 0, 0, 0, 0x0,
     0x0, NULL},
    {"s_warehouse", "s_.h", FL_SOURCE_DDL, S_WAREHOUSE_START, S_WAREHOUSE_END, S_WAREHOUSE, -1, NULL, 0, 0, 0, 0x0,
     0x01, NULL},
    {"s_web_order", "s_wo", FL_SOURCE_DDL | FL_PARENT | FL_DATE_BASED, S_WEB_ORDER_START, S_WEB_ORDER_END, S_WEB_ORDER,
     S_WEB_ORDER_LINEITEM, NULL, 0, 0, 0, 0x0, 0x01, NULL},
    {"s_web_order_lineitem", "s_wl", FL_SOURCE_DDL | FL_CHILD | FL_PARENT, S_WEB_ORDER_LINEITEM_START,
     S_WEB_ORDER_LINEITEM_END, S_WEB_ORDER_LINEITEM, S_WEB_RETURNS, NULL, 0, 0, 0, 0x0, 0x07, NULL},
    {"s_web_page", "s_wp", FL_SOURCE_DDL | FL_PASSTHRU, S_WEB_PAGE_START, S_WEB_PAGE_END, S_WEB_PAGE, -1, NULL, 0, 0, 0,
     0x0, 0x01, NULL},
    {"s_web_promotional_item", "s_wi", FL_NOP | FL_SOURCE_DDL, S_WEB_PROMOTIONAL_ITEM_START, S_WEB_PROMOTIONAL_ITEM_END,
     S_WEB_PROMOTIONAL_ITEM, -1, NULL, 0, 0, 0, 0x0, 0x0, NULL},
    {"s_web_returns", "s_wr", FL_SOURCE_DDL | FL_CHILD, S_WEB_RETURNS_START, S_WEB_RETURNS_END, S_WEB_RETURNS, -1, NULL,
     0, 0, 0, 0x0, 0x0E, NULL},
    {"s_web_site", "s_ws", FL_SOURCE_DDL, S_WEB_SITE_START, S_WEB_SITE_END, S_WEB_SITE, -1, NULL, 0, 0, 0, 0x0, 0x01,
     NULL},
    {"s_zip_to_gmt", "s_zi", FL_SOURCE_DDL | FL_VPRINT, S_ZIPG_START, S_ZIPG_END, S_ZIPG, -1, NULL, 0, 0, 0, 0x0, 0x03,
     NULL},
    {NULL}};

} // __s_tdefs__


// w_call_center.h

namespace __w_call_center__ {

/*
 * Legal Notice
 *
 * This document and associated source code (the "Work") is a part of a
 * benchmark specification maintained by the TPC.
 *
 * The TPC reserves all right, title, and interest to the Work as provided
 * under U.S. and international laws, including without limitation all patent
 * and trademark rights therein.
 *
 * No Warranty
 *
 * 1.1 TO THE MAXIMUM EXTENT PERMITTED BY APPLICABLE LAW, THE INFORMATION
 *     CONTAINED HEREIN IS PROVIDED "AS IS" AND WITH ALL FAULTS, AND THE
 *     AUTHORS AND DEVELOPERS OF THE WORK HEREBY DISCLAIM ALL OTHER
 *     WARRANTIES AND CONDITIONS, EITHER EXPRESS, IMPLIED OR STATUTORY,
 *     INCLUDING, BUT NOT LIMITED TO, ANY (IF ANY) IMPLIED WARRANTIES,
 *     DUTIES OR CONDITIONS OF MERCHANTABILITY, OF FITNESS FOR A PARTICULAR
 *     PURPOSE, OF ACCURACY OR COMPLETENESS OF RESPONSES, OF RESULTS, OF
 *     WORKMANLIKE EFFORT, OF LACK OF VIRUSES, AND OF LACK OF NEGLIGENCE.
 *     ALSO, THERE IS NO WARRANTY OR CONDITION OF TITLE, QUIET ENJOYMENT,
 *     QUIET POSSESSION, CORRESPONDENCE TO DESCRIPTION OR NON-INFRINGEMENT
 *     WITH REGARD TO THE WORK.
 * 1.2 IN NO EVENT WILL ANY AUTHOR OR DEVELOPER OF THE WORK BE LIABLE TO
 *     ANY OTHER PARTY FOR ANY DAMAGES, INCLUDING BUT NOT LIMITED TO THE
 *     COST OF PROCURING SUBSTITUTE GOODS OR SERVICES, LOST PROFITS, LOSS
 *     OF USE, LOSS OF DATA, OR ANY INCIDENTAL, CONSEQUENTIAL, DIRECT,
 *     INDIRECT, OR SPECIAL DAMAGES WHETHER UNDER CONTRACT, TORT, WARRANTY,
 *     OR OTHERWISE, ARISING IN ANY WAY OUT OF THIS OR ANY OTHER AGREEMENT
 *     RELATING TO THE WORK, WHETHER OR NOT SUCH AUTHOR OR DEVELOPER HAD
 *     ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES.
 *
 * Contributors:
 * Gradient Systems
 */
#ifndef W_CALL_CENTER_H
#define W_CALL_CENTER_H
using namespace __constants__;
using namespace __pricing__;
using namespace __address__;
using namespace __decimal__;
using namespace __date__;

#define MIN_CC_TAX_PERCENTAGE "0.00"
#define MAX_CC_TAX_PERCENTAGE "0.12"

/*
 * CALL_CENTER table structure
 */
struct CALL_CENTER_TBL {
	ds_key_t cc_call_center_sk;
	char cc_call_center_id[RS_BKEY + 1];
	ds_key_t cc_rec_start_date_id;
	ds_key_t cc_rec_end_date_id;
	ds_key_t cc_closed_date_id;
	ds_key_t cc_open_date_id;
	char cc_name[RS_CC_NAME + 1];
	char *cc_class;
	int cc_employees;
	int cc_sq_ft;
	char *cc_hours;
	char cc_manager[RS_CC_MANAGER + 1];
	int cc_market_id;
	char cc_market_class[RS_CC_MARKET_CLASS + 1];
	char cc_market_desc[RS_CC_MARKET_DESC + 1];
	char cc_market_manager[RS_CC_MARKET_MANAGER + 1];
	int cc_division_id;
	char cc_division_name[RS_CC_DIVISION_NAME + 1];
	int cc_company;
	char cc_company_name[RS_CC_COMPANY_NAME + 1];
	ds_addr_t cc_address;
	decimal_t cc_tax_percentage;
};

int mk_w_call_center(void *pDest, ds_key_t kIndex);
int pr_w_call_center(void *pSrc);
int ld_w_call_center(void *r);

#endif

} // __w_call_center__


// w_catalog_sales.h

namespace __w_catalog_sales__ {

/*
 * Legal Notice
 *
 * This document and associated source code (the "Work") is a part of a
 * benchmark specification maintained by the TPC.
 *
 * The TPC reserves all right, title, and interest to the Work as provided
 * under U.S. and international laws, including without limitation all patent
 * and trademark rights therein.
 *
 * No Warranty
 *
 * 1.1 TO THE MAXIMUM EXTENT PERMITTED BY APPLICABLE LAW, THE INFORMATION
 *     CONTAINED HEREIN IS PROVIDED "AS IS" AND WITH ALL FAULTS, AND THE
 *     AUTHORS AND DEVELOPERS OF THE WORK HEREBY DISCLAIM ALL OTHER
 *     WARRANTIES AND CONDITIONS, EITHER EXPRESS, IMPLIED OR STATUTORY,
 *     INCLUDING, BUT NOT LIMITED TO, ANY (IF ANY) IMPLIED WARRANTIES,
 *     DUTIES OR CONDITIONS OF MERCHANTABILITY, OF FITNESS FOR A PARTICULAR
 *     PURPOSE, OF ACCURACY OR COMPLETENESS OF RESPONSES, OF RESULTS, OF
 *     WORKMANLIKE EFFORT, OF LACK OF VIRUSES, AND OF LACK OF NEGLIGENCE.
 *     ALSO, THERE IS NO WARRANTY OR CONDITION OF TITLE, QUIET ENJOYMENT,
 *     QUIET POSSESSION, CORRESPONDENCE TO DESCRIPTION OR NON-INFRINGEMENT
 *     WITH REGARD TO THE WORK.
 * 1.2 IN NO EVENT WILL ANY AUTHOR OR DEVELOPER OF THE WORK BE LIABLE TO
 *     ANY OTHER PARTY FOR ANY DAMAGES, INCLUDING BUT NOT LIMITED TO THE
 *     COST OF PROCURING SUBSTITUTE GOODS OR SERVICES, LOST PROFITS, LOSS
 *     OF USE, LOSS OF DATA, OR ANY INCIDENTAL, CONSEQUENTIAL, DIRECT,
 *     INDIRECT, OR SPECIAL DAMAGES WHETHER UNDER CONTRACT, TORT, WARRANTY,
 *     OR OTHERWISE, ARISING IN ANY WAY OUT OF THIS OR ANY OTHER AGREEMENT
 *     RELATING TO THE WORK, WHETHER OR NOT SUCH AUTHOR OR DEVELOPER HAD
 *     ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES.
 *
 * Contributors:
 * Gradient Systems
 */
#ifndef W_CATALOG_SALES_H
#define W_CATALOG_SALES_H

using namespace __pricing__;

/*
 * CATALOG_SALES table structure
 */
struct W_CATALOG_SALES_TBL {
	ds_key_t cs_sold_date_sk;
	ds_key_t cs_sold_time_sk;
	ds_key_t cs_ship_date_sk;
	ds_key_t cs_bill_customer_sk;
	ds_key_t cs_bill_cdemo_sk;
	ds_key_t cs_bill_hdemo_sk;
	ds_key_t cs_bill_addr_sk;
	ds_key_t cs_ship_customer_sk;
	ds_key_t cs_ship_cdemo_sk;
	ds_key_t cs_ship_hdemo_sk;
	ds_key_t cs_ship_addr_sk;
	ds_key_t cs_call_center_sk;
	ds_key_t cs_catalog_page_sk;
	ds_key_t cs_ship_mode_sk;
	ds_key_t cs_warehouse_sk;
	ds_key_t cs_sold_item_sk;
	ds_key_t cs_promo_sk;
	ds_key_t cs_order_number;
	ds_pricing_t cs_pricing;
};

int mk_w_catalog_sales(void *info_arr, ds_key_t index);
int vld_w_catalog_sales(int nTable, ds_key_t kRow, int *Permutation);
#endif

} // __w_catalog_sales__


// w_store_sales.h

namespace __w_store_sales__ {

/*
 * Legal Notice
 *
 * This document and associated source code (the "Work") is a part of a
 * benchmark specification maintained by the TPC.
 *
 * The TPC reserves all right, title, and interest to the Work as provided
 * under U.S. and international laws, including without limitation all patent
 * and trademark rights therein.
 *
 * No Warranty
 *
 * 1.1 TO THE MAXIMUM EXTENT PERMITTED BY APPLICABLE LAW, THE INFORMATION
 *     CONTAINED HEREIN IS PROVIDED "AS IS" AND WITH ALL FAULTS, AND THE
 *     AUTHORS AND DEVELOPERS OF THE WORK HEREBY DISCLAIM ALL OTHER
 *     WARRANTIES AND CONDITIONS, EITHER EXPRESS, IMPLIED OR STATUTORY,
 *     INCLUDING, BUT NOT LIMITED TO, ANY (IF ANY) IMPLIED WARRANTIES,
 *     DUTIES OR CONDITIONS OF MERCHANTABILITY, OF FITNESS FOR A PARTICULAR
 *     PURPOSE, OF ACCURACY OR COMPLETENESS OF RESPONSES, OF RESULTS, OF
 *     WORKMANLIKE EFFORT, OF LACK OF VIRUSES, AND OF LACK OF NEGLIGENCE.
 *     ALSO, THERE IS NO WARRANTY OR CONDITION OF TITLE, QUIET ENJOYMENT,
 *     QUIET POSSESSION, CORRESPONDENCE TO DESCRIPTION OR NON-INFRINGEMENT
 *     WITH REGARD TO THE WORK.
 * 1.2 IN NO EVENT WILL ANY AUTHOR OR DEVELOPER OF THE WORK BE LIABLE TO
 *     ANY OTHER PARTY FOR ANY DAMAGES, INCLUDING BUT NOT LIMITED TO THE
 *     COST OF PROCURING SUBSTITUTE GOODS OR SERVICES, LOST PROFITS, LOSS
 *     OF USE, LOSS OF DATA, OR ANY INCIDENTAL, CONSEQUENTIAL, DIRECT,
 *     INDIRECT, OR SPECIAL DAMAGES WHETHER UNDER CONTRACT, TORT, WARRANTY,
 *     OR OTHERWISE, ARISING IN ANY WAY OUT OF THIS OR ANY OTHER AGREEMENT
 *     RELATING TO THE WORK, WHETHER OR NOT SUCH AUTHOR OR DEVELOPER HAD
 *     ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES.
 *
 * Contributors:
 * Gradient Systems
 */
#ifndef W_STORE_SALES_H
#define W_STORE_SALES_H

using namespace __constants__;
using namespace __pricing__;

/*
 * STORE_SALES table structure
 */
struct W_STORE_SALES_TBL {
	ds_key_t ss_sold_date_sk;
	ds_key_t ss_sold_time_sk;
	ds_key_t ss_sold_item_sk;
	ds_key_t ss_sold_customer_sk;
	ds_key_t ss_sold_cdemo_sk;
	ds_key_t ss_sold_hdemo_sk;
	ds_key_t ss_sold_addr_sk;
	ds_key_t ss_sold_store_sk;
	ds_key_t ss_sold_promo_sk;
	ds_key_t ss_ticket_number;
	ds_pricing_t ss_pricing;
};

int mk_w_store_sales(void *info_arr, ds_key_t kIndex);
int vld_w_store_sales(int nTable, ds_key_t kRow, int *Permutation);
#endif

} // __w_store_sales__


// w_web_returns.h

namespace __w_web_returns__ {

using namespace __porting__;
using namespace __pricing__;
/*
 * Legal Notice
 *
 * This document and associated source code (the "Work") is a part of a
 * benchmark specification maintained by the TPC.
 *
 * The TPC reserves all right, title, and interest to the Work as provided
 * under U.S. and international laws, including without limitation all patent
 * and trademark rights therein.
 *
 * No Warranty
 *
 * 1.1 TO THE MAXIMUM EXTENT PERMITTED BY APPLICABLE LAW, THE INFORMATION
 *     CONTAINED HEREIN IS PROVIDED "AS IS" AND WITH ALL FAULTS, AND THE
 *     AUTHORS AND DEVELOPERS OF THE WORK HEREBY DISCLAIM ALL OTHER
 *     WARRANTIES AND CONDITIONS, EITHER EXPRESS, IMPLIED OR STATUTORY,
 *     INCLUDING, BUT NOT LIMITED TO, ANY (IF ANY) IMPLIED WARRANTIES,
 *     DUTIES OR CONDITIONS OF MERCHANTABILITY, OF FITNESS FOR A PARTICULAR
 *     PURPOSE, OF ACCURACY OR COMPLETENESS OF RESPONSES, OF RESULTS, OF
 *     WORKMANLIKE EFFORT, OF LACK OF VIRUSES, AND OF LACK OF NEGLIGENCE.
 *     ALSO, THERE IS NO WARRANTY OR CONDITION OF TITLE, QUIET ENJOYMENT,
 *     QUIET POSSESSION, CORRESPONDENCE TO DESCRIPTION OR NON-INFRINGEMENT
 *     WITH REGARD TO THE WORK.
 * 1.2 IN NO EVENT WILL ANY AUTHOR OR DEVELOPER OF THE WORK BE LIABLE TO
 *     ANY OTHER PARTY FOR ANY DAMAGES, INCLUDING BUT NOT LIMITED TO THE
 *     COST OF PROCURING SUBSTITUTE GOODS OR SERVICES, LOST PROFITS, LOSS
 *     OF USE, LOSS OF DATA, OR ANY INCIDENTAL, CONSEQUENTIAL, DIRECT,
 *     INDIRECT, OR SPECIAL DAMAGES WHETHER UNDER CONTRACT, TORT, WARRANTY,
 *     OR OTHERWISE, ARISING IN ANY WAY OUT OF THIS OR ANY OTHER AGREEMENT
 *     RELATING TO THE WORK, WHETHER OR NOT SUCH AUTHOR OR DEVELOPER HAD
 *     ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES.
 *
 * Contributors:
 * Gradient Systems
 */
#ifndef W_WEB_RETURNS_H
#define W_WEB_RETURNS_H
/*
 * WEB_RETURNS table structure
 */
struct W_WEB_RETURNS_TBL {
	ds_key_t wr_returned_date_sk;
	ds_key_t wr_returned_time_sk;
	ds_key_t wr_item_sk;
	ds_key_t wr_refunded_customer_sk;
	ds_key_t wr_refunded_cdemo_sk;
	ds_key_t wr_refunded_hdemo_sk;
	ds_key_t wr_refunded_addr_sk;
	ds_key_t wr_returning_customer_sk;
	ds_key_t wr_returning_cdemo_sk;
	ds_key_t wr_returning_hdemo_sk;
	ds_key_t wr_returning_addr_sk;
	ds_key_t wr_web_page_sk;
	ds_key_t wr_reason_sk;
	ds_key_t wr_order_number;
	ds_pricing_t wr_pricing;
};

int mk_w_web_returns(void *row, ds_key_t kIndex);

#endif

} // __w_web_returns__


// build_support.h

namespace __build_support__ {

/*
 * Legal Notice
 *
 * This document and associated source code (the "Work") is a part of a
 * benchmark specification maintained by the TPC.
 *
 * The TPC reserves all right, title, and interest to the Work as provided
 * under U.S. and international laws, including without limitation all patent
 * and trademark rights therein.
 *
 * No Warranty
 *
 * 1.1 TO THE MAXIMUM EXTENT PERMITTED BY APPLICABLE LAW, THE INFORMATION
 *     CONTAINED HEREIN IS PROVIDED "AS IS" AND WITH ALL FAULTS, AND THE
 *     AUTHORS AND DEVELOPERS OF THE WORK HEREBY DISCLAIM ALL OTHER
 *     WARRANTIES AND CONDITIONS, EITHER EXPRESS, IMPLIED OR STATUTORY,
 *     INCLUDING, BUT NOT LIMITED TO, ANY (IF ANY) IMPLIED WARRANTIES,
 *     DUTIES OR CONDITIONS OF MERCHANTABILITY, OF FITNESS FOR A PARTICULAR
 *     PURPOSE, OF ACCURACY OR COMPLETENESS OF RESPONSES, OF RESULTS, OF
 *     WORKMANLIKE EFFORT, OF LACK OF VIRUSES, AND OF LACK OF NEGLIGENCE.
 *     ALSO, THERE IS NO WARRANTY OR CONDITION OF TITLE, QUIET ENJOYMENT,
 *     QUIET POSSESSION, CORRESPONDENCE TO DESCRIPTION OR NON-INFRINGEMENT
 *     WITH REGARD TO THE WORK.
 * 1.2 IN NO EVENT WILL ANY AUTHOR OR DEVELOPER OF THE WORK BE LIABLE TO
 *     ANY OTHER PARTY FOR ANY DAMAGES, INCLUDING BUT NOT LIMITED TO THE
 *     COST OF PROCURING SUBSTITUTE GOODS OR SERVICES, LOST PROFITS, LOSS
 *     OF USE, LOSS OF DATA, OR ANY INCIDENTAL, CONSEQUENTIAL, DIRECT,
 *     INDIRECT, OR SPECIAL DAMAGES WHETHER UNDER CONTRACT, TORT, WARRANTY,
 *     OR OTHERWISE, ARISING IN ANY WAY OUT OF THIS OR ANY OTHER AGREEMENT
 *     RELATING TO THE WORK, WHETHER OR NOT SUCH AUTHOR OR DEVELOPER HAD
 *     ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES.
 *
 * Contributors:
 * Gradient Systems
 */
#ifndef BUILD_SUPPORT_H
#define BUILD_SUPPORT_H

using namespace __decimal__;
using namespace __date__;
using namespace __dist__;
using namespace __columns__;
using namespace __pricing__;

void bitmap_to_dist(void *pDest, const char *distname, ds_key_t *modulus, int vset, int stream);
void dist_to_bitmap(int *pDest, const char *szDistName, int nValue, int nWeight, int nStream);
void random_to_bitmap(int *pDest, int nDist, int nMin, int nMax, int nMean, int nStream);
int city_hash(int nTable, char *city);
void hierarchy_item(int h_level, ds_key_t *id, char **name, ds_key_t kIndex);
ds_key_t mk_join(int from_tbl, int to_tbl, ds_key_t ref_key);
ds_key_t getCatalogNumberFromPage(ds_key_t kPageNumber);
void mk_word(char *dest, const char *syl_set, ds_key_t src, int char_cnt, int col);
int set_locale(int nRegion, decimal_t *longitude, decimal_t *latitude);
int adj_time(ds_key_t *res_date, ds_key_t *res_time, ds_key_t base_date, ds_key_t base_time, ds_key_t offset_key,
             int tabid);
void mk_bkey(char *szDest, ds_key_t kPrimary, int nStream);
int embed_string(char *szDest, const char *szDist, int nValue, int nWeight, int nStream);
int SetScaleIndex(const char *szName, const char *szValue);
int mk_companyname(char *dest, int nTable, int nCompany);
void setUpdateDateRange(int nTable, date_t *pMinDate, date_t *pMaxDate);

#endif /* BUILD_SUPPORT_H */

} // __build_support__


// w_web_sales.h

namespace __w_web_sales__ {

/*
 * Legal Notice
 *
 * This document and associated source code (the "Work") is a part of a
 * benchmark specification maintained by the TPC.
 *
 * The TPC reserves all right, title, and interest to the Work as provided
 * under U.S. and international laws, including without limitation all patent
 * and trademark rights therein.
 *
 * No Warranty
 *
 * 1.1 TO THE MAXIMUM EXTENT PERMITTED BY APPLICABLE LAW, THE INFORMATION
 *     CONTAINED HEREIN IS PROVIDED "AS IS" AND WITH ALL FAULTS, AND THE
 *     AUTHORS AND DEVELOPERS OF THE WORK HEREBY DISCLAIM ALL OTHER
 *     WARRANTIES AND CONDITIONS, EITHER EXPRESS, IMPLIED OR STATUTORY,
 *     INCLUDING, BUT NOT LIMITED TO, ANY (IF ANY) IMPLIED WARRANTIES,
 *     DUTIES OR CONDITIONS OF MERCHANTABILITY, OF FITNESS FOR A PARTICULAR
 *     PURPOSE, OF ACCURACY OR COMPLETENESS OF RESPONSES, OF RESULTS, OF
 *     WORKMANLIKE EFFORT, OF LACK OF VIRUSES, AND OF LACK OF NEGLIGENCE.
 *     ALSO, THERE IS NO WARRANTY OR CONDITION OF TITLE, QUIET ENJOYMENT,
 *     QUIET POSSESSION, CORRESPONDENCE TO DESCRIPTION OR NON-INFRINGEMENT
 *     WITH REGARD TO THE WORK.
 * 1.2 IN NO EVENT WILL ANY AUTHOR OR DEVELOPER OF THE WORK BE LIABLE TO
 *     ANY OTHER PARTY FOR ANY DAMAGES, INCLUDING BUT NOT LIMITED TO THE
 *     COST OF PROCURING SUBSTITUTE GOODS OR SERVICES, LOST PROFITS, LOSS
 *     OF USE, LOSS OF DATA, OR ANY INCIDENTAL, CONSEQUENTIAL, DIRECT,
 *     INDIRECT, OR SPECIAL DAMAGES WHETHER UNDER CONTRACT, TORT, WARRANTY,
 *     OR OTHERWISE, ARISING IN ANY WAY OUT OF THIS OR ANY OTHER AGREEMENT
 *     RELATING TO THE WORK, WHETHER OR NOT SUCH AUTHOR OR DEVELOPER HAD
 *     ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES.
 *
 * Contributors:
 * Gradient Systems
 */

using namespace __porting__;
using namespace __pricing__;

/*
 * WEB_SALES table structure
 */
struct W_WEB_SALES_TBL {
	ds_key_t ws_sold_date_sk;
	ds_key_t ws_sold_time_sk;
	ds_key_t ws_ship_date_sk;
	ds_key_t ws_item_sk;
	ds_key_t ws_bill_customer_sk;
	ds_key_t ws_bill_cdemo_sk;
	ds_key_t ws_bill_hdemo_sk;
	ds_key_t ws_bill_addr_sk;
	ds_key_t ws_ship_customer_sk;
	ds_key_t ws_ship_cdemo_sk;
	ds_key_t ws_ship_hdemo_sk;
	ds_key_t ws_ship_addr_sk;
	ds_key_t ws_web_page_sk;
	ds_key_t ws_web_site_sk;
	ds_key_t ws_ship_mode_sk;
	ds_key_t ws_warehouse_sk;
	ds_key_t ws_promo_sk;
	ds_key_t ws_order_number;
	ds_pricing_t ws_pricing;
};

/***
*** WS_xxx Web Sales Defines
***/
#define WS_QUANTITY_MAX  "100"
#define WS_MARKUP_MAX    "2.00"
#define WS_DISCOUNT_MAX  "1.00"
#define WS_WHOLESALE_MAX "100.00"
#define WS_COUPON_MAX    "0.50"
#define WS_GIFT_PCT                                                                                                    \
	7                        /* liklihood that a purchase is shipped to someone else                                   \
	                          */
#define WS_ITEMS_PER_ORDER 9 /* number of lineitems in an order */
#define WS_MIN_SHIP_DELAY  1 /* time between order date and ship date */
#define WS_MAX_SHIP_DELAY  120

int mk_w_web_sales(void *info_arr, ds_key_t kIndex);
int vld_web_sales(int nTable, ds_key_t kRow, int *Permutation);

} // __w_web_sales__


// w_store_returns.h

namespace __w_store_returns__ {

/*
 * Legal Notice
 *
 * This document and associated source code (the "Work") is a part of a
 * benchmark specification maintained by the TPC.
 *
 * The TPC reserves all right, title, and interest to the Work as provided
 * under U.S. and international laws, including without limitation all patent
 * and trademark rights therein.
 *
 * No Warranty
 *
 * 1.1 TO THE MAXIMUM EXTENT PERMITTED BY APPLICABLE LAW, THE INFORMATION
 *     CONTAINED HEREIN IS PROVIDED "AS IS" AND WITH ALL FAULTS, AND THE
 *     AUTHORS AND DEVELOPERS OF THE WORK HEREBY DISCLAIM ALL OTHER
 *     WARRANTIES AND CONDITIONS, EITHER EXPRESS, IMPLIED OR STATUTORY,
 *     INCLUDING, BUT NOT LIMITED TO, ANY (IF ANY) IMPLIED WARRANTIES,
 *     DUTIES OR CONDITIONS OF MERCHANTABILITY, OF FITNESS FOR A PARTICULAR
 *     PURPOSE, OF ACCURACY OR COMPLETENESS OF RESPONSES, OF RESULTS, OF
 *     WORKMANLIKE EFFORT, OF LACK OF VIRUSES, AND OF LACK OF NEGLIGENCE.
 *     ALSO, THERE IS NO WARRANTY OR CONDITION OF TITLE, QUIET ENJOYMENT,
 *     QUIET POSSESSION, CORRESPONDENCE TO DESCRIPTION OR NON-INFRINGEMENT
 *     WITH REGARD TO THE WORK.
 * 1.2 IN NO EVENT WILL ANY AUTHOR OR DEVELOPER OF THE WORK BE LIABLE TO
 *     ANY OTHER PARTY FOR ANY DAMAGES, INCLUDING BUT NOT LIMITED TO THE
 *     COST OF PROCURING SUBSTITUTE GOODS OR SERVICES, LOST PROFITS, LOSS
 *     OF USE, LOSS OF DATA, OR ANY INCIDENTAL, CONSEQUENTIAL, DIRECT,
 *     INDIRECT, OR SPECIAL DAMAGES WHETHER UNDER CONTRACT, TORT, WARRANTY,
 *     OR OTHERWISE, ARISING IN ANY WAY OUT OF THIS OR ANY OTHER AGREEMENT
 *     RELATING TO THE WORK, WHETHER OR NOT SUCH AUTHOR OR DEVELOPER HAD
 *     ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES.
 *
 * Contributors:
 * Gradient Systems
 */
#ifndef W_STORE_RETURNS_H
#define W_STORE_RETURNS_H
using namespace __pricing__;
using namespace __decimal__;

#define SR_SAME_CUSTOMER 80

/*
 * STORE_RETURNS table structure
 */
struct W_STORE_RETURNS_TBL {
	ds_key_t sr_returned_date_sk;
	ds_key_t sr_returned_time_sk;
	ds_key_t sr_item_sk;
	ds_key_t sr_customer_sk;
	ds_key_t sr_cdemo_sk;
	ds_key_t sr_hdemo_sk;
	ds_key_t sr_addr_sk;
	ds_key_t sr_store_sk;
	ds_key_t sr_reason_sk;
	ds_key_t sr_ticket_number;
	ds_pricing_t sr_pricing;
};

int mk_w_store_returns(void *row, ds_key_t kIndex);
#endif

} // __w_store_returns__


// w_catalog_returns.h

namespace __w_catalog_returns__ {

/*
 * Legal Notice
 *
 * This document and associated source code (the "Work") is a part of a
 * benchmark specification maintained by the TPC.
 *
 * The TPC reserves all right, title, and interest to the Work as provided
 * under U.S. and international laws, including without limitation all patent
 * and trademark rights therein.
 *
 * No Warranty
 *
 * 1.1 TO THE MAXIMUM EXTENT PERMITTED BY APPLICABLE LAW, THE INFORMATION
 *     CONTAINED HEREIN IS PROVIDED "AS IS" AND WITH ALL FAULTS, AND THE
 *     AUTHORS AND DEVELOPERS OF THE WORK HEREBY DISCLAIM ALL OTHER
 *     WARRANTIES AND CONDITIONS, EITHER EXPRESS, IMPLIED OR STATUTORY,
 *     INCLUDING, BUT NOT LIMITED TO, ANY (IF ANY) IMPLIED WARRANTIES,
 *     DUTIES OR CONDITIONS OF MERCHANTABILITY, OF FITNESS FOR A PARTICULAR
 *     PURPOSE, OF ACCURACY OR COMPLETENESS OF RESPONSES, OF RESULTS, OF
 *     WORKMANLIKE EFFORT, OF LACK OF VIRUSES, AND OF LACK OF NEGLIGENCE.
 *     ALSO, THERE IS NO WARRANTY OR CONDITION OF TITLE, QUIET ENJOYMENT,
 *     QUIET POSSESSION, CORRESPONDENCE TO DESCRIPTION OR NON-INFRINGEMENT
 *     WITH REGARD TO THE WORK.
 * 1.2 IN NO EVENT WILL ANY AUTHOR OR DEVELOPER OF THE WORK BE LIABLE TO
 *     ANY OTHER PARTY FOR ANY DAMAGES, INCLUDING BUT NOT LIMITED TO THE
 *     COST OF PROCURING SUBSTITUTE GOODS OR SERVICES, LOST PROFITS, LOSS
 *     OF USE, LOSS OF DATA, OR ANY INCIDENTAL, CONSEQUENTIAL, DIRECT,
 *     INDIRECT, OR SPECIAL DAMAGES WHETHER UNDER CONTRACT, TORT, WARRANTY,
 *     OR OTHERWISE, ARISING IN ANY WAY OUT OF THIS OR ANY OTHER AGREEMENT
 *     RELATING TO THE WORK, WHETHER OR NOT SUCH AUTHOR OR DEVELOPER HAD
 *     ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES.
 *
 * Contributors:
 * Gradient Systems
 */
#ifndef W_CATALOG_RETURNS_H
#define W_CATALOG_RETURNS_H

using namespace __pricing__;

/*
 * CATALOG_RETURNS table structure
 */
struct W_CATALOG_RETURNS_TBL {
	ds_key_t cr_returned_date_sk;
	ds_key_t cr_returned_time_sk;
	ds_key_t cr_item_sk;
	ds_key_t cr_refunded_customer_sk;
	ds_key_t cr_refunded_cdemo_sk;
	ds_key_t cr_refunded_hdemo_sk;
	ds_key_t cr_refunded_addr_sk;
	ds_key_t cr_returning_customer_sk;
	ds_key_t cr_returning_cdemo_sk;
	ds_key_t cr_returning_hdemo_sk;
	ds_key_t cr_returning_addr_sk;
	ds_key_t cr_call_center_sk;
	ds_key_t cr_catalog_page_sk;
	ds_key_t cr_ship_mode_sk;
	ds_key_t cr_warehouse_sk;
	ds_key_t cr_reason_sk;
	ds_key_t cr_order_number;
	ds_pricing_t cr_pricing;
	decimal_t cr_fee;
	decimal_t cr_refunded_cash;
	decimal_t cr_reversed_charge;
	decimal_t cr_store_credit;
	decimal_t cr_net_loss;
};

int mk_w_catalog_returns(void *row, ds_key_t kIndex);

#endif

} // __w_catalog_returns__


// params.h

namespace __params__ {

/*
 * Legal Notice
 *
 * This document and associated source code (the "Work") is a part of a
 * benchmark specification maintained by the TPC.
 *
 * The TPC reserves all right, title, and interest to the Work as provided
 * under U.S. and international laws, including without limitation all patent
 * and trademark rights therein.
 *
 * No Warranty
 *
 * 1.1 TO THE MAXIMUM EXTENT PERMITTED BY APPLICABLE LAW, THE INFORMATION
 *     CONTAINED HEREIN IS PROVIDED "AS IS" AND WITH ALL FAULTS, AND THE
 *     AUTHORS AND DEVELOPERS OF THE WORK HEREBY DISCLAIM ALL OTHER
 *     WARRANTIES AND CONDITIONS, EITHER EXPRESS, IMPLIED OR STATUTORY,
 *     INCLUDING, BUT NOT LIMITED TO, ANY (IF ANY) IMPLIED WARRANTIES,
 *     DUTIES OR CONDITIONS OF MERCHANTABILITY, OF FITNESS FOR A PARTICULAR
 *     PURPOSE, OF ACCURACY OR COMPLETENESS OF RESPONSES, OF RESULTS, OF
 *     WORKMANLIKE EFFORT, OF LACK OF VIRUSES, AND OF LACK OF NEGLIGENCE.
 *     ALSO, THERE IS NO WARRANTY OR CONDITION OF TITLE, QUIET ENJOYMENT,
 *     QUIET POSSESSION, CORRESPONDENCE TO DESCRIPTION OR NON-INFRINGEMENT
 *     WITH REGARD TO THE WORK.
 * 1.2 IN NO EVENT WILL ANY AUTHOR OR DEVELOPER OF THE WORK BE LIABLE TO
 *     ANY OTHER PARTY FOR ANY DAMAGES, INCLUDING BUT NOT LIMITED TO THE
 *     COST OF PROCURING SUBSTITUTE GOODS OR SERVICES, LOST PROFITS, LOSS
 *     OF USE, LOSS OF DATA, OR ANY INCIDENTAL, CONSEQUENTIAL, DIRECT,
 *     INDIRECT, OR SPECIAL DAMAGES WHETHER UNDER CONTRACT, TORT, WARRANTY,
 *     OR OTHERWISE, ARISING IN ANY WAY OUT OF THIS OR ANY OTHER AGREEMENT
 *     RELATING TO THE WORK, WHETHER OR NOT SUCH AUTHOR OR DEVELOPER HAD
 *     ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES.
 *
 * Contributors:
 * Gradient Systems
 */
#ifndef QGEN_PARAMS_H
#define QGEN_PARAMS_H

using namespace __r_params__;
using namespace __release__;
using namespace __build_support__;

#ifdef DECLARER

option_t options[] = {{"ABREVIATION", OPT_STR, 0, "build table with abreviation <s>", NULL, ""},
                      {"DELIMITER", OPT_STR | OPT_ADV, 1, "use <s> as output field separator", NULL, "|"},
                      {"DIR", OPT_STR, 2, "generate tables in directory <s>", NULL, "."},
                      {"DISTRIBUTIONS", OPT_STR | OPT_ADV, 3, "read distributions from file <s>", NULL, "NONE"},
                      {"FORCE", OPT_FLG | OPT_ADV, 4, "over-write data files without prompting", NULL, "N"},
                      {"HELP", OPT_INT, 5, "display this message", usage, "0"},
                      {"PARAMS", OPT_STR, 6, "read parameters from file <s>", read_file, ""},
                      {"PROG", OPT_STR | OPT_HIDE | OPT_SET, 7, "DO NOT MODIFY", NULL, "dsdgen"},
                      {"QUIET", OPT_FLG, 8, "disable all output to stdout/stderr", NULL, "N"},
                      {"SCALE", OPT_STR, 9, "volume of data to generate in GB", SetScaleIndex, "1"},
                      {"SUFFIX", OPT_STR | OPT_ADV, 10, "use <s> as output file suffix", NULL, ".dat"},
                      {"TABLE", OPT_STR, 11, "build only table <s>", NULL, "ALL"},
                      {"TERMINATE", OPT_FLG | OPT_ADV, 12, "end each record with a field delimiter", NULL, "Y"},
                      {"UPDATE", OPT_INT, 13, "generate update data set <n>", NULL, ""},
                      {"VERBOSE", OPT_FLG, 14, "enable verbose output", NULL, "N"},
                      {"_SCALE_INDEX", OPT_INT | OPT_HIDE, 15, "Scale band; used for dist lookups", NULL, "1"},
                      {"PARALLEL", OPT_INT, 16, "build data in <n> separate chunks", NULL, ""},
                      {"CHILD", OPT_INT, 17, "generate <n>th chunk of the parallelized data", NULL, "1"},
                      {"CHKSEEDS", OPT_FLG | OPT_HIDE, 18, "validate RNG usage for parallelism", NULL, "N"},
                      {"RELEASE", OPT_FLG, 19, "display the release information", printReleaseInfo, "N"},
                      {"_FILTER", OPT_FLG, 20, "output data to stdout", NULL, "N"},
                      {"VALIDATE", OPT_FLG, 21, "produce rows for data validation", NULL, "N"},
                      {"VCOUNT", OPT_INT | OPT_ADV, 22, "set number of validation rows to be produced", NULL, "50"},
                      {"VSUFFIX", OPT_STR | OPT_ADV, 23, "set file suffix for data validation", NULL, ".vld"},
                      {"RNGSEED", OPT_INT | OPT_ADV, 24, "set RNG seed", NULL, "19620718"},
                      {NULL}};

char *params[23 + 2];
#else
extern option_t options[];
extern char *params[];
extern char *szTableNames[];
#endif

#endif

} // __params__

