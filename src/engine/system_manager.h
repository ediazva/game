#pragma once
#include <memory>
#include <vector>

namespace engine {
  class System;
  class EntityManager;

  class SystemManager {
    std::vector<std::shared_ptr<System>> m_systems;
    EntityManager* m_entMgr;
  public:
    void setDepedencies(EntityManager* entMgr) {
      m_entMgr = entMgr;
    }
    void addSystem(const std::shared_ptr<System>& system);

    void init();
    void update(const float& deltatime);
    void render();
  };
} // namespace engine
