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
CMAKE_SOURCE_DIR = /home/vertil/dev/05_heli_imgui/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/vertil/dev/05_heli_imgui/build

# Include any dependencies generated for this target.
include CMakeFiles/game_heli.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/game_heli.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/game_heli.dir/flags.make

CMakeFiles/game_heli.dir/lodepng.cpp.o: CMakeFiles/game_heli.dir/flags.make
CMakeFiles/game_heli.dir/lodepng.cpp.o: /home/vertil/dev/05_heli_imgui/src/lodepng.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vertil/dev/05_heli_imgui/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/game_heli.dir/lodepng.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/game_heli.dir/lodepng.cpp.o -c /home/vertil/dev/05_heli_imgui/src/lodepng.cpp

CMakeFiles/game_heli.dir/lodepng.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game_heli.dir/lodepng.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vertil/dev/05_heli_imgui/src/lodepng.cpp > CMakeFiles/game_heli.dir/lodepng.cpp.i

CMakeFiles/game_heli.dir/lodepng.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game_heli.dir/lodepng.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vertil/dev/05_heli_imgui/src/lodepng.cpp -o CMakeFiles/game_heli.dir/lodepng.cpp.s

CMakeFiles/game_heli.dir/game.cxx.o: CMakeFiles/game_heli.dir/flags.make
CMakeFiles/game_heli.dir/game.cxx.o: /home/vertil/dev/05_heli_imgui/src/game.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vertil/dev/05_heli_imgui/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/game_heli.dir/game.cxx.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/game_heli.dir/game.cxx.o -c /home/vertil/dev/05_heli_imgui/src/game.cxx

CMakeFiles/game_heli.dir/game.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game_heli.dir/game.cxx.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vertil/dev/05_heli_imgui/src/game.cxx > CMakeFiles/game_heli.dir/game.cxx.i

CMakeFiles/game_heli.dir/game.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game_heli.dir/game.cxx.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vertil/dev/05_heli_imgui/src/game.cxx -o CMakeFiles/game_heli.dir/game.cxx.s

# Object files for target game_heli
game_heli_OBJECTS = \
"CMakeFiles/game_heli.dir/lodepng.cpp.o" \
"CMakeFiles/game_heli.dir/game.cxx.o"

# External object files for target game_heli
game_heli_EXTERNAL_OBJECTS =

game_heli: CMakeFiles/game_heli.dir/lodepng.cpp.o
game_heli: CMakeFiles/game_heli.dir/game.cxx.o
game_heli: CMakeFiles/game_heli.dir/build.make
game_heli: /usr/local/lib/libSDL2-2.0d.so.0.14.0
game_heli: /usr/local/lib/libSDL2maind.a
game_heli: imgui/libimgui.a
game_heli: libglad.so
game_heli: CMakeFiles/game_heli.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/vertil/dev/05_heli_imgui/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable game_heli"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/game_heli.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/game_heli.dir/build: game_heli

.PHONY : CMakeFiles/game_heli.dir/build

CMakeFiles/game_heli.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/game_heli.dir/cmake_clean.cmake
.PHONY : CMakeFiles/game_heli.dir/clean

CMakeFiles/game_heli.dir/depend:
	cd /home/vertil/dev/05_heli_imgui/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/vertil/dev/05_heli_imgui/src /home/vertil/dev/05_heli_imgui/src /home/vertil/dev/05_heli_imgui/build /home/vertil/dev/05_heli_imgui/build /home/vertil/dev/05_heli_imgui/build/CMakeFiles/game_heli.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/game_heli.dir/depend

