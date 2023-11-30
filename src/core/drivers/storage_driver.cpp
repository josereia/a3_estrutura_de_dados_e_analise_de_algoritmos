#include <fstream>
#include <string>

using namespace std;

namespace StorageDriver {
/// @brief open a file stream
/// @param path file path
/// @return file stream (ifstream)
ifstream open_file(string path) {
  ifstream file;

  file.open(path);
  return file;
}

/// @brief read a file content as string
/// @param path file path
/// @return file content (string)
string read_file(string path) {
  ifstream file = open_file(path);
  string content = "";

  if (file.is_open()) {
    string line;

    while (getline(file, line)) {
      content += line + "\n";
    }

    file.close();
  }

  return content;
}
}  // namespace StorageDriver