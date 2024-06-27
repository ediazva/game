#pragma once
#include "engine/assets/texture_atlas.h"

namespace engine::assets {
  typedef std::vector<std::vector<int>> TileMap;

  struct Tile {
    TextureAtlas atlas;
    TileMap map;
  };
} // namespace engine::assets