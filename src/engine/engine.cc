#include "engine/engine.h"

#include "engine/debug.h"
#include "engine/timer_manager.h"

#include <raylib.h>

namespace engine {
  Engine::Engine(const char* title, unsigned w, unsigned h, int fps) :
    m_currentLevel{} {
    ::InitWindow(w, h, title);
    if(fps > 0)
      ::SetTargetFPS(fps);
    ::InitAudioDevice();

    configure_raylib_log();
  }
  Engine::~Engine() {
    m_levels.clear();
    ::CloseAudioDevice();
    ::CloseWindow();
  }

  // assets::Tile Engine::makeTileFromPath(const char* path, Result* res) {
  // assets::Tile tile;
  // }

  // ======================================================================

  // ================
  // MAIN FUNCTIONS
  // ================
  void Engine::changeToLevel(LevelID id) {
    for(auto& level : m_levels) {
      if(level->id() == id) {
        if(m_currentLevel) m_currentLevel->destroy();
        m_currentLevel = level.get();
        m_currentLevel->init();
        return;
      }
    }

    DEBUG_WARNING("Level %d don't found", id);
  }
  // ======================================================================

  // ================
  // MAIN FUNCTIONS
  // ================
  void Engine::run() {
    onInit();
    // m_sysmgr->init();

    while(!::WindowShouldClose()) {
      processInput();
      update(::GetFrameTime());
      render();
    }
  }

  void Engine::processInput() {
    onProcessInput();
    if(m_currentLevel) m_currentLevel->processInput();
  }

  void Engine::update(float deltatime) {
    TimerManager::Tick(deltatime);
    if(m_currentLevel) m_currentLevel->update(deltatime);
    onUpdate(deltatime);
  }

  void Engine::render() {
    ::BeginDrawing();
    onRender();
    if(m_currentLevel) m_currentLevel->render();

    ::EndDrawing();
  }
} // namespace engine
