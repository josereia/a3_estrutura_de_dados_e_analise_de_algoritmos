#ifndef luggage_module
#define luggage_module

#include <core/entities/entities.hpp>
#include "ftxui/component/component.hpp"

namespace LuggageComponents {
namespace CreateModal {
ftxui::Component main(void (*on_cancel)(), void (*on_create)());
}
namespace UpdateModal {
ftxui::Component main(void (*on_cancel)(), void (*on_delete)());
}
namespace DeleteModal {
ftxui::Component main(void (*on_cancel)(), void (*on_delete)());
}
}  // namespace LuggageComponents

namespace LuggagePresentation {
ftxui::Component main();
}

namespace LuggageRepository {
std::vector<std::vector<std::string>> get_all();
Entities::luggage_entity* get_one_by_id(int id);
void create(Entities::luggage_entity* entity);
void update(int id, Entities::luggage_entity* entity);
void remove(int id);
}  // namespace LuggageRepository

#endif