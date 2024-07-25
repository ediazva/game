#pragma once
#include <cmath>
#include "engine/entity.h"
#include "engine/systems/system.h"

namespace engine {
  class HitboxSystem : public System {
  public:
    virtual void update(float deltatime) override;
    void resetEntity(std::shared_ptr<Entity>& ent, float deltatime);
//detectar si entro en el hitbox()}
//para cada uno crear un std::function<void(Entity&)>()
//entro()->onCollision;
//esta()
//salio()
  };
} // namespace engine
