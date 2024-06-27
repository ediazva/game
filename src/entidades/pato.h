#pragma once
#include "componentes/genericos.h"

class Pato {
public:
  Posicion posicion;
  VelocidadAI velocidad;
  Sprite sprite;
  Hitbox hitbox;

  // Pato() {
  //   reset_posicion();
  // }
  //
  // void reset_posicion() {
  //   pos.x = raylib::GetRandomValue(300, 700);
  //   pos.y = raylib::GetRandomValue(300, 700);
  // }
  // void* update(const float& deltatime) override {
  //   pos.x += vel * deltatime;
  //   pos.y += vel * deltatime;
  //   return this;
  // }
};
