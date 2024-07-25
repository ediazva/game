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

    auto comps = entityMgr().getEntities<SpriteComponent, PositionComponent>();
    for(auto& e : comps) {
      auto& sprite = e->getComponent<SpriteComponent>();
      auto& position = e->getComponent<PositionComponent>();

      // DrawTexture(sprite.atlas->texture(), position.coord.x,
      //             position.coord.y, WHITE);
      // auto& atlasPair = sprite.stateMap[sprite.currentState];
      auto& atlas = sprite.stateMap.at(sprite.currentState).first;
      auto& atlIdx = sprite.stateMap.at(sprite.currentState).second;

      Rectangle rect{ atlas.rectOrigin(atlIdx).x,
                      atlas.rectOrigin(atlIdx).y,
                      (float)atlas.info().size.w,
                      (float)atlas.info().size.h };
      DrawTextureRec(atlas.texture(), rect, position.coord, WHITE);
      const auto& og = atlas.rectOrigin(atlIdx);
      const auto& size = atlas.info().size;

      // TODO: Width negativo indica un mirror de textura
      DrawTexturePro(
          atlas.texture(),
          { og.x, og.y, static_cast<float>(size.w), static_cast<float>(size.h) },
          { position.coord.x - sprite.offset.x, position.coord.y - sprite.offset.y,
            size.w * atlas.info().scale, size.h * atlas.info().scale },
          {}, 0.f, WHITE);
    }

    // Identidades que contienen un texto
    comps = entityMgr().getEntities<TextComponent, PositionComponent>();
    for(auto& e : comps) {
      auto& text = e->getComponent<TextComponent>();
      auto& position = e->getComponent<PositionComponent>();

      DrawText(text.str.c_str(), position.coord.x, position.coord.x,
               text.fontSize, text.color);
    }

    // raylib::DrawTexture()
  }
} // namespace engine
