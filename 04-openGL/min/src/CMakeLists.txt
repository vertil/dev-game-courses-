cmake_minimum_required(VERSION 3.18)
project(opengl-min CXX C)

add_library(engine SHARED
    #engine.cxx
    engine.hxx
    KHR/khrplatform.h
    glad/glad.h
    glad/glad.c)
target_compile_features(engine PUBLIC cxx_std_17)
target_include_directories(engine PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

find_package(SDL2 REQUIRED)
target_link_libraries(engine PRIVATE SDL2::SDL2 SDL2::SDL2main)


add_executable(game game.cxx)
target_compile_features(game PUBLIC cxx_std_17)
target_link_libraries(game PRIVATE engine-04-1)



