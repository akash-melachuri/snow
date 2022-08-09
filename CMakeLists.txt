cmake_minimum_required(VERSION 3.7)
project(snow)

set(CMAKE_CXX_STANDARD 14)
set(SOURCE_FILES game/src/main.cpp game/src/game.cpp)
set(ENGINE_SOURCE engine/src/window.cpp engine/src/renderer.cpp)

find_package(glfw3 3.3 REQUIRED)

add_subdirectory("thirdparty/bgfx.cmake")
add_library(snow STATIC ${ENGINE_SOURCE})

target_link_libraries(snow bgfx glfw)
target_include_directories(snow PRIVATE
    thirdparty/bgfx.cmake/bgfx/include
    thirdparty/bgfx.cmake/bx/include
    thirdparty/bgfx.cmake/bimg/include
    )

add_executable(game ${SOURCE_FILES})
target_link_libraries(game snow)
target_include_directories(game PRIVATE
    engine/include
    )
