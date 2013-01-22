//
// Example 6-5. Use of cvDFT() to accelerate the computation of convolutions
// Use DFT to accelerate the convolution of array A by kernel B.
// Place the result in array V.
//

#include <cv.h>
#include <highgui.h>

int main(int argc, char** argv)
{
    int M1 = 2;
    int M2 = 2;
    int N1 = 2;
    int N2 = 2;

    // initialize A and B
    CvMat* A = cvCreateMat( M1, N1, CV_32F );
    CvMat* B = cvCreateMat( M2, N2, A->type );

    // it is also possible to have only abs(M2-M1)+1×abs(N2-N1)+1
    // part of the full convolution result
    CvMat* conv = cvCreateMat(
      A->rows + B->rows - 1,
      A->cols + B->cols - 1,
      A->type
    );

    int dft_M = cvGetOptimalDFTSize( A->rows + B->rows - 1 );
    int dft_N = cvGetOptimalDFTSize( A->cols + B->cols - 1 );

    CvMat* dft_A = cvCreateMat( dft_M, dft_N, A->type );
    CvMat* dft_B = cvCreateMat( dft_M, dft_N, B->type );
    CvMat tmp;

    // copy A to dft_A and pad dft_A with zeros
    cvGetSubRect( dft_A, &tmp, cvRect(0,0,A->cols,A->rows) );
    cvCopy( A, &tmp );
    cvGetSubRect( 
      dft_A,
      &tmp,
      cvRect( A->cols, 0, dft_A->cols-A->cols, A->rows )
    );
    cvZero( &tmp );

    // no need to pad bottom part of dft_A with zeros because of
    // use nonzero_rows parameter in cvDFT() call below
    cvDFT( dft_A, dft_A, CV_DXT_FORWARD, A->rows );

    // repeat the same with the second array
    cvGetSubRect( dft_B, &tmp, cvRect(0,0,B->cols,B->rows) );
    cvCopy( B, &tmp );
    cvGetSubRect(
      dft_B, 
      &tmp, 
      cvRect( B->cols, 0, dft_B->cols-B->cols, B->rows )
    );
    cvZero( &tmp );

    // no need to pad bottom part of dft_B with zeros because of
    // use nonzero_rows parameter in cvDFT() call below
    cvDFT( dft_B, dft_B, CV_DXT_FORWARD, B->rows );

    // or CV_DXT_MUL_CONJ to get correlation rather than convolution 
    cvMulSpectrums( dft_A, dft_B, dft_A, 0 );

    // calculate only the top part
    //
    cvDFT( dft_A, dft_A, CV_DXT_INV_SCALE, conv->rows ); 
    cvGetSubRect( dft_A, &tmp, cvRect(0,0,conv->cols,conv->rows) );

    cvCopy( &tmp, conv );
}
