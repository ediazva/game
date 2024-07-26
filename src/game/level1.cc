#include "level1.h"

#include "engine/systems/movement.h"
#include "engine/systems/draw.h"
#include "engine/systems/hitbox.h"
#include "engine/systems/animation.h"
#include "engine/systems/player.h"

#include "engine/components/sprite.h"
#include "engine/components/position.h"
#include "engine/components/animation.h"
#include "engine/components/text.h"
#include "engine/components/shoot.h"
#include "engine/components/hitbox.h"
#include "engine/components/bounce.h"

#include "engine/entity.h"

#include <filesystem>
#include <iostream>
// #include "engine/components/velocity.h"

using namespace raylib;

namespace game {
  void Level1::onInit() {
    // background1 = engine::assets::Texture::MakeFromPath(R"(C:\Users\Usuario\Desktop\game\data\level1\background.png)");
    // nubesAnimate = engine::assets::Texture::MakeFromPath(R"(C:\Users\Usuario\Desktop\game\data\level1\nubes.png)");
    // muro_izquierdo = engine::assets::Texture::MakeFromPath(R"(C:\Users\Usuario\Desktop\game\data\level1\muro-izquierdo.png)");
    // mi_cerro = engine::assets::Texture::MakeFromPath(R"(C:\Users\Usuario\Desktop\game\data\level1\mi-cerro.png)");
    // ventanas_estaticas = engine::assets::Texture::MakeFromPath(R"(C:\Users\Usuario\Desktop\game\data\level1\ventanas-estaticas.png)");
    // tejado = engine::assets::Texture::MakeFromPath(R"(C:\Users\Usuario\Desktop\game\data\level1\tejado-humilde.png)");
    // deco_muros = engine::assets::Texture::MakeFromPath(R"(C:\Users\Usuario\Desktop\game\data\level1\deco-muro-left.png)");

    std::filesystem::path dataPath = std::filesystem::current_path() / "data" / "level1";
    std::cout << dataPath << std::endl;

    background1 = engine::assets::Texture::MakeFromPath((dataPath / "background.png").c_str());
    nubesAnimate = engine::assets::Texture::MakeFromPath((dataPath / "nubes.png").c_str());
    muro_izquierdo = engine::assets::Texture::MakeFromPath((dataPath / "muro-izquierdo.png").c_str());
    mi_cerro = engine::assets::Texture::MakeFromPath((dataPath / "mi-cerro.png").c_str());
    ventanas_estaticas = engine::assets::Texture::MakeFromPath((dataPath / "ventanas-estaticas.png").c_str());
    tejado = engine::assets::Texture::MakeFromPath((dataPath / "tejado-humilde.png").c_str());
    deco_muros = engine::assets::Texture::MakeFromPath((dataPath / "deco-muro-left.png").c_str());

    textureAtlas["ropa-cerro"].makeFromTexture(
        // engine::assets::Texture::MakeFromPath(R"(C:\Users\Usuario\Desktop\game\data\level1\ropa-cerro.png)"),
        engine::assets::Texture::MakeFromPath((dataPath / "ropa-cerro.png").c_str()),
        { .size = { 103, 60 } });

    textureAtlas["cocinero"].makeFromTexture(
        // engine::assets::Texture::MakeFromPath(R"(C:\Users\Usuario\Desktop\game\data\level1\cocinero.png)"),
        engine::assets::Texture::MakeFromPath((dataPath / "cocinero.png").c_str()),
        { .size = { 54, 89 } });

    textureAtlas["django"].makeFromTexture(
        // engine::assets::Texture::MakeFromPath(R"(C:\Users\Usuario\Desktop\game\data\level1\django.png)"),
        engine::assets::Texture::MakeFromPath((dataPath / "django.png").c_str()),
        { .size = { 32, 36 } });

    textureAtlas["palomaViva"].makeFromTexture(
        // engine::assets::Texture::MakeFromPath(R"(C:\Users\Usuario\Desktop\game\data\level1\django.png)"),
        engine::assets::Texture::MakeFromPath((dataPath / "paloma.png").c_str()),
        { .size = { 64, 64 } });

    textureAtlas["palomaMuerta"].makeFromTexture(
        // engine::assets::Texture::MakeFromPath(R"(C:\Users\Usuario\Desktop\game\data\level1\django.png)"),
        engine::assets::Texture::MakeFromPath((dataPath / "huevo_chiquito.png").c_str()),
        { .size = { 64, 64 } });

    textureAtlas["mira"].makeFromTexture(
        // engine::assets::Texture::MakeFromPath(R"(C:\Users\Usuario\Desktop\game\data\level1\django.png)"),
        engine::assets::Texture::MakeFromPath((dataPath / "mira.png").c_str()),
        { .size = { 19, 19 } });

    initializeEntityManager();
    initializeSystemManager();
    /*
    m_background = engine::assets::Texture::MakeFromPath("/home/phobos/Desktop/Universidad/game/data/img/background.png");
    m_background2 = engine::assets::Texture::MakeFromPath("/home/phobos/Desktop/Universidad/game/data/img/background2.png");
    m_ladrillos = engine::assets::Texture::MakeFromPath("/home/phobos/Desktop/Universidad/game/data/img/ladrillos.png");
    m_pisos = engine::assets::Texture::MakeFromPath("/home/phobos/Desktop/Universidad/game/data/img/pisos.png");
    m_nubes.tex = engine::assets::Texture::MakeFromPath("/home/phobos/Desktop/Universidad/game/data/img/nubes.png");
    m_mira.tex = engine::assets::Texture::MakeFromPath("/home/phobos/Desktop/Universidad/game/data/img/mira.png");
    */

    // ================
    // ENTITIES
    // ================
    // m_claro = entMgr.addEntity();
    // m_claro->addComponent<engine::SpriteComponent>(

    // );
  }

