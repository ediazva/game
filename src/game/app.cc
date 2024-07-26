#include "app.h"

#include "level0.h"
#include "level1.h"

namespace game {
  App::App() : 
    engine::Engine("Django Sin Palomas", 1200, 600, 60) {}

  void App::onInit() {
    // raylib::HideCursor();
    m_main = addLevel<Level1>();
    m_menu = addLevel<Level0>();
  }

  void App::onProcessInput() {
  }
} // namespace game