#include <sqlite3.h>
#include <iostream>
#include <string>
#include <vector>

#include <core/drivers/drivers.hpp>

using namespace std;

namespace DatabaseDriver {
sqlite3** db;
string path = "orion_airlines.db";

/// @brief open a database connection
void open() {
  auto rc = sqlite3_open(path.c_str(), db);
  if (rc) {
    fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(*db));
    // exit(EXIT_FAILURE);
  }
}

/// @brief close a database connection
void close() {
  auto rc = sqlite3_close(*db);
  if (rc) {
    fprintf(stderr, "Can't close database: %s\n", sqlite3_errmsg(*db));
    // exit(EXIT_FAILURE);
  }
}

/// @brief initialize database with schema file
/// @param instance database instance (pointer)
/// @param db_path database path
void init(sqlite3** instance) {
  db = instance;

  open();

  string schema = StorageDriver::read_file("src/core/ops/schema.sql");
  string data = StorageDriver::read_file("src/core/ops/data.sql");

  auto rc = sqlite3_exec(*db, schema.c_str(), NULL, NULL, NULL);
  rc = sqlite3_exec(*db, data.c_str(), NULL, NULL, NULL);
  if (rc) {
    fprintf(stderr, "Can't initialize database: %s\n", sqlite3_errmsg(*db));
    // exit(EXIT_FAILURE);
  }

  close();
}

/// @brief execute a query
/// @param query query string
vector<vector<string>> query(string query, vector<string> bindings) {
  vector<vector<string>> results;

  open();

  sqlite3_stmt* stmt;
  auto rc = sqlite3_prepare_v2(*db, query.c_str(), -1, &stmt, nullptr);
  if (rc != SQLITE_OK) {
    fprintf(stderr, "Failed to prepare statement: %s\n", sqlite3_errmsg(*db));
  }

  for (int i = 0; i < bindings.size(); ++i) {
    rc = sqlite3_bind_text(stmt, i + 1, bindings[i].c_str(), -1, SQLITE_STATIC);
    if (rc != SQLITE_OK) {
      fprintf(stderr, "Failed to bind parameter: %s\n", sqlite3_errmsg(*db));
    }
  }

  while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
    std::vector<std::string> row;
    for (int i = 0; i < sqlite3_column_count(stmt); i++) {
      row.push_back(std::string(
          reinterpret_cast<const char*>(sqlite3_column_text(stmt, i))));
    }
    results.push_back(row);
  }

  sqlite3_finalize(stmt);

  close();

  return results;
}
}  // namespace DatabaseDriver