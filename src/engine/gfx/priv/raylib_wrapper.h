#pragma once

#define BEGIN_RAYLIB_WRAPPER(classname, type)         \
  struct classname {                                  \
    type base;                                        \
                                                      \
    classname() = default;                            \
    classname(classname&& o) {                        \
      base = o.base;                                  \
      o.base = {};                                    \
    }                                                 \
    classname(const classname&) = delete;             \
    ~classname();                                     \
                                                      \
    classname& operator=(const classname&) = delete;  \
    classname& operator=(classname&& o) {             \
      base = o.base;                                  \
      o.base = {};                                    \
                                                      \
      return *this;                                   \
    }
#define END_RAYLIB_WRAPPER };