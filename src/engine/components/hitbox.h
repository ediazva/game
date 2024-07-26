#pragma once
#include "engine/components/component.h"
#include "raylib.h"
#include <functional> 

namespace engine {
  struct HitboxComponent : public Component {
    float width;
    float height;  // tamaño del cuadrado 
    // TODO: Cambiar hitbox rectangular
    // TODO: Añadir OnCollision, OnCollisionEnter

    bool alive{ true }; // Si está muerto no es interactuable

    std::function<void()> onCollision;
    std::function<void()> onCollisionEnter;
    std::function<void()> onCollisionExit;

    HitboxComponent() = default;
    // Constructor para poner el tamaño
    HitboxComponent(float w, float h) : width(w), height(h) {}

    // Callbacks
    void setOnCollision(std::function<void()> callback) { onCollision = callback; }
    void setOnCollisionEnter(std::function<void()> callback) { onCollisionEnter = callback; }
    void setOnCollisionExit(std::function<void()> callback) { onCollisionExit = callback; }
  };
} // namespace engine
