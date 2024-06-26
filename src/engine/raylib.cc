#include "engine/raylib.h"

#include "engine/assets/tile.h"

namespace raylib {
  void DrawTile(const engine::assets::Tile& t, const Vector2& origin) {
    const auto& size = t.info.size;
    const auto& map = t.map;

    for(size_t i = 0; i < map.size(); ++i) {
      for(size_t j = 0; j < map[i].size(); ++j) {
        const auto og = t.getTileOrigin(map[i][j]);
        DrawTextureRec(t.tex,
          {og.first,
           og.second,
           size.w,
           size.h},
          {origin.x + j*size.w,
           origin.y + i*size.h}, WHITE);
      }
    }
    // DrawTexture(t.m_tex, 0, 0, WHITE);
  }
} // namespace raylib