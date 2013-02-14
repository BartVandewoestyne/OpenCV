/**
 * Exercise 5-10.
 *
 * TODO:
 *   - How are the two results different?  Why are the approaches different?
 *     Answer: to me, it LOOKS like the image using cvResize is sharper than the
 *     one with cvPyrDown???
 */

#include "cv.h"
#include "highgui.h"


bool is_resizeable( IplImage* img, int nbTimes ) {

    int width = img->width;
    int height = img->height;
    printf("width = %d\n", width);
    printf("height = %d\n", height);

    for ( int i = 0; i < nbTimes; ++i ) {
        if ( width % 2 || height % 2 ) {
          return false;
        } else {
          width /= 2;
          height /= 2;
        }
    }
    return true;

}


int main( int argc, char** argv ) {

    IplImage* src = cvLoadImage( argv[1] );

    int nbTimes = 3;

    if ( !is_resizeable(src, nbTimes) ) {
      printf("ERROR: image is not resizeable %d times!\n", nbTimes);
      exit(-1);
    }

    IplImage* dst_resized;
    IplImage* dst_pyrdown;
    IplImage* dst_resized_old = cvCloneImage(src);
    IplImage* dst_pyrdown_old = cvCloneImage(src);

    for (int i = 1; i <= nbTimes; ++i ) {

        dst_resized = cvCreateImage( cvSize(dst_resized_old->width/2, dst_resized_old->height/2), dst_resized_old->depth, dst_resized_old->nChannels );
        dst_pyrdown = cvCreateImage( cvSize(dst_pyrdown_old->width/2, dst_pyrdown_old->height/2), dst_pyrdown_old->depth, dst_pyrdown_old->nChannels );
        cvResize(dst_resized_old, dst_resized);
        cvPyrDown(dst_pyrdown_old, dst_pyrdown);

        cvReleaseImage(&dst_resized_old);
        cvReleaseImage(&dst_pyrdown_old);
        dst_resized_old = cvCloneImage(dst_resized);
        dst_pyrdown_old = cvCloneImage(dst_pyrdown);

    }

    cvNamedWindow("Original");
    cvShowImage("Original", src);

    cvNamedWindow("cvResize");
    cvShowImage("cvResize", dst_resized);

    cvNamedWindow("cvPyrDown");
    cvShowImage("cvPyrDown", dst_pyrdown);

    cvWaitKey(0); 

    cvReleaseImage( &src );
    cvReleaseImage( &dst_resized );
    cvReleaseImage( &dst_pyrdown );
    cvReleaseImage( &dst_resized_old );
    cvReleaseImage( &dst_pyrdown_old );

    cvDestroyWindow("Original");
    cvDestroyWindow("cvResize");
    cvDestroyWindow("cvPyrDown");

    return 0;

}
