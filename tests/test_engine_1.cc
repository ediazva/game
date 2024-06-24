#include "engine/engine.h"

#include "engine/debug.h"
#include "engine/assets/texture.h"

using namespace engine;

class GameEngine : public Engine {
  assets::Texture tex;
public:
  using Engine::Engine;

  Result onInit() override {
    // tex = makeTextureFromPath("/home/phobos/Desktop/Universidad/game/data/img/sheet.png");
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
    raylib::DrawTexture(tex, 0, 0, raylib::WHITE);
    // raylib::DrawTile(tile);
  }
};

int main() {
  configure_raylib_log();
  GameEngine eng("Django: Sin palomas", 800, 400, 60);
  
  return eng.run();
}