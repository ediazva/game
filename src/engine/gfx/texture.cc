#include "engine/gfx/texture.h"

namespace engine::gfx {
  Texture::~Texture() {
    raylib::UnloadTexture(*this);
  }

  Texture Texture::LoadFromPath(const char* path, Result* res) {
    Texture tex = (Texture)raylib::LoadTexture(path);
    if(res)
      *res = tex.id ? kSucess_Result : kFileNotFound_Error;
    return tex;
  }
} // namespace engine::gfx