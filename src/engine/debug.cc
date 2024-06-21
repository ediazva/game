#include "engine/debug.h"

namespace base {
  void configure_raylib_log() {
    #ifndef GAME_DEBUG
    SetTraceLogLevel(LOG_NONE);
    #endif  
  }
} // namespace base