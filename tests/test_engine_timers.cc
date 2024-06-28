#include "engine/engine.h"
#include "engine/timer_manager.h"
#include "engine/debug.h"
using namespace engine;

int attemps = 0;
class GameEngine : public Engine {
public:
  using Engine::Engine;

  virtual Result onInit() override {
    TimerManager::AddTimer(5.f) = [](){
      DEBUG_TRACE("Timer 5 segundos");
      return kContinue_TimerResult;
    };
    TimerManager::AddTimer(2.f) = []() {
      DEBUG_TRACE("Timer 2 segundos");
      if(attemps++ == 3)
        return kStop_TimerResult;
      return kContinue_TimerResult;
    };
    
    return kSucess_Result;
  }

  virtual void onUpdate(const float& deltatime) override {
    TimerManager::Tick(deltatime);
  } 
};

int main() {
  configure_raylib_log();
  GameEngine eng("Timers", 100, 100);

  return eng.run() == kSucess_Result;
}