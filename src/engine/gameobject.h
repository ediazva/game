#pragma once

namespace engine {
  class GameObject {
  public:
    ~GameObject() {}

    virtual void* update(const float& deltatime) = 0;
  };
} // namespace engine 