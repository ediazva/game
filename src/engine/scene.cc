#include "engine/scene.h"

namespace engine {
  Scene::Scene() :
    m_id{GetSceneId()} {
    m_sysMgr.setDepedencies(&m_entMgr);
  }

  Scene::~Scene() {
    destroy();
  }

  SceneID Scene::GetSceneId() {
    static size_t s_nScenes = 0;
    return s_nScenes++;
  }

  int Scene::init() {
    if(auto res = onInit(); res != 0) return res;
    m_sysMgr.init();
    return 0;
  }

  void Scene::update(float deltatime) {
    onUpdate(deltatime);
    m_sysMgr.update(deltatime);
  }

  void Scene::processInput() {
    onProcessInput();
  }

  void Scene::render() {
    onRender();
    m_sysMgr.render();
  }

  void Scene::destroy() {
    m_entMgr.clearEntities();
    m_sysMgr.destroy();
  }

  SceneID Scene::id() const {
    return m_id;
  }
} // namespace engine