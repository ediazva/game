#pragma once
#include "engine/engine.h"
#include "engine/raylib.h"

// Se necesita una forma de enumerar cada componente con un ID
typedef enum {
  SPRITE,
  HITBOX,
  POSICION,
  VELOCIDADAI,
  INPUT,
  DISPARAR
} COMPONENTE;

struct Sprite {
};

struct Hitbox {
  raylib::Vector2 dims;
};

struct Posicion {
  raylib::Vector2 pos;
};

struct VelocidadAI {
  raylib::Vector2 vel;
};

struct Input {
};

struct Disparar {
};
