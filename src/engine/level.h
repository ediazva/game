#pragma once
#include "engine/entity_manager.h"
#include "engine/system_manager.h"

namespace engine {
  typedef unsigned char LevelID;

  class Level {
    static LevelID GetLevelId(); 

    EntityManager m_entMgr;
    SystemManager m_sysMgr;
    LevelID m_id;
  protected:
    virtual void onInit() {}
    virtual void onUpdate(float deltatime) {}
    virtual void onProcessInput() {}
    virtual void onRender() {}
  public:
    Level();
    virtual ~Level();
    void init();
    void destroy();
    void processInput();
    void update(float deltatime);
    void render();
#ifdef __cpp_explicit_this_parameter
    auto&& entityManager(this auto&& self) {return self.m_entMgr;}
    auto&& systemManager(this auto&& self) {return self.m_sysMgr;}
#else
    const auto& entityManager() const {return m_entMgr;}
    auto& entityManager() {return m_entMgr;}
    const auto& systemManager() const {return m_sysMgr;}
    auto& systemManager() {return m_sysMgr;}
#endif
    LevelID id() const;
  };

  template<typename T>
  concept level_t = std::derived_from<T, Level>;
} // namespace engine