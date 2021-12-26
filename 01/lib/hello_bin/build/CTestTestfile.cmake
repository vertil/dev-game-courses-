# CMake generated Testfile for 
# Source directory: /home/vertil/dev/01/lib/hello_bin
# Build directory: /home/vertil/dev/01/lib/hello_bin/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(Test-dyn "Hello-bin-dyn")
set_tests_properties(Test-dyn PROPERTIES  PASS_REGULAR_EXPRESSION "hello, vertil" _BACKTRACE_TRIPLES "/home/vertil/dev/01/lib/hello_bin/CMakeLists.txt;24;add_test;/home/vertil/dev/01/lib/hello_bin/CMakeLists.txt;0;")
add_test(Test-stat "Hello-bin-stat")
set_tests_properties(Test-stat PROPERTIES  PASS_REGULAR_EXPRESSION "hello, vertil" _BACKTRACE_TRIPLES "/home/vertil/dev/01/lib/hello_bin/CMakeLists.txt;25;add_test;/home/vertil/dev/01/lib/hello_bin/CMakeLists.txt;0;")
