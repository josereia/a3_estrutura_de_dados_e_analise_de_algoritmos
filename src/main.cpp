#include <sqlite3.h>
#include <iostream>

#include <core/drivers/drivers.hpp>
#include <core/entities/entities.hpp>
#include <modules/airplane/airplane_module.hpp>
#include <modules/auth/auth_module.hpp>
#include <modules/ticket/ticket_module.hpp>

using namespace std;
using namespace Entities;

sqlite3* db;

int main(void) {
  // init database
  DatabaseDriver::init(&db);

  // initial module/presentation
  AuthPresentation::main();


  exit(EXIT_SUCCESS);
  return EXIT_SUCCESS;
}