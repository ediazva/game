#pragma once
#include "componentes/genericos.h"
#include "manager/entmanager.h"

void sis_movimiento(EntityManager& manager) {
  std::bitset<10> cmp;
  cmp[POSICION] = true;
  cmp[VELOCIDADAI] = true;
  auto entidades = manager.get_entidades(cmp);
  for(auto& e : entidades) {
    // e.
  }
}
