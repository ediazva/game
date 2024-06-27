#include "engine/engine.h"

#include "engine/assets/tile.h"
#include "engine/debug.h"
#include "engine/gameobject.h"
// #include "raylib.h"
#include "componentes/genericos.h"
#include "manager/entmanager.h"

#include <bitset>
#include <iostream>

using namespace engine;

class GameEngine : public Engine {
  assets::Tile tile;

public:
  using Engine::Engine;

  Result onInit() override {
    tile.tex = makeTextureFromPath("data/img/sheet.png");
    tile.info.size = { 16.f, 16.f };
    tile.map = {
      { 19, 1, 2 },
      { 19, 1, 2 },
      { 19, 1, 2 },
      { 19, 1, 2 },
      { 19, 1, 2 },
    };
    
    return kSucess_Result;
  }

  void onUpdate(const float& deltatime) override {}

  void onRender() override {
    using namespace raylib;
    ClearBackground(BLANK);
    DrawTile(tile, { 100.f, 10.f });
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
  auto conj = manager.get_entidades(cmp);
  for(auto& e : conj) {
    std::cout << e->comp_bitset << std::endl;
  }
}
