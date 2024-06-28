#pragma once
namespace engine::assets {
  struct Tile;
} // namespace engine::assets

namespace raylib {
  #include <raylib.h>

  // FIXME: Delete this!
  void DrawTile(const engine::assets::Tile& t, const Vector2& origin);
} // namespace raylib