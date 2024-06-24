#pragma once
#include "engine/raylib.h"
#include "engine/assets/priv/raylib_wrapper.h"

namespace engine::assets {
  BEGIN_RAYLIB_WRAPPER(Texture, raylib::Texture)
    ~Texture() {
      raylib::UnloadTexture(*this);
    }
  END_RAYLIB_WRAPPER
} // namespace engine::assets