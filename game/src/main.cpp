#include "game.h"

int main(void) {
  std::unique_ptr<Game> e = std::make_unique<Game>();
  e->init(800, 600, "Snow");
  e->run();
  e->cleanup();
}
