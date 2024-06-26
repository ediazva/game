#pragma once
#include "engine/assets/texture.h"

#include <utility>
#include <vector>

namespace engine::assets {
  typedef std::vector<std::vector<int>> TileMap;

  struct TileInfo {
    struct {
      float w;
      float h;
    } size;
  };
  
  /// Vectores
  struct Tile {
    Texture tex{};
    TileInfo info{};
    TileMap map;

    std::pair<float, float> getTileOrigin(unsigned idx) const {
      const int tw = tex.width / info.size.w;
      return idx > tw ?
             std::pair<float, float>{0.f,0.f} :
             std::pair<float, float>{(idx % tw) * info.size.w, (idx / tw) * info.size.h};
    }
    // void getTexture(int idx)
  };
} // namespace engine::assets