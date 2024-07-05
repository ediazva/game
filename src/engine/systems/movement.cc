#include "engine/systems/movement.h"
#include "engine/components/bounce.h"
#include "engine/entity_manager.h"
#include "engine/assets/texture.h"
#include "engine/components/position.h"
#include "engine/components/velocity.h"
#include <cmath>

namespace engine {
  /*
   * Invierte dirección de vectores dependiendo de si esta en borde
   * TODO: Como saber los bordes de la ventana
   */
  bool MovementSystem::borderBounce(PositionComponent& position,
                                    VelocityComponent& velocity, const float& deltatime) {

    bool bounce = false;
    // Bordes, ????suma de threshold para que no sea tan exacto????
    if(position.coord.x + velocity.vector.x * deltatime < 0 ||
       position.coord.x + velocity.vector.x * deltatime > 1500) {
      velocity.vector.x *= -1;
      bounce = true;
    }

    if(position.coord.y + velocity.vector.y * deltatime < 0 ||
       position.coord.y + velocity.vector.y * deltatime > 1000) {
      velocity.vector.y *= -1;
      bounce = true;
    }
    return bounce;
  }

  void MovementSystem::randomBounce(PositionComponent& position, VelocityComponent& velocity,
                                    const float& deltatime) {
    float radius = std::sqrt(velocity.vector.x * velocity.vector.x +
                             velocity.vector.y * velocity.vector.y),
          ang = zero_2pi_dist(eng);
  }

  /*
   * Sistema que mueve patos
   * *** Proximamente se puede crear un sistema especifico para patos y
   * otro para particulas(Sin bounce) ***
   */
  void MovementSystem::update(const float& deltatime) {
    using namespace raylib;

    auto entidades =
        entityMgr().getEntities<PositionComponent, VelocityComponent, BounceComponent>();

    for(auto& e : entidades) {
      auto& position = e->getComponent<PositionComponent>();
      auto& velocity = e->getComponent<VelocityComponent>();
      auto& bounce = e->getComponent<BounceComponent>();

      if(~borderBounce(position, velocity, deltatime) && bounce.cooldown < 0) {
        randomBounce(position, velocity, deltatime);
      }

      position.coord.x += (velocity.vector.x) * deltatime;
      position.coord.y += (velocity.vector.y) * deltatime;
    }
  }
} // namespace engine