  void Level1::resetEntities() {
    using namespace engine;
    auto windowWidth = raylib::GetScreenWidth();
    auto windowHeight = raylib::GetScreenHeight();

    // std::cout << windowWidth << " " << windowHeight << std::endl;

    bullets = maxBullets;

    entityManager().clearEntities();

    auto& entMgr = entityManager();

    ropaCerro = entMgr.addEntity();
    ropaCerro->addComponent<engine::PositionComponent>(349.f, 118.f);
    ropaCerro->addComponent<engine::SpriteComponent>("", textureAtlas["ropa-cerro"]);
    ropaCerro->addComponent<engine::AnimationComponent>("", 0, 11, 0.07);

    elCocinero = entMgr.addEntity();
    elCocinero->addComponent<engine::PositionComponent>(136.f, 70.f);
    elCocinero->addComponent<engine::SpriteComponent>("", textureAtlas["cocinero"]);
    elCocinero->addComponent<engine::AnimationComponent>("", 0, 5, 0.07);

    m_django = entMgr.addEntity();
    m_django->addComponent<engine::PositionComponent>(430.f, 213.f);
    m_django->addComponent<engine::SpriteComponent>("", textureAtlas["django"]);
    m_django->addComponent<engine::AnimationComponent>("", 0, 3, 0.5);

    /*
     * Balas
     */
    auto balasText = entMgr.addEntity();
    balasText->addComponent<PositionComponent>(50, windowHeight - 50);
    balasText->addComponent<TextComponent>("Plomazos", raylib::GREEN, 50);

    auto balasCounter = entMgr.addEntity();
    balasCounter->addComponent<PositionComponent>(50, windowHeight - 100);
    balasCounter->addComponent<TextComponent>(std::to_string(maxBullets), raylib::GREEN, 50);
    bulletsEntity = balasCounter.get();

    /*
     * Score
     */
    auto scoreText = entMgr.addEntity();

    scoreText->addComponent<PositionComponent>(windowWidth * 7 / 10, windowHeight - 50);
    scoreText->addComponent<TextComponent>("Puntaje: ", raylib::GREEN, 50);

    std::cout << scoreText->getComponent<PositionComponent>().coord.x << " " << scoreText->getComponent<PositionComponent>().coord.y << std::endl;

    auto scoreCounter = entMgr.addEntity();

    scoreCounter->addComponent<PositionComponent>(windowWidth * 27 / 30, windowHeight - 50);
    scoreCounter->addComponent<TextComponent>("0", raylib::GREEN, 50);
    scoreEntity = scoreCounter.get();

    /*
     * Player
     */
    auto player = entMgr.addEntity();

    player->addComponent<SpriteComponent>(
        "normal", textureAtlas["mira"], 0, textureAtlas["mira"].info().size.w / 2,
        textureAtlas["mira"].info().size.h / 2);
    player->addComponent<ShootComponent>(maxBullets);
    player->addComponent<PositionComponent>(windowWidth, windowHeight);

    // On click por ahora para contar balas
    (player.get())->onClick = std::bind([this](Entity* entityPtr) {
      bullets = --entityPtr->getComponent<ShootComponent>().bullets;

      bulletsEntity->getComponent<TextComponent>().str = std::to_string(bullets);
    },
                                        player.get());

    // player->onClick = [this, &player]() {
    //   bullets = --player->getComponent<ShootComponent>().bullets;
    //
    //   bulletsEntity->getComponent<TextComponent>().str = std::to_string(bullets);
    // };

    /*
     * Palomas
     */
    for(int i{}; i < maxPalomasAlive; ++i) {
      auto paloma = entMgr.addEntity();

      (paloma.get())->onClick = std::bind([this](Entity* entityPtr) {
        entityPtr->getComponent<HitboxComponent>().alive = false;
        entityPtr->getComponent<AnimationComponent>().changeState("muerta");
        entityPtr->getComponent<SpriteComponent>().changeState("muerta");

        auto& vel = entityPtr->getComponent<VelocityComponent>().vector;
        entityPtr->getComponent<VelocityComponent>()
            .vector = { 0, std::sqrt(vel.x * vel.x + vel.y * vel.y) };

        // Score global
        score += 1000;
      },
                                          paloma.get());

      // player->onClick = [this, &paloma]() {
      //   paloma->getComponent<HitboxComponent>().alive = false;
      //   paloma->getComponent<AnimationComponent>().changeState("muerta");
      //   paloma->getComponent<SpriteComponent>().changeState("muerta");
      //
      //   auto& vel = paloma->getComponent<VelocityComponent>().vector;
      //   paloma->getComponent<VelocityComponent>()
      //       .vector = { 0, std::sqrt(vel.x * vel.x + vel.y * vel.y) };
      //
      //   // Score global
      //   score += 1000;
      // };

      paloma->addComponent<SpriteComponent>(
          "volando", textureAtlas["palomaViva"], 0);
      paloma->getComponent<SpriteComponent>().addState("muerta", textureAtlas["palomaMuerta"]);

      paloma->addComponent<PositionComponent>(
          raylib::GetRandomValue(
              windowWidth * 9 / 10, windowWidth),
          raylib::GetRandomValue(
              0, windowHeight / 10));

      std::cout << paloma->getComponent<PositionComponent>().coord.x << " " << paloma->getComponent<PositionComponent>().coord.y << std::endl;
      paloma->addComponent<HitboxComponent>(64, 64);
      // ptr_ent->addComponent<VelocityComponent>(-300, -300);
      paloma->addComponent<VelocityComponent>(-200, -200);
      paloma->addComponent<BounceComponent>();
      paloma->addComponent<AnimationComponent>("viva", 0, textureAtlas["palomaViva"].nrects() - 1);
      paloma->getComponent<AnimationComponent>().addState(
          "muerta", 0, textureAtlas["palomaMuerta"].nrects() - 1);
    }
  }

