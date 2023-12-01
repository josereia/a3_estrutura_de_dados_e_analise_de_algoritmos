#include "ftxui/component/component.hpp"

using namespace ftxui;

namespace FooterComponent {
Element main() {
  return hbox({

             text("Pressione 'CTRL + C' para sair"),
             filler(),
             text("© SoftYes TI"),
             separatorEmpty(),
             separator(),
             separatorEmpty(),
             text("Versão 0.0.1"),
         }) |
         border;
}
}  // namespace FooterComponent