#pragma once
#include "engine/level.h"

namespace game {
  class Level0 : public engine::Level {
  public:
    virtual void onInit() override;
    virtual void onUpdate(float deltatime) override;
  };
} // namespace game