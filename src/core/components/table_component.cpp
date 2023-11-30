#include <ftxui/dom/table.hpp>

#include "ftxui/component/component.hpp"
#include "ftxui/component/screen_interactive.hpp"

using namespace std;
using namespace ftxui;

namespace TableComponent {
Element main(vector<vector<string>> data, vector<string> header) {
  data.insert(data.begin(), {header});
  auto table = Table(data);

  table.SelectAll().Border(LIGHT);
  table.SelectAll().Separator(LIGHT);
  table.SelectAll().DecorateAlternateRow(bgcolor(Color::Grey27), 2, 1);

  if (data.size() > 0) {
    table.SelectColumn(0).Border(LIGHT);
    table.SelectRow(0).Decorate(bold);
    table.SelectRow(0).SeparatorVertical(LIGHT);
    table.SelectRow(0).Border(DOUBLE);
  }

  return table.Render();
}
}  // namespace TableComponent