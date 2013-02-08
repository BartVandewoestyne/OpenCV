/**
 * Print out all capture properties for a specified video file.
 */

#include "cv.h"
#include "highgui.h"
#include <stdio.h>

int main( int argc, char* argv[] ) {

    CvCapture* capture = cvCreateFileCapture( argv[1] );

    std::cout << "CV_CAP_PROP_POS_MSEC = "
              << cvGetCaptureProperty( capture, CV_CAP_PROP_POS_MSEC )
              << std::endl;

    std::cout << "CV_CAP_PROP_POS_FRAMES = "
              << cvGetCaptureProperty( capture, CV_CAP_PROP_POS_FRAMES )
              << std::endl;

    std::cout << "CV_CAP_PROP_POS_AVI_RATIO = "
              << cvGetCaptureProperty( capture, CV_CAP_PROP_POS_AVI_RATIO )
              << std::endl;

    std::cout << "CV_CAP_PROP_FRAME_WIDTH = "
              << cvGetCaptureProperty( capture, CV_CAP_PROP_FRAME_WIDTH )
              << std::endl;

    std::cout << "CV_CAP_PROP_FRAME_HEIGHT = "
              << cvGetCaptureProperty( capture, CV_CAP_PROP_FRAME_HEIGHT )
              << std::endl;

    std::cout << "CV_CAP_PROP_FPS = "
              << cvGetCaptureProperty( capture, CV_CAP_PROP_FPS )
              << std::endl;

    std::cout << "CV_CAP_PROP_FOURCC = "
              << cvGetCaptureProperty( capture, CV_CAP_PROP_FOURCC )
              << std::endl;

    std::cout << "CV_CAP_PROP_FRAME_COUNT = "
              << cvGetCaptureProperty( capture, CV_CAP_PROP_FRAME_COUNT )
              << std::endl;

    std::cout << "CV_CAP_PROP_FORMAT = "
              << cvGetCaptureProperty( capture, CV_CAP_PROP_FORMAT )
              << std::endl;

    std::cout << "CV_CAP_PROP_MODE = "
              << cvGetCaptureProperty( capture, CV_CAP_PROP_MODE )
              << std::endl;

    std::cout << "CV_CAP_PROP_BRIGHTNESS = "
              << cvGetCaptureProperty( capture, CV_CAP_PROP_BRIGHTNESS )
              << std::endl;

    std::cout << "CV_CAP_PROP_CONTRAST = "
              << cvGetCaptureProperty( capture, CV_CAP_PROP_CONTRAST )
              << std::endl;

    std::cout << "CV_CAP_PROP_SATURATION = "
              << cvGetCaptureProperty( capture, CV_CAP_PROP_SATURATION )
              << std::endl;

    std::cout << "CV_CAP_PROP_HUE = "
              << cvGetCaptureProperty( capture, CV_CAP_PROP_HUE )
              << std::endl;

    std::cout << "CV_CAP_PROP_GAIN = "
              << cvGetCaptureProperty( capture, CV_CAP_PROP_GAIN )
              << std::endl;

    std::cout << "CV_CAP_PROP_EXPOSURE = "
              << cvGetCaptureProperty( capture, CV_CAP_PROP_EXPOSURE )
              << std::endl;

    std::cout << "CV_CAP_PROP_CONVERT_RGB = "
              << cvGetCaptureProperty( capture, CV_CAP_PROP_CONVERT_RGB )
              << std::endl;

    //std::cout << "CV_CAP_PROP_WHITE_BALANCE = "
    //          << cvGetCaptureProperty( capture, CV_CAP_PROP_WHITE_BALANCE )
    //          << std::endl;

    std::cout << "CV_CAP_PROP_RECTIFICATION = "
              << cvGetCaptureProperty( capture, CV_CAP_PROP_RECTIFICATION )
              << std::endl;

    cvReleaseCapture( &capture );

    return 0;
}
