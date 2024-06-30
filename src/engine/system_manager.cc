#include "engine/system_manager.h"
#include "engine/systems/system.h"

namespace engine {
  void SystemManager::addSystem(const std::shared_ptr<System>& system) {
    system->setDependency(m_entMgr);
    m_systems.push_back(system);
  }

  void SystemManager::init() {
    for(auto& s : m_systems)
      s->init();
  }

  void SystemManager::update(const float& deltatime) {
    for(auto& s : m_systems)
      s->update(deltatime);
  }

  void SystemManager::render() {
    for(auto& s : m_systems)
      s->render();
  }
} // namespace engine