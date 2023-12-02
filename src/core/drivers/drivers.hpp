#ifndef drivers
#define drivers

#include <sqlite3.h>
#include <fstream>
#include <string>
#include <vector>

namespace DatabaseDriver {
void init(sqlite3** db);
std::vector<std::vector<std::string>> query(std::string query,
                                            std::vector<std::string> bindings);
}  // namespace DatabaseDriver

namespace StorageDriver {
std::ifstream open_file(std::string path);
std::string read_file(std::string path);
}  // namespace StorageDriver

#endif