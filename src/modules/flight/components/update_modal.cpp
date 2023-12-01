#include <string>
#include <vector>

#include <core/components/components.hpp>
#include <core/entities/entities.hpp>
#include "../flight_module.hpp"
#include "ftxui/component/component.hpp"

using namespace std;
using namespace ftxui;
using namespace Entities;

namespace FlightComponents {
namespace UpdateModal {
string id;
string airplane_id;
string departure_date;
string arrival_date;
string departure_address;
string destination_address;

vector<string> flight;

Component main(void (*on_cancel)(), void (*on_update)()) {
  auto on_cancel_click = [on_cancel] {
    id.clear();
    airplane_id.clear();
    departure_date.clear();
    arrival_date.clear();
    departure_address.clear();
    destination_address.clear();

    flight.clear();

    on_cancel();
  };

  auto on_update_click = [on_cancel_click, on_update] {
    auto entity = flight_entity{
        .airplane_id = stoi(airplane_id),
        .departure_date = departure_date,
        .arrival_date = arrival_date,
        .departure_address = departure_address,
        .destination_address = destination_address,
    };

    FlightRepository::update(stoi(id), &entity);

    on_update();
    on_cancel_click();
  };

  auto on_search_click = [] {
    auto flight = FlightRepository::get_one_by_id(stoi(id));

    airplane_id = to_string(flight->airplane_id);
    departure_date = flight->departure_date;
    arrival_date = flight->arrival_date;
    departure_address = flight->departure_address;
    destination_address = flight->destination_address;
  };

  auto id_input = InputComponent::main(&id, "Digite o id da aeronave", {});
  auto airplane_id_input =
      InputComponent::main(&airplane_id, "Digite o id da aeronave", {});
  auto departure_date_input =
      InputComponent::main(&departure_date, "Digite a data de embarque", {});
  auto arrival_date_input =
      InputComponent::main(&arrival_date, "Digite a data de chegada", {});
  auto departure_address_input = InputComponent::main(
      &departure_address, "Digite o endereço de embarque", {});
  auto destination_address_input = InputComponent::main(
      &destination_address, "Digite o endereço de destino", {});

  auto cancel_button = Button("Cancelar", on_cancel_click);
  auto create_button = Button("Atualizar", on_update_click);
  auto search_button = Button("Buscar", on_search_click);

  auto container = Container::Vertical({
      Container::Horizontal({
          id_input,
          search_button,
      }),
      airplane_id_input,
      departure_date_input,
      arrival_date_input,
      departure_address_input,
      destination_address_input,
      Container::Horizontal({
          cancel_button,
          create_button,
      }),
  });

  auto body = Renderer(container, [airplane_id_input, departure_date_input,
                                   arrival_date_input, departure_address_input,
                                   destination_address_input, id_input,
                                   search_button] {
    return vbox({
        hbox(id_input->Render(), search_button->Render()),
        separator(),
        hbox(text("Id da aeronave: ") | center, airplane_id_input->Render()),
        hbox(text("Data de embarque: ") | center,
             departure_date_input->Render()),
        hbox(text("Data de chegada: ") | center, arrival_date_input->Render()),
        hbox(text("Endereço de embarque: ") | center,
             departure_address_input->Render()),
        hbox(text("Endereço de destino: ") | center,
             destination_address_input->Render()),

    });
  });

  auto footer = Renderer([cancel_button, create_button] {
    return hbox(cancel_button->Render(), create_button->Render());
  });

  return ModalComponent::main("Atualizar voo", body, footer);
}
}  // namespace UpdateModal
}  // namespace FlightComponents