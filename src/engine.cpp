#include "engine.h"

void Engine::init() {
  Window::init();
  window = std::make_unique<Window>(800, 600, "Snow");
}

void Engine::init(uint32_t width, uint32_t height, const std::string &title) {
  Window::init();
  window = std::make_unique<Window>(width, height, title);
}

void Engine::run() {
  while (!window->should_close()) {
    window->poll_events();
  }
}

void Engine::cleanup() {
  window->destroy();
  Window::cleanup();
}
