#pragma once
#include "engine/components/component.h"
#include "raylib.h"

namespace engine {
  /* Componente que contiene el rate of fire(cooldown)
   * y las balas restantes
   */
  struct ShootComponent : public Component {
    float shoot_cooldown{};
    int bullets{ 3 };

    ShootComponent() = default;
  };
} // namespace engine
