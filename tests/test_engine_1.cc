#include "engine/engine.h"

#include <raylib.h>

class GameEngine : public engine::Engine {
public:
  using Engine::Engine;

  void onRender() override {
  }
};

int main() {
  GameEngine eng("Django: Sin palomas", 800, 400, 60);
  eng.run();

  return 0;
}