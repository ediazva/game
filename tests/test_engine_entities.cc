#include "engine/engine.h"
#include "engine/components/sprite.h"
#include "engine/entity_manager.h"
#include "engine/system_manager.h"
#include "engine/systems/draw.h"
using namespace engine;

class GameEngine : public Engine {
public:
  using Engine::Engine;

  virtual void onInit() override {
    systemManager().addSystem(std::make_shared<DrawSystem>());
    entityManager().addEntity()->addComponent<SpriteComponent>(
        makeTextureFromPath("/home/phobos/Desktop/Universidad/game/data/img/sheet.png"),
        assets::TextureAtlas::Info{ .size = { 16, 16 } });
  }
};

int main() {
  GameEngine app("Hola mundo", 800, 400);
  // EntityManager entities;
  // SystemManager systems(entities);
  // entities.addEntity().

  // Entity a;
  // a.addComponent<SpriteComponent>();
  // DEBUG_TRACE("%o", a.hasComponent<SpriteComponent>());
  // DEBUG_TRACE("%p", a.tryGetComponent<SpriteComponent>());

  app.run();

  return 0;
}
