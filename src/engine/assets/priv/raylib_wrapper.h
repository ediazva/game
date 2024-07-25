#pragma once
#include "engine/debug.h"

template<typename T, void (*FnDeleter)(T), bool (*FnValid)(T)>
struct raylib_wrapper : T {
  raylib_wrapper() = default;
  raylib_wrapper(raylib_wrapper&& o) {
    copy_base(o);
    o.copy_base({});
  }
  raylib_wrapper(const raylib_wrapper&) = delete;
  ~raylib_wrapper() {
    if(isValid())
      FnDeleter(*this);
  }

  bool isValid() const {
    return FnValid(*this);
  }

  raylib_wrapper& operator=(const raylib_wrapper&) = delete;
  raylib_wrapper& operator=(raylib_wrapper&& o) {
    copy_base(o);
    o.copy_base({});
    return *this;
  } 
protected:
  void copy_base(const T& base) {
    T::operator=(base);
  }
};