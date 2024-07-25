#include "engine/systems/movement.h"
#include "engine/components/bounce.h"
#include "engine/components/hitbox.h"
#include "engine/entity_manager.h"
#include "engine/assets/texture.h"
#include "engine/components/position.h"
#include "engine/components/velocity.h"
#include <cmath>

#include <iostream>

namespace engine {
  /*
   * Invierte dirección de vectores dependiendo de si esta en borde
   * TODO: Tomar en cuenta la hitbox del objeto/sprite
   */
  bool MovementSystem::borderBounce(PositionComponent& position,
                                    VelocityComponent& velocity, float deltatime) {

    bool bounced = false;
    // Bordes, ????suma de threshold para que no sea tan exacto????
    if(position.coord.x + velocity.vector.x * deltatime < 0 ||
       position.coord.x + velocity.vector.x * deltatime > 1500) {
      velocity.vector.x *= -1;
      bounced = true;
    }

    if(position.coord.y + velocity.vector.y * deltatime < 0 ||
       position.coord.y + velocity.vector.y * deltatime > 1000) {
      velocity.vector.y *= -1;
      bounced = true;
    }
    return bounced;
  }

  void MovementSystem::randomBounce(PositionComponent& position, VelocityComponent& velocity,
                                    float deltatime) {
    float radius = std::sqrt(velocity.vector.x * velocity.vector.x +
                             velocity.vector.y * velocity.vector.y),
          ang = zero_2pi_dist(eng);
    velocity.vector.x = radius * std::sin(ang);
    velocity.vector.y = radius * std::cos(ang);
  }

  /*
   * Sistema que mueve patos y realiza los "bounces"
   * *** Proximamente se puede crear un sistema especifico para patos y
   * otro para particulas(Sin bounce) ***
   */
  void MovementSystem::update(float deltatime) {
    using namespace raylib;

    auto entidades =
        entityMgr()
            .getEntities<PositionComponent, VelocityComponent, BounceComponent, HitboxComponent>();

    for(auto& e : entidades) {
      auto& position = e->getComponent<PositionComponent>();
      auto& velocity = e->getComponent<VelocityComponent>();
      auto& bounce = e->getComponent<BounceComponent>();
      auto& hitbox = e->getComponent<HitboxComponent>();

      if(hitbox.alive && ~borderBounce(position, velocity, deltatime) && bounce.cooldown < 0) {
        randomBounce(position, velocity, deltatime);
        bounce.cooldown = BounceComponent::max_cooldown;
      }

      position.coord.x += (velocity.vector.x) * deltatime;
      position.coord.y += (velocity.vector.y) * deltatime;
      bounce.cooldown -= 10;
    }
  }
} // namespace engine
