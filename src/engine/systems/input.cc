#include "engine/systems/input.h"
#include "engine/mice_manager.h"
#include "engine/debug.h"
#include "engine/entity_manager.h"
#include "engine/components/input.h"
#include "engine/components/position.h"

#include <print>

namespace engine {
  void InputSystem::init() {
    auto& miceMgr = MiceManager::GetInstance();

    auto miceZip = 
      std::views::zip(
        entityMgr().getEntities<InputComponent>() | std::views::transform(&EntityPtr::get),
        miceMgr.mice() | std::views::transform([](auto&& e) {return std::addressof(e);})) | std::views::common;

    m_miceMap = miceZip | std::ranges::to<std::unordered_map<Entity*, Mouse*>>();
  }
  // Actualizamos posicion de player dependiendo del mouse 
  void InputSystem::update(float deltatime) {
    MiceManager::GetInstance().update();

    for(auto&& [k,v] : m_miceMap) {
      auto& pos = k->getComponent<PositionComponent>();
      pos.coord.x = v->x;
      pos.coord.y = v->y;
    }
  }
} // namespace engine
