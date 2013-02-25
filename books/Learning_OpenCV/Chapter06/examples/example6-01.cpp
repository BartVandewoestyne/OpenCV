//
// example 6-1 Hough circles
//
//
/*
You'll have to tune to detect the circles you expect
vSeq* cvHoughCircles( 
  CvArr* image,       // Da image
  void* storage,      // Storage for sequences
  int method,         // Always CV_HOUGH_GRADIENT until you, reader, invent a better method
  double dp,          // Hough space shrinkage. a bit larger is faster, might detect better,
  double min_dist,    // Damps out multiple detection in the same area
  double param1=100,  // High Canny threshold (edge thresh), low is half (link finding). See Canny
  double param2=100,  // Threshold where we declare detection in Canny space
  int min_radius=0,   // Smallest circle to find
  int max_radius=0    // Largest circle to find
  );
*/


#include <cv.h>
#include <highgui.h>
#include <math.h>

int main(int argc, char** argv) {

    IplImage* image = cvLoadImage( 
      argv[1],
      CV_LOAD_IMAGE_GRAYSCALE
    );
    IplImage* src = cvLoadImage( argv[1] ); // Changed for prettier show in color.
    CvMemStorage* storage = cvCreateMemStorage(0);
    cvSmooth( image, image, CV_GAUSSIAN, 5, 5 );
    CvSeq* results = cvHoughCircles( 
      image, 
      storage, 
      CV_HOUGH_GRADIENT, 
      4, 
      image->width/10 
    ); 
    for ( int i = 0; i < results->total; i++ ) {
        float* p = (float*) cvGetSeqElem( results, i );
        CvPoint pt = cvPoint( cvRound( p[0] ), cvRound( p[1] ) );
        cvCircle( 
          src,
          pt, 
          cvRound( p[2] ),
          CV_RGB(0xff,0,0) 
        );
    }
    cvNamedWindow( "cvHoughCircles", 1 );
    cvShowImage( "cvHoughCircles", src);
    cvWaitKey(0);

}
