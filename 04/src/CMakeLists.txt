cmake_minimum_required(VERSION 3.16)
project(render_base CXX)
#---0-work-with-file
add_executable(0_render_base 	 0_canvas_base.cxx
                                 0_canvas_base.hxx
                                 0_canvas_base_main.cxx
                                 )
target_compile_features(0_render_base PUBLIC cxx_std_17)
#---1-line
add_executable(01_render_line	 0_canvas_base.hxx
                                 01_render_line.hxx
                                 01_render_line_main.cxx
                                 )
target_compile_features(01_render_line PUBLIC cxx_std_17)
#---2-triangle
add_executable(02_triangle	 0_canvas_base.cxx
                                 01_render_line.hxx
                                 02_triangle.hxx
                                 02_triangle_main.cxx
                                 )
target_compile_features(02_triangle PUBLIC cxx_std_17)
#---3-triangle-index
add_executable(03_triangle_index 0_canvas_base.hxx
                                 01_render_line.hxx
                                 02_triangle.hxx
                                 03_triangle_index.hxx
                                 03_triangle_index_main.cxx
                                 )
target_compile_features(03_triangle_index PUBLIC cxx_std_17)
#---4-triangle-modified
add_executable(04_triangle_modified 0_canvas_base.hxx
                                    01_render_line.hxx
                                    02_triangle.hxx
                                    03_triangle_index.hxx
                                    04_triangle_mod.hxx
                                    04_triangle_mod_main.cxx

                                 )
target_compile_features(04_triangle_modified PUBLIC cxx_std_17)
#---5-GFX
find_package(SDL2 REQUIRED)
message(STATUS "SDL2_LIBRARIES[${SDL2_LIBRARIES}] "
    "SDL2_INCLUDE_DIRS[${SDL2_INCLUDE_DIRS}]")


add_executable(05_GFX       0_canvas_base.hxx
                            01_render_line.hxx
                            02_triangle.hxx
                            03_triangle_index.hxx
                            04_triangle_mod.hxx
                            05_GFX.hxx
                            #05_GFX.cxx
                            05_GFX_main.cxx
                                          )
target_link_libraries(05_GFX PRIVATE ${SDL2_LIBRARIES})
target_include_directories(05_GFX PRIVATE ${SDL2_INCLUDE_DIRS})
target_link_libraries(05_GFX PRIVATE SDL2::SDL2 SDL2::SDL2main)
target_compile_features(05_GFX PUBLIC cxx_std_17)
