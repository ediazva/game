#pragma once
#include "engine/level.h"
#include "engine/assets/texture.h"
#include "engine/assets/texture_atlas.h"

// JUEGO
namespace game {
  class Level1 : public engine::Level {
    static inline constexpr const float SCALE = 2.f; 
    static inline constexpr const float CLOUDS_SPEED = 14.f; 
    engine::assets::Texture m_background;
    engine::assets::Texture m_background2;
    engine::assets::Texture m_ladrillos;
    engine::assets::Texture m_pisos;
    
    engine::EntityPtr m_claro;
    engine::assets::TextureAtlas m_claroAtlas;

    struct {
      float x;
      float y;
      engine::assets::Texture tex;
    } m_mira{};

    struct {
      float x; // Parallax effect
      engine::assets::Texture tex;
    } m_nubes;

    virtual void onInit() override;
    virtual void onProcessInput() override;
    virtual void onUpdate(float deltatime) override;
    virtual void onRender() override;
  };
} // namespace game