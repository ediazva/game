#pragma once
#include <raylib.h>
#include "engine/assets/priv/raylib_wrapper.h"
#include "raylib.h"

namespace engine::assets {
  struct Sound : raylib_wrapper<::Sound, ::UnloadSound, ::IsSoundReady> {
    static Sound MakeFromPath(const char* path) {
      Sound sound;
      sound.copy_base(::LoadSound(path));
      // FIXME: Agregar algo acá
      return sound;
    }
  };
} // namespace engine::assets
