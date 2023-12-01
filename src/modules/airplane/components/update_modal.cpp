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
namespace UpdateModal {
string id;
string model;
string manufacturer;
string capacity;
string length;
string height;
string speed;
string altitude;
string engine;

vector<string> airplane;

Component main(void (*on_cancel)(), void (*on_update)()) {
  auto on_cancel_click = [on_cancel] {
    id.clear();
    model.clear();
    manufacturer.clear();
    capacity.clear();
    length.clear();
    height.clear();
    speed.clear();
    altitude.clear();
    engine.clear();

    airplane.clear();

    on_cancel();
  };

  auto on_update_click = [on_cancel_click, on_update] {
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

    AirplaneRepository::update(stoi(id), &entity);

    on_update();
    on_cancel_click();
  };

  auto on_search_click = [] {
    auto airplane = AirplaneRepository::get_one_by_id(stoi(id));

    model = airplane->model;
    manufacturer = airplane->manufacturer;
    capacity = to_string(airplane->capacity);
    length = to_string(airplane->length);
    height = to_string(airplane->height);
    speed = to_string(airplane->speed);
    altitude = to_string(airplane->altitude);
    engine = airplane->engine;
  };

  auto id_input = InputComponent::main(&id, "Digite o id da aeronave", {});
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
  auto create_button = Button("Atualizar", on_update_click);
  auto search_button = Button("Buscar", on_search_click);

  auto container = Container::Vertical({
      Container::Horizontal({
          id_input,
          search_button,
      }),
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
                  height_input, speed_input, altitude_input, engine_input,
                  id_input, search_button] {
        return vbox({
            hbox(id_input->Render(), search_button->Render()),
            separator(),
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

  return ModalComponent::main("Atualizar aeronave", body, footer);
}
}  // namespace UpdateModal
}  // namespace AirplaneComponents