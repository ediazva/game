#include "engine/systems/draw.h"
#include "engine/entity_manager.h"
#include "engine/assets/texture.h"
#include "engine/components/sprite.h"
#include "engine/components/position.h"
#include "engine/components/text.h"
#include "raylib.h"

namespace engine {
  void DrawSystem::update(float deltatime) {
    using namespace raylib;

    ClearBackground(LIGHTGRAY);

    for(auto& e : entityMgr().getEntities<SpriteComponent, PositionComponent>()) {
      auto& sprite = e->getComponent<SpriteComponent>();
      auto& position = e->getComponent<PositionComponent>();

      // DrawTexture(sprite.atlas->texture(), position.coord.x,
      //             position.coord.y, WHITE);
      Rectangle rect{ sprite.atlas.rectOrigin(sprite.atlIdx).x,
                      sprite.atlas.rectOrigin(sprite.atlIdx).y,
                      (float)sprite.atlas.info().size.w,
                      (float)sprite.atlas.info().size.h };
      DrawTextureRec(sprite.atlas.texture(), rect, position.coord, WHITE);
      const auto& og = sprite.atlas.rectOrigin(sprite.atlIdx);
      const auto& size = sprite.atlas.info().size;

      // TODO: Width negativo indica un mirror de textura
      DrawTexturePro(
          sprite.atlas.texture(),
          { og.x, og.y, static_cast<float>(size.w), static_cast<float>(size.h) },
          { position.coord.x, position.coord.y, size.w * sprite.atlas.info().scale, size.h * sprite.atlas.info().scale }, {}, 0.f, WHITE);
    }

    // Identidades que contienen un texto
    for(auto& e : entityMgr().getEntities<TextComponent, PositionComponent>()) {
      auto& text = e->getComponent<TextComponent>();
      auto& position = e->getComponent<PositionComponent>();

      DrawText(text.str.c_str(), position.coord.x, position.coord.x,
               text.fontSize, text.color);
    }

    // raylib::DrawTexture()
  }
} // namespace engine
