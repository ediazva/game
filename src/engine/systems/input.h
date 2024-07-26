#pragma once
#include "engine/systems/system.h"
#include "engine/mouse.h"

#include <unordered_map>

namespace engine {
  class InputSystem : public System {
    std::unordered_map<class Entity*, Mouse*> m_miceMap;
  public:
    virtual void init() override;
    virtual void update(float deltatime) override;
  };
} // namespace engine
