#include <sqlite3.h>
#include <string>

#include <core/drivers/drivers.hpp>

using namespace std;

namespace DatabaseDriver {
/// @brief open a database connection
/// @param db database instance (pointer)
/// @param path database path
void open(sqlite3** db, string path) {
  sqlite3_open(path.c_str(), db);
}

/// @brief initialize database with schema file
/// @param db database instance (pointer)
/// @param path database path
void init(sqlite3** db, string path) {
  open(db, path);

  string schema = StorageDriver::read_file("src/core/ops/schema.sql");
  sqlite3_exec(*db, schema.c_str(), NULL, NULL, NULL);
}
}  // namespace DatabaseDriver