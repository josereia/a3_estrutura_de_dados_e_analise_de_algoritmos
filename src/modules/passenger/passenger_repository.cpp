#include <iostream>
#include <vector>

#include <core/drivers/drivers.hpp>
#include <core/entities/entities.hpp>

using namespace std;
using namespace Entities;

namespace PassengerRepository {
vector<vector<string>> get_all() {
  auto result = DatabaseDriver::query("SELECT * FROM passengers", {});
  return result;
}

passenger_entity* get_one_by_id(int id) {
  passenger_entity* passenger;
  return passenger;
}
}  // namespace PassengerRepository