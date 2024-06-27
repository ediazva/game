#pragma once
#include <functional>

namespace engine {
  enum TimerResult {

  };

  class TimerManager {
  public:
    /// Seconds
    static std::function<bool()>& AddTimer(float delay);
    static void Tick(const float& deltatime);
  };
} // namespace engine