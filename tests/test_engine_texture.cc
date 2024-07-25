#include "engine/engine.h"

#include "engine/debug.h"
#include "engine/assets/texture.h"

#include <cmath>

using namespace engine;

class GameEngine : public Engine {
  assets::Texture tex;
public:
  using Engine::Engine;

  void onInit() override {
    tex = assets::Texture::MakeFromPath("/home/phobos/Desktop/Universidad/game/data/img/background.png");
  }


  void onRender() override {
    using namespace raylib;
    DrawTexture(tex, 0, 0, WHITE);
  }
};

int main() {
  configure_raylib_log();
  GameEngine eng("Test-texture", 800, 400, 60);
  
  eng.run();

  return 0;
}