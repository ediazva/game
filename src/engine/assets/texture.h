#pragma once
#include "engine/raylib.h"
#include "engine/assets/priv/raylib_wrapper.h"

namespace engine::assets {
  struct Texture : raylib_wrapper<raylib::Texture, raylib::UnloadTexture, raylib::IsTextureReady> {
    static Texture MakeFromPath(const char* path) {
      Texture t;
      t.copy_base(raylib::LoadTexture(path));
      return t;
    }
  };
} // namespace engine::assets