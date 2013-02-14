cmake_minimum_required(VERSION 2.6)

project(OpenCV_Tests)

include(../OpenCV_selection.cmake)

add_executable(videowriter videowriter.cpp)
target_link_libraries(videowriter ${OpenCV_LIBS})

add_executable(framecountertest framecountertest.cpp)
target_link_libraries(framecountertest ${OpenCV_LIBS})
