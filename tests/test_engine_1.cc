#include "engine/engine.h"
#include "engine/scene.h"
#include "engine/assets/texture_pool.h"

#include "engine/components/sprite.h"
#include "engine/components/transform.h"
#include "engine/systems/draw.h"

#include <cmath>
#include <raylib.h>

using namespace engine;

class Scene1 : public Scene {
  assets::TexturePool textures;
  struct {
    assets::TextureAtlas atlas;
    EntityPtr entity;
  } player;
  ::Camera2D camera;

  int onInit() override {
    if(!textures.loadFromPath("player", "player.png")) return 1;

    player.atlas = textures.makeAtlas("player", {.size = {16, 29}, .padding = {8,1}});
    player.entity = entityManager().addEntity();
    player.entity->addComponent<SpriteComponent>("down", player.atlas);
    auto& trans = player.entity->addComponent<TransformComponent>();
    trans.position = {10,10};
    camera.zoom = 10.f;

    systemManager().addSystem(std::make_shared<DrawSystem>());

    return Scene::onInit();
  }
  
  void onUpdate(float deltatime) override {
    bool up = IsKeyDown(KEY_UP);
    bool down = IsKeyDown(KEY_DOWN);
    bool left = IsKeyDown(KEY_LEFT);
    bool right = IsKeyDown(KEY_RIGHT);

    Vector2 dir(right - left, down - up);

    Scene::onUpdate(deltatime);
  }

  void onRender() override {
    ClearBackground(BLANK);

    ::BeginMode2D(camera);
    Scene::onRender();
    ::EndMode2D();
  }
public:
  Scene1() :
    textures{"/home/phobos/Documents/game/data"} {}
};

class App : public Engine {
  int onInit() override {
    addScene(std::make_unique<Scene1>());
    
    return 0;
  }
public:
  using Engine::Engine;
};

int main() {
  App app("1", 900, 500, 60);
  const auto res = app.run();
  DEBUG_WARNING("Application exited with %d code", res);
  return res;
}