#pragma once

#include <snow.h>

class Game {
public:
  void init();
  void init(uint32_t width, uint32_t height, const std::string &title);
  void run();
  void cleanup();

private:
  std::unique_ptr<snow::Window> window;
  std::unique_ptr<snow::Renderer> renderer;
};
