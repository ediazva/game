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

  void HitboxSystem::update(float deltatime) {
    using namespace raylib;

    if (!IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
      return;

    auto players = entityMgr().getEntities<ShootComponent>();
    if (players.empty())
      return;

    auto player = players.at(0);
    auto& shoot = player->getComponent<ShootComponent>();

    if (shoot.bullets <= 0 || shoot.shootCooldown > 0)
      return;

    shoot.bullets--;
    shoot.shootCooldown = shoot.maxShootCooldown;

    auto hittableEntities = entityMgr().getEntities<PositionComponent, HitboxComponent, AnimationComponent, SpriteComponent, VelocityComponent>();

    std::vector<std::pair<Entity*, Entity*>> collisions;

    for (auto& e : hittableEntities) {
      auto& position = e->getComponent<PositionComponent>();
      auto& sprite = e->getComponent<SpriteComponent>();
      auto& hitbox = e->getComponent<HitboxComponent>();
      auto& animation = e->getComponent<AnimationComponent>();
      auto& velocity = e->getComponent<VelocityComponent>();

      auto& playerPosition = player->getComponent<PositionComponent>();
      auto playerX = playerPosition.coord.x;
      auto playerY = playerPosition.coord.y;

      float halfWidth = hitbox.width / 2.0f;
      float halfHeight = hitbox.height / 2.0f; 

      bool isColliding = playerX >= (position.coord.x - halfWidth) &&
                          playerX <= (position.coord.x + halfWidth) &&
                          playerY >= (position.coord.y - halfHeight) &&
                          playerY <= (position.coord.y + halfHeight);

      bool previouslyColliding = collisionStates[e.get()];

      if (isColliding) {
        if (!previouslyColliding) {
          if (hitbox.onCollisionEnter) {
            hitbox.onCollisionEnter();
          }
          handleCollisionEnter(*player, *e);
          collisionStates[e.get()] = true;
        } else {
          if (hitbox.onCollision) {
            hitbox.onCollision();
          }
          handleCollisionStay(*player, *e);
        }
      } else {
        if (previouslyColliding) {
          if (hitbox.onCollisionExit) {
            hitbox.onCollisionExit();
          }
          handleCollisionExit(*player, *e);
          collisionStates[e.get()] = false;
        }
      }
    }
  }

  void HitboxSystem::resetEntity(std::shared_ptr<Entity>& ent, float deltatime) {
    int rand_x = raylib::GetRandomValue(200, 1300);
    float vel = 300;

    ent->getComponent<PositionComponent>().coord = { (float)rand_x, 1000 };

    if (rand_x < 500) {
      ent->getComponent<VelocityComponent>().vector = { vel, -vel };
    } else {
      ent->getComponent<VelocityComponent>().vector = { -vel, -vel };
    }
  }

  void HitboxSystem::setOnCollisionExitCallback(std::function<void(Entity&, Entity&)> callback) {
    onCollisionExitCallback = callback;
  }

  void HitboxSystem::setOnCollisionEnterCallback(std::function<void(Entity&, Entity&)> callback) {
    onCollisionEnterCallback = callback;
  }

  void HitboxSystem::setOnCollisionStayCallback(std::function<void(Entity&, Entity&)> callback) {
    onCollisionStayCallback = callback;
  }

  void HitboxSystem::handleCollisionEnter(Entity& entity1, Entity& entity2) {
    if (onCollisionEnterCallback) {
      onCollisionEnterCallback(entity1, entity2);
    }
  }

  void HitboxSystem::handleCollisionStay(Entity& entity1, Entity& entity2) {
    if (onCollisionStayCallback) {
      onCollisionStayCallback(entity1, entity2);
    }
  }

  void HitboxSystem::handleCollisionExit(Entity& entity1, Entity& entity2) {
    if (onCollisionExitCallback) {
      onCollisionExitCallback(entity1, entity2);
    }
  }

} // namespace engine
