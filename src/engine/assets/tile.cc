#include "engine/assets/tile.h"

namespace engine::assets {
  Tile Tile::MakeFromPath(const char* path, const TileInfo& info, Result* res) { 
    // Draw
    Tile tile;
    tile.m_info = info;
    tile.m_tex = Texture::MakeFromPath(path, res);
    return tile;
  }
} // namespace engine::assets