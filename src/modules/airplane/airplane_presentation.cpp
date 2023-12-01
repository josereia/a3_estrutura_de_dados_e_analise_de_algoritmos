#include <core/components/components.hpp>
#include <core/entities/entities.hpp>
#include <core/utils/utils.hpp>
#include "airplane_module.hpp"
#include "ftxui/component/component.hpp"
#include "ftxui/component/screen_interactive.hpp"

using namespace std;
using namespace ftxui;
using namespace Entities;

namespace AirplanePresentation {
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
  auto airplanes = AirplaneRepository::get_all();
  filtered = airplanes;
}

Component main() {
  vector<vector<string>> airplanes = AirplaneRepository::get_all();
  filtered = airplanes;

  auto search_input = InputComponent::main(
      &search, "Busque por aeronaves",
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
            "Id",     "Modelo",     "Fabricante", "Capacidade", "Comprimento",
            "Altura", "Velocidade", "Altitude",   "Motor",
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

  renderer |= Modal(AirplaneComponents::CreateModal::main(on_cancel, on_update),
                    &create_modal_shown);

  renderer |= Modal(AirplaneComponents::UpdateModal::main(on_cancel, on_update),
                    &update_modal_shown);

  renderer |= Modal(AirplaneComponents::DeleteModal::main(on_cancel, on_update),
                    &delete_modal_shown);

  return renderer;
}
}  // namespace AirplanePresentation