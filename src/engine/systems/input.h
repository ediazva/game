#pragma once
#include "engine/systems/system.h"

namespace engine {
  class InputSystem : public System {
  public:
    virtual void init() override;
    virtual void update(float deltatime) override;
  };
} // namespace engine
