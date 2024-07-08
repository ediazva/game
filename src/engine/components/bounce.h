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
    constexpr static const float max_cooldown{ 500 };
    float cooldown = { max_cooldown };

    BounceComponent() : cooldown(max_cooldown){};
  };
} // namespace engine
