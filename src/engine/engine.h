#pragma once
#include "engine/result.h"

#include <vector>
#include <memory>

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
    assets::Sound makeSoundFromPath(const char* path, Result* res = nullptr);
    assets::Texture makeTextureFromPath(const char* path, Result* res = nullptr);
    // assets::Tile makeTileFromPath(const char* path, Result* res = nullptr);

    // ================
    // MAIN FUNCTIONS
    // ================
    Result run();
  protected:
    virtual Result onInit() { return kSucess_Result; }
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
