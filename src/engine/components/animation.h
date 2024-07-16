#pragma once
#include "engine/components/component.h"
#include "engine/assets/texture.h"
#include "engine/assets/texture_atlas.h"

namespace engine {
  class AnimationFrame {
  public:
    float elapsedTime{};
    unsigned spriteIndex;
    AnimationFrame(unsigned spriteIndex) : spriteIndex(spriteIndex) {}
  };

  struct AnimationComponent : public Component {
    float animationSpeed;
    unsigned currentFrame;

    // TODO: Estados distintos(volando, muerte, etc)
    std::vector<AnimationFrame> frames;
    AnimationComponent(unsigned spriteIndexStart, unsigned spriteIndexEnd) {
      for(unsigned i{ spriteIndexStart }; i <= spriteIndexEnd; ++i) {
        frames.emplace_back(i);
      }
    }
  };
} // namespace engine
