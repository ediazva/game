#include "engine/systems/hitbox.h"
#include "engine/components/animation.h"
#include "engine/components/shoot.h"
#include "engine/components/sprite.h"
#include "engine/components/velocity.h"
#include "engine/debug.h"
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
  void HitboxSystem::reset_entity(std::shared_ptr<Entity>& ent, float deltatime) {
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
  void HitboxSystem::update(float deltatime) {
    using namespace raylib;
    // raylib::PollInputEvents();
    if(!IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) // Cambio a solo tap/cooldown
      return;

    // if(IsMouseButtonDown(MOUSE_BUTTON_LEFT))

    auto players = entityMgr().getEntities<ShootComponent>();
    if(players.empty())
      return;

    auto player = players.at(0);
    auto& shoot = player->getComponent<ShootComponent>();
    // std::cout << shoot.shootCooldown << std::endl;

    std::cout << "Cooldown: " << shoot.shootCooldown << std::endl;
    std::cout << "Curr bullets: " << shoot.bullets << std::endl;

    if(shoot.bullets <= 0 || shoot.shootCooldown > 0)
      return;

    shoot.bullets--;
    shoot.shootCooldown = shoot.maxShootCooldown;

    auto hittableEntities =
        entityMgr()
            .getEntities<PositionComponent, HitboxComponent, AnimationComponent, SpriteComponent, VelocityComponent>();
    // auto mouse_pos = raylib::GetMousePosition();
    // std::cout << mouse_pos.x << " " << mouse_pos.y << std::endl;

    // std::cout << "Cooldown: " << shoot.shootCooldown << std::endl;
    // std::cout << "Curr bullets: " << shoot.bullets << std::endl;
    std::cout << "Shot" << std::endl;

    for(auto& e : hittableEntities) {
      auto& position = e->getComponent<PositionComponent>();
      auto& sprite = e->getComponent<SpriteComponent>();
      auto& hitbox = e->getComponent<HitboxComponent>();
      auto& animation = e->getComponent<AnimationComponent>();
      auto& velocity = e->getComponent<VelocityComponent>();

      auto& playerPosition = player->getComponent<PositionComponent>();
      auto& playerX = playerPosition.coord.x;
      auto& playerY = playerPosition.coord.y;

      // Check si coords se encuentran dentro de hitbox
      auto x = playerX - position.coord.x - hitbox.radius;
      auto y = playerY - position.coord.y - hitbox.radius;
      // std::cout << "Player: " << playerX << " " << playerY << std::endl;
      // std::cout << "Hitbox: " << position.coord.x << " " << position.coord.y << std::endl;
      // DEBUG_TRACE("clicked");
      if(hitbox.alive && sqrt(x * x + y * y) <= hitbox.radius) {
        hitbox.alive = false;
        animation.changeState("muerta");
        sprite.changeState("muerta");

        auto& velx = velocity.vector.x;
        auto& vely = velocity.vector.y;
        velocity.vector.y = std::sqrt(velx * velx + vely * vely);
        velocity.vector.x = 0;

        DEBUG_TRACE("clicked");
        // Cambio de velocidad y sprite
        // reset_entity(e, deltatime);
      }
    }
  }
} // namespace engine
