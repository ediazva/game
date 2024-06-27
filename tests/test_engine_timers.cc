#include "engine/engine.h"
#include "engine/timer_manager.h"
#include "engine/debug.h"
using namespace engine;

class GameEngine : public Engine {
public:
  using Engine::Engine;

  virtual Result onInit() override {
    TimerManager::AddTimer(5.f) = [](){
      DEBUG_TRACE("Aparece Dina Boluarte");
      return true;
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