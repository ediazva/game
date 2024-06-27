#include "engine/assets/texture_atlas.h"

#include "engine/debug.h"

namespace engine::assets {
  void TextureAtlas::makeFromTexture(Texture&& tex, const Info& info) {
    m_tex = std::move(tex);
    m_info = info;
    initRects();
  }

  void TextureAtlas::initRects() {
    const auto& info = this->info();
    DEBUG_TRACE("[TextureAtlas] w=%d h=%d", info.size.w, info.size.h);

    m_rects.clear();
    const auto ncols = m_tex.width / info.size.w;
    const auto nrows = m_tex.height / info.size.h;
    m_rects.reserve(nrows*ncols);
    for(unsigned i = 0; i < nrows; ++i) {
      for(unsigned j = 0; j < ncols; ++j) {
        m_rects.push_back(raylib::Vector2(j*info.size.w,i*info.size.h));
      }
    }
  }
} // namespace engine::assets