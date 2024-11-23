#pragma once
#include "engine/filesystem.h"
#include <raylib.h>
#include "engine/assets/priv/raylib_wrapper.h"

namespace engine::assets {
  struct Texture : raylib_wrapper<::Texture, ::UnloadTexture, ::IsTextureReady> {
    static Texture MakeFromPath(const fs::path& path) {
      Texture t;
      t.copy_base(::LoadTexture(path.c_str()));
      return t;
    }
  };
} // namespace engine::assets
