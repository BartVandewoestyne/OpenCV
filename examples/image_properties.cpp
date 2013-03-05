/**
 * Print out all image properties for a specified image file.
 */

#include "cv.h"
#include "highgui.h"
#include <stdio.h>

int main( int argc, char* argv[] ) {

    IplImage* img = cvLoadImage( argv[1], CV_LOAD_IMAGE_ANYDEPTH);

    std::cout << "nSize: " << img->nSize << std::endl;
    std::cout << "  sizeof(IplImage)\n" << std::endl;

    std::cout << "ID: " << img->ID << std::endl;
    std::cout << "  Version, always equal 0\n" << std::endl;

    std::cout << "nChannels: " << img->nChannels << std::endl;
    std::cout << "  Number of channels\n" << std::endl;

    std::cout << "depth: " << img->depth << std::endl;
    std::cout << "  Channel depth in bits + the optional sign bit\n" << std::endl;              

    std::cout << "dataOrder: " << img->dataOrder << std::endl;
    std::cout << "  0 = interleaved color channels, 1 = separate color channels\n" << std::endl;
              
    std::cout << "origin: " << img->dataOrder << std::endl;
    std::cout << "  0 = top-left origin, 1 = bottom-left origin\n" << std::endl;

    std::cout << "align: " << img->align << std::endl;
    std::cout << "  Alignment of image rows (4 or 8).  OpenCV ignores this and uses widthStep instead.\n" << std::endl;              

    std::cout << "width: " << img->width << std::endl;
    std::cout << "  Image width in pixels\n" << std::endl;              

    std::cout << "height: " << img->height << std::endl;
    std::cout << "  Image height in pixels\n" << std::endl;              

    std::cout << "roi: " << img->roi << std::endl;
    std::cout << "  Region Of Interest (ROI).  If not NULL, only this image region will be processed.\n" << std::endl;              

    std::cout << "maskROI: " << img->maskROI << std::endl;
    std::cout << "  Must be NULL in OpenCV.\n" << std::endl;              

    std::cout << "imageId: " << img->imageId << std::endl;
    std::cout << "  Must be NULL in OpenCV.\n" << std::endl;              

    std::cout << "tileInfo: " << img->tileInfo << std::endl;
    std::cout << "  Must be NULL in OpenCV.\n" << std::endl;              

    std::cout << "imageSize: " << img->imageSize << std::endl;
    std::cout << "  Image data size in bytes.  For interleaved data, this equals image->height*image->widthStep\n" << std::endl;              

    // TODO
    //std::cout << "imageData: " << img->imageData << std::endl;
    //std::cout << "  A pointer to the aligned image data.\n" << std::endl;              

    std::cout << "widthStep: " << img->widthStep << std::endl;
    std::cout << "  The size of an aligned iamge row, in bytes.\n" << std::endl;              

    // TODO
    //std::cout << "imageDataOrigin: " << img->imageDataOrigin << std::endl;
    //std::cout << "  A pointer to the origin of the image data (not necessarily aligned). This is used for image deallocation." << std::endl;              

    cvReleaseImage( &img );

    return 0;
}
