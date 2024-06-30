#pragma once
#include "engine/raylib.h"
#include "engine/assets/priv/raylib_wrapper.h"

namespace engine::assets {
  CREATE_RAYLIB_WRAPPER(Sound, raylib::Sound, raylib::UnloadSound, raylib::IsSoundReady)
} // namespace engine::assets