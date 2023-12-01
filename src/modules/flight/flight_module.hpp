#ifndef flight_module
#define flight_module

#include <core/entities/entities.hpp>
#include "ftxui/component/component.hpp"

namespace FlightComponents {
namespace CreateModal {
ftxui::Component main(void (*on_cancel)(), void (*on_create)());
}
namespace UpdateModal {
ftxui::Component main(void (*on_cancel)(), void (*on_delete)());
}
namespace DeleteModal {
ftxui::Component main(void (*on_cancel)(), void (*on_delete)());
}
}  // namespace FlightComponents

namespace FlightPresentation {
ftxui::Component main();
}

namespace FlightRepository {
std::vector<std::vector<std::string>> get_all();
Entities::flight_entity* get_one_by_id(int id);
void create(Entities::flight_entity* entity);
void update(int id, Entities::flight_entity* entity);
void remove(int id);
}  // namespace FlightRepository

#endif