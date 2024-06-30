#pragma once

namespace engine {
  void configure_raylib_log();
} // namespace engine

#ifdef GAME_DEBUG
#include <stdarg.h>
#  include "engine/raylib.h"
// #  include <stdarg.h>
#  define DEBUG_TRACE(...) raylib::TraceLog(raylib::LOG_TRACE, __VA_ARGS__)
#  define DEBUG_WARNING(...) raylib::TraceLog(raylib::LOG_WARNING, __VA_ARGS__)
#else
#  define DEBUG_TRACE(...)
#  define DEBUG_WARNING(...)
#endif