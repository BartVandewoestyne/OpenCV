# Set this to the version of OpenCV that you need.
set(OPENCV_LIB "mine")

if(OPENCV_LIB STREQUAL "mine")

  message(STATUS "Using my own compiled OpenCV.")
  include_directories("D:\\SVN\\SE-Simulation-XDSRacu\\Libraries\\ICRacuMath\\OpenCV\\2.3.1\\include\\opencv"
	              "D:\\SVN\\SE-Simulation-XDSRacu\\Libraries\\ICRacuMath\\OpenCV\\2.3.1\\include")
  link_directories("D:\\SVN\\SE-Simulation-XDSRacu\\Libraries\\ICRacuMath\\OpenCV\\2.3.1\\vc11\\bin"
	           "D:\\SVN\\SE-Simulation-XDSRacu\\Libraries\\ICRacuMath\\OpenCV\\2.3.1\\vc11\\lib")
  set(OpenCV_LIBS "opencv_gpu231d;opencv_contrib231d;opencv_legacy231d;opencv_objdetect231d;opencv_calib3d231d;opencv_features2d231d;opencv_video231d;opencv_highgui231d;opencv_ml231d;opencv_imgproc231d;opencv_flann231d;opencv_core231d")

elseif(OPENCV_LIB STREQUAL "system")

  message(STATUS "Using OpenCV that got automatically detected.")
  find_package( OpenCV REQUIRED )

else()
  message(ERROR "No OpenCV library found!")
endif()
