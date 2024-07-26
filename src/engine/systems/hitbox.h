#pragma once
#include <cmath>
#include <functional>
#include <unordered_map>
#include "engine/entity.h"
#include "engine/systems/system.h"

namespace engine {

class HitboxSystem : public System {
public:
    std::unordered_map<Entity*, bool> collisionStates;
    
    using CollisionCallback = std::function<void(Entity&, Entity&)>;

    void update(float deltatime) override;

    void setOnCollisionEnterCallback(CollisionCallback callback);
    void setOnCollisionStayCallback(CollisionCallback callback);
    void setOnCollisionExitCallback(CollisionCallback callback);
    void resetEntity(std::shared_ptr<Entity>& ent, float deltatime);

private:
    void handleCollisionEnter(Entity& entity1, Entity& entity2);
    void handleCollisionStay(Entity& entity1, Entity& entity2);
    void handleCollisionExit(Entity& entity1, Entity& entity2);

    CollisionCallback onCollisionEnterCallback;
    CollisionCallback onCollisionStayCallback;
    CollisionCallback onCollisionExitCallback;

    
};

} // namespace engine
