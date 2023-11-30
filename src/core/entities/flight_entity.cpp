#include <string>

using namespace std;

struct flight_entity {
  string id;
  string airplane;
  string destination_address;
  string outgoing_address;
  time_t checkin_time;
  time_t checkout_time;
  int passengers;
};
