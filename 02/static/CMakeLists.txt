cmake_minimum_required(VERSION 3.18)
project(sdl-stat)

add_executable(sdl-stat main.cxx)
target_compile_features(sdl-stat PUBLIC cxx_std_17)

#target_include_directories(sdl-stat PUBLIC /home/vertil/SDL2-2.0.14/include)
#target_link_libraries(sdl-stat  /home/vertil/sdl/libSDL2d.a  -Wl,--no-undefined 
   #            -lm
    #           -ldl
     #          -lpthread
      #         -lrt)
find_package(SDL2 REQUIRED)
target_include_directories(sdl-stat ${SDL2_INCLUDE_DIRS})
find_library(SDL2_LIB libSDL2d.a)
target_link_libraries(sdl-stat ${SDL2_LIB}
    -pthread  -ldl -lm  -pthread -Wl,--no-undefined 
    )
#-------------------------
include(CTest)
add_test(Test-stat sdl-stat)
#set_tests_properties(Test-dyn PROPERTIES TIMEOUT ${MULTIPLY_TIMEOUT})

set_tests_properties(Test-stat PROPERTIES PASS_REGULAR_EXPRESSION "compiled: 2.0.14\n
linked: 2.0.14")
#--------------------




