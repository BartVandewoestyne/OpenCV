//      ./adaptThresh 15 1 1 71 15 adrian.jpg
// Example 5-4. Threshold versus adaptive threshold
// Compare thresholding with adaptive thresholding
// CALL:
// ./adaptThreshold Threshold 1binary 1adaptivemean \
//                    blocksize offset filename
//

#include <cv.h>
#include <highgui.h>
#include <math.h>

IplImage *Igray=0, *It = 0, *Iat;

int main( int argc, char** argv )
{
    if (argc != 7) { return -1; }

    // Command line.
    double threshold = (double) atof(argv[1]);
    int threshold_type = atoi(argv[2]) ?
             CV_THRESH_BINARY : CV_THRESH_BINARY_INV;
    int adaptive_method = atoi(argv[3]) ?
             CV_ADAPTIVE_THRESH_MEAN_C : CV_ADAPTIVE_THRESH_GAUSSIAN_C;
    int block_size = atoi(argv[4]);
    double offset = (double) atof(argv[5]);

    // Read in gray image.
    if ( ( Igray = cvLoadImage(argv[6], CV_LOAD_IMAGE_GRAYSCALE) ) == 0 ) {
        return -1;
    }

    // Create the grayscale output images.
    It = cvCreateImage(cvSize(Igray->width,Igray->height),
                         IPL_DEPTH_8U, 1);
    Iat = cvCreateImage(cvSize(Igray->width,Igray->height),
                         IPL_DEPTH_8U, 1);

    // Threshold.
    cvThreshold(Igray, It, threshold, 255, threshold_type);
    cvAdaptiveThreshold(Igray, Iat, 255, adaptive_method,
                        threshold_type, block_size, offset);

    // PUT UP 2 WINDOWS.
    cvNamedWindow("Raw", 1);
    cvNamedWindow("Threshold", 1);
    cvNamedWindow("Adaptive Threshold", 1);

    // Show the results.
    cvShowImage("Raw", Igray);
    cvShowImage("Threshold", It);
    cvShowImage("Adaptive Threshold", Iat);
    cvWaitKey(0);

    // Clean up.
    cvReleaseImage(&Igray);
    cvReleaseImage(&It);
    cvReleaseImage(&Iat);
	  cvDestroyWindow("Raw");
	  cvDestroyWindow("Threshold");
	  cvDestroyWindow("Adaptive Threshold");
	  return(0);
}
