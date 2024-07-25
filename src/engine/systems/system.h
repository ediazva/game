#pragma once

namespace engine {
  class EntityManager;

  class System {
    EntityManager* m_entityMgr{};
  protected:
    const EntityManager& entityMgr() const { return *m_entityMgr; }
  public:
    void setDependency(EntityManager* entityMgr) {
      m_entityMgr = entityMgr;
    }

    virtual void init() {}
    virtual void update(float deltatime) {}
    virtual void render() {}
  };
} // namespace engine
