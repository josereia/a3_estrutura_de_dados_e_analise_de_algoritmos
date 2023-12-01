#include <iostream>
#include <vector>

#include <core/drivers/drivers.hpp>
#include <core/entities/entities.hpp>

using namespace std;
using namespace Entities;

namespace FlightRepository {
vector<vector<string>> get_all() {
  auto result = DatabaseDriver::query("SELECT * FROM flights", {});
  return result;
}

flight_entity* get_one_by_id(int id) {
  flight_entity* flight;
  return flight;
}
}  // namespace FlightRepository