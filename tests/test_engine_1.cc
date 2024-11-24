#include "engine/engine.h"
#include "engine/scene.h"
#include "engine/assets/texture_pool.h"
#include "engine/assets/texture_atlas.h"

#include <cmath>
#include <raylib.h>

class Scene1 : public engine::Scene {
  engine::assets::TexturePool m_textures;
  engine::assets::TextureAtlas m_atlas;

  int onInit() override {
    m_textures.loadFromPath("sprite", "sprite.png");
    m_atlas = m_textures.makeAtlas("sprite",
      {
        .size = {10,10},
        .padding = {10,1},
        .offset = {10,10},
        .scale = 10.f,
      });

    return 0;
  }
  
  void onUpdate(float deltatime) override {
    bool up = IsKeyDown(KEY_UP);
    bool down = IsKeyDown(KEY_DOWN);
    bool left = IsKeyDown(KEY_LEFT);
    bool right = IsKeyDown(KEY_RIGHT);

    Vector2 dir(right - left, down - up);
  }

  void onRender() override {
    ClearBackground(BLANK);
    DrawTexture(m_textures["sprite"], 0, 0, WHITE);

    for(const auto& pt : m_atlas.points()) {
      DrawRectangleLines(pt.x, pt.y, m_atlas.info().size.w, m_atlas.info().size.h, GREEN);
    }

    m_atlas.draw(21, {100, 100});
  }
public:
  Scene1() :
    m_textures{"/home/phobos/Documents/game/data"} {}
};

class App : public engine::Engine {
  int onInit() override {
    addScene(std::make_unique<Scene1>());
    
    return 0;
  }
public:
  using engine::Engine::Engine;
};

int main() {
  App app("1", 900, 500, 60);
  const auto res = app.run();
  DEBUG_WARNING("Application exited with %d code", res);
  return res;
}