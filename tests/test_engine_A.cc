#include "engine/engine.h"

#include "componentes/genericos.h"
#include "manager/entmanager.h"

#include <bitset>
#include <iostream>

using namespace engine;

class GameEngine : public Engine {
public:
  using Engine::Engine;

  Result onInit() override {
    return kSucess_Result;
  }

  void onUpdate(const float& deltatime) override {

  }

  void onRender() override {
    using namespace raylib;
    ClearBackground(BLANK);
  }
};

int main() {
  // configure_raylib_log();
  // GameEngine eng("Django: Sin palomas", 1000, 1000);
  //
  // return eng.run();
  EntityManager manager;
  manager.add_entidad();
  manager.add_entidad();
  manager.add_entidad();
  manager.add_entidad();

  manager.piscina[0]->add_componente(SPRITE);
  manager.piscina[0]->add_componente(POSICION);

  manager.piscina[2]->add_componente(SPRITE);
  manager.piscina[2]->add_componente(POSICION);

  std::bitset<10> cmp;
  cmp.set(SPRITE, true);
  cmp.set(POSICION, true);
  /*
  typedef enum {
    0001
    0010
    0100
    1000

    SPRITE = 1 << 0,
    HITBOX = 1 << 1,
    POSICION = 1 << 2,
    VELOCIDADAI = 1 << 3,
    INPUT = 1 << 4,
    DISPARAR = 1 << 5,
  } COMPONENTE = 1 << 6;
  if(cmp & SPRITE) 
  auto get_entidades(unsigned flags);
  get_entidades(SPRITE | HITBOX);
  */
  auto conj = manager.get_entidades(cmp);
  for(auto& e : conj) {
    std::cout << e->comp_bitset << std::endl;
  }
}
