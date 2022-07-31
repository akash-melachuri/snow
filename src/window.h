#pragma once

#if BX_PLATFORM_LINUX
#define GLFW_EXPOSE_NATIVE_X11
#elif BX_PLATFORM_WINDOWS
#define GLFW_EXPOSE_NATIVE_WIN32
#elif BX_PLATFORM_OSX
#define GLFW_EXPOSE_NATIVE_COCOA
#endif
#include <GLFW/glfw3.h>
#include <GLFW/glfw3native.h>

#include "core.h"

class Window {
public:
  Window(uint32_t width, uint32_t height, const std::string &title);

  uint32_t get_width() const;
  uint32_t get_height() const;

  void set_size(uint32_t width, uint32_t height);

  bool should_close() const;
  void poll_events() const;

  void destroy() const;

  static void init();
  static void cleanup();

private:
  GLFWwindow *raw_window;
};
