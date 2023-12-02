#include <iostream>
#include <vector>

#include <core/drivers/drivers.hpp>
#include <core/entities/entities.hpp>

using namespace std;
using namespace Entities;

namespace LuggageRepository {
/// @brief get all luggages from database
/// @return vector of vector of strings
vector<vector<string>> get_all() {
  auto luggages = DatabaseDriver::query("SELECT * FROM luggages", {});
  return luggages;
}

/// @brief get one luggage by id
/// @param id id of the luggage
/// @return pointer to luggage entity
luggage_entity* get_one_by_id(int id) {
  auto query = "SELECT * FROM luggages WHERE id = ?";
  auto params = vector<string>{to_string(id)};

  auto result = DatabaseDriver::query(query, params);
  if (result.size() == 0) {
    return nullptr;
  }

  auto row = result[0];
  auto luggage = new luggage_entity{
      .ticket_id = stoi(row[1]),
      .type = row[2],
      .description = row[3],
      .weight = stof(row[4]),
  };

  return luggage;
}

/// @brief create a new luggage from entity
/// @param entity pointer to luggage entity
void create(luggage_entity* entity) {
  auto query =
      "INSERT INTO luggages (ticket_id, type, "
      "description, weight) VALUES (?, ?, ?, ?)";

  auto params = vector<string>{
      to_string(entity->ticket_id),
      entity->type,
      entity->description,
      to_string(entity->weight),
  };

  DatabaseDriver::query(query, params);
}

/// @brief update luggage from entity
/// @param id id of the luggage
/// @param entity pointer to luggage entity
void update(int id, luggage_entity* entity) {
  auto query =
      "UPDATE luggages SET ticket_id = ?, type = ?, "
      "description = ?, "
      "weight = ? WHERE "
      "id = ?";

  auto params = vector<string>{
      to_string(entity->ticket_id), entity->type,  entity->description,
      to_string(entity->weight),    to_string(id),
  };

  DatabaseDriver::query(query, params);
}

/// @brief remove luggage from database
/// @param id id of the luggage
void remove(int id) {
  auto query = "DELETE FROM luggages WHERE id = ?";
  auto params = vector<string>{to_string(id)};

  DatabaseDriver::query(query, params);
}
}  // namespace LuggageRepository