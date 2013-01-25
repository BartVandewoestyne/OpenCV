/**
 * Exercise 4-02.
 *
 * TODO:
 *
 *   -* Check if we need to use the cvCopyImage() technique.
 */

#include <cv.h>
#include <highgui.h>
#include <stdio.h>

void my_mouse_callback(
  int event, int x, int y, int flags, void* param
);


int main( int argc, char* argv[] ) {

    cvNamedWindow( "Exercise 4-2", CV_WINDOW_AUTOSIZE );

    IplImage* img = cvLoadImage( argv[1], CV_LOAD_IMAGE_COLOR );

    cvSetMouseCallback(
        "Exercise 4-2",
        my_mouse_callback,
        (void*) img
    );

    while (1) {

        cvShowImage( "Exercise 4-2", img );

        char c = cvWaitKey(15);
        if ( c==27 ) break;

    }

    cvReleaseImage( &img );
    cvDestroyWindow( "Exercise 4-2" );

    return 0;

}


void my_mouse_callback(int event, int x, int y, int flags, void* param)
{
    IplImage* image = (IplImage*) param;

    switch (event) {

        case CV_EVENT_LBUTTONDOWN: {

            printf("Left button down event: x = %d, y = %d.\n", x, y);

            CvFont font;
            cvInitFont( &font, CV_FONT_HERSHEY_SIMPLEX, 1, 1 );

            char text[50];
            sprintf(text, "(%d,%d)", x, y);

            cvPutText( image, text, cvPoint(x,y), &font, CV_RGB(255, 0, 0) );

        }
        break;

    }
}
