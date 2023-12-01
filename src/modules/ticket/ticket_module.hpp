#ifndef ticket_module
#define ticket_module

#include <core/entities/entities.hpp>
#include "ftxui/component/component.hpp"

namespace TicketComponents {
namespace CreateModal {
ftxui::Component main(void (*on_cancel)(), void (*on_create)());
}
namespace UpdateModal {
ftxui::Component main(void (*on_cancel)(), void (*on_delete)());
}
namespace DeleteModal {
ftxui::Component main(void (*on_cancel)(), void (*on_delete)());
}
}  // namespace TicketComponents

namespace TicketPresentation {
ftxui::Component main();
}

namespace TicketRepository {
std::vector<std::vector<std::string>> get_all();
Entities::ticket_entity* get_one_by_id(int id);
void create(Entities::ticket_entity* entity);
void update(int id, Entities::ticket_entity* entity);
void remove(int id);
}  // namespace TicketRepository

#endif