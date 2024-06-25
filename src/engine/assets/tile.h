#pragma once
#include "engine/result.h"
#include "engine/assets/texture.h"

namespace engine::assets {
  struct TileInfo {
    struct {
      unsigned w;
      unsigned h;
    } tileSize;
    
    struct {
      unsigned x;
      unsigned y;
    } offset;
  };

  class Tile {
    Texture m_tex;
    TileInfo m_info;
  };
} // namespace engine::assets