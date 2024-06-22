#include "engine/engine.h"

#include "engine/gameobject.h"
#include "engine/raylib.h"

namespace engine {
  Engine::Engine(const char* title, unsigned w, unsigned h, int fps) {
    raylib::InitWindow(w, h, title);
    if(fps > 0)
      raylib::SetTargetFPS(fps);
  }
  Engine::~Engine() {
    raylib::CloseWindow();
  }
  
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