#pragma once

namespace engine {
  void configure_raylib_log();
} // namespace engine

#ifdef GAME_DEBUG
#  include <raylib.h>
// #  include <stdarg.h>
#  define DEBUG_TRACE(...) ::TraceLog(::LOG_TRACE, __VA_ARGS__)
#  define DEBUG_WARNING(...) ::TraceLog(::LOG_WARNING, __VA_ARGS__)
#else
#  define DEBUG_TRACE(...)
#  define DEBUG_WARNING(...)
#endif