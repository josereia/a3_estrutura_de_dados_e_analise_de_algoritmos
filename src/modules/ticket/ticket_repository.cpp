#include <iostream>
#include <vector>

#include <core/drivers/drivers.hpp>
#include <core/entities/entities.hpp>

using namespace std;
using namespace Entities;

namespace TicketRepository {
/// @brief get all tickets from database
/// @return vector of vector of strings
vector<vector<string>> get_all() {
  auto query =
      "SELECT t.id, t.flight_id, t.passenger_id, p.name, t.boarding_date, "
      "t.boarding_gate, t.seat FROM tickets AS t JOIN passengers AS p WHERE "
      "t.passenger_id = "
      "p.id";

  auto tickets = DatabaseDriver::query(query, {});
  return tickets;
}

/// @brief get one ticket by id
/// @param id id of the ticket
/// @return pointer to ticket entity
ticket_entity* get_one_by_id(int id) {
  auto query = "SELECT * FROM tickets WHERE id = ?";
  auto params = vector<string>{to_string(id)};

  auto result = DatabaseDriver::query(query, params);
  if (result.size() == 0) {
    return nullptr;
  }

  auto row = result[0];
  auto ticket = new ticket_entity{
      .flight_id = stoi(row[1]),
      .passenger_id = stoi(row[2]),
      .boarding_date = row[3],
      .boarding_gate = row[4],
      .seat = row[5],
  };

  return ticket;
}

/// @brief create a new ticket from entity
/// @param entity pointer to ticket entity
void create(ticket_entity* entity) {
  auto query =
      "INSERT INTO tickets (flight_id, passenger_id, "
      "boarding_date, boarding_gate, "
      "seat) VALUES (?, ?, ?, ?, ?)";

  auto params = vector<string>{
      to_string(entity->flight_id),
      to_string(entity->passenger_id),
      entity->boarding_date,
      entity->boarding_gate,
      entity->seat,
  };

  DatabaseDriver::query(query, params);
}

/// @brief update ticket from entity
/// @param id id of the ticket
/// @param entity pointer to ticket entity
void update(int id, ticket_entity* entity) {
  auto query =
      "UPDATE tickets SET flight_id = ?, passenger_id = ?, "
      "boarding_date = ?, "
      "boarding_gate = ?, seat = ? WHERE "
      "id = ?";

  auto params = vector<string>{
      to_string(entity->flight_id),
      to_string(entity->passenger_id),
      entity->boarding_date,
      entity->boarding_gate,
      entity->seat,
      to_string(id),
  };

  DatabaseDriver::query(query, params);
}

/// @brief remove ticket from database
/// @param id id of the ticket
void remove(int id) {
  auto query = "DELETE FROM tickets WHERE id = ?";
  auto params = vector<string>{to_string(id)};

  DatabaseDriver::query(query, params);
}
}  // namespace TicketRepository