#include <string>
#include <vector>

#include <core/components/components.hpp>
#include <core/entities/entities.hpp>
#include "../ticket_module.hpp"
#include "ftxui/component/component.hpp"

using namespace std;
using namespace ftxui;
using namespace Entities;

namespace TicketComponents {
namespace CreateModal {
string flight_id;
string passenger_id;
string boarding_date;
string boarding_gate;
string seat;

Component main(void (*on_cancel)(), void (*on_create)()) {
  auto on_cancel_click = [on_cancel] {
    flight_id.clear();
    passenger_id.clear();
    boarding_date.clear();
    boarding_gate.clear();
    seat.clear();

    on_cancel();
  };

  auto on_create_click = [on_cancel_click, on_create] {
    auto entity = ticket_entity{
        .flight_id = stoi(flight_id),
        .passenger_id = stoi(passenger_id),
        .boarding_date = boarding_date,
        .boarding_gate = boarding_gate,
        .seat = seat,
    };

    TicketRepository::create(&entity);

    on_create();
    on_cancel_click();
  };

  auto flight_id_input =
      InputComponent::main(&flight_id, "Digite id do voo", {});
  auto passenger_id_input =
      InputComponent::main(&passenger_id, "Digite o id do passageiro", {});
  auto boarding_date_input =
      InputComponent::main(&boarding_date, "Digite a data de embarque", {});
  auto boarding_gate_input =
      InputComponent::main(&boarding_gate, "Digite o portão de embarque", {});
  auto seat_input =
      InputComponent::main(&seat, "Digite o código do assento", {});

  auto cancel_button = Button("Cancelar", on_cancel_click);
  auto create_button = Button("Criar", on_create_click);

  auto container = Container::Vertical({
      flight_id_input,
      passenger_id_input,
      boarding_date_input,
      boarding_gate_input,
      seat_input,
      Container::Horizontal({
          cancel_button,
          create_button,
      }),
  });

  auto body = Renderer(container, [flight_id_input, passenger_id_input,
                                   boarding_date_input, boarding_gate_input,
                                   seat_input] {
    return vbox({
        hbox(text("Id do voo: ") | center, flight_id_input->Render()),
        hbox(text("Id do passageiro: ") | center, passenger_id_input->Render()),
        hbox(text("Data de embarque: ") | center,
             boarding_date_input->Render()),
        hbox(text("Portão de embarque: ") | center,
             boarding_gate_input->Render()),
        hbox(text("Assento: ") | center, seat_input->Render()),
    });
  });

  auto footer = Renderer([cancel_button, create_button] {
    return hbox(cancel_button->Render(), create_button->Render());
  });

  return ModalComponent::main("Nova passagem", body, footer);
}
}  // namespace CreateModal
}  // namespace TicketComponents