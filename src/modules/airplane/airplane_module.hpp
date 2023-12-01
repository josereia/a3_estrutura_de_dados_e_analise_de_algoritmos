#ifndef airplane_module
#define airplane_module

#include <core/entities/entities.hpp>
#include "ftxui/component/component.hpp"

namespace AirplaneComponents {
namespace CreateModal {
ftxui::Component main(void (*on_cancel)(), void (*on_create)());
}
namespace UpdateModal {
ftxui::Component main(void (*on_cancel)(), void (*on_delete)());
}
namespace DeleteModal {
ftxui::Component main(void (*on_cancel)(), void (*on_delete)());
}
}  // namespace AirplaneComponents

namespace AirplanePresentation {
ftxui::Component main();
}

namespace AirplaneRepository {
std::vector<std::vector<std::string>> get_all();
Entities::airplane_entity* get_one_by_id(int id);
void create(Entities::airplane_entity* entity);
void update(int id, Entities::airplane_entity* entity);
void remove(int id);
}  // namespace AirplaneRepository

#endif