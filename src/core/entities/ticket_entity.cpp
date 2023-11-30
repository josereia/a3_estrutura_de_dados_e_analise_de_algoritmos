#include <string>

using namespace std;

struct ticket_entity {
  string id;
  string flight;
  time_t shipping_date;
  time_t boarding_time;
  string boarding_gate;
};
