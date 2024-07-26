#pragma once
#include "engine/level.h"
#include "engine/assets/texture.h"
#include "engine/assets/texture_atlas.h"

#include <unordered_map>

namespace game {
  // Selección
  class Level0 : public engine::Level {
    public:
    std::unordered_map<const char*, engine::assets::TextureAtlas> textureAtlas;

    engine::assets::Texture inicio;

    engine::EntityPtr btn_jugar;
    engine::EntityPtr btn_1p;
    engine::EntityPtr btn_2p;

    void initializeSystemManager();
    void initializeEntityManager();

    virtual void onInit() override;
    virtual void onProcessInput() override;
    virtual void onUpdate(float deltatime) override;
    virtual void onRender() override;
  };
} // namespace game