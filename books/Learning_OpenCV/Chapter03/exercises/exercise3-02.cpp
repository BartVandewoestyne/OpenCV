/**
 * Exercise 3-02.
 *
 * TODO:
 *
 *   - Find out what is meant by 'type byte': how many bits should we use and
 *     should we use S(igned), U(nsigned) or F(loat)?
 */

#include <highgui.h>
#include <cv.h>

main( int argc, char* argv[] ) {


    CvMat* mat = cvCreateMat(100, 100, CV_8UC3); // TODO: should this be CV_32FC3 ???
    cvZero( mat ); // equivalent to cvSet(mat, cvScalarAll(0), 0)

    CvScalar yellow = CV_RGB(255,255,0);

    cvCircle(mat, cvPoint(50, 50), 30, yellow);

    cvNamedWindow( "Circle", CV_WINDOW_AUTOSIZE );
    cvShowImage( "Circle", mat );

    cvWaitKey(0);

    cvReleaseMat( &mat );
    cvDestroyWindow( "Circle" );

    return 0;

}
