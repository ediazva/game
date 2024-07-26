#pragma once
#include "engine/components/component.h"
#include "raylib.h"

namespace engine {
  /* Componente que determina si esta entidad es
   * afectada por el mouse de un usuario
   */
  struct InputComponent : public Component {
    InputComponent() = default;
  };
} // namespace engine
