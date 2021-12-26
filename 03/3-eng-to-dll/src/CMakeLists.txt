cmake_minimum_required(VERSION 3.18)
project(loop-dll)
#---------library
add_library(eng SHARED ${CMAKE_CURRENT_SOURCE_DIR}/engine.cxx ${CMAKE_CURRENT_SOURCE_DIR}/engine.hxx)
target_compile_features(eng PUBLIC cxx_std_17)
find_package(SDL2 REQUIRED)
target_link_libraries(eng PRIVATE SDL2::SDL2 SDL2::SDL2main)
#---------main
add_executable(loop main.cxx)
target_compile_features(loop PUBLIC cxx_std_17)
#target_include_directories(loop )
target_link_libraries(loop PUBLIC eng)



