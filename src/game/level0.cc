#include "level0.h"

#include "engine/systems/draw.h"
#include "engine/components/text.h"
#include "engine/components/position.h"
#include "engine/systems/animation.h"
#include "engine/components/animation.h"
#include "engine/components/sprite.h"
#include "engine/raylib.h"

using namespace raylib;  

namespace game {
  void Level0::onInit() {

    // LA PANTALLA DE INICIO ES DE 1440 - 720   y los buttoms    256 - 80
    inicio = engine::assets::Texture::MakeFromPath(R"(C:\Users\Usuario\Desktop\game\data\level0\inicio.png)");

    textureAtlas["btn_jugar"].makeFromTexture(
      engine::assets::Texture::MakeFromPath(R"(C:\Users\Usuario\Desktop\game\data\level0\btn-jugar.png)"),
      {.size = {256, 80}}
    );

    textureAtlas["btn_1p"].makeFromTexture(
      engine::assets::Texture::MakeFromPath(R"(C:\Users\Usuario\Desktop\game\data\level0\btn-1player.png)"),
      {.size = {256, 80}}
    );

    textureAtlas["btn_2p"].makeFromTexture(
      engine::assets::Texture::MakeFromPath(R"(C:\Users\Usuario\Desktop\game\data\level0\btn-2players.png)"),
      {.size = {256, 80}}
    );

    auto& sysMgr = systemManager();
    auto& entMgr = entityManager();

    sysMgr.addSystem(std::make_shared<engine::DrawSystem>());

    auto& nubes = entMgr.addEntity();
    nubes->addComponent<engine::TextComponent>("Adios mundo", raylib::RED, 12);
    nubes->addComponent<engine::PositionComponent>(0.f, 0.f);
  }

void Level0::initializeEntityManager() {
    auto& entMgr = entityManager();

    btn_jugar = entMgr.addEntity();
    btn_jugar->addComponent<engine::PositionComponent>(530.f,490.f);
    btn_jugar->addComponent<engine::SpriteComponent>("", textureAtlas["btn_jugar"]);
    btn_jugar->addComponent<engine::AnimationComponent>("", 0, 3, 1);

    btn_1p = entMgr.addEntity();
    btn_1p->addComponent<engine::PositionComponent>(306.f,490.f);
    btn_1p->addComponent<engine::SpriteComponent>("", textureAtlas["btn_1p"]);
    btn_1p->addComponent<engine::AnimationComponent>("", 0, 3, 1);

    btn_2p = entMgr.addEntity();
    btn_2p->addComponent<engine::PositionComponent>(754.f,490.f);
    btn_2p->addComponent<engine::SpriteComponent>("", textureAtlas["btn_2p"]);
    btn_2p->addComponent<engine::AnimationComponent>("", 0, 3, 1);

    // nubesAnimate = entMgr.addEntity();
    // nubesAnimate->addComponent<engine::PositionComponent>(0.f,0.f);
    // nubesAnimate->addComponent<engine::SpriteComponent>("", "nubes");
    // nubesAnimate->addComponent<engine::AnimationComponent>("", 0, 3, 0.5);
    
  }

  void Level0::onUpdate(float deltatime) {

  }

  void Level0::onRender() {
    using namespace raylib;
    rlScalef(1.f, 1.f, 1.f);
    DrawTexture(inicio, 0, 0, WHITE);
  }
} // namespace game