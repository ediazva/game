#include "engine/engine.h"

#include "engine/debug.h"
#include "engine/raylib.h"
#include "engine/entity_manager.h"
#include "engine/system_manager.h"
#include "engine/assets/sound.h"
#include "engine/assets/texture.h"

namespace engine {
  Engine::Engine(const char* title, unsigned w, unsigned h, int fps) :
    m_entmgr{new EntityManager},
    m_sysmgr{new SystemManager} {
    raylib::InitWindow(w, h, title);
    if(fps > 0)
      raylib::SetTargetFPS(fps);
    raylib::InitAudioDevice();

    configure_raylib_log();
    m_sysmgr->setDepedencies(m_entmgr);
  }
  Engine::~Engine() {
    delete m_entmgr;
    delete m_sysmgr;
    raylib::CloseAudioDevice();
    raylib::CloseWindow();
  }

  // ======================================================================
  // ASSETS CREATION
  // ======================================================================
  assets::Sound Engine::makeSoundFromPath(const char* path) {
    assets::Sound snd;
    snd.copy_base(raylib::LoadSound(path));
    return snd;
  }

  assets::Texture Engine::makeTextureFromPath(const char* path) {
    assets::Texture tex;
    tex.copy_base(raylib::LoadTexture(path));
    return tex;
  }

  // assets::Tile Engine::makeTileFromPath(const char* path, Result* res) {
  // assets::Tile tile;
  // }

  // ======================================================================

  // ================
  // MAIN FUNCTIONS
  // ================
  SystemManager& Engine::systemManager() {
    return *m_sysmgr;
  }

  EntityManager& Engine::entityManager() {
    return *m_entmgr;
  }

  void Engine::run() {
    onInit();
    m_sysmgr->init();

    while(!raylib::WindowShouldClose()) {
      processInput();
      update(raylib::GetFrameTime());
      render();
    }
  }

  void Engine::processInput() {
    raylib::PollInputEvents();

    onProcessInput();
  }

  void Engine::update(const float& deltatime) {
    onUpdate(deltatime);

    m_sysmgr->update(deltatime);
  }

  void Engine::render() {
    raylib::BeginDrawing();
    onRender();
    m_sysmgr->render();

    raylib::EndDrawing();
  }
} // namespace engine
