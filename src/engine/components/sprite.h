#pragma once
#include "engine/components/component.h"
#include "engine/assets/texture.h"
#include "engine/assets/texture_atlas.h"

namespace engine {
  struct SpriteComponent : public Component {
    assets::TextureAtlas atlas;
    
    SpriteComponent(assets::Texture&& tex, const assets::TextureAtlas::Info& info) {
      atlas.makeFromTexture(std::move(tex), info);
    }
  };
} // namespace engine