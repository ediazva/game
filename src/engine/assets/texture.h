#pragma once
#include "engine/raylib.h"
#include "engine/assets/priv/raylib_wrapper.h"
#include "engine/result.h"

namespace engine::assets {
  BEGIN_RAYLIB_WRAPPER(Texture, raylib::Texture)
    static Texture MakeFromPath(const char* path, Result* res = nullptr);
  END_RAYLIB_WRAPPER
} // namespace engine::assets