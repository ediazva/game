#include "engine/gfx/tile.h"

namespace engine::gfx {
  void Tile::draw() {
    using namespace raylib;
    // DrawTextureRec(m_tex, {0, 0, 16, 16}, {10, 10}, WHITE);
    // DrawTexture(m_tex, 0, 0, WHITE);
    // for(int y = 0; y*tileSize.h < m_tex.height; ++y) {
      // for(int x = 0; x*tileSize.w < m_tex.width; ++x) {
        // DrawRectangleLines(x*tileSize.w, y*tileSize.h, tileSize.w, tileSize.h, GREEN);
      // }
    // }
  }
  
  Tile Tile::MakeFromPath(const char* path, const TileInfo& info, Result* res) { 
    // Draw
    Tile tile;
    tile.m_info = info;
    tile.m_tex = Texture::MakeFromPath(path, res);
    return tile;
  }
} // namespace engine::gfx