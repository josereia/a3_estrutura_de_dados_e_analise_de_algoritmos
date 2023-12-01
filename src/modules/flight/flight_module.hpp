#ifndef flight_module
#define flight_module

#include <core/entities/entities.hpp>
#include "ftxui/component/component.hpp"

namespace FlightPresentation {
ftxui::Component main();
}

namespace FlightRepository {
std::vector<std::vector<std::string>> get_all();
Entities::flight_entity* get_one_by_id(int id);
}  // namespace FlightRepository

#endif