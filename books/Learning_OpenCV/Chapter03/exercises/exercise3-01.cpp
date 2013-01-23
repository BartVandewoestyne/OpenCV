/**
 * Exercise 3-01.
 *
 * TODO: Finish this exercise!
 */

#include "cv.h"
#include <stdio.h>

main( int argc, char* argv[] ) {

    // Choose a negative floating point number.  Take its absolute value,
    // round it, and then take its ceiling and floor.
    double a = -1.23;
    // TODO: how to take absolute value?
    printf( "cvRound(a) = %d\n", cvRound(a) );
    printf( "cvCeil(a) = %d\n", cvCeil(a) );
    printf( "cvFloor(a) = %d\n", cvFloor(a) );


    // Generate some random numbers.
    CvRNG rngState = cvRNG(-1);
    printf( "%u\n", cvRandInt( &rngState ) );
    printf( "%f\n", cvRandReal( &rngState ) );

    // Create a floating point CvPoint2D32f and convert it to an integer
    // CvPoint.
    CvPoint2D32f point_float1 = cvPoint2D32f(1.0, 2.0);
    CvPoint point_int1 = cvPointFrom32f( point_float1 );

    // Convert a CvPoint to a CvPoint2D32f.
    CvPoint point_int2 = cvPoint(3, 4);
    CvPoint2D32f point_float2 = cvPointTo32f( point_int2 );

}
