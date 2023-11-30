#include <string>

using namespace std;

struct flight_entity {
  int id;
  string airplane;
  string outgoing_address;
  string destination_address;
  int checkin_time;
  int checkout_time;
  int passengers;
};
