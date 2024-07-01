#pragma once
#include <cmath>
#include "engine/entity.h"
#include "engine/systems/system.h"

namespace engine {
  class HitboxSystem : public System {
  public:
    virtual void update(const float& deltatime) override;
    void reset_entity(std::shared_ptr<Entity>&);
  };
} // namespace engine
