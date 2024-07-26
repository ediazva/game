#pragma once
#include "engine/components/component.h"
#include "raylib.h"

namespace engine {
  /* Componente que contiene el rate of fire(cooldown)
   * y las balas restantes
   */
  struct ShootComponent : public Component {
    float shootCooldown{},
        maxShootCooldown = 5.f;
    unsigned maxBullets, bullets{ maxBullets };

    ShootComponent(unsigned maxBullets) : maxBullets(maxBullets){};
  };
} // namespace engine
