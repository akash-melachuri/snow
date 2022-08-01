#include "renderer.h"

#include <bgfx/bgfx.h>
#include <bgfx/platform.h>

#if BX_PLATFORM_LINUX
#define GLFW_EXPOSE_NATIVE_X11
#elif BX_PLATFORM_WINDOWS
#define GLFW_EXPOSE_NATIVE_WIN32
#elif BX_PLATFORM_OSX
#define GLFW_EXPOSE_NATIVE_COCOA
#endif
#include <GLFW/glfw3.h>
#include <GLFW/glfw3native.h>

namespace snow {
void Renderer::init(Window &window) {
  std::cout << "Initializing renderer" << std::endl;

  bgfx::Init init;
  init.type = bgfx::RendererType::Count;
#if BX_PLATFORM_LINUX || BX_PLATFORM_BSD
  init.platformData.ndt = glfwGetX11Display();
  init.platformData.nwh =
      (void *)(uintptr_t)glfwGetX11Window(window.get_raw_window());
#elif BX_PLATFORM_OSX
  init.platformData.nwh = glfwGetCocoaWindow(window.get_raw_window());
#elif BX_PLATFORM_WINDOWS
  init.platformData.nwh = glfwGetWin32Window(window.get_raw_window());
#endif
  init.resolution.width = window.get_width();
  init.resolution.height = window.get_height();
  init.resolution.reset = BGFX_RESET_VSYNC;
  if (!bgfx::init(init))
    std::cout << "Failed to initialize bgfx" << std::endl;

  // Set clear color
  bgfx::setViewClear(0, BGFX_CLEAR_COLOR | BGFX_CLEAR_DEPTH, 0x443355FF, 1.0f,
                     0);
  bgfx::setViewRect(0, 0, 0, window.get_width(), window.get_height());
}

void Renderer::render() {
  bgfx::touch(0);
  bgfx::frame();
}

void Renderer::cleanup() {
  std::cout << "Shutting down renderer" << std::endl;
  bgfx::shutdown();
}
} // namespace snow
