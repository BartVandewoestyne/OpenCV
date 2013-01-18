#include <cv.h>
#include <highgui.h>

// ch3_ex3_13 image_name x y width height add# 

int main(int argc, char** argv)
{
    IplImage* interest_img;
    CvRect interest_rect;
    if( argc == 7 && ((interest_img=cvLoadImage(argv[1],1)) != 0 ))
    {
        interest_rect.x = atoi(argv[2]);
        interest_rect.y = atoi(argv[3]);
        interest_rect.width = atoi(argv[4]);
        interest_rect.height = atoi(argv[5]);
        int add = atoi(argv[6]);

        // Assuming IplImage *interest_img; and 
        //  CvRect interest_rect;
        //  Use widthStep to get a region of interest
        //
        // (Alternate method)
        //
        IplImage *sub_img = cvCreateImageHeader(
          cvSize(
             interest_rect.width, 
             interest_rect.height
          ),
          interest_img->depth, 
          interest_img->nChannels
        );
        
        sub_img->origin = interest_img->origin;
        
        sub_img->widthStep = interest_img->widthStep;
        
        sub_img->imageData = interest_img->imageData + 
          interest_rect.y * interest_img->widthStep  +
          interest_rect.x * interest_img->nChannels;
        
        cvAddS( sub_img, cvScalar(add), sub_img );
        
        cvReleaseImageHeader(&sub_img);

        cvNamedWindow( "Roi_Add", CV_WINDOW_AUTOSIZE );
        cvShowImage( "Roi_Add", interest_img );
        cvWaitKey();
    }
    return 0;
}
