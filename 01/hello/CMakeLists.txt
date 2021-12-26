cmake_minimum_required(VERSION 3.18)

project(Hello VERSION 1.0)

add_executable(Hello main.cxx)

target_compile_features(Hello PUBLIC cxx_std_17)

include(CTest)
add_test(Test-hello Hello)

set_tests_properties(Test-hello PROPERTIES TIMEOUT ${MULTIPLY_TIMEOUT})

set_tests_properties(Test-hello PROPERTIES PASS_REGULAR_EXPRESSION "hello, vertil")
