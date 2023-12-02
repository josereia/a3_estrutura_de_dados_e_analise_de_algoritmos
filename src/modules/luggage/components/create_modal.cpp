#include <string>
#include <vector>

#include <core/components/components.hpp>
#include <core/entities/entities.hpp>
#include "../luggage_module.hpp"
#include "ftxui/component/component.hpp"

using namespace std;
using namespace ftxui;
using namespace Entities;

namespace LuggageComponents {
namespace CreateModal {
string ticket_id;
string type;
string description;
string weight;

Component main(void (*on_cancel)(), void (*on_create)()) {
  auto on_cancel_click = [on_cancel] {
    ticket_id.clear();
    type.clear();
    description.clear();
    weight.clear();

    on_cancel();
  };

  auto on_create_click = [on_cancel_click, on_create] {
    auto entity = luggage_entity{
        .ticket_id = stoi(ticket_id),
        .type = type,
        .description = description,
        .weight = stof(weight),
    };

    LuggageRepository::create(&entity);

    on_create();
    on_cancel_click();
  };

  auto ticket_id_input =
      InputComponent::main(&ticket_id, "Digite id da passagem", {});
  auto type_input = InputComponent::main(&type, "Digite o tipo da bagagem", {});
  auto description_input = InputComponent::main(
      &description, "Digite uma descrição para a bagagem", {});
  auto weight_input =
      InputComponent::main(&weight, "Digite o peso da bagagem", {});

  auto cancel_button = Button("Cancelar", on_cancel_click);
  auto create_button = Button("Criar", on_create_click);

  auto container = Container::Vertical({
      ticket_id_input,
      type_input,
      description_input,
      weight_input,
      Container::Horizontal({
          cancel_button,
          create_button,
      }),
  });

  auto body = Renderer(
      container, [ticket_id_input, type_input, description_input, weight_input] {
        return vbox({
            hbox(text("Id da passagem: ") | center, ticket_id_input->Render()),
            hbox(text("Tipo: ") | center, type_input->Render()),
            hbox(text("Descrição: ") | center, description_input->Render()),
            hbox(text("Preso(Kg): ") | center, weight_input->Render()),
        });
      });

  auto footer = Renderer([cancel_button, create_button] {
    return hbox(cancel_button->Render(), create_button->Render());
  });

  return ModalComponent::main("Nova bagagem", body, footer);
}
}  // namespace CreateModal
}  // namespace LuggageComponents