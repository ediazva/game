#pragma once
#include "engine/raylib.h"
#include "engine/result.h"

namespace engine::gfx {
  struct Texture : raylib::Texture {
    ~Texture();
    
    static Texture LoadFromPath(const char* path, Result* res = nullptr);
  };
} // namespace engine::gfx