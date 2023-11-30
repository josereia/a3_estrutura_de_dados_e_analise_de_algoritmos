#ifndef components
#define components

#include <vector>
#include "ftxui/component/component.hpp"

using namespace std;
using namespace ftxui;

namespace TableComponent {
Element main(vector<vector<string>> data, vector<string> header);
}

#endif