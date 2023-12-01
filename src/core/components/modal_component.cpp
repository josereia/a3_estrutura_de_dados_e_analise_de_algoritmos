#include <string>
#include <vector>

#include <ftxui/component/component.hpp>
#include "components.hpp"

namespace ModalComponent {
using namespace std;
using namespace ftxui;

Component main(string title, Component body, Component footer) {
  auto renderer = Renderer(body, [title, body, footer] {
    return vbox({
               hbox({
                   text(title) | bold | center,
               }),
               separator(),
               body->Render(),
               separator(),
               footer->Render() | align_right,
           }) |
           border | center;
  });

  return renderer;
}
}  // namespace ModalComponent