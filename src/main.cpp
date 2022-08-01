#include "engine.h"

int main(void) {
  std::unique_ptr<snow::Engine> e = std::make_unique<snow::Engine>();
  e->init(800, 600, "Snow");
  e->run();
  e->cleanup();
}
