#pragma once
#include "engine/raylib.h"
#include "engine/assets/priv/raylib_wrapper.h"

namespace engine::assets {
  BEGIN_RAYLIB_WRAPPER(Sound, raylib::Sound)
    ~Sound() {
      raylib::UnloadSound(*this);
    }
  END_RAYLIB_WRAPPER
} // namespace engine::assets