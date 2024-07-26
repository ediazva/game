#include "level1.h"

#include "engine/systems/draw.h"
#include "engine/systems/animation.h"
#include "engine/components/sprite.h"
#include "engine/components/position.h"
#include "engine/components/animation.h"
// #include "engine/components/velocity.h"

using namespace raylib;

namespace game {
  void Level1::onInit() {
    background1 = engine::assets::Texture::MakeFromPath(R"(C:\Users\Usuario\Desktop\game\data\level1\background.png)");
    nubesAnimate = engine::assets::Texture::MakeFromPath(R"(C:\Users\Usuario\Desktop\game\data\level1\nubes.png)");
    muro_izquierdo = engine::assets::Texture::MakeFromPath(R"(C:\Users\Usuario\Desktop\game\data\level1\muro-izquierdo.png)");
    mi_cerro = engine::assets::Texture::MakeFromPath(R"(C:\Users\Usuario\Desktop\game\data\level1\mi-cerro.png)");
    ventanas_estaticas = engine::assets::Texture::MakeFromPath(R"(C:\Users\Usuario\Desktop\game\data\level1\ventanas-estaticas.png)");
    tejado = engine::assets::Texture::MakeFromPath(R"(C:\Users\Usuario\Desktop\game\data\level1\tejado-humilde.png)");
    deco_muros = engine::assets::Texture::MakeFromPath(R"(C:\Users\Usuario\Desktop\game\data\level1\deco-muro-left.png)");

    textureAtlas["ropa-cerro"].makeFromTexture(
      engine::assets::Texture::MakeFromPath(R"(C:\Users\Usuario\Desktop\game\data\level1\ropa-cerro.png)"),
      {.size = {103, 60}}
    );

    textureAtlas["cocinero"].makeFromTexture(
      engine::assets::Texture::MakeFromPath(R"(C:\Users\Usuario\Desktop\game\data\level1\cocinero.png)"),
      {.size = {54, 89}}
    );

    textureAtlas["django"].makeFromTexture(
      engine::assets::Texture::MakeFromPath(R"(C:\Users\Usuario\Desktop\game\data\level1\django.png)"),
      {.size = {32, 36}}
    );

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

  void Level1::initializeEntityManager() {
    auto& entMgr = entityManager();

    ropaCerro = entMgr.addEntity();
    ropaCerro->addComponent<engine::PositionComponent>(349.f,118.f);
    ropaCerro->addComponent<engine::SpriteComponent>("", textureAtlas["ropa-cerro"]);
    ropaCerro->addComponent<engine::AnimationComponent>("", 0, 11, 0.07);

    elCocinero = entMgr.addEntity();
    elCocinero->addComponent<engine::PositionComponent>(136.f,70.f);
    elCocinero->addComponent<engine::SpriteComponent>("", textureAtlas["cocinero"]);
    elCocinero->addComponent<engine::AnimationComponent>("", 0, 5, 0.07);

    m_django = entMgr.addEntity();
    m_django->addComponent<engine::PositionComponent>(430.f,213.f);
    m_django->addComponent<engine::SpriteComponent>("", textureAtlas["django"]);
    m_django->addComponent<engine::AnimationComponent>("", 0, 3, 0.5);

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
  }

  void Level1::onProcessInput() {
    /*
    m_mira.x = GetMouseX()/SCALE - m_mira.tex.width/2.f;
    m_mira.y = GetMouseY()/SCALE - m_mira.tex.height/2.f;
    */
  }

  // float x{};

  void Level1::onUpdate(float deltatime) {
    /*
    x -= deltatime*CLOUDS_SPEED;
    if(x <= -m_nubes.tex.width) x = 0.f;
    */
  }

  void Level1::onRender() {
    using namespace raylib;
    rlScalef(2.f, 2.f, 1.f);
    DrawTexture(background1, 0, 0, WHITE);
    DrawTexture(nubesAnimate, 0, 0, WHITE); // falta move 
    DrawTexture(mi_cerro, 0, 0, WHITE);
    DrawTexture(muro_izquierdo, 0, 0, WHITE);
    DrawTexture(deco_muros, 0, 0, WHITE);
    DrawTexture(ventanas_estaticas, 0, 0, WHITE);
    DrawTexture(tejado, 0, 0, WHITE);

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