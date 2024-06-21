#pragma once
#include <vector>
#include <memory>

namespace engine {
  class Engine {
  public:
    Engine(const char* title, unsigned w, unsigned h, int fps = -1);
    ~Engine();

    void run();
  protected:
    virtual void onProcessInput() {}
    virtual void onUpdate(const float& deltatime) {}
    virtual void onRender() {}
  private:
    void processInput();
    void update(const float& deltatime);
    void render();

    std::vector<std::unique_ptr<class GameObject>> m_objects;
  };
} // namespace engine