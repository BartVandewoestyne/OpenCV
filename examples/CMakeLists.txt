cmake_minimum_required(VERSION 2.6)

project(OpenCV_Examples)

include(../OpenCV_selection.cmake)

add_executable(properties properties.cpp)
target_link_libraries(properties ${OpenCV_LIBS})
