#pragma once

namespace engine {
  void configure_raylib_log();
} // namespace engine

#ifdef GAME_DEBUG
#  include <raylib.h>
#  define LOG_TRACE(...) TraceLog(LOG_TRACE, _VA_ARGS_)
#else
#  define LOG_TRACE(...)
#endif