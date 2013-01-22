// An example program in which the
// user can draw boxes on the screen.
//
#include <cv.h>
#include <highgui.h>
 
// Define our callback which we will install for
// mouse events.
//
void my_mouse_callback(
   int event, int x, int y, int flags, void* param 
);
 
CvRect box;
bool drawing_box = false;
 
// A litte subroutine to draw a box onto an image
//
void draw_box( IplImage* img, CvRect rect ) {
  cvRectangle (
    img, 
    cvPoint(box.x,box.y),
    cvPoint(box.x+box.width,box.y+box.height),
    cvScalar(0xff,0x00,0x00)    /* red */
  );
}
 
int main( int argc, char* argv[] ) {
  
  box = cvRect(-1,-1,0,0);

  IplImage* image = cvCreateImage( 
    cvSize(200,200),
    IPL_DEPTH_8U,
    3
  );
  cvZero( image );
  IplImage* temp = cvCloneImage( image );
  
  cvNamedWindow( "Box Example" );
 
  // Here is the crucial moment that we actually install
  // the callback.  Note that we set the value ‘param’ to
  // be the image we are working with so that the callback
  // will have the image to edit.
  //
  cvSetMouseCallback( 
    "Box Example", 
    my_mouse_callback, 
    (void*) image 
  );
 
  // The main program loop.  Here we copy the working image
  // to the ‘temp’ image, and if the user is drawing, then
  // put the currently contemplated box onto that temp image.
  // display the temp image, and wait 15ms for a keystroke,
  // then repeat…
  //
  while( 1 ) {
 
    cvCopyImage( image, temp );
    if( drawing_box ) draw_box( temp, box ); 
    cvShowImage( "Box Example", temp );
 
    if( cvWaitKey( 15 )==27 ) break;
  }
 
  // Be tidy
  //
  cvReleaseImage( &image );
  cvReleaseImage( &temp );
  cvDestroyWindow( "Box Example" );
}
 
// This is our mouse callback.  If the user
// presses the left button, we start a box.
// when the user releases that button, then we
// add the box to the current image.  When the
// mouse is dragged (with the button down) we 
// resize the box.
//
void my_mouse_callback(
   int event, int x, int y, int flags, void* param )
{
 
  IplImage* image = (IplImage*) param;

  switch( event ) {
    case CV_EVENT_MOUSEMOVE: {
      if( drawing_box ) {
        box.width  = x-box.x;
        box.height = y-box.y;
      }
    }
    break;
    case CV_EVENT_LBUTTONDOWN: {
      drawing_box = true;
      box = cvRect( x, y, 0, 0 );
    }
    break;   
    case CV_EVENT_LBUTTONUP: {
      drawing_box = false; 
      if( box.width<0  ) { 
        box.x+=box.width;  
        box.width *=-1; 
      }
      if( box.height<0 ) { 
        box.y+=box.height; 
        box.height*=-1; 
      }
      draw_box( image, box );
    }
    break;   
  }
}
