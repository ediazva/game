#include "engine/engine.h"

#include "engine/debug.h"
#include "engine/timer_manager.h"
#include "engine/scene.h"
#include "engine/assets/texture.h"

#include <raylib.h>

namespace engine {
  namespace priv {
    bool SceneComparator::operator()(const std::unique_ptr<Scene>& a,
                               const std::unique_ptr<Scene>& b) const {
      assert(a && b);
      return a->id() < b->id();
    }
  } // namespace priv

  Engine::Engine(const char* title, unsigned w, unsigned h, int fps) :
    m_currentLevel{} {
    configure_raylib_log();
    ::InitWindow(w, h, title);
    if(fps > 0)
      ::SetTargetFPS(fps);
    ::InitAudioDevice();

    configure_raylib_log();
  }
  Engine::~Engine() {
    m_scenes.clear();
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
  // void Engine::changeToLevel(LevelID id) {
  //   for(auto& level : m_levels) {
  //     if(level->id() == id) {
  //       if(m_currentLevel) m_currentLevel->destroy();
  //       m_currentLevel = level.get();
  //       m_currentLevel->init();
  //       return;
  //     }
  //   }

  //   DEBUG_WARNING("Level %d don't found", id);
  // }
  void Engine::addScene(std::unique_ptr<Scene>&& scene) {
    auto x =  m_scenes.insert(std::move(scene));
    if(!m_currentLevel)
      m_currentLevel = x.first->get();
  }
  // ======================================================================

  // ================
  // MAIN FUNCTIONS
  // ================
  int Engine::run() {
    if(auto res = init(); res != 0) return res;

    while(!::WindowShouldClose()) {
      processInput();
      update(::GetFrameTime());
      render();
    }

    return 0;
  }

  int Engine::init() {
    auto res = onInit();
    if(res != 0) return res;

    for(auto&& scene : m_scenes)
      if((res = scene->onInit()) != 0) return res;

    return 0;
  }

  void Engine::processInput() {
    if(m_currentLevel) m_currentLevel->onProcessInput();
  }

  void Engine::update(float deltatime) {
    TimerManager::Tick(deltatime);
    if(m_currentLevel) m_currentLevel->onUpdate(deltatime);
  }

  void Engine::render() {
    ::BeginDrawing();
    if(m_currentLevel) m_currentLevel->onRender();
    ::EndDrawing();
  }
} // namespace engine
