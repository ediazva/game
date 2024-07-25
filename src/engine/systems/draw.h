#pragma once
#include "engine/systems/system.h"

namespace engine {
  class DrawSystem : public System {
  public:
    virtual void update(float deltatime) override;
  };
} // namespace engine