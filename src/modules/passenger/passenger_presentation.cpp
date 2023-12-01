#include <core/components/components.hpp>
#include <core/utils/utils.hpp>
#include "ftxui/component/component.hpp"
#include "ftxui/component/screen_interactive.hpp"
#include "passenger_module.hpp"

using namespace std;
using namespace ftxui;

namespace PassengerPresentation {
string search;
bool create_modal_shown = false;
bool update_modal_shown = false;
bool delete_modal_shown = false;

vector<vector<string>> filtered = {};

void on_cancel() {
  create_modal_shown = false;
  update_modal_shown = false;
  delete_modal_shown = false;
}

void on_update() {
  auto flights = PassengerRepository::get_all();
  filtered = flights;
}

Component main() {
  vector<vector<string>> airplanes = PassengerRepository::get_all();
  filtered = airplanes;

  auto search_input = InputComponent::main(
      &search, "Busque por passageiros",
      {
          .multiline = false,
          .on_change =
              [airplanes] { filtered = Utils::filter(airplanes, search); },
      });

  auto new_button = Button("Novo", [] { create_modal_shown = true; });
  auto update_button = Button("Atualizar", [] { update_modal_shown = true; });
  auto delete_button = Button("Excluir", [] { delete_modal_shown = true; });

  auto layout = Container::Vertical({
      Container::Horizontal({
          search_input,
          new_button,
          update_button,
          delete_button,
      }),
  });

  auto renderer = Renderer(
      layout, [search_input, new_button, update_button, delete_button] {
        vector<string> table_header = {
            "Id",    "Nome",     "CPF", "Passaporte", "Data de nascimento",
            "Email", "Telefone",
        };
        auto table = TableComponent::main(filtered, table_header);

        return vbox({
            hbox({
                search_input->Render(),
                separatorEmpty(),
                new_button->Render(),
                update_button->Render(),
                delete_button->Render(),
            }),
            flex_grow(table | frame),
        });
      });

  renderer |=
      Modal(PassengerComponents::CreateModal::main(on_cancel, on_update),
            &create_modal_shown);

  renderer |=
      Modal(PassengerComponents::UpdateModal::main(on_cancel, on_update),
            &update_modal_shown);

  renderer |=
      Modal(PassengerComponents::DeleteModal::main(on_cancel, on_update),
            &delete_modal_shown);

  return renderer;
}
}  // namespace PassengerPresentation