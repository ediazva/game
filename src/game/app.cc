#include "app.h"

#include "level0.h"
#include "level1.h"
#include "raylib.h"

#include "engine/mice_manager.h"

namespace game {
  App::App() : engine::Engine("Django Sin Palomas", 1200, 600, 60) {}

  void App::onInit() {
    ::DisableCursor();
    m_main = addLevel<Level1>();
    music = ::LoadMusicStream("data/songs/prision.wav");

    // ::InitAudioDevice();
    PlayMusicStream(music);

    // m_menu = addLevel<Level0>();
  }

  void App::onUpdate() {
    // UpdateMusicStream(music); // Update music buffer with new stream data
  }

  App::~App() {
    // UnloadMusicStream(music);
    // ::CloseAudioDevice();
  }

  void App::onProcessInput() {
  }
} // namespace game
