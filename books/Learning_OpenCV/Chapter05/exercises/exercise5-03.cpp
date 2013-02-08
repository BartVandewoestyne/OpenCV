/**
 * Exercise 5-3.
 *
 * TODO:
 *   - Check if conclusions are correct.
 */

#include <cv.h>
#include <highgui.h>

void doTest(IplImage* src, const char* title, int param1, int param2, double param3, double param4)
{
    IplImage* dst = cvCreateImage( cvGetSize(src), src->depth, src->nChannels );

    cvSmooth( src, dst, CV_GAUSSIAN, param1, param2, param3, param4 );

    cvNamedWindow( title );
    cvShowImage( title, dst );

    cvWaitKey(0); 

    cvReleaseImage( &dst );
    cvDestroyWindow( title );
}


int main( int argc, char** argv ) {

    IplImage* src = cvLoadImage( argv[1] );
    cvNamedWindow( "Exercise 5-3: original" );
    cvShowImage( "Exercise 5-3: original", src );

    doTest( src, "Exercise 5-3a", 9, 9, 1, 0);
    doTest( src, "Exercise 5-3a", 9, 9, 4, 0);
    doTest( src, "Exercise 5-3a", 9, 9, 6, 0);

    // For Gaussian blur, the first two parameters give the width and height of
    // the filter window.  When setting them to 0, results will be different
    // because the size of the window will be automatically determined from the
    // value of sigma (the third parameter).
    doTest( src, "Exercise 5-3b", 0, 0, 1, 0);
    doTest( src, "Exercise 5-3b", 0, 0, 4, 0);
    doTest( src, "Exercise 5-3b", 0, 0, 6, 0);

    // Assymetric kernel with sigma_x = 1 and sigma_y = 9.
    doTest( src, "Exercise 5-3c", 0, 0, 1, 9);

    // Assymetric kernel with sigma_x = 9 and sigma_y = 1.
    doTest( src, "Exercise 5-3d", 0, 0, 9, 1);

    IplImage* dst = cvCreateImage( cvGetSize(src), src->depth, src->nChannels );
    IplImage* dst2 = cvCreateImage( cvGetSize(src), src->depth, src->nChannels );
    cvSmooth( src, dst, CV_GAUSSIAN, 0, 0, 1, 9);
    cvSmooth( dst, dst2, CV_GAUSSIAN, 0, 0, 9, 1);
    cvNamedWindow( "Exercise 5-3e");
    cvShowImage( "Exercise 5-3e", dst2 );
    cvWaitKey(0); 
    cvReleaseImage( &dst );
    cvReleaseImage( &dst2 );
    cvDestroyWindow( "Exercise 5-3e" );

    // 9-by-9 filter where sigma_x and sigma_y are automatically determined to
    // be:
    //
    //   sigma_x = (9/2-1)*0.30 + 0.80 = 1.85
    //   sigma_y = (9/2-1)*0.30 + 0.80 = 1.85
    //
    // Results are thus not the same as in part e.
    doTest( src, "Exercise 5-3f", 9, 9, 0, 0);

    cvDestroyWindow( "Exercise 5-3: original" );

    return 0;

}
