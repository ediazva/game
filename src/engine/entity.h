#pragma once
#include "engine/components/component.h"
#include "engine/debug.h"
#include <functional>
#include <memory>
#include <vector>
#include <cassert>

namespace engine {
  class Entity {
    Component::List m_componentRefList{};
    Component::Bitset m_componentFlags{};
    std::vector<ComponentPtr> m_components{};
  public:
    std::function<void()> onClick = []() {};

    template <component_t T, typename... Args> requires std::constructible_from<T, Args...>
    T& addComponent(Args&&... args) {
      if(hasComponent<T>()) {
        DEBUG_WARNING("[Entity] double call addComponent with T=%s. Returning existing one", typeid(T).name());
        return getComponent<T>();
      }

      DEBUG_TRACE("[Entity] created T=%s", typeid(T).name());
      auto ptr = new T(std::forward<Args>(args)...);
      m_componentRefList[Component::GetTypeID<T>()] = ptr;
      m_componentFlags[Component::GetTypeID<T>()] = true;
      m_components.emplace_back(ptr);
      return *ptr;
    }

    template <component_t... T>
    bool hasComponent() const {
      return (m_componentFlags[Component::GetTypeID<T>()] && ...);
    }

    template <component_t T>
    T* tryGetComponent() {
      return dynamic_cast<T*>(m_componentRefList[Component::GetTypeID<T>()]);
    }

    template <component_t T>
    T& getComponent() {
      auto ptr = tryGetComponent<T>();
      assert(ptr);
      return *ptr;
    }
  };

  typedef std::shared_ptr<Entity> EntityPtr;
} // namespace engine
