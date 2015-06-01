cmake_minimum_required(VERSION 2.6)

project(OpenCV_Examples)

include(../OpenCV_selection.cmake)

add_executable(image_properties image_properties.cpp)
target_link_libraries(image_properties ${OpenCV_LIBS})

add_executable(capture_properties capture_properties.cpp)
target_link_libraries(capture_properties ${OpenCV_LIBS})

add_executable(cvMat cvMat.cpp)
target_link_libraries(cvMat ${OpenCV_LIBS})
