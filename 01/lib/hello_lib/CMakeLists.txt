cmake_minimum_required(VERSION 3.18)

project(Hello-lib VERSION 1.0)

add_library(Hello-lib-stat STATIC include/hello_lib.hxx src/hello_lib.cxx)
target_include_directories(Hello-lib-stat PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_compile_features(Hello-lib-stat PUBLIC cxx_std_17)

add_library(Hello-lib-dyn SHARED include/hello_lib.hxx src/hello_lib.cxx)
target_include_directories(Hello-lib-dyn PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_compile_features(Hello-lib-dyn PUBLIC cxx_std_17)


