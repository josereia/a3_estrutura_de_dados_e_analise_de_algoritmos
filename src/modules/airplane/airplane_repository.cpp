#include <iostream>
#include <vector>

#include <core/drivers/drivers.hpp>
#include <core/entities/entities.hpp>

using namespace std;
using namespace Entities;

namespace AirplaneRepository {
vector<vector<string>> get_all() {
  auto airplanes = DatabaseDriver::query("SELECT * FROM airplanes", {});
  return airplanes;
}

airplane_entity* get_one_by_id(int id) {
  auto query = "SELECT * FROM airplanes WHERE id = ?";
  auto params = vector<string>{to_string(id)};

  auto result = DatabaseDriver::query(query, params);
  if (result.size() == 0) {
    return nullptr;
  }

  auto row = result[0];
  auto airplane = new airplane_entity{
      .model = row[1],
      .manufacturer = row[2],
      .capacity = stoi(row[3]),
      .length = stof(row[4]),
      .height = stof(row[5]),
      .speed = stof(row[6]),
      .altitude = stof(row[7]),
      .engine = row[8],
  };

  return airplane;
}

void create(airplane_entity* entity) {
  auto query =
      "INSERT INTO airplanes (model, manufacturer, capacity, length, "
      "height, speed, altitude, engine) VALUES (?, ?, ?, ?, ?, ?, ?, "
      "?)";

  auto params = vector<string>{
      entity->model,
      entity->manufacturer,
      to_string(entity->capacity),
      to_string(entity->length),
      to_string(entity->height),
      to_string(entity->speed),
      to_string(entity->altitude),
      entity->engine,
  };

  DatabaseDriver::query(query, params);
}

void update(int id, airplane_entity* entity) {
  auto query =
      "UPDATE airplanes SET model = ?, manufacturer = ?, capacity = ?, "
      "length = ?, height = ?, speed = ?, altitude = ?, engine = ? WHERE "
      "id = ?";

  auto params = vector<string>{
      entity->model,
      entity->manufacturer,
      to_string(entity->capacity),
      to_string(entity->length),
      to_string(entity->height),
      to_string(entity->speed),
      to_string(entity->altitude),
      entity->engine,
      to_string(id),
  };

  DatabaseDriver::query(query, params);
}

void remove(int id) {
  auto query = "DELETE FROM airplanes WHERE id = ?";
  auto params = vector<string>{
      to_string(id),
  };

  DatabaseDriver::query(query, params);
}
}  // namespace AirplaneRepository