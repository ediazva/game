#include "engine/raylib.h"

#include "engine/assets/tile.h"

namespace raylib {
  void DrawTile(const engine::assets::Tile& t, const Vector2& origin) {
    const auto& size = t.atlas.info().size;
    const auto& scale = t.atlas.info().scale;
    for(const auto& a : t.map) {
      for(const auto& b : a) {
        const auto& og = t.atlas.rectOrigin(b);
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
            origin.x + og.x,
            origin.y + og.y,
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