  void Level1::initializeEntityManager() {
    resetEntities();
    // nubesAnimate = entMgr.addEntity();
    // nubesAnimate->addComponent<engine::PositionComponent>(0.f,0.f);
    // nubesAnimate->addComponent<engine::SpriteComponent>("", "nubes");
    // nubesAnimate->addComponent<engine::AnimationComponent>("", 0, 3, 0.5);
  }

  // void Update(float deltaTime) { XD
  //   auto& positionComponent = nubesAnimate->getComponent<engine::PositionComponent>();
  //   positionComponent.x += velocidadNubes * deltaTime;

  //   if (positionComponent.x > GetScreenWidth) {
  //     positionComponent.x = -nubesAnimate.getWidth();
  //   }
  // }

  // void Render() {
  //   auto% positionComponent = nubesAnimate->getComponent<engine::PositionComponent>();
  //   DrawTexture(nubesAnimation, positionComponent.x, positionComponent.y, BLACK)
  // }

  void Level1::initializeSystemManager() {
    auto& sysMgr = systemManager();

    sysMgr.addSystem(std::make_shared<engine::DrawSystem>());
    sysMgr.addSystem(std::make_shared<engine::AnimationSystem>());
    sysMgr.addSystem(std::make_shared<engine::MovementSystem>());
    sysMgr.addSystem(std::make_shared<engine::HitboxSystem>());
    sysMgr.addSystem(std::make_shared<engine::PlayerSystem>());
  }

