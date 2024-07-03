#include "engine/systems/draw.h"
#include "engine/entity_manager.h"
#include "engine/assets/texture.h"
#include "engine/components/sprite.h"
#include "engine/components/position.h"

namespace engine {
  void DrawSystem::update(const float& deltatime) {
    using namespace raylib;

    ClearBackground(LIGHTGRAY);

    auto comps = entityMgr().getEntities<SpriteComponent>();
    for(auto& e : comps) {
      auto& sprite = e->getComponent<SpriteComponent>();
      auto& position = e->getComponent<PositionComponent>();

      DrawTexture(sprite.atlas.texture(), position.coord.x,
                  position.coord.y, WHITE);
    }
    // raylib::DrawTexture()
  }
} // namespace engine
