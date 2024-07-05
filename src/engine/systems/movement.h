#pragma once
#include "engine/components/position.h"
#include "engine/components/velocity.h"
#include "engine/systems/system.h"
#include <numbers>
#include <random>

namespace engine {
  class MovementSystem : public System {
    std::random_device dev;
    std::mt19937 eng;
    std::uniform_real_distribution<float> zero_2pi_dist;

    bool borderBounce(PositionComponent& position, VelocityComponent& velocity,
                      const float& deltatime);
    void randomBounce(PositionComponent& position, VelocityComponent& velocity,
                      const float& deltatime);
    MovementSystem() : eng(dev()), zero_2pi_dist(0, std::numbers::pi_v<float>){};


  public:
    virtual void update(const float& deltatime) override;
  };
} // namespace engine
