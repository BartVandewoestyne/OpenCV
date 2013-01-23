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

    // TODO

}
