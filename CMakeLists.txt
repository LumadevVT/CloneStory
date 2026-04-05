cmake_minimum_required(VERSION 3.22)
set(CMAKE_CXX_STANDARD 20)

project(CloneStory)

add_subdirectory(vendor/SDL3 EXCLUDE_FROM_ALL)
add_subdirectory(vendor/SDL3_image EXCLUDE_FROM_ALL)

add_executable(
        CloneStory WIN32
        src/main.cpp
        src/globals.h
        src/input/input.h
        src/input/input.cpp
        src/math/shapes.h
        src/graphics/animated_sprite.cpp
        src/graphics/animated_sprite.h
        src/time/timing.cpp
        src/time/timing.h
        src/assets/asset_manager.cpp
        src/assets/asset_manager.h
        src/assets/asset.h
        src/assets/missing_image.c
        src/math/shapes.cpp
        src/math/vector2d.cpp
        src/math/vector2d.h
        src/game/player.cpp
        src/game/player.h
)

if (${CMAKE_BUILD_TYPE} STREQUAL "Debug")
    target_compile_definitions(CloneStory PRIVATE GAME_DEBUG=1)
else ()
    target_compile_definitions(CloneStory PRIVATE GAME_DEBUG=0)
endif ()

target_compile_features(CloneStory PRIVATE cxx_std_20)
target_include_directories(CloneStory PRIVATE src)
target_link_libraries(
        CloneStory
        PRIVATE
        SDL3::SDL3
        SDL3_image::SDL3_image
)