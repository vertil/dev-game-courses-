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
CMAKE_SOURCE_DIR = /home/vertil/dev/04/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/vertil/dev/04/build

# Include any dependencies generated for this target.
include CMakeFiles/03_triangle_index.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/03_triangle_index.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/03_triangle_index.dir/flags.make

CMakeFiles/03_triangle_index.dir/03_triangle_index_main.cxx.o: CMakeFiles/03_triangle_index.dir/flags.make
CMakeFiles/03_triangle_index.dir/03_triangle_index_main.cxx.o: /home/vertil/dev/04/src/03_triangle_index_main.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vertil/dev/04/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/03_triangle_index.dir/03_triangle_index_main.cxx.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/03_triangle_index.dir/03_triangle_index_main.cxx.o -c /home/vertil/dev/04/src/03_triangle_index_main.cxx

CMakeFiles/03_triangle_index.dir/03_triangle_index_main.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/03_triangle_index.dir/03_triangle_index_main.cxx.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vertil/dev/04/src/03_triangle_index_main.cxx > CMakeFiles/03_triangle_index.dir/03_triangle_index_main.cxx.i

CMakeFiles/03_triangle_index.dir/03_triangle_index_main.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/03_triangle_index.dir/03_triangle_index_main.cxx.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vertil/dev/04/src/03_triangle_index_main.cxx -o CMakeFiles/03_triangle_index.dir/03_triangle_index_main.cxx.s

# Object files for target 03_triangle_index
03_triangle_index_OBJECTS = \
"CMakeFiles/03_triangle_index.dir/03_triangle_index_main.cxx.o"

# External object files for target 03_triangle_index
03_triangle_index_EXTERNAL_OBJECTS =

03_triangle_index: CMakeFiles/03_triangle_index.dir/03_triangle_index_main.cxx.o
03_triangle_index: CMakeFiles/03_triangle_index.dir/build.make
03_triangle_index: CMakeFiles/03_triangle_index.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/vertil/dev/04/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 03_triangle_index"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/03_triangle_index.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/03_triangle_index.dir/build: 03_triangle_index

.PHONY : CMakeFiles/03_triangle_index.dir/build

CMakeFiles/03_triangle_index.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/03_triangle_index.dir/cmake_clean.cmake
.PHONY : CMakeFiles/03_triangle_index.dir/clean

CMakeFiles/03_triangle_index.dir/depend:
	cd /home/vertil/dev/04/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/vertil/dev/04/src /home/vertil/dev/04/src /home/vertil/dev/04/build /home/vertil/dev/04/build /home/vertil/dev/04/build/CMakeFiles/03_triangle_index.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/03_triangle_index.dir/depend

