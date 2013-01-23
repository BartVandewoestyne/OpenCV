/**
 * Exercise 2-05:
 *
 *   Modify the program of exercise 4 with a slider control from Example 2-3 so
 *   that the user can dynamically vary the pyramid downsampling reduction level
 *   by factors of between 2 and 8.  You may skip writing this to disk, but you
 *   should display the results.
 *
 * TODO:
 *
 *   - Find out what exactly is meant by 'vary the pyramid downsampling
 *     reduction level by factors of between 2 and 8'.
 *
 *   - Make sure downsampling reduction level can only be varied between 2
 *     and 8 with the slider.  Now, it can still be 1 and 0.
 */

#include "cv.h"
#include "highgui.h"

int g_downsampling_reduction_level = 2;

IplImage* doPyrDown(
  IplImage* in,
  int       filter = IPL_GAUSSIAN_5x5)
{
    // Best to make sure input image is divisible by two.
    assert( in->width%2 == 0 && in->height%2 == 0 );

    IplImage* out = cvCreateImage(
        cvSize( in->width/2,
                in->height/2 ),
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

    cvCreateTrackbar(
       "Downsampling factor",
       "Exercise 2-3: original",
       &g_downsampling_reduction_level,
       8,
       NULL
    );

    IplImage* original;
    IplImage* downsampled;
    while ( ( original=cvQueryFrame(capture) ) != NULL ) {

        cvShowImage( "Exercise 2-3: original", original );

        downsampled = doPyrDown( original );
        if (g_downsampling_reduction_level > 2) {
            for (int i = 2; i <= g_downsampling_reduction_level; ++i) {
                downsampled = doPyrDown( downsampled );
            }
        }

        cvShowImage( "Exercise 2-3: downsampled", downsampled );

        char c = cvWaitKey(10);
        if ( c == 27 ) break;

    }
    cvReleaseCapture( &capture );
}
