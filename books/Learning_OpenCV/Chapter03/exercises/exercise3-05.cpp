/**
 * Exercise 3-05.
 *
 * TODO:
 *
 *   - What should be the depth of the IplImage for a 'single-channel byte
 *     image'?
 */

#include <highgui.h>
#include <cv.h>

main( int argc, char* argv[] ) {

    cvNamedWindow( "ROI", CV_WINDOW_AUTOSIZE );

    IplImage* img = cvCreateImage( cvSize(210,210), IPL_DEPTH_8U, 1 );
    cvSetZero( img );

    for (int x = 10; x <= 100; x += 10) {

      int width = 210 - 2*x;
      int height = width;
      int val = 2*x;
      CvScalar value = cvScalar( val, val, val );

      cvSetImageROI( img, cvRect( x, x, width, height) );
      cvSet( img, value );
      cvResetImageROI( img );

    }

    cvShowImage( "ROI", img );
    cvWaitKey(0);
    cvDestroyWindow( "ROI" );

    return 0;

}
