cmake_minimum_required(VERSION 3.18)
project(sdl-dyn)
add_executable(sdl-dyn main.cxx)
target_compile_features(sdl-dyn PUBLIC cxx_std_17)


#target_include_directories(sdl-dyn PUBLIC /home/vertil/SDL2-2.0.14/include)
#target_link_libraries(sdl-dyn PUBLIC /home/vertil/sdl/libSDL2-2.0d.so -Wl,--enable-new-dtags
#		-lpthread
#)




#--------------
include(CTest)
add_test(Test-dyn sdl-dyn)
#set_tests_properties(Test-dyn PROPERTIES TIMEOUT ${MULTIPLY_TIMEOUT})

set_tests_properties(Test-dyn PROPERTIES PASS_REGULAR_EXPRESSION "compiled: 2.0.14\nlinked: 2.0.14")
