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
  std::string departure_date;
  std::string arrival_date;
  std::string departure_address;
  std::string destination_address;
};
struct passenger_entity {
  int id;
  std::string name;
  std::string cpf;
  std::string passport;
  std::string birth_date;
  std::string email;
  std::string phone;
};
struct ticket_entity {
  int id;
  int flight_id;
  int passenger_id;
  std::string boarding_date;
  std::string boarding_gate;
  std::string seat;
};
}  // namespace Entities

#endif