  void Level1::onProcessInput() {
    /*
    m_mira.x = GetMouseX()/SCALE - m_mira.tex.width/2.f;
    m_mira.y = GetMouseY()/SCALE - m_mira.tex.height/2.f;
    */
  }

  // float x{};

  void Level1::onUpdate(float deltatime) {
    using namespace engine;
    /*
    x -= deltatime*CLOUDS_SPEED;
    if(x <= -m_nubes.tex.width) x = 0.f;
    */
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

  void Level1::onRender() {
    using namespace raylib;
    // rlScalef(2.f, 2.f, 1.f);
    DrawTextureEx(background1, { 0, 0 }, 0, 2.f, WHITE);
    DrawTextureEx(nubesAnimate, { 0, 0 }, 0, 2.f, WHITE);
    DrawTextureEx(mi_cerro, { 0, 0 }, 0, 2.f, WHITE);
    DrawTextureEx(muro_izquierdo, { 0, 0 }, 0, 2.f, WHITE);
    DrawTextureEx(deco_muros, { 0, 0 }, 0, 2.f, WHITE);
    DrawTextureEx(ventanas_estaticas, { 0, 0 }, 0, 2.f, WHITE);
    DrawTextureEx(tejado, { 0, 0 }, 0, 2.f, WHITE);

    // DrawTexture(background1, 0, 0, WHITE);
    // DrawTexture(nubesAnimate, 0, 0, WHITE); // falta move
    // DrawTexture(mi_cerro, 0, 0, WHITE);
    // DrawTexture(muro_izquierdo, 0, 0, WHITE);
    // DrawTexture(deco_muros, 0, 0, WHITE);
    // DrawTexture(ventanas_estaticas, 0, 0, WHITE);
    // DrawTexture(tejado, 0, 0, WHITE);

    /*
    using namespace raylib;
    rlScalef(SCALE, SCALE, 1.f);
    ClearBackground(BLACK);

    DrawTexture(m_background, 0, 0, WHITE);
    // Parallax effect
    DrawTexture(m_nubes.tex, x, 0.f, WHITE);
    DrawTexture(m_nubes.tex, m_nubes.tex.width+x, 0.f, WHITE);
    // =====================
    DrawTexture(m_background2, 0, 0, WHITE);
    DrawTexture(m_pisos, 0.f, 0.f, WHITE);
    DrawTexture(m_ladrillos, 0.f, 0.f, WHITE);

    DrawTexture(m_mira.tex, m_mira.x, m_mira.y, GREEN);
  */
  }
} // namespace game
