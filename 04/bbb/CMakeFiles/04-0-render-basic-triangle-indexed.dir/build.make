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
CMAKE_SOURCE_DIR = /home/vertil/Загрузки/b_y-om-a76d84b01f5e/class-01-basic-game-dev/04-0-render-basic

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/vertil/dev/04/bbb

# Include any dependencies generated for this target.
include CMakeFiles/04-0-render-basic-triangle-indexed.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/04-0-render-basic-triangle-indexed.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/04-0-render-basic-triangle-indexed.dir/flags.make

CMakeFiles/04-0-render-basic-triangle-indexed.dir/03_triangle_indexed_render.cxx.o: CMakeFiles/04-0-render-basic-triangle-indexed.dir/flags.make
CMakeFiles/04-0-render-basic-triangle-indexed.dir/03_triangle_indexed_render.cxx.o: /home/vertil/Загрузки/b_y-om-a76d84b01f5e/class-01-basic-game-dev/04-0-render-basic/03_triangle_indexed_render.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vertil/dev/04/bbb/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/04-0-render-basic-triangle-indexed.dir/03_triangle_indexed_render.cxx.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/04-0-render-basic-triangle-indexed.dir/03_triangle_indexed_render.cxx.o -c /home/vertil/Загрузки/b_y-om-a76d84b01f5e/class-01-basic-game-dev/04-0-render-basic/03_triangle_indexed_render.cxx

CMakeFiles/04-0-render-basic-triangle-indexed.dir/03_triangle_indexed_render.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/04-0-render-basic-triangle-indexed.dir/03_triangle_indexed_render.cxx.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vertil/Загрузки/b_y-om-a76d84b01f5e/class-01-basic-game-dev/04-0-render-basic/03_triangle_indexed_render.cxx > CMakeFiles/04-0-render-basic-triangle-indexed.dir/03_triangle_indexed_render.cxx.i

CMakeFiles/04-0-render-basic-triangle-indexed.dir/03_triangle_indexed_render.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/04-0-render-basic-triangle-indexed.dir/03_triangle_indexed_render.cxx.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vertil/Загрузки/b_y-om-a76d84b01f5e/class-01-basic-game-dev/04-0-render-basic/03_triangle_indexed_render.cxx -o CMakeFiles/04-0-render-basic-triangle-indexed.dir/03_triangle_indexed_render.cxx.s

CMakeFiles/04-0-render-basic-triangle-indexed.dir/03_triangle_indexed_render_main.cxx.o: CMakeFiles/04-0-render-basic-triangle-indexed.dir/flags.make
CMakeFiles/04-0-render-basic-triangle-indexed.dir/03_triangle_indexed_render_main.cxx.o: /home/vertil/Загрузки/b_y-om-a76d84b01f5e/class-01-basic-game-dev/04-0-render-basic/03_triangle_indexed_render_main.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vertil/dev/04/bbb/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/04-0-render-basic-triangle-indexed.dir/03_triangle_indexed_render_main.cxx.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/04-0-render-basic-triangle-indexed.dir/03_triangle_indexed_render_main.cxx.o -c /home/vertil/Загрузки/b_y-om-a76d84b01f5e/class-01-basic-game-dev/04-0-render-basic/03_triangle_indexed_render_main.cxx

CMakeFiles/04-0-render-basic-triangle-indexed.dir/03_triangle_indexed_render_main.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/04-0-render-basic-triangle-indexed.dir/03_triangle_indexed_render_main.cxx.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vertil/Загрузки/b_y-om-a76d84b01f5e/class-01-basic-game-dev/04-0-render-basic/03_triangle_indexed_render_main.cxx > CMakeFiles/04-0-render-basic-triangle-indexed.dir/03_triangle_indexed_render_main.cxx.i

CMakeFiles/04-0-render-basic-triangle-indexed.dir/03_triangle_indexed_render_main.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/04-0-render-basic-triangle-indexed.dir/03_triangle_indexed_render_main.cxx.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vertil/Загрузки/b_y-om-a76d84b01f5e/class-01-basic-game-dev/04-0-render-basic/03_triangle_indexed_render_main.cxx -o CMakeFiles/04-0-render-basic-triangle-indexed.dir/03_triangle_indexed_render_main.cxx.s

