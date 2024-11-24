#include "engine/assets/texture_pool.h"

#include <cassert>

namespace engine::assets {
  TexturePool::TexturePool(fs::path&& base) :
    m_base{std::move(base)} {}
  
  bool TexturePool::loadFromPath(const char* id, const char* path) {
    const auto pair = m_pool.insert({id, Texture::MakeFromPath(m_base/path)});
    return pair.first->second.isValid() && pair.second;
  }

  void TexturePool::remove(const char* id) {
    auto it = m_pool.find(id);
    assert(it != m_pool.end());
    m_pool.erase(it);
  }

  const Texture& TexturePool::operator[](const char* id) const {
    const auto it = m_pool.find(id);
    assert(it != m_pool.end());
    return it->second;
  }

  bool TexturePool::contains(const char* id) const {
    return m_pool.contains(id);
  }

  TextureAtlas TexturePool::makeAtlas(const char* id, const TextureAtlas::Info& info) const {
    assert(contains(id));

    TextureAtlas atlas;
    atlas.makeFromTexture(&(*this)[id], info);
    return atlas;
  }
} // namespace engine::assets