#include "engine/components/shoot.h"
#include "engine/debug.h"
#include "engine/engine.h"

// #include "engine/entity.h"
#include "engine/entity_manager.h"

#include "engine/system_manager.h"
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

class GameEngine : public Engine {
public:
  using Engine::Engine;

  // Estados de juego a ser usado
  enum State {
    Menu,
    Round
  };

  // Asignamos indexes a nuestro contenedor de texture atlas
  enum Textures {
    PalomaVolando,
    PalomaMuere,
    Crosshair
  };

  GameEngine(const char* title, unsigned w, unsigned h, int fps)
      : Engine(title, w, h, fps, 2) {
    // raylib::HideCursor();
    // Carga de texturas
    atlases.emplace_back(makeTextureFromPath("data/img/paloma.png"),
                         assets::TextureAtlas::Info{ .size = { 64, 64 } });
    atlases.emplace_back(makeTextureFromPath("data/img/huevo_chiquito.png"),
                         assets::TextureAtlas::Info{ .size = { 64, 64 } });
    atlases.emplace_back(makeTextureFromPath("data/img/crosshair.png"),
                         assets::TextureAtlas::Info{ .size = { 32, 32 }, .scale = 2. });

    // resetEntities();
  }

  void changeState(State state) {
    entityManager(m_state).clearEntities();
    m_state = state;
    systemManager().setDepedencies(&entityManager(m_state));
    resetEntities();
    DEBUG_TRACE(std::to_string(entityManager(m_state).getEntities().size()).c_str());
  }

  // TODO: Cambiar a un factory de entidades?????
  void resetEntities() {

    switch(m_state) {
    case Menu: { // Entidades temporales para el menu
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

      break;
    }
    case Round: {
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
      break;
    }
    }

    // m_entmgr
  }

  void onInit() override {
    systemManager().addSystem(std::make_shared<DrawSystem>());
    systemManager().addSystem(std::make_shared<MovementSystem>());
    systemManager().addSystem(std::make_shared<HitboxSystem>());
    systemManager().addSystem(std::make_shared<AnimationSystem>());
    systemManager().addSystem(std::make_shared<PlayerSystem>());
    resetEntities();
  }

  void onProcessInput() override {
    // raylib::IsKeyDown(/)
    // if(IsKeyPressed(raylib::KEY_F3)) {
    // raylib::PollInputEvents();
    // DEBUG_TRACE(std::to_string(raylib::GetKeyPressed()).c_str());
    if(IsKeyPressed(raylib::KEY_ENTER)) {
      DEBUG_TRACE("Cambio de estado");
      if(m_state == Menu)
        changeState(Round);
      else
        changeState(Menu);
    }
  }

private:
  // State m_state{ Menu };
  State m_state{ Round };

  std::vector<assets::TextureAtlas> atlases{};
};

int main() {
  GameEngine game("Django: Sin palomas", 1500, 1000, 60);
  game.run();
}
