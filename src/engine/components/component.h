#pragma once
#include "engine/debug.h"

#include <memory>
#include <bitset>
#include <array>

namespace engine {
  class Entity;
  
  class Component {
  public:
    typedef unsigned short ID;
    static constexpr const size_t nmax_components = sizeof(ID)*8/*bits*/; 
    typedef std::bitset<nmax_components> Bitset;
    typedef std::array<Component*, nmax_components> List;
    
    template<typename T> requires std::derived_from<T, Component>
    static ID GetTypeID() {
      static ID s_typeID = MakeID();
      return s_typeID;
    }

    // std::weak_ptr<Entity> entity;
    virtual ~Component() {
      DEBUG_TRACE("[Component] destructor!!");
    }
  private:
    static ID MakeID() {
      static ID s_lastID{};
      return ++s_lastID;
    }
  };

  typedef std::unique_ptr<Component> ComponentPtr;

  template<typename T>
  concept component_t = std::derived_from<T, Component>;
} // namespace engine