#pragma once
#include <memory>
#include <set>

namespace engine {
  class Scene;
  
  namespace priv {
    struct SceneComparator {
      bool operator()(const std::unique_ptr<Scene>& a,
                      const std::unique_ptr<Scene>& b) const;
    };
  } // namespace priv

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
    int run();
  protected:
    virtual int onInit() {return 0;}


    void addScene(std::unique_ptr<Scene>&& scene);
  private:
    int init();
    void processInput();
    void update(float deltatime);
    void render();

    std::set<std::unique_ptr<Scene>, priv::SceneComparator> m_scenes;
    Scene* m_currentLevel;
  };
} // namespace engine
