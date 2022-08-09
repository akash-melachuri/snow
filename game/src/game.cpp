#include "game.h"

void Game::init() {
    init(800, 600, "Snow");
}

void Game::init(uint32_t width, uint32_t height, const std::string &title) {
    snow::Window::init();
  window = std::make_unique<snow::Window>(width, height, title);

  renderer = std::make_unique<snow::Renderer>();
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
  snow::Window::cleanup();
}
