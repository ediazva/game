#pragma once
#include "engine/raylib.h"
#include "engine/assets/priv/raylib_wrapper.h"

namespace engine::assets {
  struct Sound : raylib_wrapper<raylib::Sound, raylib::UnloadSound, raylib::IsSoundReady> {
    static Sound MakeFromPath(const char* path) {
      // FIXME: Agregar algo acá
      return {};
    }
  };
} // namespace engine::assets