#include <core/components/components.hpp>
#include "ftxui/component/component.hpp"
#include "ftxui/component/screen_interactive.hpp"

using namespace std;
using namespace ftxui;

namespace FlightPresentation {
Component main() {
  auto layout = Container::Vertical({});

  auto renderer = Renderer(layout, [] {
    auto table = TableComponent::main({{}}, {""});

    return vbox({flex_grow(table | frame)});
  });

  return renderer;
}
}  // namespace FlightPresentation