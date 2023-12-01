#include <string>

using namespace std;

namespace Entities {
struct flight_entity {
  int id;
  int airplane_id;
  string departure_address;
  string destination_address;
  int departure_date;
  int arrival_date;
};

}  // namespace Entities