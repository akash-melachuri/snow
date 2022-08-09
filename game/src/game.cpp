#include "game.h"

namespace snow {
void Game::init() {
    init(800, 600, "Snow");
}

void Game::init(uint32_t width, uint32_t height, const std::string &title) {
  Window::init();
  window = std::make_unique<Window>(width, height, title);

  renderer = std::make_unique<Renderer>();
  renderer->init(*window);
}

void Game::run() {
  while (!window->should_close()) {
    window->poll_events();
    
    renderer->render();
  }
}

void Game::cleanup() {
  renderer->cleanup();

  window->destroy();
  Window::cleanup();
}
}; // namespace snow
