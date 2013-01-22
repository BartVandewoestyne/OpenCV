#include <stdio.h>
#include <cv.h>
#include <highgui.h>

void saturate_sv( IplImage* img ) {

  for( int y=0; y<img->height; y++ ) {
    uchar* ptr = (uchar*) (
      img->imageData + y * img->widthStep 
    );
    for( int x=0; x<img->width; x++ ) {
      ptr[3*x+1] = 255;
      ptr[3*x+2] = 255;
    }
  }
}

int main( int argc, char** argv )
{
  IplImage* img = cvLoadImage( argv[1] );
  cvNamedWindow("Example1", CV_WINDOW_AUTOSIZE );
  saturate_sv(img);
  cvShowImage("Example1", img );
  cvWaitKey(0);
  cvReleaseImage( &img );
  cvDestroyWindow("Example1");
}