CMakeFiles/04-0-render-basic-triangle-indexed.dir/00_canvas_basic.cxx.o: CMakeFiles/04-0-render-basic-triangle-indexed.dir/flags.make
CMakeFiles/04-0-render-basic-triangle-indexed.dir/00_canvas_basic.cxx.o: /home/vertil/Загрузки/b_y-om-a76d84b01f5e/class-01-basic-game-dev/04-0-render-basic/00_canvas_basic.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vertil/dev/04/bbb/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/04-0-render-basic-triangle-indexed.dir/00_canvas_basic.cxx.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/04-0-render-basic-triangle-indexed.dir/00_canvas_basic.cxx.o -c /home/vertil/Загрузки/b_y-om-a76d84b01f5e/class-01-basic-game-dev/04-0-render-basic/00_canvas_basic.cxx

CMakeFiles/04-0-render-basic-triangle-indexed.dir/00_canvas_basic.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/04-0-render-basic-triangle-indexed.dir/00_canvas_basic.cxx.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vertil/Загрузки/b_y-om-a76d84b01f5e/class-01-basic-game-dev/04-0-render-basic/00_canvas_basic.cxx > CMakeFiles/04-0-render-basic-triangle-indexed.dir/00_canvas_basic.cxx.i

CMakeFiles/04-0-render-basic-triangle-indexed.dir/00_canvas_basic.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/04-0-render-basic-triangle-indexed.dir/00_canvas_basic.cxx.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vertil/Загрузки/b_y-om-a76d84b01f5e/class-01-basic-game-dev/04-0-render-basic/00_canvas_basic.cxx -o CMakeFiles/04-0-render-basic-triangle-indexed.dir/00_canvas_basic.cxx.s

CMakeFiles/04-0-render-basic-triangle-indexed.dir/01_line_render.cxx.o: CMakeFiles/04-0-render-basic-triangle-indexed.dir/flags.make
CMakeFiles/04-0-render-basic-triangle-indexed.dir/01_line_render.cxx.o: /home/vertil/Загрузки/b_y-om-a76d84b01f5e/class-01-basic-game-dev/04-0-render-basic/01_line_render.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vertil/dev/04/bbb/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/04-0-render-basic-triangle-indexed.dir/01_line_render.cxx.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/04-0-render-basic-triangle-indexed.dir/01_line_render.cxx.o -c /home/vertil/Загрузки/b_y-om-a76d84b01f5e/class-01-basic-game-dev/04-0-render-basic/01_line_render.cxx

CMakeFiles/04-0-render-basic-triangle-indexed.dir/01_line_render.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/04-0-render-basic-triangle-indexed.dir/01_line_render.cxx.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vertil/Загрузки/b_y-om-a76d84b01f5e/class-01-basic-game-dev/04-0-render-basic/01_line_render.cxx > CMakeFiles/04-0-render-basic-triangle-indexed.dir/01_line_render.cxx.i

CMakeFiles/04-0-render-basic-triangle-indexed.dir/01_line_render.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/04-0-render-basic-triangle-indexed.dir/01_line_render.cxx.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vertil/Загрузки/b_y-om-a76d84b01f5e/class-01-basic-game-dev/04-0-render-basic/01_line_render.cxx -o CMakeFiles/04-0-render-basic-triangle-indexed.dir/01_line_render.cxx.s

CMakeFiles/04-0-render-basic-triangle-indexed.dir/02_triangle_render.cxx.o: CMakeFiles/04-0-render-basic-triangle-indexed.dir/flags.make
CMakeFiles/04-0-render-basic-triangle-indexed.dir/02_triangle_render.cxx.o: /home/vertil/Загрузки/b_y-om-a76d84b01f5e/class-01-basic-game-dev/04-0-render-basic/02_triangle_render.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vertil/dev/04/bbb/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/04-0-render-basic-triangle-indexed.dir/02_triangle_render.cxx.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/04-0-render-basic-triangle-indexed.dir/02_triangle_render.cxx.o -c /home/vertil/Загрузки/b_y-om-a76d84b01f5e/class-01-basic-game-dev/04-0-render-basic/02_triangle_render.cxx

