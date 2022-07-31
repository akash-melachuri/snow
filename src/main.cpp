#include "engine.h"

int main(void) {
  std::unique_ptr<Engine> e = std::make_unique<Engine>();
  e->init(800, 600, "Snow");
  e->run();
  e->cleanup();
}
