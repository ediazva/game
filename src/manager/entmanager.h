#pragma once
#include "entidades/entidad.h"
#include <bitset>
#include <memory>
#include <vector>

class EntityManager {
public:
  std::vector<std::shared_ptr<Entidad>> piscina;

  void add_entidad() {
    piscina.emplace_back(std::make_shared<Entidad>());
  }

  std::vector<std::shared_ptr<Entidad>> get_entidades(std::bitset<10> comp_bitset) {
    std::vector<std::shared_ptr<Entidad>> res;
    for(auto& e : piscina) {
      if((e->comp_bitset & comp_bitset) == comp_bitset)
        // if(e.)
        res.push_back(e);
    }
    return res;
  }
};
