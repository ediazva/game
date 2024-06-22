#pragma once
#include "engine/raylib.h"
#include "engine/gfx/priv/raylib_wrapper.h"
#include "engine/result.h"

namespace engine::gfx {
  BEGIN_RAYLIB_WRAPPER(Texture, raylib::Texture)
    static Texture LoadFromPath(const char* path, Result* res = nullptr);
  END_RAYLIB_WRAPPER
} // namespace engine::gfx