#include "engine/engine.h"

#include "engine/debug.h"
#include "engine/assets/texture_atlas.h"

#include <cmath>

using namespace engine;

class GameEngine : public Engine {
  assets::TextureAtlas atlas;
public:
  using Engine::Engine;

  void onInit() override {
    atlas.makeFromTexture(
      assets::Texture::MakeFromPath("/home/phobos/Desktop/Universidad/game/data/img/sheet.png"),
      {
        .size = {16,16},
        .scale = 16.f
      });
  }

  float idx = 0;

  void onUpdate(float deltatime) override {
    idx += deltatime;
    if(idx > atlas.nrects())
      idx = 0.f;
  }


  void onRender() override {
    using namespace raylib;
    ClearBackground(BLANK);
    DrawTexture(atlas.texture(), 0, 0, WHITE);
    
    const auto& og = atlas.rectOrigin(std::round(idx));
    const auto& size = atlas.info().size;
    DrawTexturePro(
      atlas.texture(),
      {og.x, og.y, static_cast<float>(size.w), static_cast<float>(size.h)}, 
      {400.f, 0.f, size.w*atlas.info().scale, size.h*atlas.info().scale}, {}, 0.f, WHITE);
  }
};

int main() {
  configure_raylib_log();
  GameEngine eng("Django: Sin palomas", 800, 400, 60);
  
  eng.run();

  return 0;
}