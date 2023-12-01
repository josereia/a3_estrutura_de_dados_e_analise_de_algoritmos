#ifndef airplane_module
#define airplane_module

#include <core/entities/entities.hpp>
#include "ftxui/component/component.hpp"

namespace AirplanePresentation {
ftxui::Component main();
}

namespace AirplaneRepository {
std::vector<std::vector<std::string>> get_all();
Entities::airplane_entity* get_one_by_id(int id);
}  // namespace AirplaneRepository

#endif