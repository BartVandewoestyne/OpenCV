/**
 * Exercise 2-03:
 *
 *   Read from a camera and store downsampled color images to disk.
 */

#include "cv.h"
#include "highgui.h"
#include <stdio.h>


IplImage* doPyrDown(
  IplImage* in,
  int       filter = IPL_GAUSSIAN_5x5)
{
    // Best to make sure input image is divisible by two.
    assert( in->width%2 == 0 && in->height%2 == 0 );

    IplImage* out = cvCreateImage(
        cvSize( in->width/2, in->height/2 ),
        in->depth,
        in->nChannels
    );
    cvPyrDown( in, out );
    return( out );
};


main( int argc, char* argv[] ) {

    cvNamedWindow( "Exercise 2-3: original", CV_WINDOW_AUTOSIZE );
    cvNamedWindow( "Exercise 2-3: downsampled", CV_WINDOW_AUTOSIZE );

    CvCapture* capture = cvCreateCameraCapture( 0 );
    if (!capture) {
        return -1;
    }

    IplImage* original;
    IplImage* downsampled;
    while ( ( original=cvQueryFrame(capture) ) != NULL ) {

        cvShowImage( "Exercise 2-3: original", original );

        downsampled = doPyrDown( original );
        cvShowImage( "Exercise 2-3: downsampled", downsampled );

        char c = cvWaitKey(10);
        if ( c == 'p' ) {
            printf("Writing downsampled image to file.\n");
            cvSaveImage( "downsampled.jpg", downsampled );
        }
        if ( c == 27 ) break;

    }
    cvReleaseCapture( &capture );
}
