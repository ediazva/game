#include "engine/systems/hitbox.h"
#include "engine/components/velocity.h"
#include "engine/entity_manager.h"
#include "engine/components/position.h"
#include "engine/components/hitbox.h"
#include "raylib.h"
#include <memory>

#include <iostream>

namespace engine {

  /*
   * Reset basico de coordenadas
   * ??? El reset es interno del sistema???
   */
  void HitboxSystem::reset_entity(std::shared_ptr<Entity>& ent, const float& deltatime) {
    int rand_x = raylib::GetRandomValue(200, 1300);
    float vel = 300;

    ent->getComponent<PositionComponent>().coord = { (float)rand_x, 1000 };

    if(rand_x < 500) {
      ent->getComponent<VelocityComponent>().vector = { vel, -vel };
    } else {
      ent->getComponent<VelocityComponent>().vector = { -vel, -vel };
    }
  }

  /*
   * Detectamos eventos del mouse internamente
   * Hacemos un shift de la hitbox para que concuerde con el sprite
   * Asumimos que la hitbox es de las mismas dimensiones que el sprite(en lo posible)
   * TODO: ??? Es posible que se rompa en algun cuadrante negativo????
   */
  void HitboxSystem::update(const float& deltatime) {
    using namespace raylib;
    raylib::PollInputEvents();
    if(!IsMouseButtonDown(MOUSE_BUTTON_LEFT)) // Cambio a solo tap/cooldown
      return;

    // if(IsMouseButtonDown(MOUSE_BUTTON_LEFT))
    //   std::cout << "Hit" << std::endl;

    auto entities = entityMgr().getEntities<PositionComponent, HitboxComponent>();
    auto mouse_pos = raylib::GetMousePosition();
    // std::cout << mouse_pos.x << " " << mouse_pos.y << std::endl;

    for(auto& e : entities) {
      auto& position = e->getComponent<PositionComponent>();
      auto& hitbox = e->getComponent<HitboxComponent>();
      // Check si coords se encuentran dentro de hitbox
      auto x = mouse_pos.x - position.coord.x - hitbox.radius;
      auto y = mouse_pos.y - position.coord.y - hitbox.radius;
      if(sqrt(x * x + y * y) <= hitbox.radius) {
        std::cout << sqrt((mouse_pos.x - position.coord.x) * (mouse_pos.x - position.coord.x) +
                          (mouse_pos.y - position.coord.y) * (mouse_pos.y - position.coord.y))
                  << std::endl;

        reset_entity(e, deltatime);
      }
    }
  }
} // namespace engine
