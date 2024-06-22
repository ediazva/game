#pragma once

namespace engine {
  void configure_raylib_log();
} // namespace engine

#ifdef GAME_DEBUG
#  include "engine/raylib.h"
#  define DEBUG_TRACE(...) raylib::TraceLog(raylib::LOG_TRACE, __VA_ARGS__)
#else
#  define DEBUG_TRACE(...)
#endif