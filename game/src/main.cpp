#include "game.h"

int main(void) {
  std::unique_ptr<snow::Game> e = std::make_unique<snow::Game>();
  e->init(800, 600, "Snow");
  e->run();
  e->cleanup();
}
