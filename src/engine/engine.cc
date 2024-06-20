#include "engine/engine.h"

#include "engine/gameobject.h"

#include <SFML/Window/Event.hpp>

namespace engine {
  Engine::Engine(const char* title, unsigned w, unsigned h, bool vsync) :
    m_window{{w,h}, title, sf::Style::Close} {
    m_window.setVerticalSyncEnabled(vsync);
  }
  Engine::~Engine() {}
  
  void Engine::run() {
    for(sf::Clock clk; m_window.isOpen(); m_window.display()) {
      const auto deltatime = clk.restart().asSeconds();
    
      processInput();
      update(deltatime);
      render();
    }
  }

  void Engine::processInput() {
    for(sf::Event ev; m_window.pollEvent(ev);) {
      switch(ev.type) {
        using enum sf::Event::EventType;
        case Closed: m_window.close(); break;
      }
    }
  }

  void Engine::update(const float& deltatime) {
    for(auto& obj : m_objects)
      obj->update(deltatime);
  }

  void Engine::render() {
  }
} // namespace engine 