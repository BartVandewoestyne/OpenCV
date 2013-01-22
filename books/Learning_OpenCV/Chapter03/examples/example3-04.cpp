#include "cv.h"
#include <stdio.h>

int main()
{
  CvMat* mat = cvCreateMat( 5, 5, CV_32FC1 );
  float element_3_2 = CV_MAT_ELEM( *mat, float, 3, 2 );
  printf("Exercise 3_4, matrix created and accessed [3,2]=%f\n",element_3_2);
}
