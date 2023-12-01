#include <core/components/components.hpp>
#include <core/utils/utils.hpp>
#include "ftxui/component/component.hpp"
#include "ftxui/component/screen_interactive.hpp"
#include "ticket_module.hpp"

using namespace std;
using namespace ftxui;

namespace TicketPresentation {
string search;
bool create_modal_shown = false;
bool update_modal_shown = false;
bool delete_modal_shown = false;

vector<vector<string>> filtered = {};

Component main() {
  vector<vector<string>> airplanes = TicketRepository::get_all();
  filtered = airplanes;

  auto search_input = InputComponent::main(
      &search, "Busque por passagens",
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
            "Id",
            "Voo",
            "Passageiro",
            "Data de embarque",
            "Portão de embarque",
            "Assento",
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

  return renderer;
}
}  // namespace TicketPresentation