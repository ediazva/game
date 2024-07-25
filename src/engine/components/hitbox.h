#pragma once
#include "engine/components/component.h"
#include "raylib.h"

namespace engine {
  struct HitboxComponent : public Component {
    // Hitbox circular por el momento
    float radius{};
    // TODO: Cambiar hitbox rectangular
    // TODO: Añadir OnCollision, OnCollisionEnter

    HitboxComponent() = default;
    HitboxComponent(float radius) : radius(radius) {
    }
  };
} // namespace engine
