#include "engine/engine.h"

#include "engine/debug.h"
#include "engine/raylib.h"
#include "engine/assets/sound.h"
#include "engine/assets/texture.h"

namespace engine {
  Engine::Engine(const char* title, unsigned w, unsigned h, int fps) :
    m_currentLevel{} {
    raylib::InitWindow(w, h, title);
    if(fps > 0)
      raylib::SetTargetFPS(fps);
    raylib::InitAudioDevice();

    configure_raylib_log();
  }
  Engine::~Engine() {
    m_levels.clear();
    raylib::CloseAudioDevice();
    raylib::CloseWindow();
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

    while(!raylib::WindowShouldClose()) {
      processInput();
      update(raylib::GetFrameTime());
      render();
    }
  }

  void Engine::processInput() {
    onProcessInput();
    if(m_currentLevel) m_currentLevel->processInput();
  }

  void Engine::update(float deltatime) {
    if(m_currentLevel) m_currentLevel->update(deltatime);
    onUpdate(deltatime);
  }

  void Engine::render() {
    raylib::BeginDrawing();
    onRender();
    if(m_currentLevel) m_currentLevel->render();

    raylib::EndDrawing();
  }
} // namespace engine
