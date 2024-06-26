#pragma once
#include <vector>

namespace engine::assets {
  struct Tile;
} // namespace engine::assets

namespace raylib {
  #include <raylib.h>

  void DrawTile(const engine::assets::Tile& t, const Vector2& origin);
} // namespace raylib