//
// Example 5-3. Alternative method to combine and threshold image planes
//

#include <stdio.h>
#include <cv.h>
#include <highgui.h>


void sum_rgb( IplImage* src, IplImage* dst ) {

  // Allocate individual image planes.
  IplImage* r = cvCreateImage( cvGetSize(src), IPL_DEPTH_8U, 1 );
  IplImage* g = cvCreateImage( cvGetSize(src), IPL_DEPTH_8U, 1 );
  IplImage* b = cvCreateImage( cvGetSize(src), IPL_DEPTH_8U, 1 );

  // Temporary storage.
  IplImage* s = cvCreateImage(cvGetSize(src), IPL_DEPTH_32F, 1);
      
  // Split image onto the color planes.
  cvSplit( src, r, g, b, NULL );
     
  // Accumulate separate planes, combine and threshold.
	cvZero(s);
	cvAcc(b,s);
	cvAcc(g,s);
	cvAcc(r,s);
	
	// Truncate values above 100 and rescale into dst.
	cvThreshold( s, s, 100, 100, CV_THRESH_TRUNC );
	cvConvertScale( s, dst, 1, 0 );
 
  cvReleaseImage( &r );
  cvReleaseImage( &g );   
  cvReleaseImage( &b );   
  cvReleaseImage( &s );

}


int main(int argc, char** argv)
{
  // Create a named window with the name of the file.
  cvNamedWindow( argv[1], 1 );

  // Load the image from the given file name.
  IplImage* src = cvLoadImage( argv[1] );
  IplImage* dst = cvCreateImage( cvGetSize(src), src->depth, 1);
  sum_rgb(src, dst);

  // Show the image in the named window.
  cvShowImage( argv[1], dst );

  // Idle until the user hits the "Esc" key.
  while ( 1 ) {
      if( (cvWaitKey( 10 ) & 0x7f) == 27 )
          break;
  }

  // Clean up and don’t be piggies.
  cvDestroyWindow( argv[1] );
  cvReleaseImage( &src );
  cvReleaseImage( &dst );
}
