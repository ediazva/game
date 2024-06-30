#pragma once
#include "engine/entity.h"

namespace engine {
  class EntityManager {
    std::vector<EntityPtr> m_pool;
  public:
    EntityPtr& addEntity() {
      return m_pool.emplace_back(std::make_shared<Entity>());
    }

    template<component_t... T>
    std::vector<EntityPtr> getEntities() const {
      std::vector<EntityPtr> res;
      for(auto& e : m_pool)
        if(e->hasComponent<T...>())
          res.push_back(e);
      
      return res;
    }

    const std::vector<EntityPtr>& getEntities() const {
      return m_pool;
    }
  };
} // namespace engine