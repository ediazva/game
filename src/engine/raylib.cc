#include "engine/raylib.h"

#include "engine/assets/tile.h"

namespace raylib {
  void DrawTile(const engine::assets::Tile& t, const Vector2& origin) {
    const auto& size = t.atlas.info().size;
    const auto& scale = t.atlas.info().scale;
    const auto& map = t.map;
    for(size_t i = 0; i < map.size(); ++i) {
      for(size_t j = 0; j < map[i].size(); ++j) {
        if(map[i][j] < 0) continue;
        const auto& og = t.atlas.rectOrigin(map[i][j]);
        const auto scaledWidth = size.w*scale;
        const auto scaledHeight = size.h*scale;
        DrawTexturePro(
          t.atlas.texture(),
          {
            og.x,
            og.y,
            static_cast<float>(size.w),
            static_cast<float>(size.h)
          },
          {
            origin.x + j*scaledWidth,
            origin.y + i*scaledHeight,
            scaledWidth,
            scaledHeight
          },
          {},
          0.f,
          WHITE);
      }
    }
  }
} // namespace raylib