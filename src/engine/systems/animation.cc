#include "engine/systems/animation.h"
#include "engine/entity_manager.h"
#include "engine/components/sprite.h"
#include "engine/components/animation.h"
#include <string>

namespace engine {
  void AnimationSystem::update(float deltatime) {
    
    auto entities = entityMgr().getEntities<SpriteComponent, AnimationComponent>();

    for(auto& e : entities) {
      auto& anim = e->getComponent<AnimationComponent>();
      auto& sprite = e->getComponent<SpriteComponent>();

      auto& frameIndex = anim.currentFrame;
      auto& frames = anim.stateMap.at(anim.currentState);

      if(frameIndex >= frames.size()) {
        anim.currentFrame = 0;
      }

      auto& frame = frames[frameIndex];

      frame.elapsedTime += deltatime;
      sprite.stateMap.at(sprite.currentState).second = frame.spriteIndex;

      if(frame.elapsedTime >= anim.animationSpeed) {
        frameIndex++;
        frame.elapsedTime = 0;
      }
    }
  }
} // namespace engine
