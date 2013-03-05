#include "averaging_background_method.h"

// Global storage.

// Float, 3-channel images.
IplImage *IavgF[NUM_CAMERAS], *IdiffF[NUM_CAMERAS], *IprevF[NUM_CAMERAS], *IhiF[NUM_CAMERAS], *IlowF[NUM_CAMERAS];
IplImage *Iscratch, *Iscratch2;

// Float, 1-channel images.
IplImage *Igray1, *Igray2, *Igray3;
IplImage *Ilow1[NUM_CAMERAS], *Ilow2[NUM_CAMERAS], *Ilow3[NUM_CAMERAS];
IplImage *Ihi1[NUM_CAMERAS], *Ihi2[NUM_CAMERAS], *Ihi3[NUM_CAMERAS];

// Byte, 1-channel image
IplImage *Imaskt;

// Counts number of images learned for averaging later.
float Icount[NUM_CAMERAS];


// I is just a sample for allocation purposes
// (passed in for sizing)
void AllocateImages(IplImage *I)
{
  for(int i = 0; i < NUM_CAMERAS; i++)
  {
  	IavgF[i]  = cvCreateImage( cvGetSize(I), IPL_DEPTH_32F, 3 );
  	IdiffF[i] = cvCreateImage( cvGetSize(I), IPL_DEPTH_32F, 3 );
  	IprevF[i] = cvCreateImage( cvGetSize(I), IPL_DEPTH_32F, 3 );
  	IhiF[i]   = cvCreateImage( cvGetSize(I), IPL_DEPTH_32F, 3 );
  	IlowF[i]  = cvCreateImage( cvGetSize(I), IPL_DEPTH_32F, 3 );
  	Ilow1[i]  = cvCreateImage( cvGetSize(I), IPL_DEPTH_32F, 1 );
  	Ilow2[i]  = cvCreateImage( cvGetSize(I), IPL_DEPTH_32F, 1 );
  	Ilow3[i]  = cvCreateImage( cvGetSize(I), IPL_DEPTH_32F, 1 );
  	Ihi1[i]   = cvCreateImage( cvGetSize(I), IPL_DEPTH_32F, 1 );
  	Ihi2[i]   = cvCreateImage( cvGetSize(I), IPL_DEPTH_32F, 1 );
  	Ihi3[i]   = cvCreateImage( cvGetSize(I), IPL_DEPTH_32F, 1 );
  	cvZero( IavgF[i] );
  	cvZero( IdiffF[i] );
  	cvZero( IprevF[i] );
  	cvZero( IhiF[i] );
  	cvZero( IlowF[i] );		
  	Icount[i] = 0.00001;  // Protect against divide by zero.
  }
  Iscratch  = cvCreateImage( cvGetSize(I), IPL_DEPTH_32F, 3 );
  Iscratch2 = cvCreateImage( cvGetSize(I), IPL_DEPTH_32F, 3 );
  Igray1    = cvCreateImage( cvGetSize(I), IPL_DEPTH_32F, 1 );
  Igray2    = cvCreateImage( cvGetSize(I), IPL_DEPTH_32F, 1 );
  Igray3    = cvCreateImage( cvGetSize(I), IPL_DEPTH_32F, 1 );
  Imaskt    = cvCreateImage( cvGetSize(I), IPL_DEPTH_8U,  1 );
  
  cvZero( Iscratch );
  cvZero( Iscratch2 );
}


void DeallocateImages()
{
	for (int i=0; i<NUM_CAMERAS; i++)
  {
		cvReleaseImage( &IavgF[i] );
		cvReleaseImage( &IdiffF[i] );
		cvReleaseImage( &IprevF[i] );
		cvReleaseImage( &IhiF[i] );
		cvReleaseImage( &IlowF[i] );
		cvReleaseImage( &Ilow1[i] );
		cvReleaseImage( &Ilow2[i] );
		cvReleaseImage( &Ilow3[i] );
		cvReleaseImage( &Ihi1[i] );
		cvReleaseImage( &Ihi2[i] );
		cvReleaseImage( &Ihi3[i] );
	}
	cvReleaseImage( &Iscratch );
	cvReleaseImage( &Iscratch2 );
	cvReleaseImage( &Igray1 );
	cvReleaseImage( &Igray2 );
	cvReleaseImage( &Igray3 );
	cvReleaseImage( &Imaskt );
}


