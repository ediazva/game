#include "engine/assets/texture_atlas.h"

#include "engine/assets/texture.h"
#include "engine/debug.h"
#include <cassert>

namespace engine::assets {
  TextureAtlas::TextureAtlas() :
    m_refTexture{},
    m_info{} {}

  void TextureAtlas::makeFromTexture(const Texture* tex, const Info& info) {
    assert(tex);
    m_refTexture = tex;
    initInfo(info),
    initPoints();
  }

  void TextureAtlas::initInfo(const Info& info) {
    assert(!(info.size.w == 0 || info.size.h == 0));
    assert(info.scale > 0.f);
    m_info = info;
  }

  void TextureAtlas::initPoints() {
    const auto& info = this->info();
    DEBUG_TRACE("[TextureAtlas] w=%d h=%d", info.size.w, info.size.h);

    const auto ncols = (m_refTexture->width + info.padding.r) / (info.size.w + info.padding.r);
    const auto nrows = (m_refTexture->height + info.padding.b) / (info.size.h + info.padding.b);
    m_points.reserve(nrows * ncols);
    for(unsigned i = 0; i < nrows; ++i) {
      for(unsigned j = 0; j < ncols; ++j) {
        const auto x = info.offset.l + (info.size.w + info.padding.r)*j;
        const auto y = info.offset.t + (info.size.h + info.padding.b)*i;
        
        m_points.push_back(::Vector2(x, y));
      }
    }
    DEBUG_TRACE("[TextureAtlas] #points=%zu", m_points.size());
  }

  void TextureAtlas::draw(unsigned idx, const ::Vector2& position) const {
    assert(idx < m_points.size());

    DrawTexturePro(
          *m_refTexture,
          { m_points[idx].x, m_points[idx].y, static_cast<float>(m_info.size.w), static_cast<float>(m_info.size.h) },
          { position.x, position.y,
            m_info.size.w * m_info.scale, m_info.size.h * m_info.scale },
          {}, 0.f, WHITE);
  }
} // namespace engine::assets
