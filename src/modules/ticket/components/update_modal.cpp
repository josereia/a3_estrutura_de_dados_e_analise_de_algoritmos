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
namespace UpdateModal {
string id;
string flight_id;
string passenger_id;
string boarding_date;
string boarding_gate;
string seat;

vector<string> ticket;

Component main(void (*on_cancel)(), void (*on_update)()) {
  auto on_cancel_click = [on_cancel] {
    id.clear();
    flight_id.clear();
    passenger_id.clear();
    boarding_date.clear();
    boarding_gate.clear();
    seat.clear();

    ticket.clear();

    on_cancel();
  };

  auto on_update_click = [on_cancel_click, on_update] {
    auto entity = ticket_entity{
        .flight_id = stoi(flight_id),
        .passenger_id = stoi(passenger_id),
        .boarding_date = boarding_date,
        .boarding_gate = boarding_gate,
        .seat = seat,
    };

    TicketRepository::update(stoi(id), &entity);

    on_update();
    on_cancel_click();
  };

  auto on_search_click = [] {
    auto ticket = TicketRepository::get_one_by_id(stoi(id));

    flight_id = to_string(ticket->flight_id);
    passenger_id = to_string(ticket->passenger_id);
    boarding_date = ticket->boarding_date;
    boarding_gate = ticket->boarding_gate;
    seat = ticket->seat;
  };

  auto id_input = InputComponent::main(&id, "Digite o id da aeronave", {});
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
  auto create_button = Button("Atualizar", on_update_click);
  auto search_button = Button("Buscar", on_search_click);

  auto container = Container::Vertical({
      Container::Horizontal({
          id_input,
          search_button,
      }),
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
                                   seat_input, id_input, search_button] {
    return vbox({
        hbox(id_input->Render(), search_button->Render()),
        separator(),
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

  return ModalComponent::main("Atualizar passagem", body, footer);
}
}  // namespace UpdateModal
}  // namespace TicketComponents