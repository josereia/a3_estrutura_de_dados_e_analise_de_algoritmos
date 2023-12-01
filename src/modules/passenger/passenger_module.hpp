#ifndef passenger_module
#define passenger_module

#include <core/entities/entities.hpp>
#include "ftxui/component/component.hpp"

namespace PassengerPresentation {
ftxui::Component main();
}

namespace PassengerRepository {
std::vector<std::vector<std::string>> get_all();
Entities::passenger_entity* get_one_by_id(int id);
}  // namespace PassengerRepository

#endif