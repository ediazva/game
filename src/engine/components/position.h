#pragma once
#include "engine/components/component.h"
#include "raylib.h"

namespace engine {
  struct PositionComponent : public Component {
    raylib::Vector2 coord{};

    PositionComponent() = default;
    PositionComponent(float x, float y) : coord({ x, y }) {
    }
  };
} // namespace engine
