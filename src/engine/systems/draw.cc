#include "engine/systems/draw.h"
#include "engine/entity_manager.h"
#include "engine/components/sprite.h"
#include "engine/components/transform.h"

namespace engine {
  void DrawSystem::render() {
    for(auto& e : entityMgr().getEntities<SpriteComponent, TransformComponent>()) {
      auto& sprite = e->getComponent<SpriteComponent>();
      auto& transform = e->getComponent<TransformComponent>();

      // DrawTexture(sprite.atlas->texture(), position.coord.x,
      //             position.coord.y, WHITE);
      // auto& atlasPair = sprite.stateMap[sprite.currentState];
      auto& atlas = sprite.stateMap.at(sprite.currentState).first;
      auto& atlIdx = sprite.stateMap.at(sprite.currentState).second;

      atlas.draw(atlIdx, transform.position, transform.scale);

      // Rectangle rect{ atlas.rectOrigin(atlIdx).x,
                      // atlas.rectOrigin(atlIdx).y,
                      // (float)atlas.info().size.w,
                      // (float)atlas.info().size.h };
      // DrawTextureRec(atlas.texture(), rect, position.coord, WHITE);
      // const auto& og = atlas.rectOrigin(atlIdx);
      // const auto& size = atlas.info().size;

      // TODO: Width negativo indica un mirror de textura
      // DrawTexturePro(
          // atlas.texture(),
          // { og.x, og.y, static_cast<float>(size.w), static_cast<float>(size.h) },
          // { position.coord.x - sprite.offset.x, position.coord.y - sprite.offset.y,
            // size.w * atlas.info().scale, size.h * atlas.info().scale },
          // {}, 0.f, WHITE);
    }

    // Identidades que contienen un texto
    /*for(auto& e : entityMgr().getEntities<TextComponent, PositionComponent>()) {
      auto& text = e->getComponent<TextComponent>();
      auto& position = e->getComponent<PositionComponent>();

      DrawText(text.str.c_str(), position.coord.x, position.coord.y,
               text.fontSize, text.color);
    }*/

    // ::DrawTexture()
  }
} // namespace engine
