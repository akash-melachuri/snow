#pragma once

#include <GLFW/glfw3.h>

#include "core.h"

namespace snow {
class Window {
public:
  Window(uint32_t width, uint32_t height, const std::string &title);

  uint32_t get_width() const;
  uint32_t get_height() const;
  GLFWwindow* get_raw_window() const;

  void set_size(uint32_t width, uint32_t height);

  bool should_close() const;
  void poll_events() const;

  void destroy() const;

  static void init();
  static void cleanup();

private:
  GLFWwindow *raw_window;
};
} // namespace snow
