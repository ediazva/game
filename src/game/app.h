#pragma once
#include "engine/engine.h"

namespace game {
  class Level0;
  class Level1;

  class App : public engine::Engine {
    Level0* m_menu;
    Level1* m_main;
    raylib::Music music;
  public:
    App();
    ~App();

    virtual void onInit() override;
    virtual void onProcessInput() override;
    virtual void onUpdate();
  };
} // namespace game
