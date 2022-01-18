cmake_minimum_required(VERSION 3.13)

project(toyrobot)

aux_source_directory("${CMAKE_CURRENT_SOURCE_DIR}/src" DIR_SRCS) 

add_executable(toyrobot ${DIR_SRCS})