#pragma once
#include "player.h"
#include "engine/entity_manager.h"
#include "engine/components/position.h"
#include "engine/components/shoot.h"

namespace engine {
  // Actualizamos posicion de player dependiendo del mouse
  void PlayerSystem::update(const float& deltatime) {
    auto entidades =
        entityMgr().getEntities<PositionComponent, ShootComponent>();

    auto mouse_pos = raylib::GetMousePosition();
    for(auto& e : entidades) {
      auto& posicion = e->getComponent<PositionComponent>();
      auto& shoot = e->getComponent<ShootComponent>();

      if(shoot.shootCooldown > 0)
        shoot.shootCooldown -= deltatime;

      posicion.coord = mouse_pos;
    }
  }

} // namespace engine
