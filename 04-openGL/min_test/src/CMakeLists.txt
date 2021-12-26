cmake_minimum_required(VERSION 3.18)
project(opengl-min CXX C)

find_package(SDL2 REQUIRED)
message(STATUS "SDL2_LIBRARIES[${SDL2_LIBRARIES}] "
    "SDL2_INCLUDE_DIRS[${SDL2_INCLUDE_DIRS}]")


add_library(glad SHARED
            KHR/khrplatform.h
            glad/glad.h
            glad/glad.c)
            
target_compile_features(glad PUBLIC cxx_std_17)

add_executable(game
                            engine.hxx
                            game.cxx)
target_link_libraries(game PRIVATE ${SDL2_LIBRARIES})
target_include_directories(game PRIVATE ${SDL2_INCLUDE_DIRS})
target_link_libraries(game PRIVATE SDL2::SDL2 SDL2::SDL2main)
target_link_libraries(game PRIVATE glad)
target_compile_features(game PUBLIC cxx_std_17)

