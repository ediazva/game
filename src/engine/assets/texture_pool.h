#pragma once
#include "engine/assets/texture.h"
#include "engine/assets/texture_atlas.h"

#include <unordered_map>

namespace engine::assets {
  class TexturePool {
  public:
    TexturePool(fs::path&& base);

    bool loadFromPath(const char* id, const char* path);
    void remove(const char* id);
    const Texture& operator[](const char* id) const;
    bool contains(const char* id) const;

    TextureAtlas makeAtlas(const char* id, const TextureAtlas::Info& info) const;
  private:
    std::unordered_map<const char*, Texture> m_pool;
    fs::path m_base;
  };
} // namespace engine::assets