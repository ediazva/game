#include "engine/engine.h"

#include "engine/debug.h"
#include "engine/assets/tile.h"

using namespace engine;

class GameEngine : public Engine {
  assets::Tile tile;
public:
  using Engine::Engine;

  Result onInit() override {
    tile.atlas.makeFromTexture(
      makeTextureFromPath("/home/phobos/Desktop/Universidad/game/data/img/sheet2.png"),
      {
        .size = {137, 137},
      });
    tile.map = {
      {0},
    };

    return kSucess_Result;
  }

  void onUpdate(const float& deltatime) override {
  }


  void onRender() override {
    using namespace raylib;
    ClearBackground(BLANK);
    DrawTile(tile, {100.f,0});
  }
};

int main() {
  configure_raylib_log();
  GameEngine eng("Django: Sin palomas", 800, 400);
  
  return eng.run();
}