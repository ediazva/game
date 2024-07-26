#pragma once
#include "engine/level.h"

#include <memory>
#include <vector>

namespace engine {
  class Level;

  namespace assets {
    struct Sound;
    struct Texture;
    struct Tile;
  } // namespace assets

  class Engine {
  public:
    Engine(const char* title, unsigned w, unsigned h, int fps = -1);
    ~Engine();

    // ================
    // MAIN FUNCTIONS
    // ================
    void run();
  protected:
    // SystemManager& systemManager();
    // EntityManager& entityManager(int index = 0);
    virtual void onInit() {}
    virtual void onProcessInput() {}
    virtual void onUpdate(float deltatime) {}
    virtual void onRender() {}

    template <level_t T, typename... Args>
    T* addLevel(Args&&... args) {
      T* level = new T(std::forward<Args>(args)...);
      m_levels.emplace_back(level);
      if(!m_currentLevel)
        changeToLevel(level->id());
      return level;
    }

    void changeToLevel(LevelID id);

    Level* currentLevel() { return m_currentLevel; }
  private:
    void processInput();
    void update(float deltatime);
    void render();

    Level* m_currentLevel;
    // TODO: Podemos usar una tabla hash pero al final solo son 3 niveles
    std::vector<std::unique_ptr<Level>> m_levels;
  };
} // namespace engine
