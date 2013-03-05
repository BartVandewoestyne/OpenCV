/**
 * Exercise 5-5.
 */

#include <cstdlib>
#include <iostream>
#include "cv.h"
#include "highgui.h"
using namespace std;

int main( int argc, char** argv )
{
    IplImage* src1 = cvLoadImage( argv[1], CV_LOAD_IMAGE_GRAYSCALE );
    IplImage* src2 = cvLoadImage( argv[2], CV_LOAD_IMAGE_GRAYSCALE );

    IplImage* diff12 = cvCreateImage( cvGetSize(src1), src1->depth, src1->nChannels );
    cvAbsDiff(src1, src2, diff12);

    double threshold = (double)atof(argv[3]); // Play with values in [0,255].
    IplImage* thresh = cvCreateImage( cvGetSize(src1), src1->depth, src1->nChannels );
    cvThreshold(diff12, thresh, threshold, 255.0, CV_THRESH_BINARY); // 0 = black, 255 = white

    // In the case of opening, we erode first and then dilate
    // Opening is often used to count regions in a binary image. For example, if we have
    // thresholded an image of cells on a microscope slide, we might use opening to separate
    // out cells that are near each other before counting the regions.
    IplImage* mop_opened = cvCreateImage( cvGetSize(src1), src1->depth, src1->nChannels);
    cvMorphologyEx(
            thresh,
            mop_opened,
            NULL,
            NULL,
            CV_MOP_OPEN);

    cvNamedWindow("Exercise 5-5: |src1-src2|");
    cvShowImage("Exercise 5-5: |src1-src2|", diff12);
    cvNamedWindow("Exercise 5-5: thresholded");
    cvShowImage("Exercise 5-5: thresholded", thresh);
    cvNamedWindow("Exercise 5-5: opened");
    cvShowImage("Exercise 5-5: opened", mop_opened);

    cvWaitKey(0); 

    cvReleaseImage( &src1 );
    cvReleaseImage( &src2 );
    cvReleaseImage( &diff12 );
    cvReleaseImage( &thresh );
    cvDestroyWindow("Exercise 5-5: |src1-src2|");
    cvDestroyWindow("Exercise 5-5: thresholded");
    cvDestroyWindow("Exercise 5-5: opened");

    return 0;
}
