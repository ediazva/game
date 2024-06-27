#pragma once

#include <bitset>
#include <memory>
#include <vector>
#include "componentes/genericos.h"

class Entidad {
public:
  std::bitset<10> comp_bitset{};
  // std::vector<typename Tp>
  // std::shared_ptr<Sprite> sprite{};
  // std::shared_ptr<Posicion> posicion{};
  // std::shared_ptr<Hitbox> hitbox{};
  // std::shared_ptr<VelocidadAI> velocidadAI{};

  void add_componente(COMPONENTE comp) {
    comp_bitset.set(comp, true);
  }
};
