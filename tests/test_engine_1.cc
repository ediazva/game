#include "engine/engine.h"

#include "engine/debug.h"
#include "engine/gfx/tile.h"

using namespace engine;

class GameEngine : public Engine {
  gfx::Tile tile;
public:
  using Engine::Engine;

  Result onInit() override {
    tile = gfx::Tile::MakeFromPath("/home/phobos/Desktop/Universidad/game/data/img/sheet.png");
    // tile.tileSize.w = 16;
    // tile.tileSize.h = 16;

    return kSucess_Result;
  }

  void onUpdate(const float& deltatime) override {
  }

  void onRender() override {
    tile.draw();
  }
};

int main() {
  configure_raylib_log();
  GameEngine eng("Django: Sin palomas", 800, 400, 60);
  
  return eng.run();
}