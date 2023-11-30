#include <modules/airplane/airplane_module.hpp>
#include <modules/flight/flight_module.hpp>
#include <string>
#include <vector>
#include "ftxui/component/component.hpp"
#include "ftxui/component/screen_interactive.hpp"

using namespace std;
using namespace ftxui;

namespace ManagerPresentation {
auto screen = ScreenInteractive::Fullscreen();

void main() {
  int selected = 0;
  vector<string> tabs = {"Voos", "Aeronaves", "Aeroportos", "Relatórios"};

  auto toggle = Toggle(&tabs, &selected);
  auto container = Container::Tab(
      {
          FlightPresentation::main(),
          AirplanePresentation::main(),
      },
      &selected);

  auto layout = Container::Vertical({
      toggle,
      container,
  });

  auto renderer = Renderer(layout, [&] {
    return vbox({
        toggle->Render(),
        separator(),
        container->Render(),
    });
  });

  screen.Loop(renderer);
}
}  // namespace ManagerPresentation