#pragma once
#include "engine/systems/system.h"

namespace engine {
  class DrawSystem : public System {
  public:
    virtual void render() override;
  };
} // namespace engine