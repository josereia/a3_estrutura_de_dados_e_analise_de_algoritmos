#include <iostream>
#include <vector>

#include <core/drivers/drivers.hpp>
#include <core/entities/entities.hpp>

using namespace std;
using namespace Entities;

namespace TicketRepository {
vector<vector<string>> get_all() {
  auto result = DatabaseDriver::query("SELECT * FROM tickets", {});
  return result;
}

ticket_entity* get_one_by_id(int id) {
  ticket_entity* ticket;
  return ticket;
}
}  // namespace TicketRepository