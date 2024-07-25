#include "engine/level.h"

namespace engine {
  Level::Level() :
    m_id{GetLevelId()} {
    m_sysMgr.setDepedencies(&m_entMgr);
  }

  Level::~Level() {
    destroy();
  }

  LevelID Level::GetLevelId() {
    static size_t s_nlevels = 0;
    return s_nlevels++;
  }

  void Level::init() {
    m_sysMgr.init();
    onInit();
  }

  void Level::update(float deltatime) {
    m_sysMgr.update(deltatime);
    onUpdate(deltatime);
  }

  void Level::processInput() {
    onProcessInput();
  }

  void Level::render() {
    m_sysMgr.render();
    onRender();
  }

  void Level::destroy() {
    m_entMgr.clearEntities();
    m_sysMgr.destroy();
  }

  LevelID Level::id() const {
    return m_id;
  }
} // namespace engine