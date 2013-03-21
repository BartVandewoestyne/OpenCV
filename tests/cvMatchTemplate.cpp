#include <cv.h>
#include <highgui.h>
#include <iostream>

void setPixel(IplImage* img, int x, int y, int color)
{
    if (img->nChannels == 1)
    {
        ((uchar*)(img->imageData + img->widthStep*y))[x] = color;
    }
    else if (img->nChannels == 3)
    {
        ((uchar*)(img->imageData + img->widthStep*y))[x*3] = color;
        ((uchar*)(img->imageData + img->widthStep*y))[x*3 + 1] = color;
        ((uchar*)(img->imageData + img->widthStep*y))[x*3 + 2] = color;
    }
}


int getIntPixel(IplImage* img, int x, int y)
{
    // Assuming 1 channel!!!
    return (img->imageData + img->widthStep*y)[x];
}


float getFloatPixel(IplImage* img, int x, int y)
{
    // Assuming 1 channel!!!
    return (img->imageData + img->widthStep*y)[x];
}


void printVector(IplImage* img, int nbSamples, int type)
{
    for (int i = 0; i < nbSamples; ++i)
    {
      if (type == 0) {
          std::cout << getIntPixel(img, 0, i) << " ";
      } else {
          std::cout << getFloatPixel(img, 0, i) << " ";
      }
    }
    std::cout << std::endl;
}


int main(int argc, char *argv[])
{
    int nbSamples = 10;

    CvSize sizeLine     = cvSize(1,nbSamples);
    CvSize sizeTemplate = cvSize(1,3);

    IplImage* line  = cvCreateImage(sizeLine,     IPL_DEPTH_8U, 1);
    IplImage* templ = cvCreateImage(sizeTemplate, IPL_DEPTH_8U, 1);
    cvZero(line);
    cvZero(templ);
    setPixel(line, 0, 3, 1);
    setPixel(templ, 0, 1, 1);

    printVector(line, sizeLine.height, 0);
    printVector(templ, sizeTemplate.height, 0);

    /* create new image for template matching computation */
    CvSize resSize = cvSize(1, sizeLine.height - sizeTemplate.height + 1);
    IplImage* res = cvCreateImage( resSize, IPL_DEPTH_32F, 1 );
    cvZero(res);

    //cvMatchTemplate( line, templ, res, CV_TM_SQDIFF );
    cvMatchTemplate( line, templ, res, CV_TM_CCORR );
    printVector(res, sizeLine.height - sizeTemplate.height + 1, 1);

    double minval;
    double maxval;
    CvPoint minloc;
    CvPoint maxloc;
    cvMinMaxLoc( res, &minval, &maxval, &minloc, &maxloc, 0 );

    std::cout << "minval = " << minval << std::endl;
    std::cout << "maxval = " << maxval << std::endl;
    std::cout << "minloc = (" << minloc.x << ", " << minloc.y << ")"  << std::endl;
    std::cout << "maxloc = (" << maxloc.x << ", " << maxloc.y << ")"  << std::endl;

    cvNamedWindow("Line 1", CV_WINDOW_AUTOSIZE);
    cvNamedWindow("Line 2", CV_WINDOW_AUTOSIZE);
    cvNamedWindow("Correlation", CV_WINDOW_AUTOSIZE);

    cvShowImage("Line 1", line);
    cvShowImage("Line 2", templ);
    cvShowImage("Correlation", res);

    cvWaitKey(0);

    return 0;
}
