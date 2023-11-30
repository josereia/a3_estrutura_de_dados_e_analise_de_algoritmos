#ifndef drivers
#define drivers

#include <sqlite3.h>
#include <fstream>
#include <string>

using namespace std;

namespace DatabaseDriver {
void init(sqlite3** db, string path);
}

namespace StorageDriver {
ifstream open_file(string path);
string read_file(string path);
}  // namespace StorageDriver

#endif