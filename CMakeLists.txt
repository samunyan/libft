cmake_minimum_required(VERSION 3.16)
project(libft C)

aux_source_directory(${CMAKE_SOURCE_DIR}/ SRC)
add_library(libft ${SRC})

target_link_libraries(libft libft.a)
