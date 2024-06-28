#pragma once
#include "engine/entity_manager.h"

namespace engine {
  class System {
    EntityManager& m_entityMgr;
  public:
    System(EntityManager& entityMgr) :
      m_entityMgr{entityMgr} {}

    virtual void init() = 0;
    virtual void update() = 0;
  };
} // namespace engine