// Accumulate the background statistics for one more frame.
// We accumulate the images, the image differences and the count of images for the 
//    the routine createModelsfromStats() to work on after we're done accumulating N frames.
//
// Parameters:
//   I:       Background image, 3 channel, 8u
//   number:	Camera number
void accumulateBackground(IplImage *I, int number)
{
	static int first = 1;  // nb. Not thread safe

  // Turn the raw background 8-bit-per-channel, three-color-channel image into a
  // floating-point three-channel image.
	cvCvtScale(I, Iscratch, 1, 0);

	if (!first)
  {
    // Learn the accumulated background image.
		cvAcc(Iscratch, IavgF[number]);

    // Learn the accumulated absolute value of frame-to-frame image differences.
		cvAbsDiff(Iscratch, IprevF[number], Iscratch2);
		cvAcc(Iscratch2, IdiffF[number]);

		Icount[number] += 1.0;
	}
	first = 0;
	cvCopy(Iscratch, IprevF[number]);
}


// Scale the average difference from the average image high acceptance threshold.
void scaleHigh(float scale, int num)
{
	cvConvertScale( IdiffF[num], Iscratch, scale); // Converts with rounding and saturation.
	cvAdd( Iscratch, IavgF[num], IhiF[num]);
	cvCvtPixToPlane( IhiF[num], Ihi1[num], Ihi2[num], Ihi3[num], 0 ); // TODO: book has other function here.  Check!
}


// Scale the average difference from the average image low acceptance threshold.
void scaleLow(float scale, int num)
{
	cvConvertScale( IdiffF[num], Iscratch, scale ); // Converts with rounding and saturation.
	cvSub( IavgF[num], Iscratch, IlowF[num] );
	cvCvtPixToPlane( IlowF[num], Ilow1[num], Ilow2[num], Ilow3[num], 0 );
}


// Once you've learned the background long enough, turn it into a background
// model.
void createModelsfromStats()
{
	for (int i=0; i < NUM_CAMERAS; i++)
	{
		cvConvertScale( IavgF[i], IavgF[i], (double)(1.0/Icount[i]) );
		cvConvertScale( IdiffF[i], IdiffF[i], (double)(1.0/Icount[i]) );

    // Make sure diff is always something.
		cvAddS( IdiffF[i], cvScalar(1.0,1.0,1.0), IdiffF[i] );

		scaleHigh(HIGH_SCALE_NUM, i);
		scaleLow(LOW_SCALE_NUM, i);
	}
}


// Create a binary: 0,255 mask where 255 means forground pixel.
//
// Parameters:
//   I:     input image, 3 channel, 8u
//   Imask: mask image to be created, 1 channel 8u
//   num:   camera number
//
void backgroundDiff(IplImage *I, IplImage *Imask, int num)  // Mask should be grayscale
{
	cvCvtScale(I, Iscratch, 1, 0);  // To float.

	// Channel 1
	cvCvtPixToPlane( Iscratch, Igray1, Igray2, Igray3, 0 ); // TODO: book uses cvSplit: check!
	cvInRange( Igray1, Ilow1[num], Ihi1[num], Imask);

	// Channel 2
	cvInRange( Igray2, Ilow2[num], Ihi2[num], Imaskt );
	cvOr( Imask, Imaskt, Imask );

	// Channel 3
	cvInRange( Igray3, Ilow3[num], Ihi3[num], Imaskt );
	cvOr( Imask, Imaskt, Imask );

	// Finally, invert the results.
	cvSubRS( Imask, cvScalar(255), Imask);
}
