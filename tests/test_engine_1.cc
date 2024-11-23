#include "engine/engine.h"

class App : public engine::Engine {
public:
  using engine::Engine::Engine;
};

int main() {
  App app("1", 400, 400, 60);
  app.run();
  return 0;
}