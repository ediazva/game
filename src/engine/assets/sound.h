#pragma once
#include "engine/raylib.h"
#include "engine/assets/priv/raylib_wrapper.h"
#include "raylib.h"

namespace engine::assets {
  struct Sound : raylib_wrapper<raylib::Sound, raylib::UnloadSound, raylib::IsSoundReady> {
    static Sound MakeFromPath(const char* path) {
      Sound sound;
      sound.copy_base(raylib::LoadSound(path));
      // FIXME: Agregar algo acá
      return sound;
    }
  };
} // namespace engine::assets
