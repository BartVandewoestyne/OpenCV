/**
 * Exercise 5-01.
 */

#include <cv.h>
#include <highgui.h>
#include <stdio.h>

int main( int argc, char* argv[] ) {

    IplImage* img = cvLoadImage( argv[1], CV_LOAD_IMAGE_COLOR );
    cvNamedWindow( "Original", CV_WINDOW_AUTOSIZE );
    cvShowImage( "Original", img );

    IplImage* img_smoothed = cvCreateImage( cvGetSize(img), img->depth, img->nChannels );
    char windowtitle[50];
    for (int s=3; s<=11; s+=2) {

        cvSmooth( img, img_smoothed, CV_GAUSSIAN, s, s );

        sprintf(windowtitle, "Smoothed with %d by %d window", s, s);
        cvNamedWindow( windowtitle, CV_WINDOW_AUTOSIZE );
        cvShowImage( windowtitle, img_smoothed );

        cvWaitKey(0);

        cvDestroyWindow( windowtitle );

    }

    cvReleaseImage( &img );
    cvReleaseImage( &img_smoothed );
    cvDestroyWindow( "Original" );

    return 0;

}
