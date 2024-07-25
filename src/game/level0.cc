#include "level0.h"

#include "engine/systems/draw.h"
#include "engine/components/text.h"
#include "engine/components/position.h"
#include "engine/raylib.h"

namespace game {
  void Level0::onInit() {
    auto& sysMgr = systemManager();
    auto& entMgr = entityManager();

    sysMgr.addSystem(std::make_shared<engine::DrawSystem>());

    auto& nubes = entMgr.addEntity();
    nubes->addComponent<engine::TextComponent>("Adios mundo", raylib::RED, 12);
    nubes->addComponent<engine::PositionComponent>(0.f, 0.f);
  }

  void Level0::onUpdate(float deltatime) {

  }
} // namespace game