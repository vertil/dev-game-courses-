# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/vertil/dev/03/loop-to-eng/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/vertil/dev/03/loop/build-Release

# Include any dependencies generated for this target.
include CMakeFiles/eng.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/eng.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/eng.dir/flags.make

CMakeFiles/eng.dir/engine.cxx.o: CMakeFiles/eng.dir/flags.make
CMakeFiles/eng.dir/engine.cxx.o: /home/vertil/dev/03/loop-to-eng/src/engine.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vertil/dev/03/loop/build-Release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/eng.dir/engine.cxx.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/eng.dir/engine.cxx.o -c /home/vertil/dev/03/loop-to-eng/src/engine.cxx

CMakeFiles/eng.dir/engine.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/eng.dir/engine.cxx.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vertil/dev/03/loop-to-eng/src/engine.cxx > CMakeFiles/eng.dir/engine.cxx.i

CMakeFiles/eng.dir/engine.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/eng.dir/engine.cxx.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vertil/dev/03/loop-to-eng/src/engine.cxx -o CMakeFiles/eng.dir/engine.cxx.s

# Object files for target eng
eng_OBJECTS = \
"CMakeFiles/eng.dir/engine.cxx.o"

# External object files for target eng
eng_EXTERNAL_OBJECTS =

libeng.a: CMakeFiles/eng.dir/engine.cxx.o
libeng.a: CMakeFiles/eng.dir/build.make
libeng.a: CMakeFiles/eng.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/vertil/dev/03/loop/build-Release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libeng.a"
	$(CMAKE_COMMAND) -P CMakeFiles/eng.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/eng.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/eng.dir/build: libeng.a

.PHONY : CMakeFiles/eng.dir/build

CMakeFiles/eng.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/eng.dir/cmake_clean.cmake
.PHONY : CMakeFiles/eng.dir/clean

CMakeFiles/eng.dir/depend:
	cd /home/vertil/dev/03/loop/build-Release && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/vertil/dev/03/loop-to-eng/src /home/vertil/dev/03/loop-to-eng/src /home/vertil/dev/03/loop/build-Release /home/vertil/dev/03/loop/build-Release /home/vertil/dev/03/loop/build-Release/CMakeFiles/eng.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/eng.dir/depend

