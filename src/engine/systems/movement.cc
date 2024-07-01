#include "engine/systems/movement.h"
#include "engine/entity_manager.h"
#include "engine/assets/texture.h"
#include "engine/components/position.h"
#include "engine/components/velocity.h"

namespace engine {
  void MovementSystem::update(const float& deltatime) {
    using namespace raylib;

    auto entidades = entityMgr().getEntities<PositionComponent, VelocityComponent>();

    for(auto& e : entidades) {
      auto& position = e->getComponent<PositionComponent>();
      auto& velocity = e->getComponent<VelocityComponent>();
      position.coord.x += (velocity.vector.x) * deltatime;
      position.coord.y += (velocity.vector.y) * deltatime;
    }
  }
} // namespace engine
