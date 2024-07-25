#pragma once
#include "engine/engine.h"

namespace game  {
  class Level0;
  class Level1;

  class App : public engine::Engine {
    Level0* m_menu;
    Level1* m_main;
  public:
    App();

    virtual void onInit() override;
    virtual void onProcessInput() override;
    // virtual void onUpdate(float deltatime) override;
  };
} // namespace game