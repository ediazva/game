#pragma once
#include "engine/mouse.h"

#include <map>
#include <string>
#include <memory>
#include <ranges>

namespace engine {
  struct EventCompare {
    bool operator()(const std::string& a, const std::string& b) const;
  };

  class MiceManager {
  public:
    typedef std::map<std::string, Mouse, EventCompare> MouseList;
    class Type {
    public:
      virtual ~Type() {}
      virtual void update() = 0;
    protected:
      Type(MouseList& list) :
        listRef{list} {}
      MouseList& listRef;
    };

    ~MiceManager();

    MiceManager(const MiceManager&) = delete;
    MiceManager(MiceManager&&) = delete;
    MiceManager& operator=(MiceManager&&) = delete;
    MiceManager& operator=(const MiceManager&) = delete;

    void update();

    void enableMultipleMouse();
    void disableMultipleMouse();

    auto mice() {
      return m_mice | std::views::values;
    }
  
    static MiceManager& GetInstance();
  private:
    MiceManager();

    bool m_multiple;
    MouseList m_mice;
    std::unique_ptr<Type> m_type;
  };
} // namespace engine