/**
 * Exercise 4-03.
 */

#include <cv.h>
#include <highgui.h>
#include <stdio.h>

void my_mouse_callback(
  int event, int x, int y, int flags, void* param
);

CvRect box;

bool drawing_box = false;
bool box_drawn = false;
bool region_highlighted = false;


void print_rect(const char* name, CvRect rect) {

    printf("%s: rectangle is (x=%d, y=%d, width=%d, height=%d)\n",
           name, rect.x, rect.y, rect.width, rect.height);

}


void highlight_region( IplImage* img, CvRect rect ) {

    CvScalar highlight_color = cvScalarAll( 50 );
    CvScalar border_color = cvScalar( 0, 255, 0 );

    cvRectangle(
      img,
      cvPoint(rect.x, rect.y),
      cvPoint(rect.x+rect.width, rect.y+rect.height),
      border_color
    );

    cvSetImageROI( img, rect );
    cvAddS( img, highlight_color, img );
    cvResetImageROI( img );

}


void draw_box( IplImage* img, CvRect rect ) {

    cvRectangle(
      img,
      cvPoint(rect.x, rect.y),
      cvPoint(rect.x+rect.width, rect.y+rect.height),
      cvScalar(0xff, 0x00, 0x00)
    );
}


int main( int argc, char* argv[] ) {

    box = cvRect(-1,-1,0,0);

    cvNamedWindow( "Exercise 4-3a", CV_WINDOW_AUTOSIZE );

    IplImage* image = cvLoadImage( argv[1], CV_LOAD_IMAGE_COLOR );
    IplImage* temp = cvCloneImage( image );

    cvSetMouseCallback(
        "Exercise 4-3a",
        my_mouse_callback,
        (void*) temp
    );

    while (1) {


        if ( box_drawn && !region_highlighted ) {
            highlight_region( temp, box );
            region_highlighted = true;
        }
        if ( drawing_box ) {
            cvCopyImage( image, temp );
            draw_box( temp, box );
        }

        cvShowImage( "Exercise 4-3a", temp );

        char c = cvWaitKey(15);
        if ( c==27 ) break;

    }

    cvReleaseImage( &image );
    cvReleaseImage( &temp );
    cvDestroyWindow( "Exercise 4-3a" );

    return 0;

}


void my_mouse_callback(int event, int x, int y, int flags, void* param)
{
    IplImage* image = (IplImage*) param;

    switch (event) {

        case CV_EVENT_MOUSEMOVE: {

            print_rect("Moving mouse", box);
            if (drawing_box) {
                box.width  = x - box.x;
                box.height = y - box.y;
            }

        }
        break;

        case CV_EVENT_LBUTTONDOWN: {

            drawing_box = true;
            box_drawn = false;
            region_highlighted = false;
            box = cvRect(x, y, 0, 0);

        }
        break;

        case CV_EVENT_LBUTTONUP: {

            drawing_box = false;
            box_drawn = true;
            if (box.width < 0) {
                box.x += box.width;
                box.width *= -1;
            }
            if (box.height < 0) {
                box.y += box.height;
                box.height *= -1;
            }
            print_rect("Releasing left button", box);
            draw_box(image, box);

        }
        break;

    }
}
