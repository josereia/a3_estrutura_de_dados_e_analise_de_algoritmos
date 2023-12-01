#ifndef entities
#define entities

#include <string>

namespace Entities {
struct airplane_entity {
  int id;
  std::string model;
  std::string manufacturer;
  int capacity;
  float length;
  float height;
  float speed;
  float altitude;
  std::string engine;
};
struct flight_entity {
  int id;
  int airplane_id;
  std::string departure_address;
  std::string destination_address;
  int departure_date;
  int arrival_date;
};
struct passenger_entity {
  int id;
  std::string name;
  std::string cpf;
  std::string passport;
  int birth_date;
  std::string email;
  std::string phone;
};
struct ticket_entity {
  int id;
  int flight_id;
  int passenger_id;
  int boarding_date;
  int boarding_gate;
  std::string seat;
};
}  // namespace Entities

#endif