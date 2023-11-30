#include "ftxui/component/component.hpp"
#include "ftxui/component/screen_interactive.hpp"

#include <core/components/components.hpp>

using namespace std;
using namespace ftxui;

namespace TicketPresentation {
Component main() {
  auto layout = Container::Vertical({});

  auto renderer = Renderer(layout, [] {
    vector<string> table_header = {
        "Id", "Voo", "Embarque", "Portão", "Assento", "Bagagem",
    };
    auto table = TableComponent::main({{}}, table_header);

    return vbox({flex_grow(table | frame)});
  });

  return renderer;
}
}  // namespace TicketPresentation
