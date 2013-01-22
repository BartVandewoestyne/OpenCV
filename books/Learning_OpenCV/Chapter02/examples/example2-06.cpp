#include "cv.h"
#include "highgui.h"

IplImage* doCanny(
    IplImage* in,
    double    lowThresh,
    double    highThresh,
    double    aperture)
{
    if (in->nChannels != 1)
        return(0); // Canny only handles gray scale images
    IplImage* out = cvCreateImage( 
        cvGetSize( in ),
        in->depth, //IPL_DEPTH_8U,    
        1);
    cvCanny( in, out, lowThresh, highThresh, aperture );
    return( out );
};

int main( int argc, char** argv )
{
  IplImage* img_rgb = cvLoadImage( argv[1] );
  IplImage* img_gry = cvCreateImage( cvSize( img_rgb->width,img_rgb->height ), img_rgb->depth, 1);
  cvCvtColor(img_rgb, img_gry ,CV_BGR2GRAY);
  cvNamedWindow("Example Gray", CV_WINDOW_AUTOSIZE );
  cvNamedWindow("Example Canny", CV_WINDOW_AUTOSIZE );
  cvShowImage("Example Gray", img_gry );
  IplImage* img_cny = doCanny( img_gry, 10, 100, 3 );
  cvShowImage("Example Canny", img_cny );
  cvWaitKey(0);
  cvReleaseImage( &img_rgb);
  cvReleaseImage( &img_gry);
  cvReleaseImage( &img_cny);
  cvDestroyWindow("Example Gray");
  cvDestroyWindow("Example Canny");
}
