/**
 * Test program that illustrates a problem with creating videos.
 *
 * PROBLEM:
 *   - With OpenCV 2.3.1 on Ubuntu 12.10 using a CvSize of 262x720 results in an
 *     incorrect video.
 */

#include "cv.h"
#include "highgui.h"


void setPixel(IplImage* img, unsigned int X, unsigned int Y, int col)
{
    if (img->nChannels == 1)
    {
        ((uchar*)(img->imageData + img->widthStep*Y))[X] = col;
    }
    else if (img->nChannels == 3)
    {
        ((uchar*)(img->imageData + img->widthStep*Y))[X*3] = col;
        ((uchar*)(img->imageData + img->widthStep*Y))[X*3 + 1] = col;
        ((uchar*)(img->imageData + img->widthStep*Y))[X*3 + 2] = col;
    }
}


int main( int argc, char* argv[] ) {

    CvSize mySize = cvSize(262, 720);    // Gives a tilted line video with OpenCV 2.3, but works with OpenCV 2.4.
    //CvSize mySize = cvSize(264, 720);  // Works (maybe because 264 is a multiple of 4???).

    CvVideoWriter* writer = cvCreateVideoWriter(
        "test.avi",
        CV_FOURCC('P','I','M','1'),
        25,
        mySize
    );

    // Fill image with a vertical growing line.
    IplImage* img = cvCreateImage(mySize, IPL_DEPTH_8U, 3);
    for (int y = 1; y <= 700; ++y)
    {
        setPixel(img, 100, y, 125);
        cvWriteFrame(writer, img);
    }

    // Show last added frame.
    cvNamedWindow("Test", CV_WINDOW_AUTOSIZE);
    cvShowImage("Test", img);
    cvWaitKey(0);

    cvReleaseVideoWriter( &writer );
    cvReleaseImage( &img );
    cvDestroyWindow("Test");

    return 0;
}
