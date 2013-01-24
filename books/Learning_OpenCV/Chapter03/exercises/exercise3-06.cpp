/**
 * Exercise 3-06.
 *
 * TODO: need to set width and height afterwards???
 */

#include <highgui.h>
#include <cv.h>

main( int argc, char* argv[] ) {

    IplImage* img = cvLoadImage( argv[1], CV_LOAD_IMAGE_COLOR );

    if ( img->width < 100 || img->height < 100 ) {
        printf("ERROR: image should be at least 100x100!\n");
        return -1;
    }

    IplImage* header1 = cvCreateImageHeader(
      cvSize(20,30), // or cvGetSize(img) and afterwards setting width and height???
      img->depth,
      img->nChannels
    );
    header1->origin = img->origin;
    header1->widthStep = img->widthStep;
    //header1->width = 20;
    //header1->height = 30;
    header1->imageData = img->imageData +
        10*img->widthStep + 5*img->nChannels;

    IplImage* header2 = cvCreateImageHeader(
      cvSize(20,30), // or cvGetSize(img) and afterwards setting width and height???
      img->depth,
      img->nChannels
    );
    header2->origin = img->origin;
    header2->widthStep = img->widthStep;
    //header2->width = 20;
    //header2->height = 30;
    header2->imageData = img->imageData +
        60*img->widthStep + 50*img->nChannels;

    cvNot(header1, header1);
    cvNot(header2, header2);

    cvNamedWindow( "Exercise 3-6", CV_WINDOW_AUTOSIZE );
    cvShowImage( "Exercise 3-6", img );

    cvWaitKey(0);

    cvReleaseImage( &header1 );
    cvReleaseImage( &header2 );
    cvReleaseImage( &img );
    cvDestroyWindow( "Exercise 3-6" );

    return 0;

}
