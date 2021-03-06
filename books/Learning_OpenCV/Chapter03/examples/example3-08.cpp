//Example 3-8. Set element functions for CvMat or IplImage.  
// Also see usage example in example3-05.cpp
void cvSetReal1D( CvArr* arr, int idx0, double value );
void cvSetReal2D( CvArr* arr, int idx0, int idx1, double value );
void cvSetReal3D(
   CvArr* arr,
   int idx0,
   int idx1,
   int idx2,
   double value
);
void cvSetRealND( CvArr* arr, int* idx, double value );
void cvSet1D( CvArr* arr, int idx0, CvScalar value );
void cvSet2D( CvArr* arr, int idx0, int idx1, CvScalar value );
void cvSet3D(
   CvArr* arr,
   int idx0,
   int idx1,
   int idx2,
   CvScalar value
);
void cvSetND( CvArr* arr, int* idx, CvScalar value );
