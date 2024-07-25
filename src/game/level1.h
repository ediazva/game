#pragma once
#include "engine/level.h"
#include "engine/assets/texture.h"

// JUEGO
namespace game {
  class Level1 : public engine::Level {
    engine::assets::Texture m_background;
  public:
    virtual void onInit() override;
    virtual void onRender() override;
  };
} // namespace game