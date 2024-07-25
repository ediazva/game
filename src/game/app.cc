#include "app.h"

#include "level0.h"
#include "level1.h"

namespace game {
  App::App() : 
    engine::Engine("Django Sin Palomas", 800, 400, 60) {}

  void App::onInit() {
    m_main = addLevel<Level1>();
    m_menu = addLevel<Level0>();
  }

  void App::onProcessInput() {
  }
} // namespace game