#include <cv.h>
#include <highgui.h>
#include <stdio.h>

int main(int argc, char** argv)
{
    printf("Example 3_19 Reading in cfg.xml\n");
    CvFileStorage* fs = cvOpenFileStorage(
      "cfg.xml", 
      0, 
      CV_STORAGE_READ
    );

    int frame_count = cvReadIntByName( 
      fs, 
      0, 
      "frame_count", 
      5 /* default value */ 
    );

    CvSeq* s = cvGetFileNodeByName(fs,0,"frame_size")->data.seq;

    int frame_width = cvReadInt( 
      (CvFileNode*)cvGetSeqElem(s,0) 
    );

    int frame_height = cvReadInt( 
      (CvFileNode*)cvGetSeqElem(s,1) 
    );

    CvMat* color_cvt_matrix = (CvMat*) cvRead(
      fs,
      0
    );
    printf("frame_count=%d, frame_width=%d, frame_height=%d\n",frame_count,frame_width,frame_height);

    cvReleaseFileStorage( &fs );
}
