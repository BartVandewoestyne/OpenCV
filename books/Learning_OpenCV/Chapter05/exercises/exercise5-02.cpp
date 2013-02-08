/**
 * Exercise 5-02.
 *
 * TODO:
 *   - What should we observe here???
 */

#include <cv.h>
#include <highgui.h>

int main( int argc, char* argv[] ) {

    IplImage* img = cvCreateImage( cvSize(100, 100), IPL_DEPTH_8U, 1 );
    cvSetZero(img);
    IplImage* img_smoothed_5x5       = cvCreateImage( cvGetSize(img), img->depth, img->nChannels );
    IplImage* img_smoothed_5x5_twice = cvCreateImage( cvGetSize(img), img->depth, img->nChannels );
    IplImage* img_smoothed_9x9       = cvCreateImage( cvGetSize(img), img->depth, img->nChannels );

    int row = 50;
    int col = 50;
    ((uchar*)(img->imageData + img->widthStep*row))[col] = 255;

    cvSmooth( img,              img_smoothed_5x5,       CV_GAUSSIAN, 5, 5 );
    cvSmooth( img_smoothed_5x5, img_smoothed_5x5_twice, CV_GAUSSIAN, 5, 5 );
    cvSmooth( img,              img_smoothed_9x9,       CV_GAUSSIAN, 9, 9 );

    cvNamedWindow( "Exercise 5-2: original",  CV_WINDOW_AUTOSIZE );
    cvNamedWindow( "Exercise 5-2: 5x5",       CV_WINDOW_AUTOSIZE );
    cvNamedWindow( "Exercise 5-2: 5x5 twice", CV_WINDOW_AUTOSIZE );
    cvNamedWindow( "Exercise 5-2: 9x9",       CV_WINDOW_AUTOSIZE );

    cvShowImage( "Exercise 5-2: original",  img );
    cvShowImage( "Exercise 5-2: 5x5",       img_smoothed_5x5 );
    cvShowImage( "Exercise 5-2: 5x5 twice", img_smoothed_5x5_twice );
    cvShowImage( "Exercise 5-2: 9x9",       img_smoothed_9x9 );

    cvWaitKey(0);

    cvReleaseImage( &img );
    cvReleaseImage( &img_smoothed_5x5 );
    cvReleaseImage( &img_smoothed_5x5_twice );
    cvReleaseImage( &img_smoothed_9x9 );

    cvDestroyWindow( "Exercise 5-2: original" );
    cvDestroyWindow( "Exercise 5-2: 5x5" );
    cvDestroyWindow( "Exercise 5-2: 5x5 twice" );
    cvDestroyWindow( "Exercise 5-2: 9x9" );

    return 0;

}
