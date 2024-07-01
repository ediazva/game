#pragma once
#include "engine/components/component.h"
#include "raylib.h"

namespace engine {
  struct VelocityComponent : public Component {
    raylib::Vector2 vector{};

    VelocityComponent() = default;
    VelocityComponent(float x, float y) : vector({ x, y }) {
    }
  };
} // namespace engine
