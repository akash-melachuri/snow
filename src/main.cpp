#include "bgfx/platform.h"
#include <bgfx/bgfx.h>
#include <GLFW/glfw3.h>

#if BX_PLATFORM_LINUX
#define GLFW_EXPOSE_NATIVE_X11
#elif BX_PLATFORM_WINDOWS
#define GLFW_EXPOSE_NATIVE_WIN32
#elif BX_PLATFORM_OSX
#define GLFW_EXPOSE_NATIVE_COCOA
#endif
#include <GLFW/glfw3native.h>

#define WIDTH 800
#define HEIGHT 600

int main (void) {
    glfwInit();

    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Snow", nullptr, nullptr);

    bgfx::Init init;
#if BX_PLATFORM_LINUX || BX_PLATFORM_BSD
	init.platformData.ndt = glfwGetX11Display();
	init.platformData.nwh = (void*)(uintptr_t)glfwGetX11Window(window);
#elif BX_PLATFORM_OSX
	init.platformData.nwh = glfwGetCocoaWindow(window);
#elif BX_PLATFORM_WINDOWS
	init.platformData.nwh = glfwGetWin32Window(window);
#endif
    init.type = bgfx::RendererType::Count;
    int width, height;
    glfwGetWindowSize(window, &width, &height);
    init.resolution.width = width;
    init.resolution.height = height;
    init.resolution.reset = BGFX_RESET_VSYNC;
    bgfx::init(init);

    bgfx::setViewClear(0, BGFX_CLEAR_COLOR | BGFX_CLEAR_DEPTH, 0x443355FF, 1.0f, 0);
    bgfx::setViewRect(0, 0, 0, bgfx::BackbufferRatio::Equal);

    unsigned int counter = 0;
    while(!glfwWindowShouldClose(window)) {   
        glfwPollEvents();

        bgfx::touch(0);
        bgfx::frame();

        counter++;
    }

    bgfx::shutdown();
    glfwTerminate();

    return 0;
}
