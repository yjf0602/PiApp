cmake_minimum_required (VERSION 2.8)

project (PiApp)

add_subdirectory(app)
add_subdirectory(lcd_1in3)
add_subdirectory(utils)

add_executable(PiApp main.cpp)

target_link_libraries(PiApp app)
target_link_libraries(PiApp lcd_1in3)
target_link_libraries(PiApp utils)
target_link_libraries(PiApp bcm2835)

include (FindPkgConfig)
pkg_check_modules(OPENCV REQUIRED opencv)

target_link_libraries(PiApp ${OPENCV_LDFLAGS})