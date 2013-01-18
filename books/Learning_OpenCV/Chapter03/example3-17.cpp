#include <cv.h>
#include <highgui.h>
#include <stdio.h>

int main(int argc, char** argv)
{
    CvMat *cmatrix = cvCreateMat(5,5,CV_32FC1);
    float element_3_2 = 7.7;
    *((float*)CV_MAT_ELEM_PTR( *cmatrix, 3,2) ) = element_3_2;
    cvmSet(cmatrix,4,4,0.5000);
    cvSetReal2D(cmatrix,3,3,0.5000);
	  printf("Example 3_17, writing cfg.xml\n");
    CvFileStorage* fs = cvOpenFileStorage(
      "cfg.xml",
      0,
      CV_STORAGE_WRITE
    );
    cvWriteInt( fs, "frame_count", 10 );
    cvStartWriteStruct( fs, "frame_size", CV_NODE_SEQ);
    cvWriteInt( fs, 0, 320 );
    cvWriteInt( fs, 0, 200 );
    cvEndWriteStruct(fs);
    cvWrite( fs, "color_cvt_matrix", cmatrix );
    cvReleaseFileStorage( &fs );
}
