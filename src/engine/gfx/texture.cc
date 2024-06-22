#include "engine/gfx/texture.h"

namespace engine::gfx {
  Texture::~Texture() {
    raylib::UnloadTexture(base);
  }

  Texture Texture::LoadFromPath(const char* path, Result* res) {
    Texture tex;
    tex.base = raylib::LoadTexture(path);
    if(res)
      *res = tex.base.id ? kSucess_Result : kFileNotFound_Error;
    return tex;
  }
} // namespace engine::gfx