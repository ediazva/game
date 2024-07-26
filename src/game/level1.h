#pragma once
#include "engine/entity.h"
#include "engine/level.h"
#include "engine/assets/texture.h"
#include "engine/assets/texture_atlas.h"

#include <unordered_map>

namespace game {
  // JUEGO
  class Level1 : public engine::Level {
    static inline constexpr const float CLOUDS_SPEED = 14.f; 
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
    
    struct {
      float x;
      engine::assets::Texture tex;
    } nubesAnimate{};

    engine::EntityPtr ropaCerro;
    engine::EntityPtr elCocinero;
    engine::EntityPtr m_django;
    
    void initializeSystemManager();
    void initializeEntityManager();

    void resetEntities();

    virtual void onInit() override;
    virtual void onProcessInput() override;
    virtual void onUpdate(float deltatime) override;
    virtual void onRender() override;
  };
} // namespace game
