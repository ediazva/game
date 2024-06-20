#pragma once

#ifndef GAME_DEBUG
#  define DEBUG(...)
#else
#include <print>
#include <iostream>

namespace base::priv {
  inline std::ostream& out = std::cerr;

  template<typename... Args>
  inline void debug(std::format_string<Args...> fmt, Args&&... args) {
    std::println(out, fmt, std::forward<Args>(args)...);
  }
} // namespace base::priv

#  define DEBUG(...) base::priv::debug(__VA_ARGS__)

#endif