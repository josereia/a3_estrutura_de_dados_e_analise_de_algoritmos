#include <iostream>
#include <vector>

#include <core/drivers/drivers.hpp>
#include <core/entities/entities.hpp>

using namespace std;
using namespace Entities;

namespace FlightRepository {
/// @brief get all flights from database
/// @return vector of vector of strings
vector<vector<string>> get_all() {
  auto flights = DatabaseDriver::query("SELECT * FROM flights", {});
  return flights;
}

/// @brief get one flight by id
/// @param id id of the flight
/// @return pointer to flight entity
flight_entity* get_one_by_id(int id) {
  auto query = "SELECT * FROM flights WHERE id = ?";
  auto params = vector<string>{to_string(id)};

  auto result = DatabaseDriver::query(query, params);
  if (result.size() == 0) {
    return nullptr;
  }

  auto row = result[0];
  auto flight = new flight_entity{
      .airplane_id = stoi(row[1]),
      .departure_date = row[2],
      .arrival_date = row[3],
      .departure_address = row[4],
      .destination_address = row[5],

  };

  return flight;
}

/// @brief create a new flight from entity
/// @param entity pointer to flight entity
void create(flight_entity* entity) {
  auto query =
      "INSERT INTO flights (airplane_id, departure_address, "
      "destination_address, departure_date, "
      "arrival_date) VALUES (?, ?, ?, ?, ?)";

  auto params = vector<string>{
      to_string(entity->airplane_id), entity->departure_address,
      entity->destination_address,    entity->departure_date,
      entity->arrival_date,
  };

  DatabaseDriver::query(query, params);
}

/// @brief update flight from entity
/// @param id id of the flight
/// @param entity pointer to flight entity
void update(int id, flight_entity* entity) {
  auto query =
      "UPDATE flights SET airplane_id = ?, departure_address = ?, "
      "destination_address = ?, "
      "departure_date = ?, arrival_date = ? WHERE "
      "id = ?";

  auto params = vector<string>{
      to_string(entity->airplane_id), entity->departure_address,
      entity->destination_address,    entity->departure_date,
      entity->arrival_date,           to_string(id),
  };

  DatabaseDriver::query(query, params);
}

/// @brief remove flight from database
/// @param id id of the flight
void remove(int id) {
  auto query = "DELETE FROM flights WHERE id = ?";
  auto params = vector<string>{to_string(id)};

  DatabaseDriver::query(query, params);
}
}  // namespace FlightRepository