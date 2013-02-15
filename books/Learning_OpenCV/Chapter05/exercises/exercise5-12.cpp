/**
 * Exercise 5-12:
 */

#include "cv.h"
#include "highgui.h"

const int threshold_type[5] = {
    CV_THRESH_BINARY,
    CV_THRESH_BINARY_INV,
    CV_THRESH_TRUNC,
    CV_THRESH_TOZERO_INV,
    CV_THRESH_TOZERO
};

const char* threshold_type_names[5] = {
    "Threshold Binary",
    "Threshold Binary, Inverted",
    "Truncate",
    "Threshold to Zero, Inverted",
    "Threshold to Zero",
};

void show_image(IplImage* img, const char* title)
{
    cvNamedWindow(title);
    cvShowImage(title, img);
    cvWaitKey(0); 
    cvReleaseImage( &img );
    cvDestroyWindow(title);
}

void do_threshold(IplImage* src)
{
    for (int i = 0; i < 5; ++i) {

        IplImage* dst = cvCreateImage( cvGetSize(src), src->depth, src->nChannels );

        cvThreshold(
            src,
            dst,
            128,
            255,
            threshold_type[i]
        );

        char title[50];
        sprintf(title, "Normal threshold, %s", threshold_type_names[i]);
        show_image(dst, title);

    }
}

void do_adaptive_threshold(IplImage* src, double param1)
{
    for (int i = 0; i < 2; ++i) {

        IplImage* dst = cvCreateImage( cvGetSize(src), src->depth, src->nChannels );

        cvAdaptiveThreshold(
            src,
            dst,
            255,                        // max_val
            CV_ADAPTIVE_THRESH_MEAN_C,  // adaptive method
            threshold_type[i],          // threshold type
            3,                          // block size
            param1                      // a certain constant
        );

        char title[50];
        sprintf(title, "Adaptive threshold, %s, %f", threshold_type_names[i], param1);
        show_image(dst, title);

    }
}


int main( int argc, char** argv ) {

    // The cvThreshold() function handles only 8-bit or floating-point
    // grayscale source images. The destination image must either match the source
    // image or be an 8-bit image.
    IplImage* src = cvLoadImage( argv[1], CV_LOAD_IMAGE_GRAYSCALE );
    cvNamedWindow("Original image");
    cvShowImage("Original image", src);

    do_threshold(src);
    do_adaptive_threshold(src,  5);
    do_adaptive_threshold(src,  0);
    do_adaptive_threshold(src, -5);

    cvReleaseImage( &src );
    cvDestroyWindow("Original image");

    return 0;

}
