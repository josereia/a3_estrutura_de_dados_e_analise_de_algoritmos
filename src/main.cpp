#include <sqlite3.h>
#include <iostream>

#include <core/drivers/drivers.hpp>
#include <modules/auth/auth_module.hpp>

sqlite3* db;

int main(void) {
  // init database
  DatabaseDriver::init(&db, "orion_airlines.db");

  // initial module/presentation
  AuthPresentation::main();

  exit(EXIT_SUCCESS);
  return EXIT_SUCCESS;
}