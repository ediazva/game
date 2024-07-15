#pragma once
#include "engine/assets/texture.h"

#include <vector>

namespace engine::assets {
  class TextureAtlas {
  public:
    struct Info {
      struct {
        unsigned w;
        unsigned h;
      } size;
      float scale{ 1.f };
    };

    TextureAtlas() = default;
    TextureAtlas(Texture&& tex, const Info& info) {
      makeFromTexture(std::move(tex), info);
    }

    void makeFromTexture(Texture&& tex, const Info& info);
    void setScale(float scale);

    const Texture& texture() const { return m_tex; }
    const Info& info() const { return m_info; }
    size_t nrects() const { return m_rects.size(); }

    const raylib::Vector2& rectOrigin(unsigned idx) const { return m_rects.at(idx); }
  private:
    Texture m_tex{};
    Info m_info{};
    std::vector<raylib::Vector2> m_rects;

    void initRects();
    void initInfo(const Info& info);
  };
} // namespace engine::assets
