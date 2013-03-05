# Set this to the version of OpenCV that you need.
set(OPENCV_LIB "latest")

if(OPENCV_LIB STREQUAL "latest")

  message(STATUS "Using my own compiled OpenCV.")
  include_directories("/opt/opencv/latest/include/opencv")
  link_directories("/opt/opencv/latest/lib")
  set(OpenCV_LIBS "opencv_gpu;opencv_contrib;opencv_legacy;opencv_objdetect;opencv_calib3d;opencv_features2d;opencv_video;opencv_highgui;opencv_ml;opencv_imgproc;opencv_flann;opencv_core")

elseif(OPENCV_LIB STREQUAL "fat")

  message(STATUS "Using OpenCV from Traficon's fat repository.")
  include_directories("$ENV{HOME}/Git/Research/fat/inc/TraficonOpenCv/opencv")
  link_directories("$ENV{HOME}/Git/Research/fat/bin/TraficonOpenCv/linux_release" "$ENV{HOME}/Git/Research/fat/bin/FFMpeg/linux_release")
  set(OpenCV_LIBS "opencv_gpu;opencv_contrib;opencv_legacy;opencv_objdetect;opencv_calib3d;opencv_features2d;opencv_video;opencv_highgui;opencv_ml;opencv_imgproc;opencv_flann;opencv_core")

elseif(OPENCV_LIB STREQUAL "system")

  message(STATUS "Using OpenCV that got automatically detected.")
  find_package( OpenCV REQUIRED )

else()
  message(ERROR "No OpenCV library found!")
endif()
