#include "engine/engine.h"
#include "engine/level.h"
#include "engine/systems/draw.h"
#include "engine/components/sprite.h"
using namespace engine;

class Level1 : public Level {
public:
  virtual void onInit() override {
    DEBUG_TRACE("Level1 loaded");
  }
};

class Level2 : public Level {
  virtual void onInit() override {
    DEBUG_TRACE("Level2 loaded");
  }
};

class GameEngine : public Engine {
public:
  using Engine::Engine;
  Level1* level1;
  Level2* level2;

  virtual void onInit() override {
    level1 = addLevel<Level1>();
    level2 = addLevel<Level2>();
  }

  virtual void onProcessInput() override {
    if(raylib::IsKeyPressed(raylib::KEY_A)) {
      changeToLevel(level2->id());
    }

    if(raylib::IsKeyPressed(raylib::KEY_S)) {
      changeToLevel(level1->id());
    }
  }

  virtual void onUpdate(float deltatime) override {
      
  }

  virtual void onRender() override {

  }
};

int main() {
  GameEngine eng("Level", 100, 100);
  eng.run();

  return 0;
}