#pragma once

#include "duckdb.hpp"
#ifndef DUCKDB_AMALGAMATION
#include "duckdb-internal.hpp"
#endif

#include <memory>
#include <cassert>

namespace tpcds {

struct tpcds_table_def {
	const char *name;
	int fl_small;
	int fl_child;
};

#define CALL_CENTER   0
#define DBGEN_VERSION 24

struct tpcds_append_information {
	tpcds_append_information(duckdb::ClientContext &context_p, duckdb::TableCatalogEntry *table)
	    : context(context_p), appender(context_p, *table) {
	}

	duckdb::ClientContext &context;
	duckdb::InternalAppender appender;

	tpcds_table_def table_def;
};

} // namespace tpcds
