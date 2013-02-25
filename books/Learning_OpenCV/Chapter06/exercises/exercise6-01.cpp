/**
 * References:
 *
 *   [1] http://tech.groups.yahoo.com/group/OpenCV/message/74329
 *   [2] http://stackoverflow.com/questions/15059650/scan-picture-and-detect-lines
 *   [3] http://answers.opencv.org/question/8026/line-detection/
 *   [4] http://en.wikipedia.org/wiki/Steerable_filter
 *
 * TODO: get this working!
 */

#include "cv.h"
#include "highgui.h"

int main(int argc, char** argv)
{
    IplImage* src = cvLoadImage(argv[1]);

    cvNamedWindow("src", 1);
    cvShowImage("src", src);
    
    float R60[] = {
        -0.5, -0.5, -0.5,  2.0, -0.5,
         0.0,  0.0,  0.0,  0.0,  0.0,
         0.0,  0.0,  0.0,  0.0,  0.0,
         0.0,  0.0,  0.0,  0.0,  0.0,
        -0.5,  2.0, -0.5, -0.5, -0.5};
    
    CvMat* rgbMat = cvCreateMat(5, 5, CV_32FC1);
    for (int y = 0; y < 5; y++)
    {
        for (int x = 0; x < 5; x++)
            cvmSet(rgbMat, y, x, R60[y*5 + x]);
    }
    
    IplImage* dstRGB[3];
    IplImage* rgb[3];
    for (int i = 0; i < 3; i++)
    {
        rgb[i] = cvCreateImage(cvSize(src->width, src->height), src->depth, 1);
        dstRGB[i] = cvCreateImage(cvSize(src->width, src->height), src->depth, 1);
    }
    
    cvSplit(src, rgb[0], rgb[1], rgb[2], NULL);
    
    for (int i = 0; i < 3; i++)
    {
        cvFilter2D(rgb[i], dstRGB[i], rgbMat);
    }

    cvReleaseMat(&rgbMat);
    
    IplImage* dst = cvCreateImage(cvSize(src->width, src->height), src->depth, 3);
    cvMerge(dstRGB[0], dstRGB[1], dstRGB[2], NULL, dst);
    
    cvNamedWindow("dst", 1);
    cvShowImage("dst", dst);
    
    cvReleaseImage(&dst);
    
    for (int i = 0; i < 3; i++)
    {
        cvReleaseImage(&rgb[i]);
        cvReleaseImage(&dstRGB[i]);
    }
    
    cvWaitKey(0);
    
    cvReleaseImage(&src);
    
    cvDestroyWindow("src");
    cvDestroyWindow("dst");
}
