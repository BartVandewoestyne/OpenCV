/**
 * Exercise 3-03.
 *
 * TODO:
 *
 *   - Find out what is meant by 'type byte': how many bits should we use and
 *     should we use S(igned), U(nsigned) or F(loat)?
 */

#include <highgui.h>
#include <cv.h>
#include <stdio.h>

main( int argc, char* argv[] ) {

    cvNamedWindow( "Rectangle", CV_WINDOW_AUTOSIZE );

    CvMat* mat = cvCreateMat(100, 100, CV_8UC3);
    cvZero( mat );

    uchar* ptr = cvPtr2D( mat, 1, 1);
    printf("B: %d G: %d R: %d\n", ptr[0], ptr[1], ptr[2]);
    ptr[1] = 255;
    printf("B: %d G: %d R: %d\n", ptr[0], ptr[1], ptr[2]);

    CvScalar green = CV_RGB(0,255,0);

    cvRectangle(mat, cvPoint(20,5), cvPoint(40,20), green);

    cvShowImage( "Rectangle", mat );
    cvWaitKey(0);
    cvDestroyWindow( "Rectangle" );

    return 0;

}
