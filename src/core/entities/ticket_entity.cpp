#include <string>

using namespace std;

namespace Entities {
struct ticket_entity {
  int id;
  int flight_id;
  int passenger_id;
  int boarding_date;
  int boarding_gate;
  string seat;
};
}  // namespace Entities
