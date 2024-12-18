#pragma once
#include "engine/entity_manager.h"
#include "engine/system_manager.h"

namespace engine {
  typedef unsigned short SceneID;

  class Scene {
    static SceneID GetSceneId(); 

    EntityManager m_entMgr;
    SystemManager m_sysMgr;
    SceneID m_id;
  public:
    Scene();
    virtual ~Scene();
    void destroy();

    virtual int onInit();
    virtual void onUpdate(float deltatime);
    virtual void onProcessInput();
    virtual void onRender();
    
    auto&& entityManager(this auto&& self) {return self.m_entMgr;}
    auto&& systemManager(this auto&& self) {return self.m_sysMgr;}
    SceneID id() const;
  };

  template<typename T>
  concept scene_t = std::derived_from<T, Scene>;
} // namespace engine