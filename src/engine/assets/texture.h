#pragma once
#include "engine/raylib.h"
#include "engine/assets/priv/raylib_wrapper.h"

namespace engine::assets {
  CREATE_RAYLIB_WRAPPER(Texture, raylib::Texture, raylib::UnloadTexture, raylib::IsTextureReady)
} // namespace engine::assets