// alphablend <imageA> <image B> <x> <y> <width> <height> 
//            <alpha> <beta>
#include <cv.h>
#include <highgui.h>
#include <stdio.h>

int main(int argc, char** argv)
{
    IplImage *src1, *src2;
    if( argc == 9 && ((src1=cvLoadImage(argv[1],1)) != 0 
        )&&((src2=cvLoadImage(argv[2],1)) != 0 ))
    {
        int x = atoi(argv[3]);
        int y = atoi(argv[4]);
        int width = atoi(argv[5]);
        int height = atoi(argv[6]);
        double alpha = (double)atof(argv[7]);
        double beta  = (double)atof(argv[8]);
        cvSetImageROI(src1, cvRect(x,y,width,height));
        cvSetImageROI(src2, cvRect(0,0,width,height));
        cvAddWeighted(src1, alpha, src2, beta,0.0,src1);
        cvResetImageROI(src1);
        cvNamedWindow( "Alpha_blend", 1 );
        cvShowImage( "Alpha_blend", src1 );
        cvWaitKey();
    }
    else 
      printf("Couldn't load one or both of %s, %s\n",argv[1],argv[2]);
    return 0;
}
