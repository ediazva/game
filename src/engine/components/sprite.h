#pragma once
#include "engine/components/component.h"
#include "engine/assets/texture.h"
#include "engine/assets/texture_atlas.h"
#include "raylib.h"
#include <unordered_map>
#include <utility>
#include <string>

namespace engine {
  // TODO: Offset para donde dibujar textura
  struct SpriteComponent : public Component {
    // assets::TextureAtlas& atlas;
    // unsigned atlIdx{};
    float height;
    float width;
    ::Vector2 offset{};

    std::string currentState;
    // Cada estado tiene un atlas diferente y un index asociado a ese
    std::unordered_map<std::string, std::pair<assets::TextureAtlas&, unsigned>> stateMap{};

    void changeState(std::string state) {
      currentState = state;
    }

    void addState(std::string state, assets::TextureAtlas& atlas, unsigned atlIdx = 0) {
      stateMap.insert(std::make_pair(state,
                                     std::make_pair(std::ref(atlas), atlIdx)));
    }
    // SpriteComponent(assets::Texture&& tex, const assets::TextureAtlas::Info& info) {
    //   atlas.makeFromTexture(std::move(tex), info);
    // }
    SpriteComponent(std::string currentState, assets::TextureAtlas& atlas, unsigned atlIdx = 0,
                    float offstx = 0, float offsty = 0)
        : currentState(currentState), offset(offstx, offsty) {
      // : atlas(atlas), atlIdx(atlIdx) {
      stateMap.insert(std::make_pair(currentState,
                                     std::make_pair(std::ref(atlas), atlIdx)));
      // stateMap[state] = std::make_pair(std::ref(atlas), atlIdx);
    }

    ~SpriteComponent() {
      DEBUG_TRACE("SpriteComponent destruido");
    }
  };
} // namespace engine
