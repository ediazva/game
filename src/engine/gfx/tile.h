#pragma once
#include "engine/result.h"
#include "engine/gfx/texture.h"

namespace engine::gfx {
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
  public:
    void draw();

    static Tile MakeFromPath(const char* path, const TileInfo& info, Result* res = nullptr);
  };
} // namespace engine::gfx