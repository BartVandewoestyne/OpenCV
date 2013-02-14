/**
 * Exercise 5-9.
 *
 * TODO:
 *   - Understand this exercise.
 */

#include <cv.h>
#include <highgui.h>

int main( int argc, char* argv[] ) {

    // Load an image of a scene and convert it to grayscale.
    IplImage* src = cvLoadImage( argv[1], CV_LOAD_IMAGE_GRAYSCALE );

    // Run the morphological Top Hat operation on your image and display the
    // results.
    IplImage* dst_a = cvCloneImage(src);
    cvMorphologyEx(src, dst_a, NULL, NULL, CV_MOP_TOPHAT, 1);

    // Convert the resulting image into an 8-bit mask.
    // TODO: understand this!
    IplImage *dst_b = cvCreateImage( cvSize(dst_a->width, dst_a->height), IPL_DEPTH_8U, 1 );
    cvCopy( dst_a, dst_b );
    cvThreshold( dst_b, dst_b, 25, 255, CV_THRESH_BINARY );

    // Copy a grayscale value into the Top Hat pieces and display the results.
    // TODO: understand this!
    IplImage *img_black = cvCreateImage( cvSize(src->width, src->height), IPL_DEPTH_8U, 1 );
    IplImage *dst_c     = cvCreateImage( cvSize(src->width, src->height), IPL_DEPTH_8U, 1 );
    cvZero( img_black );
    cvSet( dst_c, cvScalarAll(200) );
    cvCopy( img_black, dst_c, dst_b );

    cvNamedWindow( "Original", CV_WINDOW_AUTOSIZE );
    cvNamedWindow( "Top Hat", CV_WINDOW_AUTOSIZE );
    cvNamedWindow( "8-bit mask", CV_WINDOW_AUTOSIZE );
    cvNamedWindow( "Grayscale value copied into Top Hat pieces", CV_WINDOW_AUTOSIZE );
    cvShowImage( "Original", src );
    cvShowImage( "Top Hat", dst_a );
    cvShowImage( "8-bit mask", dst_b );
    cvShowImage( "Grayscale value copied into Top Hat pieces", dst_c );

    cvWaitKey(0);

    cvReleaseImage( &src );
    cvReleaseImage( &dst_a );
    cvReleaseImage( &dst_b );
    cvDestroyWindow( "Original" );
    cvDestroyWindow( "Top Hat" );
    cvDestroyWindow( "8-bit mask" );
    cvDestroyWindow( "Grayscale value copied into Top Hat pieces" );

    return 0;

}
