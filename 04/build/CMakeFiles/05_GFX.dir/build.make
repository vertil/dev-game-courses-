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
include CMakeFiles/05_GFX.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/05_GFX.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/05_GFX.dir/flags.make

CMakeFiles/05_GFX.dir/05_GFX_main.cxx.o: CMakeFiles/05_GFX.dir/flags.make
CMakeFiles/05_GFX.dir/05_GFX_main.cxx.o: /home/vertil/dev/04/src/05_GFX_main.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vertil/dev/04/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/05_GFX.dir/05_GFX_main.cxx.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/05_GFX.dir/05_GFX_main.cxx.o -c /home/vertil/dev/04/src/05_GFX_main.cxx

CMakeFiles/05_GFX.dir/05_GFX_main.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/05_GFX.dir/05_GFX_main.cxx.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vertil/dev/04/src/05_GFX_main.cxx > CMakeFiles/05_GFX.dir/05_GFX_main.cxx.i

CMakeFiles/05_GFX.dir/05_GFX_main.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/05_GFX.dir/05_GFX_main.cxx.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vertil/dev/04/src/05_GFX_main.cxx -o CMakeFiles/05_GFX.dir/05_GFX_main.cxx.s

# Object files for target 05_GFX
05_GFX_OBJECTS = \
"CMakeFiles/05_GFX.dir/05_GFX_main.cxx.o"

# External object files for target 05_GFX
05_GFX_EXTERNAL_OBJECTS =

05_GFX: CMakeFiles/05_GFX.dir/05_GFX_main.cxx.o
05_GFX: CMakeFiles/05_GFX.dir/build.make
05_GFX: /usr/local/lib/libSDL2-2.0d.so.0.14.0
05_GFX: /usr/local/lib/libSDL2maind.a
05_GFX: CMakeFiles/05_GFX.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/vertil/dev/04/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 05_GFX"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/05_GFX.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/05_GFX.dir/build: 05_GFX

.PHONY : CMakeFiles/05_GFX.dir/build

CMakeFiles/05_GFX.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/05_GFX.dir/cmake_clean.cmake
.PHONY : CMakeFiles/05_GFX.dir/clean

CMakeFiles/05_GFX.dir/depend:
	cd /home/vertil/dev/04/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/vertil/dev/04/src /home/vertil/dev/04/src /home/vertil/dev/04/build /home/vertil/dev/04/build /home/vertil/dev/04/build/CMakeFiles/05_GFX.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/05_GFX.dir/depend

