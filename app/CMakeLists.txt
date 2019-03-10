cmake_minimum_required (VERSION 2.8)

aux_source_directory(. DIR_LIB_SRCS)
aux_source_directory(./app_camera DIR_LIB_SRCS)

add_library(app ${DIR_LIB_SRCS})