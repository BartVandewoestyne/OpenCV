/**
 * Exercise 3-03.
 *
 * TODO:
 *
 *   - Find out what is meant by 'type byte': how many bits should we use and
 *     should we use S(igned), U(nsigned) or F(loat)?
 *
 *   - Check if there is an off-by-one error.
 */

#include <highgui.h>
#include <cv.h>
#include <stdio.h>

main( int argc, char* argv[] ) {

    // TODO: should this be CV_8UC3 or CV_32FC3?
    CvMat* mat = cvCreateMat(100, 100, CV_32FC3);
    //CvMat* mat = cvCreateMat(100, 100, CV_8UC3);

    cvZero( mat );  // equivalent to cvSet( mat, cvScalarAll(0), 0 );

    // A small test.
    uchar* ptr = cvPtr2D( mat, 1, 1);
    printf("B: %d G: %d R: %d\n", ptr[0], ptr[1], ptr[2]);
    ptr[1] = 255;
    printf("B: %d G: %d R: %d\n", ptr[0], ptr[1], ptr[2]);

    // The hard way.
    // TODO: change cast to uchar* or float*, depending on whether CV_8UC3 or CV_32FC3 was chosen.
    for ( int rows = 5; rows <= 20; ++rows ) {
        for ( int cols = 20; cols <= 40; ++cols ) {
            float* ptr = (float*)cvPtr2D( mat, rows, cols );
            //uchar* ptr = (uchar*)cvPtr2D( mat, rows, cols );
            ptr[1] = 255;
        }
    }

    // The easy way (we draw this one in red).
    CvScalar green = CV_RGB(255,0,0);
    cvRectangle(mat, cvPoint(20,5), cvPoint(40,20), green);

    cvNamedWindow( "Rectangle", CV_WINDOW_AUTOSIZE );
    cvShowImage( "Rectangle", mat );

    cvWaitKey(0);

    cvReleaseMat( &mat );
    cvDestroyWindow( "Rectangle" );

    return 0;

}
