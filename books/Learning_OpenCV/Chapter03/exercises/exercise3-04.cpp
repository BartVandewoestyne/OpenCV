/**
 * Exercise 3-04.
 *
 * TODO:
 *
 *   - What should be the depth of the image for a 'three-channel RGB image'?
 *   - There still seems something wrong.  The rectangle's coordinates are not
 *     correct.
 */

#include <highgui.h>
#include <cv.h>

main( int argc, char* argv[] ) {


    IplImage* img = cvCreateImage(
      cvSize(100, 100),
      //IPL_DEPTH_32F, // TODO: is this correct???
      IPL_DEPTH_8U, // TODO: is this correct???
      3
    );
    cvZero( img );

    for (int col=5; col < 20; col++) {
        uchar *ptr = (uchar*)(img->imageDataOrigin + col*img->widthStep);
        ptr++;
        for (int row=20; row < 40; row++) {
            *(ptr+20*3) = 255;
            ptr += 3;
        }
    }

    cvNamedWindow( "Square", CV_WINDOW_AUTOSIZE );
    cvShowImage( "Square", img );

    cvWaitKey(0);

    cvReleaseImage( &img );
    cvDestroyWindow( "Square" );

    return 0;

}
