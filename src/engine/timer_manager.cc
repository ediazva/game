#include "engine/timer_manager.h"

#include "engine/debug.h"

#include <list>

namespace engine {
  struct Timer {
    ~Timer() {
      DEBUG_TRACE("[Timer] Destructor!");
    }
    float delay{};
    float elapsed{};
    std::function<TimerResult()> fn;
  };

  static std::list<Timer> s_timers;
  
  std::function<TimerResult()>& TimerManager::AddTimer(float seconds) {
    DEBUG_TRACE("[TimerManager] Adding timer with %f delay", seconds);
    s_timers.push_back({.delay = seconds});
    return s_timers.back().fn;
  }

  void TimerManager::Tick(const float& deltatime) {
    for(auto it = s_timers.begin(); it != s_timers.end(); ++it) {
      it->elapsed += deltatime;
      if(it->elapsed >= it->delay) {
        if(it->fn() == kContinue_TimerResult)
          it->elapsed = 0.f;
        else
          it = s_timers.erase(it);
      }
    }
  }
} // namespace engine