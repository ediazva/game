#include "engine/engine.h"

#include "engine/gameobject.h"
#include "engine/raylib.h"
#include "engine/assets/sound.h"
#include "engine/assets/texture.h"

namespace engine {
  Engine::Engine(const char* title, unsigned w, unsigned h, int fps) {
    raylib::InitWindow(w, h, title);
    if(fps > 0)
      raylib::SetTargetFPS(fps);
    raylib::InitAudioDevice();
  }
  Engine::~Engine() {
    raylib::CloseAudioDevice();
    raylib::CloseWindow();
  }

  // ======================================================================
  // ASSETS CREATION
  // ======================================================================
  assets::Sound Engine::makeSoundFromPath(const char* path, Result* res) {
    assets::Sound snd;
    snd.copy_base(raylib::LoadSound(path));
    if(res)
      *res = snd.stream.buffer ? kSucess_Result : kFileNotFound_Result;
    return snd;
  }

  assets::Texture Engine::makeTextureFromPath(const char* path, Result* res) {
    assets::Texture tex;
    tex.copy_base(raylib::LoadTexture(path));
    if(res)
      *res = tex.id ? kSucess_Result : kFileNotFound_Result;
    return tex;
  }

  // ======================================================================

  // ================
  // MAIN FUNCTIONS
  // ================
  Result Engine::run() {
    if(Result res = onInit(); res != kSucess_Result)
      return res;
    
    while(!raylib::WindowShouldClose()) {
      processInput();
      update(raylib::GetFrameTime());
      render();
    }

    return kSucess_Result;
  }

  void Engine::processInput() {
    raylib::PollInputEvents();

    onProcessInput();
  }

  void Engine::update(const float& deltatime) {
    onUpdate(deltatime);

    for(auto& obj : m_objects)
      obj->update(deltatime);
  }

  void Engine::render() {
    raylib::BeginDrawing();
    onRender();
    raylib::EndDrawing();
  }
} // namespace engine 