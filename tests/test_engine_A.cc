#include "engine/components/component.h"
#include "engine/engine.h"

// #include "engine/entity.h"
#include "engine/entity_manager.h"

#include "engine/system_manager.h"
#include "engine/systems/movement.h"
#include "engine/systems/draw.h"
#include "engine/systems/hitbox.h"

#include "engine/components/position.h"
#include "engine/components/hitbox.h"
#include "engine/components/velocity.h"
#include "engine/components/sprite.h"

#include "raylib.h"

using namespace engine;

class GameEngine : public Engine {
public:
  using Engine::Engine;

  void resetEntity(std::shared_ptr<Entity>& ent) {
    int rand_x = raylib::GetRandomValue(200, 1300);
    ent->getComponent<PositionComponent>().coord = { (float)rand_x, 1000 };

    if(rand_x < 500) {
      ent->getComponent<VelocityComponent>().vector = { 30, -30 };
    } else {
      ent->getComponent<VelocityComponent>().vector = { -30, -30 };
    }
  }

  void onInit() override {
    systemManager().addSystem(std::make_shared<DrawSystem>());
    systemManager().addSystem(std::make_shared<MovementSystem>());
    systemManager().addSystem(std::make_shared<HitboxSystem>());
    // entityManager().addEntity()->addComponent<SpriteComponent>(
    //     makeTextureFromPath("/home/phobos/Desktop/Universidad/game/data/img/sheet.png"),
    //     assets::TextureAtlas::Info{ .size = { 16, 16 } });

    /*
     * Inicializaciones ejemplo
     */

    for(int i{}; i < 5; ++i) {
      auto& ptr_ent = entityManager().addEntity();
      ptr_ent->addComponent<SpriteComponent>(
          makeTextureFromPath("data/img/huevo_chiquito.png"),
          assets::TextureAtlas::Info{ .size = { 128, 128 } });
      ptr_ent->addComponent<PositionComponent>();
      ptr_ent->addComponent<HitboxComponent>(64);
      ptr_ent->addComponent<VelocityComponent>();
    }

    // auto conj = entityManager().getEntities<PositionComponent, VelocityComponent>();

    for(auto e : entityManager().getEntities<PositionComponent, VelocityComponent>()) {
      resetEntity(e);
    }
  }
};

int main() {
  GameEngine game("Django: Sin palomas", 1500, 1000, 60);
  game.run();
}
