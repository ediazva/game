#include "engine/engine.h"

#include "engine/debug.h"
#include "engine/gfx/texture.h"

using namespace engine;

class GameEngine : public Engine {
  gfx::Texture tex;
public:
  using Engine::Engine;

  Result onInit() override {
    tex = gfx::Texture::LoadFromPath("/home/phobos/Desktop/Universidad/game/data/img/sheet.png");

    return kSucess_Result;
  }

  void onUpdate(const float& deltatime) override {
  }

  void onRender() override {
    using namespace raylib;
    DrawTexture(tex, 0, 0, WHITE);
    for(int y = 0; y*16 < tex.height; ++y) {
      for(int x = 0; x*16 < tex.width; ++x) {
        DrawRectangleLines(16*x, 16*y, 16, 16, GREEN);
      }
    }
  }
};

int main() {
  configure_raylib_log();
  GameEngine eng("Django: Sin palomas", 800, 400, 60);
  
  return eng.run();
}