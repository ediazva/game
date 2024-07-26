#pragma once
#include "engine/systems/shoot.h"
#include "engine//entity_manager.h"
#include "engine/components/shoot.h"
#include "engine/components/position.h"

namespace engine {
  // Actualizamos posicion de player dependiendo del mouse 
  void ShootSystem::update(float deltatime) {
    for(auto& e : entityMgr().getEntities<ShootComponent>()) {
      auto& shoot = e->getComponent<ShootComponent>();

      if(shoot.shootCooldown > 0)
        shoot.shootCooldown -= deltatime;
    }
  }

} // namespace engine
