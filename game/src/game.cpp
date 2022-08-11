#include "game.h"

#include <bgfx/bgfx.h>

struct PosVertex {
  float x, y, z;
  uint32_t color;

  static void init() {
    layout.begin()
        .add(bgfx::Attrib::Position, 3, bgfx::AttribType::Float)
        .add(bgfx::Attrib::Color0, 4, bgfx::AttribType::Uint8, true)
        .end();
    ;
  }

  static bgfx::VertexLayout layout;
};

bgfx::VertexLayout PosVertex::layout;

static PosVertex cubeVertices[] = {{0.5f, 0.5f, 0.0f, 0xff0000ff},
                                   {0.5f, -0.5f, 0.0f, 0xff0000ff},
                                   {-0.5f, -0.5f, 0.0f, 0xff00ff00},
                                   {-0.5f, 0.5f, 0.0f, 0xff00ff00}};

static const uint16_t cubeIndices[] = {0, 1, 3, 1, 2, 3};

bgfx::VertexBufferHandle vbh;
bgfx::IndexBufferHandle ibh;

void Game::init() { init(800, 600, "Snow"); }

void Game::init(uint32_t width, uint32_t height, const std::string &title) {
  snow::Window::init();
  window = std::make_unique<snow::Window>(width, height, title);

  renderer = std::make_unique<snow::Renderer>();
  renderer->init(*window);

  PosVertex::init();
  vbh = bgfx::createVertexBuffer(
      bgfx::makeRef(cubeVertices, sizeof(cubeVertices)), PosVertex::layout);
  ibh =
      bgfx::createIndexBuffer(bgfx::makeRef(cubeIndices, sizeof(cubeIndices)));
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
