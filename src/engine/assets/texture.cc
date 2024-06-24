#include "engine/assets/texture.h"

namespace engine::assets {
  Texture::~Texture() {
    raylib::UnloadTexture(*this);
  }

  Texture Texture::MakeFromPath(const char* path, Result* res) {
    Texture tex;
    tex.copy_base(raylib::LoadTexture(path));
    if(res)
      *res = tex.id ? kSucess_Result : kFileNotFound_Error;
    return tex;
  }
} // namespace engine::assets