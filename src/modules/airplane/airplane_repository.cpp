#include <iostream>
#include <vector>

#include <core/drivers/drivers.hpp>
#include <core/entities/entities.hpp>

using namespace std;
using namespace Entities;

namespace AirplaneRepository {
vector<vector<string>> get_all() {
  auto result = DatabaseDriver::query("SELECT * FROM airplanes", {});
  return result;
}

airplane_entity* get_one_by_id(int id) {
  airplane_entity* airplane;
  return airplane;
}
}  // namespace AirplaneRepository