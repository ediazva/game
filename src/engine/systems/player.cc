#pragma once
#include "player.h"
#include "engine/entity_manager.h"
#include "engine/components/position.h"
#include "engine/components/shoot.h"
#include "engine/components/input.h"

#include "engine/mice_manager.h"

namespace engine {
  // Actualizamos posicion de player dependiendo del mouse
  void PlayerSystem::update(float deltatime) {
    auto& miceMgr = MiceManager::GetInstance();
    auto mouse_pos = miceMgr.mice().front();

    for(auto& e : entityMgr().getEntities<PositionComponent, ShootComponent>()) {
      auto& posicion = e->getComponent<PositionComponent>();
      auto& shoot = e->getComponent<ShootComponent>();

      if(shoot.shootCooldown > 0)
        shoot.shootCooldown -= deltatime;

      posicion.coord.x = mouse_pos.x;
      posicion.coord.y = mouse_pos.y;
    }
  }

} // namespace engine
