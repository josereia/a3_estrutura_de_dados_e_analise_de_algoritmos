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
namespace CreateModal {
string airplane_id;
string departure_date;
string arrival_date;
string departure_address;
string destination_address;

Component main(void (*on_cancel)(), void (*on_create)()) {
  auto on_cancel_click = [on_cancel] {
    airplane_id.clear();
    departure_date.clear();
    arrival_date.clear();
    departure_address.clear();
    destination_address.clear();

    on_cancel();
  };

  auto on_create_click = [on_cancel_click, on_create] {
    auto entity = flight_entity{
        .airplane_id = stoi(airplane_id),
        .departure_date = departure_date,
        .arrival_date = arrival_date,
        .departure_address = departure_address,
        .destination_address = destination_address,
    };

    FlightRepository::create(&entity);

    on_create();
    on_cancel_click();
  };

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
  auto create_button = Button("Criar", on_create_click);

  auto container = Container::Vertical({
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
                                   destination_address_input] {
    return vbox({
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

  return ModalComponent::main("Novo voo", body, footer);
}
}  // namespace CreateModal
}  // namespace FlightComponents