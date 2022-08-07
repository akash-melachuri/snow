#pragma once

#include "engine/core.h"
#include "engine/renderer.h"
#include "engine/window.h"

namespace snow {
class Game {
public:
  void init();
  void init(uint32_t width, uint32_t height, const std::string &title);
  void run();
  void cleanup();

private:
  std::unique_ptr<Window> window;
  std::unique_ptr<Renderer> renderer;
};
} // namespace snow
