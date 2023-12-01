#include <string>
#include <vector>

#include <core/components/components.hpp>
#include <core/entities/entities.hpp>
#include "../passenger_module.hpp"
#include "ftxui/component/component.hpp"

using namespace std;
using namespace ftxui;
using namespace Entities;

namespace PassengerComponents {
namespace CreateModal {
string name;
string cpf;
string passport;
string birth_date;
string email;
string phone;

Component main(void (*on_cancel)(), void (*on_create)()) {
  auto on_cancel_click = [on_cancel] {
    name.clear();
    cpf.clear();
    passport.clear();
    birth_date.clear();
    email.clear();
    phone.clear();

    on_cancel();
  };

  auto on_create_click = [on_cancel_click, on_create] {
    auto entity = passenger_entity{
        .name = name,
        .cpf = cpf,
        .passport = passport,
        .birth_date = birth_date,
        .email = email,
        .phone = phone,
    };

    PassengerRepository::create(&entity);

    on_create();
    on_cancel_click();
  };

  auto name_input = InputComponent::main(&name, "Digite o nome", {});
  auto cpf_input = InputComponent::main(&cpf, "Digite o CPF", {});
  auto passport_input =
      InputComponent::main(&passport, "Digite o passaporte", {});
  auto birth_date_input =
      InputComponent::main(&birth_date, "Digite a data de nascimento", {});
  auto email_input = InputComponent::main(&email, "Digite o e-mail", {});
  auto phone_input = InputComponent::main(&phone, "Digite o telefone", {});

  auto cancel_button = Button("Cancelar", on_cancel_click);
  auto create_button = Button("Criar", on_create_click);

  auto container = Container::Vertical({
      name_input,
      cpf_input,
      passport_input,
      birth_date_input,
      email_input,
      phone_input,
      Container::Horizontal({
          cancel_button,
          create_button,
      }),
  });

  auto body = Renderer(container, [name_input, cpf_input, passport_input,
                                   birth_date_input, email_input, phone_input] {
    return vbox({
        hbox(text("Nome: ") | center, name_input->Render()),
        hbox(text("CPF: ") | center, cpf_input->Render()),
        hbox(text("Passaporte: ") | center, passport_input->Render()),
        hbox(text("Data de nascimento: ") | center, birth_date_input->Render()),
        hbox(text("E-mail: ") | center, email_input->Render()),
        hbox(text("Telefone: ") | center, phone_input->Render()),
    });
  });

  auto footer = Renderer([cancel_button, create_button] {
    return hbox(cancel_button->Render(), create_button->Render());
  });

  return ModalComponent::main("Novo passageiro", body, footer);
}
}  // namespace CreateModal
}  // namespace PassengerComponents