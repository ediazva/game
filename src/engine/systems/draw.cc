#include "engine/systems/draw.h"
#include "engine/entity_manager.h"
#include "engine/assets/texture.h"
#include "engine/components/sprite.h"

namespace engine {
  void DrawSystem::update(const float& deltatime) {
    using namespace raylib;

    auto comps = entityMgr().getEntities<SpriteComponent>();
    for(auto& e : comps) {
      auto& sprite = e->getComponent<SpriteComponent>();
      DrawTexture(sprite.atlas.texture(), 0, 0, WHITE);
    }
    // raylib::DrawTexture()
  }
} // namespace engine 