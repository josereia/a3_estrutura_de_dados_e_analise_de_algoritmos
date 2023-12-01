#include <iostream>
#include <vector>

#include <core/drivers/drivers.hpp>
#include <core/entities/entities.hpp>

using namespace std;
using namespace Entities;

namespace PassengerRepository {
/// @brief get all passengers from database
/// @return vector of vector of strings
vector<vector<string>> get_all() {
  auto passengers = DatabaseDriver::query("SELECT * FROM passengers", {});
  return passengers;
}

/// @brief get one passenger by id
/// @param id id of the passenger
/// @return pointer to passenger entity
passenger_entity* get_one_by_id(int id) {
  auto query = "SELECT * FROM passengers WHERE id = ?";
  auto params = vector<string>{to_string(id)};

  auto result = DatabaseDriver::query(query, params);
  if (result.size() == 0) {
    return nullptr;
  }

  auto row = result[0];
  auto passenger = new passenger_entity{
      .name = row[1],
      .cpf = row[2],
      .passport = row[3],
      .birth_date = row[4],
      .email = row[5],
      .phone = row[6],
  };

  return passenger;
}

/// @brief create a new passenger from entity
/// @param entity pointer to passenger entity
void create(passenger_entity* entity) {
  auto query =
      "INSERT INTO passengers (name, cpf, "
      "passport, birth_date, "
      "email, phone) VALUES (?, ?, ?, ?, ?, ?)";

  auto params = vector<string>{
      entity->name,       entity->cpf,   entity->passport,
      entity->birth_date, entity->email, entity->phone,
  };

  DatabaseDriver::query(query, params);
}

/// @brief update passenger from entity
/// @param id id of the passenger
/// @param entity pointer to passenger entity
void update(int id, passenger_entity* entity) {
  auto query =
      "UPDATE passengers SET name = ?, cpf = ?, "
      "passport = ?, "
      "birth_date = ?, email = ?, phone = ? WHERE "
      "id = ?";

  auto params = vector<string>{
      entity->name,  entity->cpf,   entity->passport, entity->birth_date,
      entity->email, entity->phone, to_string(id),
  };

  DatabaseDriver::query(query, params);
}

/// @brief remove passenger from database
/// @param id id of the passenger
void remove(int id) {
  auto query = "DELETE FROM passengers WHERE id = ?";
  auto params = vector<string>{to_string(id)};

  DatabaseDriver::query(query, params);
}
}  // namespace PassengerRepository