/**
 * Program to check if CV_CAP_PROP_POS_FRAMES returns the same frame
 * position as a manual count of the frames.
 */

#include <stdio.h>
#include "highgui.h"

int main( int argc, char** argv ) {

    cvNamedWindow( "Frame counter test", CV_WINDOW_AUTOSIZE );

    CvCapture* capture = cvCreateFileCapture( argv[1] );

    double fps = cvGetCaptureProperty(capture, CV_CAP_PROP_FPS);

    IplImage* frame;
    CvFont font;
    cvInitFont( &font, CV_FONT_HERSHEY_SIMPLEX, 0.5, 0.5 );
    char countOpenCV[100];
    char countManual[100];

    // CV_CAP_PROP_POS_FRAMES works with a 0-based index, so our first frame
    // with the manual counter must have index 0.
    unsigned long counterManual = -1;

    while (1) {

        unsigned long counterOpenCV = (unsigned long) cvGetCaptureProperty (
            capture,
            CV_CAP_PROP_POS_FRAMES
        );

        frame = cvQueryFrame( capture );
        if ( !frame ) {
            printf("\nCould not query frame at OpenCV count %lu\n", counterOpenCV);
            break;
        }

        counterManual++;

        printf("\nCV_CAP_PROP_POS_FRAMES: %lu\n", counterOpenCV);
        printf("Manual frame count:     %lu\n", counterManual);
        sprintf(countOpenCV, "CV_CAP_PROP_POS_FRAMES: %lu", counterOpenCV);
        sprintf(countManual, "Manual frame count:     %lu", counterManual);
        cvPutText( frame, countOpenCV, cvPoint(1, 50), &font, CV_RGB(0, 0, 0) );
        cvPutText( frame, countManual, cvPoint(1,100), &font, CV_RGB(0, 0, 0) );

        cvShowImage( "Frame counter test", frame );

        char c = cvWaitKey(1000/fps);
        if ( c == 27 ) break;
        if ( c == 'p' ) cvWaitKey(0);
    }

    cvReleaseCapture( &capture );
    cvDestroyWindow( "Frame counter test" );

}
