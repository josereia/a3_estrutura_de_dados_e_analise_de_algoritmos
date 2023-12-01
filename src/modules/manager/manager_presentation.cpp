#include "ftxui/component/component.hpp"
#include "ftxui/component/screen_interactive.hpp"

#include <modules/airplane/airplane_module.hpp>
#include <modules/passenger/passenger_module.hpp>
#include <modules/flight/flight_module.hpp>
#include <modules/ticket/ticket_module.hpp>

using namespace std;
using namespace ftxui;

namespace ManagerPresentation {
auto screen = ScreenInteractive::Fullscreen();

void main() {
  int selected = 0;
  vector<string> tabs = {"Voos", "Aeronaves", "Passagens", "Passageiros"};

  auto toggle = Toggle(&tabs, &selected);
  auto container = Container::Tab(
      {
          FlightPresentation::main(),
          AirplanePresentation::main(),
          TicketPresentation::main(),
          PassengerPresentation::main(),
      },
      &selected);

  auto layout = Container::Vertical({
      toggle,
      container,
  });

  auto renderer = Renderer(layout, [toggle, container] {
    return vbox({
        toggle->Render(),
        separator(),
        container->Render(),
    });
  });

  screen.Loop(renderer);
}
}  // namespace ManagerPresentation