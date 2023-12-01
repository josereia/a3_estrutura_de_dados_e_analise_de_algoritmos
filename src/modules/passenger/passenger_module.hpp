#ifndef passenger_module
#define passenger_module

#include <core/entities/entities.hpp>
#include "ftxui/component/component.hpp"

namespace PassengerComponents {
namespace CreateModal {
ftxui::Component main(void (*on_cancel)(), void (*on_create)());
}
namespace UpdateModal {
ftxui::Component main(void (*on_cancel)(), void (*on_delete)());
}
namespace DeleteModal {
ftxui::Component main(void (*on_cancel)(), void (*on_delete)());
}
}  // namespace PassengerComponents
namespace PassengerPresentation {
ftxui::Component main();
}

namespace PassengerRepository {
std::vector<std::vector<std::string>> get_all();
Entities::passenger_entity* get_one_by_id(int id);
void create(Entities::passenger_entity* entity);
void update(int id, Entities::passenger_entity* entity);
void remove(int id);
}  // namespace PassengerRepository

#endif