#include "engine/components/shoot.h"
#include "engine/debug.h"
#include "engine/engine.h"

// #include "engine/entity.h"
#include "engine/entity_manager.h"

#include "engine/system_manager.h"
#include "engine/level.h"
#include "engine/systems/movement.h"
#include "engine/systems/draw.h"
#include "engine/systems/hitbox.h"
#include "engine/systems/animation.h"

#include "engine/components/position.h"
#include "engine/components/hitbox.h"
#include "engine/components/velocity.h"
#include "engine/components/sprite.h"
#include "engine/components/bounce.h"
#include "engine/components/text.h"
#include "engine/components/animation.h"

#include "engine/systems/player.h"
#include "raylib.h"
#include <string>

using namespace engine;

class Level1 : public Level {
public:
  enum Textures {
    PalomaVolando,
    PalomaMuere,
    Crosshair
  };
  std::vector<assets::TextureAtlas> atlases{};

  virtual void onInit() override {
    DEBUG_TRACE("Level1 loaded");
    atlases.emplace_back(engine::assets::Texture::MakeFromPath("/home/user/Documentos/CC2_TIF/game/data/img/paloma.png"),
                         assets::TextureAtlas::Info{ .size = { 64, 64 } });
    atlases.emplace_back(engine::assets::Texture::MakeFromPath("/home/user/Documentos/CC2_TIF/game/data/img/huevo_chiquito.png"),
                         assets::TextureAtlas::Info{ .size = { 64, 64 } });
    atlases.emplace_back(engine::assets::Texture::MakeFromPath("/home/user/Documentos/CC2_TIF/game/data/img/crosshair.png"),
                         assets::TextureAtlas::Info{ .size = { 32, 32 }, .scale = 2. });

    systemManager().addSystem(std::make_shared<DrawSystem>());
    resetEntities();
  }

  void resetEntities() {

    // CLEAR????
    auto* ptr_ent = entityManager().addEntity().get();

    ptr_ent = entityManager().addEntity().get();
    ptr_ent->addComponent<SpriteComponent>(
        "volando", atlases[PalomaVolando], 0);
    ptr_ent->addComponent<PositionComponent>(300, 300);
    ptr_ent->addComponent<VelocityComponent>(300, -300);
    ptr_ent->addComponent<BounceComponent>();
    ptr_ent->addComponent<AnimationComponent>("viva", 0, atlases[PalomaVolando].nrects() - 1);

    // DEBUG_TRACE(std::to_string(atlases[Paloma].nrects()).c_str());

    ptr_ent = entityManager().addEntity().get();
    ptr_ent->addComponent<PositionComponent>(500, 500);
    ptr_ent->addComponent<TextComponent>("Menu principal", raylib::WHITE, 50);
  }

  // m_entmgr
};

class Level2 : public Level {
  std::vector<assets::TextureAtlas> atlases{};

  // Asignamos indexes a nuestro contenedor de texture atlas
  enum Textures {
    PalomaVolando,
    PalomaMuere,
    Crosshair
  };
  virtual void onInit() override {
    DEBUG_TRACE("Level2 loaded");
    atlases.emplace_back(engine::assets::Texture::MakeFromPath("/home/user/Documentos/CC2_TIF/game/data/img/paloma.png"),
                         assets::TextureAtlas::Info{ .size = { 64, 64 } });
    atlases.emplace_back(engine::assets::Texture::MakeFromPath("/home/user/Documentos/CC2_TIF/game/data/img/huevo_chiquito.png"),
                         assets::TextureAtlas::Info{ .size = { 64, 64 } });
    atlases.emplace_back(engine::assets::Texture::MakeFromPath("/home/user/Documentos/CC2_TIF/game/data/img/crosshair.png"),
                         assets::TextureAtlas::Info{ .size = { 32, 32 }, .scale = 2. });

    systemManager().addSystem(std::make_shared<DrawSystem>());
    systemManager().addSystem(std::make_shared<MovementSystem>());
    systemManager().addSystem(std::make_shared<HitboxSystem>());
    systemManager().addSystem(std::make_shared<AnimationSystem>());
    systemManager().addSystem(std::make_shared<PlayerSystem>());

    resetEntities();
  }

  void resetEntities() {
    for(int i{}; i < 3; ++i) {
      auto* ptr_ent = entityManager().addEntity().get();
      ptr_ent->addComponent<PositionComponent>(0, 0);
      ptr_ent->addComponent<TextComponent>("Balas: ", raylib::WHITE, 50);

      // // Player
      ptr_ent = entityManager().addEntity().get();
      ptr_ent->addComponent<SpriteComponent>(
          "normal", atlases[Crosshair], 0, atlases[Crosshair].info().size.w / 2, atlases[Crosshair].info().size.h / 2);
      ptr_ent->addComponent<ShootComponent>();
      ptr_ent->addComponent<PositionComponent>(500, 500);

      // ptr_ent->addComponent<SpriteComponent>(
      //     makeTextureFromPath("data/img/huevo_chiquito.png"),
      //     assets::TextureAtlas::Info{ .size = { 128, 128 } });

      ptr_ent = entityManager().addEntity().get();
      ptr_ent->addComponent<SpriteComponent>(
          "volando", atlases[PalomaVolando], 0);
      ptr_ent->getComponent<SpriteComponent>().addState("muerta", atlases[PalomaMuere]);

      ptr_ent->addComponent<PositionComponent>(raylib::GetRandomValue(200, 1300), 800);
      ptr_ent->addComponent<HitboxComponent>(64);
      ptr_ent->addComponent<VelocityComponent>(300, -300);
      ptr_ent->addComponent<BounceComponent>();
      ptr_ent->addComponent<AnimationComponent>("viva", 0, atlases[PalomaVolando].nrects() - 1);
      ptr_ent->getComponent<AnimationComponent>().addState(
          "muerta", 0, atlases[PalomaMuere].nrects() - 1);
    }
  }
};

class GameEngine : public Engine {
public:
  using Engine::Engine;
  Level1* level1;
  Level2* level2;

  virtual void onInit() override {
    level1 = addLevel<Level1>();

    level2 = addLevel<Level2>();
  }

  virtual void onProcessInput() override {
    if(raylib::IsKeyPressed(raylib::KEY_A)) {
      changeToLevel(level2->id());
    }

    if(raylib::IsKeyPressed(raylib::KEY_S)) {
      changeToLevel(level1->id());
    }
  } // TODO: Cambiar a un factory de entidades?????
};

int main() {
  GameEngine game("Django: Sin palomas", 1500, 1000, 60);
  game.run();
}
