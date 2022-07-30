#include "window.h"
#include <GLFW/glfw3.h>

window::window(uint32_t width, uint32_t height, const std::string &title) {
  raw_window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
}

uint32_t window::get_width() const {
  int width;
  glfwGetWindowSize(raw_window, &width, nullptr);
  return width;
}

uint32_t window::get_height() const {
  int height;
  glfwGetWindowSize(raw_window, nullptr, &height);
  return height;
}

bool window::should_close() const {
    return glfwWindowShouldClose(raw_window);
}

void window::poll_events() const {
    glfwPollEvents();
}

window::~window() {
  glfwDestroyWindow(raw_window);
  glfwTerminate();
}
