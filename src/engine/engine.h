#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <vector>
#include <memory>

namespace engine {
  class Engine {
  public:
    Engine(const char* title, unsigned w, unsigned h, bool vsync = true);
    ~Engine();

    void run();
  private:
    void processInput();
    void update(const float& deltatime);
    void render();

    sf::RenderWindow m_window;
    std::vector<std::unique_ptr<class GameObject>> m_objects;
  };
} // namespace engine