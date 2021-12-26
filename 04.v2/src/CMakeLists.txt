cmake_minimum_required(VERSION 3.1)
project(GFX CXX)

#---5-GFX
find_package(SDL2 REQUIRED)
message(STATUS "SDL2_LIBRARIES[${SDL2_LIBRARIES}] "
    "SDL2_INCLUDE_DIRS[${SDL2_INCLUDE_DIRS}]")


add_executable(GFX_V2
                            GFX.hxx
                            GFX_main.cxx
                                          )
target_link_libraries(GFX_V2 PRIVATE ${SDL2_LIBRARIES})
target_include_directories(GFX_V2 PRIVATE ${SDL2_INCLUDE_DIRS})
target_link_libraries(GFX_V2 PRIVATE SDL2::SDL2 SDL2::SDL2main)
target_compile_features(GFX_V2 PUBLIC cxx_std_17)
