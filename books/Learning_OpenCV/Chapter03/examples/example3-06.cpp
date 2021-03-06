//   Example 3-6. Pointer access to matrix structures
   uchar* cvPtr1D(
      const CvArr* arr,
      int          idx0,
      int*         type = NULL
   );
   uchar* cvPtr2D(
      const CvArr* arr,
      int          idx0,
      int          idx1,
      int*         type = NULL
   );
   uchar* cvPtr3D(
      const CvArr* arr,
      int          idx0,
		int          idx1,
		int          idx2,
		int*         type = NULL
	);
	uchar* cvPtrND(
		const CvArr* arr,
		int*         idx,
		int*         type            = NULL,
		int          create_node     = 1,
		unsigned*    precalc_hashval = NULL
	);
