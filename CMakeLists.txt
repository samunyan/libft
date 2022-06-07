cmake_minimum_required(VERSION 3.16)
project(libft C)
set(CMAKE_C_STANDARD 99)

aux_source_directory(${CMAKE_SOURCE_DIR}/ SRC)
aux_source_directory(${CMAKE_SOURCE_DIR}/ft_printf PRINTF_SRC)
aux_source_directory(${CMAKE_SOURCE_DIR}/_testing TEST_SRC)

include_directories(${CMAKE_SOURCE_DIR})

add_library(ft STATIC ${SRC})
add_library(ftprintf STATIC ${PRINTF_SRC})

add_executable(libft_test ${TEST_SRC})

target_link_libraries(ft ftprintf)
target_link_libraries(libft_test ft)


