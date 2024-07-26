#pragma once
#include "engine/components/component.h"
#include "engine/assets/texture.h"
#include "engine/assets/texture_atlas.h"
#include <unordered_map>
#include <string>
#include <utility>

namespace engine {
  class AnimationFrame {
  public:
    float elapsedTime{};
    unsigned spriteIndex;
    AnimationFrame(unsigned spriteIndex) : spriteIndex(spriteIndex) {}
  };

  // El componente de animacion tiene estados
  // El cambio de visual se tiene que dar en SpriteComponent
  struct AnimationComponent : public Component {
    float animationSpeed{};
    unsigned currentFrame{};
    std::string currentState{};
    std::unordered_map<std::string, std::vector<AnimationFrame>> stateMap{};

    AnimationComponent(std::string currentState, unsigned spriteIndexStart, unsigned spriteIndexEnd, float animationSpeed = 0.03)
        : currentState{ currentState },
          animationSpeed{animationSpeed} {
      stateMap.insert(std::make_pair(currentState, std::vector<AnimationFrame>()));
      for(unsigned i{ spriteIndexStart }; i <= spriteIndexEnd; ++i) {
        stateMap[currentState].emplace_back(i);
      }
    }

    void addState(std::string state, unsigned spriteIndexStart, unsigned spriteIndexEnd) {
      stateMap.insert(std::make_pair(state, std::vector<AnimationFrame>()));
      for(unsigned i{ spriteIndexStart }; i <= spriteIndexEnd; ++i) {
        stateMap[state].emplace_back(i);
      }
    }

    void changeState(std::string newState) {
      currentState = newState;
    }
  };
} // namespace engine
