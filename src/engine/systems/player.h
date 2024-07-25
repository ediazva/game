#pragma once
#include <cmath>
#include "engine/entity.h"
#include "engine/systems/system.h"

namespace engine {
  class PlayerSystem : public System {
  public:
    virtual void update(float deltatime) override;
    // void reset_entity(std::shared_ptr<Entity>& ent, const float& deltatime);
  };
} // namespace engine
