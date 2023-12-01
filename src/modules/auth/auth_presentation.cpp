#include <core/components/components.hpp>
#include <modules/manager/manager_module.hpp>
#include "ftxui/component/component.hpp"
#include "ftxui/component/screen_interactive.hpp"

using namespace std;
using namespace ftxui;

namespace AuthPresentation {
auto screen = ScreenInteractive::Fullscreen();

void login(string* username, string* password) {
  bool isLogged = *username == "admin" && *password == "admin";
  if (isLogged) {
    screen.ExitLoopClosure()();
    ManagerPresentation::main();
  }
}

void main() {
  string username;
  string password;

  auto input_option = InputOption{.multiline = false};
  auto username_input =
      InputComponent::main(&username, "Digite seu usuário", input_option);
  auto password_input =
      InputComponent::main(&password, "Digite sua senha", input_option);

  auto login_button = Button("Entrar", [&] { login(&username, &password); });

  auto layout = Container::Vertical({
      username_input,
      password_input,
      login_button,
  });

  auto renderer = Renderer(layout, [&] {
    return vbox({
        text("Orion Airlines") | bold,
        text("Faça login para acessar o sistema.") | border,
        filler(),
        vbox({
            vbox(text("Nome de usuário: "), username_input->Render()),
            vbox(text("Senha: "), password_input->Render()),
            separatorEmpty(),
            login_button->Render() | center,
        }) | border |
            center,
        filler(),
        FooterComponent::main(),
    });
  });

  screen.Loop(renderer);
}
}  // namespace AuthPresentation