CMakeFiles/04-0-render-basic-triangle-indexed.dir/02_triangle_render.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/04-0-render-basic-triangle-indexed.dir/02_triangle_render.cxx.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vertil/Загрузки/b_y-om-a76d84b01f5e/class-01-basic-game-dev/04-0-render-basic/02_triangle_render.cxx > CMakeFiles/04-0-render-basic-triangle-indexed.dir/02_triangle_render.cxx.i

CMakeFiles/04-0-render-basic-triangle-indexed.dir/02_triangle_render.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/04-0-render-basic-triangle-indexed.dir/02_triangle_render.cxx.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vertil/Загрузки/b_y-om-a76d84b01f5e/class-01-basic-game-dev/04-0-render-basic/02_triangle_render.cxx -o CMakeFiles/04-0-render-basic-triangle-indexed.dir/02_triangle_render.cxx.s

# Object files for target 04-0-render-basic-triangle-indexed
04__0__render__basic__triangle__indexed_OBJECTS = \
"CMakeFiles/04-0-render-basic-triangle-indexed.dir/03_triangle_indexed_render.cxx.o" \
"CMakeFiles/04-0-render-basic-triangle-indexed.dir/03_triangle_indexed_render_main.cxx.o" \
"CMakeFiles/04-0-render-basic-triangle-indexed.dir/00_canvas_basic.cxx.o" \
"CMakeFiles/04-0-render-basic-triangle-indexed.dir/01_line_render.cxx.o" \
"CMakeFiles/04-0-render-basic-triangle-indexed.dir/02_triangle_render.cxx.o"

# External object files for target 04-0-render-basic-triangle-indexed
04__0__render__basic__triangle__indexed_EXTERNAL_OBJECTS =

04-0-render-basic-triangle-indexed: CMakeFiles/04-0-render-basic-triangle-indexed.dir/03_triangle_indexed_render.cxx.o
04-0-render-basic-triangle-indexed: CMakeFiles/04-0-render-basic-triangle-indexed.dir/03_triangle_indexed_render_main.cxx.o
04-0-render-basic-triangle-indexed: CMakeFiles/04-0-render-basic-triangle-indexed.dir/00_canvas_basic.cxx.o
04-0-render-basic-triangle-indexed: CMakeFiles/04-0-render-basic-triangle-indexed.dir/01_line_render.cxx.o
04-0-render-basic-triangle-indexed: CMakeFiles/04-0-render-basic-triangle-indexed.dir/02_triangle_render.cxx.o
04-0-render-basic-triangle-indexed: CMakeFiles/04-0-render-basic-triangle-indexed.dir/build.make
04-0-render-basic-triangle-indexed: CMakeFiles/04-0-render-basic-triangle-indexed.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/vertil/dev/04/bbb/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable 04-0-render-basic-triangle-indexed"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/04-0-render-basic-triangle-indexed.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/04-0-render-basic-triangle-indexed.dir/build: 04-0-render-basic-triangle-indexed

.PHONY : CMakeFiles/04-0-render-basic-triangle-indexed.dir/build

CMakeFiles/04-0-render-basic-triangle-indexed.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/04-0-render-basic-triangle-indexed.dir/cmake_clean.cmake
.PHONY : CMakeFiles/04-0-render-basic-triangle-indexed.dir/clean

CMakeFiles/04-0-render-basic-triangle-indexed.dir/depend:
	cd /home/vertil/dev/04/bbb && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/vertil/Загрузки/b_y-om-a76d84b01f5e/class-01-basic-game-dev/04-0-render-basic /home/vertil/Загрузки/b_y-om-a76d84b01f5e/class-01-basic-game-dev/04-0-render-basic /home/vertil/dev/04/bbb /home/vertil/dev/04/bbb /home/vertil/dev/04/bbb/CMakeFiles/04-0-render-basic-triangle-indexed.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/04-0-render-basic-triangle-indexed.dir/depend
