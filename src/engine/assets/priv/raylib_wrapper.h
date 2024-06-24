#pragma once

#define BEGIN_RAYLIB_WRAPPER(classname, type)         \
  struct classname : type {                           \
    classname() = default;                            \
    classname(classname&& o) {                        \
      copy_base(o);                                   \
      o.copy_base({});                                \
    }                                                 \
    classname(const classname&) = delete;             \
    ~classname();                                     \
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
  public:
#define END_RAYLIB_WRAPPER };