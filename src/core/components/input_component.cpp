#include "ftxui/component/component.hpp"

using namespace std;
using namespace ftxui;

namespace InputComponent {
Component main(StringRef content, string placeholder, InputOption option) {
  return Input(content, placeholder, option) | border;
}
}  // namespace InputComponent