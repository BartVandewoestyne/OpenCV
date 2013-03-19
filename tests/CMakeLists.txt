cmake_minimum_required(VERSION 2.6)

project(OpenCV_Tests)

include(../OpenCV_selection.cmake)

add_executable(videowriter1 videowriter1.cpp)
target_link_libraries(videowriter1 ${OpenCV_LIBS})

add_executable(videowriter2 videowriter2.cpp)
target_link_libraries(videowriter2 ${OpenCV_LIBS})

add_executable(framecountertest framecountertest.cpp)
target_link_libraries(framecountertest ${OpenCV_LIBS})

add_executable(cvHoughLines2 cvHoughLines2.cpp)
target_link_libraries(cvHoughLines2 ${OpenCV_LIBS})

#add_executable(myHoughTest myHoughTest.cpp)
#target_link_libraries(myHoughTest ${OpenCV_LIBS})
