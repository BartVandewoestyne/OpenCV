add_executable(example9-01 example9-01.cpp)
target_link_libraries(example9-01 ${OpenCV_LIBS})

add_executable(background_avg_main cv_yuv_codebook.cpp averaging_background_method.cpp background_avg_main.cpp)
target_link_libraries(background_avg_main ${OpenCV_LIBS})
