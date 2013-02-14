/**
 * Test program to check the behavior of the cvCreateVideoWriter() function.
 *
 * I wrote this test because with the OpenCV version at work, there seemed to
 * be a problem that made this program segfault on the call to
 * cvCreateVideoWriter...
 *
 */
#include "cv.h"
#include "highgui.h"

int main( int argc, char* argv[] ) {

    CvVideoWriter* writer = 0;
    writer = cvCreateVideoWriter(
            "test.avi",
            CV_FOURCC('M','J','P','G'),
            25,
            cvSize(100,100)
    );

    return 0;
}
