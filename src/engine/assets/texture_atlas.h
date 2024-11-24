#pragma once
#include <raylib.h>
#include <vector>

namespace engine::assets {
  class Texture;

  class TextureAtlas {
  public:
    TextureAtlas();

    struct Info {
      struct {
        unsigned w;
        unsigned h;
      } size;
      struct {
        unsigned r;
        unsigned b;
      } padding;
      struct {
        unsigned l;
        unsigned t;
      } offset;
      float scale{ 1.f };
    };

    void draw(unsigned idx, const ::Vector2& position) const;

    const std::vector<::Vector2>& points() const {return m_points;}
    const Info& info() const {return m_info;}
  private:
    friend class TexturePool;

    void makeFromTexture(const Texture* tex, const Info& info);
    void initInfo(const Info& info);
    void initPoints();

    std::vector<::Vector2> m_points;
    Info m_info;
    const Texture* m_refTexture;
  };
} // namespace engine::assets
