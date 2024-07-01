#include "engine/systems/hitbox.h"
#include "engine/components/velocity.h"
#include "engine/entity_manager.h"
#include "engine/components/position.h"
#include "engine/components/hitbox.h"
#include "raylib.h"
#include <memory>

namespace engine {

  /*
   * Reset basico de coordenadas
   * ??? El reset es interno del sistema???
   */
  void HitboxSystem::reset_entity(std::shared_ptr<Entity>& ent) {
    int rand_x = raylib::GetRandomValue(200, 1300);
    ent->getComponent<PositionComponent>().coord = { (float)rand_x, 1000 };

    if(rand_x < 500) {
      ent->getComponent<VelocityComponent>().vector = { 30, -30 };
    } else {
      ent->getComponent<VelocityComponent>().vector = { -30, -30 };
    }
  }
  void HitboxSystem::update(const float& deltatime) {
    using namespace raylib;

    auto entities = entityMgr().getEntities<PositionComponent, HitboxComponent>();
    auto mouse_pos = raylib::GetMousePosition();

    for(auto& e : entities) {
      auto& position = e->getComponent<PositionComponent>();
      auto& hitbox = e->getComponent<HitboxComponent>();
      // std::cout << sqrt((mouse_pos.x - ptr_pos->coord.x) * (mouse_pos.x - ptr_pos->coord.x) +
      //                   (mouse_pos.y - ptr_pos->coord.y) * (mouse_pos.y - ptr_pos->coord.y))
      //           << std::endl;

      // Check si coords se encuentran dentro de hitbox
      if(sqrt(
             (mouse_pos.x - position.coord.x) * (mouse_pos.x - position.coord.x) +
             (mouse_pos.y - position.coord.y) * (mouse_pos.y - position.coord.y)) <=
         hitbox.radius) {
        reset_entity(e);
      }
    }
  }
} // namespace engine
