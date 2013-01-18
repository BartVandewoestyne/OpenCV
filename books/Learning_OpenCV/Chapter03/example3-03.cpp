#include "cv.h"
#include <stdio.h>

int main()
{
  // Create an OpenCV Matrix containing some fixed data.
  //
  float vals[] = { 0.866025, -0.500000, 0.500000, 0.866025};
   
  CvMat rotmat;
   
  cvInitMatHeader(
    &rotmat,
    2,
    2, 
    CV_32FC1,
    vals
  );
  printf("Ex 3_3 matrix initialized\n");
}
