/**
 * Exercise 5-4.
 *
 * A) It isn't black because there are small differences between the pictures.
 *
 * B) See code.
 *
 * C) See code.
 *
 * D) TODO: explain difference between cleandiff and dirtydiff.
 *
 */

#include "cv.h"
#include "highgui.h"

int main( int argc, char** argv ) {

    IplImage* src1 = cvLoadImage( argv[1] );
    IplImage* src2 = cvLoadImage( argv[2] );
    IplImage* diff12 = cvCreateImage( cvGetSize(src1), src1->depth, src1->nChannels );
    IplImage* cleandiff = cvCreateImage( cvGetSize(src1), src1->depth, src1->nChannels );
    IplImage* dirtydiff = cvCreateImage( cvGetSize(src1), src1->depth, src1->nChannels );

    cvAbsDiff(src1, src2, diff12);

    cvErode(diff12, cleandiff);
    cvDilate(cleandiff, cleandiff);

    cvDilate(diff12, dirtydiff);
    cvErode(dirtydiff, dirtydiff);

    cvNamedWindow("Exercise 5-4: |src1-src2|");
    cvShowImage("Exercise 5-4: |src1-src2|", diff12);

    cvNamedWindow("Exercise 5-4: cleandiff");
    cvShowImage("Exercise 5-4: cleandiff", cleandiff);

    cvNamedWindow("Exercise 5-4: dirtydiff");
    cvShowImage("Exercise 5-4: dirtydiff", dirtydiff);

    cvWaitKey(0); 

    cvReleaseImage( &src1 );
    cvReleaseImage( &src2 );
    cvReleaseImage( &diff12 );
    cvReleaseImage( &cleandiff );
    cvReleaseImage( &dirtydiff );

    cvDestroyWindow("Exercise 5-4: |src1-src2|");
    cvDestroyWindow("Exercise 5-4: cleandiff");
    cvDestroyWindow("Exercise 5-4: dirtydiff");

    return 0;

}
