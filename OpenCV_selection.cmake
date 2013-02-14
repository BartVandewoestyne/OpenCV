# Set this to the version of OpenCV that you need.
set(OPENCV_LIB "fat")

if(OPENCV_LIB STREQUAL "latest")

  message(STATUS "Using my own compiled OpenCV.")
  set(OpenCV_INCLUDE_DIR "/opt/opencv/latest/include/opencv")
  include_directories(${OpenCV_INCLUDE_DIR})
  set(OpenCV_LIBS "opencv_gpu;opencv_contrib;opencv_legacy;opencv_objdetect;opencv_calib3d;opencv_features2d;opencv_video;opencv_highgui;opencv_ml;opencv_imgproc;opencv_flann;opencv_core")
  link_directories(/opt/opencv/latest/lib)

elseif(OPENCV_LIB STREQUAL "fat")

  message(STATUS "Using OpenCV from Traficon's fat repository.")
  set(OpenCV_INCLUDE_DIR "$ENV{HOME}/Git/Research/fat/inc/TraficonOpenCv/opencv")
  include_directories(${OpenCV_INCLUDE_DIR})
  set(OpenCV_LIBS "opencv_gpu;opencv_contrib;opencv_legacy;opencv_objdetect;opencv_calib3d;opencv_features2d;opencv_video;opencv_highgui;opencv_ml;opencv_imgproc;opencv_flann;opencv_core")
  link_directories($ENV{HOME}/Git/Research/fat/bin/TraficonOpenCv/linux_release $ENV{HOME}/Git/Research/fat/bin/FFMpeg/linux_release)

elseif(OPENCV_LIB STREQUAL "system")

  message(STATUS "Using OpenCV that got automatically detected.")
  find_package( OpenCV REQUIRED )

else()
  message(ERROR "No OpenCV library found!")
endif()
