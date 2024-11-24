#pragma once
#include "engine/components/component.h"
#include <raylib.h>

namespace engine {
  struct TransformComponent : public Component {
    ::Vector2 position{};
    float scale{1.f};

    TransformComponent() = default;
  };
} // namespace engine
