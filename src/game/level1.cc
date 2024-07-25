#include "level1.h"

#include "engine/systems/draw.h"

namespace game {
  void Level1::onInit() {
    auto& sysMgr = systemManager();
    auto& entMgr = entityManager();

    // sysMgr.addSystem(std::make_shared<engine::DrawSystem>());

    m_background = engine::assets::Texture::MakeFromPath("/home/phobos/Desktop/Universidad/game/data/img/background.png");
  }

  void Level1::onRender() {
    using namespace raylib;
    DrawTexture(m_background, 0, 0, WHITE);
  }
} // namespace game