#pragma once
#include "engine/entity_manager.h"
#include "engine/system_manager.h"

namespace engine {
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
    SystemManager& systemManager() {return m_sysmgr;}
    EntityManager& entityManager() {return m_entmgr;}
    virtual void onInit() {}
    virtual void onProcessInput() {}
    virtual void onUpdate(const float& deltatime) {}
    virtual void onRender() {}
  private:
    void processInput();
    void update(const float& deltatime);
    void render();

    EntityManager m_entmgr;
    SystemManager m_sysmgr;
  };
} // namespace engine
