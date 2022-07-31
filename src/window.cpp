#include "window.h"
#include <GLFW/glfw3.h>

void Window::init() { glfwInit(); }
void Window::cleanup() { glfwTerminate(); }

Window::Window(uint32_t width, uint32_t height, const std::string &title) {
  raw_window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
}

uint32_t Window::get_width() const {
  int width;
  glfwGetWindowSize(raw_window, &width, nullptr);
  return width;
}

uint32_t Window::get_height() const {
  int height;
  glfwGetWindowSize(raw_window, nullptr, &height);
  return height;
}

void Window::set_size(uint32_t width, uint32_t height) {
  glfwSetWindowSize(raw_window, width, height);
}

bool Window::should_close() const { return glfwWindowShouldClose(raw_window); }

void Window::poll_events() const { glfwPollEvents(); }

void Window::destroy() const { glfwDestroyWindow(raw_window); }
