#include "cv.h"
#include "highgui.h"

int main( int argc, char** argv ) { 
    cvNamedWindow( "Example2_9", CV_WINDOW_AUTOSIZE );
    CvCapture* capture;
    if (argc==1) {
        capture = cvCreateCameraCapture( 0 );
    } else {
        capture = cvCreateFileCapture( argv[1] );
    }
    assert( capture != NULL );

    IplImage* frame;
    while(1) {
        frame = cvQueryFrame( capture );
        if( !frame ) break;
        cvShowImage( "Example2_9", frame );
        char c = cvWaitKey(10);
        if( c == 27 ) break;
    }
    cvReleaseCapture( &capture );
    cvDestroyWindow( "Example2_9" );
}
