#include "engine.h"

namespace snow {
void Engine::init() {
    init(800, 600, "Snow");
}

void Engine::init(uint32_t width, uint32_t height, const std::string &title) {
  Window::init();
  window = std::make_unique<Window>(width, height, title);

  renderer = std::make_unique<Renderer>();
  renderer->init(*window);
}

void Engine::run() {
  while (!window->should_close()) {
    window->poll_events();
    renderer->render();
  }
}

void Engine::cleanup() {
  renderer->cleanup();

  window->destroy();
  Window::cleanup();
}
}; // namespace snow
