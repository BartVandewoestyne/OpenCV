/**
 * Exercise 3-07.
 *
 * TODO:
 *
 *   - Check whether we need cvScalar or cvScalarAll.
 *
 */

#include <highgui.h>
#include <cv.h>

main( int argc, char* argv[] ) {

    IplImage* img = cvLoadImage( argv[1], CV_LOAD_IMAGE_COLOR );

    IplImage* red_image = cvCreateImage( cvGetSize(img), img->depth, 1 );
    IplImage* green_image = cvCreateImage( cvGetSize(img), img->depth, 1 );
    IplImage* blue_image = cvCreateImage( cvGetSize(img), img->depth, 1 );

    cvSplit( img, red_image, green_image, blue_image, NULL );

    // Clone the green image plane twice.
    IplImage* clone1 = cvCloneImage( green_image );
    IplImage* clone2 = cvCloneImage( green_image );

    // Find the green plane's minimum and maximum value.
    double minimum, maximum;
    CvPoint min_loc, max_loc;
    cvMinMaxLoc(
            green_image,
            &minimum,
            &maximum,
            &min_loc,
            &max_loc,
            NULL
    );
    printf("minimum = %f\n", minimum);
    printf("maximum = %f\n", maximum);
    printf("min_loc = (%d,%d)\n", min_loc.x, min_loc.y);
    printf("max_loc = (%d,%d)\n", max_loc.x, max_loc.y);

    // Set clone1's values to thresh = (unsigned char)((maximum - minimum)/2.0).
    unsigned char thresh = (unsigned char)((maximum - minimum)/2.0);
    cvSet( clone1, cvScalarAll(thresh) ); // TODO: or cvScalar(thresh) ???

    // Set clone2 to 0.
    cvSetZero( clone2 );

    // Use cvCmp(green_image, clone1, clone2, CV_CMP_GE).  Now, clone2 will have
    // a mask of where the value exceeds thresh in the green image.
    cvCmp(green_image, clone1, clone2, CV_CMP_GE);
    
    // Finally, use cvSubS(green_image, thresh/2, green_image, clone2) and
    // display the results.
    cvSubS(green_image, cvScalarAll(thresh/2), green_image, clone2); // TODO: or cvScalar(thresh)???

    cvNamedWindow( "Exercise 3-7: original", CV_WINDOW_AUTOSIZE );
    cvShowImage( "Exercise 3-7: original", img );

    // Display the green image.
    cvNamedWindow( "Exercise 3-7: green", CV_WINDOW_AUTOSIZE );
    cvShowImage( "Exercise 3-7: green", green_image );

    cvWaitKey(0);

    cvReleaseImage( &red_image );
    cvReleaseImage( &green_image );
    cvReleaseImage( &blue_image );
    cvReleaseImage( &img );
    cvDestroyWindow( "Exercise 3-7: green" );
    cvDestroyWindow( "Exercise 3-7: original" );

    return 0;

}
