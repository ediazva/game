#pragma once
#include <functional>

namespace engine {
  enum TimerResult {
    kStop_TimerResult     = 0,
    kContinue_TimerResult = 1,
  };

  class TimerManager {
  public:
    /// Seconds
    static std::function<TimerResult()>& AddTimer(float delay);
    static void Tick(const float& deltatime);
  };
} // namespace engine