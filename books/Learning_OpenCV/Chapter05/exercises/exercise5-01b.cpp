/**
 * Exercise 5-1b.
 */

#include <cv.h>
#include <highgui.h>

int main( int argc, char* argv[] ) {

    IplImage* src = cvLoadImage( argv[1] );
    IplImage* dst1 = cvCreateImage( cvGetSize(src), src->depth, src->nChannels );
    IplImage* dst2 = cvCreateImage( cvGetSize(src), src->depth, src->nChannels );

    cvNamedWindow( "Original", CV_WINDOW_AUTOSIZE );
    cvNamedWindow( "Twice with 5 by 5", CV_WINDOW_AUTOSIZE );
    cvNamedWindow( "Once with 11 by 11", CV_WINDOW_AUTOSIZE );

    cvSmooth( src, dst1, CV_GAUSSIAN, 5, 5 );
    cvSmooth( dst1, dst1, CV_GAUSSIAN, 5, 5 );

    cvSmooth( src, dst2, CV_GAUSSIAN, 11, 11 );

    cvShowImage( "Original", src );
    cvShowImage( "Twice with 5 by 5", dst1 );
    cvShowImage( "Once with 11 by 11", dst2 );

    cvWaitKey();

    cvReleaseImage( &src );
    cvReleaseImage( &dst1 );
    cvReleaseImage( &dst2 );

    cvDestroyWindow( "Original" );
    cvDestroyWindow( "Twice with 5 by 5" );
    cvDestroyWindow( "Once with 11 by 11" );

    return 0;
}
