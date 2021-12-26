cmake_minimum_required(VERSION 3.18)
project(loop)

add_executable(loop main.cxx)
target_compile_features(loop PUBLIC cxx_std_17)
find_package(SDL2 REQUIRED)
target_link_libraries(loop PRIVATE SDL2::SDL2 SDL2::SDL2main)
