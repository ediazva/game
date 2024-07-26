#pragma once
#include <map>
#include <string>
#include <ranges>

namespace engine {
  struct Mouse {
    float x{};
    float y{};
  };

  struct EventCompare {
    bool operator()(const std::string& a, const std::string& b) const;
  };

  class MiceManager {
    std::map<std::string, Mouse, EventCompare> m_mice;
    
    struct Impl;
    Impl* m_impl;
    
    MiceManager();
  public:
    ~MiceManager();

    MiceManager(const MiceManager&) = delete;
    MiceManager(MiceManager&&) = delete;
    MiceManager& operator=(MiceManager&&) = delete;
    MiceManager& operator=(const MiceManager&) = delete;

    auto mice() const {
      return m_mice | std::views::values;
    }
  
    static MiceManager& GetInstance();
  };
} // namespace engine