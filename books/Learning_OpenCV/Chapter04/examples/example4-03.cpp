#include <cv.h>
#include <highgui.h>
#include <stdio.h>
int main(int argc, char** argv)
{
    // Adding something to open a video so that we can read its properties ...
  	IplImage *frame; // To hold movie images
    CvCapture* capture         = NULL;
    if((argc < 2 )|| !(capture = cvCreateFileCapture( argv[1] ))){
    	printf("Failed to open %s\n",argv[1]);
    	return -1;
    }
    //Read the properties
	  double f = cvGetCaptureProperty(
		  capture,
		  CV_CAP_PROP_FOURCC
	  );
	  char* fourcc = (char*) (&f);
	  printf("Properties of %s are:\n",argv[1]);
	  printf("FORCC = %d | %d | %d | %d |\n",fourcc[0],fourcc[1],fourcc[2],fourcc[3]);
    cvReleaseCapture( &capture );
    return 0;
}
