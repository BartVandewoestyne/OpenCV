/**
 * Exercise 4-4.
 *
 * TODO:
 *  - Slider to control position in video should be in 10 increments.
 *  - Pause-unpause button/slider.
 */

#include <cv.h>
#include <highgui.h>
#include <stdio.h>

int g_slider_position = 0;
CvCapture* g_capture = NULL;

void onTrackbarSlide(int pos) {
    cvSetCaptureProperty(
        g_capture,
        CV_CAP_PROP_POS_FRAMES,
        pos
    );
}

int main( int argc, char* argv[] ) {

    cvNamedWindow( "Exercise 4-4", CV_WINDOW_AUTOSIZE );

    g_capture = cvCreateFileCapture( argv[1] );
    int nbFrames = (int) cvGetCaptureProperty(
                             g_capture,
                             CV_CAP_PROP_FRAME_COUNT
                         );
    std::cout << "Movie has " << nbFrames << " frames." << std::endl;

    if ( nbFrames != 0 )
    {
        cvCreateTrackbar(
            "Frame",
            "Exercise 4-4",
            &g_slider_position,
            nbFrames,
            onTrackbarSlide
        );
    }
    IplImage* frame;

    while (1)
    {
        frame = cvQueryFrame( g_capture );
        if (!frame) break;

        g_slider_position += 1;
        cvSetTrackbarPos("Frame", "Exercise 4-4", g_slider_position);

        cvShowImage( "Exercise 4-4", frame );
        char c = cvWaitKey(33);
        if ( c==27 ) break;

    }

    cvReleaseCapture( &g_capture );
    cvDestroyWindow( "Exercise 4-4" );

    return 0;
}
