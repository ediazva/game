#pragma once
#include "engine/components/component.h"
#include "raylib.h"

namespace engine {
  /*
   * Componente que determina si una entidad debe:
   * - "revotar" al chocar con un borde de pantalla
   * - Cambiar de dirección cada cierto tiempo
   */
  struct BounceComponent : public Component {
    static float maxcooldown;
    float cooldown = { maxcooldown };

    BounceComponent() : cooldown(maxcooldown){};
  };
} // namespace engine
