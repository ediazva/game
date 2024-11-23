#include "engine/debug.h"

#include <raylib.h>

namespace engine {
  void configure_raylib_log() {
#ifndef GAME_DEBUG
    ::SetTraceLogLevel(::LOG_NONE);
#else
    ::SetTraceLogLevel(::LOG_ALL);
#endif
  }
} // namespace engine
