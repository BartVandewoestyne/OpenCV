//Example 7-4. Using EMD to measure the similarity between distributions
// Do EMD AND REPORT
//
float emd = cvCalcEMD2(sig1,sig2,CV_DIST_L2);
printf(“%f; ”,emd);
