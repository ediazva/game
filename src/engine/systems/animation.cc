#include "engine/systems/animation.h"
#include "engine/entity_manager.h"
#include "engine/components/sprite.h"
#include "engine/components/animation.h"

namespace engine {
  void AnimationSystem::update(float deltatime) {
    using namespace raylib;
    auto entities = entityMgr().getEntities<SpriteComponent, AnimationComponent>();

    for(auto& e : entities) {
      auto& anim = e->getComponent<AnimationComponent>();
      auto& sprite = e->getComponent<SpriteComponent>();

      if(anim.currentFrame >= anim.frames.size()) {
        anim.currentFrame = 0;
      }

      auto frame = anim.frames[anim.currentFrame];
      frame.elapsedTime += deltatime;
      sprite.atlIdx = frame.spriteIndex;

      if(frame.elapsedTime >= anim.animationSpeed) {
        anim.currentFrame++;
        frame.elapsedTime = 0;
      }
    }
  }
} // namespace engine
