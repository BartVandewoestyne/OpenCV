/**
 * Exercise 3-04.
 *
 * TODO:
 *
 *   - What should be the type of the matrix elements for a 'three-channel RGB
 *     image'?
 *   - There still seems something wrong.  The rectangle's coordinates are not
 *     correct.
 */

#include <highgui.h>
#include <cv.h>

main( int argc, char* argv[] ) {

    cvNamedWindow( "Square", CV_WINDOW_AUTOSIZE );

    CvMat* mat = cvCreateMat(100, 100, CV_8UC3); // TODO: check if type is correct
    cvSetZero( mat );

    for (int row=20; row < 40; row++) {
        uchar *ptr = (uchar*)(mat->data.ptr + row*mat->step);
        ptr++;
        for (int col=5; col < 20; col++) {
            *ptr = 255;
            ptr += 3;
        }
    }

    cvShowImage( "Square", mat );
    cvWaitKey(0);
    cvDestroyWindow( "Square" );

    return 0;

}
