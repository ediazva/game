#pragma once
#include "engine/entity.h"

#include <ranges>

namespace engine {
  class EntityManager {
    std::vector<EntityPtr> m_pool{};
  public:
    EntityPtr& addEntity() {
      // return m_pool.emplace_back();
      return m_pool.emplace_back(std::make_shared<Entity>());
    }

    template <component_t... T>
    auto getEntities(this auto&& self) {
      return self.m_pool | std::views::filter([](auto& x) {return x->template hasComponent<T...>();});
    }

    const std::vector<EntityPtr>& getEntities() const {
      return m_pool;
    }

    void clearEntities() {
      m_pool.clear();
    }
  };
} // namespace engine
