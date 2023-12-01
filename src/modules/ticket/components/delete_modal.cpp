#include <string>

#include <core/components/components.hpp>
#include "../ticket_module.hpp"

using namespace std;
using namespace ftxui;

namespace TicketComponents {
namespace DeleteModal {
string id;

Component main(void (*on_cancel)(), void (*on_delete)()) {
  auto on_cancel_click = [on_cancel] {
    id.clear();
    on_cancel();
  };

  auto on_delete_click = [on_cancel_click, on_delete] {
    TicketRepository::remove(stoi(id));

    on_delete();
    on_cancel_click();
  };

  auto id_input = InputComponent::main(&id, "Digite o id do passageiro", {});

  auto cancel_button = Button("Cancelar", on_cancel_click);
  auto delete_button = Button("Excluir", on_delete_click);

  auto container = Container::Vertical({
      id_input,
      Container::Horizontal({
          cancel_button,
          delete_button,
      }),
  });

  auto body = Renderer(container, [id_input] {
    return vbox({
        hbox(text("Id do passageiro: ") | center, id_input->Render()),
    });
  });

  auto footer = Renderer([cancel_button, delete_button] {
    return hbox(cancel_button->Render(), delete_button->Render());
  });

  return ModalComponent::main("Excluir passageiro", body, footer);
}
}  // namespace DeleteModal
}  // namespace TicketComponents