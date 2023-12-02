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
namespace UpdateModal {
string id;
string ticket_id;
string type;
string description;
string weight;

vector<string> luggage;

Component main(void (*on_cancel)(), void (*on_update)()) {
  auto on_cancel_click = [on_cancel] {
    id.clear();
    ticket_id.clear();
    type.clear();
    description.clear();
    weight.clear();

    luggage.clear();

    on_cancel();
  };

  auto on_update_click = [on_cancel_click, on_update] {
    auto entity = luggage_entity{
        .ticket_id = stoi(ticket_id),
        .type = type,
        .description = description,
        .weight = stof(weight),
    };

    LuggageRepository::update(stoi(id), &entity);

    on_update();
    on_cancel_click();
  };

  auto on_search_click = [] {
    auto luggage = LuggageRepository::get_one_by_id(stoi(id));

    ticket_id = to_string(luggage->ticket_id);
    type = luggage->type;
    description = luggage->description;
    weight = to_string(luggage->weight);
  };

  auto id_input = InputComponent::main(&id, "Digite o id da bagagem", {});
  auto ticket_id_input =
      InputComponent::main(&ticket_id, "Digite id da passagem", {});
  auto type_input = InputComponent::main(&type, "Digite o tipo da bagagem", {});
  auto description_input = InputComponent::main(
      &description, "Digite uma descrição para a bagagem", {});
  auto weight_input =
      InputComponent::main(&weight, "Digite o peso da bagagem", {});

  auto cancel_button = Button("Cancelar", on_cancel_click);
  auto create_button = Button("Atualizar", on_update_click);
  auto search_button = Button("Buscar", on_search_click);

  auto container = Container::Vertical({
      Container::Horizontal({
          id_input,
          search_button,
      }),
      ticket_id_input,
      type_input,
      description_input,
      weight_input,
      Container::Horizontal({
          cancel_button,
          create_button,
      }),
  });

  auto body =
      Renderer(container, [ticket_id_input, type_input, description_input,
                           weight_input, id_input, search_button] {
        return vbox({
            hbox(id_input->Render(), search_button->Render()),
            separator(),
            hbox(text("Id da passagem: ") | center, ticket_id_input->Render()),
            hbox(text("Tipo: ") | center, type_input->Render()),
            hbox(text("Descrição: ") | center, description_input->Render()),
            hbox(text("Preso(Kg): ") | center, weight_input->Render()),
        });
      });

  auto footer = Renderer([cancel_button, create_button] {
    return hbox(cancel_button->Render(), create_button->Render());
  });

  return ModalComponent::main("Atualizar bagagem", body, footer);
}
}  // namespace UpdateModal
}  // namespace LuggageComponents