#pragma once
#include "engine/components/component.h"
#include "raylib.h"

namespace engine {
  /*
   * Entidades que tienen un vector velocidad
   */
  struct VelocityComponent : public Component {
    raylib::Vector2 vector{};

    VelocityComponent() = default;
    VelocityComponent(float x, float y) : vector({ x, y }) {
    }
  };
} // namespace engine
