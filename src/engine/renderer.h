#pragma once

#include "window.h"

namespace snow {
class Renderer {
public:
  void init(Window& window);
  void render();
  void cleanup();
};
} // namespace snow
