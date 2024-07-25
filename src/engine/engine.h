#pragma once

#include <array>
#include <memory>
#include <vector>

namespace engine {
  class SystemManager;
  class EntityManager;

  namespace assets {
    struct Sound;
    struct Texture;
    struct Tile;
  } // namespace assets

  class Engine {
  public:
    Engine(const char* title, unsigned w, unsigned h, int fps = -1, int nEntMgr = 1);
    ~Engine();

    // ================
    // ASSETS CREATION
    // ================
    assets::Sound makeSoundFromPath(const char* path);
    assets::Texture makeTextureFromPath(const char* path);
    // assets::Tile makeTileFromPath(const char* path, Result* res = nullptr);

    // ================
    // MAIN FUNCTIONS
    // ================
    void run();
  protected:
    SystemManager& systemManager();
    EntityManager& entityManager(int index = 0);
    virtual void onInit() {}
    virtual void onProcessInput() {}
    virtual void onUpdate(float deltatime) {}
    virtual void onRender() {}
  private:
    void processInput();
    void update(float deltatime);
    void render();

    // SystemManager* m_sysmgr;
    // EntityManager* m_entmgr;
    std::unique_ptr<SystemManager> m_sysmgr;
    std::vector<std::unique_ptr<EntityManager>> m_entmgrs;
  };
} // namespace engine
