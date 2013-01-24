/**
 * Exercise 4-01.
 *
 * TODO:
 *   - change this so that we have 3 times the WIDTH instead of the HEIGHT!
 *   - check if we can avoid the temporaries for the cvCopy operation.
 *   - add text labels
 */

#include "cv.h"
#include "highgui.h"

int main( int argc, char* argv[] ) {

    CvCapture* capture = NULL;
    if (argc >= 2) {
      capture = cvCreateFileCapture( argv[1] );
    } else {
      capture = cvCreateCameraCapture( 0 );
    }

    cvNamedWindow( "Three in one!", CV_WINDOW_AUTOSIZE );

    IplImage* frame = NULL;
    IplImage* frame_gray = NULL;
    IplImage* frame_gray_ = NULL;
    IplImage* frame_edges = NULL;
    IplImage* frame_edges_ = NULL;
    IplImage* frame_all = NULL;
    IplImage* temp1 = NULL;
    IplImage* temp2 = NULL;
    IplImage* temp3 = NULL;
    while (1) {

        frame = cvQueryFrame(capture);
        if (!frame) break;

        // Turn to grayscale;
        frame_gray_ = cvCreateImage( cvGetSize(frame), frame->depth, 1 );
        frame_gray  = cvCreateImage( cvGetSize(frame), frame->depth, frame->nChannels );
        cvCvtColor(frame, frame_gray_, CV_RGB2GRAY);

        // Perform Canny edge detection;
        frame_edges_ = cvCreateImage( cvGetSize(frame), frame->depth, 1 );
        frame_edges  = cvCreateImage( cvGetSize(frame), frame->depth, frame->nChannels );
        cvCanny( frame_gray_, frame_edges_, 10, 100, 3 );

        // Convert back to RGB to have the same number of channels as frame
        // again!!!
        //
        // TODO: check why we need temporary images to do this... can't
        //       cvCvtColor convert in place???
        cvCvtColor(frame_gray_, frame_gray, CV_GRAY2RGB);
        cvCvtColor(frame_edges_, frame_edges, CV_GRAY2RGB);

        // TODO: change this so that we have 3 times the WIDTH.
        frame_all = cvCreateImage( cvSize(frame->width, frame->height*3), frame->depth, frame->nChannels );

        temp1 = cvCreateImageHeader( cvGetSize(frame), frame->depth, frame->nChannels );
        temp2 = cvCreateImageHeader( cvGetSize(frame), frame->depth, frame->nChannels );
        temp3 = cvCreateImageHeader( cvGetSize(frame), frame->depth, frame->nChannels );

        temp1->imageData = frame_all->imageData;
        temp2->imageData = frame_all->imageData + frame->height*frame_all->widthStep;
        temp3->imageData = frame_all->imageData + frame->height*frame_all->widthStep*2;

        cvCopy( frame,       temp1 );
        cvCopy( frame_gray,  temp2 );
        cvCopy( frame_edges, temp3 );

        CvFont font;
        cvInitFont( &font, CV_FONT_HERSHEY_SIMPLEX, 1, 1 );
        CvPoint origin = cvPoint (50, 50);
        cvPutText(temp1, "Original",       origin, &font, CV_RGB(255, 0, 0));
        cvPutText(temp2, "Grayscale",      origin, &font, CV_RGB(255, 0, 0));
        cvPutText(temp3, "Edge detection", origin, &font, CV_RGB(255, 0, 0));

        cvShowImage( "Three in one!", frame_all );

        char c = cvWaitKey(33);
        if ( c == 27 ) break;

    }

    cvReleaseImage( &frame );
    cvReleaseImage( &frame_gray );
    cvReleaseImage( &frame_edges );
    cvReleaseImage( &frame_all );
    cvReleaseImage( &temp1 );
    cvReleaseImage( &temp2 );
    cvReleaseImage( &temp3 );
    cvReleaseCapture( &capture );
    cvDestroyWindow( "Three in one!" );

    return 0;

}
