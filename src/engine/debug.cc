#include "engine/debug.h"

namespace engine {
  void configure_raylib_log() {
#ifndef GAME_DEBUG
    raylib::SetTraceLogLevel(raylib::LOG_NONE);
#else
    raylib::SetTraceLogLevel(raylib::LOG_ALL);
#endif
  }
} // namespace engine
