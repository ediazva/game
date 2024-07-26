#pragma once
#include "engine/entity.h"
#include "engine/level.h"
#include "engine/assets/texture.h"
#include "engine/assets/texture_atlas.h"

#include <unordered_map>

namespace game {
  // JUEGO
  class Level1 : public engine::Level {
    std::unordered_map<const char*, engine::assets::TextureAtlas> textureAtlas;

    const unsigned maxPalomasAlive = 5, maxBullets = 6;
    // engine::EntityPtr
    engine::Entity *bulletsEntity, *scoreEntity;
    unsigned score{}, bullets{ maxBullets };

    engine::assets::Texture background1;
    engine::assets::Texture muro_izquierdo;
    engine::assets::Texture mi_cerro;
    engine::assets::Texture ventanas_estaticas;
    engine::assets::Texture tejado;
    engine::assets::Texture deco_muros;
    engine::assets::Texture nubesAnimate;

    engine::EntityPtr ropaCerro;
    engine::EntityPtr elCocinero;
    engine::EntityPtr m_django;

    /*static inline constexpr const float SCALE = 2.f;
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
    } m_nubes;*/

    void initializeSystemManager();
    void initializeEntityManager();

    void resetEntities();

    virtual void onInit() override;
    virtual void onProcessInput() override;
    virtual void onUpdate(float deltatime) override;
    virtual void onRender() override;
  };
} // namespace game
