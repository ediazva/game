#include "engine/engine.h"

#include "engine/gameobject.h"

#include <raylib.h>

namespace engine {
  Engine::Engine(const char* title, unsigned w, unsigned h, int fps) {
    InitWindow(w, h, title);
    if(fps > 0)
      SetTargetFPS(fps);
  }
  Engine::~Engine() {
    CloseWindow();
  }
  
  void Engine::run() {
    while(!WindowShouldClose()) {
      processInput();
      update(GetFrameTime());
      render();
    }
  }

  void Engine::processInput() {
    PollInputEvents();

    onProcessInput();
  }

  void Engine::update(const float& deltatime) {
    onUpdate(deltatime);

    for(auto& obj : m_objects)
      obj->update(deltatime);
  }

  void Engine::render() {
    BeginDrawing();
    onRender();
    EndDrawing();
  }
} // namespace engine 