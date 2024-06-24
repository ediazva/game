#pragma once

namespace engine {
  class Engine;
} // namespace engine

/// Se necesita que se defina un destructor
#define BEGIN_RAYLIB_WRAPPER(classname, type)         \
  struct classname : type {                           \
    classname() = default;                            \
    classname(classname&& o) {                        \
      copy_base(o);                                   \
      o.copy_base({});                                \
    }                                                 \
    classname(const classname&) = delete;             \
                                                      \
    classname& operator=(const classname&) = delete;  \
    classname& operator=(classname&& o) {             \
      copy_base(o);                                   \
      o.copy_base({});                                \
      return *this;                                   \
    }                                                 \
  private:                                            \
    void copy_base(const type& base) {                \
      type::operator=(base);                          \
    }                                                 \
    friend class engine::Engine;                              \
  public:
#define END_RAYLIB_WRAPPER };