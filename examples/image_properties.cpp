/**
 * Print out all image properties for a specified mage file.
 *
 * TODO: finish this!
 */

#include "cv.h"
#include "highgui.h"
#include <stdio.h>

int main( int argc, char* argv[] ) {

    CvCapture* capture = cvCreateFileCapture( argv[1] );
    IplImage* img = cvLoadImage( argv[1], CV_LOAD_IMAGE_ANYDEPTH)

    // TODO: print properties!!!

    cvReleaseImage( &img );

    return 0;
}
