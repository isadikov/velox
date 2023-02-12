//===----------------------------------------------------------------------===//
//                         DuckDB                                               
//                                                                              
// TPC-DS amalgamation file                                                     
//                                                                              
//                                                                              
//===----------------------------------------------------------------------===//


#include "duckdb.hpp"
#include "duckdb-internal.hpp"
#include "tpcds-extension.hpp"
#include "tpcds_constants.hpp"
#include "tpcds_idx.hpp"

using namespace std;
using namespace tpcds;

// init.cpp

int InitConstants::init_rand_init = 0;
int InitConstants::mk_address_init = 0;
int InitConstants::setUpdateDateRange_init = 0;
int InitConstants::mk_dbgen_version_init = 0;
int InitConstants::getCatalogNumberFromPage_init = 0;
int InitConstants::checkSeeds_init = 0;
int InitConstants::dateScaling_init = 0;
int InitConstants::mk_w_call_center_init = 0;
int InitConstants::mk_w_catalog_page_init = 0;
int InitConstants::mk_master_catalog_sales_init = 0;
int InitConstants::dectostr_init = 0;
int InitConstants::date_join_init = 0;
int InitConstants::setSCDKeys_init = 0;
int InitConstants::scd_join_init = 0;
int InitConstants::matchSCDSK_init = 0;
int InitConstants::skipDays_init = 0;
int InitConstants::mk_w_catalog_returns_init = 0;
int InitConstants::mk_detail_catalog_sales_init = 0;
int InitConstants::mk_w_customer_init = 0;
int InitConstants::mk_w_date_init = 0;
int InitConstants::mk_w_inventory_init = 0;
int InitConstants::mk_w_item_init = 0;
int InitConstants::mk_w_promotion_init = 0;
int InitConstants::mk_w_reason_init = 0;
int InitConstants::mk_w_ship_mode_init = 0;
int InitConstants::mk_w_store_returns_init = 0;
int InitConstants::mk_master_store_sales_init = 0;
int InitConstants::mk_w_store_init = 0;
int InitConstants::mk_w_web_page_init = 0;
int InitConstants::mk_w_web_returns_init = 0;
int InitConstants::mk_master_init = 0;
int InitConstants::mk_detail_init = 0;
int InitConstants::mk_w_web_site_init = 0;
int InitConstants::mk_cust_init = 0;
int InitConstants::mk_order_init = 0;
int InitConstants::mk_part_init = 0;
int InitConstants::mk_supp_init = 0;
int InitConstants::dbg_text_init = 0;
int InitConstants::find_dist_init = 0;
int InitConstants::cp_join_init = 0;
int InitConstants::web_join_init = 0;
int InitConstants::set_pricing_init = 0;
int InitConstants::init_params_init = 0;
int InitConstants::get_rowcount_init = 0;

void InitConstants::Reset() {
	init_rand_init = 0;
	mk_address_init = 0;
	setUpdateDateRange_init = 0;
	mk_dbgen_version_init = 0;
	getCatalogNumberFromPage_init = 0;
	checkSeeds_init = 0;
	dateScaling_init = 0;
	mk_w_call_center_init = 0;
	mk_w_catalog_page_init = 0;
	mk_master_catalog_sales_init = 0;
	dectostr_init = 0;
	date_join_init = 0;
	setSCDKeys_init = 0;
	scd_join_init = 0;
	matchSCDSK_init = 0;
	skipDays_init = 0;
	mk_w_catalog_returns_init = 0;
	mk_detail_catalog_sales_init = 0;
	mk_w_customer_init = 0;
	mk_w_date_init = 0;
	mk_w_inventory_init = 0;
	mk_w_item_init = 0;
	mk_w_promotion_init = 0;
	mk_w_reason_init = 0;
	mk_w_ship_mode_init = 0;
	mk_w_store_returns_init = 0;
	mk_master_store_sales_init = 0;
	mk_w_store_init = 0;
	mk_w_web_page_init = 0;
	mk_w_web_returns_init = 0;
	mk_master_init = 0;
	mk_detail_init = 0;
	mk_w_web_site_init = 0;
	mk_cust_init = 0;
	mk_order_init = 0;
	mk_part_init = 0;
	mk_supp_init = 0;
	dbg_text_init = 0;
	find_dist_init = 0;
	cp_join_init = 0;
	web_join_init = 0;
	set_pricing_init = 0;
	init_params_init = 0;
	get_rowcount_init = 0;
}

// load.cpp

#ifdef SQLSERVER
// ODBC headers
#include <sql.h>
#include <sqlext.h>
#include <odbcss.h>
SQLHENV henv;
#endif

/*
 * Routine:
 * Purpose:
 * Algorithm:
 * Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO: None
 */
int create_table(int nTable) {
	return (0);
}

/*
 * Routine:
 * Purpose:
 * Algorithm:
 * Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO: None
 */
void load_init(void)

{
#ifdef SQLSERVER
	SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &henv);
	SQLSetEnvAttr(henv, SQL_ATTR_ODBC_VERSION, (void *)SQL_OV_ODBC3, 0);
#endif

	return;
}

/*
 * Routine:
 * Purpose:
 * Algorithm:
 * Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO: None
 */
void load_close(void) {
#ifdef SQLSERVER
	SQLFreeHandle(SQL_HANDLE_ENV, henv);
#endif

	return;
}

// tpcds-extension.cpp
#define DUCKDB_EXTENSION_MAIN



#ifndef DUCKDB_AMALGAMATION
#endif

namespace duckdb {

struct DSDGenFunctionData : public TableFunctionData {
	DSDGenFunctionData() {
	}

	bool finished = false;
	double sf = 0;
	string schema = DEFAULT_SCHEMA;
	string suffix;
	bool overwrite = false;
	bool keys = false;
};

static unique_ptr<FunctionData> DsdgenBind(ClientContext &context, TableFunctionBindInput &input,
                                           vector<LogicalType> &return_types, vector<string> &names) {
	auto result = make_unique<DSDGenFunctionData>();
	for (auto &kv : input.named_parameters) {
		if (kv.first == "sf") {
			result->sf = kv.second.GetValue<double>();
		} else if (kv.first == "schema") {
			result->schema = StringValue::Get(kv.second);
		} else if (kv.first == "suffix") {
			result->suffix = StringValue::Get(kv.second);
		} else if (kv.first == "overwrite") {
			result->overwrite = kv.second.GetValue<bool>();
		} else if (kv.first == "keys") {
			result->keys = kv.second.GetValue<bool>();
		}
	}
	return_types.emplace_back(LogicalType::BOOLEAN);
	names.emplace_back("Success");
	return std::move(result);
}

static void DsdgenFunction(ClientContext &context, TableFunctionInput &data_p, DataChunk &output) {
	auto &data = (DSDGenFunctionData &)*data_p.bind_data;
	if (data.finished) {
		return;
	}
	tpcds::DSDGenWrapper::CreateTPCDSSchema(context, data.schema, data.suffix, data.keys, data.overwrite);
	tpcds::DSDGenWrapper::DSDGen(data.sf, context, data.schema, data.suffix);

	data.finished = true;
}

struct TPCDSData : public GlobalTableFunctionState {
	TPCDSData() : offset(0) {
	}
	idx_t offset;
};

unique_ptr<GlobalTableFunctionState> TPCDSInit(ClientContext &context, TableFunctionInitInput &input) {
	auto result = make_unique<TPCDSData>();
	return std::move(result);
}

static unique_ptr<FunctionData> TPCDSQueryBind(ClientContext &context, TableFunctionBindInput &input,
                                               vector<LogicalType> &return_types, vector<string> &names) {
	names.emplace_back("query_nr");
	return_types.emplace_back(LogicalType::INTEGER);

	names.emplace_back("query");
	return_types.emplace_back(LogicalType::VARCHAR);

	return nullptr;
}

static void TPCDSQueryFunction(ClientContext &context, TableFunctionInput &data_p, DataChunk &output) {
	auto &data = (TPCDSData &)*data_p.global_state;
	idx_t tpcds_queries = tpcds::DSDGenWrapper::QueriesCount();
	if (data.offset >= tpcds_queries) {
		// finished returning values
		return;
	}
	idx_t chunk_count = 0;
	while (data.offset < tpcds_queries && chunk_count < STANDARD_VECTOR_SIZE) {
		auto query = TPCDSExtension::GetQuery(data.offset + 1);
		// "query_nr", PhysicalType::INT32
		output.SetValue(0, chunk_count, Value::INTEGER((int32_t)data.offset + 1));
		// "query", PhysicalType::VARCHAR
		output.SetValue(1, chunk_count, Value(query));
		data.offset++;
		chunk_count++;
	}
	output.SetCardinality(chunk_count);
}

static unique_ptr<FunctionData> TPCDSQueryAnswerBind(ClientContext &context, TableFunctionBindInput &input,
                                                     vector<LogicalType> &return_types, vector<string> &names) {
	names.emplace_back("query_nr");
	return_types.emplace_back(LogicalType::INTEGER);

	names.emplace_back("scale_factor");
	return_types.emplace_back(LogicalType::DOUBLE);

	names.emplace_back("answer");
	return_types.emplace_back(LogicalType::VARCHAR);

	return nullptr;
}

static void TPCDSQueryAnswerFunction(ClientContext &context, TableFunctionInput &data_p, DataChunk &output) {
	auto &data = (TPCDSData &)*data_p.global_state;
	idx_t tpcds_queries = tpcds::DSDGenWrapper::QueriesCount();
	vector<double> scale_factors {1, 10};
	idx_t total_answers = tpcds_queries * scale_factors.size();
	if (data.offset >= total_answers) {
		// finished returning values
		return;
	}
	idx_t chunk_count = 0;
	while (data.offset < total_answers && chunk_count < STANDARD_VECTOR_SIZE) {
		idx_t cur_query = data.offset % tpcds_queries;
		idx_t cur_sf = data.offset / tpcds_queries;
		auto answer = TPCDSExtension::GetAnswer(scale_factors[cur_sf], cur_query + 1);
		// "query_nr", PhysicalType::INT32
		output.SetValue(0, chunk_count, Value::INTEGER((int32_t)cur_query + 1));
		// "scale_factor", PhysicalType::DOUBLE
		output.SetValue(1, chunk_count, Value::DOUBLE(scale_factors[cur_sf]));
		// "query", PhysicalType::VARCHAR
		output.SetValue(2, chunk_count, Value(answer));
		data.offset++;
		chunk_count++;
	}
	output.SetCardinality(chunk_count);
}

static string PragmaTpcdsQuery(ClientContext &context, const FunctionParameters &parameters) {
	auto index = parameters.values[0].GetValue<int32_t>();
	return tpcds::DSDGenWrapper::GetQuery(index);
}

void TPCDSExtension::Load(DuckDB &db) {
	Connection con(db);
	con.BeginTransaction();

	TableFunction dsdgen_func("dsdgen", {}, DsdgenFunction, DsdgenBind);
	dsdgen_func.named_parameters["sf"] = LogicalType::DOUBLE;
	dsdgen_func.named_parameters["overwrite"] = LogicalType::BOOLEAN;
	dsdgen_func.named_parameters["keys"] = LogicalType::BOOLEAN;
	dsdgen_func.named_parameters["schema"] = LogicalType::VARCHAR;
	dsdgen_func.named_parameters["suffix"] = LogicalType::VARCHAR;
	CreateTableFunctionInfo dsdgen_info(dsdgen_func);

	// create the dsdgen function
	auto &catalog = Catalog::GetSystemCatalog(*con.context);
	catalog.CreateTableFunction(*con.context, &dsdgen_info);

	// create the TPCDS pragma that allows us to run the query
	auto tpcds_func = PragmaFunction::PragmaCall("tpcds", PragmaTpcdsQuery, {LogicalType::BIGINT});
	CreatePragmaFunctionInfo info(tpcds_func);
	catalog.CreatePragmaFunction(*con.context, &info);

	// create the TPCDS_QUERIES function that returns the query
	TableFunction tpcds_query_func("tpcds_queries", {}, TPCDSQueryFunction, TPCDSQueryBind, TPCDSInit);
	CreateTableFunctionInfo tpcds_query_info(tpcds_query_func);
	catalog.CreateTableFunction(*con.context, &tpcds_query_info);

	// create the TPCDS_ANSWERS that returns the query result
	TableFunction tpcds_query_answer_func("tpcds_answers", {}, TPCDSQueryAnswerFunction, TPCDSQueryAnswerBind,
	                                      TPCDSInit);
	CreateTableFunctionInfo tpcds_query_asnwer_info(tpcds_query_answer_func);
	catalog.CreateTableFunction(*con.context, &tpcds_query_asnwer_info);

	con.Commit();
}

std::string TPCDSExtension::GetQuery(int query) {
	return tpcds::DSDGenWrapper::GetQuery(query);
}

std::string TPCDSExtension::GetAnswer(double sf, int query) {
	return tpcds::DSDGenWrapper::GetAnswer(sf, query);
}

std::string TPCDSExtension::Name() {
	return "tpcds";
}

} // namespace duckdb

extern "C" {
DUCKDB_EXTENSION_API void tpcds_init(duckdb::DatabaseInstance &db) {
	duckdb::DuckDB db_wrapper(db);
	db_wrapper.LoadExtension<duckdb::TPCDSExtension>();
}

DUCKDB_EXTENSION_API const char *tpcds_version() {
	return duckdb::DuckDB::LibraryVersion();
}
}

#ifndef DUCKDB_EXTENSION_MAIN
#error DUCKDB_EXTENSION_MAIN not defined
#endif

// StringBuffer.cpp
#include <stdio.h>
#include <assert.h>
#ifndef USE_STDLIB_H
#include <malloc.h>
#endif

/*
 * Routine: InitBuffer
 * Purpose:
 * Algorithm:
 * Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO: None
 */
StringBuffer_t *InitBuffer(int nSize, int nIncrement) {
	StringBuffer_t *pBuf;

	pBuf = (StringBuffer_t *)malloc(sizeof(struct STRING_BUFFER_T));
	MALLOC_CHECK(pBuf);
	if (pBuf == NULL)
		return (NULL);
	memset((void *)pBuf, 0, sizeof(struct STRING_BUFFER_T));

	pBuf->pText = (char *)malloc(sizeof(char) * nSize);
	MALLOC_CHECK(pBuf->pText);
	if (pBuf->pText == NULL)
		return (NULL);
	memset((void *)pBuf->pText, 0, sizeof(char) * nSize);

	pBuf->nIncrement = nIncrement;
	pBuf->nBytesAllocated = nSize;
	pBuf->nFlags = SB_INIT;

	return (pBuf);
}

/*
 * Routine: AddBuffer
 * Purpose:
 * Algorithm:
 * Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO: None
 */
int AddBuffer(StringBuffer_t *pBuf, char *pStr) {
	int nRemaining = pBuf->nBytesAllocated - pBuf->nBytesUsed, nRequested = strlen(pStr);

	if (!nRequested)
		return (0);

	while (nRequested >= nRemaining) {
		pBuf->pText = (char *)realloc((void *)pBuf->pText, pBuf->nBytesAllocated + pBuf->nIncrement);
		if (!pBuf->pText)
			return (-1);
		pBuf->nBytesAllocated += pBuf->nIncrement;
		nRemaining += pBuf->nIncrement;
	}

	strcat(pBuf->pText, pStr);
	if (pBuf->nBytesUsed == 0) /* first string adds a terminator */
		pBuf->nBytesUsed = 1;
	pBuf->nBytesUsed += nRequested;

	return (0);
}

/*
 * Routine: ResetStringBuffer
 * Purpose:
 * Algorithm:
 * Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO: None
 */
int ResetBuffer(StringBuffer_t *pBuf) {
	pBuf->nBytesUsed = 0;
	if (pBuf->nBytesAllocated)
		pBuf->pText[0] = '\0';

	return (0);
}

/*
 * Routine: GetBuffer
 * Purpose:
 * Algorithm:
 * Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO: None
 */
char *GetBuffer(StringBuffer_t *pBuf) {
	return (pBuf->pText);
}

/*
 * Routine: FreeBuffer
 * Purpose:
 * Algorithm:
 * Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO: None
 */
void FreeBuffer(StringBuffer_t *pBuf) {
	if (!pBuf)
		return;
	if (pBuf->pText)
		free((void *)pBuf->pText);
	free((void *)pBuf);

	return;
}

// decimal.cpp

/*** includes ***/
#ifndef USE_STDLIB_H
#include <malloc.h>
#endif
#include <stdio.h>

/*
 * Routine: set_precision(decimal_t *dest, int size, int precision)
 * Purpose:
 * Algorithm:
 * Data Structures:
 *
 * Params:
 * Returns: None
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO: None
 */
void set_precision(decimal_t *dest, int scale, int precision) {
	dest->scale = scale;
	dest->precision = precision;
	dest->number = 0;
	dest->flags = 0;

	return;
}

/*
 * Routine: mk_decimal(int size, int precision)
 * Purpose: initialize a decimal_t
 * Algorithm:
 * Data Structures:
 *
 * Params:	int size:		total number of places in the decimal
 *			int precision:	number of places in the fraction
 * Returns: decimal_t *
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO: None
 */
decimal_t *mk_decimal(int s, int p) {
	decimal_t *res;

	if ((s < 0) || (p < 0))
		return (NULL);

	res = (decimal_t *)malloc(sizeof(struct DECIMAL_T));
	MALLOC_CHECK(res);

	res->flags = 0;
	res->scale = s;
	res->precision = p;
	res->flags |= FL_INIT;

	return (res);
}

/*
 * Routine: itodec(int src, decimal_t *dest)
 * Purpose: convert an integer to a decimal_t
 * Algorithm:
 * Data Structures:
 *
 * Params: source integer
 * Returns: decimal_t *
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO:
 * 20000104 need to set errno on error
 */
int itodec(decimal_t *dest, int src) {
	int scale = 1, bound = 1;

	while ((bound * 10) <= src) {
		scale += 1;
		bound *= 10;
	}

	dest->precision = 0;
	dest->scale = scale;
	dest->number = src;

	return (0);
}

/*
 * Routine: ftodec(double f, decimal_t *dec)
 * Purpose: Convert a double to a decimal_t
 * Algorithm:
 * Data Structures:
 *
 * Params: double f
 * Returns: decimal_t *
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO: None
 */
int ftodec(decimal_t *dest, double f) {
	static char valbuf[20];

	sprintf(valbuf, "%f", f);

	return (strtodec(dest, valbuf));
}

/*
 * Routine: strtodec()
 * Purpose: Convert an ascii string to a decimal_t structure
 * Algorithm:
 * Data Structures:
 *
 * Params: char *s
 * Returns: decimal_t *
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO: None
 */
int strtodec(decimal_t *dest, char *s) {
	int i;
	char *d_pt;
	char valbuf[20];

	strcpy(valbuf, s);
	dest->flags = 0;
	if ((d_pt = strchr(valbuf, '.')) == NULL) {
		dest->scale = strlen(valbuf);
		dest->number = atoi(valbuf);
		dest->precision = 0;
	} else {
		*d_pt = '\0';
		d_pt += 1;
		dest->scale = strlen(valbuf);
		dest->number = atoi(valbuf);
		dest->precision = strlen(d_pt);
		for (i = 0; i < dest->precision; i++)
			dest->number *= 10;
		dest->number += atoi(d_pt);
	}

	if (*s == '-' && dest->number > 0)
		dest->number *= -1;

	return (0);
}

/*
 * Routine: dectostr(decimal_t *d, char *buf)
 * Purpose: convert a decimal structure to a string
 * Algorithm:
 * Data Structures:
 *
 * Params:
 * Returns: char *; NULL on success
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO: None
 */
int dectostr(char *dest, decimal_t *d) {
	ds_key_t number;
	int i;
	static char szFormat[20];

	if (!InitConstants::dectostr_init) {
		sprintf(szFormat, "%s.%s", HUGE_FORMAT, HUGE_FORMAT);
		InitConstants::dectostr_init = 1;
	}

	if (d == NULL || dest == NULL)
		return (-1);
	for (number = d->number, i = 0; i < d->precision; i++)
		number /= 10;

	sprintf(dest, szFormat, number, d->number - number);

	return (0);
}

/*
 * Routine: dectof(float *dest, decimal_t *d)
 * Purpose: convert a decimal structure to a double
 * Algorithm:
 * Data Structures:
 *
 * Params:
 * Returns: char *; NULL on success
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO: None
 */
int dectoflt(double *dest, decimal_t *d) {
	if ((dest == NULL) || (d == NULL))
		return (-1);
#ifdef WIN32
#pragma warning(disable : 4244)
#endif
	*dest = d->number;
#ifdef WIN32
#pragma warning(default : 4244)
#endif
	while (--d->precision > 0)
		*dest /= 10.0;

	return (0);
}

/*
 * Routine: decimal_t_op(int op, decimal_t *operand1, decimal_t *operand2)
 * Purpose: execute arbitrary binary operations on decimal_t's
 * Algorithm:
 * Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO: None
 */
int decimal_t_op(decimal_t *dest, int op, decimal_t *d1, decimal_t *d2) {
	int res, np;
	float f1, f2;

	if ((d1 == NULL) || (d2 == NULL))
		return (-1);

	dest->scale = (d1->scale > d2->scale) ? d1->scale : d2->scale;
	if (d1->precision > d2->precision) {
		dest->precision = d1->precision;
	} else {
		dest->precision = d2->precision;
	}

	switch (op) {
	case OP_PLUS:
		dest->number = d1->number + d2->number;
		break;
	case OP_MINUS:
		dest->number = d1->number - d2->number;
		break;
	case OP_MULT:
		res = d1->precision + d2->precision;
		dest->number = d1->number * d2->number;
		while (res-- > dest->precision)
			dest->number /= 10;
		break;
	case OP_DIV:
		f1 = (float)d1->number;
		np = d1->precision;
		while (np < dest->precision) {
			f1 *= 10.0;
			np += 1;
		}
		np = 0;
		while (np < dest->precision) {
			f1 *= 10.0;
			np += 1;
		}
		f2 = (float)d2->number;
		np = d2->precision;
		while (np < dest->precision) {
			f2 *= 10.0;
			np += 1;
		}

		dest->number = (int)(f1 / f2);
		break;
	default:
		printf("decimal_t_op does not support op %d\n", op);
		exit(1);
		break;
	}

	return (0);
}

#ifdef TEST
main() {
	decimal_t *res;
	int code;

	/* mk_decimal */
	res = mk_decimal(5, 2);
	if (res == NULL) {
		printf("mk_decimal returned NULL\n");
		exit(-1);
	}

	/* itodec */
	itodec(res, 0);
	code = dectoi(res);
	if (code) {
		printf("r_decimal:itodec(0, res) != 0 (%d)\n", code);
		exit(-1);
	}

	itodec(res, 999);
	code = dectoi(res);
	if (code != 999) {
		printf("r_decimal:itodec(999, res) != 0 (%d)\n", code);
		exit(-1);
	}

	exit(0);
}
#endif /* TEST */

// date.cpp

/*** includes ***/
#include <stdlib.h>
#ifndef USE_STDLIB_H
#include <malloc.h>
#endif
#include <stdio.h>
#include <math.h>

#define D_CHARS      "ymdYMD24" /* valid characters in a DBGDATE setting */
#define MIN_DATE_INT 18000101

static int m_days[2][13] = {{0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334},
                            {0, 0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335}};
static char *qtr_start[5] = {NULL, "01-01", "04-01", "07-01", "10-01"};
char *weekday_names[8] = {NULL, "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
/*
 * Routine: mk_date(void)
 * Purpose: initialize a date_t
 * Algorithm:
 * Data Structures:
 * Params:
 * Returns: date_t *
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO: None
 */
date_t *mk_date(void) {
	date_t *res;

	res = (date_t *)malloc(sizeof(struct DATE_T));
	MALLOC_CHECK(res);

	res->flags = 0;
	res->year = 0;
	res->month = 0;
	res->day = 0;
	res->julian = 0;

	return (res);
}
/*
 * Routine: strtotime(char *str)
 * Purpose: convert a string from the time to the number of seconds since
 * midnight Algorithm: Data Structures: Params: Returns: int Called By: Calls:
 * Assumptions:
 * Side Effects:
 * TODO: None
 */
int strtotime(char *str) {
	int hour, min, sec, res;

	if (sscanf(str, "%d:%d:%d", &hour, &min, &sec) != 3) {
		if (sscanf(str, "%d:%d", &hour, &min) != 2) {
			INTERNAL("Invalid time format");
		}
		sec = 0;
	}

	if (hour > 23 || hour < 0)
		INTERNAL("Invalid time format");
	if (min > 59 || min < 0)
		INTERNAL("Invalid time format");
	if (sec > 59 || sec < 0)
		INTERNAL("Invalid time format");

	res = hour * 3600 + min * 60 + sec;

	return (res);
}

/*
 * Routine: jtodt(int src, date_t *dest)
 * Purpose: convert a number of julian days to a date_t
 * Algorithm: Fleigel and Van Flandern (CACM, vol 11, #10, Oct. 1968, p. 657)
 * Data Structures:
 *
 * Params: source integer: days since big bang
 * Returns: date_t *; NULL on failure
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO:
 */
int jtodt(date_t *dest, int src) {
	long i, j, l, n;

	if (src < 0)
		return (-1);

	dest->julian = src;
	l = src + 68569;
	n = (int)floor((4 * l) / 146097);
	l = l - (int)floor((146097 * n + 3) / 4);
	i = (int)floor((4000 * (l + 1) / 1461001));
	l = l - (int)floor((1461 * i) / 4) + 31;
	j = (int)floor((80 * l) / 2447);
	dest->day = l - (int)floor((2447 * j) / 80);
	l = (int)floor(j / 11);
	dest->month = j + 2 - 12 * l;
	dest->year = 100 * (n - 49) + i + l;

	return (0);
}

/*
 * Routine: dttoj(date_t *)
 * Purpose: convert a date_t to a number of julian days
 * Algorithm: http://quasar.as.utexas.edu/BillInfo/JulianDatesG.html
 * Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO: None
 */
int dttoj(date_t *dt) {
	int y, m, res;

	y = dt->year;
	m = dt->month;
	if (m <= 2) {
		m += 12;
		y -= 1;
	}

	/*
	 * added 1 to get dttoj and jtodt to match
	 */
	res = dt->day + (153 * m - 457) / 5 + 365 * y + (int)floor(y / 4) - (int)floor(y / 100) + (int)floor(y / 400) +
	      1721118 + 1;

	return (res);
}

/*
 * Routine: strtodt()
 * Purpose: Convert an ascii string to a date_t structure
 * Algorithm:
 * Data Structures:
 *
 * Params: char *s, date_t *dest
 * Returns: int; 0 on success
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO: Need to allow for date formats other than Y4MD-
 */
int strtodt(date_t *dest, char *s) {
	int nRetCode = 0;

	if (s == NULL) {
		dest = NULL;
		return (-1);
	}

	if (sscanf(s, "%4d-%d-%d", &dest->year, &dest->month, &dest->day) != 3) {
		fprintf(stderr, "ERROR: Invalid string to date conversion in strtodt\n");
		nRetCode = -1;
	}

	dest->julian = dttoj(dest);

	return (nRetCode);
}

/*
 * Routine: dttostr(date_t *d)
 * Purpose: convert a date_t structure to a string
 * Algorithm:
 * Data Structures:
 *
 * Params:
 * Returns: char *; NULL on failure
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO: 20000110 Need to handle more than Y4MD-
 */
char *dttostr(date_t *d) {
	static char *res;
	static int init = 0;

	if (!init) {
		res = (char *)malloc(sizeof(char) * 11);
		MALLOC_CHECK(res);
		init = 1;
	}

	if (d == NULL)
		return (NULL);

	sprintf(res, "%4d-%02d-%02d", d->year, d->month, d->day);

	return (res);
}

/*
 * Routine: date_init
 * Purpose: set the date handling parameters
 * Algorithm:
 * Data Structures:
 *
 * Params: None
 * Returns: int; 0 on success
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO: None
 */
int date_init(void) {
	printf("date_init is not yet complete\n");
	exit(1);
	return (0);
}

/*
 * Routine: date_t_op(int op, date_t *operand1, date_t *operand2)
 * Purpose: execute arbitrary binary operations on date_t's
 * Algorithm:
 * Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO:
 *	20010806 jms	Return code is meaningless
 */
int date_t_op(date_t *dest, int op, date_t *d1, date_t *d2) {
	int tJulian;
	char tString[11];
	date_t tDate;

	switch (op) {
	case OP_FIRST_DOM: /* set to first day of month */
		tJulian = d1->julian - d1->day + 1;
		jtodt(dest, tJulian);
		break;
	case OP_LAST_DOM: /* set to last day of month */
		tJulian = d1->julian - d1->day + m_days[is_leap(d1->year)][d1->month];
		jtodt(dest, tJulian);
		break;
	case OP_SAME_LY:
		if (is_leap(d1->year) && (d1->month == 2) && (d1->day == 29))
			sprintf(tString, "%d-02-28", d1->year - 1);
		else
			sprintf(tString, "%4d-%02d-%02d", d1->year - 1, d1->month, d1->day);
		strtodt(dest, tString);
		break;
	case OP_SAME_LQ:
		switch (d1->month) {
		case 1:
		case 2:
		case 3:
			sprintf(tString, "%4d-%s", d1->year, qtr_start[1]);
			strtodt(&tDate, tString);
			tJulian = d1->julian - tDate.julian;
			sprintf(tString, "%4d-%s", d1->year - 1, qtr_start[4]);
			strtodt(&tDate, tString);
			tJulian += tDate.julian;
			jtodt(dest, tJulian);
			break;
		case 4:
		case 5:
		case 6:
			sprintf(tString, "%4d-%s", d1->year, qtr_start[2]);
			strtodt(&tDate, tString);
			tJulian = d1->julian - tDate.julian;
			sprintf(tString, "%4d-%s", d1->year, qtr_start[1]);
			strtodt(&tDate, tString);
			tJulian += tDate.julian;
			jtodt(dest, tJulian);
			break;
		case 7:
		case 8:
		case 9:
			sprintf(tString, "%4d-%s", d1->year, qtr_start[3]);
			strtodt(&tDate, tString);
			tJulian = d1->julian - tDate.julian;
			sprintf(tString, "%4d-%s", d1->year, qtr_start[2]);
			strtodt(&tDate, tString);
			tJulian += tDate.julian;
			jtodt(dest, tJulian);
			break;
		case 10:
		case 11:
		case 12:
			sprintf(tString, "%4d-%s", d1->year, qtr_start[4]);
			strtodt(&tDate, tString);
			tJulian = d1->julian - tDate.julian;
			sprintf(tString, "%4d-%s", d1->year, qtr_start[3]);
			strtodt(&tDate, tString);
			tJulian += tDate.julian;
			jtodt(dest, tJulian);
			break;
		}
		break;
	}

	return (0);
}

/*
 * Routine: itodt(date_t *d, int src)
 * Purpose:  convert a number of days to a date_t
 * Algorithm: NOTE: sets only julian field
 * Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO: None
 */
int itodt(date_t *dest, int src) {

	dest->julian = src;

	return (0);
}

/*
 * Routine: set_dow(date *d)
 * Purpose: perpetual calendar stuff
 * Algorithm:
 * Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO:
 */
static int doomsday[4] = {3, 2, 0, 5};
static int known[13] = {0, 3, 0, 0, 4, 9, 6, 11, 8, 5, 10, 7, 12};
int set_dow(date_t *d) {

	static int last_year = -1, dday;
	int res, q, r, s;

	if (d->year != last_year) {
		if (is_leap(d->year)) {
			/* adjust the known dates for january and february */
			known[1] = 4;
			known[2] = 1;
		} else {
			known[1] = 3;
			known[2] = 0;
		}

		/* calculate the doomsday for the century */
		dday = d->year / 100;
		dday -= 15;
		dday %= 4;
		dday = doomsday[dday];

		/* and then calculate the doomsday for the year */
		q = d->year % 100;
		r = q % 12;
		q /= 12;
		s = r / 4;
		dday += q + r + s;
		dday %= 7;
		last_year = d->year;
	}

	res = d->day;
	res -= known[d->month];
	while (res < 0)
		res += 7;
	while (res > 6)
		res -= 7;

	res += dday;
	res %= 7;

	return (res);
}

/*
 * Routine: is_leap(year)
 * Purpose:
 * Algorithm:
 * Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO: None
 */
int is_leap(int year) {

	return (((year % 100) == 0) ? ((((year % 400) % 2) == 0) ? 1 : 0) : ((year % 4) == 0) ? 1 : 0);
}

/*
 * Routine: day_number(date_t *)
 * Purpose:
 * Algorithm: NOTE: this is NOT the ordinal day in the year, but the ordinal
 *reference into the calendar distribution for the day; in particular, this
 *needs to skip over the leap day Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO: None
 */
int day_number(date_t *d) {
	return (m_days[is_leap(d->year)][d->month] + d->day);
}

/*
 * Routine: getDateWeightFromJulian(jDay, nDistribution)
 * Purpose: return the weight associated with a particular julian date and
 * distribution Algorithm: Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO: None
 */
int getDateWeightFromJulian(int jDay, int nDistribution) {
	date_t dTemp;
	int nDay;

	jtodt(&dTemp, jDay);
	nDay = day_number(&dTemp);

	return (dist_weight(NULL, "calendar", nDay, nDistribution + is_leap(dTemp.year)));
}

/*
 * Routine: date_part(date_t *, int part)
 * Purpose:
 * Algorithm:
 * Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO: None
 */
int date_part(date_t *d, int part) {
	switch (part) {
	case 1:
		return (d->year);
	case 2:
		return (d->month);
	case 3:
		return (d->day);
	default:
		INTERNAL("Invalid call to date_part()");
		return (-1);
	}
}

#ifdef TEST
main() {
	date_t *d;
	int ret;

	d = mk_date();
	strtodt(d, "1776-07-04");
	ret = set_dow(d);
	printf("set_dow(\"1776-07-04\"): wanted 4 got %d\n", ret);
	if (ret != 4) {
		exit(1);
	}
	strtodt(d, "2000-01-01");
	ret = set_dow(d);
	printf("set_dow(\"2000-01-01\"): wanted 6 got %d\n", ret);
	if (ret != 6) {
		exit(1);
	}

	strtodt(d, "1970-01-01");
	if ((ret = dttoj(d)) != 2440588) {
		printf("dttoj returned %d\n", ret);
		exit(1);
	}

	d->year = 1;
	d->month = 11;
	d->date = 11;
	jtodt(d, 2440588);
	if ((d->year != 1970) || (d->month != 1) || (d->date != 1)) {
		printf("jtodt failed got: ");
		printf("%4d-%02d-%02d", d->year, d->month, d->date);
		exit(1);
	}
	return (0);
}
#endif /* TEST */

// skip_days.cpp

ds_key_t skipDays(int nTable, ds_key_t *pRemainder) {
	static date_t BaseDate;
	ds_key_t jDate;
	ds_key_t kRowCount, kFirstRow, kDayCount, index = 1;

	if (!InitConstants::skipDays_init) {
		strtodt(&BaseDate, DATA_START_DATE);
		InitConstants::skipDays_init = 1;
		*pRemainder = 0;
	}

	// set initial conditions
	jDate = BaseDate.julian;
	*pRemainder = dateScaling(nTable, jDate) + index;

	// now check to see if we need to move to the
	// the next piece of a parallel build
	// move forward one day at a time
	split_work(nTable, &kFirstRow, &kRowCount);
	while (index < kFirstRow) {
		kDayCount = dateScaling(nTable, jDate);
		index += kDayCount;
		jDate += 1;
		*pRemainder = index;
	}
	if (index > kFirstRow) {
		jDate -= 1;
	}
	return (jDate);
}

// release.cpp
#include <stdio.h>

/*
 * Routine: release(char *param_name, char *msg)
 * Purpose: display version information
 * Algorithm:
 * Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO: None
 */
int printReleaseInfo(const char *param_name, const char *msg) {
	fprintf(stderr, "%s Population Generator (Version %d.%d.%d%s)\n", get_str("PROG"), VERSION, RELEASE, MODIFICATION,
	        PATCH);
	fprintf(stderr, "Copyright %s %s\n", COPYRIGHT, C_DATES);

	exit(0);
}

// list.cpp
#include <stdio.h>
#include <assert.h>

list_t *makeList(int nFlags, int (*SortFunc)(const void *d1, const void *d2)) {
	list_t *pRes;

	pRes = (list_t *)malloc(sizeof(list_t));
	MALLOC_CHECK(pRes);
	if (pRes == NULL)
		ReportError(QERR_NO_MEMORY, "client list", 1);
	memset(pRes, 0, sizeof(list_t));
	pRes->nFlags = nFlags;
	pRes->pSortFunc = SortFunc;

	return (pRes);
}

list_t *addList(list_t *pList, void *pData) {
	node_t *pNode;
	node_t *pInsertPoint;
	int bMoveForward = (pList->nFlags & L_FL_HEAD);

	pNode = (node_t *)malloc(sizeof(node_t));
	MALLOC_CHECK(pNode);
	if (!pNode)
		ReportErrorNoLine(QERR_NO_MEMORY, "client node", 1);
	memset(pNode, 0, sizeof(node_t));
	pNode->pData = pData;

	if (pList->nMembers == 0) /* first node */
	{
		pList->head = pNode;
		pList->tail = pNode;
		pList->nMembers = 1;
		return (pList);
	}

	if (pList->nFlags & L_FL_SORT) {
		if (pList->pSortFunc(pData, pList->head->pData) <= 0) {
			/* new node become list head */
			pNode->pNext = pList->head;
			pList->head->pPrev = pNode;
			pList->head = pNode;
			pList->nMembers += 1;
			return (pList);
		}
		pInsertPoint = pList->head;

		/* find the correct point to insert new node */
		while (pInsertPoint) {
			if (pList->pSortFunc(pInsertPoint->pData, pData) < 0)
				break;
			pInsertPoint = (bMoveForward) ? pInsertPoint->pNext : pInsertPoint->pPrev;
		}
		if (pInsertPoint) /* mid-list insert */
		{
			pNode->pNext = pInsertPoint->pNext;
			pNode->pPrev = pInsertPoint;
			pInsertPoint->pNext = pNode;
		} else {
			if (bMoveForward) {
				/* new node becomes list tail */
				pNode->pPrev = pList->tail;
				pList->tail->pNext = pNode;
				pList->tail = pNode;
			} else {
				/* new node become list head */
				pNode->pNext = pList->head;
				pList->head->pPrev = pNode;
				pList->head = pNode;
			}
		}

		pList->nMembers += 1;

		return (pList);
	}

	if (pList->nFlags & L_FL_HEAD) {
		pNode->pNext = pList->head;
		pList->head->pPrev = pNode;
		pList->head = pNode;
		pList->nMembers += 1;
	} else {
		pNode->pPrev = pList->tail;
		pList->tail->pNext = pNode;
		pList->tail = pNode;
		pList->nMembers += 1;
	}

	return (pList);
}

/*
 * Routine:
 * Purpose:
 * Algorithm:
 * Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO: None
 */
void *removeItem(list_t *pList, int bHead) {
	void *pResult;

	if (pList->nMembers == 0)
		return (NULL);

	if (!bHead) {
		pResult = pList->tail->pData;
		pList->tail = pList->tail->pPrev;
		pList->tail->pNext = NULL;
	} else {
		pResult = pList->head->pData;
		pList->head = pList->head->pNext;
		pList->head->pPrev = NULL;
	}

	pList->nMembers -= 1;

	return (pResult);
}

/*
 * Routine:
 * Purpose:
 * Algorithm:
 * Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO: None
 */
void *getHead(list_t *pList) {
	assert(pList);

	if (!pList->head)
		return (NULL);

	pList->pCurrent = pList->head;

	return (pList->pCurrent->pData);
}

/*
 * Routine:
 * Purpose:
 * Algorithm:
 * Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO: None
 */
void *getTail(list_t *pList) {
	assert(pList);

	if (!pList->tail)
		return (NULL);

	pList->pCurrent = pList->tail;

	return (pList->pCurrent->pData);
}

/*
 * Routine:
 * Purpose:
 * Algorithm:
 * Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO: None
 */
void *getNext(list_t *pList) {
	assert(pList);

	if (!pList->pCurrent->pNext)
		return (NULL);

	pList->pCurrent = pList->pCurrent->pNext;

	return (pList->pCurrent->pData);
}

/*
 * Routine:
 * Purpose: findList(list_t *pList, void *pData)
 * Algorithm:
 * Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO: None
 */
void *findList(list_t *pList, void *pData) {
	void *pNode;
	struct LIST_NODE_T *pOldCurrent = pList->pCurrent;

	for (pNode = getHead(pList); pNode; pNode = getNext(pList))
		if (pList->pSortFunc(pNode, pData) == 0) {
			pList->pCurrent = pOldCurrent;
			return (pNode);
		}

	pList->pCurrent = pOldCurrent;
	return (NULL);
}

/*
 * Routine:
 * Purpose:
 * Algorithm:
 * Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO: None
 */
void *getItem(list_t *pList, int nIndex) {
	void *pResult;
	struct LIST_NODE_T *pOldCurrent = pList->pCurrent;

	if (nIndex > length(pList))
		return (NULL);

	for (pResult = getHead(pList); --nIndex; pResult = getNext(pList))
		;

	pList->pCurrent = pOldCurrent;
	return (pResult);
}

// error_msg.cpp
#include <stdio.h>
static int *LN;
static char *FN;

err_msg_t Errors[MAX_ERROR + 2] = {{
                                       EFLG_NO_ARG,
                                       "",
                                   },
                                   {EFLG_STR_ARG, "File '%s' not found"},
                                   {EFLG_NO_ARG, "Line exceeds maximum leng.h"},
                                   {EFLG_STR_ARG, "Memory allocation failed %s"},
                                   {EFLG_STR_ARG, "Syntax Error: \n'%s'"},
                                   {EFLG_NO_ARG, "Invalid/Out-of-range Argument"},
                                   {EFLG_STR_ARG, "'%s' is not a unique name"},
                                   {EFLG_STR_ARG, "'%s' is not a valid name"},
                                   {EFLG_NO_ARG, "Command parse failed"},
                                   {EFLG_NO_ARG, "Invalid tag found"},
                                   {EFLG_STR_ARG, "Read failed on '%s'"},
                                   {EFLG_NO_ARG, "Too Many Templates!"},
                                   {EFLG_NO_ARG, "Each workload definition must be in its own file"},
                                   {EFLG_NO_ARG, "Query Class name must be unique within a workload definition"},
                                   {EFLG_NO_ARG, "Query Template must be unique within a query class"},
                                   {EFLG_STR_ARG | EFLG_SYSTEM, "Open failed on '%s'"},
                                   {EFLG_STR_ARG, "%s  not yet implemented"}, /* QERR_NOT_IMPLEMENTED */
                                   {EFLG_STR_ARG, "string trucated to '%s'"},
                                   {EFLG_NO_ARG, "Non-terminated string"},
                                   {EFLG_STR_ARG, "failed to write to '%s'"},
                                   {EFLG_NO_ARG, "No type vector defined for distribution"},
                                   {EFLG_NO_ARG, "No weight count defined for distribution"},
                                   {EFLG_NO_ARG, "No limits defined for pricing calculations"},
                                   {EFLG_STR_ARG, "Percentage is out of bounds in substitution '%s'"},
                                   {EFLG_STR_ARG, "Name is not a distribution or table name: '%s'"},
                                   {EFLG_NO_ARG, "Cannot evaluate expression"},
                                   {EFLG_STR_ARG, "Substitution'%s' is used before being initialized"}, /* QERR_NO_INIT
                                                                                                         */
                                   {EFLG_NO_ARG, "RANGE()/LIST()/ULIST() not supported for NORMAL "
                                                 "distributions"},
                                   {EFLG_STR_ARG, "Bad Nesting; '%s' not found"},
                                   {EFLG_STR_ARG, "Include stack overflow when opening '%s'"},
                                   {EFLG_STR_ARG, "Bad function call: '%s'"},
                                   {EFLG_STR_ARG, "Bad Hierarchy Call: '%s'"},
                                   {EFLG_NO_ARG, "Must set types and weights before defining names"},
                                   {EFLG_NO_ARG, "More than 20 arguments in definition"},
                                   {EFLG_NO_ARG, "Argument type mismat.h"},
                                   {EFLG_NO_ARG, "RANGE()/LIST()/ULIST() cannot be used in the "
                                                 "same expression"}, /* QERR_RANGE_LIST
                                                                      */
                                   {EFLG_NO_ARG, "Selected scale factor is NOT valid for result publication"},
                                   {EFLG_STR_ARG, "Parameter setting failed for '%s'"},
                                   {EFLG_STR_ARG, "Table %s is being joined without an explicit rule"},
                                   {EFLG_STR_ARG, "Table %s is not yet fully defined"},
                                   {EFLG_STR_ARG, "Table %s is a child; it is populated during the build of "
                                                  "its parent (e.g., catalog_sales builds catalog returns)"},
                                   {EFLG_NO_ARG, "Command line arguments for dbgen_version exceed 200 "
                                                 "characters; truncated"},
                                   {EFLG_NO_ARG, "A query template list must be supplied using the "
                                                 "INPUT option"},                               /* QERR_NO_QUERYLIST
                                                                                                 */
                                   {EFLG_NO_ARG, "Invalid query number found in permutation!"}, /* QERR_QUERY_RANGE
                                                                                                 */
                                   {EFLG_NO_ARG, "RANGE/LIST/ULIST expressions not valid as "
                                                 "function parameters"}, /* QERR_MODIFIED_PARAM
                                                                          */
                                   {EFLG_NO_ARG, "RANGE/LIST/ULIST truncated to available "
                                                 "values"}, /* QERR_MODIFIED_PARAM
                                                             */
                                   {EFLG_NO_ARG, "This scale factor is valid for QUALIFICATION "
                                                 "ONLY"}, /* QERR_QUALIFICATION_SCALE
                                                           */
                                   {EFLG_STR_ARG, "Generating %s requires the '-update' option"}, /* QERR_TABLE_UPDATE
                                                                                                   */
                                   {0, NULL}};

/*
 * Routine:
 * Purpose:
 * Algorithm:
 * Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO: None
 */
void ProcessErrorCode(int nErrorCode, char *szRoutineName, char *szParam, int nParam) {
	switch (nErrorCode) {
	case QERR_NO_FILE:
		ReportError(QERR_NO_FILE, szParam, 1);
		break;
	case QERR_SYNTAX:
	case QERR_RANGE_ERROR:
	case QERR_NON_UNIQUE:
	case QERR_BAD_NAME:
	case QERR_DEFINE_OVERFLOW:
	case QERR_INVALID_TAG:
	case QERR_READ_FAILED:
	case QERR_NO_MEMORY:
	case QERR_LINE_TOO_LONG:
		ReportError(nErrorCode, szRoutineName, 1);
		break;
	}
	return;
}

/*
 * Routine:
 * Purpose:
 * Algorithm:
 * Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO: None
 */
int ReportError(int nError, const char *msg, int bExit) {
	fprintf(stderr, "ERROR?!\n");
	return (nError);
}

/*
 * Routine:
 * Purpose:
 * Algorithm:
 * Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO: None
 */
int ReportErrorNoLine(int nError, const char *msg, int bExit) {
	char e_msg[1024];

	if (nError < MAX_ERROR) {
		switch (Errors[-nError].flags & EFLG_ARG_MASK) {
		case EFLG_NO_ARG:
			fprintf(stderr, "%s: %s\n", (bExit) ? "ERROR" : "Warning", Errors[-nError].prompt);
			break;
		case EFLG_STR_ARG:
			sprintf(e_msg, Errors[-nError].prompt, msg);
			fprintf(stderr, "%s: %s\n", (bExit) ? "ERROR" : "Warning", e_msg);
			break;
		}

		if (Errors[-nError].flags & EFLG_SYSTEM)
			perror(msg);
	}

	if (bExit)
		exit(nError);
	else
		return (nError);
}

/*
 * Routine:
 * Purpose:
 * Algorithm:
 * Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO: None
 */
void SetErrorGlobals(char *szFileName, int *nLineNumber) {
	FN = szFileName;
	LN = nLineNumber;

	return;
}

// append_info-c.cpp


#include <cstring>
#include <memory>


append_info *append_info_get(void *info_list, int table_id) {
	auto &append_vector = *((std::vector<std::unique_ptr<tpcds_append_information>> *)info_list);
	return (append_info *)append_vector[table_id].get();
}

void append_row_start(append_info info) {
	auto append_info = (tpcds_append_information *)info;
	append_info->appender.BeginRow();
}

void append_row_end(append_info info) {
	auto append_info = (tpcds_append_information *)info;
	append_info->appender.EndRow();
}

void append_varchar(append_info info, const char *value) {
	auto append_info = (tpcds_append_information *)info;
	if (!nullCheck(append_info->appender.CurrentColumn())) {
		append_info->appender.Append<duckdb::string_t>(duckdb::string_t(value));
	} else {
		append_info->appender.Append(nullptr);
	}
}

// TODO: use direct array manipulation for speed, but not now
static void append_value(append_info info, duckdb::Value v) {
	auto append_info = (tpcds_append_information *)info;
	append_info->appender.Append<duckdb::Value>(v);
}

void append_key(append_info info, int64_t value) {
	auto append_info = (tpcds_append_information *)info;
	append_info->appender.Append<int64_t>(value);
}

void append_integer(append_info info, int32_t value) {
	auto append_info = (tpcds_append_information *)info;
	append_info->appender.Append<int32_t>(value);
}

void append_boolean(append_info info, int32_t value) {
	auto append_info = (tpcds_append_information *)info;
	append_info->appender.Append<bool>(value != 0);
}

// value is a Julian date
// FIXME: direct int conversion, offsets should be constant
void append_date(append_info info, int64_t value) {
	date_t dTemp;
	jtodt(&dTemp, (int)value);
	auto ddate = duckdb::Date::FromDate(dTemp.year, dTemp.month, dTemp.day);
	auto append_info = (tpcds_append_information *)info;
	append_info->appender.Append<duckdb::date_t>(ddate);
}

void append_decimal(append_info info, decimal_t *val) {
	auto append_info = (tpcds_append_information *)info;
	auto &appender = append_info->appender;
	auto &type = appender.GetTypes()[appender.CurrentColumn()];
	D_ASSERT(type.id() == duckdb::LogicalTypeId::DECIMAL);
	D_ASSERT(duckdb::DecimalType::GetScale(type) == val->precision);
	appender.Append<int64_t>(val->number);
}

// text.cpp
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/*
 * Routine: mk_sentence()
 * Purpose: create a sample sentence
 * Algorithm:
 * Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO: None
 */
static int used_space = 0; /* current length of the sentence being built */
#define SPACE_INCREMENT 100

static char *mk_sentence(int stream) {
	static char *verbiage = NULL;
	static int allocated_space = 0;
	int word_len;
	char *syntax, *cp, *word = NULL, temp[2];

	temp[1] = '\0';
	pick_distribution(&syntax, "sentences", 1, 1, stream);

	for (cp = syntax; *cp; cp++) {
		switch (*cp) {
		case 'N': /* pick a noun */
			pick_distribution(&word, "nouns", 1, 1, stream);
			break;
		case 'V': /* pick a verb */
			pick_distribution(&word, "verbs", 1, 1, stream);
			break;
		case 'J': /* pick a adjective */
			pick_distribution(&word, "adjectives", 1, 1, stream);
			break;
		case 'D': /* pick a adverb */
			pick_distribution(&word, "adverbs", 1, 1, stream);
			break;
		case 'X': /* pick a auxiliary verb */
			pick_distribution(&word, "auxiliaries", 1, 1, stream);
			break;
		case 'P': /* pick a preposition */
			pick_distribution(&word, "prepositions", 1, 1, stream);
			break;
		case 'A': /* pick an article */
			pick_distribution(&word, "articles", 1, 1, stream);
			break;
		case 'T': /* pick an terminator */
			pick_distribution(&word, "terminators", 1, 1, stream);
			break;
		default:
			temp[0] = *cp;
			break;
		}

		if (word == NULL)
			word_len = 1;
		else
			word_len = strlen(word);

		if (used_space + word_len >= allocated_space) {
			verbiage = (char *)realloc(verbiage, allocated_space + SPACE_INCREMENT);
			MALLOC_CHECK(verbiage);
			allocated_space += SPACE_INCREMENT;
		}

		if (word == NULL)
			strcpy(&verbiage[used_space], temp);
		else
			strcpy(&verbiage[used_space], word);
		used_space += word_len;
		word = NULL;
	}

	return (verbiage);
}

/*
 * Routine: gen_text()
 * Purpose: entry point for this module. Generate a truncated sentence in a
 *			given length range
 * Algorithm:
 * Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO: None
 */
char *gen_text(char *dest, int min, int max, int stream) {
	int target_len, generated_length, capitalize = 1;
	char *s;

	used_space = 0;
	genrand_integer(&target_len, DIST_UNIFORM, min, max, 0, stream);
	if (dest)
		*dest = '\0';
	else {
		dest = (char *)malloc((max + 1) * sizeof(char));
		MALLOC_CHECK(dest);
	}

	while (target_len > 0) {
		used_space = 0;
		s = mk_sentence(stream);
		if (capitalize)
			*s = toupper(*s);
		generated_length = strlen(s);
		capitalize = (s[generated_length - 1] == '.');
		if (target_len <= generated_length)
			s[target_len] = '\0';
		strcat(dest, s);
		target_len -= generated_length;
		if (target_len > 0) {
			strcat(dest, " ");
			target_len -= 1;
		}
	}

	return (dest);
}

#ifdef TEST
#define DECLARER

typedef struct {
	char *name;
} tdef;
/* tdef tdefs[] = {NULL}; */

option_t options[] = {

    {"DISTRIBUTIONS", OPT_STR, 0, NULL, NULL, "tester_dist.idx"}, NULL};

char *params[2];

main() {
	char test_dest[201];
	int i;

	init_params();

	for (i = 0; i < 100; i++) {
		gen_text(test_dest, 100, 200, 1);
		printf("%s\n", test_dest);
		test_dest[0] = '\0';
	}

	return (0);
}
#endif

// permute.cpp
#ifndef USE_STDLIB_H
#include <malloc.h>
#endif
#include <stdio.h>

/*
 * Routine: MakePermutation(int nSize)
 * Purpose: Permute the integers in [1..nSize]
 * Algorithm:
 * Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO: None
 */
int *makePermutation(int *nNumberSet, int nSize, int nStream) {
	int i, nTemp, nIndex, *pInt;

	if (nSize <= 0)
		return (NULL);

	if (!nNumberSet) {
		nNumberSet = (int *)malloc(nSize * sizeof(int));
		MALLOC_CHECK(nNumberSet);
		pInt = nNumberSet;
		for (i = 0; i < nSize; i++)
			*pInt++ = i;
	}

	for (i = 0; i < nSize; i++) {
		nIndex = genrand_integer(NULL, DIST_UNIFORM, 0, nSize - 1, 0, nStream);
		nTemp = nNumberSet[i];
		nNumberSet[i] = nNumberSet[nIndex];
		nNumberSet[nIndex] = nTemp;
	}

	return (nNumberSet);
}

/*
 * Routine: MakePermutation(int nSize)
 * Purpose: Permute the integers in [1..nSize]
 * Algorithm:
 * Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO: None
 */
ds_key_t *makeKeyPermutation(ds_key_t *nNumberSet, ds_key_t nSize, int nStream) {
	ds_key_t i, nTemp, nIndex, *pInt;
	if (nSize <= 0)
		return (NULL);

	if (!nNumberSet) {
		nNumberSet = (ds_key_t *)malloc(nSize * sizeof(ds_key_t));
		MALLOC_CHECK(nNumberSet);
		pInt = nNumberSet;
		for (i = 0; i < nSize; i++)
			*pInt++ = i;
	}

	for (i = 0; i < nSize; i++) {
		nIndex = genrand_key(NULL, DIST_UNIFORM, 0, nSize - 1, 0, nStream);
		nTemp = nNumberSet[i];
		nNumberSet[i] = nNumberSet[nIndex];
		nNumberSet[nIndex] = nTemp;
	}

	return (nNumberSet);
}

// dist.cpp


#include <assert.h>
#include <fcntl.h>
#include <stdio.h>

#ifdef WIN32
#include <io.h>
#include <search.h>
#include <stdlib.h>
#else
#include <netinet/in.h>
#include <sys/stat.h>
#include <sys/types.h>
#endif
#ifdef NCR
#include <sys/types.h>
#endif
#ifndef USE_STDLIB_H
#include <malloc.h>
#endif
#ifdef TEST
option_t options[] = {{"DISTRIBUTIONS", OPT_STR, 2, "read distributions from file <s>", NULL, "tester_dist.idx"}, NULL};

char params[2];
struct {
	char *name;
} tdefs[] = {NULL};
#endif

/* NOTE: these need to be in sync with a_dist.h */
#define D_NAME_LEN 20
#define FL_LOADED  0x01
static int load_dist(d_idx_t *d);

/*
 * Routine: di_compare()
 * Purpose: comparison routine for two d_idx_t entries; used by qsort
 * Algorithm:
 * Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO: None
 */
int di_compare(const void *op1, const void *op2) {
	d_idx_t *ie1 = (d_idx_t *)op1, *ie2 = (d_idx_t *)op2;

	return (strcasecmp(ie1->name, ie2->name));
}

/*
 * Routine: find_dist(char *name)
 * Purpose: translate from dist_t name to d_idx_t *
 * Algorithm:
 * Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO: None
 */
d_idx_t *find_dist(const char *name) {
	static int entry_count;
	static d_idx_t *idx = NULL;
	d_idx_t key, *id = NULL;
	int i;
	FILE *ifp;
	int32_t temp;

	/* load the index if this is the first time through */
	if (!InitConstants::find_dist_init) {
		/* make sure that this is read one thread at a time */
		if (!InitConstants::find_dist_init) /* make sure no one beat us to it */
		{

			/* open the dist file */
			auto read_ptr = tpcds_idx;
			//			if ((ifp = fopen(get_str("DISTRIBUTIONS"), "rb")) == NULL) {
			//				fprintf(stderr, "Error: open of distributions failed: ");
			//				perror(get_str("DISTRIBUTIONS"));
			//				exit(1);
			//			}
			memcpy(&temp, read_ptr, sizeof(int32_t));
			read_ptr += sizeof(int32_t);
			//			if (fread(&temp, 1, sizeof(int32_t), ifp) != sizeof(int32_t)) {
			//				fprintf(stderr, "Error: read of index count failed: ");
			//				perror(get_str("DISTRIBUTIONS"));
			//				exit(2);
			//			}
			entry_count = ntohl(temp);
			read_ptr = tpcds_idx + tpcds_idx_len - (entry_count * IDX_SIZE);
			//			if ((temp = fseek(ifp, -entry_count * IDX_SIZE, SEEK_END)) < 0) {
			//				fprintf(stderr, "Error: lseek to index failed: ");
			//				fprintf(stderr, "attempting to reach %d\nSystem error: ", (int)(-entry_count * IDX_SIZE));
			//				perror(get_str("DISTRIBUTIONS"));
			//				exit(3);
			//			}
			idx = (d_idx_t *)malloc(entry_count * sizeof(d_idx_t));
			MALLOC_CHECK(idx);
			for (i = 0; i < entry_count; i++) {
				memset(idx + i, 0, sizeof(d_idx_t));
				//				if (fread(idx[i].name, 1, D_NAME_LEN, ifp) < D_NAME_LEN) {
				//					fprintf(stderr, "Error: read index failed (1): ");
				//					perror(get_str("DISTRIBUTIONS"));
				//					exit(2);
				//				}
				memcpy(idx[i].name, read_ptr, D_NAME_LEN);
				read_ptr += D_NAME_LEN;
				idx[i].name[D_NAME_LEN] = '\0';
				memcpy(&temp, read_ptr, sizeof(int32_t));
				read_ptr += sizeof(int32_t);
				//				if (fread(&temp, 1, sizeof(int32_t), ifp) != sizeof(int32_t)) {
				//					fprintf(stderr, "Error: read index failed (2): ");
				//					perror(get_str("DISTRIBUTIONS"));
				//					exit(2);
				//				}
				idx[i].index = ntohl(temp);
				memcpy(&temp, read_ptr, sizeof(int32_t));
				read_ptr += sizeof(int32_t);
				//				if (fread(&temp, 1, sizeof(int32_t), ifp) != sizeof(int32_t)) {
				//					fprintf(stderr, "Error: read index failed (4): ");
				//					perror(get_str("DISTRIBUTIONS"));
				//					exit(2);
				//				}
				idx[i].offset = ntohl(temp);
				memcpy(&temp, read_ptr, sizeof(int32_t));
				read_ptr += sizeof(int32_t);
				//				if (fread(&temp, 1, sizeof(int32_t), ifp) != sizeof(int32_t)) {
				//					fprintf(stderr, "Error: read index failed (5): ");
				//					perror(get_str("DISTRIBUTIONS"));
				//					exit(2);
				//				}
				idx[i].str_space = ntohl(temp);
				memcpy(&temp, read_ptr, sizeof(int32_t));
				read_ptr += sizeof(int32_t);
				//				if (fread(&temp, 1, sizeof(int32_t), ifp) != sizeof(int32_t)) {
				//					fprintf(stderr, "Error: read index failed (6): ");
				//					perror(get_str("DISTRIBUTIONS"));
				//					exit(2);
				//				}
				idx[i].length = ntohl(temp);
				memcpy(&temp, read_ptr, sizeof(int32_t));
				read_ptr += sizeof(int32_t);
				//				if (fread(&temp, 1, sizeof(int32_t), ifp) != sizeof(int32_t)) {
				//					fprintf(stderr, "Error: read index failed (7): ");
				//					perror(get_str("DISTRIBUTIONS"));
				//					exit(2);
				//				}
				idx[i].w_width = ntohl(temp);
				memcpy(&temp, read_ptr, sizeof(int32_t));
				read_ptr += sizeof(int32_t);
				//				if (fread(&temp, 1, sizeof(int32_t), ifp) != sizeof(int32_t)) {
				//					fprintf(stderr, "Error: read index failed (8): ");
				//					perror(get_str("DISTRIBUTIONS"));
				//					exit(2);
				//				}
				idx[i].v_width = ntohl(temp);
				memcpy(&temp, read_ptr, sizeof(int32_t));
				read_ptr += sizeof(int32_t);
				//				if (fread(&temp, 1, sizeof(int32_t), ifp) != sizeof(int32_t)) {
				//					fprintf(stderr, "Error: read index failed (9): ");
				//					perror(get_str("DISTRIBUTIONS"));
				//					exit(2);
				//				}
				idx[i].name_space = ntohl(temp);
				idx[i].dist = NULL;
			}
			qsort((void *)idx, entry_count, sizeof(d_idx_t), di_compare);
			InitConstants::find_dist_init = 1;

			/* make sure that this is read one thread at a time */
			//			fclose(ifp);
		}
	}

	/* find the distribution, if it exists and move to it */
	strcpy(key.name, name);
	id = (d_idx_t *)bsearch((void *)&key, (void *)idx, entry_count, sizeof(d_idx_t), di_compare);
	if (id != NULL)                 /* found a valid distribution */
		if (id->flags != FL_LOADED) /* but it needs to be loaded */
			load_dist(id);

	return (id);
}

/*
 * Routine: load_dist(int fd, dist_t *d)
 * Purpose: load a particular distribution
 * Algorithm:
 * Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO: None
 */
static int load_dist(d_idx_t *di) {
	int res = 0, i, j;
	dist_t *d;
	int32_t temp;
	FILE *ifp;

	if (di->flags != FL_LOADED) /* make sure no one beat us to it */
	{
		auto read_ptr = tpcds_idx;
		//		if ((ifp = fopen(get_str("DISTRIBUTIONS"), "rb")) == NULL) {
		//			fprintf(stderr, "Error: open of distributions failed: ");
		//			perror(get_str("DISTRIBUTIONS"));
		//			exit(1);
		//		}
		read_ptr += di->offset;
		//		if ((temp = fseek(ifp, di->offset, SEEK_SET)) < 0) {
		//			fprintf(stderr, "Error: lseek to distribution failed: ");
		//			perror("load_dist()");
		//			exit(2);
		//		}

		di->dist = (dist_t *)malloc(sizeof(struct DIST_T));
		MALLOC_CHECK(di->dist);
		d = di->dist;

		// fprintf(stderr, "\ndist %s ", di->name);

		/* load the type information */
		d->type_vector = (int *)malloc(sizeof(int32_t) * di->v_width);
		MALLOC_CHECK(d->type_vector);
		for (i = 0; i < di->v_width; i++) {
			memcpy(&temp, read_ptr, sizeof(int32_t));
			read_ptr += sizeof(int32_t);
			//			if (fread(&temp, 1, sizeof(int32_t), ifp) != sizeof(int32_t)) {
			//				fprintf(stderr, "Error: read of type vector failed for '%s': ", di->name);
			//				perror("load_dist()");
			//				exit(3);
			//			}
			d->type_vector[i] = ntohl(temp);
			// fprintf(stderr, "type %d, ", d->type_vector[i]);
		}

		/* load the weights */
		d->weight_sets = (int **)malloc(sizeof(int *) * di->w_width);
		d->maximums = (int *)malloc(sizeof(int32_t) * di->w_width);
		MALLOC_CHECK(d->weight_sets);
		MALLOC_CHECK(d->maximums);
		for (i = 0; i < di->w_width; i++) {
			*(d->weight_sets + i) = (int *)malloc(di->length * sizeof(int32_t));
			MALLOC_CHECK(*(d->weight_sets + i));
			d->maximums[i] = 0;
			for (j = 0; j < di->length; j++) {
				memcpy(&temp, read_ptr, sizeof(int32_t));
				read_ptr += sizeof(int32_t);
				//				if (fread(&temp, 1, sizeof(int32_t), ifp) < 0) {
				//					fprintf(stderr, "Error: read of weights failed: ");
				//					perror("load_dist()");
				//					exit(3);
				//				}
				*(*(d->weight_sets + i) + j) = ntohl(temp);
				/* calculate the maximum weight and convert sets to cummulative
				 */
				d->maximums[i] += d->weight_sets[i][j];
				d->weight_sets[i][j] = d->maximums[i];
			}
		}

		/* load the value offsets */
		d->value_sets = (int **)malloc(sizeof(int *) * di->v_width);
		MALLOC_CHECK(d->value_sets);
		for (i = 0; i < di->v_width; i++) {
			*(d->value_sets + i) = (int *)malloc(di->length * sizeof(int32_t));
			MALLOC_CHECK(*(d->value_sets + i));
			for (j = 0; j < di->length; j++) {
				memcpy(&temp, read_ptr, sizeof(int32_t));
				read_ptr += sizeof(int32_t);
				//				if (fread(&temp, 1, sizeof(int32_t), ifp) != sizeof(int32_t)) {
				//					fprintf(stderr, "Error: read of values failed: ");
				//					perror("load_dist()");
				//					exit(4);
				//				}
				*(*(d->value_sets + i) + j) = ntohl(temp);
			}
		}

		/* load the column aliases, if they were defined */
		if (di->name_space) {
			d->names = (char *)malloc(di->name_space);
			MALLOC_CHECK(d->names);
			memcpy(d->names, read_ptr, di->name_space * sizeof(char));
			read_ptr += di->name_space * sizeof(char);
			//			if (fread(d->names, 1, di->name_space * sizeof(char), ifp) < 0) {
			//				fprintf(stderr, "Error: read of names failed: ");
			//				perror("load_dist()");
			//				exit(599);
			//			}
		}

		/* and finally the values themselves */
		d->strings = (char *)malloc(sizeof(char) * di->str_space);
		MALLOC_CHECK(d->strings);
		memcpy(d->strings, read_ptr, di->str_space * sizeof(char));
		read_ptr += di->str_space * sizeof(char);
		//		if (fread(d->strings, 1, di->str_space * sizeof(char), ifp) < 0) {
		//			fprintf(stderr, "Error: read of strings failed: ");
		//			perror("load_dist()");
		//			exit(5);
		//		}

		//		fclose(ifp);

		//
		//	fprintf(stderr, "%s {\n", di->name);
		//
		//	// type_vector
		//	fprintf(stderr, "{");
		//
		//	for (int i = 0 ; i < di->v_width; i++) {
		//		fprintf(stderr, "%d", d->type_vector[i]);
		//
		//		if (i < di->v_width-1) {
		//			fprintf(stderr, ", ");
		//
		//		}
		//	}
		//	fprintf(stderr, "},");
		//
		//// weight_sets
		//	fprintf(stderr, "{");
		//		for (int i = 0 ; i < di->w_width; i++) {
		//			fprintf(stderr, "{");
		//
		//					for (int j = 0 ; j < di->length; j++) {
		//
		//						fprintf(stderr, "%d", d->weight_sets[i][j]);
		//
		//
		//
		//						if (j < di->length-1) {
		//							fprintf(stderr, ", ");
		//
		//						}
		//					}
		//					fprintf(stderr, "},");
		//
		//
		//
		//			if (i < di->w_width-1) {
		//				fprintf(stderr, ", ");
		//
		//			}
		//		}
		//		fprintf(stderr, "},");
		//
		//
		//	// maximums
		//			fprintf(stderr, "{");
		//
		//		for (int i = 0 ; i < di->w_width; i++) {
		//			fprintf(stderr, "%d", d->maximums[i]);
		//
		//			if (i < di->w_width-1) {
		//				fprintf(stderr, ", ");
		//
		//			}
		//		}
		//		fprintf(stderr, "},");
		//
		//
		//
		//		// value sets
		//		fprintf(stderr, "{");
		//			for (int i = 0 ; i < di->v_width; i++) {
		//				fprintf(stderr, "{");
		//
		//						for (int j = 0 ; j < di->length; j++) {
		//
		//							fprintf(stderr, "%d", d->value_sets[i][j]);
		//
		//
		//
		//							if (j < di->length-1) {
		//								fprintf(stderr, ", ");
		//
		//							}
		//						}
		//						fprintf(stderr, "},");
		//
		//
		//
		//				if (i < di->v_width-1) {
		//					fprintf(stderr, ", ");
		//
		//				}
		//			}
		//			fprintf(stderr, "},");
		//
		//
		//// strings
		//
		//
		//			fprintf(stderr, "{");
		//
		//				for (int i = 0 ; i < di->str_space; i++) {
		//					fprintf(stderr, "%d", (int) d->strings[i]);
		//
		//					if (i < di->str_space-1) {
		//						fprintf(stderr, ", ");
		//
		//					}
		//				}
		//				fprintf(stderr, "},");
		//
		//
		//
		//			// names
		//
		//			fprintf(stderr, "{");
		//
		//				for (int i = 0 ; i < di->name_space; i++) {
		//					fprintf(stderr, "%d", (int) d->names[i]);
		//
		//					if (i < di->name_space-1) {
		//						fprintf(stderr, ", ");
		//
		//					}
		//				}
		//				fprintf(stderr, "},");
		//
		//
		//
		//			// size
		//	fprintf(stderr, "%d}\n", d->size);

		di->flags = FL_LOADED;
	}

	return (res);
}

/*
 * Routine: void *dist_op()
 * Purpose: select a value/weight from a distribution
 * Algorithm:
 * Data Structures:
 *
 * Params:	char *d_name
 *			int vset: which set of values
 *			int wset: which set of weights
 * Returns: appropriate data type cast as a void *
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO: 20000317 Need to be sure this is portable to NT and others
 */
int dist_op(void *dest, int op, const char *d_name, int vset, int wset, int stream) {
	d_idx_t *d;
	dist_t *dist;
	int level, index = 0, dt;
	char *char_val;
	int i_res = 1;

	if ((d = find_dist(d_name)) == NULL) {
		char msg[80];
		sprintf(msg, "Invalid distribution name '%s'", d_name);
		INTERNAL(msg);
		assert(d != NULL);
	}

	dist = d->dist;

	if (op == 0) {
		genrand_integer(&level, DIST_UNIFORM, 1, dist->maximums[wset - 1], 0, stream);
		while (level > dist->weight_sets[wset - 1][index] && index < d->length)
			index += 1;
		dt = vset - 1;
		if ((index >= d->length) || (dt > d->v_width))
			INTERNAL("Distribution overrun");
		char_val = dist->strings + dist->value_sets[dt][index];
	} else {
		index = vset - 1;
		dt = wset - 1;
		if (index >= d->length || index < 0) {
			fprintf(stderr, "Runtime ERROR: Distribution over-run/under-run\n");
			fprintf(stderr, "Check distribution definitions and usage for %s.\n", d->name);
			fprintf(stderr, "index = %d, length=%d.\n", index, d->length);
			exit(1);
		}
		char_val = dist->strings + dist->value_sets[dt][index];
	}

	switch (dist->type_vector[dt]) {
	case TKN_VARCHAR:
		if (dest)
			*(char **)dest = (char *)char_val;
		break;
	case TKN_INT:
		i_res = atoi(char_val);
		if (dest)
			*(int *)dest = i_res;
		break;
	case TKN_DATE:
		if (dest == NULL) {
			dest = (date_t *)malloc(sizeof(date_t));
			MALLOC_CHECK(dest);
		}
		strtodt(*(date_t **)dest, char_val);
		break;
	case TKN_DECIMAL:
		if (dest == NULL) {
			dest = (decimal_t *)malloc(sizeof(decimal_t));
			MALLOC_CHECK(dest);
		}
		strtodec(*(decimal_t **)dest, char_val);
		break;
	}

	return ((dest == NULL) ? i_res : index + 1); /* shift back to the 1-based indexing scheme */
}

/*
 * Routine: int dist_weight
 * Purpose: return the weight of a particular member of a distribution
 * Algorithm:
 * Data Structures:
 *
 * Params:	distribution *d
 *			int index: which "row"
 *			int wset: which set of weights
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO:
 *	20000405 need to add error checking
 */
int dist_weight(int *dest, const char *d, int index, int wset) {
	d_idx_t *d_idx;
	dist_t *dist;
	int res;

	if ((d_idx = find_dist(d)) == NULL) {
		char msg[80];
		sprintf(msg, "Invalid distribution name '%s'", d);
		INTERNAL(msg);
	}

	dist = d_idx->dist;
	assert(index > 0);
	assert(wset > 0);
	res = dist->weight_sets[wset - 1][index - 1];
	/* reverse the accumulation of weights */
	if (index > 1)
		res -= dist->weight_sets[wset - 1][index - 2];

	if (dest == NULL)
		return (res);

	*dest = res;

	return (0);
}

/*
 * Routine: int DistNameIndex()
 * Purpose: return the index of a column alias
 * Algorithm:
 * Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO:
 */
int DistNameIndex(const char *szDist, int nNameType, const char *szName) {
	d_idx_t *d_idx;
	dist_t *dist;
	int res;
	char *cp = NULL;

	if ((d_idx = find_dist(szDist)) == NULL)
		return (-1);
	dist = d_idx->dist;

	if (dist->names == NULL)
		return (-1);

	res = 0;
	cp = dist->names;
	do {
		if (strcasecmp(szName, cp) == 0)
			break;
		cp += strlen(cp) + 1;
		res += 1;
	} while (res < (d_idx->v_width + d_idx->w_width));

	if (res >= 0) {
		if ((nNameType == VALUE_NAME) && (res < d_idx->v_width))
			return (res + 1);
		if ((nNameType == WEIGHT_NAME) && (res > d_idx->v_width))
			return (res - d_idx->v_width + 1);
	}

	return (-1);
}

/*
 * Routine: int distsize(char *name)
 * Purpose: return the size of a distribution
 * Algorithm:
 * Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO:
 *	20000405 need to add error checking
 */
int distsize(const char *name) {
	d_idx_t *dist;

	dist = find_dist(name);

	if (dist == NULL)
		return (-1);

	return (dist->length);
}

/*
 * Routine: int IntegrateDist(char *szDistName, int nPct, int nStartIndex, int
 *nWeightSet) Purpose: return the index of the entry which, starting from
 *nStartIndex, would create a range comprising nPct of the total contained in
 *nWeightSet NOTE: the value can "wrap" -- that is, the returned value can be
 *less than nStartIndex Algorithm: Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO:
 */

int IntegrateDist(const char *szDistName, int nPct, int nStartIndex, int nWeightSet) {
	d_idx_t *pDistIndex;
	int nGoal, nSize;

	if ((nPct <= 0) || (nPct >= 100))
		return (QERR_RANGE_ERROR);

	pDistIndex = find_dist(szDistName);
	if (pDistIndex == NULL)
		return (QERR_BAD_NAME);

	if (nStartIndex > pDistIndex->length)
		return (QERR_RANGE_ERROR);

	nGoal = pDistIndex->dist->maximums[nWeightSet];
	nGoal = nGoal * nPct / 100;
	nSize = distsize(szDistName);

	while (nGoal >= 0) {
		nStartIndex++;
		nGoal -= dist_weight(NULL, szDistName, nStartIndex % nSize, nWeightSet);
	}

	return (nStartIndex);
}

/*
 * Routine: int dist_type(char *name, int nValueSet)
 * Purpose: return the type of the n-th value set in a distribution
 * Algorithm:
 * Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO:
 */
int dist_type(const char *name, int nValueSet) {
	d_idx_t *dist;

	dist = find_dist(name);

	if (dist == NULL)
		return (-1);

	if (nValueSet < 1 || nValueSet > dist->v_width)
		return (-1);

	return (dist->dist->type_vector[nValueSet - 1]);
}

/*
 * Routine:
 * Purpose:
 * Algorithm:
 * Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO: None
 */
void dump_dist(const char *name) {
	d_idx_t *pIndex;
	int i, j;
	char *pCharVal = NULL;
	int nVal;

	pIndex = find_dist(name);
	if (pIndex == NULL)
		ReportErrorNoLine(QERR_BAD_NAME, name, 1);
	printf("create %s;\n", pIndex->name);
	printf("set types = (");
	for (i = 0; i < pIndex->v_width; i++) {
		if (i > 0)
			printf(", ");
		printf("%s", dist_type(name, i + 1) == 7 ? "int" : "varchar");
	}
	printf(");\n");
	printf("set weights = %d;\n", pIndex->w_width);
	for (i = 0; i < pIndex->length; i++) {
		printf("add(");
		for (j = 0; j < pIndex->v_width; j++) {
			if (j)
				printf(", ");
			if (dist_type(name, j + 1) != 7) {
				dist_member(&pCharVal, name, i + 1, j + 1);
				printf("\"%s\"", pCharVal);
			} else {
				dist_member(&nVal, name, i + 1, j + 1);
				printf("%d", nVal);
			}
		}
		printf("; ");
		for (j = 0; j < pIndex->w_width; j++) {
			if (j)
				printf(", ");
			printf("%d", dist_weight(NULL, name, i + 1, j + 1));
		}
		printf(");\n");
	}

	return;
}

/*
 * Routine: dist_active(char *szName, int nWeightSet)
 * Purpose: return number of entries with non-zero weght values
 * Algorithm:
 * Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO: None
 */
int dist_active(const char *szName, int nWeightSet) {
	int nSize, nResult = 0, i;

	nSize = distsize(szName);
	for (i = 1; i <= nSize; i++) {
		if (dist_weight(NULL, szName, i, nWeightSet) != 0)
			nResult += 1;
	}

	return (nResult);
}

/*
 * Routine: DistSizeToShiftWidth(char *szDist)
 * Purpose: Determine the number of bits required to select a member of the
 * distribution Algorithm: Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO: None
 */
int DistSizeToShiftWidth(const char *szDist, int nWeightSet) {
	int nBits = 1, nTotal = 2, nMax;
	d_idx_t *d;

	d = find_dist(szDist);
	nMax = dist_max(d->dist, nWeightSet);

	while (nTotal < nMax) {
		nBits += 1;
		nTotal <<= 1;
	}

	return (nBits);
}

/*
 * Routine:
 * Purpose:
 * Algorithm:
 * Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO: None
 */
int MatchDistWeight(void *dest, const char *szDist, int nWeight, int nWeightSet, int ValueSet) {
	d_idx_t *d;
	dist_t *dist;
	int index = 0, dt, i_res, nRetcode;
	char *char_val;

	if ((d = find_dist(szDist)) == NULL) {
		char msg[80];
		sprintf(msg, "Invalid distribution name '%s'", szDist);
		INTERNAL(msg);
	}

	dist = d->dist;
	nWeight %= dist->maximums[nWeightSet - 1];

	while (nWeight > dist->weight_sets[nWeightSet - 1][index] && index < d->length)
		index += 1;
	dt = ValueSet - 1;
	if (index >= d->length)
		index = d->length - 1;
	char_val = dist->strings + dist->value_sets[dt][index];

	switch (dist->type_vector[dt]) {
	case TKN_VARCHAR:
		if (dest)
			*(char **)dest = (char *)char_val;
		break;
	case TKN_INT:
		i_res = atoi(char_val);
		if (dest)
			*(int *)dest = i_res;
		break;
	case TKN_DATE:
		if (dest == NULL) {
			dest = (date_t *)malloc(sizeof(date_t));
			MALLOC_CHECK(dest);
		}
		strtodt(*(date_t **)dest, char_val);
		break;
	case TKN_DECIMAL:
		if (dest == NULL) {
			dest = (decimal_t *)malloc(sizeof(decimal_t));
			MALLOC_CHECK(dest);
		}
		strtodec(*(decimal_t **)dest, char_val);
		break;
	}

	nRetcode = 1;
	index = 1;
	while (index < dist->maximums[nWeightSet - 1]) {
		nRetcode += 1;
		index *= 2;
	}

	return (nRetcode);
}

/*
 * Routine: findDistValue(char *szValue, char *szDistName, int nValueSet)
 * Purpose: Return the row number where the entry is found
 * Algorithm:
 * Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO:
 * 20031024 jms this routine needs to handle all data types, not just varchar
 */
int findDistValue(const char *szValue, const char *szDistName, int ValueSet) {
	int nRetValue = 1, nDistMax;
	char szDistValue[128];

	nDistMax = distsize(szDistName);

	for (nRetValue = 1; nRetValue < nDistMax; nRetValue++) {
		dist_member(&szDistValue, szDistName, nRetValue, ValueSet);
		if (strcmp(szValue, szDistValue) == 0)
			break;
	}

	if (nRetValue <= nDistMax)
		return (nRetValue);
	return (-1);
}

#ifdef TEST
main() {
	int i_res;
	char *c_res;
	decimal_t dec_res;

	init_params();

	dist_member(&i_res, "test_dist", 1, 1);
	if (i_res != 10) {
		printf("dist_member(\"test_dist\", 1, 1): %d != 10\n", i_res);
		exit(1);
	}
	dist_member(&i_res, "test_dist", 1, 2);
	if (i_res != 60) {
		printf("dist_member(\"test_dist\", 1, 2): %d != 60\n", i_res);
		exit(1);
	}
	dist_member((void *)&c_res, "test_dist", 1, 3);
	if (strcmp(c_res, "El Camino")) {
		printf("dist_member(\"test_dist\", 1, 3): %s != El Camino\n", c_res);
		exit(1);
	}
	dist_member((void *)&dec_res, "test_dist", 1, 4);
	if (strcmp(dec_res.number, "1") || strcmp(dec_res.fraction, "23")) {
		printf("dist_member(\"test_dist\", 1, 4): %s.%s != 1.23\n", dec_res.number, dec_res.fraction);
		exit(1);
	}
	dist_weight(&i_res, "test_dist", 2, 2);
	if (3 != i_res) {
		printf("dist_weight(\"test_dist\", 2, 2): %d != 3\n", i_res);
		exit(1);
	}
}
#endif /* TEST */

// r_params.cpp
/*
 * parameter handling functions
 */
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <cassert>

#define PARAM_MAX_LEN 80

#ifndef TEST
extern option_t options[];
extern char *params[];
#else
option_t options[] = {{"PROG", OPT_STR | OPT_HIDE, 0, NULL, NULL, "tester"},
                      {"PARAMS", OPT_STR, 1, "read parameters from file <s>", read_file, ""},
                      {"DISTRIBUTIONS", OPT_STR, 2, "read distributions from file <s>", NULL, "tester_dist.idx"},
                      {"OUTDIR", OPT_STR, 3, "generate files in directory <s>", NULL, "./"},
                      {"VERBOSE", OPT_FLG, 4, "enable verbose output", NULL, "N"},
                      {"HELP", OPT_FLG, 5, "display this message", usage, "N"},
                      {"scale", OPT_INT, 6, "set scale to <i>", NULL, "1"},
                      NULL};
char *params[9];
#endif

#define MAX_LINE_LEN 120
#ifdef WIN32
#define OPTION_START '/'
#else
#define OPTION_START '-'
#endif

int read_file(const char *param_name, const char *option);
int fnd_param(const char *name);
void print_params(void);

/*
 * Routine:  load_params()
 * Purpose:
 * Algorithm:
 * Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO:
 * 20010621 JMS shared memory not yet implemented
 */
void load_params() {
	/*
	    int i=0;
	    while (options[i].name != NULL)
	    {
	        load_param(i, GetSharedMemoryParam(options[i].index));
	        i++;
	    }
	    SetSharedMemoryStat(STAT_ROWCOUNT, get_int("STEP"), 0);
	*/
	return;
}

/*
 * Routine:  set_flag(int f)
 * Purpose:  set a toggle parameter
 * Algorithm:
 * Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO: None
 */
void set_flg(const char *flag) {
	int nParam;

	init_params();
	nParam = fnd_param(flag);
	if (nParam >= 0)
		strcpy(params[options[nParam].index], "Y");

	return;
}

/*
 * Routine: clr_flg(f)
 * Purpose: clear a toggle parameter
 * Algorithm:
 * Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO: None
 */
void clr_flg(const char *flag) {
	int nParam;

	init_params();
	nParam = fnd_param(flag);
	if (nParam >= 0)
		strcpy(params[options[nParam].index], "N");
	return;
}

/*
 * Routine: is_set(int f)
 * Purpose: return the state of a toggle parameter, or whether or not a string
 * or int parameter has been set Algorithm: Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO: None
 */
int is_set(const char *flag) {
	int nParam, bIsSet = 0;

	init_params();
	nParam = fnd_param(flag);
	if (nParam >= 0) {
		if ((options[nParam].flags & TYPE_MASK) == OPT_FLG)
			bIsSet = (params[options[nParam].index][0] == 'Y') ? 1 : 0;
		else
			bIsSet = (options[nParam].flags & OPT_SET) || (strlen(options[nParam].dflt) > 0);
	}

	return (bIsSet); /* better a false negative than a false positive ? */
}

/*
 * Routine: set_int(int var, char *value)
 * Purpose: set an integer parameter
 * Algorithm:
 * Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO: None
 */
void set_int(const char *var, const char *val) {
	int nParam;

	init_params();
	nParam = fnd_param(var);
	if (nParam >= 0) {
		strcpy(params[options[nParam].index], val);
		options[nParam].flags |= OPT_SET;
	}
	return;
}

/*
 * Routine: get_int(char *var)
 * Purpose: return the value of an integer parameter
 * Algorithm:
 * Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO: None
 */
int get_int(const char *var) {
	int nParam;

	init_params();
	nParam = fnd_param(var);
	if (nParam >= 0)
		return (atoi(params[options[nParam].index]));
	else
		return (0);
}

double get_dbl(const char *var) {
	int nParam;

	init_params();
	nParam = fnd_param(var);
	if (nParam >= 0)
		return (atof(params[options[nParam].index]));
	else
		return (0);
}

/*
 * Routine: set_str(int var, char *value)
 * Purpose: set a character parameter
 * Algorithm:
 * Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO: None
 */
void set_str(const char *var, const char *val) {
	int nParam;

	init_params();
	nParam = fnd_param(var);
	if (nParam >= 0) {
		strcpy(params[options[nParam].index], val);
		options[nParam].flags |= OPT_SET;
	}

	return;
}

/*
 * Routine: get_str(char * var)
 * Purpose: return the value of a character parameter
 * Algorithm:
 * Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO: None
 */
char *get_str(const char *var) {
	int nParam;

	init_params();
	nParam = fnd_param(var);
	if (nParam >= 0)
		return (params[options[nParam].index]);
	else
		return (NULL);
}

/*
 * Routine: init_params(void)
 * Purpose: initialize a parameter set, setting default values
 * Algorithm:
 * Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO: None
 */
int init_params(void) {
	int i;

	if (InitConstants::init_params_init)
		return (0);

	for (i = 0; options[i].name != NULL; i++) {
		params[options[i].index] = (char *)malloc(PARAM_MAX_LEN * sizeof(char));
		MALLOC_CHECK(params[options[i].index]);
		strncpy(params[options[i].index], options[i].dflt, 80);
		if (*options[i].dflt)
			options[i].flags |= OPT_DFLT;
	}

	InitConstants::init_params_init = 1;

	return (0);
}

/*
 * Routine: print_options(struct OPTION_T *o, int file, int depth)
 * Purpose: print a summary of options
 * Algorithm:
 * Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO: None
 */
static void print_options(struct OPTION_T *o, int bShowOptional) {
	int i, w_adjust, bShow = 0, nCount = 0;

	for (i = 0; options[i].name != NULL; i++) {
		/*
		 * options come in two groups, general and "hidden". Decide which group
		 * to show in this pass, and ignore others
		 */
		bShow = 0;
		if (bShowOptional && (o[i].flags & OPT_ADV))
			bShow = 1;
		if (!bShowOptional && !(o[i].flags & OPT_ADV))
			bShow = 1;

		if (!bShow || (o[i].flags & OPT_HIDE))
			continue;

		nCount += 1;
		printf("%s = ", o[i].name);
		w_adjust = 15 - strlen(o[i].name);
		if (o[i].flags & OPT_INT)
			printf(" <n>   ");
		else if (o[i].flags & OPT_STR)
			printf(" <s>   ");
		else if (o[i].flags & OPT_SUB)
			printf(" <opt> ");
		else if (o[i].flags & OPT_FLG)
			printf(" [Y|N] ");
		else
			printf("       ");
		printf("%*s-- %s", w_adjust, " ", o[i].usage);
		if (o[i].flags & OPT_NOP)
			printf(" NOT IMPLEMENTED");
		printf("\n");
	}

	if (nCount == 0)
		printf("None defined.\n");

	return;
}
/*
 * Routine: save_file(char *path)
 * Purpose: print a summary of options
 * Algorithm:
 * Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO: None
 */
int save_file(const char *path) {
	int i, w_adjust;
	FILE *ofp;
	time_t timestamp;

	init_params();
	time(&timestamp);

	if ((ofp = fopen(path, "w")) == NULL)
		return (-1);

	fprintf(ofp, "--\n-- %s Benchmark Parameter File\n-- Created: %s", get_str("PROG"), ctime(&timestamp));
	fprintf(ofp, "--\n-- Each entry is of the form: '<parameter> = <value> -- "
	             "optional comment'\n");
	fprintf(ofp, "-- Refer to benchmark documentation for more details\n--\n");

	for (i = 0; options[i].name != NULL; i++) {
		if (options[i].flags & OPT_HIDE) /* hidden option */
			continue;
		if (strlen(params[options[i].index]) == 0)
			continue;

		fprintf(ofp, "%s = ", options[i].name);
		w_adjust = strlen(options[i].name) + 3;
		if (options[i].flags & OPT_STR) {
			fprintf(ofp, "\"%s\"", params[options[i].index]);
			w_adjust += 2;
		} else
			fprintf(ofp, "%s", params[options[i].index]);
		w_adjust += strlen(params[options[i].index]) + 3;
		w_adjust = 60 - w_adjust;
		fprintf(ofp, "%*s-- %s", w_adjust, " ", options[i].usage);
		if (options[i].flags & OPT_NOP)
			fprintf(ofp, " NOT IMPLEMENTED");
		fprintf(ofp, "\n");
	}

	fclose(ofp);

	return (0);
}

/*
 * Routine: usage(char *param_name, char *msg)
 * Purpose: display a usage message, with an optional error message
 * Algorithm:
 * Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO: None
 */
int usage(const char *param_name, const char *msg) {
	init_params();

	fprintf(stderr, "%s Population Generator (Version %d.%d.%d%s)\n", get_str("PROG"), VERSION, RELEASE, MODIFICATION,
	        PATCH);
	fprintf(stderr, "Copyright %s %s\n", COPYRIGHT, C_DATES);

	if (msg != NULL)
		printf("\nERROR: %s\n\n", msg);

	printf("\n\nUSAGE: %s [options]\n", get_str("PROG"));
	printf("\nNote: When defined in a parameter file (using -p), parmeters "
	       "should\n");
	printf("use the form below. Each option can also be set from the command\n");
	printf("line, using a form of '%cparam [optional argument]'\n", OPTION_START);
	printf("Unique anchored substrings of options are also recognized, and \n");
	printf("case is ignored, so '%csc' is equivalent to '%cSCALE'\n\n", OPTION_START, OPTION_START);
	printf("General Options\n===============\n");
	print_options(options, 0);
	printf("\n");
	printf("Advanced Options\n===============\n");
	print_options(options, 1);
	printf("\n");
	exit((msg == NULL) ? 0 : 1);
}

/*
 * Routine: set_option(int var, char *value)
 * Purpose: set a particular parameter; main entry point for the module
 * Algorithm:
 * Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO: None
 */
int set_option(const char *name, const char *param) {
	printf("ERROR: set_option not supported");
	assert(0);
	exit(1);
	//	int res = 1;
	//	option_t *o;
	//	char parse_int[15];
	//	char *cp;
	//
	//	init_params();
	//
	//	res = fnd_param(name);
	//	if (res == -1)
	//		return (res);
	//
	//	o = &options[res];
	//
	//	if (o->flags & OPT_NOP) {
	//		printf("ERROR: Cannot accept %s.\tNot Implemented!\n", o->name);
	//		return (0);
	//	}
	//
	//	/* option is already set from the command line or hard-coded */
	//	/* and doesn't allow multiple settings */
	//
	//	switch (o->flags & TYPE_MASK) {
	//	case OPT_FLG:
	//		if ((param && (*param == 'Y' || *param == 'Y' || *param == OPTION_START)) || (param == NULL)) {
	//			if (o->action)
	//				if (o->action((char *)o->name, NULL) < 0)
	//					usage((char *)o->name, "Cannot process option");
	//			set_flg(name);
	//		} else
	//			clr_flg(name);
	//		res = 1;
	//		break;
	//	case OPT_INT:
	//		if (o->action) {
	//			if ((res = o->action((char *)o->name, param)) < 0)
	//				usage(NULL, "Bad parameter argument");
	//			else
	//				sprintf(parse_int, "%d", res);
	//		}
	//		set_int(name, (o->action) ? parse_int : param);
	//		res = 2;
	//		break;
	//	case OPT_STR:
	//		if (*param == '"') {
	//			cp = strchr((param + 1), '"');
	//			if (cp == NULL) /* non-terminated string literal */
	//				usage(NULL, "Non-terminated string");
	//			*cp = '\0';
	//			param += 1;
	//		} else {
	//			cp = strpbrk(param, " \t\n");
	//			if (cp != NULL)
	//				*cp = '\0';
	//		}
	//		if (o->action && strlen(param))
	//			if (o->action((char *)o->name, param) < 0)
	//				usage((char *)o->name, "Cannot process option");
	//		set_str(name, param);
	//		res = 2;
	//		break;
	//	default:
	//		fprintf(stderr, "Invalid option/type (%d/%s)\n", o->flags & TYPE_MASK, o->name);
	//		exit(0);
	//		break;
	//	}
	//
	//	o->flags |= OPT_SET; /* marked as set */
	//
	//	return (res);
}

/*
 * Routine: process_options(int count, char **vector)
 * Purpose:  process a set of command line options
 * Algorithm:
 * Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO: 20000309 need to return integer to allow processing of left-over args
 */
int process_options(int count, const char **vector) {
	int option_num = 1, res = 1;

	init_params();

	while (option_num < count) {
		if (*vector[option_num] == OPTION_START) {
			if (option_num == (count - 1))
				res = set_option(vector[option_num] + 1, NULL);
			else
				res = set_option(vector[option_num] + 1, vector[option_num + 1]);
		}

		if (res < 0) {
			printf("ERROR: option '%s' or its argument unknown.\n", (vector[option_num] + 1));
			usage(NULL, NULL);
			exit(1);
		} else
			option_num += res;
	}

#ifdef JMS
	if (is_set("VERBOSE"))
		print_params();
#endif

	return (option_num);
}

/*
 * Routine: read_file(char *param_name, char *fname)
 * Purpose: process a parameter file
 * Algorithm:
 * Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO: None
 */
int read_file(const char *param_name, const char *optarg) {
	FILE *fp;
	char *cp;
	char line[MAX_LINE_LEN];
	char name[100];
	int index;

	init_params();

	if ((fp = fopen(optarg, "r")) == NULL)
		return (-1);
	while (fgets(line, MAX_LINE_LEN, fp) != NULL) {
		if ((cp = strchr(line, '\n')) != NULL)
			*cp = '\0';
		if ((cp = strchr(line, '-')) != NULL)
			if (*(cp + 1) == '-')
				*cp = '\0';
		if ((cp = strtok(line, " \t=\n")) != NULL) {
			strcpy(name, cp);
			index = fnd_param(name);
			if (index == -1)
				continue; /* JMS: errors are silently ignored */
			cp += strlen(cp) + 1;
			while (*cp && strchr(" \t =", *cp))
				cp++;

			/* command line options over-ride those in a file */
			if (options[index].flags & OPT_SET)
				continue;

			if (*cp) {
				switch (options[index].flags & TYPE_MASK) {
				case OPT_INT:
					if ((cp = strtok(cp, " \t\n")) != NULL)
						set_option(name, cp);
					break;
				case OPT_STR:
				case OPT_FLG:
					set_option(name, cp);
					break;
				}
			}
		}
	}

	fclose(fp);

	return (0);
}

/*
 * Routine: print_params(void)
 * Purpose: print a parameter summary to display current settings
 * Algorithm:
 * Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO: None
 */
void print_params(void) {
	int i;

	init_params();

	for (i = 0; options[i].name != NULL; i++)
		if (options[i].name != NULL) {
			printf("%s = ", options[i].name);
			switch (options[i].flags & TYPE_MASK) {
			case OPT_INT:
				printf("%d\n", get_int((char *)options[i].name));
				break;
			case OPT_STR:
				printf("%s\n", get_str((char *)options[i].name));
				break;
			case OPT_FLG:
				printf("%c\n", is_set((char *)options[i].name) ? 'Y' : 'N');
				break;
			}
		}

	return;
}

/*
 * Routine: fnd_param(char *name, int *type, char *value)
 * Purpose: traverse the defined parameters, looking for a match
 * Algorithm:
 * Data Structures:
 *
 * Params:
 * Returns: index of option
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO: None
 */
int fnd_param(const char *name) {
	int i, res = -1;

	for (i = 0; options[i].name != NULL; i++) {
		if (strncasecmp(name, options[i].name, strlen(name)) == 0) {
			if (res == -1)
				res = i;
			else
				return (-1);
		}
	}

	return (res);
}

/*
 * Routine:  GetParamName(int nParam)
 * Purpose:  Translate between a parameter index and its name
 * Algorithm:
 * Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO: None
 */
char *GetParamName(int nParam) {
	init_params();

	return (char *)(options[nParam].name);
}

/*
 * Routine:  GetParamValue(int nParam)
 * Purpose:  Retrieve a parameters string value based on an index
 * Algorithm:
 * Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO: None
 */
char *GetParamValue(int nParam) {
	init_params();

	return (params[options[nParam].index]);
}

/*
 * Routine:  load_param(char *szValue, int nParam)
 * Purpose:  Set a parameter based on an index
 * Algorithm:
 * Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO: None
 */
int load_param(int nParam, const char *szValue) {
	init_params();

	if (options[nParam].flags & OPT_SET) /* already set from the command line */
		return (0);
	else
		strcpy(params[options[nParam].index], szValue);

	return (0);
}

/*
 * Routine:  IsIntParam(char *szValue, int nParam)
 * Purpose:  Boolean test for integer parameter
 * Algorithm:
 * Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO: None
 */
int IsIntParam(const char *szParam) {
	int nParam;

	if ((nParam = fnd_param(szParam)) == -1)
		return (nParam);

	return ((options[nParam].flags & OPT_INT) ? 1 : 0);
}

/*
 * Routine:  IsStrParam(char *szValue, int nParam)
 * Purpose:  Boolean test for string parameter
 * Algorithm:
 * Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO: None
 */
int IsStrParam(const char *szParam) {
	int nParam;

	if ((nParam = fnd_param(szParam)) == -1)
		return (nParam);

	return ((options[nParam].flags & OPT_STR) ? 1 : 0);
}

#ifdef TEST

main() {
	init_params();
	set_int("SCALE", "7");
	set_flg("VERBOSE");
	set_str("DISTRIBUTIONS", "'some file name'");
	print_params();
	set_int("s", "8");
	clr_flg("VERBOSE");
	printf("DIST is %s\n", get_str("DISTRIBUTIONS"));
	print_params();
	usage(NULL, NULL);
}
#endif /* TEST_PARAMS */

// misc.cpp

#include <stdio.h>
#include <time.h>
#include <errno.h>
#include <ctype.h>
#include <math.h>
#ifndef USE_STDLIB_H
#include <malloc.h>
#endif
#include <fcntl.h>
#ifdef AIX
#include <sys/mode.h>
#endif /* AIX */
#include <sys/types.h>
#include <sys/stat.h>

static char alpha_num[65] = "0123456789abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ,";

char *getenv(const char *name);
int print_separator(int sep);

extern long Seed[];

#ifdef WIN32
#define PATH_SEP '\\'
#else
#define PATH_SEP '/'
#endif

int file_num = -1;

/*
 *
 * Various routines that handle distributions, value selections and
 * seed value management for the DSS benchmark. Current functions:
 * env_config -- set config vars with optional environment override
 * a_rnd(min, max) -- random alphanumeric within length range
 */

/*
 * env_config: look for a environmental variable setting and return its
 * value; otherwise return the default supplied
 */
char *env_config(char *var, char *dflt) {
	static char *evar;

	if ((evar = getenv(var)) != NULL)
		return (evar);
	else
		return (dflt);
}

/*
 * generate a random string with length randomly selected in [min, max]
 * and using the characters in alphanum (currently includes a space
 * and comma)
 */
int a_rnd(int min, int max, int column, char *dest) {
	int i, len, char_int;

	genrand_integer(&len, DIST_UNIFORM, min, max, 0, column);
	for (i = 0; i < len; i++) {
		if (i % 5 == 0)
			genrand_integer(&char_int, DIST_UNIFORM, 0, 1 << 30, 0, column);
		*(dest + i) = alpha_num[char_int & 077];
		char_int >>= 6;
	}
	*(dest + len) = '\0';
	return (len);
}

// parallel.cpp
#include <stdio.h>

/*
 * Routine: split_work(int tnum, worker_t *w)
 * Purpose: allocate work between processes and threads
 * Algorithm:
 * Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO: None
 */
int split_work(int tnum, ds_key_t *pkFirstRow, ds_key_t *pkRowCount) {
	ds_key_t kTotalRows, kRowsetSize, kExtraRows;
	int nParallel, nChild;

	kTotalRows = get_rowcount(tnum);
	nParallel = get_int("PARALLEL");
	nChild = get_int("CHILD");

	/*
	 * 1. small tables aren't paralelized
	 * 2. nothing is parallelized unless a command line arg is supplied
	 */
	*pkFirstRow = 1;
	*pkRowCount = kTotalRows;

	if (kTotalRows < 1000000) {
		if (nChild > 1) /* small table; only build it once */
		{
			*pkFirstRow = 1;
			*pkRowCount = 0;
			return (0);
		}
		return (1);
	}

	if (!is_set("PARALLEL")) {
		return (1);
	}

	/*
	 * at this point, do the calculation to set the rowcount for this part of a
	 * parallel build
	 */
	kExtraRows = kTotalRows % nParallel;
	kRowsetSize = (kTotalRows - kExtraRows) / nParallel;

	/* start the starting row id */
	*pkFirstRow += (nChild - 1) * kRowsetSize;
	if (kExtraRows && (nChild - 1))
		*pkFirstRow += ((nChild - 1) < kExtraRows) ? (nChild - 1) : kExtraRows;

	/* set the rowcount for this child */
	*pkRowCount = kRowsetSize;
	if (kExtraRows && (nChild <= kExtraRows))
		*pkRowCount += 1;

	return (1);
}

/*
 * Routine:
 * Purpose:
 * Algorithm:
 * Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO: None
 */
int checkSeeds(tdef *pTdef) {
	int i, res, nReturnCode = 0;
	static int bSetSeeds = 0;

	if (!InitConstants::checkSeeds_init) {
		bSetSeeds = is_set("CHKSEEDS");
		InitConstants::checkSeeds_init = 1;
	}

	for (i = pTdef->nFirstColumn; i <= pTdef->nLastColumn; i++) {
		while (Streams[i].nUsed < Streams[i].nUsedPerRow)
			genrand_integer(&res, DIST_UNIFORM, 1, 100, 0, i);
		if (bSetSeeds) {
			if (Streams[i].nUsed > Streams[i].nUsedPerRow) {
				fprintf(stderr, "Seed overrun on column %d. Used: %d\n", i, Streams[i].nUsed);
				Streams[i].nUsedPerRow = Streams[i].nUsed;
				nReturnCode = 1;
			}
		}
		Streams[i].nUsed = 0; /* reset for the next time */
	}

	return (nReturnCode);
}

/*
 * Routine:
 * Purpose:
 * Algorithm:
 * Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO: None
 */
int row_stop(int tbl) {
	tdef *pTdef;

	pTdef = getSimpleTdefsByNumber(tbl);
	checkSeeds(pTdef);
	if (pTdef->flags & FL_PARENT) {
		pTdef = getSimpleTdefsByNumber(pTdef->nParam);
		checkSeeds(pTdef);
		if (pTdef->flags & FL_PARENT) {
			pTdef = getSimpleTdefsByNumber(pTdef->nParam);
			checkSeeds(pTdef);
		}
	}

	return (0);
}

/*
 * Routine: row_skip
 * Purpose: skip over un-used rows in a table
 * Algorithm:
 * Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO: 20020816 jms The second parameter should really be a ds_key_t to allow
 * BIG skips
 */
int row_skip(int tbl, ds_key_t count) {
	int i;

	for (i = 0; Streams[i].nColumn != -1; i++) {
		if (Streams[i].nTable == tbl) {
			skip_random(i, count * Streams[i].nUsedPerRow);
			Streams[i].nUsed = 0;
			Streams[i].nTotal = count * Streams[i].nUsedPerRow;
		}
		if (Streams[i].nDuplicateOf && (Streams[i].nDuplicateOf != i)) {
			skip_random(Streams[i].nDuplicateOf, count * Streams[Streams[i].nDuplicateOf].nUsedPerRow);
			Streams[Streams[i].nDuplicateOf].nUsed = 0;
			Streams[Streams[i].nDuplicateOf].nTotal = count * Streams[i].nUsedPerRow;
		}
	}

	return (0);
}

// scaling.cpp
#include <stdio.h>
#include <assert.h>
#include <stdio.h>

static struct SCALING_T {
	ds_key_t kBaseRowcount;
	ds_key_t kNextInsertValue;
	int nUpdatePercentage;
	ds_key_t kDayRowcount[6];
} arRowcount[MAX_TABLE + 1];
static int arUpdateDates[6];
static int arInventoryUpdateDates[6];

static int arScaleVolume[9] = {1, 10, 100, 300, 1000, 3000, 10000, 30000, 100000};

void setUpdateScaling(int table);
int row_skip(int tbl, ds_key_t count);

/*
 * Routine:
 * Purpose:
 * Algorithm:
 * Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO: None
 */
int getScaleSlot(int nTargetGB) {
	int i;

	for (i = 0; nTargetGB > arScaleVolume[i]; i++)
		;

	return (i);
}

/*
 * Routine: LogScale(void)
 * Purpose: use the command line volume target, in GB, to calculate the global
 * rowcount multiplier Algorithm: Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects: arRowcounts are set to the appropriate number of rows for the
 * target scale factor
 * TODO: None
 */
static ds_key_t LogScale(int nTable, int nTargetGB) {
	int nIndex = 1, nDelta, i;
	float fOffset;
	ds_key_t hgRowcount = 0;

	i = getScaleSlot(nTargetGB);

	nDelta = dist_weight(NULL, "rowcounts", nTable + 1, i + 1) - dist_weight(NULL, "rowcounts", nTable + 1, i);
	fOffset = (float)(nTargetGB - arScaleVolume[i - 1]) / (float)(arScaleVolume[i] - arScaleVolume[i - 1]);

	hgRowcount = (int)(fOffset * (float)nDelta);
	hgRowcount += dist_weight(NULL, "rowcounts", nTable + 1, nIndex);

	return (hgRowcount);
}

/*
 * Routine: StaticScale(void)
 * Purpose: use the command line volume target, in GB, to calculate the global
 * rowcount multiplier Algorithm: Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects: arRowcounts are set to the appropriate number of rows for the
 * target scale factor
 * TODO: None
 */
static ds_key_t StaticScale(int nTable, int nTargetGB) {
	return (dist_weight(NULL, "rowcounts", nTable + 1, 1));
}

/*
 * Routine: LinearScale(void)
 * Purpose: use the command line volume target, in GB, to calculate the global
 *rowcount multiplier Algorithm: Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions: scale factors defined in rowcounts distribution define
 *1/10/100/1000/... GB with sufficient accuracy Side Effects: arRowcounts are
 *set to the appropriate number of rows for the target scale factor
 * TODO: None
 */
static ds_key_t LinearScale(int nTable, int nTargetGB) {
	int i;
	ds_key_t hgRowcount = 0;

	for (i = 8; i >= 0; i--) /* work from large scales down)*/
	{
		/*
		 * use the defined rowcounts to build up the target GB volume
		 */
		while (nTargetGB >= arScaleVolume[i]) {
			hgRowcount += dist_weight(NULL, "rowcounts", nTable + 1, i + 1);
			nTargetGB -= arScaleVolume[i];
		}
	}

	return (hgRowcount);
}
/*
 * Routine:
 * Purpose:
 * Algorithm:
 * Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO: None
 */
ds_key_t getIDCount(int nTable) {
	ds_key_t kRowcount, kUniqueCount;
	tdef *pTdef;

	kRowcount = get_rowcount(nTable);
	if (nTable >= PSEUDO_TABLE_START)
		return (kRowcount);
	pTdef = getSimpleTdefsByNumber(nTable);
	if (pTdef->flags & FL_TYPE_2) {
		kUniqueCount = (kRowcount / 6) * 3;
		switch (kRowcount % 6) {
		case 1:
			kUniqueCount += 1;
			break;
		case 2:
		case 3:
			kUniqueCount += 2;
			break;
		case 4:
		case 5:
			kUniqueCount += 3;
			break;
		}
		return (kUniqueCount);
	} else {
		return (kRowcount);
	}
}

/*
 * Routine: get_rowcount(int table)
 * Purpose:
 * Algorithm:
 * Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO: 20040820 jms Need to address special case scaling in a more general
 * fashion
 */
ds_key_t get_rowcount(int table) {

	static double nScale;
	int nTable, nMultiplier, i, nBadScale = 0, nRowcountOffset = 0;
	tdef *pTdef;

	if (!InitConstants::get_rowcount_init) {
		nScale = get_dbl("SCALE");
		if (nScale > 100000)
			ReportErrorNoLine(QERR_BAD_SCALE, NULL, 1);

		memset(arRowcount, 0, sizeof(long) * MAX_TABLE);
		int iScale = nScale < 1 ? 1 : int(nScale);
		for (nTable = CALL_CENTER; nTable <= MAX_TABLE; nTable++) {
			switch (iScale) {
			case 100000:
				arRowcount[nTable].kBaseRowcount = dist_weight(NULL, "rowcounts", nTable + nRowcountOffset + 1, 9);
				break;
			case 30000:
				arRowcount[nTable].kBaseRowcount = dist_weight(NULL, "rowcounts", nTable + nRowcountOffset + 1, 8);
				break;
			case 10000:
				arRowcount[nTable].kBaseRowcount = dist_weight(NULL, "rowcounts", nTable + nRowcountOffset + 1, 7);
				break;
			case 3000:
				arRowcount[nTable].kBaseRowcount = dist_weight(NULL, "rowcounts", nTable + nRowcountOffset + 1, 6);
				break;
			case 1000:
				arRowcount[nTable].kBaseRowcount = dist_weight(NULL, "rowcounts", nTable + nRowcountOffset + 1, 5);
				break;
			case 300:
				nBadScale = QERR_BAD_SCALE;
				arRowcount[nTable].kBaseRowcount = dist_weight(NULL, "rowcounts", nTable + nRowcountOffset + 1, 4);
				break;
			case 100:
				nBadScale = QERR_BAD_SCALE;
				arRowcount[nTable].kBaseRowcount = dist_weight(NULL, "rowcounts", nTable + nRowcountOffset + 1, 3);
				break;
			case 10:
				nBadScale = QERR_BAD_SCALE;
				arRowcount[nTable].kBaseRowcount = dist_weight(NULL, "rowcounts", nTable + nRowcountOffset + 1, 2);
				break;
			case 1:
				nBadScale = QERR_QUALIFICATION_SCALE;
				arRowcount[nTable].kBaseRowcount = dist_weight(NULL, "rowcounts", nTable + nRowcountOffset + 1, 1);
				break;
			default:
				nBadScale = QERR_BAD_SCALE;
				int mem = dist_member(NULL, "rowcounts", nTable + 1, 3);
				switch (mem) {
				case 2:
					arRowcount[nTable].kBaseRowcount = LinearScale(nTable + nRowcountOffset, nScale);
					break;
				case 1:
					arRowcount[nTable].kBaseRowcount = StaticScale(nTable + nRowcountOffset, nScale);
					break;
				case 3:
					arRowcount[nTable].kBaseRowcount = LogScale(nTable + nRowcountOffset, nScale);
					break;
				} /* switch(FL_SCALE_MASK) */
				break;
			} /* switch(nScale) */

			/* now adjust for the multiplier */
			nMultiplier = 1;
			if (nTable < PSEUDO_TABLE_START) {
				pTdef = getSimpleTdefsByNumber(nTable);
				nMultiplier = (pTdef->flags & FL_TYPE_2) ? 2 : 1;
			}
			for (i = 1; i <= dist_member(NULL, "rowcounts", nTable + 1, 2); i++) {
				nMultiplier *= 10;
			}
			arRowcount[nTable].kBaseRowcount *= nMultiplier;
			if (arRowcount[nTable].kBaseRowcount >= 0) {
				if (nScale < 1) {
					int mem = dist_member(NULL, "rowcounts", nTable + 1, 3);
					if (!(mem == 1 && nMultiplier == 1)) {
						arRowcount[nTable].kBaseRowcount = int(arRowcount[nTable].kBaseRowcount * nScale);
					}
					if (arRowcount[nTable].kBaseRowcount == 0) {
						arRowcount[nTable].kBaseRowcount = 1;
					}
				}
			}
		} /* for each table */

		//		if (nBadScale && !is_set("QUIET"))
		//			ReportErrorNoLine(nBadScale, NULL, 0);

		InitConstants::get_rowcount_init = 1;
	}

	if (table == INVENTORY)
		return (sc_w_inventory(nScale));
	if (table == S_INVENTORY)
		return (getIDCount(ITEM) * get_rowcount(WAREHOUSE) * 6);

	return (arRowcount[table].kBaseRowcount);
}

/*
 * Routine: setUpdateDates
 * Purpose: determine the dates for fact table updates
 * Algorithm:
 * Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO: None
 */
void setUpdateDates(void) {
	assert(0);
	int nDay, nUpdate, i;
	date_t dtTemp;

	nUpdate = get_int("UPDATE");
	while (nUpdate--) {
		/* pick two adjacent days in the low density zone */
		arUpdateDates[0] = getSkewedJulianDate(calendar_low, 0);
		jtodt(&dtTemp, arUpdateDates[0]);
		dist_weight(&nDay, "calendar", day_number(&dtTemp) + 1, calendar_low);
		if (nDay)
			arUpdateDates[1] = arUpdateDates[0] + 1;
		else
			arUpdateDates[1] = arUpdateDates[0] - 1;

		/*
		 * pick the related Thursdays for inventory
		 * 1. shift first date to the Thursday in the current update week
		 * 2. move forward/back to get into correct comparability zone
		 * 3. set next date to next/prior Thursday based on comparability zone
		 */
		jtodt(&dtTemp, arUpdateDates[0] + (4 - set_dow(&dtTemp)));
		dist_weight(&nDay, "calendar", day_number(&dtTemp), calendar_low);
		arInventoryUpdateDates[0] = dtTemp.julian;
		if (!nDay) {
			jtodt(&dtTemp, dtTemp.julian - 7);
			arInventoryUpdateDates[0] = dtTemp.julian;
			dist_weight(&nDay, "calendar", day_number(&dtTemp), calendar_low);
			if (!nDay)
				arInventoryUpdateDates[0] += 14;
		}

		arInventoryUpdateDates[1] = arInventoryUpdateDates[0] + 7;
		jtodt(&dtTemp, arInventoryUpdateDates[1]);
		dist_weight(&nDay, "calendar", day_number(&dtTemp) + 1, calendar_low);
		if (!nDay)
			arInventoryUpdateDates[1] -= 14;

		/* repeat for medium calendar zone */
		arUpdateDates[2] = getSkewedJulianDate(calendar_medium, 0);
		jtodt(&dtTemp, arUpdateDates[2]);
		dist_weight(&nDay, "calendar", day_number(&dtTemp) + 1, calendar_medium);
		if (nDay)
			arUpdateDates[3] = arUpdateDates[2] + 1;
		else
			arUpdateDates[3] = arUpdateDates[2] - 1;

		jtodt(&dtTemp, arUpdateDates[2] + (4 - set_dow(&dtTemp)));
		dist_weight(&nDay, "calendar", day_number(&dtTemp), calendar_medium);
		arInventoryUpdateDates[2] = dtTemp.julian;
		if (!nDay) {
			jtodt(&dtTemp, dtTemp.julian - 7);
			arInventoryUpdateDates[2] = dtTemp.julian;
			dist_weight(&nDay, "calendar", day_number(&dtTemp), calendar_medium);
			if (!nDay)
				arInventoryUpdateDates[2] += 14;
		}

		arInventoryUpdateDates[3] = arInventoryUpdateDates[2] + 7;
		jtodt(&dtTemp, arInventoryUpdateDates[3]);
		dist_weight(&nDay, "calendar", day_number(&dtTemp), calendar_medium);
		if (!nDay)
			arInventoryUpdateDates[3] -= 14;

		/* repeat for high calendar zone */
		arUpdateDates[4] = getSkewedJulianDate(calendar_high, 0);
		jtodt(&dtTemp, arUpdateDates[4]);
		dist_weight(&nDay, "calendar", day_number(&dtTemp) + 1, calendar_high);
		if (nDay)
			arUpdateDates[5] = arUpdateDates[4] + 1;
		else
			arUpdateDates[5] = arUpdateDates[4] - 1;

		jtodt(&dtTemp, arUpdateDates[4] + (4 - set_dow(&dtTemp)));
		dist_weight(&nDay, "calendar", day_number(&dtTemp), calendar_high);
		arInventoryUpdateDates[4] = dtTemp.julian;
		if (!nDay) {
			jtodt(&dtTemp, dtTemp.julian - 7);
			arInventoryUpdateDates[4] = dtTemp.julian;
			dist_weight(&nDay, "calendar", day_number(&dtTemp), calendar_high);
			if (!nDay)
				arInventoryUpdateDates[4] += 14;
		}

		arInventoryUpdateDates[5] = arInventoryUpdateDates[4] + 7;
		jtodt(&dtTemp, arInventoryUpdateDates[5]);
		dist_weight(&nDay, "calendar", day_number(&dtTemp), calendar_high);
		if (!nDay)
			arInventoryUpdateDates[5] -= 14;
	}

	//	/*
	//	 * output the update dates for this update set
	//	 */
	//	openDeleteFile(1);
	//	for (i = 0; i < 6; i += 2)
	//		print_delete(&arUpdateDates[i]);
	//
	//	/*
	//	 * inventory uses separate dates
	//	 */
	//	openDeleteFile(2);
	//	for (i = 0; i < 6; i += 2)
	//		print_delete(&arInventoryUpdateDates[i]);
	//	openDeleteFile(0);

	return;
}

/*
 * Routine:
 * Purpose:
 * Algorithm:
 * Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO: None
 */
int getUpdateDate(int nTable, ds_key_t kRowcount) {
	static int nIndex = 0, nLastTable = -1;

	if (nLastTable != nTable) {
		nLastTable = nTable;
		get_rowcount(nTable);
		nIndex = 0;
	}

	for (nIndex = 0; kRowcount > arRowcount[nTable].kDayRowcount[nIndex]; nIndex++)
		if (nIndex == 5)
			break;

	if (nTable == S_INVENTORY) {
		return (arInventoryUpdateDates[nIndex]);
	} else
		return (arUpdateDates[nIndex]);
}

/*
 * Routine: getUpdateID(int nTable, ds_key_t *pDest)
 * Purpose: select the primary key for an update set row
 * Algorithm:
 * Data Structures:
 *
 * Params:
 * Returns: 1 if the row is new, 0 if it is reusing an existing ID
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO: 20040326 jms getUpdateID() this MUST be updated for 64bit -- all usages
 * use casts today
 * TODO:	20060102 jms this will need to be looked at for parallelism at some
 * point
 */
/*
int
getUpdateID(ds_key_t *pDest, int nTable, int nColumn)
{
    int bIsUpdate = 0,
        nTemp;

    if (genrand_integer(NULL, DIST_UNIFORM, 0, 99, 0, nColumn) <
arRowcount[nTable].nUpdatePercentage)
    {
        bIsUpdate = 1;
        genrand_integer(&nTemp, DIST_UNIFORM, 1, (int)getIDCount(nTable), 0,
nColumn); *pDest = (ds_key_t)nTemp;
    }
    else
    {
        *pDest = ++arRowcount[nTable].kNextInsertValue;
    }

    return(bIsUpdate);
}
*/

/*
 * Routine: getSkewedJulianDate()
 * Purpose: return a julian date based on the given skew and column
 * Algorithm:
 * Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO: None
 */
int getSkewedJulianDate(int nWeight, int nColumn) {
	int i;
	date_t Date;

	pick_distribution(&i, "calendar", 1, nWeight, nColumn);
	genrand_integer(&Date.year, DIST_UNIFORM, YEAR_MINIMUM, YEAR_MAXIMUM, 0, nColumn);
	dist_member(&Date.day, "calendar", i, 3);
	dist_member(&Date.month, "calendar", i, 5);
	return (dttoj(&Date));
}

/*
 * Routine: initializeOrderUpdate()
 * Purpose: skip over prior updates for the named table
 * Algorithm:
 * Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO: None
 */
/*
int
initializeOrderUpdates(int nParent, int nChild, int nIDColumn, int nDateColumn,
int *pnOrderNumber)
{
   int i,
      nRowcount,
      nRowsRemaining,
      nStep = 0;
   date_t Date;


        *pnOrderNumber = 0;

      for (i=0; i < (get_int("UPDATE") - 1); i++)
        {
            nRowsRemaining = (int)get_rowcount(nParent);
         while (nRowsRemaining > 0)
         {
            nStep = nStep % 3;
            nStep += 1;
            Date.julian = getSkewedJulianDate((nStep++ % 3) + 8, nDateColumn);
            nRowcount = (int)dateScaling(getTableFromColumn(nIDColumn),
Date.julian); *pnOrderNumber += nRowcount; row_skip(nParent, nRowcount);
            row_skip(nChild, LINES_PER_ORDER * nRowcount);
            nRowsRemaining -= nRowcount;
         }
        }

      return(nStep);
}
*/

/*
 * Routine: dateScaling(int nTable, ds_key_t jDate)
 * Purpose: determine the number of rows to build for a given date and fact
 * table Algorithm: Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO: None
 */
ds_key_t dateScaling(int nTable, ds_key_t jDate) {
	static dist_t *pDist;
	d_idx_t *pDistIndex;
	date_t Date;
	int nDateWeight = 1, nCalendarTotal, nDayWeight;
	ds_key_t kRowCount = -1;
	tdef *pTdef = getSimpleTdefsByNumber(nTable);

	if (!InitConstants::dateScaling_init) {
		pDistIndex = find_dist("calendar");
		pDist = pDistIndex->dist;
		if (!pDist)
			ReportError(QERR_NO_MEMORY, "dateScaling()", 1);
		InitConstants::dateScaling_init = 1;
	}

	jtodt(&Date, (int)jDate);

	switch (nTable) {
	case STORE_SALES:
	case CATALOG_SALES:
	case WEB_SALES:
		kRowCount = get_rowcount(nTable);
		nDateWeight = calendar_sales;
		break;
	case S_CATALOG_ORDER:
		kRowCount = get_rowcount(CATALOG_SALES);
		nDateWeight = calendar_sales;
		break;
	case S_PURCHASE:
		kRowCount = get_rowcount(STORE_SALES);
		nDateWeight = calendar_sales;
		break;
	case S_WEB_ORDER:
		kRowCount = get_rowcount(WEB_SALES);
		nDateWeight = calendar_sales;
		break;
	case S_INVENTORY:
	case INVENTORY:
		nDateWeight = calendar_uniform;
		kRowCount = get_rowcount(WAREHOUSE) * getIDCount(ITEM);
		break;
	default:
		ReportErrorNoLine(QERR_TABLE_NOP, pTdef->name, 1);
		break;
	}

	if (nTable != INVENTORY) /* inventory rowcount is uniform thorughout the year */
	{
		if (is_leap(Date.year))
			nDateWeight += 1;

		nCalendarTotal = dist_max(pDist, nDateWeight);
		nCalendarTotal *= 5; /* assumes date range is 5 years */

		dist_weight(&nDayWeight, "calendar", day_number(&Date), nDateWeight);
		kRowCount *= nDayWeight;
		kRowCount += nCalendarTotal / 2;
		kRowCount /= nCalendarTotal;
	}

	return (kRowCount);
}

/*
 * Routine: getUpdateBase(int nTable)
 * Purpose: return the offset to the first order in this update set for a given
 * table Algorithm: Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO: None
 */
ds_key_t getUpdateBase(int nTable) {
	return (arRowcount[nTable - S_BRAND].kNextInsertValue);
}

/*
 * Routine:
 * Purpose:
 * Algorithm:
 * Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO: None
 */
void setUpdateScaling(int nTable) {
	tdef *pTdef;
	int i, nBaseTable;
	ds_key_t kNewRowcount = 0;

	pTdef = getSimpleTdefsByNumber(nTable);
	if (!(pTdef->flags & FL_SOURCE_DDL) || !(pTdef->flags & FL_DATE_BASED) || (pTdef->flags & FL_NOP))
		return;

	switch (nTable) {
	case S_PURCHASE:
		nBaseTable = STORE_SALES;
		break;
	case S_CATALOG_ORDER:
		nBaseTable = CATALOG_SALES;
		break;
	case S_WEB_ORDER:
		nBaseTable = WEB_SALES;
		break;
	case S_INVENTORY:
		nBaseTable = INVENTORY;
		break;
	default:
		fprintf(stderr, "ERROR: Invalid table in setUpdateScaling\n");
		exit(1);
		break;
	}

	arRowcount[nTable].kNextInsertValue = arRowcount[nTable].kBaseRowcount;

	for (i = 0; i < 6; i++) {
		kNewRowcount += dateScaling(nBaseTable, arUpdateDates[i]);
		arRowcount[nTable].kDayRowcount[i] = kNewRowcount;
	}

	arRowcount[nTable].kBaseRowcount = kNewRowcount;
	arRowcount[nTable].kNextInsertValue += kNewRowcount * (get_int("update") - 1);

	return;
}

// sparse.cpp

/*
 * Routine: initSparseKeys()
 * Purpose: set up the set of valid key values for a sparse table.
 * Algorithm:
 * Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions: The total population will fit in 32b
 * Side Effects:
 * TODO: None
 */
int initSparseKeys(int nTable) {
	ds_key_t kRowcount, kOldSeed;
	int k;
	tdef *pTdef;

	kRowcount = get_rowcount(nTable);
	pTdef = getTdefsByNumber(nTable);

	pTdef->arSparseKeys = (ds_key_t *)malloc((long)kRowcount * sizeof(ds_key_t));
	MALLOC_CHECK(pTdef->arSparseKeys);
	if (pTdef->arSparseKeys == NULL)
		ReportError(QERR_NO_MEMORY, "initSparseKeys()", 1);
	memset(pTdef->arSparseKeys, 0, (long)kRowcount * sizeof(ds_key_t));

	kOldSeed = setSeed(0, nTable);
	for (k = 0; k < kRowcount; k++)
		genrand_key(&pTdef->arSparseKeys[k], DIST_UNIFORM, 1, pTdef->nParam, 0, 0);
	setSeed(0, (int)kOldSeed);

	return (0);
}

/*
 * Routine: randomSparseKey()
 * Purpose: randomly select one of the valid key values for a sparse table
 * Algorithm:
 * Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO: None
 */
ds_key_t randomSparseKey(int nTable, int nColumn) {
	int nKeyIndex;
	ds_key_t kRowcount;
	tdef *pTdef;

	pTdef = getTdefsByNumber(nTable);
	kRowcount = get_rowcount(nTable);
	genrand_integer(&nKeyIndex, DIST_UNIFORM, 1, (long)kRowcount, 0, nColumn);

	return (pTdef->arSparseKeys[nKeyIndex]);
}

// nulls.cpp

/*
 * Routine: nullCheck(int nColumn)
 * Purpose:
 * Algorithm:
 * Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO: None
 */
int nullCheck(int nColumn) {
	static int nLastTable = 0;
	tdef *pTdef;
	ds_key_t kBitMask = 1;

	nLastTable = getTableFromColumn(nColumn);
	pTdef = getSimpleTdefsByNumber(nLastTable);

	kBitMask <<= nColumn - pTdef->nFirstColumn;

	return ((pTdef->kNullBitMap & kBitMask) != 0);
}

/*
* Routine: nullSet(int *pDest, int nStream)
* Purpose: set the kNullBitMap for a particular table
* Algorithm:
*	1. if random[1,100] >= table's NULL pct, clear map and return
*	2. set map

* Data Structures:
*
* Params:
* Returns:
* Called By:
* Calls:
* Assumptions:
* Side Effects: uses 2 RNG calls
* TODO: None
*/
void nullSet(ds_key_t *pDest, int nStream) {
	int nThreshold;
	ds_key_t kBitMap;
	static int nLastTable = 0;
	tdef *pTdef;

	nLastTable = getTableFromColumn(nStream);
	pTdef = getSimpleTdefsByNumber(nLastTable);

	/* burn the RNG calls */
	genrand_integer(&nThreshold, DIST_UNIFORM, 0, 9999, 0, nStream);
	genrand_key(&kBitMap, DIST_UNIFORM, 1, MAXINT, 0, nStream);

	/* set the bitmap based on threshold and NOT NULL definitions */
	*pDest = 0;
	if (nThreshold < pTdef->nNullPct) {
		*pDest = kBitMap;
		*pDest &= ~pTdef->kNotNullBitMap;
	}

	return;
}

// address.cpp
#include <stdio.h>

static int s_nCountyCount = 0;
static int s_nCityCount = 0;

void resetCountCount(void) {
	s_nCountyCount = 0;
	s_nCityCount = 0;

	return;
}

/*
 * Routine:
 * Purpose:
 * Algorithm:
 * Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO: None
 */
int mk_address(ds_addr_t *pAddr, int nColumn) {
	int i, nRegion;
	char *szZipPrefix, szAddr[100];
	static int nMaxCities, nMaxCounties;
	tdef *pTdef;

	if (!InitConstants::mk_address_init) {
		nMaxCities = (int)get_rowcount(ACTIVE_CITIES);
		nMaxCounties = (int)get_rowcount(ACTIVE_COUNTIES);
		InitConstants::mk_address_init = 1;
	}

	/* street_number is [1..1000] */
	genrand_integer(&pAddr->street_num, DIST_UNIFORM, 1, 1000, 0, nColumn);

	/* street names are picked from a distribution */
	pick_distribution(&pAddr->street_name1, "street_names", 1, 1, nColumn);
	pick_distribution(&pAddr->street_name2, "street_names", 1, 2, nColumn);

	/* street type is picked from a distribution */
	pick_distribution(&pAddr->street_type, "street_type", 1, 1, nColumn);

	/* suite number is alphabetic 50% of the time */
	genrand_integer(&i, DIST_UNIFORM, 1, 100, 0, nColumn);
	if (i & 0x01) {
		sprintf(pAddr->suite_num, "Suite %d", (i >> 1) * 10);
	} else {
		sprintf(pAddr->suite_num, "Suite %c", ((i >> 1) % 25) + 'A');
	}

	pTdef = getTdefsByNumber(getTableFromColumn(nColumn));

	/* city is picked from a distribution which maps to large/medium/small */
	if (pTdef->flags & FL_SMALL) {
		i = (int)get_rowcount(getTableFromColumn(nColumn));
		genrand_integer(&i, DIST_UNIFORM, 1, (nMaxCities > i) ? i : nMaxCities, 0, nColumn);
		dist_member(&pAddr->city, "cities", i, 1);
	} else
		pick_distribution(&pAddr->city, "cities", 1, 6, nColumn);

	/* county is picked from a distribution, based on population and keys the
	 * rest */
	if (pTdef->flags & FL_SMALL) {
		i = (int)get_rowcount(getTableFromColumn(nColumn));
		genrand_integer(&nRegion, DIST_UNIFORM, 1, (nMaxCounties > i) ? i : nMaxCounties, 0, nColumn);
		dist_member(&pAddr->county, "fips_county", nRegion, 2);
	} else
		nRegion = pick_distribution(&pAddr->county, "fips_county", 2, 1, nColumn);

	/* match state with the selected region/county */
	dist_member(&pAddr->state, "fips_county", nRegion, 3);

	/* match the zip prefix with the selected region/county */
	pAddr->zip = city_hash(0, pAddr->city);
	/* 00000 - 00600 are unused. Avoid them */
	dist_member((void *)&szZipPrefix, "fips_county", nRegion, 5);
	if (!(szZipPrefix[0] - '0') && (pAddr->zip < 9400))
		pAddr->zip += 600;
	pAddr->zip += (szZipPrefix[0] - '0') * 10000;

	sprintf(szAddr, "%d %s %s %s", pAddr->street_num, pAddr->street_name1, pAddr->street_name2, pAddr->street_type);
	pAddr->plus4 = city_hash(0, szAddr);
	dist_member(&pAddr->gmt_offset, "fips_county", nRegion, 6);
	strcpy(pAddr->country, "United States");

	return (0);
}

/*
 * Routine: mk_streetnumber
 * Purpose:
 *	one of a set of routines that creates addresses
 * Algorithm:
 * Data Structures:
 *
 * Params:
 *	nTable: target table (and, by extension, address) to allow differing
 *distributions dest: destination for the random number Returns: Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO: 20030422 jms should be replaced if there is no table variation
 */
int mk_streetnumber(int nTable, int *dest) {
	genrand_integer(dest, DIST_UNIFORM, 1, 1000, 0, nTable);

	return (0);
}

/*
 * Routine: mk_suitenumber()
 * Purpose:
 *	one of a set of routines that creates addresses
 * Algorithm:
 * Data Structures:
 *
 * Params:
 *	nTable: target table (and, by extension, address) to allow differing
 *distributions dest: destination for the random number Returns: Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO: 20010615 JMS return code is meaningless
 */
int mk_suitenumber(int nTable, char *dest) {
	int i;

	genrand_integer(&i, DIST_UNIFORM, 1, 100, 0, nTable);
	if (i <= 50) {
		genrand_integer(&i, DIST_UNIFORM, 1, 1000, 0, nTable);
		sprintf(dest, "Suite %d", i);
	} else {
		genrand_integer(&i, DIST_UNIFORM, 0, 25, 0, nTable);
		sprintf(dest, "Suite %c", i + 'A');
	}

	return (0);
}

/*
 * Routine: mk_streetname()
 * Purpose:
 *	one of a set of routines that creates addresses
 * Algorithm:
 *	use a staggered distibution and the 150 most common street names in the US
 * Data Structures:
 *
 * Params:
 *	nTable: target table (and, by extension, address) to allow differing
 *distributions dest: destination for the street name Returns: Called By: Calls:
 * Assumptions:
 * Side Effects:
 * TODO: 20010615 JMS return code is meaningless
 */
int mk_streetname(int nTable, char *dest) {
	char *pTemp1 = NULL, *pTemp2 = NULL;

	pick_distribution((void *)&pTemp1, "street_names", (int)1, (int)1, nTable);
	pick_distribution((void *)&pTemp2, "street_names", (int)1, (int)2, nTable);
	if (strlen(pTemp2))
		sprintf(dest, "%s %s", pTemp1, pTemp2);
	else
		strcpy(dest, pTemp1);

	return (0);
}

/*
 * Routine: mk_city
 * Purpose:
 *	one of a set of routines that creates addresses
 * Algorithm:
 *	use a staggered distibution of 1000 most common place names in the US
 * Data Structures:
 *
 * Params:
 *	nTable: target table (and, by extension, address) to allow differing
 *distributions dest: destination for the city name Returns: Called By: Calls:
 * Assumptions:
 * Side Effects:
 * TODO: 20030423 jms should be replaced if there is no per-table variation
 */
int mk_city(int nTable, char **dest) {
	pick_distribution((void *)dest, "cities", (int)1, (int)get_int("_SCALE_INDEX"), 11);

	return (0);
}

/*
 * Routine: city_hash()
 * Purpose:
 * Algorithm:
 * Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO: None
 */
int city_hash(int nTable, char *name) {
	char *cp;
	long long hash_value = 0, res = 0; // changed to long long from int

	for (cp = name; *cp; cp++) {
		hash_value *= 26;
        // simulate the overflow as if it were an int
        if (hash_value > MAXINT) {
            hash_value %= MAXINT;
            hash_value -= MAXINT;
            hash_value -= 2;
        } else if (hash_value < -MAXINT) {
            hash_value %= MAXINT;
            hash_value += MAXINT;
            hash_value += 2;
        }
		hash_value -= 'A';
		hash_value += *cp;
		if (hash_value > 1000000) {
			hash_value %= 10000;
			res += hash_value;
			hash_value = 0;
		}
	}
	hash_value %= 1000;
	res += hash_value;
	res %= 10000; /* looking for a 4 digit result */

	return (res);
}

/*
 * Routine:
 *	one of a set of routines that creates addresses
 * Algorithm:
 *	use a compound distribution of the 3500 counties in the US
 * Data Structures:
 *
 * Params:
 *	nTable: target table (and, by extension, address) to allow differing
 *distributions dest: destination for the city name nRegion: the county selected
 *	city: the city name selected
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO: 20010615 JMS return code is meaningless
 */
int mk_zipcode(int nTable, char *dest, int nRegion, char *city) {
	char *szZipPrefix = NULL;
	int nCityCode;
	int nPlusFour;

	dist_member((void *)&szZipPrefix, "fips_county", nRegion, 5);
	nCityCode = city_hash(nTable, city);
	genrand_integer(&nPlusFour, DIST_UNIFORM, 1, 9999, 0, nTable);
	sprintf(dest, "%s%04d-%04d", szZipPrefix, nCityCode, nPlusFour);

	return (0);
}

// dsdgen.cpp


#include <cassert>


namespace tpcds {

template <class T>
static void CreateTPCDSTable(ClientContext &context, string schema, string suffix, bool keys, bool overwrite) {
	auto info = make_unique<CreateTableInfo>();
	info->schema = schema;
	info->table = T::Name + suffix;
	info->on_conflict = overwrite ? OnCreateConflict::REPLACE_ON_CONFLICT : OnCreateConflict::ERROR_ON_CONFLICT;
	info->temporary = false;
	for (idx_t i = 0; i < T::ColumnCount; i++) {
		info->columns.AddColumn(ColumnDefinition(T::Columns[i], T::Types[i]));
	}
	if (keys) {
		vector<string> pk_columns;
		for (idx_t i = 0; i < T::PrimaryKeyCount; i++) {
			pk_columns.push_back(T::PrimaryKeyColumns[i]);
		}
		info->constraints.push_back(make_unique<UniqueConstraint>(std::move(pk_columns), true));
	}
	auto &catalog = Catalog::GetCatalog(context, INVALID_CATALOG);
	catalog.CreateTable(context, std::move(info));
}

void DSDGenWrapper::CreateTPCDSSchema(ClientContext &context, string schema, string suffix, bool keys, bool overwrite) {
	CreateTPCDSTable<CallCenterInfo>(context, schema, suffix, keys, overwrite);
	CreateTPCDSTable<CatalogPageInfo>(context, schema, suffix, keys, overwrite);
	CreateTPCDSTable<CatalogReturnsInfo>(context, schema, suffix, keys, overwrite);
	CreateTPCDSTable<CatalogSalesInfo>(context, schema, suffix, keys, overwrite);
	CreateTPCDSTable<CustomerInfo>(context, schema, suffix, keys, overwrite);
	CreateTPCDSTable<CustomerAddressInfo>(context, schema, suffix, keys, overwrite);
	CreateTPCDSTable<CustomerDemographicsInfo>(context, schema, suffix, keys, overwrite);
	CreateTPCDSTable<DateDimInfo>(context, schema, suffix, keys, overwrite);
	CreateTPCDSTable<HouseholdDemographicsInfo>(context, schema, suffix, keys, overwrite);
	CreateTPCDSTable<IncomeBandInfo>(context, schema, suffix, keys, overwrite);
	CreateTPCDSTable<InventoryInfo>(context, schema, suffix, keys, overwrite);
	CreateTPCDSTable<ItemInfo>(context, schema, suffix, keys, overwrite);
	CreateTPCDSTable<PromotionInfo>(context, schema, suffix, keys, overwrite);
	CreateTPCDSTable<ReasonInfo>(context, schema, suffix, keys, overwrite);
	CreateTPCDSTable<ShipModeInfo>(context, schema, suffix, keys, overwrite);
	CreateTPCDSTable<StoreInfo>(context, schema, suffix, keys, overwrite);
	CreateTPCDSTable<StoreReturnsInfo>(context, schema, suffix, keys, overwrite);
	CreateTPCDSTable<StoreSalesInfo>(context, schema, suffix, keys, overwrite);
	CreateTPCDSTable<TimeDimInfo>(context, schema, suffix, keys, overwrite);
	CreateTPCDSTable<WarehouseInfo>(context, schema, suffix, keys, overwrite);
	CreateTPCDSTable<WebPageInfo>(context, schema, suffix, keys, overwrite);
	CreateTPCDSTable<WebReturnsInfo>(context, schema, suffix, keys, overwrite);
	CreateTPCDSTable<WebSalesInfo>(context, schema, suffix, keys, overwrite);
	CreateTPCDSTable<WebSiteInfo>(context, schema, suffix, keys, overwrite);
}

void DSDGenWrapper::DSDGen(double scale, ClientContext &context, string schema, string suffix) {
	if (scale <= 0) {
		// schema only
		return;
	}

	InitializeDSDgen(scale);

	// populate append info
	vector<unique_ptr<tpcds_append_information>> append_info;
	append_info.resize(DBGEN_VERSION);
	auto &catalog = Catalog::GetCatalog(context, INVALID_CATALOG);

	int tmin = CALL_CENTER, tmax = DBGEN_VERSION;

	for (int table_id = tmin; table_id < tmax; table_id++) {
		auto table_def = GetTDefByNumber(table_id);
		auto table_name = table_def.name + suffix;
		assert(table_def.name);
		auto table_entry = catalog.GetEntry<TableCatalogEntry>(context, schema, table_name);

		auto append = make_unique<tpcds_append_information>(context, table_entry);
		append->table_def = table_def;
		append_info[table_id] = std::move(append);
	}

	// actually generate tables using modified data generator functions
	for (int table_id = tmin; table_id < tmax; table_id++) {
		// child tables are created in parent loaders
		if (append_info[table_id]->table_def.fl_child) {
			continue;
		}

		ds_key_t k_row_count = GetRowCount(table_id), k_first_row = 1;

		// TODO: verify this is correct and required here
		if (append_info[table_id]->table_def.fl_small) {
			ResetCountCount();
		}

		auto builder_func = GetTDefFunctionByNumber(table_id);
		assert(builder_func);

		for (ds_key_t i = k_first_row; k_row_count; i++, k_row_count--) {
			// append happens directly in builders since they dump child tables
			// immediately
			if (builder_func((void *)&append_info, i)) {
				throw Exception("Table generation failed");
			}
		}
	}

	// flush any incomplete chunks
	for (int table_id = tmin; table_id < tmax; table_id++) {
		append_info[table_id]->appender.Close();
	}
}

uint32_t DSDGenWrapper::QueriesCount() {
	return TPCDS_QUERIES_COUNT;
}

string DSDGenWrapper::GetQuery(int query) {
	if (query <= 0 || query > TPCDS_QUERIES_COUNT) {
		throw SyntaxException("Out of range TPC-DS query number %d", query);
	}
	return TPCDS_QUERIES[query - 1];
}

string DSDGenWrapper::GetAnswer(double sf, int query) {
	if (query <= 0 || query > TPCDS_QUERIES_COUNT) {
		throw SyntaxException("Out of range TPC-DS query number %d", query);
	}

	if (sf == 0.01) {
		return TPCDS_ANSWERS_SF0_01[query - 1];
	} else if (sf == 1) {
		return TPCDS_ANSWERS_SF1[query - 1];
	} else {
		throw NotImplementedException("Don't have TPC-DS answers for SF %llf!", sf);
	}
}

} // namespace tpcds

// w_inventory.cpp


#include <stdio.h>

struct W_INVENTORY_TBL g_w_inventory;

/*
 * Routine:
 * Purpose:
 * Algorithm:
 * Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO: None
 */
int mk_w_inventory(void *info_arr, ds_key_t index) {
	struct W_INVENTORY_TBL *r;
	static ds_key_t item_count;
	static ds_key_t warehouse_count;
	static int jDate;
	date_t base_date_storage;
	date_t *base_date = &base_date_storage;
	int nTemp;
	tdef *pTdef = getSimpleTdefsByNumber(INVENTORY);

	r = &g_w_inventory;

	if (!InitConstants::mk_w_inventory_init) {
		memset(&g_w_inventory, 0, sizeof(struct W_INVENTORY_TBL));
		item_count = getIDCount(ITEM);
		warehouse_count = get_rowcount(WAREHOUSE);
		strtodt(base_date, DATE_MINIMUM);
		jDate = base_date->julian;
		set_dow(base_date);
		/* Make exceptions to the 1-rng-call-per-row rule */
		InitConstants::mk_w_inventory_init = 1;
	}

	nullSet(&pTdef->kNullBitMap, INV_NULLS);
	nTemp = (int)index - 1;
	r->inv_item_sk = (nTemp % item_count) + 1;
	nTemp /= (int)item_count;
	r->inv_warehouse_sk = (nTemp % warehouse_count) + 1;
	nTemp /= (int)warehouse_count;
	r->inv_date_sk = jDate + (nTemp * 7); /* inventory is updated weekly */

	/*
	 * the join between item and inventory is tricky. The item_id selected above
	 * identifies a unique part num but item is an SCD, so we need to account
	 * for that in selecting the SK to join with
	 */
	r->inv_item_sk = matchSCDSK(r->inv_item_sk, r->inv_date_sk, ITEM);

	genrand_integer(&r->inv_quantity_on_hand, DIST_UNIFORM, INV_QUANTITY_MIN, INV_QUANTITY_MAX, 0,
	                INV_QUANTITY_ON_HAND);

	void *info = append_info_get(info_arr, INVENTORY);
	append_row_start(info);
	append_key(info, r->inv_date_sk);
	append_key(info, r->inv_item_sk);
	append_key(info, r->inv_warehouse_sk);
	append_integer(info, r->inv_quantity_on_hand);
	append_row_end(info);

	return 0;
}

/*
 * Routine:
 * Purpose:
 * Algorithm:
 * Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO: None
 */
ds_key_t sc_w_inventory(int nScale) {
	ds_key_t kRes;
	date_t dTemp;
	int nDays;

	kRes = getIDCount(ITEM);
	kRes *= get_rowcount(WAREHOUSE);
	strtodt(&dTemp, DATE_MAXIMUM);
	nDays = dTemp.julian;
	strtodt(&dTemp, DATE_MINIMUM);
	nDays -= dTemp.julian;
	nDays += 1;
	nDays += 6;
	nDays /= 7; /* each items inventory is updated weekly */
	kRes *= nDays;

	return (kRes);
}

// w_household_demographics.cpp


#include <stdio.h>

struct W_HOUSEHOLD_DEMOGRAPHICS_TBL g_w_household_demographics;

/*
 * mk_household_demographics
 */
int mk_w_household_demographics(void *info_arr, ds_key_t index) {
	/* begin locals declarations */
	ds_key_t nTemp;
	struct W_HOUSEHOLD_DEMOGRAPHICS_TBL *r;
	tdef *pTdef = getSimpleTdefsByNumber(HOUSEHOLD_DEMOGRAPHICS);

	r = &g_w_household_demographics;

	nullSet(&pTdef->kNullBitMap, HD_NULLS);
	r->hd_demo_sk = index;
	nTemp = r->hd_demo_sk;
	r->hd_income_band_id = (nTemp % distsize("income_band")) + 1;
	nTemp /= distsize("income_band");
	bitmap_to_dist(&r->hd_buy_potential, "buy_potential", &nTemp, 1, HOUSEHOLD_DEMOGRAPHICS);
	bitmap_to_dist(&r->hd_dep_count, "dependent_count", &nTemp, 1, HOUSEHOLD_DEMOGRAPHICS);
	bitmap_to_dist(&r->hd_vehicle_count, "vehicle_count", &nTemp, 1, HOUSEHOLD_DEMOGRAPHICS);

	void *info = append_info_get(info_arr, HOUSEHOLD_DEMOGRAPHICS);
	append_row_start(info);
	append_key(info, r->hd_demo_sk);
	append_key(info, r->hd_income_band_id);
	append_varchar(info, r->hd_buy_potential);
	append_integer(info, r->hd_dep_count);
	append_integer(info, r->hd_vehicle_count);
	append_row_end(info);

	return 0;
}

// w_ship_mode.cpp


#include <stdio.h>

struct W_SHIP_MODE_TBL g_w_ship_mode;

/*
 * Routine:
 * Purpose:
 * Algorithm:
 * Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO: None
 */
int mk_w_ship_mode(void *info_arr, ds_key_t kIndex) {
	struct W_SHIP_MODE_TBL *r;
	ds_key_t nTemp;
	tdef *pTdef = getSimpleTdefsByNumber(SHIP_MODE);

	r = &g_w_ship_mode;

	if (!InitConstants::mk_w_ship_mode_init) {
		memset(&g_w_ship_mode, 0, sizeof(struct W_SHIP_MODE_TBL));
		InitConstants::mk_w_ship_mode_init = 1;
	}

	nullSet(&pTdef->kNullBitMap, SM_NULLS);
	r->sm_ship_mode_sk = kIndex;
	mk_bkey(&r->sm_ship_mode_id[0], kIndex, SM_SHIP_MODE_ID);
	nTemp = (long)kIndex;
	bitmap_to_dist(&r->sm_type, "ship_mode_type", &nTemp, 1, SHIP_MODE);
	bitmap_to_dist(&r->sm_code, "ship_mode_code", &nTemp, 1, SHIP_MODE);
	dist_member(&r->sm_carrier, "ship_mode_carrier", (int)kIndex, 1);
	gen_charset(r->sm_contract, ALPHANUM, 1, RS_SM_CONTRACT, SM_CONTRACT);

	void *info = append_info_get(info_arr, SHIP_MODE);
	append_row_start(info);
	append_key(info, r->sm_ship_mode_sk);
	append_varchar(info, r->sm_ship_mode_id);
	append_varchar(info, r->sm_type);
	append_varchar(info, r->sm_code);
	append_varchar(info, r->sm_carrier);
	append_varchar(info, &r->sm_contract[0]);
	append_row_end(info);

	return 0;
}

// w_income_band.cpp


#include <stdio.h>

struct W_INCOME_BAND_TBL g_w_income_band;

/*
 * mk_income_band
 */
int mk_w_income_band(void *info_arr, ds_key_t index) {
	struct W_INCOME_BAND_TBL *r;
	tdef *pTdef = getSimpleTdefsByNumber(INCOME_BAND);

	r = &g_w_income_band;

	nullSet(&pTdef->kNullBitMap, IB_NULLS);
	r->ib_income_band_id = (long)index;
	dist_member(&r->ib_lower_bound, "income_band", (long)index, 1);
	dist_member(&r->ib_upper_bound, "income_band", (long)index, 2);

	void *info = append_info_get(info_arr, INCOME_BAND);
	append_row_start(info);
	append_integer(info, r->ib_income_band_id);
	append_integer(info, r->ib_lower_bound);
	append_integer(info, r->ib_upper_bound);
	append_row_end(info);

	return 0;
}

// w_customer_address.cpp


#include <stdio.h>

struct W_CUSTOMER_ADDRESS_TBL g_w_customer_address;

/*
 * mk_customer_address
 */
int mk_w_customer_address(void *info_arr, ds_key_t index) {

	/* begin locals declarations */
	struct W_CUSTOMER_ADDRESS_TBL *r;
	tdef *pTdef = getSimpleTdefsByNumber(CUSTOMER_ADDRESS);

	r = &g_w_customer_address;

	nullSet(&pTdef->kNullBitMap, CA_NULLS);
	r->ca_addr_sk = index;
	mk_bkey(&r->ca_addr_id[0], index, CA_ADDRESS_ID);
	pick_distribution(&r->ca_location_type, "location_type", 1, 1, CA_LOCATION_TYPE);
	mk_address(&r->ca_address, CA_ADDRESS);

	void *info = append_info_get(info_arr, CUSTOMER_ADDRESS);
	append_row_start(info);

	char szTemp[128];

	append_key(info, r->ca_addr_sk);
	append_varchar(info, r->ca_addr_id);
	append_integer(info, r->ca_address.street_num);
	if (r->ca_address.street_name2) {
		sprintf(szTemp, "%s %s", r->ca_address.street_name1, r->ca_address.street_name2);
		append_varchar(info, szTemp);
	} else
		append_varchar(info, r->ca_address.street_name1);
	append_varchar(info, r->ca_address.street_type);
	append_varchar(info, &r->ca_address.suite_num[0]);
	append_varchar(info, r->ca_address.city);
	append_varchar(info, r->ca_address.county);
	append_varchar(info, r->ca_address.state);
	sprintf(szTemp, "%05d", r->ca_address.zip);
	append_varchar(info, szTemp);
	append_varchar(info, &r->ca_address.country[0]);
	append_integer(info, r->ca_address.gmt_offset);
	append_varchar(info, r->ca_location_type);

	append_row_end(info);

	return 0;
}

// w_datetbl.cpp


#include <stdio.h>

struct W_DATE_TBL g_w_date;
/* extern tdef w_tdefs[]; */

/*
 * Routine: mk_datetbl
 * Purpose: populate the date dimension
 * Algorithm:
 * Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO:
 */
int mk_w_date(void *info_arr, ds_key_t index) {
	int res = 0;

	/* begin locals declarations */
	static date_t base_date;
	int day_index, nTemp;
	date_t temp_date, dTemp2;
	struct W_DATE_TBL *r;
	tdef *pT = getSimpleTdefsByNumber(DATET);

	r = &g_w_date;

	if (!InitConstants::mk_w_date_init) {
		r->d_month_seq = 0;
		r->d_week_seq = 1;
		r->d_quarter_seq = 1;
		r->d_current_month = 0;
		r->d_current_quarter = 0;
		r->d_current_week = 0;
		strtodt(&base_date, "1900-01-01");
		/* Make exceptions to the 1-rng-call-per-row rule */
		InitConstants::mk_w_date_init = 1;
	}

	nullSet(&pT->kNullBitMap, D_NULLS);
	nTemp = (long)index + base_date.julian;
	r->d_date_sk = nTemp;
	mk_bkey(&r->d_date_id[0], nTemp, D_DATE_ID);
	jtodt(&temp_date, nTemp);
	r->d_year = temp_date.year;
	r->d_dow = set_dow(&temp_date);
	r->d_moy = temp_date.month;
	r->d_dom = temp_date.day;
	/* set the sequence counts; assumes that the date table starts on a year
	 * boundary */
	r->d_week_seq = ((int)index + 6) / 7;
	r->d_month_seq = (r->d_year - 1900) * 12 + r->d_moy - 1;
	r->d_quarter_seq = (r->d_year - 1900) * 4 + r->d_moy / 3 + 1;
	day_index = day_number(&temp_date);
	dist_member(&r->d_qoy, "calendar", day_index, 6);
	/* fiscal year is identical to calendar year */
	r->d_fy_year = r->d_year;
	r->d_fy_quarter_seq = r->d_quarter_seq;
	r->d_fy_week_seq = r->d_week_seq;
	r->d_day_name = weekday_names[r->d_dow + 1];
	dist_member(&r->d_holiday, "calendar", day_index, 8);
	if ((r->d_dow == 5) || (r->d_dow == 6))
		r->d_weekend = 1;
	else
		r->d_weekend = 0;
	if (day_index == 1)
		dist_member(&r->d_following_holiday, "calendar", 365 + is_leap(r->d_year - 1), 8);
	else
		dist_member(&r->d_following_holiday, "calendar", day_index - 1, 8);
	date_t_op(&dTemp2, OP_FIRST_DOM, &temp_date, 0);
	r->d_first_dom = dTemp2.julian;
	date_t_op(&dTemp2, OP_LAST_DOM, &temp_date, 0);
	r->d_last_dom = dTemp2.julian;
	date_t_op(&dTemp2, OP_SAME_LY, &temp_date, 0);
	r->d_same_day_ly = dTemp2.julian;
	date_t_op(&dTemp2, OP_SAME_LQ, &temp_date, 0);
	r->d_same_day_lq = dTemp2.julian;
	r->d_current_day = (r->d_date_sk == CURRENT_DAY) ? 1 : 0;
	r->d_current_year = (r->d_year == CURRENT_YEAR) ? 1 : 0;
	if (r->d_current_year) {
		r->d_current_month = (r->d_moy == CURRENT_MONTH) ? 1 : 0;
		r->d_current_quarter = (r->d_qoy == CURRENT_QUARTER) ? 1 : 0;
		r->d_current_week = (r->d_week_seq == CURRENT_WEEK) ? 1 : 0;
	}

	char sQuarterName[7];

	void *info = append_info_get(info_arr, DATET);
	append_row_start(info);

	append_key(info, r->d_date_sk);
	append_varchar(info, r->d_date_id);
	append_date(info, r->d_date_sk);
	append_integer(info, r->d_month_seq);
	append_integer(info, r->d_week_seq);
	append_integer(info, r->d_quarter_seq);
	append_integer(info, r->d_year);
	append_integer(info, r->d_dow);
	append_integer(info, r->d_moy);
	append_integer(info, r->d_dom);
	append_integer(info, r->d_qoy);
	append_integer(info, r->d_fy_year);
	append_integer(info, r->d_fy_quarter_seq);
	append_integer(info, r->d_fy_week_seq);
	append_varchar(info, r->d_day_name);
	sprintf(sQuarterName, "%4dQ%d", r->d_year, r->d_qoy);
	append_varchar(info, sQuarterName);
	append_varchar(info, r->d_holiday ? "Y" : "N");
	append_varchar(info, r->d_weekend ? "Y" : "N");
	append_varchar(info, r->d_following_holiday ? "Y" : "N");
	append_integer(info, r->d_first_dom);
	append_integer(info, r->d_last_dom);
	append_integer(info, r->d_same_day_ly);
	append_integer(info, r->d_same_day_lq);
	append_varchar(info, r->d_current_day ? "Y" : "N");
	append_varchar(info, r->d_current_week ? "Y" : "N");
	append_varchar(info, r->d_current_month ? "Y" : "N");
	append_varchar(info, r->d_current_quarter ? "Y" : "N");
	append_varchar(info, r->d_current_year ? "Y" : "N");

	append_row_end(info);

	return (res);
}

// w_catalog_page.cpp


#include <stdio.h>

struct CATALOG_PAGE_TBL g_w_catalog_page;

/*
 * Routine: mk_catalog_page()
 * Purpose: populate the catalog_page table
 * Algorithm:
 *	catalogs are issued either monthly, quarterly or bi-annually (cp_type)
 *	there is 1 of each type circulating at all times
 * Data tdefsures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO:
 * 20020903 jms cp_department needs to be randomized
 * 20020903 jms cp_description needs to be randomized
 */
int mk_w_catalog_page(void *info_arr, ds_key_t index) {
	static date_t dStartDateStorage;
	static date_t *dStartDate = &dStartDateStorage;
	static int nCatalogPageMax;
	int nDuration, nOffset, nType;
	struct CATALOG_PAGE_TBL *r;
	int nCatalogInterval;
	tdef *pTdef = getSimpleTdefsByNumber(CATALOG_PAGE);

	r = &g_w_catalog_page;

	if (!InitConstants::mk_w_catalog_page_init) {
		nCatalogPageMax = ((int)get_rowcount(CATALOG_PAGE) / CP_CATALOGS_PER_YEAR) / (YEAR_MAXIMUM - YEAR_MINIMUM + 2);

		strtodt(dStartDate, DATA_START_DATE);

		/* columns that still need to be populated */
		strcpy(r->cp_department, "DEPARTMENT");

		InitConstants::mk_w_catalog_page_init = 1;
	}

	nullSet(&pTdef->kNullBitMap, CP_NULLS);
	r->cp_catalog_page_sk = index;
	mk_bkey(&r->cp_catalog_page_id[0], index, CP_CATALOG_PAGE_ID);
	r->cp_catalog_number = (long)(index - 1) / nCatalogPageMax + 1;
	r->cp_catalog_page_number = (long)(index - 1) % nCatalogPageMax + 1;
	switch (nCatalogInterval = ((r->cp_catalog_number - 1) % CP_CATALOGS_PER_YEAR)) {
	case 0: /* bi-annual */
	case 1:
		nType = 1;
		nDuration = 182;
		nOffset = nCatalogInterval * nDuration;
		break;
	case 2:
	case 3: /* Q2 */
	case 4: /* Q3 */
	case 5: /* Q4 */
		nDuration = 91;
		nOffset = (nCatalogInterval - 2) * nDuration;
		nType = 2;
		break;
	default:
		nDuration = 30;
		nOffset = (nCatalogInterval - 6) * nDuration;
		nType = 3; /* monthly */
	}
	r->cp_start_date_id = dStartDate->julian + nOffset;
	r->cp_start_date_id += ((r->cp_catalog_number - 1) / CP_CATALOGS_PER_YEAR) * 365;
	r->cp_end_date_id = r->cp_start_date_id + nDuration - 1;
	dist_member(&r->cp_type, "catalog_page_type", nType, 1);
	gen_text(&r->cp_description[0], RS_CP_DESCRIPTION / 2, RS_CP_DESCRIPTION - 1, CP_DESCRIPTION);

	void *info = append_info_get(info_arr, CATALOG_PAGE);

	append_row_start(info);

	append_key(info, r->cp_catalog_page_sk);
	append_varchar(info, r->cp_catalog_page_id);
	append_key(info, r->cp_start_date_id);
	append_key(info, r->cp_end_date_id);
	append_varchar(info, &r->cp_department[0]);
	append_integer(info, r->cp_catalog_number);
	append_integer(info, r->cp_catalog_page_number);
	append_varchar(info, &r->cp_description[0]);
	append_varchar(info, r->cp_type);

	append_row_end(info);

	return 0;
}

// w_store_returns.cpp
#include <stdio.h>

struct W_STORE_RETURNS_TBL g_w_store_returns;
extern struct W_STORE_SALES_TBL g_w_store_sales;

/*
 * Routine: mk_store_returns()
 * Purpose: populate a return fact *sync'd with a sales fact*
 * Algorithm:
 * Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO: None
 */
int mk_w_store_returns(void *row, ds_key_t index) {
	int res = 0, nTemp;
	struct W_STORE_RETURNS_TBL *r;
	struct W_STORE_SALES_TBL *sale = &g_w_store_sales;
	tdef *pT = getSimpleTdefsByNumber(STORE_RETURNS);

	static decimal_t dMin, dMax;
	/* begin locals declarations */

	if (row == NULL)
		r = &g_w_store_returns;
	else
		r = (W_STORE_RETURNS_TBL *)row;

	if (!InitConstants::mk_w_store_returns_init) {
		strtodec(&dMin, "1.00");
		strtodec(&dMax, "100000.00");
		InitConstants::mk_w_store_returns_init = 1;
	}

	nullSet(&pT->kNullBitMap, SR_NULLS);
	/*
	 * Some of the information in the return is taken from the original sale
	 * which has been regenerated
	 */
	r->sr_ticket_number = sale->ss_ticket_number;
	r->sr_item_sk = sale->ss_sold_item_sk;
	memcpy((void *)&r->sr_pricing, (void *)&sale->ss_pricing, sizeof(ds_pricing_t));

	/*
	 * some of the fields are conditionally taken from the sale
	 */
	r->sr_customer_sk = mk_join(SR_CUSTOMER_SK, CUSTOMER, 1);
	if (genrand_integer(NULL, DIST_UNIFORM, 1, 100, 0, SR_TICKET_NUMBER) < SR_SAME_CUSTOMER)
		r->sr_customer_sk = sale->ss_sold_customer_sk;

	/*
	 * the rest of the columns are generated for this specific return
	 */
	/* the items cannot be returned until they are sold; offset is handled in
	 * mk_join, based on sales date */
	r->sr_returned_date_sk = mk_join(SR_RETURNED_DATE_SK, DATET, sale->ss_sold_date_sk);
	genrand_integer(&nTemp, DIST_UNIFORM, (8 * 3600) - 1, (17 * 3600) - 1, 0, SR_RETURNED_TIME_SK);
	r->sr_returned_time_sk = nTemp;
	r->sr_cdemo_sk = mk_join(SR_CDEMO_SK, CUSTOMER_DEMOGRAPHICS, 1);
	r->sr_hdemo_sk = mk_join(SR_HDEMO_SK, HOUSEHOLD_DEMOGRAPHICS, 1);
	r->sr_addr_sk = mk_join(SR_ADDR_SK, CUSTOMER_ADDRESS, 1);
	r->sr_store_sk = mk_join(SR_STORE_SK, STORE, 1);
	r->sr_reason_sk = mk_join(SR_REASON_SK, REASON, 1);
	genrand_integer(&r->sr_pricing.quantity, DIST_UNIFORM, 1, sale->ss_pricing.quantity, 0, SR_PRICING);
	set_pricing(SR_PRICING, &r->sr_pricing);

	return (res);
}

// w_promotion.cpp


#include <stdio.h>

struct W_PROMOTION_TBL g_w_promotion;

/*
 * Routine: mk_promotion
 * Purpose: populate the promotion table
 * Algorithm:
 * Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO:
 * 20020829 jms RNG usage on p_promo_name may be too large
 * 20020829 jms RNG usage on P_CHANNEL_DETAILS may be too large
 */
int mk_w_promotion(void *info_arr, ds_key_t index) {
	struct W_PROMOTION_TBL *r;

	/* begin locals declarations */
	static date_t start_date;
	ds_key_t nTemp;
	int nFlags;
	tdef *pTdef = getSimpleTdefsByNumber(PROMOTION);

	r = &g_w_promotion;

	if (!InitConstants::mk_w_promotion_init) {
		memset(&g_w_promotion, 0, sizeof(struct W_PROMOTION_TBL));
		InitConstants::mk_w_promotion_init = 1;
		strtodt(&start_date, DATE_MINIMUM);
	}

	nullSet(&pTdef->kNullBitMap, P_NULLS);
	r->p_promo_sk = index;
	mk_bkey(&r->p_promo_id[0], index, P_PROMO_ID);
	nTemp = index;
	r->p_start_date_id = start_date.julian + genrand_integer(NULL, DIST_UNIFORM, PROMO_START_MIN, PROMO_START_MAX,
	                                                         PROMO_START_MEAN, P_START_DATE_ID);
	r->p_end_date_id = r->p_start_date_id +
	                   genrand_integer(NULL, DIST_UNIFORM, PROMO_LEN_MIN, PROMO_LEN_MAX, PROMO_LEN_MEAN, P_END_DATE_ID);
	r->p_item_sk = mk_join(P_ITEM_SK, ITEM, 1);
	strtodec(&r->p_cost, "1000.00");
	r->p_response_target = 1;
	mk_word(&r->p_promo_name[0], "syllables", (int)index, PROMO_NAME_LEN, P_PROMO_NAME);
	nFlags = genrand_integer(NULL, DIST_UNIFORM, 0, 511, 0, P_CHANNEL_DMAIL);
	r->p_channel_dmail = nFlags & 0x01;
	nFlags <<= 1;
	r->p_channel_email = nFlags & 0x01;
	nFlags <<= 1;
	r->p_channel_catalog = nFlags & 0x01;
	nFlags <<= 1;
	r->p_channel_tv = nFlags & 0x01;
	nFlags <<= 1;
	r->p_channel_radio = nFlags & 0x01;
	nFlags <<= 1;
	r->p_channel_press = nFlags & 0x01;
	nFlags <<= 1;
	r->p_channel_event = nFlags & 0x01;
	nFlags <<= 1;
	r->p_channel_demo = nFlags & 0x01;
	nFlags <<= 1;
	r->p_discount_active = nFlags & 0x01;
	gen_text(&r->p_channel_details[0], PROMO_DETAIL_LEN_MIN, PROMO_DETAIL_LEN_MAX, P_CHANNEL_DETAILS);
	pick_distribution(&r->p_purpose, "promo_purpose", 1, 1, P_PURPOSE);

	void *info = append_info_get(info_arr, PROMOTION);
	append_row_start(info);
	append_key(info, r->p_promo_sk);
	append_varchar(info, r->p_promo_id);
	append_key(info, r->p_start_date_id);
	append_key(info, r->p_end_date_id);
	append_key(info, r->p_item_sk);
	append_decimal(info, &r->p_cost);
	append_integer(info, r->p_response_target);
	append_varchar(info, &r->p_promo_name[0]);
	append_varchar(info, r->p_channel_dmail ? "Y" : "N");
	append_varchar(info, r->p_channel_email ? "Y" : "N");
	append_varchar(info, r->p_channel_catalog ? "Y" : "N");
	append_varchar(info, r->p_channel_tv ? "Y" : "N");
	append_varchar(info, r->p_channel_radio ? "Y" : "N");
	append_varchar(info, r->p_channel_press ? "Y" : "N");
	append_varchar(info, r->p_channel_event ? "Y" : "N");
	append_varchar(info, r->p_channel_demo ? "Y" : "N");
	append_varchar(info, &r->p_channel_details[0]);
	append_varchar(info, r->p_purpose);
	append_varchar(info, r->p_discount_active ? "Y" : "N");

	append_row_end(info);

	return 0;
}

// w_store.cpp
namespace w_store {


#include <stdio.h>

struct W_STORE_TBL g_w_store;
static struct W_STORE_TBL g_OldValues;

/*
 * mk_store
 */
int mk_w_store(void *info_arr, ds_key_t index) {
	int32_t nFieldChangeFlags, bFirstRecord = 0;

	/* begin locals declarations */
	static decimal_t dRevMin, dRevMax;
	char *sName1, *sName2, *szTemp;
	int32_t nHierarchyTotal, nStoreType, nPercentage, nDaysOpen, nMin, nMax;
	static date_t tDate;
	static decimal_t min_rev_growth, max_rev_growth, dMinTaxPercentage, dMaxTaxPercentage;
	struct W_STORE_TBL *r, *rOldValues = &g_OldValues;
	tdef *pT = getSimpleTdefsByNumber(STORE);

	r = &g_w_store;

	if (!InitConstants::mk_w_store_init) {
		nHierarchyTotal = (int)get_rowcount(DIVISIONS);
		nHierarchyTotal *= (int)get_rowcount(COMPANY);
		strtodt(&tDate, DATE_MINIMUM);
		strtodec(&min_rev_growth, STORE_MIN_REV_GROWTH);
		strtodec(&max_rev_growth, STORE_MAX_REV_GROWTH);
		strtodec(&dRevMin, "1.00");
		strtodec(&dRevMax, "1000000.00");
		strtodec(&dMinTaxPercentage, STORE_MIN_TAX_PERCENTAGE);
		strtodec(&dMaxTaxPercentage, STORE_MAX_TAX_PERCENTAGE);

		/* columns that should be dynamic */
		r->rec_end_date_id = -1;
		InitConstants::mk_w_store_init = 1;
	}

	nullSet(&pT->kNullBitMap, W_STORE_NULLS);
	r->store_sk = index;

	/* if we have generated the required history for this business key and
	 * generate a new one then reset associate fields (e.g., rec_start_date
	 * minimums)
	 */
	if (setSCDKeys(S_STORE_ID, index, r->store_id, &r->rec_start_date_id, &r->rec_end_date_id)) {
		bFirstRecord = 1;
	}

	/*
	 * this is  where we select the random number that controls if a field
	 * changes from one record to the next.
	 */
	nFieldChangeFlags = next_random(W_STORE_SCD);

	/* the rest of the record in a history-keeping dimension can either be a new
	 * data value or not; use a random number and its bit pattern to determine
	 * which fields to replace and which to retain
	 */
	nPercentage = genrand_integer(NULL, DIST_UNIFORM, 1, 100, 0, W_STORE_CLOSED_DATE_ID);
	nDaysOpen =
	    genrand_integer(NULL, DIST_UNIFORM, STORE_MIN_DAYS_OPEN, STORE_MAX_DAYS_OPEN, 0, W_STORE_CLOSED_DATE_ID);
	if (nPercentage < STORE_CLOSED_PCT)
		r->closed_date_id = tDate.julian + nDaysOpen;
	else
		r->closed_date_id = -1;
	changeSCD(SCD_KEY, &r->closed_date_id, &rOldValues->closed_date_id, &nFieldChangeFlags, bFirstRecord);
	if (!r->closed_date_id)
		r->closed_date_id = -1; /* dates use a special NULL indicator */

	mk_word(r->store_name, "syllables", (long)index, 5, W_STORE_NAME);
	changeSCD(SCD_CHAR, &r->store_name, &rOldValues->store_name, &nFieldChangeFlags, bFirstRecord);

	/*
	 * use the store type to set the parameters for the rest of the attributes
	 */
	nStoreType = pick_distribution(&szTemp, "store_type", 1, 1, W_STORE_TYPE);
	dist_member(&nMin, "store_type", nStoreType, 2);
	dist_member(&nMax, "store_type", nStoreType, 3);
	genrand_integer(&r->employees, DIST_UNIFORM, nMin, nMax, 0, W_STORE_EMPLOYEES);
	changeSCD(SCD_INT, &r->employees, &rOldValues->employees, &nFieldChangeFlags, bFirstRecord);

	dist_member(&nMin, "store_type", nStoreType, 4);
	dist_member(&nMax, "store_type", nStoreType, 5),
	    genrand_integer(&r->floor_space, DIST_UNIFORM, nMin, nMax, 0, W_STORE_FLOOR_SPACE);
	changeSCD(SCD_INT, &r->floor_space, &rOldValues->floor_space, &nFieldChangeFlags, bFirstRecord);

	pick_distribution(&r->hours, "call_center_hours", 1, 1, W_STORE_HOURS);
	changeSCD(SCD_PTR, &r->hours, &rOldValues->hours, &nFieldChangeFlags, bFirstRecord);

	pick_distribution(&sName1, "first_names", 1, 1, W_STORE_MANAGER);
	pick_distribution(&sName2, "last_names", 1, 1, W_STORE_MANAGER);
	sprintf(r->store_manager, "%s %s", sName1, sName2);
	changeSCD(SCD_CHAR, &r->store_manager, &rOldValues->store_manager, &nFieldChangeFlags, bFirstRecord);

	r->market_id = genrand_integer(NULL, DIST_UNIFORM, 1, 10, 0, W_STORE_MARKET_ID);
	changeSCD(SCD_INT, &r->market_id, &rOldValues->market_id, &nFieldChangeFlags, bFirstRecord);

	genrand_decimal(&r->dTaxPercentage, DIST_UNIFORM, &dMinTaxPercentage, &dMaxTaxPercentage, NULL,
	                W_STORE_TAX_PERCENTAGE);
	changeSCD(SCD_DEC, &r->dTaxPercentage, &rOldValues->dTaxPercentage, &nFieldChangeFlags, bFirstRecord);

	pick_distribution(&r->geography_class, "geography_class", 1, 1, W_STORE_GEOGRAPHY_CLASS);
	changeSCD(SCD_PTR, &r->geography_class, &rOldValues->geography_class, &nFieldChangeFlags, bFirstRecord);

	gen_text(&r->market_desc[0], STORE_DESC_MIN, RS_S_MARKET_DESC, W_STORE_MARKET_DESC);
	changeSCD(SCD_CHAR, &r->market_desc, &rOldValues->market_desc, &nFieldChangeFlags, bFirstRecord);

	pick_distribution(&sName1, "first_names", 1, 1, W_STORE_MARKET_MANAGER);
	pick_distribution(&sName2, "last_names", 1, 1, W_STORE_MARKET_MANAGER);
	sprintf(r->market_manager, "%s %s", sName1, sName2);
	changeSCD(SCD_CHAR, &r->market_manager, &rOldValues->market_manager, &nFieldChangeFlags, bFirstRecord);

	r->division_id = pick_distribution(&r->division_name, "divisions", 1, 1, W_STORE_DIVISION_NAME);
	changeSCD(SCD_KEY, &r->division_id, &rOldValues->division_id, &nFieldChangeFlags, bFirstRecord);
	changeSCD(SCD_PTR, &r->division_name, &rOldValues->division_name, &nFieldChangeFlags, bFirstRecord);

	r->company_id = pick_distribution(&r->company_name, "stores", 1, 1, W_STORE_COMPANY_NAME);
	changeSCD(SCD_KEY, &r->company_id, &rOldValues->company_id, &nFieldChangeFlags, bFirstRecord);
	changeSCD(SCD_PTR, &r->company_name, &rOldValues->company_name, &nFieldChangeFlags, bFirstRecord);

	mk_address(&r->address, W_STORE_ADDRESS);
	changeSCD(SCD_PTR, &r->address.city, &rOldValues->address.city, &nFieldChangeFlags, bFirstRecord);
	changeSCD(SCD_PTR, &r->address.county, &rOldValues->address.county, &nFieldChangeFlags, bFirstRecord);
	changeSCD(SCD_INT, &r->address.gmt_offset, &rOldValues->address.gmt_offset, &nFieldChangeFlags, bFirstRecord);
	changeSCD(SCD_PTR, &r->address.state, &rOldValues->address.state, &nFieldChangeFlags, bFirstRecord);
	changeSCD(SCD_PTR, &r->address.street_type, &rOldValues->address.street_type, &nFieldChangeFlags, bFirstRecord);
	changeSCD(SCD_PTR, &r->address.street_name1, &rOldValues->address.street_name1, &nFieldChangeFlags, bFirstRecord);
	changeSCD(SCD_PTR, &r->address.street_name2, &rOldValues->address.street_name2, &nFieldChangeFlags, bFirstRecord);
	changeSCD(SCD_INT, &r->address.street_num, &rOldValues->address.street_num, &nFieldChangeFlags, bFirstRecord);
	changeSCD(SCD_INT, &r->address.zip, &rOldValues->address.zip, &nFieldChangeFlags, bFirstRecord);

	char szTemp2[128];

	void *info = append_info_get(info_arr, STORE);
	append_row_start(info);

	append_key(info, r->store_sk);
	append_varchar(info, r->store_id);
	append_date(info, r->rec_start_date_id);
	append_date(info, r->rec_end_date_id);
	append_key(info, r->closed_date_id);
	append_varchar(info, r->store_name);
	append_integer(info, r->employees);
	append_integer(info, r->floor_space);
	append_varchar(info, r->hours);
	append_varchar(info, &r->store_manager[0]);
	append_integer(info, r->market_id);
	append_varchar(info, r->geography_class);
	append_varchar(info, &r->market_desc[0]);
	append_varchar(info, &r->market_manager[0]);
	append_key(info, r->division_id);
	append_varchar(info, r->division_name);
	append_key(info, r->company_id);
	append_varchar(info, r->company_name);
	append_integer(info, r->address.street_num);
	if (r->address.street_name2) {
		sprintf(szTemp2, "%s %s", r->address.street_name1, r->address.street_name2);
		append_varchar(info, szTemp2);
	} else
		append_varchar(info, r->address.street_name1);
	append_varchar(info, r->address.street_type);
	append_varchar(info, r->address.suite_num);
	append_varchar(info, r->address.city);
	append_varchar(info, r->address.county);
	append_varchar(info, r->address.state);
	sprintf(szTemp2, "%05d", r->address.zip);
	append_varchar(info, szTemp2);
	append_varchar(info, r->address.country);
	append_integer(info, r->address.gmt_offset);
	append_decimal(info, &r->dTaxPercentage);

	append_row_end(info);

	return 0;
}
}

// dbgen_version.cpp
#include <stdio.h>
#include <time.h>

struct DBGEN_VERSION_TBL g_dbgen_version;

/*
 * Routine:
 * Purpose:
 * Algorithm:
 * Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO: None
 */
int mk_dbgen_version(void *pDest, ds_key_t kIndex) {
	struct DBGEN_VERSION_TBL *r;
	time_t ltime;
	struct tm *pTimeStamp;

	if (pDest == NULL)
		r = &g_dbgen_version;
	else
		r = (DBGEN_VERSION_TBL *)pDest;

	if (!InitConstants::mk_dbgen_version_init) {
		memset(&g_dbgen_version, 0, sizeof(struct DBGEN_VERSION_TBL));
		InitConstants::mk_dbgen_version_init = 1;
	}

	time(&ltime);                   /* Get time in seconds */
	pTimeStamp = localtime(&ltime); /* Convert time to struct */

	sprintf(r->szDate, "%4d-%02d-%02d", pTimeStamp->tm_year + 1900, pTimeStamp->tm_mon + 1, pTimeStamp->tm_mday);
	sprintf(r->szTime, "%02d:%02d:%02d", pTimeStamp->tm_hour, pTimeStamp->tm_min, pTimeStamp->tm_sec);
	sprintf(r->szVersion, "%d.%d.%d%s", VERSION, RELEASE, MODIFICATION, PATCH);
	strcpy(r->szCmdLineArgs, "--this_table_is_rather_pointless");

	return (0);
}
//
///*
// * Routine:
// * Purpose:
// * Algorithm:
// * Data Structures:
// *
// * Params:
// * Returns:
// * Called By:
// * Calls:
// * Assumptions:
// * Side Effects:
// * TODO: None
// */
// int pr_dbgen_version(void *pSrc) {
//	struct DBGEN_VERSION_TBL *r;
//
//	if (pSrc == NULL)
//		r = &g_dbgen_version;
//	else
//		r = pSrc;
//
//	print_start(DBGEN_VERSION);
//	print_varchar(DV_VERSION, r->szVersion, 1);
//	print_varchar(DV_CREATE_DATE, r->szDate, 1);
//	print_varchar(DV_CREATE_TIME, r->szTime, 1);
//	print_varchar(DV_CMDLINE_ARGS, r->szCmdLineArgs, 0);
//	print_end(DBGEN_VERSION);
//
//	return (0);
//}

// w_customer.cpp


#include <stdio.h>

struct W_CUSTOMER_TBL g_w_customer;
/* extern tdef w_tdefs[]; */

/*
 * Routine: mk_customer
 * Purpose: populate the customer dimension
 * Algorithm:
 * Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO:
 */
int mk_w_customer(void *info_arr, ds_key_t index) {
	int nTemp;

	static int nBaseDate;
	/* begin locals declarations */
	int nNameIndex, nGender;
	struct W_CUSTOMER_TBL *r;
	date_t dtTemp;
	static date_t dtBirthMin, dtBirthMax, dtToday, dt1YearAgo, dt10YearsAgo;
	tdef *pT = getSimpleTdefsByNumber(CUSTOMER);

	r = &g_w_customer;

	if (!InitConstants::mk_w_customer_init) {
		date_t min_date;
		strtodt(&min_date, DATE_MINIMUM);
		nBaseDate = dttoj(&min_date);

		strtodt(&dtBirthMax, "1992-12-31");
		strtodt(&dtBirthMin, "1924-01-01");
		strtodt(&dtToday, TODAYS_DATE);
		jtodt(&dt1YearAgo, dtToday.julian - 365);
		jtodt(&dt10YearsAgo, dtToday.julian - 3650);

		InitConstants::mk_w_customer_init = 1;
	}

	nullSet(&pT->kNullBitMap, C_NULLS);
	r->c_customer_sk = index;
	mk_bkey(&r->c_customer_id[0], index, C_CUSTOMER_ID);
	genrand_integer(&nTemp, DIST_UNIFORM, 1, 100, 0, C_PREFERRED_CUST_FLAG);
	r->c_preferred_cust_flag = (nTemp < C_PREFERRED_PCT) ? 1 : 0;

	/* demographic keys are a composite of values. rebuild them a la
	 * bitmap_to_dist */
	r->c_current_hdemo_sk = mk_join(C_CURRENT_HDEMO_SK, HOUSEHOLD_DEMOGRAPHICS, 1);

	r->c_current_cdemo_sk = mk_join(C_CURRENT_CDEMO_SK, CUSTOMER_DEMOGRAPHICS, 1);

	r->c_current_addr_sk = mk_join(C_CURRENT_ADDR_SK, CUSTOMER_ADDRESS, r->c_customer_sk);
	nNameIndex = pick_distribution(&r->c_first_name, "first_names", 1, 3, C_FIRST_NAME);
	pick_distribution(&r->c_last_name, "last_names", 1, 1, C_LAST_NAME);
	dist_weight(&nGender, "first_names", nNameIndex, 2);
	pick_distribution(&r->c_salutation, "salutations", 1, (nGender == 0) ? 2 : 3, C_SALUTATION);

	genrand_date(&dtTemp, DIST_UNIFORM, &dtBirthMin, &dtBirthMax, NULL, C_BIRTH_DAY);
	r->c_birth_day = dtTemp.day;
	r->c_birth_month = dtTemp.month;
	r->c_birth_year = dtTemp.year;
	genrand_email(r->c_email_address, r->c_first_name, r->c_last_name, C_EMAIL_ADDRESS);
	genrand_date(&dtTemp, DIST_UNIFORM, &dt1YearAgo, &dtToday, NULL, C_LAST_REVIEW_DATE);
	r->c_last_review_date = dtTemp.julian;
	genrand_date(&dtTemp, DIST_UNIFORM, &dt10YearsAgo, &dtToday, NULL, C_FIRST_SALES_DATE_ID);
	r->c_first_sales_date_id = dtTemp.julian;
	r->c_first_shipto_date_id = r->c_first_sales_date_id + 30;

	pick_distribution(&r->c_birth_country, "countries", 1, 1, C_BIRTH_COUNTRY);

	void *info = append_info_get(info_arr, CUSTOMER);
	append_row_start(info);

	append_key(info, r->c_customer_sk);
	append_varchar(info, r->c_customer_id);
	append_key(info, r->c_current_cdemo_sk);
	append_key(info, r->c_current_hdemo_sk);
	append_key(info, r->c_current_addr_sk);
	append_integer(info, r->c_first_shipto_date_id);
	append_integer(info, r->c_first_sales_date_id);
	append_varchar(info, r->c_salutation);
	append_varchar(info, r->c_first_name);
	append_varchar(info, r->c_last_name);
	append_varchar(info, r->c_preferred_cust_flag ? "Y" : "N");
	append_integer(info, r->c_birth_day);
	append_integer(info, r->c_birth_month);
	append_integer(info, r->c_birth_year);
	append_varchar(info, r->c_birth_country);
	append_varchar(info, &r->c_login[0]);
	append_varchar(info, &r->c_email_address[0]);
	append_integer(info, r->c_last_review_date);

	append_row_end(info);

	return 0;
}

// w_reason.cpp


#include <stdio.h>

struct W_REASON_TBL g_w_reason;

/*
 * mk_reason
 */
int mk_w_reason(void *info_arr, ds_key_t index) {
	struct W_REASON_TBL *r;
	tdef *pTdef = getSimpleTdefsByNumber(REASON);

	r = &g_w_reason;

	if (!InitConstants::mk_w_reason_init) {
		memset(&g_w_reason, 0, sizeof(struct W_REASON_TBL));
		InitConstants::mk_w_reason_init = 1;
	}

	nullSet(&pTdef->kNullBitMap, R_NULLS);
	r->r_reason_sk = index;
	mk_bkey(&r->r_reason_id[0], index, R_REASON_ID);
	dist_member(&r->r_reason_description, "return_reasons", (int)index, 1);

	void *info = append_info_get(info_arr, REASON);
	append_row_start(info);
	append_key(info, r->r_reason_sk);
	append_varchar(info, r->r_reason_id);
	append_varchar(info, r->r_reason_description);
	append_row_end(info);

	return 0;
}

// w_timetbl.cpp


#include <stdio.h>

struct W_TIME_TBL g_w_time;

/*
 * mk_time
 */
int mk_w_time(void *info_arr, ds_key_t index) {

	/* begin locals declarations */
	int nTemp;
	struct W_TIME_TBL *r;
	tdef *pT = getSimpleTdefsByNumber(TIME);

	r = &g_w_time;

	nullSet(&pT->kNullBitMap, T_NULLS);
	r->t_time_sk = index - 1;
	mk_bkey(&r->t_time_id[0], index, T_TIME_ID);
	r->t_time = (long)index - 1;
	nTemp = (long)index - 1;
	r->t_second = nTemp % 60;
	nTemp /= 60;
	r->t_minute = nTemp % 60;
	nTemp /= 60;
	r->t_hour = nTemp % 24;
	dist_member(&r->t_am_pm, "hours", r->t_hour + 1, 2);
	dist_member(&r->t_shift, "hours", r->t_hour + 1, 3);
	dist_member(&r->t_sub_shift, "hours", r->t_hour + 1, 4);
	dist_member(&r->t_meal_time, "hours", r->t_hour + 1, 5);

	void *info = append_info_get(info_arr, TIME);
	append_row_start(info);
	append_key(info, r->t_time_sk);
	append_varchar(info, r->t_time_id);
	append_integer(info, r->t_time);
	append_integer(info, r->t_hour);
	append_integer(info, r->t_minute);
	append_integer(info, r->t_second);
	append_varchar(info, r->t_am_pm);
	append_varchar(info, r->t_shift);
	append_varchar(info, r->t_sub_shift);
	append_varchar(info, r->t_meal_time);
	append_row_end(info);

	return 0;
}

// w_warehouse.cpp


#include <stdio.h>

struct W_WAREHOUSE_TBL g_w_warehouse;

/*
 * mk_warehouse
 */
int mk_w_warehouse(void *info_arr, ds_key_t index) {

	/* begin locals declarations */
	struct W_WAREHOUSE_TBL *r;
	tdef *pT = getSimpleTdefsByNumber(WAREHOUSE);

	r = &g_w_warehouse;

	nullSet(&pT->kNullBitMap, W_NULLS);
	r->w_warehouse_sk = index;
	mk_bkey(&r->w_warehouse_id[0], index, W_WAREHOUSE_ID);
	gen_text(&r->w_warehouse_name[0], W_NAME_MIN, RS_W_WAREHOUSE_NAME, W_WAREHOUSE_NAME);
	r->w_warehouse_sq_ft = genrand_integer(NULL, DIST_UNIFORM, W_SQFT_MIN, W_SQFT_MAX, 0, W_WAREHOUSE_SQ_FT);

	mk_address(&r->w_address, W_WAREHOUSE_ADDRESS);

	char szTemp[128];

	void *info = append_info_get(info_arr, WAREHOUSE);
	append_row_start(info);

	append_key(info, r->w_warehouse_sk);
	append_varchar(info, r->w_warehouse_id);
	append_varchar(info, &r->w_warehouse_name[0]);
	append_integer(info, r->w_warehouse_sq_ft);
	append_integer(info, r->w_address.street_num);
	if (r->w_address.street_name2 != NULL) {
		sprintf(szTemp, "%s %s", r->w_address.street_name1, r->w_address.street_name2);
		append_varchar(info, szTemp);
	} else
		append_varchar(info, r->w_address.street_name1);
	append_varchar(info, r->w_address.street_type);
	append_varchar(info, r->w_address.suite_num);
	append_varchar(info, r->w_address.city);
	append_varchar(info, r->w_address.county);
	append_varchar(info, r->w_address.state);
	sprintf(szTemp, "%05d", r->w_address.zip);
	append_varchar(info, szTemp);
	append_varchar(info, r->w_address.country);
	append_integer(info, r->w_address.gmt_offset);

	append_row_end(info);

	return 0;
}

// w_store_sales.cpp


#ifdef JMS
extern rng_t Streams[];
#endif

struct W_STORE_SALES_TBL g_w_store_sales;
ds_key_t skipDays(int nTable, ds_key_t *pRemainder);
static int *pItemPermutation, nItemCount, nItemIndex;
static ds_key_t jDate, kNewDateIndex;

/*
 * mk_store_sales
 */
static void mk_master(void *info_arr, ds_key_t index) {
	struct W_STORE_SALES_TBL *r;
	static decimal_t dMin, dMax;
	static int nMaxItemCount;
	static ds_key_t kNewDateIndex = 0;

	r = &g_w_store_sales;

	if (!InitConstants::mk_master_store_sales_init) {
		strtodec(&dMin, "1.00");
		strtodec(&dMax, "100000.00");
		nMaxItemCount = 20;
		jDate = skipDays(STORE_SALES, &kNewDateIndex);
		pItemPermutation = makePermutation(NULL, nItemCount = (int)getIDCount(ITEM), SS_PERMUTATION);

		InitConstants::mk_master_store_sales_init = 1;
	}

	while (index > kNewDateIndex) /* need to move to a new date */
	{
		jDate += 1;
		kNewDateIndex += dateScaling(STORE_SALES, jDate);
	}
	r->ss_sold_store_sk = mk_join(SS_SOLD_STORE_SK, STORE, 1);
	r->ss_sold_time_sk = mk_join(SS_SOLD_TIME_SK, TIME, 1);
	r->ss_sold_date_sk = mk_join(SS_SOLD_DATE_SK, DATET, 1);
	r->ss_sold_customer_sk = mk_join(SS_SOLD_CUSTOMER_SK, CUSTOMER, 1);
	r->ss_sold_cdemo_sk = mk_join(SS_SOLD_CDEMO_SK, CUSTOMER_DEMOGRAPHICS, 1);
	r->ss_sold_hdemo_sk = mk_join(SS_SOLD_HDEMO_SK, HOUSEHOLD_DEMOGRAPHICS, 1);
	r->ss_sold_addr_sk = mk_join(SS_SOLD_ADDR_SK, CUSTOMER_ADDRESS, 1);
	r->ss_ticket_number = index;
	genrand_integer(&nItemIndex, DIST_UNIFORM, 1, nItemCount, 0, SS_SOLD_ITEM_SK);

	return;
}

static void mk_detail(void *info_arr, int bPrint) {
	int nTemp;
	struct W_STORE_SALES_TBL *r;
	tdef *pT = getSimpleTdefsByNumber(STORE_SALES);

	r = &g_w_store_sales;

	nullSet(&pT->kNullBitMap, SS_NULLS);
	/*
	 * items need to be unique within an order
	 * use a sequence within the permutation
	 */
	if (++nItemIndex > nItemCount)
		nItemIndex = 1;
	r->ss_sold_item_sk = matchSCDSK(getPermutationEntry(pItemPermutation, nItemIndex), r->ss_sold_date_sk, ITEM);
	r->ss_sold_promo_sk = mk_join(SS_SOLD_PROMO_SK, PROMOTION, 1);
	set_pricing(SS_PRICING, &r->ss_pricing);

	/**
	 * having gone to the trouble to make the sale, now let's see if it gets
	 * returned
	 */
	genrand_integer(&nTemp, DIST_UNIFORM, 0, 99, 0, SR_IS_RETURNED);
	if (nTemp < SR_RETURN_PCT) {
		struct W_STORE_RETURNS_TBL w_web_returns;
		struct W_STORE_RETURNS_TBL *rr = &w_web_returns;
		mk_w_store_returns(rr, 1);

		void *info = append_info_get(info_arr, STORE_RETURNS);
		append_row_start(info);

		append_key(info, rr->sr_returned_date_sk);
		append_key(info, rr->sr_returned_time_sk);
		append_key(info, rr->sr_item_sk);
		append_key(info, rr->sr_customer_sk);
		append_key(info, rr->sr_cdemo_sk);
		append_key(info, rr->sr_hdemo_sk);
		append_key(info, rr->sr_addr_sk);
		append_key(info, rr->sr_store_sk);
		append_key(info, rr->sr_reason_sk);
		append_key(info, rr->sr_ticket_number);
		append_integer(info, rr->sr_pricing.quantity);
		append_decimal(info, &rr->sr_pricing.net_paid);
		append_decimal(info, &rr->sr_pricing.ext_tax);
		append_decimal(info, &rr->sr_pricing.net_paid_inc_tax);
		append_decimal(info, &rr->sr_pricing.fee);
		append_decimal(info, &rr->sr_pricing.ext_ship_cost);
		append_decimal(info, &rr->sr_pricing.refunded_cash);
		append_decimal(info, &rr->sr_pricing.reversed_charge);
		append_decimal(info, &rr->sr_pricing.store_credit);
		append_decimal(info, &rr->sr_pricing.net_loss);
		append_row_end(info);
	}

	void *info = append_info_get(info_arr, STORE_SALES);
	append_row_start(info);

	append_key(info, r->ss_sold_date_sk);
	append_key(info, r->ss_sold_time_sk);
	append_key(info, r->ss_sold_item_sk);
	append_key(info, r->ss_sold_customer_sk);
	append_key(info, r->ss_sold_cdemo_sk);
	append_key(info, r->ss_sold_hdemo_sk);
	append_key(info, r->ss_sold_addr_sk);
	append_key(info, r->ss_sold_store_sk);
	append_key(info, r->ss_sold_promo_sk);
	append_key(info, r->ss_ticket_number);
	append_integer(info, r->ss_pricing.quantity);
	append_decimal(info, &r->ss_pricing.wholesale_cost);
	append_decimal(info, &r->ss_pricing.list_price);
	append_decimal(info, &r->ss_pricing.sales_price);
	append_decimal(info, &r->ss_pricing.coupon_amt);
	append_decimal(info, &r->ss_pricing.ext_sales_price);
	append_decimal(info, &r->ss_pricing.ext_wholesale_cost);
	append_decimal(info, &r->ss_pricing.ext_list_price);
	append_decimal(info, &r->ss_pricing.ext_tax);
	append_decimal(info, &r->ss_pricing.coupon_amt);
	append_decimal(info, &r->ss_pricing.net_paid);
	append_decimal(info, &r->ss_pricing.net_paid_inc_tax);
	append_decimal(info, &r->ss_pricing.net_profit);

	append_row_end(info);

	return;
}

/*
 * mk_store_sales
 */
int mk_w_store_sales(void *info_arr, ds_key_t index) {
	int nLineitems, i;

	/* build the static portion of an order */
	mk_master(info_arr, index);

	/* set the number of lineitems and build them */
	genrand_integer(&nLineitems, DIST_UNIFORM, 8, 16, 0, SS_TICKET_NUMBER);
	for (i = 1; i <= nLineitems; i++) {
		mk_detail(info_arr, 1);
	}

	/**
	 * and finally return 1 since we have already printed the rows
	 */
	return 0;
}

/*
 * Routine:
 * Purpose:
 * Algorithm:
 * Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO: None
 */
int vld_w_store_sales(int nTable, ds_key_t kRow, int *Permutation) {
	int nLineitem, nMaxLineitem, i;

	row_skip(nTable, kRow - 1);
	row_skip(STORE_RETURNS, kRow - 1);
	jDate = skipDays(STORE_SALES, &kNewDateIndex);
	mk_master(NULL, kRow);
	genrand_integer(&nMaxLineitem, DIST_UNIFORM, 8, 16, 9, SS_TICKET_NUMBER);
	genrand_integer(&nLineitem, DIST_UNIFORM, 1, nMaxLineitem, 0, SS_PRICING_QUANTITY);
	for (i = 1; i < nLineitem; i++) {
		mk_detail(NULL, 0);
	}
	mk_detail(NULL, 1);

	return (0);
}

// w_item.cpp
namespace w_item {


#include <stdio.h>

/* extern tdef w_tdefs[]; */

struct W_ITEM_TBL g_w_item, g_OldValues;

/*
 * mk_item
 */
int mk_w_item(void *info_arr, ds_key_t index) {
	/* begin locals declarations */
	decimal_t dMinPrice, dMaxPrice, dMarkdown;
	static decimal_t dMinMarkdown, dMaxMarkdown;
	int32_t bUseSize, bFirstRecord = 0, nFieldChangeFlags, nMin, nMax, nIndex, nTemp;
	char *cp;
	struct W_ITEM_TBL *r;
	struct W_ITEM_TBL *rOldValues = &g_OldValues;
	char *szMinPrice = NULL, *szMaxPrice = NULL;
	tdef *pT = getSimpleTdefsByNumber(ITEM);

	r = &g_w_item;

	if (!InitConstants::mk_w_item_init) {
		/* some fields are static throughout the data set */
		strtodec(&dMinMarkdown, MIN_ITEM_MARKDOWN_PCT);
		strtodec(&dMaxMarkdown, MAX_ITEM_MARKDOWN_PCT);

		InitConstants::mk_w_item_init = 1;
	}

	memset(r, 0, sizeof(struct W_ITEM_TBL));

	/* build the new value */
	nullSet(&pT->kNullBitMap, I_NULLS);
	r->i_item_sk = index;

	nIndex = pick_distribution(&nMin, "i_manager_id", 2, 1, I_MANAGER_ID);
	dist_member(&nMax, "i_manager_id", nIndex, 3);
	genrand_key(&r->i_manager_id, DIST_UNIFORM, (ds_key_t)nMin, (ds_key_t)nMax, 0, I_MANAGER_ID);

	/* if we have generated the required history for this business key and
	 * generate a new one then reset associated fields (e.g., rec_start_date
	 * minimums)
	 */
	if (setSCDKeys(I_ITEM_ID, index, r->i_item_id, &r->i_rec_start_date_id, &r->i_rec_end_date_id)) {
		/*
		 * some fields are not changed, even when a new version of the row is
		 * written
		 */
		bFirstRecord = 1;
	}

	/*
	 * this is  where we select the random number that controls if a field
	 * changes from one record to the next.
	 */
	nFieldChangeFlags = next_random(I_SCD);

	/* the rest of the record in a history-keeping dimension can either be a new
	 * data value or not; use a random number and its bit pattern to determine
	 * which fields to replace and which to retain
	 */
	gen_text(r->i_item_desc, 1, RS_I_ITEM_DESC, I_ITEM_DESC);
	changeSCD(SCD_CHAR, &r->i_item_desc, &rOldValues->i_item_desc, &nFieldChangeFlags, bFirstRecord);

	nIndex = pick_distribution(&szMinPrice, "i_current_price", 2, 1, I_CURRENT_PRICE);
	dist_member(&szMaxPrice, "i_current_price", nIndex, 3);
	strtodec(&dMinPrice, szMinPrice);
	strtodec(&dMaxPrice, szMaxPrice);
	genrand_decimal(&r->i_current_price, DIST_UNIFORM, &dMinPrice, &dMaxPrice, NULL, I_CURRENT_PRICE);
	changeSCD(SCD_INT, &r->i_current_price, &rOldValues->i_current_price, &nFieldChangeFlags, bFirstRecord);

	genrand_decimal(&dMarkdown, DIST_UNIFORM, &dMinMarkdown, &dMaxMarkdown, NULL, I_WHOLESALE_COST);
	decimal_t_op(&r->i_wholesale_cost, OP_MULT, &r->i_current_price, &dMarkdown);
	changeSCD(SCD_DEC, &r->i_wholesale_cost, &rOldValues->i_wholesale_cost, &nFieldChangeFlags, bFirstRecord);

	hierarchy_item(I_CATEGORY, &r->i_category_id, &r->i_category, index);
	/*
	 * changeSCD(SCD_INT, &r->i_category_id, &rOldValues->i_category_id,
	 * &nFieldChangeFlags,  bFirstRecord);
	 */

	hierarchy_item(I_CLASS, &r->i_class_id, &r->i_class, index);
	changeSCD(SCD_KEY, &r->i_class_id, &rOldValues->i_class_id, &nFieldChangeFlags, bFirstRecord);

	cp = &r->i_brand[0];
	hierarchy_item(I_BRAND, &r->i_brand_id, &cp, index);
	changeSCD(SCD_KEY, &r->i_brand_id, &rOldValues->i_brand_id, &nFieldChangeFlags, bFirstRecord);

	/* some categories have meaningful sizes, some don't */
	if (r->i_category_id) {
		dist_member(&bUseSize, "categories", (int)r->i_category_id, 3);
		pick_distribution(&r->i_size, "sizes", 1, bUseSize + 2, I_SIZE);
		changeSCD(SCD_PTR, &r->i_size, &rOldValues->i_size, &nFieldChangeFlags, bFirstRecord);
	} else {
		bUseSize = 0;
		r->i_size = NULL;
	}

	nIndex = pick_distribution(&nMin, "i_manufact_id", 2, 1, I_MANUFACT_ID);
	genrand_integer(&nTemp, DIST_UNIFORM, nMin, dist_member(NULL, "i_manufact_id", nIndex, 3), 0, I_MANUFACT_ID);
	r->i_manufact_id = nTemp;
	changeSCD(SCD_KEY, &r->i_manufact_id, &rOldValues->i_manufact_id, &nFieldChangeFlags, bFirstRecord);

	mk_word(r->i_manufact, "syllables", (int)r->i_manufact_id, RS_I_MANUFACT, ITEM);
	changeSCD(SCD_CHAR, &r->i_manufact, &rOldValues->i_manufact, &nFieldChangeFlags, bFirstRecord);

	gen_charset(r->i_formulation, DIGITS, RS_I_FORMULATION, RS_I_FORMULATION, I_FORMULATION);
	embed_string(r->i_formulation, "colors", 1, 2, I_FORMULATION);
	changeSCD(SCD_CHAR, &r->i_formulation, &rOldValues->i_formulation, &nFieldChangeFlags, bFirstRecord);

	pick_distribution(&r->i_color, "colors", 1, 2, I_COLOR);
	changeSCD(SCD_PTR, &r->i_color, &rOldValues->i_color, &nFieldChangeFlags, bFirstRecord);

	pick_distribution(&r->i_units, "units", 1, 1, I_UNITS);
	changeSCD(SCD_PTR, &r->i_units, &rOldValues->i_units, &nFieldChangeFlags, bFirstRecord);

	pick_distribution(&r->i_container, "container", 1, 1, ITEM);
	changeSCD(SCD_PTR, &r->i_container, &rOldValues->i_container, &nFieldChangeFlags, bFirstRecord);

	mk_word(r->i_product_name, "syllables", (int)index, RS_I_PRODUCT_NAME, ITEM);

	r->i_promo_sk = mk_join(I_PROMO_SK, PROMOTION, 1);
	genrand_integer(&nTemp, DIST_UNIFORM, 1, 100, 0, I_PROMO_SK);
	if (nTemp > I_PROMO_PERCENTAGE)
		r->i_promo_sk = -1;

	/*
	 * if this is the first of a set of revisions, then baseline the old values
	 */
	if (bFirstRecord)
		memcpy(&g_OldValues, r, sizeof(struct W_ITEM_TBL));

	if (index == 1)
		memcpy(&g_OldValues, r, sizeof(struct W_ITEM_TBL));

	void *info = append_info_get(info_arr, ITEM);
	append_row_start(info);

	append_key(info, r->i_item_sk);
	append_varchar(info, r->i_item_id);
	append_date(info, r->i_rec_start_date_id);
	append_date(info, r->i_rec_end_date_id);
	append_varchar(info, r->i_item_desc);
	append_decimal(info, &r->i_current_price);
	append_decimal(info, &r->i_wholesale_cost);
	append_key(info, r->i_brand_id);
	append_varchar(info, r->i_brand);
	append_key(info, r->i_class_id);
	append_varchar(info, r->i_class);
	append_key(info, r->i_category_id);
	append_varchar(info, r->i_category);
	append_key(info, r->i_manufact_id);
	append_varchar(info, r->i_manufact);
	append_varchar(info, r->i_size);
	append_varchar(info, r->i_formulation);
	append_varchar(info, r->i_color);
	append_varchar(info, r->i_units);
	append_varchar(info, r->i_container);
	append_key(info, r->i_manager_id);
	append_varchar(info, r->i_product_name);

	append_row_end(info);

	return 0;
}
}

// w_web_page.cpp


#include <stdio.h>

struct W_WEB_PAGE_TBL g_w_web_page;
static struct W_WEB_PAGE_TBL g_OldValues;

/*
 * Routine: mk_web_page()
 * Purpose: populate the web_page table
 * Algorithm:
 * Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO:
 * 20020815 jms check text generation/seed usage
 */
int mk_w_web_page(void *info_arr, ds_key_t index) {
	int32_t bFirstRecord = 0, nFieldChangeFlags;
	static date_t dToday;
	static ds_key_t nConcurrent, nRevisions;

	/* begin locals declarations */
	int32_t nTemp, nAccess;
	char szTemp[16];
	struct W_WEB_PAGE_TBL *r, *rOldValues = &g_OldValues;
	tdef *pT = getSimpleTdefsByNumber(WEB_PAGE);

	r = &g_w_web_page;

	if (!InitConstants::mk_w_web_page_init) {
		/* setup invariant values */
		sprintf(szTemp, "%d-%d-%d", CURRENT_YEAR, CURRENT_MONTH, CURRENT_DAY);
		strtodt(&dToday, szTemp);

		/* set up for the SCD handling */
		nConcurrent = (int)get_rowcount(CONCURRENT_WEB_SITES);
		nRevisions = (int)get_rowcount(WEB_PAGE) / nConcurrent;

		InitConstants::mk_w_web_page_init = 1;
	}

	nullSet(&pT->kNullBitMap, WP_NULLS);
	r->wp_page_sk = index;

	/* if we have generated the required history for this business key and
	 * generate a new one then reset associate fields (e.g., rec_start_date
	 * minimums)
	 */
	if (setSCDKeys(WP_PAGE_ID, index, r->wp_page_id, &r->wp_rec_start_date_id, &r->wp_rec_end_date_id)) {

		/*
		 * some fields are not changed, even when a new version of the row is
		 * written
		 */
		bFirstRecord = 1;
	}

	/*
	 * this is  where we select the random number that controls if a field
	 * changes from one record to the next.
	 */
	nFieldChangeFlags = next_random(WP_SCD);

	r->wp_creation_date_sk = mk_join(WP_CREATION_DATE_SK, DATET, index);
	changeSCD(SCD_KEY, &r->wp_creation_date_sk, &rOldValues->wp_creation_date_sk, &nFieldChangeFlags, bFirstRecord);

	genrand_integer(&nAccess, DIST_UNIFORM, 0, WP_IDLE_TIME_MAX, 0, WP_ACCESS_DATE_SK);
	r->wp_access_date_sk = dToday.julian - nAccess;
	changeSCD(SCD_KEY, &r->wp_access_date_sk, &rOldValues->wp_access_date_sk, &nFieldChangeFlags, bFirstRecord);
	if (r->wp_access_date_sk == 0)
		r->wp_access_date_sk = -1; /* special case for dates */

	genrand_integer(&nTemp, DIST_UNIFORM, 0, 99, 0, WP_AUTOGEN_FLAG);
	r->wp_autogen_flag = (nTemp < WP_AUTOGEN_PCT) ? 1 : 0;
	changeSCD(SCD_INT, &r->wp_autogen_flag, &rOldValues->wp_autogen_flag, &nFieldChangeFlags, bFirstRecord);

	r->wp_customer_sk = mk_join(WP_CUSTOMER_SK, CUSTOMER, 1);
	changeSCD(SCD_KEY, &r->wp_customer_sk, &rOldValues->wp_customer_sk, &nFieldChangeFlags, bFirstRecord);

	if (!r->wp_autogen_flag)
		r->wp_customer_sk = -1;

	genrand_url(r->wp_url, WP_URL);
	changeSCD(SCD_CHAR, &r->wp_url, &rOldValues->wp_url, &nFieldChangeFlags, bFirstRecord);

	pick_distribution(&r->wp_type, "web_page_use", 1, 1, WP_TYPE);
	changeSCD(SCD_PTR, &r->wp_type, &rOldValues->wp_type, &nFieldChangeFlags, bFirstRecord);

	genrand_integer(&r->wp_link_count, DIST_UNIFORM, WP_LINK_MIN, WP_LINK_MAX, 0, WP_LINK_COUNT);
	changeSCD(SCD_INT, &r->wp_link_count, &rOldValues->wp_link_count, &nFieldChangeFlags, bFirstRecord);

	genrand_integer(&r->wp_image_count, DIST_UNIFORM, WP_IMAGE_MIN, WP_IMAGE_MAX, 0, WP_IMAGE_COUNT);
	changeSCD(SCD_INT, &r->wp_image_count, &rOldValues->wp_image_count, &nFieldChangeFlags, bFirstRecord);

	genrand_integer(&r->wp_max_ad_count, DIST_UNIFORM, WP_AD_MIN, WP_AD_MAX, 0, WP_MAX_AD_COUNT);
	changeSCD(SCD_INT, &r->wp_max_ad_count, &rOldValues->wp_max_ad_count, &nFieldChangeFlags, bFirstRecord);

	genrand_integer(&r->wp_char_count, DIST_UNIFORM, r->wp_link_count * 125 + r->wp_image_count * 50,
	                r->wp_link_count * 300 + r->wp_image_count * 150, 0, WP_CHAR_COUNT);
	changeSCD(SCD_INT, &r->wp_char_count, &rOldValues->wp_char_count, &nFieldChangeFlags, bFirstRecord);

	void *info = append_info_get(info_arr, WEB_PAGE);
	append_row_start(info);

	append_key(info, r->wp_page_sk);
	append_varchar(info, r->wp_page_id);
	append_date(info, r->wp_rec_start_date_id);
	append_date(info, r->wp_rec_end_date_id);
	append_key(info, r->wp_creation_date_sk);
	append_key(info, r->wp_access_date_sk);
	append_varchar(info, r->wp_autogen_flag ? "Y" : "N");
	append_key(info, r->wp_customer_sk);
	append_varchar(info, &r->wp_url[0]);
	append_varchar(info, &r->wp_type[0]);
	append_integer(info, r->wp_char_count);
	append_integer(info, r->wp_link_count);
	append_integer(info, r->wp_image_count);
	append_integer(info, r->wp_max_ad_count);
	append_row_end(info);

	return 0;
}

// w_web_site.cpp
namespace w_web_site {


#include <stdio.h>

struct W_WEB_SITE_TBL g_w_web_site;
static struct W_WEB_SITE_TBL g_OldValues;

/*
 * Routine: mk_web_site()
 * Purpose: populate the web_site table
 * Algorithm:
 * Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO:
 */
int mk_w_web_site(void *info_arr, ds_key_t index) {
	int32_t nFieldChangeFlags, bFirstRecord = 0;
	static decimal_t dMinTaxPercentage, dMaxTaxPercentage;

	/* begin locals declarations */
	char szTemp[16], *sName1, *sName2;
	struct W_WEB_SITE_TBL *r, *rOldValues = &g_OldValues;
	tdef *pT = getSimpleTdefsByNumber(WEB_SITE);

	r = &g_w_web_site;

	if (!InitConstants::mk_w_web_site_init) {
		/* setup invariant values */
		sprintf(szTemp, "%d-%d-%d", CURRENT_YEAR, CURRENT_MONTH, CURRENT_DAY);
		strcpy(r->web_class, "Unknown");
		strtodec(&dMinTaxPercentage, WEB_MIN_TAX_PERCENTAGE);
		strtodec(&dMaxTaxPercentage, WEB_MAX_TAX_PERCENTAGE);

		InitConstants::mk_w_web_site_init = 1;
	}

	nullSet(&pT->kNullBitMap, WEB_NULLS);
	r->web_site_sk = index;

	/* if we have generated the required history for this business key and
	 * generate a new one then reset associate fields (e.g., rec_start_date
	 * minimums)
	 */
	if (setSCDKeys(WEB_SITE_ID, index, r->web_site_id, &r->web_rec_start_date_id, &r->web_rec_end_date_id)) {
		r->web_open_date = mk_join(WEB_OPEN_DATE, DATET, index);
		r->web_close_date = mk_join(WEB_CLOSE_DATE, DATET, index);
		if (r->web_close_date > r->web_rec_end_date_id)
			r->web_close_date = -1;
		sprintf(r->web_name, "site_%d", (int)(index / 6));
		bFirstRecord = 1;
	}

	/*
	 * this is  where we select the random number that controls if a field
	 * changes from one record to the next.
	 */
	nFieldChangeFlags = next_random(WEB_SCD);

	/* the rest of the record in a history-keeping dimension can either be a new
	 * data value or not; use a random number and its bit pattern to determine
	 * which fields to replace and which to retain
	 */
	pick_distribution(&sName1, "first_names", 1, 1, WEB_MANAGER);
	pick_distribution(&sName2, "last_names", 1, 1, WEB_MANAGER);
	sprintf(r->web_manager, "%s %s", sName1, sName2);
	changeSCD(SCD_CHAR, &r->web_manager, &rOldValues->web_manager, &nFieldChangeFlags, bFirstRecord);

	genrand_integer(&r->web_market_id, DIST_UNIFORM, 1, 6, 0, WEB_MARKET_ID);
	changeSCD(SCD_INT, &r->web_market_id, &rOldValues->web_market_id, &nFieldChangeFlags, bFirstRecord);

	gen_text(r->web_market_class, 20, RS_WEB_MARKET_CLASS, WEB_MARKET_CLASS);
	changeSCD(SCD_CHAR, &r->web_market_class, &rOldValues->web_market_class, &nFieldChangeFlags, bFirstRecord);

	gen_text(r->web_market_desc, 20, RS_WEB_MARKET_DESC, WEB_MARKET_DESC);
	changeSCD(SCD_CHAR, &r->web_market_desc, &rOldValues->web_market_desc, &nFieldChangeFlags, bFirstRecord);

	pick_distribution(&sName1, "first_names", 1, 1, WEB_MARKET_MANAGER);
	pick_distribution(&sName2, "last_names", 1, 1, WEB_MARKET_MANAGER);
	sprintf(r->web_market_manager, "%s %s", sName1, sName2);
	changeSCD(SCD_CHAR, &r->web_market_manager, &rOldValues->web_market_manager, &nFieldChangeFlags, bFirstRecord);

	genrand_integer(&r->web_company_id, DIST_UNIFORM, 1, 6, 0, WEB_COMPANY_ID);
	changeSCD(SCD_INT, &r->web_company_id, &rOldValues->web_company_id, &nFieldChangeFlags, bFirstRecord);

	mk_word(r->web_company_name, "Syllables", r->web_company_id, RS_WEB_COMPANY_NAME, WEB_COMPANY_NAME);
	changeSCD(SCD_CHAR, &r->web_company_name, &rOldValues->web_company_name, &nFieldChangeFlags, bFirstRecord);

	mk_address(&r->web_address, WEB_ADDRESS);
	changeSCD(SCD_PTR, &r->web_address.city, &rOldValues->web_address.city, &nFieldChangeFlags, bFirstRecord);
	changeSCD(SCD_PTR, &r->web_address.county, &rOldValues->web_address.county, &nFieldChangeFlags, bFirstRecord);
	changeSCD(SCD_INT, &r->web_address.gmt_offset, &rOldValues->web_address.gmt_offset, &nFieldChangeFlags,
	          bFirstRecord);
	changeSCD(SCD_PTR, &r->web_address.state, &rOldValues->web_address.state, &nFieldChangeFlags, bFirstRecord);
	changeSCD(SCD_PTR, &r->web_address.street_type, &rOldValues->web_address.street_type, &nFieldChangeFlags,
	          bFirstRecord);
	changeSCD(SCD_PTR, &r->web_address.street_name1, &rOldValues->web_address.street_name1, &nFieldChangeFlags,
	          bFirstRecord);
	changeSCD(SCD_PTR, &r->web_address.street_name2, &rOldValues->web_address.street_name2, &nFieldChangeFlags,
	          bFirstRecord);
	changeSCD(SCD_INT, &r->web_address.street_num, &rOldValues->web_address.street_num, &nFieldChangeFlags,
	          bFirstRecord);
	changeSCD(SCD_INT, &r->web_address.zip, &rOldValues->web_address.zip, &nFieldChangeFlags, bFirstRecord);

	genrand_decimal(&r->web_tax_percentage, DIST_UNIFORM, &dMinTaxPercentage, &dMaxTaxPercentage, NULL,
	                WEB_TAX_PERCENTAGE);
	changeSCD(SCD_DEC, &r->web_tax_percentage, &rOldValues->web_tax_percentage, &nFieldChangeFlags, bFirstRecord);

	void *info = append_info_get(info_arr, WEB_SITE);
	append_row_start(info);

	char szStreetName[128];

	append_key(info, r->web_site_sk);
	append_varchar(info, &r->web_site_id[0]);
	append_date(info, (int)r->web_rec_start_date_id);
	append_date(info, (int)r->web_rec_end_date_id);
	append_varchar(info, &r->web_name[0]);
	append_key(info, r->web_open_date);
	append_key(info, r->web_close_date);
	append_varchar(info, &r->web_class[0]);
	append_varchar(info, &r->web_manager[0]);
	append_integer(info, r->web_market_id);
	append_varchar(info, &r->web_market_class[0]);
	append_varchar(info, &r->web_market_desc[0]);
	append_varchar(info, &r->web_market_manager[0]);
	append_integer(info, r->web_company_id);
	append_varchar(info, &r->web_company_name[0]);
	append_integer(info, r->web_address.street_num);
	if (r->web_address.street_name2) {
		sprintf(szStreetName, "%s %s", r->web_address.street_name1, r->web_address.street_name2);
		append_varchar(info, szStreetName);
	} else
		append_varchar(info, r->web_address.street_name1);
	append_varchar(info, r->web_address.street_type);
	append_varchar(info, r->web_address.suite_num);
	append_varchar(info, r->web_address.city);
	append_varchar(info, r->web_address.county);
	append_varchar(info, r->web_address.state);
	sprintf(szStreetName, "%05d", r->web_address.zip);
	append_varchar(info, szStreetName);
	append_varchar(info, r->web_address.country);
	append_integer(info, r->web_address.gmt_offset);
	append_decimal(info, &r->web_tax_percentage);

	append_row_end(info);

	return 0;
}
}

// build_support.cpp
#include <stdio.h>
#ifndef WIN32
#include <netinet/in.h>
#endif
#include <math.h>

/*
 * Routine: hierarchy_item
 * Purpose:
 *	select the hierarchy entry for this level
 * Algorithm: Assumes a top-down ordering
 * Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO:
 */
void hierarchy_item(int h_level, ds_key_t *id, char **name, ds_key_t kIndex) {
	static int nLastCategory = -1, nLastClass = -1, nBrandBase;
	int nBrandCount;
	static char *szClassDistName = NULL;
	char sTemp[6];

	switch (h_level) {
	case I_CATEGORY:
		nLastCategory = pick_distribution(name, "categories", 1, 1, h_level);
		*id = nLastCategory;
		nBrandBase = nLastCategory;
		nLastClass = -1;
		break;
	case I_CLASS:
		if (nLastCategory == -1)
			ReportErrorNoLine(DBGEN_ERROR_HIERACHY_ORDER, "I_CLASS before I_CATEGORY", 1);
		dist_member(&szClassDistName, "categories", nLastCategory, 2);
		nLastClass = pick_distribution(name, szClassDistName, 1, 1, h_level);
		nLastCategory = -1;
		*id = nLastClass;
		break;
	case I_BRAND:
		if (nLastClass == -1)
			ReportErrorNoLine(DBGEN_ERROR_HIERACHY_ORDER, "I_BRAND before I_CLASS", 1);
		dist_member(&nBrandCount, szClassDistName, nLastClass, 2);
		*id = kIndex % nBrandCount + 1;
		mk_word(*name, "brand_syllables", nBrandBase * 10 + nLastClass, 45, I_BRAND);
		sprintf(sTemp, " #%d", (int)*id);
		strcat(*name, sTemp);
		*id += (nBrandBase * 1000 + nLastClass) * 1000;
		break;
	default:
		printf("ERROR: Invalid call to hierarchy_item with argument '%d'\n", h_level);
		exit(1);
	}

	return;
}

/*
 * Routine: mk_companyname()
 * Purpose:
 *	yet another member of a set of routines used for address creation
 * Algorithm:
 *	create a hash, based on an index value, so that the same result can be
 *derived reliably and then build a word from a syllable set Data Structures:
 *
 * Params:
 *	char * dest: target for resulting name
 *	int nTable: to allow differing distributions
 *	int nCompany: index value
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO:
 *	20010615 JMS return code is meaningless
 *	20030422 JMS should be replaced if there is no per-table variation
 */
int mk_companyname(char *dest, int nTable, int nCompany) {
	mk_word(dest, "syllables", nCompany, 10, CC_COMPANY_NAME);

	return (0);
}

/*
 * Routine: set_locale()
 * Purpose:
 *	generate a reasonable lattitude and longitude based on a region and the USGS
 *data on 3500 counties in the US Algorithm: Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO: 20011230 JMS set_locale() is just a placeholder; do we need geographic
 *coords?
 */
int set_locale(int nRegion, decimal_t *longitude, decimal_t *latitude) {
	static int init = 0;
	static decimal_t dZero;

	if (!init) {
		strtodec(&dZero, "0.00");
		init = 1;
	}

	memcpy(longitude, &dZero, sizeof(decimal_t));
	memcpy(latitude, &dZero, sizeof(decimal_t));

	return (0);
}

/*
 * Routine:
 * Purpose:
 * Algorithm:
 * Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO: None
 */
void bitmap_to_dist(void *pDest, const char *distname, ds_key_t *modulus, int vset, int stream) {
	int32_t m, s;
	char msg[80];

	if ((s = distsize(distname)) == -1) {
		sprintf(msg, "Invalid distribution name '%s'", distname);
		INTERNAL(msg);
	}
	m = (int32_t)((*modulus % s) + 1);
	*modulus /= s;

	dist_member(pDest, distname, m, vset);

	return;
}

/*
 * Routine: void dist_to_bitmap(int *pDest, char *szDistName, int nValueSet, int
 * nWeightSet, int nStream) Purpose: Reverse engineer a composite key based on
 * distributions Algorithm: Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO: None
 */
void dist_to_bitmap(int *pDest, const char *szDistName, int nValue, int nWeight, int nStream) {
	*pDest *= distsize(szDistName);
	*pDest += pick_distribution(NULL, szDistName, nValue, nWeight, nStream);

	return;
}

/*
 * Routine: void random_to_bitmap(int *pDest, int nDist, int nMin, int nMax, int
 * nMean, int nStream) Purpose: Reverse engineer a composite key based on an
 * integer range Algorithm: Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO: None
 */
void random_to_bitmap(int *pDest, int nDist, int nMin, int nMax, int nMean, int nStream) {
	*pDest *= nMax;
	*pDest += genrand_integer(NULL, nDist, nMin, nMax, nMean, nStream);

	return;
}

/*
 * Routine: mk_word()
 * Purpose:
 *	generate a gibberish word from a given syllable set
 * Algorithm:
 * Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO:
 */
void mk_word(char *dest, const char *syl_set, ds_key_t src, int char_cnt, int col) {
	ds_key_t i = src, nSyllableCount;
	char *cp;

	*dest = '\0';
	while (i > 0) {
		nSyllableCount = distsize(syl_set);
		dist_member(&cp, syl_set, (int)(i % nSyllableCount) + 1, 1);
		i /= nSyllableCount;
		if ((int)(strlen(dest) + strlen(cp)) <= char_cnt)
			strcat(dest, cp);
		else
			break;
	}

	return;
}

/*
 * Routine: mk_surrogate()
 * Purpose: create a character based surrogate key from a 64-bit value
 * Algorithm: since the RNG routines produce a 32bit value, and surrogate keys
 *can reach beyond that, use the RNG output to generate the lower end of a
 *random string, and build the upper end from a ds_key_t Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls: ltoc()
 * Assumptions: output is a 16 character string. Space is not checked
 * Side Effects:
 * TODO:
 * 20020830 jms may need to define a 64-bit form of htonl() for portable shift
 *operations
 */
static char szXlate[16] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P'};
static void ltoc(char *szDest, unsigned long nVal) {
	int i;
	char c;

	for (i = 0; i < 8; i++) {
		c = szXlate[(nVal & 0xF)];
		*szDest++ = c;
		nVal >>= 4;
	}
	*szDest = '\0';
}

void mk_bkey(char *szDest, ds_key_t kPrimary, int nStream) {
	unsigned long nTemp;

	nTemp = (unsigned long)(kPrimary >> 32);
	ltoc(szDest, nTemp);

	nTemp = (unsigned long)(kPrimary & 0xFFFFFFFF);
	ltoc(szDest + 8, nTemp);

	return;
}

/*
 * Routine: embed_string(char *szDest, char *szDist, int nValue, int nWeight,
 * int nStream) Purpose: Algorithm: Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO: None
 */
int embed_string(char *szDest, const char *szDist, int nValue, int nWeight, int nStream) {
	int nPosition;
	char *szWord = NULL;

	pick_distribution(&szWord, szDist, nValue, nWeight, nStream);
	nPosition = genrand_integer(NULL, DIST_UNIFORM, 0, strlen(szDest) - strlen(szWord) - 1, 0, nStream);
	memcpy(&szDest[nPosition], szWord, sizeof(char) * strlen(szWord));

	return (0);
}

/*
 * Routine: set_scale()
 * Purpose: link SCALE and SCALE_INDEX
 * Algorithm:
 * Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO: None
 */
int SetScaleIndex(const char *szName, const char *szValue) {
	int nScale;
	char szScale[2];

	if ((nScale = atoi(szValue)) == 0)
		nScale = 1;

	nScale = 1 + (int)log10(nScale);
	szScale[0] = '0' + nScale;
	szScale[1] = '\0';

	set_int("_SCALE_INDEX", szScale);

	return (atoi(szValue));
}

/*
 * Routine: adjust the valid date window for source schema tables, based on
 *	based on the update count, update window size, etc.
 * Purpose:
 * Algorithm:
 * Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO: None
 */
void setUpdateDateRange(int nTable, date_t *pMinDate, date_t *pMaxDate) {
	static int nUpdateNumber;

	if (!InitConstants::setUpdateDateRange_init) {
		nUpdateNumber = get_int("UPDATE");
		InitConstants::setUpdateDateRange_init = 1;
	}

	switch (nTable) /* no per-table changes at the moment; but could be */
	{
	default:
		strtodt(pMinDate, WAREHOUSE_LOAD_DATE);
		pMinDate->julian += UPDATE_INTERVAL * (nUpdateNumber - 1);
		jtodt(pMinDate, pMinDate->julian);
		jtodt(pMaxDate, pMinDate->julian + UPDATE_INTERVAL);
		break;
	}

	return;
}

// w_customer_demographics.cpp


#include <stdio.h>

struct W_CUSTOMER_DEMOGRAPHICS_TBL g_w_customer_demographics;

/*
 * mk_customer_demographics
 */
int mk_w_customer_demographics(void *info_arr, ds_key_t index) {

	struct W_CUSTOMER_DEMOGRAPHICS_TBL *r;
	ds_key_t kTemp;
	tdef *pTdef = getSimpleTdefsByNumber(CUSTOMER_DEMOGRAPHICS);

	r = &g_w_customer_demographics;

	nullSet(&pTdef->kNullBitMap, CD_NULLS);
	r->cd_demo_sk = index;
	kTemp = r->cd_demo_sk - 1;
	bitmap_to_dist(&r->cd_gender, "gender", &kTemp, 1, CUSTOMER_DEMOGRAPHICS);
	bitmap_to_dist(&r->cd_marital_status, "marital_status", &kTemp, 1, CUSTOMER_DEMOGRAPHICS);
	bitmap_to_dist(&r->cd_education_status, "education", &kTemp, 1, CUSTOMER_DEMOGRAPHICS);
	bitmap_to_dist(&r->cd_purchase_estimate, "purchase_band", &kTemp, 1, CUSTOMER_DEMOGRAPHICS);
	bitmap_to_dist(&r->cd_credit_rating, "credit_rating", &kTemp, 1, CUSTOMER_DEMOGRAPHICS);
	r->cd_dep_count = (int)(kTemp % (ds_key_t)CD_MAX_CHILDREN);
	kTemp /= (ds_key_t)CD_MAX_CHILDREN;
	r->cd_dep_employed_count = (int)(kTemp % (ds_key_t)CD_MAX_EMPLOYED);
	kTemp /= (ds_key_t)CD_MAX_EMPLOYED;
	r->cd_dep_college_count = (int)(kTemp % (ds_key_t)CD_MAX_COLLEGE);

	void *info = append_info_get(info_arr, CUSTOMER_DEMOGRAPHICS);
	append_row_start(info);

	append_key(info, r->cd_demo_sk);
	append_varchar(info, r->cd_gender);
	append_varchar(info, r->cd_marital_status);
	append_varchar(info, r->cd_education_status);
	append_integer(info, r->cd_purchase_estimate);
	append_varchar(info, r->cd_credit_rating);
	append_integer(info, r->cd_dep_count);
	append_integer(info, r->cd_dep_employed_count);
	append_integer(info, r->cd_dep_college_count);

	append_row_end(info);

	return 0;
}

// w_catalog_returns.cpp
#include <stdio.h>

struct W_CATALOG_RETURNS_TBL g_w_catalog_returns;
extern struct W_CATALOG_SALES_TBL g_w_catalog_sales;

/*
 * Routine: mk_catalog_returns()
 * Purpose: populate a return fact *sync'd with a sales fact*
 * Algorithm: Since the returns need to be in line with a prior sale, they need
 *	to use the output of the mk_catalog_sales() routine, and then add
 *return-related information Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO:
 * 20020902 jms Need to link call center to date/time of return
 * 20031023 jms removed ability for stand alone generation
 */
int mk_w_catalog_returns(void *row, ds_key_t index) {
	int res = 0;

	static decimal_t dHundred;
	int nTemp;
	struct W_CATALOG_RETURNS_TBL *r;
	struct W_CATALOG_SALES_TBL *sale = &g_w_catalog_sales;
	static int bStandAlone = 0;
	tdef *pTdef = getSimpleTdefsByNumber(CATALOG_RETURNS);

	if (row == NULL)
		r = &g_w_catalog_returns;
	else
		r = (W_CATALOG_RETURNS_TBL *)row;

	if (!InitConstants::mk_w_catalog_returns_init) {
		strtodec(&dHundred, "100.00");
		InitConstants::mk_w_catalog_returns_init = 1;
	}

	/* if we were not called from the parent table's mk_xxx routine, then
	 * move to a parent row that needs to be returned, and generate it
	 */
	nullSet(&pTdef->kNullBitMap, CR_NULLS);
	if (bStandAlone) {
		genrand_integer(&nTemp, DIST_UNIFORM, 0, 99, 0, CR_IS_RETURNED);
		if (nTemp >= CR_RETURN_PCT) {
			row_skip(CATALOG_SALES, 1);
			return (1);
		}
		mk_w_catalog_sales(&g_w_catalog_sales, index);
	}

	/*
	 * Some of the information in the return is taken from the original sale
	 * which has been regenerated
	 */
	r->cr_item_sk = sale->cs_sold_item_sk;
	r->cr_catalog_page_sk = sale->cs_catalog_page_sk;
	r->cr_order_number = sale->cs_order_number;
	memcpy(&r->cr_pricing, &sale->cs_pricing, sizeof(ds_pricing_t));
	r->cr_refunded_customer_sk = sale->cs_bill_customer_sk;
	r->cr_refunded_cdemo_sk = sale->cs_bill_cdemo_sk;
	r->cr_refunded_hdemo_sk = sale->cs_bill_hdemo_sk;
	r->cr_refunded_addr_sk = sale->cs_bill_addr_sk;
	r->cr_call_center_sk = sale->cs_call_center_sk;

	/*
	 * some of the fields are conditionally taken from the sale
	 */
	r->cr_returning_customer_sk = mk_join(CR_RETURNING_CUSTOMER_SK, CUSTOMER, 2);
	r->cr_returning_cdemo_sk = mk_join(CR_RETURNING_CDEMO_SK, CUSTOMER_DEMOGRAPHICS, 2);
	r->cr_returning_hdemo_sk = mk_join(CR_RETURNING_HDEMO_SK, HOUSEHOLD_DEMOGRAPHICS, 2);
	r->cr_returning_addr_sk = mk_join(CR_RETURNING_ADDR_SK, CUSTOMER_ADDRESS, 2);
	if (genrand_integer(NULL, DIST_UNIFORM, 0, 99, 0, CR_RETURNING_CUSTOMER_SK) < CS_GIFT_PCT) {
		r->cr_returning_customer_sk = sale->cs_ship_customer_sk;
		r->cr_returning_cdemo_sk = sale->cs_ship_cdemo_sk;
		/* cr_returning_hdemo_sk removed, since it doesn't exist on the sales
		 * record */
		r->cr_returning_addr_sk = sale->cs_ship_addr_sk;
	}

	/**
	 * the rest of the columns are generated for this specific return
	 */
	/* the items cannot be returned until they are shipped; offset is handled in
	 * mk_join, based on sales date */
	r->cr_returned_date_sk = mk_join(CR_RETURNED_DATE_SK, DATET, sale->cs_ship_date_sk);

	/* the call center determines the time of the return */
	r->cr_returned_time_sk = mk_join(CR_RETURNED_TIME_SK, TIME, 1);

	r->cr_ship_mode_sk = mk_join(CR_SHIP_MODE_SK, SHIP_MODE, 1);
	r->cr_warehouse_sk = mk_join(CR_WAREHOUSE_SK, WAREHOUSE, 1);
	r->cr_reason_sk = mk_join(CR_REASON_SK, REASON, 1);
	if (sale->cs_pricing.quantity != -1)
		genrand_integer(&r->cr_pricing.quantity, DIST_UNIFORM, 1, sale->cs_pricing.quantity, 0, CR_PRICING);
	else
		r->cr_pricing.quantity = -1;
	set_pricing(CR_PRICING, &r->cr_pricing);

	return (res);
}

// w_call_center.cpp
namespace w_call_center {


#include <assert.h>
#include <stdio.h>
#include <string.h>

struct CALL_CENTER_TBL g_w_call_center;
static struct CALL_CENTER_TBL g_OldValues;

/*
 * Routine: mk_w_call_center()
 * Purpose:
 * Algorithm:
 * Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO:
 * 20020830 jms Need to populate open and close dates
 */
int mk_w_call_center(void *info_arr, ds_key_t index) {
	static int32_t jDateStart, nDaysPerRevision;
	int32_t nSuffix, bFirstRecord = 0, nFieldChangeFlags, jDateEnd, nDateRange;
	char *cp, *sName1, *sName2;
	static decimal_t dMinTaxPercentage, dMaxTaxPercentage;
	tdef *pTdef = getSimpleTdefsByNumber(CALL_CENTER);

	/* begin locals declarations */
	date_t dTemp;
	static double nScale;
	struct CALL_CENTER_TBL *r, *rOldValues = &g_OldValues;

	r = &g_w_call_center;

	if (!InitConstants::mk_w_call_center_init) {
		/* begin locals allocation/initialization */
		strtodt(&dTemp, DATA_START_DATE);
		jDateStart = dttoj(&dTemp) - WEB_SITE;
		strtodt(&dTemp, DATA_END_DATE);
		jDateEnd = dttoj(&dTemp);
		nDateRange = jDateEnd - jDateStart + 1;
		nDaysPerRevision = nDateRange / pTdef->nParam + 1;
		nScale = get_dbl("SCALE");

		/* these fields need to be handled as part of SCD code or further
		 * definition */
		r->cc_division_id = -1;
		r->cc_closed_date_id = -1;
		strcpy(r->cc_division_name, "No Name");

		strtodec(&dMinTaxPercentage, MIN_CC_TAX_PERCENTAGE);
		strtodec(&dMaxTaxPercentage, MAX_CC_TAX_PERCENTAGE);
		InitConstants::mk_w_call_center_init = 1;
	}

	nullSet(&pTdef->kNullBitMap, CC_NULLS);
	r->cc_call_center_sk = index;

	/* if we have generated the required history for this business key and
	 * generate a new one then reset associate fields (e.g., rec_start_date
	 * minimums)
	 */
	if (setSCDKeys(CC_CALL_CENTER_ID, index, r->cc_call_center_id, &r->cc_rec_start_date_id, &r->cc_rec_end_date_id)) {
		r->cc_open_date_id = jDateStart - genrand_integer(NULL, DIST_UNIFORM, -365, 0, 0, CC_OPEN_DATE_ID);

		/*
		 * some fields are not changed, even when a new version of the row is
		 * written
		 */
		nSuffix = (int)index / distsize("call_centers");
		dist_member(&cp, "call_centers", (int)(index % distsize("call_centers")) + 1, 1);
		if (nSuffix > 0)
			sprintf(r->cc_name, "%s_%d", cp, nSuffix);
		else
			strcpy(r->cc_name, cp);

		mk_address(&r->cc_address, CC_ADDRESS);
		bFirstRecord = 1;
	}

	/*
	 * this is  where we select the random number that controls if a field
	 * changes from one record to the next.
	 */
	nFieldChangeFlags = next_random(CC_SCD);

	/* the rest of the record in a history-keeping dimension can either be a new
	 * data value or not; use a random number and its bit pattern to determine
	 * which fields to replace and which to retain
	 */
	pick_distribution(&r->cc_class, "call_center_class", 1, 1, CC_CLASS);
	changeSCD(SCD_PTR, &r->cc_class, &rOldValues->cc_class, &nFieldChangeFlags, bFirstRecord);

	genrand_integer(&r->cc_employees, DIST_UNIFORM, 1, nScale >= 1 ? int(CC_EMPLOYEE_MAX * nScale * nScale) : int(CC_EMPLOYEE_MAX), 0, CC_EMPLOYEES);
	changeSCD(SCD_INT, &r->cc_employees, &rOldValues->cc_employees, &nFieldChangeFlags, bFirstRecord);

	genrand_integer(&r->cc_sq_ft, DIST_UNIFORM, 100, 700, 0, CC_SQ_FT);
	r->cc_sq_ft *= r->cc_employees;
	changeSCD(SCD_INT, &r->cc_sq_ft, &rOldValues->cc_sq_ft, &nFieldChangeFlags, bFirstRecord);

	pick_distribution(&r->cc_hours, "call_center_hours", 1, 1, CC_HOURS);
	changeSCD(SCD_PTR, &r->cc_hours, &rOldValues->cc_hours, &nFieldChangeFlags, bFirstRecord);

	pick_distribution(&sName1, "first_names", 1, 1, CC_MANAGER);
	pick_distribution(&sName2, "last_names", 1, 1, CC_MANAGER);
	sprintf(&r->cc_manager[0], "%s %s", sName1, sName2);
	changeSCD(SCD_CHAR, &r->cc_manager, &rOldValues->cc_manager, &nFieldChangeFlags, bFirstRecord);

	genrand_integer(&r->cc_market_id, DIST_UNIFORM, 1, 6, 0, CC_MARKET_ID);
	changeSCD(SCD_INT, &r->cc_market_id, &rOldValues->cc_market_id, &nFieldChangeFlags, bFirstRecord);

	gen_text(r->cc_market_class, 20, RS_CC_MARKET_CLASS, CC_MARKET_CLASS);
	changeSCD(SCD_CHAR, &r->cc_market_class, &rOldValues->cc_market_class, &nFieldChangeFlags, bFirstRecord);

	gen_text(r->cc_market_desc, 20, RS_CC_MARKET_DESC, CC_MARKET_DESC);
	changeSCD(SCD_CHAR, &r->cc_market_desc, &rOldValues->cc_market_desc, &nFieldChangeFlags, bFirstRecord);

	pick_distribution(&sName1, "first_names", 1, 1, CC_MARKET_MANAGER);
	pick_distribution(&sName2, "last_names", 1, 1, CC_MARKET_MANAGER);
	sprintf(&r->cc_market_manager[0], "%s %s", sName1, sName2);
	changeSCD(SCD_CHAR, &r->cc_market_manager, &rOldValues->cc_market_manager, &nFieldChangeFlags, bFirstRecord);

	genrand_integer(&r->cc_company, DIST_UNIFORM, 1, 6, 0, CC_COMPANY);
	changeSCD(SCD_INT, &r->cc_company, &rOldValues->cc_company, &nFieldChangeFlags, bFirstRecord);

	genrand_integer(&r->cc_division_id, DIST_UNIFORM, 1, 6, 0, CC_COMPANY);
	changeSCD(SCD_INT, &r->cc_division_id, &rOldValues->cc_division_id, &nFieldChangeFlags, bFirstRecord);

	mk_word(r->cc_division_name, "syllables", r->cc_division_id, RS_CC_DIVISION_NAME, CC_DIVISION_NAME);
	changeSCD(SCD_CHAR, &r->cc_division_name, &rOldValues->cc_division_name, &nFieldChangeFlags, bFirstRecord);

	mk_companyname(r->cc_company_name, CC_COMPANY_NAME, r->cc_company);
	changeSCD(SCD_CHAR, &r->cc_company_name, &rOldValues->cc_company_name, &nFieldChangeFlags, bFirstRecord);

	genrand_decimal(&r->cc_tax_percentage, DIST_UNIFORM, &dMinTaxPercentage, &dMaxTaxPercentage, NULL,
	                CC_TAX_PERCENTAGE);
	changeSCD(SCD_DEC, &r->cc_tax_percentage, &rOldValues->cc_tax_percentage, &nFieldChangeFlags, bFirstRecord);

	// append the newly created row
	char szTemp[128];

	void *info = append_info_get(info_arr, CALL_CENTER);

	append_row_start(info);

	append_key(info, r->cc_call_center_sk);
	append_varchar(info, r->cc_call_center_id);
	append_date(info, r->cc_rec_start_date_id);
	append_date(info, r->cc_rec_end_date_id);
	append_key(info, r->cc_closed_date_id);
	append_key(info, r->cc_open_date_id);
	append_varchar(info, r->cc_name);
	append_varchar(info, &r->cc_class[0]);
	append_integer(info, r->cc_employees);
	append_integer(info, r->cc_sq_ft);
	append_varchar(info, r->cc_hours);
	append_varchar(info, &r->cc_manager[0]);
	append_integer(info, r->cc_market_id);
	append_varchar(info, &r->cc_market_class[0]);
	append_varchar(info, &r->cc_market_desc[0]);
	append_varchar(info, &r->cc_market_manager[0]);
	append_integer(info, r->cc_division_id);
	append_varchar(info, &r->cc_division_name[0]);
	append_integer(info, r->cc_company);
	append_varchar(info, &r->cc_company_name[0]);
	append_integer(info, r->cc_address.street_num);

	if (r->cc_address.street_name2) {
		sprintf(szTemp, "%s %s", r->cc_address.street_name1, r->cc_address.street_name2);
		append_varchar(info, szTemp);
	} else {
		append_varchar(info, r->cc_address.street_name1);
	}

	append_varchar(info, r->cc_address.street_type);
	append_varchar(info, &r->cc_address.suite_num[0]);
	append_varchar(info, r->cc_address.city);
	append_varchar(info, r->cc_address.county);
	append_varchar(info, r->cc_address.state);
	sprintf(szTemp, "%05d", r->cc_address.zip);
	append_varchar(info, szTemp);
	append_varchar(info, &r->cc_address.country[0]);
	append_integer(info, r->cc_address.gmt_offset);
	append_decimal(info, &r->cc_tax_percentage);

	append_row_end(info);

	return 0;
}
}

// pricing.cpp
#include <stdio.h>

#define MAX_LIMIT 12
static ds_limits_t aPriceLimits[MAX_LIMIT] = {
    {CS_PRICING, CS_QUANTITY_MAX, CS_MARKUP_MAX, CS_DISCOUNT_MAX, CS_WHOLESALE_MAX, CS_COUPON_MAX},
    {SS_PRICING, SS_QUANTITY_MAX, SS_MARKUP_MAX, SS_DISCOUNT_MAX, SS_WHOLESALE_MAX, SS_COUPON_MAX},
    {WS_PRICING, WS_QUANTITY_MAX, WS_MARKUP_MAX, WS_DISCOUNT_MAX, WS_WHOLESALE_MAX, WS_COUPON_MAX},
    {CR_PRICING, CS_QUANTITY_MAX, CS_MARKUP_MAX, CS_DISCOUNT_MAX, CS_WHOLESALE_MAX, CS_COUPON_MAX},
    {SR_PRICING, SS_QUANTITY_MAX, SS_MARKUP_MAX, SS_DISCOUNT_MAX, SS_WHOLESALE_MAX, SS_COUPON_MAX},
    {WR_PRICING, WS_QUANTITY_MAX, WS_MARKUP_MAX, WS_DISCOUNT_MAX, WS_WHOLESALE_MAX, WS_COUPON_MAX},
    {S_PLINE_PRICING, WS_QUANTITY_MAX, WS_MARKUP_MAX, WS_DISCOUNT_MAX, WS_WHOLESALE_MAX, WS_COUPON_MAX},
    {S_CLIN_PRICING, WS_QUANTITY_MAX, WS_MARKUP_MAX, WS_DISCOUNT_MAX, WS_WHOLESALE_MAX, WS_COUPON_MAX},
    {S_WLIN_PRICING, WS_QUANTITY_MAX, WS_MARKUP_MAX, WS_DISCOUNT_MAX, WS_WHOLESALE_MAX, WS_COUPON_MAX},
    {S_SRET_PRICING, WS_QUANTITY_MAX, WS_MARKUP_MAX, WS_DISCOUNT_MAX, WS_WHOLESALE_MAX, WS_COUPON_MAX},
    {S_CRET_PRICING, WS_QUANTITY_MAX, WS_MARKUP_MAX, WS_DISCOUNT_MAX, WS_WHOLESALE_MAX, WS_COUPON_MAX},
    {S_WRET_PRICING, WS_QUANTITY_MAX, WS_MARKUP_MAX, WS_DISCOUNT_MAX, WS_WHOLESALE_MAX, WS_COUPON_MAX}

};

/*
 * Routine: set_pricing(int nTabId, ds_pricing_t *pPricing)
 * Purpose: handle the various pricing calculations for the fact tables
 * Notes:
 *	the RNG usage is not kept in sync between sales pricing and returns pricing.
 *If the calculations look wrong, it may be necessary to "waste" some RNG calls
 *on one side or the other to bring things back in line Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO: None
 */
void set_pricing(int nTabId, ds_pricing_t *pPricing) {
	static int nLastId = -1, nQuantityMax, nQuantityMin = 1;
	static decimal_t dQuantity, dMarkupMin, dDiscountMin, dWholesaleMin, dMarkupMax, dDiscountMax, dWholesaleMax,
	    dCouponMin, dCouponMax, dZero, dOneHalf, d9pct, dOne, dTemp, dHundred;
	decimal_t dMarkup, dCoupon, dShipping, dDiscount, dTemp2;
	int i, nCashPct, nCreditPct, nCouponUsage;

	if (!InitConstants::set_pricing_init) {
		strtodec(&dMarkupMin, "0.00");
		strtodec(&dDiscountMin, "0.00");
		strtodec(&dWholesaleMin, "1.00");
		strtodec(&dCouponMin, "0.00");
		strtodec(&dZero, "0.00");
		strtodec(&dOneHalf, "0.50");
		strtodec(&d9pct, "0.09");
		strtodec(&dWholesaleMin, "1.00");
		strtodec(&dHundred, "100.00");
		strtodec(&dOne, "1.00");

		InitConstants::set_pricing_init = 1;
	}

	if (nTabId != nLastId) {
		nLastId = -1;
		for (i = 0; i < MAX_LIMIT; i++) {
			if (nTabId == aPriceLimits[i].nId)
				nLastId = i;
		}
		if (nLastId == -1)
			INTERNAL("No pricing limits defined");
		nQuantityMax = atoi(aPriceLimits[nLastId].szQuantity);
		strtodec(&dDiscountMax, aPriceLimits[nLastId].szDiscount);
		strtodec(&dMarkupMax, aPriceLimits[nLastId].szMarkUp);
		strtodec(&dWholesaleMax, aPriceLimits[nLastId].szWholesale);
		strtodec(&dCouponMax, aPriceLimits[nLastId].szCoupon);
	}

	switch (nTabId) {
	case SS_PRICING:
	case CS_PRICING:
	case WS_PRICING:
	case S_PLINE_PRICING:
	case S_CLIN_PRICING:
	case S_WLIN_PRICING:
		genrand_integer(&pPricing->quantity, DIST_UNIFORM, nQuantityMin, nQuantityMax, 0, nTabId);
		itodec(&dQuantity, pPricing->quantity);
		genrand_decimal(&pPricing->wholesale_cost, DIST_UNIFORM, &dWholesaleMin, &dWholesaleMax, NULL, nTabId);

		/* ext_wholesale_cost = wholesale_cost * quantity */
		decimal_t_op(&pPricing->ext_wholesale_cost, OP_MULT, &dQuantity, &pPricing->wholesale_cost);

		/* list_price = wholesale_cost * (1 + markup) */
		genrand_decimal(&dMarkup, DIST_UNIFORM, &dMarkupMin, &dMarkupMax, NULL, nTabId);
		decimal_t_op(&dMarkup, OP_PLUS, &dMarkup, &dOne);
		decimal_t_op(&pPricing->list_price, OP_MULT, &pPricing->wholesale_cost, &dMarkup);

		/* sales_price = list_price * (1 - discount)*/
		genrand_decimal(&dDiscount, DIST_UNIFORM, &dDiscountMin, &dDiscountMax, NULL, nTabId);
		NegateDecimal(&dDiscount);
		decimal_t_op(&pPricing->ext_discount_amt, OP_PLUS, &dDiscount, &dOne);
		decimal_t_op(&pPricing->sales_price, OP_MULT, &pPricing->list_price, &pPricing->ext_discount_amt);

		/* ext_list_price = list_price * quantity */
		decimal_t_op(&pPricing->ext_list_price, OP_MULT, &pPricing->list_price, &dQuantity);

		/* ext_sales_price = sales_price * quantity */
		decimal_t_op(&pPricing->ext_sales_price, OP_MULT, &pPricing->sales_price, &dQuantity);

		/* ext_discount_amt = ext_list_price - ext_sales_price */
		decimal_t_op(&pPricing->ext_discount_amt, OP_MINUS, &pPricing->ext_list_price, &pPricing->ext_sales_price);

		/* coupon_amt = ext_sales_price * coupon */
		genrand_decimal(&dCoupon, DIST_UNIFORM, &dZero, &dOne, NULL, nTabId);
		genrand_integer(&nCouponUsage, DIST_UNIFORM, 1, 100, 0, nTabId);
		if (nCouponUsage <= 20) /* 20% of sales employ a coupon */
			decimal_t_op(&pPricing->coupon_amt, OP_MULT, &pPricing->ext_sales_price, &dCoupon);
		else
			memcpy(&pPricing->coupon_amt, &dZero, sizeof(decimal_t));

		/* net_paid = ext_sales_price - coupon_amt */
		decimal_t_op(&pPricing->net_paid, OP_MINUS, &pPricing->ext_sales_price, &pPricing->coupon_amt);

		/* shipping_cost = list_price * shipping */
		genrand_decimal(&dShipping, DIST_UNIFORM, &dZero, &dOneHalf, NULL, nTabId);
		decimal_t_op(&pPricing->ship_cost, OP_MULT, &pPricing->list_price, &dShipping);

		/* ext_shipping_cost = shipping_cost * quantity */
		decimal_t_op(&pPricing->ext_ship_cost, OP_MULT, &pPricing->ship_cost, &dQuantity);

		/* net_paid_inc_ship = net_paid + ext_shipping_cost */
		decimal_t_op(&pPricing->net_paid_inc_ship, OP_PLUS, &pPricing->net_paid, &pPricing->ext_ship_cost);

		/* ext_tax = tax * net_paid */
		genrand_decimal(&pPricing->tax_pct, DIST_UNIFORM, &dZero, &d9pct, NULL, nTabId);
		decimal_t_op(&pPricing->ext_tax, OP_MULT, &pPricing->net_paid, &pPricing->tax_pct);

		/* net_paid_inc_tax = net_paid + ext_tax */
		decimal_t_op(&pPricing->net_paid_inc_tax, OP_PLUS, &pPricing->net_paid, &pPricing->ext_tax);

		/* net_paid_inc_ship_tax = net_paid_inc_tax + ext_shipping_cost */
		decimal_t_op(&pPricing->net_paid_inc_ship_tax, OP_PLUS, &pPricing->net_paid_inc_ship, &pPricing->ext_tax);

		/* net_profit = net_paid - ext_wholesale_cost */
		decimal_t_op(&pPricing->net_profit, OP_MINUS, &pPricing->net_paid, &pPricing->ext_wholesale_cost);
		break;
	case CR_PRICING:
	case SR_PRICING:
	case WR_PRICING:
		/* quantity is determined before we are called */
		/* ext_wholesale_cost = wholesale_cost * quantity */
		itodec(&dQuantity, pPricing->quantity);
		decimal_t_op(&pPricing->ext_wholesale_cost, OP_MULT, &dQuantity, &pPricing->wholesale_cost);

		/* ext_list_price = list_price * quantity */
		decimal_t_op(&pPricing->ext_list_price, OP_MULT, &pPricing->list_price, &dQuantity);

		/* ext_sales_price = sales_price * quantity */
		decimal_t_op(&pPricing->ext_sales_price, OP_MULT, &pPricing->sales_price, &dQuantity);

		/* net_paid = ext_list_price (couppons don't effect returns) */
		memcpy(&pPricing->net_paid, &pPricing->ext_sales_price, sizeof(decimal_t));

		/* shipping_cost = list_price * shipping */
		genrand_decimal(&dShipping, DIST_UNIFORM, &dZero, &dOneHalf, NULL, nTabId);
		decimal_t_op(&pPricing->ship_cost, OP_MULT, &pPricing->list_price, &dShipping);

		/* ext_shipping_cost = shipping_cost * quantity */
		decimal_t_op(&pPricing->ext_ship_cost, OP_MULT, &pPricing->ship_cost, &dQuantity);

		/* net_paid_inc_ship = net_paid + ext_shipping_cost */
		decimal_t_op(&pPricing->net_paid_inc_ship, OP_PLUS, &pPricing->net_paid, &pPricing->ext_ship_cost);

		/* ext_tax = tax * net_paid */
		decimal_t_op(&pPricing->ext_tax, OP_MULT, &pPricing->net_paid, &pPricing->tax_pct);

		/* net_paid_inc_tax = net_paid + ext_tax */
		decimal_t_op(&pPricing->net_paid_inc_tax, OP_PLUS, &pPricing->net_paid, &pPricing->ext_tax);

		/* net_paid_inc_ship_tax = net_paid_inc_tax + ext_shipping_cost */
		decimal_t_op(&pPricing->net_paid_inc_ship_tax, OP_PLUS, &pPricing->net_paid_inc_ship, &pPricing->ext_tax);

		/* net_profit = net_paid - ext_wholesale_cost */
		decimal_t_op(&pPricing->net_profit, OP_MINUS, &pPricing->net_paid, &pPricing->ext_wholesale_cost);

		/* see to it that the returned amounts add up to the total returned */
		/* allocate some of return to cash */
		genrand_integer(&nCashPct, DIST_UNIFORM, 0, 100, 0, nTabId);
		itodec(&dTemp, nCashPct);
		decimal_t_op(&pPricing->refunded_cash, OP_DIV, &dTemp, &dHundred);
		decimal_t_op(&pPricing->refunded_cash, OP_MULT, &pPricing->refunded_cash, &pPricing->net_paid);

		/* allocate some to reversed charges */
		genrand_integer(&nCreditPct, DIST_UNIFORM, 1, 100, 0, nTabId);
		itodec(&dTemp2, nCreditPct);
		decimal_t_op(&dTemp, OP_DIV, &dTemp2, &dHundred);
		decimal_t_op(&dTemp2, OP_MINUS, &pPricing->net_paid, &pPricing->refunded_cash);
		decimal_t_op(&pPricing->reversed_charge, OP_MULT, &dTemp2, &dTemp);

		/* the rest is store credit */
		decimal_t_op(&pPricing->store_credit, OP_MINUS, &pPricing->net_paid, &pPricing->reversed_charge);
		decimal_t_op(&pPricing->store_credit, OP_MINUS, &pPricing->store_credit, &pPricing->refunded_cash);

		/* pick a fee for the return */
		genrand_decimal(&pPricing->fee, DIST_UNIFORM, &dOneHalf, &dHundred, &dZero, nTabId);

		/* and calculate the net effect */
		decimal_t_op(&pPricing->net_loss, OP_MINUS, &pPricing->net_paid_inc_ship_tax, &pPricing->store_credit);
		decimal_t_op(&pPricing->net_loss, OP_MINUS, &pPricing->net_loss, &pPricing->refunded_cash);
		decimal_t_op(&pPricing->net_loss, OP_MINUS, &pPricing->net_loss, &pPricing->reversed_charge);
		decimal_t_op(&pPricing->net_loss, OP_PLUS, &pPricing->net_loss, &pPricing->fee);
		break;
	}

	return;
}

// w_web_sales.cpp
namespace w_web_sales {


#include <stdio.h>

struct W_WEB_SALES_TBL g_w_web_sales;
ds_key_t skipDays(int nTable, ds_key_t *pRemainder);

static ds_key_t kNewDateIndex = 0;
static ds_key_t jDate;
static int nItemIndex = 0;

/*
 * the validation process requires generating a single lineitem
 * so the main mk_xxx routine has been split into a master record portion
 * and a detail/lineitem portion.
 */
static void mk_master(void *info_arr, ds_key_t index) {
	static decimal_t dMin, dMax;
	int nGiftPct;
	struct W_WEB_SALES_TBL *r;
	static int nItemCount;

	r = &g_w_web_sales;

	if (!InitConstants::mk_master_init) {
		strtodec(&dMin, "1.00");
		strtodec(&dMax, "100000.00");
		jDate = skipDays(WEB_SALES, &kNewDateIndex);
		nItemCount = (int)getIDCount(ITEM);
		InitConstants::mk_master_init = 1;
	}

	/***
	 * some attributes reamin the same for each lineitem in an order; others are
	 * different for each lineitem. Since the number of lineitems per order is
	 * static, we can use a modulo to determine when to change the semi-static
	 * values
	 */
	while (index > kNewDateIndex) /* need to move to a new date */
	{
		jDate += 1;
		kNewDateIndex += dateScaling(WEB_SALES, jDate);
	}

	r->ws_sold_date_sk = mk_join(WS_SOLD_DATE_SK, DATET, 1);
	r->ws_sold_time_sk = mk_join(WS_SOLD_TIME_SK, TIME, 1);
	r->ws_bill_customer_sk = mk_join(WS_BILL_CUSTOMER_SK, CUSTOMER, 1);
	r->ws_bill_cdemo_sk = mk_join(WS_BILL_CDEMO_SK, CUSTOMER_DEMOGRAPHICS, 1);
	r->ws_bill_hdemo_sk = mk_join(WS_BILL_HDEMO_SK, HOUSEHOLD_DEMOGRAPHICS, 1);
	r->ws_bill_addr_sk = mk_join(WS_BILL_ADDR_SK, CUSTOMER_ADDRESS, 1);

	/* most orders are for the ordering customers, some are not */
	genrand_integer(&nGiftPct, DIST_UNIFORM, 0, 99, 0, WS_SHIP_CUSTOMER_SK);
	if (nGiftPct > WS_GIFT_PCT) {
		r->ws_ship_customer_sk = mk_join(WS_SHIP_CUSTOMER_SK, CUSTOMER, 2);
		r->ws_ship_cdemo_sk = mk_join(WS_SHIP_CDEMO_SK, CUSTOMER_DEMOGRAPHICS, 2);
		r->ws_ship_hdemo_sk = mk_join(WS_SHIP_HDEMO_SK, HOUSEHOLD_DEMOGRAPHICS, 2);
		r->ws_ship_addr_sk = mk_join(WS_SHIP_ADDR_SK, CUSTOMER_ADDRESS, 2);
	} else {
		r->ws_ship_customer_sk = r->ws_bill_customer_sk;
		r->ws_ship_cdemo_sk = r->ws_bill_cdemo_sk;
		r->ws_ship_hdemo_sk = r->ws_bill_hdemo_sk;
		r->ws_ship_addr_sk = r->ws_bill_addr_sk;
	}

	r->ws_order_number = index;
	genrand_integer(&nItemIndex, DIST_UNIFORM, 1, nItemCount, 0, WS_ITEM_SK);

	return;
}

static void mk_detail(void *info_arr, int bPrint) {
	static int *pItemPermutation, nItemCount;
	struct W_WEB_SALES_TBL *r;
	int nShipLag, nTemp;
	struct W_WEB_RETURNS_TBL w_web_returns;
	tdef *pT = getSimpleTdefsByNumber(WEB_SALES);

	if (!InitConstants::mk_detail_init) {
		jDate = skipDays(WEB_SALES, &kNewDateIndex);
		pItemPermutation = makePermutation(NULL, nItemCount = (int)getIDCount(ITEM), WS_PERMUTATION);

		InitConstants::mk_detail_init = 1;
	}

	r = &g_w_web_sales;

	nullSet(&pT->kNullBitMap, WS_NULLS);

	/* orders are shipped some number of days after they are ordered,
	 * and not all lineitems ship at the same time
	 */
	genrand_integer(&nShipLag, DIST_UNIFORM, WS_MIN_SHIP_DELAY, WS_MAX_SHIP_DELAY, 0, WS_SHIP_DATE_SK);
	r->ws_ship_date_sk = r->ws_sold_date_sk + nShipLag;

	if (++nItemIndex > nItemCount)
		nItemIndex = 1;
	r->ws_item_sk = matchSCDSK(getPermutationEntry(pItemPermutation, nItemIndex), r->ws_sold_date_sk, ITEM);

	/* the web page needs to be valid for the sale date */
	r->ws_web_page_sk = mk_join(WS_WEB_PAGE_SK, WEB_PAGE, r->ws_sold_date_sk);
	r->ws_web_site_sk = mk_join(WS_WEB_SITE_SK, WEB_SITE, r->ws_sold_date_sk);

	r->ws_ship_mode_sk = mk_join(WS_SHIP_MODE_SK, SHIP_MODE, 1);
	r->ws_warehouse_sk = mk_join(WS_WAREHOUSE_SK, WAREHOUSE, 1);
	r->ws_promo_sk = mk_join(WS_PROMO_SK, PROMOTION, 1);
	set_pricing(WS_PRICING, &r->ws_pricing);

	/**
	 * having gone to the trouble to make the sale, now let's see if it gets
	 * returned
	 */
	genrand_integer(&nTemp, DIST_UNIFORM, 0, 99, 0, WR_IS_RETURNED);
	if (nTemp < WR_RETURN_PCT) {
		mk_w_web_returns(&w_web_returns, 1);

		struct W_WEB_RETURNS_TBL *rr = &w_web_returns;

		void *info = append_info_get(info_arr, WEB_RETURNS);
		append_row_start(info);

		append_key(info, rr->wr_returned_date_sk);
		append_key(info, rr->wr_returned_time_sk);
		append_key(info, rr->wr_item_sk);
		append_key(info, rr->wr_refunded_customer_sk);
		append_key(info, rr->wr_refunded_cdemo_sk);
		append_key(info, rr->wr_refunded_hdemo_sk);
		append_key(info, rr->wr_refunded_addr_sk);
		append_key(info, rr->wr_returning_customer_sk);
		append_key(info, rr->wr_returning_cdemo_sk);
		append_key(info, rr->wr_returning_hdemo_sk);
		append_key(info, rr->wr_returning_addr_sk);
		append_key(info, rr->wr_web_page_sk);
		append_key(info, rr->wr_reason_sk);
		append_key(info, rr->wr_order_number);
		append_integer(info, rr->wr_pricing.quantity);
		append_decimal(info, &rr->wr_pricing.net_paid);
		append_decimal(info, &rr->wr_pricing.ext_tax);
		append_decimal(info, &rr->wr_pricing.net_paid_inc_tax);
		append_decimal(info, &rr->wr_pricing.fee);
		append_decimal(info, &rr->wr_pricing.ext_ship_cost);
		append_decimal(info, &rr->wr_pricing.refunded_cash);
		append_decimal(info, &rr->wr_pricing.reversed_charge);
		append_decimal(info, &rr->wr_pricing.store_credit);
		append_decimal(info, &rr->wr_pricing.net_loss);

		append_row_end(info);
	}

	void *info = append_info_get(info_arr, WEB_SALES);
	append_row_start(info);

	append_key(info, r->ws_sold_date_sk);
	append_key(info, r->ws_sold_time_sk);
	append_key(info, r->ws_ship_date_sk);
	append_key(info, r->ws_item_sk);
	append_key(info, r->ws_bill_customer_sk);
	append_key(info, r->ws_bill_cdemo_sk);
	append_key(info, r->ws_bill_hdemo_sk);
	append_key(info, r->ws_bill_addr_sk);
	append_key(info, r->ws_ship_customer_sk);
	append_key(info, r->ws_ship_cdemo_sk);
	append_key(info, r->ws_ship_hdemo_sk);
	append_key(info, r->ws_ship_addr_sk);
	append_key(info, r->ws_web_page_sk);
	append_key(info, r->ws_web_site_sk);
	append_key(info, r->ws_ship_mode_sk);
	append_key(info, r->ws_warehouse_sk);
	append_key(info, r->ws_promo_sk);
	append_key(info, r->ws_order_number);
	append_integer(info, r->ws_pricing.quantity);
	append_decimal(info, &r->ws_pricing.wholesale_cost);
	append_decimal(info, &r->ws_pricing.list_price);
	append_decimal(info, &r->ws_pricing.sales_price);
	append_decimal(info, &r->ws_pricing.ext_discount_amt);
	append_decimal(info, &r->ws_pricing.ext_sales_price);
	append_decimal(info, &r->ws_pricing.ext_wholesale_cost);
	append_decimal(info, &r->ws_pricing.ext_list_price);
	append_decimal(info, &r->ws_pricing.ext_tax);
	append_decimal(info, &r->ws_pricing.coupon_amt);
	append_decimal(info, &r->ws_pricing.ext_ship_cost);
	append_decimal(info, &r->ws_pricing.net_paid);
	append_decimal(info, &r->ws_pricing.net_paid_inc_tax);
	append_decimal(info, &r->ws_pricing.net_paid_inc_ship);
	append_decimal(info, &r->ws_pricing.net_paid_inc_ship_tax);
	append_decimal(info, &r->ws_pricing.net_profit);

	append_row_end(info);

	return;
}

/*
 * mk_web_sales
 */
int mk_w_web_sales(void *info_arr, ds_key_t index) {
	int nLineitems, i;

	/* build the static portion of an order */
	mk_master(info_arr, index);

	/* set the number of lineitems and build them */
	genrand_integer(&nLineitems, DIST_UNIFORM, 8, 16, 9, WS_ORDER_NUMBER);
	for (i = 1; i <= nLineitems; i++) {
		mk_detail(info_arr, 1);
	}

	/**
	 * and finally return 1 since we have already printed the rows
	 */
	return 0;
}

/*
 * Routine:
 * Purpose:
 * Algorithm:
 * Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO: None
 */
int vld_web_sales(int nTable, ds_key_t kRow, int *Permutation) {
	int nLineitem, nMaxLineitem, i;

	row_skip(nTable, kRow - 1);
	row_skip(WEB_RETURNS, (kRow - 1));
	jDate = skipDays(WEB_SALES, &kNewDateIndex);
	mk_master(NULL, kRow);
	genrand_integer(&nMaxLineitem, DIST_UNIFORM, 8, 16, 9, WS_ORDER_NUMBER);
	genrand_integer(&nLineitem, DIST_UNIFORM, 1, nMaxLineitem, 0, WS_PRICING_QUANTITY);
	for (i = 1; i < nLineitem; i++) {
		mk_detail(NULL, 0);
	}
	mk_detail(NULL, 1);

	return (0);
}
}

// tdef_functions.cpp

table_func_t w_tdef_funcs[] = {{"call_center", mk_w_call_center, {NULL, NULL}, NULL},
                               {"catalog_page", mk_w_catalog_page, {NULL, NULL}, NULL},
                               {"catalog_returns", NULL, {NULL, NULL}, NULL},
                               {"catalog_sales", mk_w_catalog_sales, {NULL, NULL}, NULL},
                               {"customer", mk_w_customer, {NULL, NULL}, NULL},
                               {"customer_address", mk_w_customer_address, {NULL, NULL}, NULL},
                               {"customer_demographics", mk_w_customer_demographics, {NULL, NULL}, NULL},
                               {"date", mk_w_date, {NULL, NULL}, NULL},
                               {"household_demographics", mk_w_household_demographics, {NULL, NULL}, NULL},
                               {"income_band", mk_w_income_band, {NULL, NULL}, NULL},
                               {"inventory", mk_w_inventory, {NULL, NULL}, NULL},
                               {"item", mk_w_item, {NULL, NULL}, NULL},
                               {"promotion", mk_w_promotion, {NULL, NULL}, NULL},
                               {"reason", mk_w_reason, {NULL, NULL}, NULL},
                               {"ship_mode", mk_w_ship_mode, {NULL, NULL}, NULL},
                               {"store", mk_w_store, {NULL, NULL}, NULL},
                               {"store_returns", mk_w_store_returns, {NULL, NULL}, NULL},
                               {"store_sales", mk_w_store_sales, {NULL, NULL}, NULL},
                               {"time", mk_w_time, {NULL, NULL}, NULL},
                               {"warehouse", mk_w_warehouse, {NULL, NULL}, NULL},
                               {"web_page", mk_w_web_page, {NULL, NULL}, NULL},
                               {"web_returns", mk_w_web_returns, {NULL, NULL}, NULL},
                               {"web_sales", mk_w_web_sales, {NULL, NULL}, NULL},
                               {"web_site", mk_w_web_site, {NULL, NULL}, NULL},
                               {"dbgen_version", mk_dbgen_version, {NULL, NULL}, NULL},
                               {NULL}};

table_func_t *getTdefFunctionsByNumber(int nTable) {
	return (&w_tdef_funcs[nTable]);
}

// w_web_returns.cpp
#include <stdio.h>

struct W_WEB_RETURNS_TBL g_w_web_returns;
extern struct W_WEB_SALES_TBL g_w_web_sales;

/*
 * Routine: mk_web_returns()
 * Purpose: populate a return fact *sync'd with a sales fact*
 * Algorithm: Since the returns need to be in line with a prior sale, they are
 *built by a call from the mk_catalog_sales() routine, and then add
 *return-related information Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO: None
 */
int mk_w_web_returns(void *row, ds_key_t index) {
	int res = 0;

	static decimal_t dMin, dMax;
	static struct W_WEB_SALES_TBL *sale;
	struct W_WEB_RETURNS_TBL *r;
	tdef *pT = getSimpleTdefsByNumber(WEB_RETURNS);

	if (row == NULL)
		r = &g_w_web_returns;
	else
		r = (W_WEB_RETURNS_TBL *)row;

	if (!InitConstants::mk_w_web_returns_init) {
		strtodec(&dMin, "1.00");
		strtodec(&dMax, "100000.00");
		InitConstants::mk_w_web_returns_init = 1;
	}

	nullSet(&pT->kNullBitMap, WR_NULLS);

	/*
	 * Some of the information in the return is taken from the original sale
	 * which has been regenerated
	 */
	sale = &g_w_web_sales;
	r->wr_item_sk = sale->ws_item_sk;
	r->wr_order_number = sale->ws_order_number;
	memcpy((void *)&r->wr_pricing, (void *)&sale->ws_pricing, sizeof(ds_pricing_t));
	r->wr_web_page_sk = sale->ws_web_page_sk;

	/*
	 * the rest of the columns are generated for this specific return
	 */
	/* the items cannot be returned until they are shipped; offset is handled in
	 * mk_join, based on sales date */
	r->wr_returned_date_sk = mk_join(WR_RETURNED_DATE_SK, DATET, sale->ws_ship_date_sk);
	r->wr_returned_time_sk = mk_join(WR_RETURNED_TIME_SK, TIME, 1);

	/* most items are returned by the people they were shipped to, but some are
	 * returned by other folks
	 */
	r->wr_refunded_customer_sk = mk_join(WR_REFUNDED_CUSTOMER_SK, CUSTOMER, 1);
	r->wr_refunded_cdemo_sk = mk_join(WR_REFUNDED_CDEMO_SK, CUSTOMER_DEMOGRAPHICS, 1);
	r->wr_refunded_hdemo_sk = mk_join(WR_REFUNDED_HDEMO_SK, HOUSEHOLD_DEMOGRAPHICS, 1);
	r->wr_refunded_addr_sk = mk_join(WR_REFUNDED_ADDR_SK, CUSTOMER_ADDRESS, 1);
	if (genrand_integer(NULL, DIST_UNIFORM, 0, 99, 0, WR_RETURNING_CUSTOMER_SK) < WS_GIFT_PCT) {
		r->wr_refunded_customer_sk = sale->ws_ship_customer_sk;
		r->wr_refunded_cdemo_sk = sale->ws_ship_cdemo_sk;
		r->wr_refunded_hdemo_sk = sale->ws_ship_hdemo_sk;
		r->wr_refunded_addr_sk = sale->ws_ship_addr_sk;
	}
	r->wr_returning_customer_sk = r->wr_refunded_customer_sk;
	r->wr_returning_cdemo_sk = r->wr_refunded_cdemo_sk;
	r->wr_returning_hdemo_sk = r->wr_refunded_hdemo_sk;
	r->wr_returning_addr_sk = r->wr_refunded_addr_sk;

	r->wr_reason_sk = mk_join(WR_REASON_SK, REASON, 1);
	genrand_integer(&r->wr_pricing.quantity, DIST_UNIFORM, 1, sale->ws_pricing.quantity, 0, WR_PRICING);
	set_pricing(WR_PRICING, &r->wr_pricing);

	return (res);
}

// join.cpp
#include <stdio.h>

static ds_key_t web_join(int col, ds_key_t join_key);

/*
 * Routine: date_join(int from_tbl, int join_count)
 * Purpose: account for the different date-adjusted patterns in the data set
 * Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO: Relies on existing RNG code, which isn't really 64bit; will probably
 * requre a rework of the genrand_xx routines
 */
static ds_key_t date_join(int from_tbl, int from_col, ds_key_t join_count, int nYear) {
	int nDay, nTemp, nMin = -1, nMax = -1, nResult;
	static int jToday;
	date_t TempDate;

	if (InitConstants::date_join_init == 0) {
		strtodt(&TempDate, TODAYS_DATE);
		jToday = dttoj(&TempDate);
		InitConstants::date_join_init = 1;
	}

	switch (from_tbl) {
	case STORE_SALES:
	case CATALOG_SALES:
	case WEB_SALES:
		pick_distribution(&nDay, "calendar", 1, calendar_sales + is_leap(nYear), from_col);
		break;

	/*
	 * returns are keyed to the sale date, with the lag between sale and return
	 * selected within a known range, based on sales channel
	 */
	case STORE_RETURNS:
		nMin = SS_MIN_SHIP_DELAY;
		nMax = SS_MAX_SHIP_DELAY;
	case CATALOG_RETURNS:
		if (nMin == -1) {
			nMin = CS_MIN_SHIP_DELAY;
			nMax = CS_MAX_SHIP_DELAY;
		}
	case WEB_RETURNS:
		if (nMin == -1) {
			nMin = WS_MIN_SHIP_DELAY;
			nMax = WS_MAX_SHIP_DELAY;
		}
		genrand_integer(&nTemp, DIST_UNIFORM, nMin * 2, nMax * 2, 0, from_col);
		return (join_count + nTemp);
		break;
	case WEB_SITE:
	case WEB_PAGE:
		return (web_join(from_col, join_count));
	default:
		pick_distribution(&nDay, "calendar", 1, 1 + is_leap(nYear), from_col);
		break;
	}

	TempDate.year = nYear;
	TempDate.month = 1;
	TempDate.day = 1;

	nResult = dttoj(&TempDate) + nDay;

	return ((ds_key_t)(nResult > jToday) ? -1 : nResult);
}

/*
 * Routine: time_join(int from_tbl, int join_count)
 * Purpose: create joins that are time-skewed
 * Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO: Relies on existing RNG code, which isn't really 64bit; will probably
 * requre a rework of the genrand_xx routines
 */
static ds_key_t time_join(int to_tbl, int to_col, ds_key_t join_count) {
	int hour, secs;

	switch (to_tbl) {
	case STORE_SALES:
	case STORE_RETURNS:
		pick_distribution(&hour, "hours", 1, 2, to_col);
		break;
	case CATALOG_SALES:
	case WEB_SALES:
	case CATALOG_RETURNS:
	case WEB_RETURNS:
		pick_distribution(&hour, "hours", 1, 3, to_col);
		break;
	default:
		pick_distribution(&hour, "hours", 1, 1, to_col);
		break;
	}
	genrand_integer(&secs, DIST_UNIFORM, 0, 3599, 0, to_col);

	return ((ds_key_t)(hour * 3600 + secs));
}

/*
 * Routine: cp_join(int from_tbl, int join_count)
 * Purpose: create joins to catalog_page
 * Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO: None
 */
static ds_key_t cp_join(int tbl, int col, ds_key_t jDate) {
	ds_key_t res;
	static int nPagePerCatalog;
	int nType, nCount, nOffset, nPage;
	static date_t dTemp;
	char *szTemp;

	if (!InitConstants::cp_join_init) {
		nPagePerCatalog = ((int)get_rowcount(CATALOG_PAGE) / CP_CATALOGS_PER_YEAR) / (YEAR_MAXIMUM - YEAR_MINIMUM + 2);
		strtodt(&dTemp, DATA_START_DATE);
		InitConstants::cp_join_init = 1;
	}

	nType = pick_distribution(&szTemp, "catalog_page_type", 1, 2, col);
	genrand_integer(&nPage, DIST_UNIFORM, 1, nPagePerCatalog, 0, col);
	nOffset = (int)jDate - dTemp.julian - 1;
	nCount = (nOffset / 365) * CP_CATALOGS_PER_YEAR;
	nOffset %= 365;

	switch (nType) {
	case 1: /* bi-annual */
		if (nOffset > 183)
			nCount += 1;
		break;
	case 2: /* quarterly */
		nCount += (nOffset / 91);
		break;
	case 3: /* monthly */
		nCount += (nOffset / 31);
		break;
	}

	res = CP_SK(nCount, nPagePerCatalog, nPage);

	return (res);
}
/*
 * Routine:
 * Purpose:
 * Algorithm:
 * Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO: None
 */
ds_key_t getCatalogNumberFromPage(ds_key_t kPageNumber) {
	static int nPagePerCatalog;

	if (!InitConstants::getCatalogNumberFromPage_init) {
		nPagePerCatalog = ((int)get_rowcount(CATALOG_PAGE) / CP_CATALOGS_PER_YEAR) / (YEAR_MAXIMUM - YEAR_MINIMUM + 2);
		InitConstants::getCatalogNumberFromPage_init = 1;
	}

	return (kPageNumber / nPagePerCatalog);
}

/*
 * Routine: web_join(int col, ds_key_t join_key)
 * Purpose: create joins to web_site/web_page. These need to be handled
 *together, since the date of transaction must fit within the lifetime of a
 *particular page, which must fit within the lifetime of a particular site Data
 *Structures:
 *
 * Params:
 *	join_key is one of two things:
 *		1. the xxx_sk for a particular row in the dimension for which we need
 *appropriate dates
 *		2. a julian date for which we need to pick a valid xxx_sk value
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO: None
 */
static ds_key_t web_join(int col, ds_key_t join_key) {
	ds_key_t res = -1, kSite;
	static int nConcurrentSites, nSiteDuration, nOffset;
	static date_t dSiteOpen, /* open/close dates for current web site */
	    dSiteClose;
	int nTemp;
	tdef *pWS = getSimpleTdefsByNumber(WEB_SITE);
	tdef *pWP = getSimpleTdefsByNumber(WEB_PAGE);

	if (!InitConstants::web_join_init) {
		strtodt(&dSiteClose, WEB_END_DATE);
		nSiteDuration = dSiteClose.julian;
		nConcurrentSites = (int)get_rowcount(CONCURRENT_WEB_SITES);
		strtodt(&dSiteOpen, WEB_START_DATE);
		nSiteDuration -= dSiteOpen.julian;
		nSiteDuration *= nConcurrentSites;
		nOffset = (dSiteClose.julian - dSiteOpen.julian) / (2 * nSiteDuration);
		InitConstants::web_join_init = 1;
	}

	switch (col) {
		/**************
		 * join_key is the xxx_sk value for a dimension
		 */
	case WEB_OPEN_DATE:
		strtodt(&dSiteOpen, DATE_MINIMUM);
		res = dSiteOpen.julian - ((join_key * WEB_DATE_STAGGER) % nSiteDuration / 2);
		if (WEB_IS_REPLACED(join_key)) /* this site is completely replaced */
		{
			if (WEB_IS_REPLACEMENT(join_key)) /* this is the second site */
			{
				/* the open date of the second site needs to align on a revision
				 * boundary */
				res += nOffset * nSiteDuration;
			}
		}
		break;
	case WEB_CLOSE_DATE:
		strtodt(&dSiteOpen, DATE_MINIMUM);
		res = dSiteOpen.julian - ((join_key * WEB_DATE_STAGGER) % nSiteDuration / 2);
		res += pWS->nParam * nSiteDuration;
		if (WEB_IS_REPLACED(join_key)) /* this site is completely replaced */
		{
			if (!WEB_IS_REPLACEMENT(join_key)) /* this is the first site */
			{
				/* the close date of the first site needs to align on a revision
				 * boundary */
				res -= pWS->nParam * nSiteDuration / 2;
			}
		}
		break;
	case WEB_REC_START_DATE_ID:
		strtodt(&dSiteOpen, DATE_MINIMUM);
		res = dSiteOpen.julian - (((join_key - 1) * WEB_DATE_STAGGER) % nSiteDuration / 2);
		res += (join_key % pWS->nParam) * nSiteDuration;
		break;
	case WEB_REC_END_DATE_ID:
		strtodt(&dSiteOpen, DATE_MINIMUM);
		res = dSiteOpen.julian - ((join_key * WEB_DATE_STAGGER) % nSiteDuration / 2);
		res += ((join_key + 1) % pWS->nParam) * nSiteDuration * 5 - 1;
		break;
	case WP_REC_START_DATE_ID:
		strtodt(&dSiteOpen, DATE_MINIMUM);
		res = dSiteOpen.julian - (((join_key - 1) * WEB_DATE_STAGGER) % nSiteDuration / 2);
		res += (join_key % pWP->nParam) * nSiteDuration * 5;
		break;
	case WP_REC_END_DATE_ID:
		strtodt(&dSiteOpen, DATE_MINIMUM);
		res = dSiteOpen.julian - ((join_key * WEB_DATE_STAGGER) % nSiteDuration / 2);
		res += ((join_key + 1) % pWP->nParam) * nSiteDuration - 1;
		break;
	case WP_CREATION_DATE_SK:
		/* page creation has to happen outside of the page window, to assure a
		 * constant number of pages, so it occurs in the gap between site
		 * creation and the site's actual activity. For sites that are replaced
		 * in the time span of the data set, this will depend on whether they
		 * are the first version or the second
		 */
		strtodt(&dSiteOpen, DATE_MINIMUM);
		kSite = join_key / WEB_PAGES_PER_SITE + 1;
		res = dSiteOpen.julian - (((int)kSite * WEB_DATE_STAGGER) % nSiteDuration / 2);
		if (((int)kSite % pWP->nParam) == 0) /* this is a site that gets replaced */
		{
			genrand_integer(&nTemp, DIST_UNIFORM, (int)res, dSiteOpen.julian, 0, col);
			res = nTemp;
		}
		break;
		/*****************
		 * join key from here on is a date for which a valid site/page must be
		 * found the sk for a web page is a compound value: <site id><page id>
		 * and each component is a combination of the unique site or page and
		 * the active revision to it
		 */
	case WR_WEB_PAGE_SK:
	case WS_WEB_PAGE_SK:
		res = genrand_integer(NULL, DIST_UNIFORM, 1, WEB_PAGES_PER_SITE, 0, col);
		break;
	}

	return (res);
}

/*
 * Routine: mk_join(int from_tbl, int to_tbl, int join_count)
 * Purpose: return a primary key for to_tbl, creating a join between from_tbl
 *and to_tbl Algorithm: all joins are currently uniformly distributed. The
 *calling convention allows for each join in the schema to be distributed
 *differently Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO: Relies on existing RNG code, which isn't really 64bit; will probably
 *requre a rework of the genrand_xx routines
 */
ds_key_t mk_join(int from_col, int to_tbl, ds_key_t join_count) {
	ds_key_t res;
	int nYear, nFromTable = 0, nTableIndex = to_tbl;
	tdef *pTdef;

	nFromTable = getTableFromColumn(from_col);

	/*
	 * if the table being joined to employs sparse keys, the join gets handled
	 * in sparse.c
	 */
	pTdef = getSimpleTdefsByNumber(to_tbl);
	if (pTdef->flags & FL_SPARSE) {
		if (pTdef->arSparseKeys == NULL)
			initSparseKeys(to_tbl);
	}

	switch (to_tbl) {
	/* some tables require special handling */
	case CATALOG_PAGE:
		return (cp_join(nFromTable, from_col, join_count));
	case DATET:
		genrand_integer(&nYear, DIST_UNIFORM, YEAR_MINIMUM, YEAR_MAXIMUM, 0, from_col);
		return (date_join(nFromTable, from_col, join_count, nYear));
	case TIME:
		return (time_join(nFromTable, from_col, join_count));
		/* the rest of the tables use standard, uniform joins */
	default:
		/*
		 * all TYPE2 tables (i.e., history keeping dimensions) need a special
		 * join algorithm
		 */
		if (pTdef->flags & FL_TYPE_2)
			return (scd_join(nTableIndex, from_col, join_count));

		if (pTdef->flags & FL_SPARSE)
			return (randomSparseKey(nTableIndex, from_col));

		genrand_key(&res, DIST_UNIFORM, (ds_key_t)1, get_rowcount(nTableIndex), (ds_key_t)0, from_col);
		break;
	}

	return ((ds_key_t)res);
}

// tdefs.cpp
#include <stdio.h>

extern tdef w_tdefs[];
extern tdef s_tdefs[];
extern table_func_t s_tdef_funcs[];
extern table_func_t w_tdef_funcs[];

/*
 * Routine: get_rowcount(int table)
 * Purpose:
 * Algorithm:
 * Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO: None
 */
ds_key_t GetRowcountByName(char *szName) {
	int nTable = -1;

	nTable = GetTableNumber(szName);
	if (nTable >= 0)
		return (get_rowcount(nTable - 1));

	nTable = distsize(szName);
	return (nTable);
}

/*
 * Routine: GetTableNumber(char *szName)
 * Purpose: Return size of table, pseudo table or distribution
 * Algorithm: Need to use rowcount distribution, since argument could be a
 * pseudo table Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO: None
 */
int GetTableNumber(char *szName) {
	int i;
	char *szTable;

	for (i = 1; i <= distsize("rowcounts"); i++) {
		dist_member(&szTable, "rowcounts", i, 1);
		if (strcasecmp(szTable, szName) == 0)
			return (i - 1);
	}

	return (-1);
}

/*
 * Routine:
 * Purpose:
 * Algorithm:
 * Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO: None
 */
/*
tdef *
getTdefsByNumber(int nTable)
{
   if (is_set("UPDATE"))
   {
      if (s_tdefs[nTable].flags & FL_PASSTHRU)
      {
         switch(nTable + S_BRAND)
         {
         case S_CATALOG_PAGE: nTable = CATALOG_PAGE; break;
         case S_CUSTOMER_ADDRESS: nTable = CUSTOMER_ADDRESS; break;
         case S_PROMOTION: nTable = PROMOTION; break;
         }
         return(&w_tdefs[nTable]);
      }
      else
         return(&s_tdefs[nTable]);
   }
    else
        return(&w_tdefs[nTable]);
}
*/
tdef *getSimpleTdefsByNumber(int nTable) {
	if (nTable >= S_BRAND)
		return (&s_tdefs[nTable - S_BRAND]);
	return (&w_tdefs[nTable]);
}

tdef *getTdefsByNumber(int nTable) {
	if (is_set("UPDATE") && is_set("VALIDATE")) {
		if (s_tdefs[nTable].flags & FL_PASSTHRU) {
			switch (nTable + S_BRAND) {
			case S_CATALOG_PAGE:
				nTable = CATALOG_PAGE;
				break;
			case S_CUSTOMER_ADDRESS:
				nTable = CUSTOMER_ADDRESS;
				break;
			case S_PROMOTION:
				nTable = PROMOTION;
				break;
			}
			return (&w_tdefs[nTable]);
		} else
			return (&s_tdefs[nTable]);
	}

	return (getSimpleTdefsByNumber(nTable));
}

/*
 * Routine:
 * Purpose:
 * Algorithm:
 * Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO: None
 */
char *getTableNameByID(int i) {
	tdef *pT = getSimpleTdefsByNumber(i);

	return (pT->name);
}

/*
 * Routine:
 * Purpose:
 * Algorithm:
 * Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO: None
 */
int getTableFromColumn(int nColumn) {
	int i;
	tdef *pT;

	for (i = 0; i <= MAX_TABLE; i++) {
		pT = getSimpleTdefsByNumber(i);
		if ((nColumn >= pT->nFirstColumn) && (nColumn <= pT->nLastColumn))
			return (i);
	}
	return (-1);
}

// w_catalog_sales.cpp
namespace w_catalog_sales {


#include <stdio.h>

struct W_CATALOG_SALES_TBL g_w_catalog_sales;
ds_key_t skipDays(int nTable, ds_key_t *pRemainder);

static ds_key_t kNewDateIndex = 0;
static ds_key_t jDate;
static int nTicketItemBase = 1;
static int *pItemPermutation;
static int nItemCount;

/*
 * the validation process requires generating a single lineitem
 * so the main mk_xxx routine has been split into a master record portion
 * and a detail/lineitem portion.
 */
static void mk_master(void *info_arr, ds_key_t index) {
	static decimal_t dZero, dHundred, dOne, dOneHalf;
	int nGiftPct;
	struct W_CATALOG_SALES_TBL *r;

	r = &g_w_catalog_sales;

	if (!InitConstants::mk_master_catalog_sales_init) {
		strtodec(&dZero, "0.00");
		strtodec(&dHundred, "100.00");
		strtodec(&dOne, "1.00");
		strtodec(&dOneHalf, "0.50");
		jDate = skipDays(CATALOG_SALES, &kNewDateIndex);
		pItemPermutation = makePermutation(NULL, (nItemCount = (int)getIDCount(ITEM)), CS_PERMUTE);

		InitConstants::mk_master_catalog_sales_init = 1;
	}

	while (index > kNewDateIndex) /* need to move to a new date */
	{
		jDate += 1;
		kNewDateIndex += dateScaling(CATALOG_SALES, jDate);
	}

	/***
	 * some attributes remain the same for each lineitem in an order; others are
	 * different for each lineitem.
	 *
	 * Parallel generation causes another problem, since the values that get
	 * seeded may come from a prior row. If we are seeding at the start of a
	 * parallel chunk, hunt backwards in the RNG stream to find the most recent
	 * values that were used to set the values of the orderline-invariant
	 * columns
	 */

	r->cs_sold_date_sk = jDate;
	r->cs_sold_time_sk = mk_join(CS_SOLD_TIME_SK, TIME, r->cs_call_center_sk);
	r->cs_call_center_sk =
	    (r->cs_sold_date_sk == -1) ? -1 : mk_join(CS_CALL_CENTER_SK, CALL_CENTER, r->cs_sold_date_sk);

	r->cs_bill_customer_sk = mk_join(CS_BILL_CUSTOMER_SK, CUSTOMER, 1);
	r->cs_bill_cdemo_sk = mk_join(CS_BILL_CDEMO_SK, CUSTOMER_DEMOGRAPHICS, 1);
	r->cs_bill_hdemo_sk = mk_join(CS_BILL_HDEMO_SK, HOUSEHOLD_DEMOGRAPHICS, 1);
	r->cs_bill_addr_sk = mk_join(CS_BILL_ADDR_SK, CUSTOMER_ADDRESS, 1);

	/* most orders are for the ordering customers, some are not */
	genrand_integer(&nGiftPct, DIST_UNIFORM, 0, 99, 0, CS_SHIP_CUSTOMER_SK);
	if (nGiftPct <= CS_GIFT_PCT) {
		r->cs_ship_customer_sk = mk_join(CS_SHIP_CUSTOMER_SK, CUSTOMER, 2);
		r->cs_ship_cdemo_sk = mk_join(CS_SHIP_CDEMO_SK, CUSTOMER_DEMOGRAPHICS, 2);
		r->cs_ship_hdemo_sk = mk_join(CS_SHIP_HDEMO_SK, HOUSEHOLD_DEMOGRAPHICS, 2);
		r->cs_ship_addr_sk = mk_join(CS_SHIP_ADDR_SK, CUSTOMER_ADDRESS, 2);
	} else {
		r->cs_ship_customer_sk = r->cs_bill_customer_sk;
		r->cs_ship_cdemo_sk = r->cs_bill_cdemo_sk;
		r->cs_ship_hdemo_sk = r->cs_bill_hdemo_sk;
		r->cs_ship_addr_sk = r->cs_bill_addr_sk;
	}

	r->cs_order_number = index;
	genrand_integer(&nTicketItemBase, DIST_UNIFORM, 1, nItemCount, 0, CS_SOLD_ITEM_SK);

	return;
}

static void mk_detail(void *info_arr, int bPrint) {
	static decimal_t dZero, dHundred, dOne, dOneHalf;
	int nShipLag, nTemp;
	ds_key_t kItem;
	static ds_key_t kNewDateIndex = 0;
	static ds_key_t jDate;
	struct W_CATALOG_SALES_TBL *r;
	tdef *pTdef = getSimpleTdefsByNumber(CATALOG_SALES);

	r = &g_w_catalog_sales;

	if (!InitConstants::mk_detail_catalog_sales_init) {
		strtodec(&dZero, "0.00");
		strtodec(&dHundred, "100.00");
		strtodec(&dOne, "1.00");
		strtodec(&dOneHalf, "0.50");
		jDate = skipDays(CATALOG_SALES, &kNewDateIndex);

		InitConstants::mk_detail_catalog_sales_init = 1;
	}

	nullSet(&pTdef->kNullBitMap, CS_NULLS);

	/* orders are shipped some number of days after they are ordered */
	genrand_integer(&nShipLag, DIST_UNIFORM, CS_MIN_SHIP_DELAY, CS_MAX_SHIP_DELAY, 0, CS_SHIP_DATE_SK);
	r->cs_ship_date_sk = (r->cs_sold_date_sk == -1) ? -1 : r->cs_sold_date_sk + nShipLag;

	/*
	 * items need to be unique within an order
	 * use a sequence within the permutation
	 * NB: Permutations are 1-based
	 */
	if (++nTicketItemBase > nItemCount)
		nTicketItemBase = 1;
	kItem = getPermutationEntry(pItemPermutation, nTicketItemBase);
	r->cs_sold_item_sk = matchSCDSK(kItem, r->cs_sold_date_sk, ITEM);

	/* catalog page needs to be from a catlog active at the time of the sale */
	r->cs_catalog_page_sk =
	    (r->cs_sold_date_sk == -1) ? -1 : mk_join(CS_CATALOG_PAGE_SK, CATALOG_PAGE, r->cs_sold_date_sk);

	r->cs_ship_mode_sk = mk_join(CS_SHIP_MODE_SK, SHIP_MODE, 1);
	r->cs_warehouse_sk = mk_join(CS_WAREHOUSE_SK, WAREHOUSE, 1);
	r->cs_promo_sk = mk_join(CS_PROMO_SK, PROMOTION, 1);
	set_pricing(CS_PRICING, &r->cs_pricing);

	/**
	 * having gone to the trouble to make the sale, now let's see if it gets
	 * returned
	 */
	genrand_integer(&nTemp, DIST_UNIFORM, 0, 99, 0, CR_IS_RETURNED);
	if (nTemp < CR_RETURN_PCT) {
		struct W_CATALOG_RETURNS_TBL w_catalog_returns;
		struct W_CATALOG_RETURNS_TBL *rr = &w_catalog_returns;
		mk_w_catalog_returns(rr, 1);

		void *info = append_info_get(info_arr, CATALOG_RETURNS);
		append_row_start(info);

		append_key(info, rr->cr_returned_date_sk);
		append_key(info, rr->cr_returned_time_sk);
		append_key(info, rr->cr_item_sk);
		append_key(info, rr->cr_refunded_customer_sk);
		append_key(info, rr->cr_refunded_cdemo_sk);
		append_key(info, rr->cr_refunded_hdemo_sk);
		append_key(info, rr->cr_refunded_addr_sk);
		append_key(info, rr->cr_returning_customer_sk);
		append_key(info, rr->cr_returning_cdemo_sk);
		append_key(info, rr->cr_returning_hdemo_sk);
		append_key(info, rr->cr_returning_addr_sk);
		append_key(info, rr->cr_call_center_sk);
		append_key(info, rr->cr_catalog_page_sk);
		append_key(info, rr->cr_ship_mode_sk);
		append_key(info, rr->cr_warehouse_sk);
		append_key(info, rr->cr_reason_sk);
		append_key(info, rr->cr_order_number);
		append_integer(info, rr->cr_pricing.quantity);
		append_decimal(info, &rr->cr_pricing.net_paid);
		append_decimal(info, &rr->cr_pricing.ext_tax);
		append_decimal(info, &rr->cr_pricing.net_paid_inc_tax);
		append_decimal(info, &rr->cr_pricing.fee);
		append_decimal(info, &rr->cr_pricing.ext_ship_cost);
		append_decimal(info, &rr->cr_pricing.refunded_cash);
		append_decimal(info, &rr->cr_pricing.reversed_charge);
		append_decimal(info, &rr->cr_pricing.store_credit);
		append_decimal(info, &rr->cr_pricing.net_loss);

		append_row_end(info);
	}

	void *info = append_info_get(info_arr, CATALOG_SALES);
	append_row_start(info);

	append_key(info, r->cs_sold_date_sk);
	append_key(info, r->cs_sold_time_sk);
	append_key(info, r->cs_ship_date_sk);
	append_key(info, r->cs_bill_customer_sk);
	append_key(info, r->cs_bill_cdemo_sk);
	append_key(info, r->cs_bill_hdemo_sk);
	append_key(info, r->cs_bill_addr_sk);
	append_key(info, r->cs_ship_customer_sk);
	append_key(info, r->cs_ship_cdemo_sk);
	append_key(info, r->cs_ship_hdemo_sk);
	append_key(info, r->cs_ship_addr_sk);
	append_key(info, r->cs_call_center_sk);
	append_key(info, r->cs_catalog_page_sk);
	append_key(info, r->cs_ship_mode_sk);
	append_key(info, r->cs_warehouse_sk);
	append_key(info, r->cs_sold_item_sk);
	append_key(info, r->cs_promo_sk);
	append_key(info, r->cs_order_number);
	append_integer(info, r->cs_pricing.quantity);
	append_decimal(info, &r->cs_pricing.wholesale_cost);
	append_decimal(info, &r->cs_pricing.list_price);
	append_decimal(info, &r->cs_pricing.sales_price);
	append_decimal(info, &r->cs_pricing.ext_discount_amt);
	append_decimal(info, &r->cs_pricing.ext_sales_price);
	append_decimal(info, &r->cs_pricing.ext_wholesale_cost);
	append_decimal(info, &r->cs_pricing.ext_list_price);
	append_decimal(info, &r->cs_pricing.ext_tax);
	append_decimal(info, &r->cs_pricing.coupon_amt);
	append_decimal(info, &r->cs_pricing.ext_ship_cost);
	append_decimal(info, &r->cs_pricing.net_paid);
	append_decimal(info, &r->cs_pricing.net_paid_inc_tax);
	append_decimal(info, &r->cs_pricing.net_paid_inc_ship);
	append_decimal(info, &r->cs_pricing.net_paid_inc_ship_tax);
	append_decimal(info, &r->cs_pricing.net_profit);

	append_row_end(info);

	return;
}

/*
 * Routine: mk_catalog_sales()
 * Purpose: build rows for the catalog sales table
 * Algorithm:
 * Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO:
 * 20020902 jms Need to link order date/time to call center record
 * 20020902 jms Should promos be tied to item id?
 */
int mk_w_catalog_sales(void *info_arr, ds_key_t index) {
	int nLineitems, i;

	mk_master(info_arr, index);

	/*
	 * now we select the number of lineitems in this order, and loop through
	 * them, printing as we go
	 */
	genrand_integer(&nLineitems, DIST_UNIFORM, 4, 14, 0, CS_ORDER_NUMBER);
	for (i = 1; i <= nLineitems; i++) {
		mk_detail(info_arr, 1);
	}

	/**
	 * and finally return 1 since we have already printed the rows.
	 */
	return 0;
}

/*
 * Routine:
 * Purpose:
 * Algorithm:
 * Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO: None
 */
int vld_w_catalog_sales(int nTable, ds_key_t kRow, int *Permutation) {
	int nLineitem, nMaxLineitem, i;

	row_skip(nTable, kRow - 1);
	row_skip(CATALOG_RETURNS, (kRow - 1));
	jDate = skipDays(CATALOG_SALES, &kNewDateIndex);
	mk_master(NULL, kRow);
	genrand_integer(&nMaxLineitem, DIST_UNIFORM, 4, 14, 9, CS_ORDER_NUMBER);
	genrand_integer(&nLineitem, DIST_UNIFORM, 1, nMaxLineitem, 0, CS_PRICING_QUANTITY);
	for (i = 1; i < nLineitem; i++) {
		mk_detail(NULL, 0);
	}
	mk_detail(NULL, 1);

	return (0);
}
}

// scd.cpp
#include <stdio.h>

/* an array of the most recent business key for each table */
char arBKeys[MAX_TABLE][17];

/*
 * Routine: setSCDKey
 * Purpose: handle the versioning and date stamps for slowly changing dimensions
 * Algorithm:
 * Data Structures:
 *
 * Params: 1 if there is a new id; 0 otherwise
 * Returns:
 * Called By:
 * Calls:
 * Assumptions: Table indexs (surrogate keys) are 1-based. This assures that the
 *arBKeys[] entry for each table is initialized. Otherwise, parallel generation
 *would be more difficult. Side Effects:
 * TODO: None
 */
int setSCDKeys(int nColumnID, ds_key_t kIndex, char *szBKey, ds_key_t *pkBeginDateKey, ds_key_t *pkEndDateKey) {
	int bNewBKey = 0, nModulo;
	static ds_key_t jMinimumDataDate, jMaximumDataDate, jH1DataDate, jT1DataDate, jT2DataDate;
	date_t dtTemp;
	int nTableID;

	if (!InitConstants::setSCDKeys_init) {
		strtodt(&dtTemp, DATA_START_DATE);
		jMinimumDataDate = dtTemp.julian;
		strtodt(&dtTemp, DATA_END_DATE);
		jMaximumDataDate = dtTemp.julian;
		jH1DataDate = jMinimumDataDate + (jMaximumDataDate - jMinimumDataDate) / 2;
		jT2DataDate = (jMaximumDataDate - jMinimumDataDate) / 3;
		jT1DataDate = jMinimumDataDate + jT2DataDate;
		jT2DataDate += jT1DataDate;
		InitConstants::setSCDKeys_init = 1;
	}

	nTableID = getTableFromColumn(nColumnID);
	nModulo = (int)(kIndex % 6);
	switch (nModulo) {
	case 1: /* 1 revision */
		mk_bkey(arBKeys[nTableID], kIndex, nColumnID);
		bNewBKey = 1;
		*pkBeginDateKey = jMinimumDataDate - nTableID * 6;
		*pkEndDateKey = -1;
		break;
	case 2: /* 1 of 2 revisions */
		mk_bkey(arBKeys[nTableID], kIndex, nColumnID);
		bNewBKey = 1;
		*pkBeginDateKey = jMinimumDataDate - nTableID * 6;
		*pkEndDateKey = jH1DataDate - nTableID * 6;
		break;
	case 3: /* 2 of 2 revisions */
		mk_bkey(arBKeys[nTableID], kIndex - 1, nColumnID);
		*pkBeginDateKey = jH1DataDate - nTableID * 6 + 1;
		*pkEndDateKey = -1;
		break;
	case 4: /* 1 of 3 revisions */
		mk_bkey(arBKeys[nTableID], kIndex, nColumnID);
		bNewBKey = 1;
		*pkBeginDateKey = jMinimumDataDate - nTableID * 6;
		*pkEndDateKey = jT1DataDate - nTableID * 6;
		break;
	case 5: /* 2 of 3 revisions */
		mk_bkey(arBKeys[nTableID], kIndex - 1, nColumnID);
		*pkBeginDateKey = jT1DataDate - nTableID * 6 + 1;
		*pkEndDateKey = jT2DataDate - nTableID * 6;
		break;
	case 0: /* 3 of 3 revisions */
		mk_bkey(arBKeys[nTableID], kIndex - 2, nColumnID);
		*pkBeginDateKey = jT2DataDate - nTableID * 6 + 1;
		*pkEndDateKey = -1;
		break;
	}

	/* can't have a revision in the future, per bug 114 */
	if (*pkEndDateKey > jMaximumDataDate)
		*pkEndDateKey = -1;

	strcpy(szBKey, arBKeys[nTableID]);

	return (bNewBKey);
}

/*
 * Routine: scd_join(int tbl, int col, ds_key_t jDate)
 * Purpose: create joins to slowly changing dimensions
 * Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO: None
 */
ds_key_t scd_join(int tbl, int col, ds_key_t jDate) {
	ds_key_t res, kRowcount;
	static int jMinimumDataDate, jMaximumDataDate, jH1DataDate, jT1DataDate, jT2DataDate;
	date_t dtTemp;

	if (!InitConstants::scd_join_init) {
		strtodt(&dtTemp, DATA_START_DATE);
		jMinimumDataDate = dtTemp.julian;
		strtodt(&dtTemp, DATA_END_DATE);
		jMaximumDataDate = dtTemp.julian;
		jH1DataDate = jMinimumDataDate + (jMaximumDataDate - jMinimumDataDate) / 2;
		jT2DataDate = (jMaximumDataDate - jMinimumDataDate) / 3;
		jT1DataDate = jMinimumDataDate + jT2DataDate;
		jT2DataDate += jT1DataDate;
		InitConstants::scd_join_init = 1;
	}

	kRowcount = getIDCount(tbl);
	genrand_key(&res, DIST_UNIFORM, 1, kRowcount, 0, col); /* pick the id */
	res = matchSCDSK(res, jDate, tbl);                     /* map to the date-sensitive surrogate key */

	/* can't have a revision in the future, per bug 114 */
	if (jDate > jMaximumDataDate)
		res = -1;

	return ((res > get_rowcount(tbl)) ? -1 : res);
}

/*
 * Routine:
 * Purpose:
 * Algorithm:
 * Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO: None
 */
ds_key_t matchSCDSK(ds_key_t kUnique, ds_key_t jDate, int nTable) {
	ds_key_t kReturn = -1;
	int jMinimumDataDate, jMaximumDataDate;
	static int jH1DataDate, jT1DataDate, jT2DataDate;
	date_t dtTemp;

	if (!InitConstants::matchSCDSK_init) {
		strtodt(&dtTemp, DATA_START_DATE);
		jMinimumDataDate = dtTemp.julian;
		strtodt(&dtTemp, DATA_END_DATE);
		jMaximumDataDate = dtTemp.julian;
		jH1DataDate = jMinimumDataDate + (jMaximumDataDate - jMinimumDataDate) / 2;
		jT2DataDate = (jMaximumDataDate - jMinimumDataDate) / 3;
		jT1DataDate = jMinimumDataDate + jT2DataDate;
		jT2DataDate += jT1DataDate;
		InitConstants::matchSCDSK_init = 1;
	}

	switch (kUnique % 3) /* number of revisions for the ID */
	{
	case 1: /* only one occurrence of this ID */
		kReturn = (kUnique / 3) * 6;
		kReturn += 1;
		break;
	case 2: /* two revisions of this ID */
		kReturn = (kUnique / 3) * 6;
		kReturn += 2;
		if (jDate > jH1DataDate)
			kReturn += 1;
		break;
	case 0: /* three revisions of this ID */
		kReturn = (kUnique / 3) * 6;
		kReturn += -2;
		if (jDate > jT1DataDate)
			kReturn += 1;
		if (jDate > jT2DataDate)
			kReturn += 1;
		break;
	}

	if (kReturn > get_rowcount(nTable))
		kReturn = get_rowcount(nTable);

	return (kReturn);
}

/*
 * Routine:
 * Purpose: map from a unique ID to a random SK
 * Algorithm:
 * Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO: None
 */
ds_key_t getSKFromID(ds_key_t kID, int nColumn) {
	ds_key_t kTemp = -1;

	switch (kID % 3) {
	case 1: /* single revision */
		kTemp = kID / 3;
		kTemp *= 6;
		kTemp += 1;
		break;
	case 2: /* two revisions */
		kTemp = kID / 3;
		kTemp *= 6;
		kTemp += genrand_integer(NULL, DIST_UNIFORM, 2, 3, 0, nColumn);
		break;
	case 0: /* three revisions */
		kTemp = kID / 3;
		kTemp -= 1;
		kTemp *= 6;
		kTemp += genrand_integer(NULL, DIST_UNIFORM, 4, 6, 0, nColumn);
		break;
	}

	return (kTemp);
}

/*
 * Routine: getFirstSK
 * Purpose: map from id to an SK that can be mapped back to an id by printID()
 * Algorithm:
 * Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO: None
 */
ds_key_t getFirstSK(ds_key_t kID) {
	ds_key_t kTemp = -1;

	switch (kID % 3) {
	case 1: /* single revision */
		kTemp = kID / 3;
		kTemp *= 6;
		kTemp += 1;
		break;
	case 2: /* two revisions */
		kTemp = kID / 3;
		kTemp *= 6;
		kTemp += 2;
		break;
	case 0: /* three revisions */
		kTemp = kID / 3;
		kTemp -= 1;
		kTemp *= 6;
		kTemp += 4;
		break;
	}

	return (kTemp);
}

/*
 * Routine:
 * Purpose:
 * Algorithm:
 * Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO: None
 */
void changeSCD(int nDataType, void *pNewData, void *pOldData, int *nFlags, int bFirst) {

	/**
	 * if nFlags is odd, then this value will be retained
	 */
	if ((*nFlags != ((*nFlags / 2) * 2)) && (bFirst == 0)) {

		/*
		 * the method to retain the old value depends on the data type
		 */
		switch (nDataType) {
		case SCD_INT:
			*(int *)pNewData = *(int *)pOldData;
			break;
		case SCD_PTR:
			pNewData = pOldData;
			break;
		case SCD_KEY:
			*(ds_key_t *)pNewData = *(ds_key_t *)pOldData;
			break;
		case SCD_CHAR:
			strcpy((char *)pNewData, (char *)pOldData);
			break;
		case SCD_DEC:
			memcpy(pNewData, pOldData, sizeof(decimal_t));
			break;
		}
	} else {

		/*
		 * the method to set the old value depends on the data type
		 */
		switch (nDataType) {
		case SCD_INT:
			*(int *)pOldData = *(int *)pNewData;
			break;
		case SCD_PTR:
			pOldData = pNewData;
			break;
		case SCD_KEY:
			*(ds_key_t *)pOldData = *(ds_key_t *)pNewData;
			break;
		case SCD_CHAR:
			strcpy((char *)pOldData, (char *)pNewData);
			break;
		case SCD_DEC:
			memcpy(pOldData, pNewData, sizeof(decimal_t));
			break;
		}
	}

	*nFlags /= 2;

	return;
}

// dsdgen_helpers.cpp

#define DECLARER

namespace tpcds {

void InitializeDSDgen(double scale) {
	InitConstants::Reset();
	ResetCountCount();
	std::string t = std::to_string(scale);
	set_str("SCALE", (char*) t.c_str()); // set SF, which also does a default init (e.g. random seed)
	init_rand();                 // no random numbers without this
}

ds_key_t GetRowCount(int table_id) {
	return get_rowcount(table_id);
}

void ResetCountCount() {
	resetCountCount();
}

tpcds_table_def GetTDefByNumber(int table_id) {
	auto tdef = getSimpleTdefsByNumber(table_id);
	tpcds_table_def def;
	def.name = tdef->name;
	def.fl_child = tdef->flags & FL_CHILD ? 1 : 0;
	def.fl_small = tdef->flags & FL_SMALL ? 1 : 0;
	return def;
}

tpcds_builder_func GetTDefFunctionByNumber(int table_id) {
	auto table_funcs = getTdefFunctionsByNumber(table_id);
	return table_funcs->builder;
}

} // namespace tpcds

// genrand.cpp
#include <stdio.h>
#include <stdlib.h>
#ifdef WIN32
#include <search.h>
#include <limits.h>
#endif


static long Mult = 16807; /* the multiplier */
static long nQ = 127773;  /* the quotient MAXINT / Mult */
static long nR = 2836;    /* the remainder MAXINT % Mult */
void DSNthElement(HUGE_TYPE N, int nStream);

/*
 * Routine: next_random(int stream)
 * Purpose:
 * Algorithm:
 * Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO: None
 */
long next_random(int stream) {
	long s = Streams[stream].nSeed, div_res, mod_res;

	div_res = s / nQ;
	mod_res = s - nQ * div_res; /* i.e., mod_res = s % nQ */
	s = Mult * mod_res - div_res * nR;
	if (s < 0)
		s += MAXINT;
	Streams[stream].nSeed = s;
	Streams[stream].nUsed += 1;
#ifdef JMS
	Streams[stream].nTotal += 1;
#endif
	return (s);
}

/*
 * Routine: next_random_float(int stream)
 * Purpose:  return random in [0..1]
 * Algorithm:
 * Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO: None
 */
double next_random_float(int stream) {
	long res;

	res = next_random(stream);

	return ((double)res / (double)MAXINT);
}

/*
 * Routine: skip_random(int stream, int skip_count)
 * Purpose:
 * Algorithm:
 * Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO: None
 */
void skip_random(int nStream, ds_key_t N) {
	ds_key_t Z;
	ds_key_t M;

#ifdef UNDEF
	fprintf(stderr, "skipping stream %d to %d\n", nStream, N);
	Streams[nStream].nTotal = N;
#endif
	M = Mult;
	Z = (ds_key_t)Streams[nStream].nInitialSeed;
	while (N > 0) {
		if (N % 2 != 0) /* testing for oddness, this seems portable */
			Z = (M * Z) % MAXINT;
		N = N / 2; /* integer division, truncates */
		M = (M * M) % MAXINT;
	}
	Streams[nStream].nSeed = (long)Z;

	return;
}

/*
 * Routine: genrand_integer(int dist, int min, int max, int mean)
 * Purpose: generate a random integer given the distribution and limits
 * Algorithm:
 * Data Structures:
 *
 * Params:
 * Returns: int
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 */
int genrand_integer(int *dest, int dist, int min, int max, int mean, int stream) {
	int res = 0, i;
	double fres = 0;

	switch (dist) {
	case DIST_UNIFORM:
		res = next_random(stream);
		res %= max - min + 1;
		res += min;
		break;
	case DIST_EXPONENTIAL:
		for (i = 0; i < 12; i++)
			fres += (double)(next_random(stream) / MAXINT) - 0.5;
		res = min + (int)((max - min + 1) * fres);
		break;
	default:
		INTERNAL("Undefined distribution");
		break;
	}

	if (dest == NULL)
		return (res);

	*dest = res;

	return (0);
}

/*
 * Routine: genrand_key(ket_t *dest, int dist, ds_key_t min, ds_key_t max,
 * ds_key_t mean, int stream) Purpose: generate a random integer given the
 * distribution and limits Algorithm: Data Structures:
 *
 * Params:
 * Returns: ds_key_t
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO: Need to rework to rely on RNG routines that will work for 64 bit return
 * values
 */
ds_key_t genrand_key(ds_key_t *dest, int dist, ds_key_t min, ds_key_t max, ds_key_t mean, int stream) {
	int res = 0, i;
	double fres = 0;

	switch (dist) {
	case DIST_UNIFORM:
		res = next_random(stream);
		res %= (int)(max - min + 1);
		res += (int)min;
		break;
	case DIST_EXPONENTIAL:
		for (i = 0; i < 12; i++)
			fres += (double)(next_random(stream) / MAXINT) - 0.5;
		res = (int)min + (int)((max - min + 1) * fres);
		break;
	default:
		INTERNAL("Undefined distribution");
		break;
	}

	if (dest == NULL)
		return ((ds_key_t)res);

	*dest = (ds_key_t)res;

	return ((ds_key_t)0);
}

/*
 * Routine:
 *	genrand_decimal(int dist, decimal_t *min, decimal_t *max, decimal_t *mean)
 * Purpose: create a random decimal_t
 * Algorithm:
 * Data Structures:
 *
 * Params: min/max are char * to allow easy passing of precision
 * Returns: decimal_t *; NULL on failure
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO: None
 */
int genrand_decimal(decimal_t *dest, int dist, decimal_t *min, decimal_t *max, decimal_t *mean, int stream) {
	int i;
	decimal_t res;
	double fres = 0.0;

	if (min->precision < max->precision)
		dest->precision = min->precision;
	else
		dest->precision = max->precision;

	switch (dist) {
	case DIST_UNIFORM:
		res.number = next_random(stream);
		res.number %= max->number - min->number + 1;
		res.number += min->number;
		break;
	case DIST_EXPONENTIAL:
		for (i = 0; i < 12; i++) {
			fres /= 2.0;
			fres += (double)((double)next_random(stream) / (double)MAXINT) - 0.5;
		}
		res.number = mean->number + (int)((max->number - min->number + 1) * fres);
		break;
	default:
		INTERNAL("Undefined distribution");
		break;
	}

	dest->number = res.number;
	i = 0;
	while (res.number > 10) {
		res.number /= 10;
		i += 1;
	}
	dest->scale = i;

	return (0);
}

/* Routine: RNGReset(int tbl)
 * Purpose:
 * Algorithm:
 * Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO: None
 */
int RNGReset(int tbl) {
	int i;

	for (i = 0; Streams[i].nColumn != -1; i++)
		if (Streams[i].nTable == tbl)
			Streams[i].nSeed = Streams[i].nInitialSeed;

	return (0);
}

/* WARNING!  This routine assumes the existence of 64-bit                 */

/* integers.  The notation used here- "HUGE" is *not* ANSI standard. */

/* Hopefully, you have this extension as well.  If not, use whatever      */

/* nonstandard trick you need to in order to get 64 bit integers.         */

/* The book says that this will work if MAXINT for the type you choose    */

/* is at least 2**46  - 1, so 64 bits is more than you *really* need      */

static HUGE_TYPE Multiplier = 16807;   /* or whatever nonstandard */
static HUGE_TYPE Modulus = 2147483647; /* trick you use to get 64 bit int */

/* Advances value of Seed after N applications of the random number generator
   with multiplier Mult and given Modulus.
   NthElement(Seed[],count);

   Theory:  We are using a generator of the form
        X_n = [Mult * X_(n-1)]  mod Modulus.    It turns out that
        X_n = [(Mult ** n) X_0] mod Modulus.
   This can be computed using a divide-and-conquer technique, see
   the code below.

   In words, this means that if you want the value of the Seed after n
   applications of the generator,  you multiply the initial value of the
   Seed by the "super multiplier" which is the basic multiplier raised
   to the nth power, and then take mod Modulus.
*/

/* Nth Element of sequence starting with StartSeed */
void DSNthElementNthElement(HUGE_TYPE N, int nStream) {
	HUGE_TYPE Z;
	HUGE_TYPE Mult;

	Mult = Multiplier;
	Z = (HUGE_TYPE)Streams[nStream].nInitialSeed;
	while (N > 0) {
		if (N % 2 != 0) /* testing for oddness, this seems portable */
		{
#ifdef JMS
			Streams[nStream].nTotal += 1;
#endif
			Z = (Mult * Z) % Modulus;
		}
		N = N / 2; /* integer division, truncates */
		Mult = (Mult * Mult) % Modulus;
#ifdef JMS
		Streams[nStream].nTotal += 2;
#endif
	}
	Streams[nStream].nSeed = (long)Z;

	return;
}

/*
 * Routine:
 * Purpose:
 * Algorithm:
 * Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO: None
 */
int dump_seeds_ds(int tbl) {
	int i;

	for (i = 0; Streams[i].nColumn != -1; i++)
		if (Streams[i].nTable == tbl)
			printf("%04d\t%09d\t%09ld\n", i, Streams[i].nUsed, Streams[i].nSeed);
	return (0);
}

/*
 * Routine: gen_charset(char *set, int min, int max)
 * Purpose: generate random characters from set for a random length [min..max]
 * Algorithm:
 * Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO: None
 */
int gen_charset(char *dest, char *set, int min, int max, int stream) {
	int len, i, temp;

	if (set == NULL) {
		dest = NULL;
		return (-1);
	}

	genrand_integer(&len, DIST_UNIFORM, min, max, 0, stream);

	for (i = 0; i < max; i++) {
		genrand_integer(&temp, DIST_UNIFORM, 0, strlen(set) - 1, 0, stream);
		if (i < len)
			dest[i] = *(set + temp);
	}
	dest[len] = '\0';

	return (0);
}

/*
 * Routine: genrand_date(int dist, date_t *min, date_t *max)
 * Purpose: generate random date within [min..max]
 * Algorithm:
 * Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO: None
 */
int genrand_date(date_t *dest, int dist, date_t *min, date_t *max, date_t *mean, int stream) {
	int range, imean = 0, temp, idt, nYear, nTotalWeight = 0, nDayCount;

	idt = dttoj(min);
	range = dttoj(max);
	range -= idt;
	nDayCount = min->day;
	nYear = min->year;

	switch (dist) {
	case DIST_SALES:
	case DIST_RETURNS:
		/* walk from min to max to "integrate" the distribution */
		while (range -= 1) {
			nTotalWeight += dist_weight(NULL, "calendar", nDayCount, dist + is_leap(nYear));
			if (nDayCount == 365 + is_leap(nYear)) {
				nYear += 1;
				nDayCount = 1;
			} else
				nDayCount += 1;
		}
		/* pick a value in the resulting range */
		temp = genrand_integer(NULL, DIST_UNIFORM, 1, nTotalWeight, 0, stream);
		/* and walk it again to translate that back to a date */
		nDayCount = min->day;
		idt = min->julian;
		nYear = min->year;
		while (temp >= 0) {
			temp -= dist_weight(NULL, "calendar", nDayCount, dist + is_leap(nYear));
			nDayCount += 1;
			idt += 1;
			if (nDayCount > 365 + is_leap(nYear)) {
				nYear += 1;
				nDayCount = 1;
			}
		}
		break;
	case DIST_EXPONENTIAL:
		imean = dttoj(mean);
		imean -= idt;
	case DIST_UNIFORM:
		genrand_integer(&temp, dist, 0, range, imean, stream);
		idt += temp;
		break;
	default:
		break;
	}

	jtodt(dest, idt);

	return (0);
}

/**************
 **************
 **
 ** static routines
 **
 **************
 **************/

/*
 * Routine: init_rand()
 * Purpose: Initialize the RNG used throughout the code
 * Algorithm: To allow two columns to use the same stream of numbers (for
 *joins), pre-sort the streams list by Duplicate and then assign values. Order
 *by column after initialization Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO:
 */
// FIXME: allow re-init
void init_rand(void) {
	long long i, skip, nSeed; // changed to long long from int

	if (!InitConstants::init_rand_init) {
		if (is_set("RNGSEED"))
			nSeed = get_int("RNGSEED");
		else
			nSeed = RNG_SEED;
		skip = MAXINT / MAX_COLUMN;
		for (i = 0; i < MAX_COLUMN; i++) {
            // simulate the overflow as if it were an int
            if (i != 0 && (INT_MAX - nSeed) / i < skip) {
                long long val = nSeed + skip * i;
                val %= MAXINT;
                val -= MAXINT;
                val -= 2;
                Streams[i].nInitialSeed = val;
                Streams[i].nSeed = val;
            } else {
                Streams[i].nInitialSeed = nSeed + skip * i;
                Streams[i].nSeed = nSeed + skip * i;
            }
			    Streams[i].nUsed = 0;
		}
		InitConstants::init_rand_init = 1;
	}
	return;
}

void resetSeeds(int nTable) {
	int i;

	for (i = 0; i < MAX_COLUMN; i++)
		if (Streams[i].nTable == nTable)
			Streams[i].nSeed = Streams[i].nInitialSeed;
	return;
}

/*
 * Routine:
 * Purpose:
 * Algorithm:
 * Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO: None
 */
void genrand_email(char *pEmail, char *pFirst, char *pLast, int nColumn) {
	char *pDomain;
	char szCompany[50];
	int nCompanyLength;

	pick_distribution(&pDomain, "top_domains", 1, 1, nColumn);
	genrand_integer(&nCompanyLength, DIST_UNIFORM, 10, 20, 0, nColumn);
	gen_charset(&szCompany[0], ALPHANUM, 1, 20, nColumn);
	szCompany[nCompanyLength] = '\0';

	sprintf(pEmail, "%s.%s@%s.%s", pFirst, pLast, szCompany, pDomain);

	return;
}

/*
 * Routine:
 * Purpose:
 * Algorithm:
 * Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO: None
 */
void genrand_ipaddr(char *pDest, int nColumn) {
	int arQuads[4], i;

	for (i = 0; i < 4; i++)
		genrand_integer(&arQuads[i], DIST_UNIFORM, 1, 255, 0, nColumn);
	sprintf(pDest, "%03d.%03d.%03d.%03d", arQuads[0], arQuads[1], arQuads[2], arQuads[3]);

	return;
}

/*
 * Routine:
 * Purpose:
 * Algorithm:
 * Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO: None
 */
int genrand_url(char *pDest, int nColumn) {
	strcpy(pDest, "http://www.foo.com");

	return (0);
}

/*
 * Routine:
 * Purpose:
 * Algorithm:
 * Data Structures:
 *
 * Params:
 * Returns:
 * Called By:
 * Calls:
 * Assumptions:
 * Side Effects:
 * TODO: None
 */
int setSeed(int nStream, int nValue) {
	int nRetValue;

	nRetValue = Streams[nStream].nSeed;
	Streams[nStream].nSeed = nValue;

	return (nRetValue);
}

#ifdef TEST
main() {
	printf("r_genrand:No test routine has been defined for this module\n");

	exit(0);
}
#endif /* TEST */

