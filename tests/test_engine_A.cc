#include "engine/components/shoot.h"
#include "engine/debug.h"
#include "engine/engine.h"

// #include "engine/entity.h"
#include "engine/entity.h"
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
#include "engine/timer_manager.h"

#include <functional>
#include <iostream>
#include "engine/systems/shoot.h"
#include "engine/systems/input.h"
#include "raylib.h"
#include <memory>
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
  const unsigned maxPalomasAlive = 5, maxBullets = 6;

  // Globales
  Entity *bulletsEntity, *scoreEntity;
  unsigned score{}, bullets{ maxBullets };

  // Asignamos indexes a nuestro contenedor de texture atlas
  enum Textures {
    PalomaVolando,
    PalomaMuere,
    Crosshair
  };

  virtual void onInit() override {
    TimerManager::AddTimer(5.f) = []() {
      DEBUG_TRACE("Timer 5 segundos");
      return kContinue_TimerResult;
    };

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
    systemManager().addSystem(std::make_shared<ShootSystem>());

    resetEntities();
  }

  void resetEntities() {
    auto windowWidth = raylib::GetScreenWidth();
    auto windowHeight = raylib::GetScreenHeight();

    bullets = maxBullets;

    entityManager().clearEntities();
    /*
     * Balas
     */
    auto* ptr_ent = entityManager().addEntity().get();
    ptr_ent->addComponent<PositionComponent>(50, windowHeight - 50);
    ptr_ent->addComponent<TextComponent>("Plomazos", raylib::RED, 50);

    ptr_ent = entityManager().addEntity().get();
    bulletsEntity = ptr_ent;
    ptr_ent->addComponent<PositionComponent>(50, windowHeight - 100);
    ptr_ent->addComponent<TextComponent>(std::to_string(maxBullets), raylib::RED, 50);

    /*
     * Score
     */
    ptr_ent = entityManager().addEntity().get();
    ptr_ent->addComponent<PositionComponent>(windowWidth * 7 / 10, windowHeight - 50);
    ptr_ent->addComponent<TextComponent>("Puntaje: ", raylib::RED, 50);

    ptr_ent = entityManager().addEntity().get();
    scoreEntity = ptr_ent;
    ptr_ent->addComponent<PositionComponent>(windowWidth * 17 / 20, windowHeight - 50);
    ptr_ent->addComponent<TextComponent>("0", raylib::RED, 50);

    /*
     * Player
     */
    ptr_ent = entityManager().addEntity().get();
    ptr_ent->addComponent<SpriteComponent>(
        "normal", atlases[Crosshair], 0, atlases[Crosshair].info().size.w / 2,
        atlases[Crosshair].info().size.h / 2);
    ptr_ent->addComponent<ShootComponent>(maxBullets);
    ptr_ent->addComponent<PositionComponent>(windowWidth, windowHeight);

    // On click por ahora para contar balas
    ptr_ent->onClick = std::bind([this](Entity* entityPtr) {
      bullets = --entityPtr->getComponent<ShootComponent>().bullets;

      bulletsEntity->getComponent<TextComponent>().str = std::to_string(bullets);
    },
                                 ptr_ent);

    /*
     * Palomas
     */
    for(int i{}; i < maxPalomasAlive; ++i) {
      ptr_ent = entityManager().addEntity().get();

      ptr_ent->onClick = std::bind([this](Entity* entityPtr) {
        entityPtr->getComponent<HitboxComponent>().alive = false;
        entityPtr->getComponent<AnimationComponent>().changeState("muerta");
        entityPtr->getComponent<SpriteComponent>().changeState("muerta");

        auto& vel = entityPtr->getComponent<VelocityComponent>().vector;
        entityPtr->getComponent<VelocityComponent>()
            .vector = { 0, std::sqrt(vel.x * vel.x + vel.y * vel.y) };

        // Score global
        score += 1000;
      },
                                   ptr_ent);

      ptr_ent->addComponent<SpriteComponent>(
          "volando", atlases[PalomaVolando], 0);
      ptr_ent->getComponent<SpriteComponent>().addState("muerta", atlases[PalomaMuere]);

      ptr_ent->addComponent<PositionComponent>(
          raylib::GetRandomValue(
              windowWidth * 9 / 10, windowWidth),
          raylib::GetRandomValue(
              0, windowHeight / 10));
      ptr_ent->addComponent<HitboxComponent>(64, 64);
      // ptr_ent->addComponent<VelocityComponent>(-300, -300);
      ptr_ent->addComponent<VelocityComponent>(0, 0);
      ptr_ent->addComponent<BounceComponent>();
      ptr_ent->addComponent<AnimationComponent>("viva", 0, atlases[PalomaVolando].nrects() - 1);
      ptr_ent->getComponent<AnimationComponent>().addState(
          "muerta", 0, atlases[PalomaMuere].nrects() - 1);
    }
  }

  void onUpdate(float deltatime) override {
    // Revisamos si palomas muertas
    auto entities =
        entityManager()
            .getEntities<PositionComponent, HitboxComponent, AnimationComponent,
                         SpriteComponent, VelocityComponent, BounceComponent>();
    unsigned vivas{ maxPalomasAlive };
    for(auto& e : entities) {
      if(!e->getComponent<HitboxComponent>().alive) {
        vivas--;
      }
    }

    scoreEntity->getComponent<TextComponent>().str = std::to_string(score);

    // Todas estan muertas, reinicia
    // TODO: Un wait
    if(vivas == 0 || bullets == 0) {
      resetEntities();
      // TimerManager::Tick(deltatime);
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
