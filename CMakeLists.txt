cmake_minimum_required(VERSION 3.7)
project(snow)

set(CMAKE_CXX_STANDARD 14)
set(SOURCE_FILES src/main.cpp src/window.cpp src/engine.cpp src/renderer.cpp src/app.cpp)

find_package(glfw3 3.3 REQUIRED)

add_subdirectory("thirdparty/bgfx.cmake")
add_executable(snow ${SOURCE_FILES})

target_link_libraries(snow bgfx glfw)
target_include_directories(snow PRIVATE
    thirdparty/bgfx.cmake/bgfx/include
    thirdparty/bgfx.cmake/bx/include
    thirdparty/bgfx.cmake/bimg/include
    )

