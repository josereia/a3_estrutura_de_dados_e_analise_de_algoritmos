#include <string>
#include <vector>

#include <core/components/components.hpp>
#include <core/entities/entities.hpp>
#include "../airplane_module.hpp"
#include "ftxui/component/component.hpp"

using namespace std;
using namespace ftxui;
using namespace Entities;

namespace AirplaneComponents {
namespace CreateModal {
string model;
string manufacturer;
string capacity;
string length;
string height;
string speed;
string altitude;
string engine;

Component main(void (*on_cancel)(), void (*on_create)()) {
  auto on_cancel_click = [on_cancel] {
    model.clear();
    manufacturer.clear();
    capacity.clear();
    length.clear();
    height.clear();
    speed.clear();
    altitude.clear();
    engine.clear();

    on_cancel();
  };

  auto on_create_click = [on_cancel_click, on_create] {
    auto entity = airplane_entity{
        .model = model,
        .manufacturer = manufacturer,
        .capacity = stoi(capacity),
        .length = stof(length),
        .height = stof(height),
        .speed = stof(speed),
        .altitude = stof(altitude),
        .engine = engine,
    };

    AirplaneRepository::create(&entity);

    on_create();
    on_cancel_click();
  };

  auto model_input = InputComponent::main(&model, "Digite o modelo", {});
  auto manufacturer_input =
      InputComponent::main(&manufacturer, "Digite o fabricante", {});
  auto capacity_input =
      InputComponent::main(&capacity, "Digite a capacidade", {});
  auto length_input = InputComponent::main(&length, "Digite o comprimento", {});
  auto height_input = InputComponent::main(&height, "Digite a altura", {});
  auto speed_input = InputComponent::main(&speed, "Digite a velocidade", {});
  auto altitude_input =
      InputComponent::main(&altitude, "Digite a altitude", {});
  auto engine_input = InputComponent::main(&engine, "Digite o motor", {});

  auto cancel_button = Button("Cancelar", on_cancel_click);
  auto create_button = Button("Criar", on_create_click);

  auto container = Container::Vertical({
      model_input,
      manufacturer_input,
      capacity_input,
      length_input,
      height_input,
      speed_input,
      altitude_input,
      engine_input,
      Container::Horizontal({
          cancel_button,
          create_button,
      }),
  });

  auto body = Renderer(
      container, [model_input, manufacturer_input, capacity_input, length_input,
                  height_input, speed_input, altitude_input, engine_input] {
        return vbox({
            hbox(text("Modelo: ") | center, model_input->Render()),
            hbox(text("Fabricante: ") | center, manufacturer_input->Render()),
            hbox(text("Capacidade: ") | center, capacity_input->Render()),
            hbox(text("Comprimento: ") | center, length_input->Render()),
            hbox(text("Altura: ") | center, height_input->Render()),
            hbox(text("Velocidade: ") | center, speed_input->Render()),
            hbox(text("Altitude: ") | center, altitude_input->Render()),
            hbox(text("Motor: ") | center, engine_input->Render()),
        });
      });

  auto footer = Renderer([cancel_button, create_button] {
    return hbox(cancel_button->Render(), create_button->Render());
  });

  return ModalComponent::main("Nova aeronave", body, footer);
}
}  // namespace CreateModal
}  // namespace AirplaneComponents