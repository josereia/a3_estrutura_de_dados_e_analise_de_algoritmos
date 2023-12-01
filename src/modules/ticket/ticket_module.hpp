#ifndef ticket_module
#define ticket_module

#include <core/entities/entities.hpp>
#include "ftxui/component/component.hpp"

namespace TicketPresentation {
ftxui::Component main();
}

namespace TicketRepository {
std::vector<std::vector<std::string>> get_all();
Entities::ticket_entity* get_one_by_id(int id);
}  // namespace TicketRepository

#endif