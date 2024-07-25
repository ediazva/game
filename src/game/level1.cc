#include "level1.h"

#include "engine/systems/draw.h"
#include "engine/components/sprite.h"

using namespace raylib;

namespace game {
  void Level1::onInit() {
    auto& sysMgr = systemManager();
    auto& entMgr = entityManager();

    m_background = engine::assets::Texture::MakeFromPath("/home/phobos/Desktop/Universidad/game/data/img/background.png");
    m_background2 = engine::assets::Texture::MakeFromPath("/home/phobos/Desktop/Universidad/game/data/img/background2.png");
    m_ladrillos = engine::assets::Texture::MakeFromPath("/home/phobos/Desktop/Universidad/game/data/img/ladrillos.png");
    m_pisos = engine::assets::Texture::MakeFromPath("/home/phobos/Desktop/Universidad/game/data/img/pisos.png");
    m_nubes.tex = engine::assets::Texture::MakeFromPath("/home/phobos/Desktop/Universidad/game/data/img/nubes.png");
    m_mira.tex = engine::assets::Texture::MakeFromPath("/home/phobos/Desktop/Universidad/game/data/img/mira.png");

    // ================
    // ENTITIES
    // ================
    // m_claro = entMgr.addEntity();
    // m_claro->addComponent<engine::SpriteComponent>(
      
    // );
  }

  void Level1::onProcessInput() {
    m_mira.x = GetMouseX()/SCALE - m_mira.tex.width/2.f;
    m_mira.y = GetMouseY()/SCALE - m_mira.tex.height/2.f;
  }

  float x{};

  void Level1::onUpdate(float deltatime) {
    x -= deltatime*CLOUDS_SPEED;
    if(x <= -m_nubes.tex.width) x = 0.f;
  }

  void Level1::onRender() {
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
  }
} // namespace game