#include <modules/manager/manager_module.hpp>
#include <string>
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

  auto username_input = Input(&username, "Digite seu usuário");
  auto password_input = Input(&password, "Digite sua senha");

  auto login_button = Button("Entrar", [&] { login(&username, &password); });

  auto layout = Container::Vertical({
      username_input,
      password_input,
      login_button,
  });

  auto renderer = Renderer(layout, [&] {
    return vbox({
        vbox(text("Orion Airlines") | bold,
             text("Faça login para acessar o sistema.")),
        separator(),
        vbox(text("Nome de usuário: "), username_input->Render() | border),
        vbox(text("Senha: "), password_input->Render() | border),
        separatorEmpty(),
        login_button->Render() | center,
    });
  });

  screen.Loop(renderer);
}
}  // namespace AuthPresentation