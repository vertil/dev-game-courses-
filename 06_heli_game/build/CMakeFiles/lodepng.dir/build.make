# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

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
CMAKE_SOURCE_DIR = /home/vertil/game/heli_game-main/06_heli_game/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/vertil/dev/06_heli_game/build

# Include any dependencies generated for this target.
include CMakeFiles/lodepng.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/lodepng.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lodepng.dir/flags.make

CMakeFiles/lodepng.dir/lodepng.cpp.o: CMakeFiles/lodepng.dir/flags.make
CMakeFiles/lodepng.dir/lodepng.cpp.o: /home/vertil/game/heli_game-main/06_heli_game/src/lodepng.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vertil/dev/06_heli_game/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/lodepng.dir/lodepng.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lodepng.dir/lodepng.cpp.o -c /home/vertil/game/heli_game-main/06_heli_game/src/lodepng.cpp

CMakeFiles/lodepng.dir/lodepng.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lodepng.dir/lodepng.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vertil/game/heli_game-main/06_heli_game/src/lodepng.cpp > CMakeFiles/lodepng.dir/lodepng.cpp.i

CMakeFiles/lodepng.dir/lodepng.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lodepng.dir/lodepng.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vertil/game/heli_game-main/06_heli_game/src/lodepng.cpp -o CMakeFiles/lodepng.dir/lodepng.cpp.s

# Object files for target lodepng
lodepng_OBJECTS = \
"CMakeFiles/lodepng.dir/lodepng.cpp.o"

# External object files for target lodepng
lodepng_EXTERNAL_OBJECTS =

liblodepng.so: CMakeFiles/lodepng.dir/lodepng.cpp.o
liblodepng.so: CMakeFiles/lodepng.dir/build.make
liblodepng.so: CMakeFiles/lodepng.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/vertil/dev/06_heli_game/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library liblodepng.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lodepng.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lodepng.dir/build: liblodepng.so

.PHONY : CMakeFiles/lodepng.dir/build

CMakeFiles/lodepng.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lodepng.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lodepng.dir/clean

CMakeFiles/lodepng.dir/depend:
	cd /home/vertil/dev/06_heli_game/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/vertil/game/heli_game-main/06_heli_game/src /home/vertil/game/heli_game-main/06_heli_game/src /home/vertil/dev/06_heli_game/build /home/vertil/dev/06_heli_game/build /home/vertil/dev/06_heli_game/build/CMakeFiles/lodepng.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lodepng.dir/depend

