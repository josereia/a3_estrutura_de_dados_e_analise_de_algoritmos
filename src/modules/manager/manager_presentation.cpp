#include <core/components/components.hpp>
#include <modules/airplane/airplane_module.hpp>
#include <modules/flight/flight_module.hpp>
#include <modules/passenger/passenger_module.hpp>
#include <modules/ticket/ticket_module.hpp>
#include "ftxui/component/component.hpp"
#include "ftxui/component/screen_interactive.hpp"

using namespace std;
using namespace ftxui;

namespace ManagerPresentation {
auto screen = ScreenInteractive::Fullscreen();

void main() {
  int selected = 0;
  vector<string> tabs = {"Vôos", "Aeronaves", "Passagens", "Passageiros"};

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
        text("Orion Airlines") | bold,
        toggle->Render() | border,
        container->Render(),
        filler(),
        FooterComponent::main(),
    });
  });

  screen.Loop(renderer);
}
}  // namespace ManagerPresentation