/**
 * Exercise 5-11:
 *
 * Load an image of a scene. Use cvPyrSegmentation() and display the results.
 *
 * TODO:
 *   - How to assure src and dst image are 8-bit???
 *
 */

#include "cv.h"
#include "highgui.h"

int main( int argc, char** argv ) {

    // Note: src and dst image must be 8-bit, of the same size, and of the same
    // number of channels (1 or 3).
    //
    // Attention:
    //   src image must be enough divisible by 2.
    IplImage* src = cvLoadImage( argv[1], CV_LOAD_IMAGE_COLOR );
    IplImage* dst = cvCreateImage( cvGetSize(src), src->depth, src->nChannels );

    CvMemStorage* storage = cvCreateMemStorage(0); // Use default block size.
    CvSeq* comp = NULL;

    cvPyrSegmentation(src,      // 8-bit source image
                      dst,      // 8-bit destination image (same size and nChannels (1 or 3) as src)
                      storage,  // OpenCV memory storage area
                      &comp,    // location for storing further information about the resulting segmentation
                      4,        // number of levels in the pyramid
                      200,      // treshold1
                      50);      // treshold2


    cvNamedWindow("Original");
    cvShowImage("Original", src);
    cvNamedWindow("cvPyrSegmentation");
    cvShowImage("cvPyrSegmentation", dst);

    cvWaitKey(0); 

    cvReleaseImage( &src );
    cvReleaseImage( &dst );
    cvDestroyWindow("Original");
    cvDestroyWindow("cvPyrSegmentation");

    return 0;

}
