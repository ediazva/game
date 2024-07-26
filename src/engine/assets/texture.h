#pragma once
#include "engine/filesystem.h"
#include "engine/raylib.h"
#include "engine/assets/priv/raylib_wrapper.h"

namespace engine::assets {
  struct Texture : raylib_wrapper<raylib::Texture, raylib::UnloadTexture, raylib::IsTextureReady> {
    static Texture MakeFromPath(const fs::path& path) {
      Texture t;
      t.copy_base(raylib::LoadTexture(path.c_str()));
      return t;
    }
  };
} // namespace engine::assets
