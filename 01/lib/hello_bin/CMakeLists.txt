cmake_minimum_required(VERSION 3.18)

project(Hello-bin VERSION 1.0)
#--------------dyn
add_executable(Hello-bin-dyn ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cxx)

target_compile_features(Hello-bin-dyn PUBLIC cxx_std_17)

target_include_directories(Hello-bin-dyn PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../hello_lib/include  )

target_link_libraries(Hello-bin-dyn   ${CMAKE_CURRENT_SOURCE_DIR}/../hello_lib/build/libHello-lib-dyn.so)

#-----------------stat
add_executable(Hello-bin-stat ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cxx)

target_compile_features(Hello-bin-stat PUBLIC cxx_std_17)

target_include_directories(Hello-bin-stat PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../hello_lib/include  )

target_link_libraries(Hello-bin-stat   ${CMAKE_CURRENT_SOURCE_DIR}/../hello_lib/build/libHello-lib-stat.a)

#--------------tests
include(CTest)
add_test(Test-dyn Hello-bin-dyn)
add_test(Test-stat Hello-bin-stat)
#set_tests_properties(Test-dyn PROPERTIES TIMEOUT ${MULTIPLY_TIMEOUT})

set_tests_properties(Test-dyn PROPERTIES PASS_REGULAR_EXPRESSION "hello, vertil")
set_tests_properties(Test-stat PROPERTIES PASS_REGULAR_EXPRESSION "hello, vertil")



#include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../hello_lib/include)
#link_directories(${CMAKE_CURRENT_SOURCE_DIR}/../hello_lib/include)

#add_library(Hello-lib-dyn SHARED ${CMAKE_CURRENT_SOURCE_DIR}/../hello_lib/include/hello_lib.hxx ${CMAKE_CURRENT_SOURCE_DIR}/../hello_lib/src/hello_lib.cxx)
#target_include_directories(Hello-lib-dyn PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../hello_lib/include)
#target_compile_features(Hello-lib-dyn PUBLIC cxx_std_17)

#target_include_directories(Hello-bin-dyn PUBLIC Hello-lib-dyn)

