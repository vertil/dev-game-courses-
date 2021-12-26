cmake_minimum_required(VERSION 3.18)
project(game-dll)
#---------library
#add_library(eng STATIC ${CMAKE_CURRENT_SOURCE_DIR}/engine.cxx ${CMAKE_CURRENT_SOURCE_DIR}/engine.hxx)
#target_compile_features(eng PUBLIC cxx_std_17)
#find_package(SDL2 REQUIRED)
#target_link_libraries(eng PRIVATE SDL2::SDL2 SDL2::SDL2main)
#---------main
#add_executable(loop main.cxx)
#target_compile_features(loop PUBLIC cxx_std_17)
#----target_include_directories(loop )
#target_link_libraries(loop PUBLIC eng)


#------------game-dll
add_library(game SHARED ${CMAKE_CURRENT_SOURCE_DIR}/main.cxx)
target_compile_features(game PUBLIC cxx_std_17)
#-------------engine
add_executable(eng ${CMAKE_CURRENT_SOURCE_DIR}/engine.cxx ${CMAKE_CURRENT_SOURCE_DIR}/engine.hxx)
target_compile_features(eng PUBLIC cxx_std_17)
set_target_properties(eng PROPERTIES ENABLE_EXPORTS 1)
find_package(SDL2 REQUIRED)
target_link_libraries(eng PRIVATE SDL2::SDL2 SDL2::SDL2main)
target_link_libraries(eng PRIVATE game)

