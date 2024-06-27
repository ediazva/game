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
      makeTextureFromPath("/home/phobos/Desktop/Universidad/game/data/img/sheet.png"),
      {
        .size = {16, 16},
        .scale = 5.f
      });
    tile.map = {
      {-1, 0, -1},
      {-1, 0, -1},
      {-1, 0, -1},
      {-1, 0, -1},
      {0,  0,  0},
    };

    return kSucess_Result;
  }

  void onUpdate(const float& deltatime) override {
  }


  void onRender() override {
    using namespace raylib;
    ClearBackground(BLANK);
    DrawTexture(tile.atlas.texture(), 0, 0, WHITE);
    DrawTile(tile, {400.f,0});
  }
};

int main() {
  configure_raylib_log();
  GameEngine eng("Django: Sin palomas", 800, 400);
  
  return eng.run();
}