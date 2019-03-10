cmake_minimum_required (VERSION 2.8)

aux_source_directory(. DIR_LIB_SRCS)

set(CMAKE_C_COMPILER gcc)

add_library(lcd_1in3 ${DIR_LIB_SRCS})