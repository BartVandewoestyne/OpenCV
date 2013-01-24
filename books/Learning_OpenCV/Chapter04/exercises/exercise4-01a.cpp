/**
 * Exercise 4-01.
 */

#include "cv.h"
#include "highgui.h"

int main( int argc, char* argv[] ) {

    CvCapture* capture = NULL;
    if (argc >= 2) {
      capture = cvCreateFileCapture( argv[1] );
    } else {
      capture = cvCreateCameraCapture( 0 );
    }

    cvNamedWindow( "Original", CV_WINDOW_AUTOSIZE );
    cvNamedWindow( "Grayscale", CV_WINDOW_AUTOSIZE );
    cvNamedWindow( "Canny edge detection", CV_WINDOW_AUTOSIZE );

    IplImage* frame = NULL;
    IplImage* frame_gray = NULL;
    IplImage* frame_edges = NULL;
    while (1) {

        frame = cvQueryFrame(capture);
        if (!frame) break;

        cvShowImage( "Original", frame );

        // Turn to grayscale;
        frame_gray = cvCreateImage( cvGetSize(frame), frame->depth, 1 );
        cvCvtColor(frame, frame_gray, CV_RGB2GRAY);
        cvSmooth( frame_gray, frame_gray, CV_GAUSSIAN, 5); // TODO: is this really necessary???
        cvShowImage( "Grayscale", frame_gray );

        // Perform Canny edge detection;
        frame_edges = cvCreateImage( cvGetSize(frame), frame->depth, 1 );
        cvCanny( frame_gray, frame_edges, 10, 100, 3 );
        cvShowImage( "Canny edge detection", frame_edges );

        char c = cvWaitKey(33);
        if ( c == 27 ) break;

    }

    cvReleaseImage( &frame );
    cvReleaseImage( &frame_gray );
    cvReleaseImage( &frame_edges );
    cvReleaseCapture( &capture );
    cvDestroyWindow( "Original" );
    cvDestroyWindow( "Grayscale" );
    cvDestroyWindow( "Canny edge detection" );

    return 0;

}
