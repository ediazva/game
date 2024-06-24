#include "engine/engine.h"

#include "engine/debug.h"
#include "engine/assets/tile.h"

using namespace engine;

class GameEngine : public Engine {
  assets::Tile tile;
public:
  using Engine::Engine;

  Result onInit() override {
    // assets::TileInfo info;
    // info.tileSize.w = 16;
    // info.tileSize.h = 16;
    // tile = assets::Tile::MakeFromPath("/home/phobos/Desktop/Universidad/game/data/img/sheet.png", info);
    // tile.tileSize.w = 16;
    // tile.tileSize.h = 16;

    return kSucess_Result;
  }

  void onUpdate(const float& deltatime) override {
  }

  void onRender() override {
    // raylib::DrawTile(tile);
  }
};

int main() {
  configure_raylib_log();
  GameEngine eng("Django: Sin palomas", 800, 400, 60);
  
  return eng.run();
}