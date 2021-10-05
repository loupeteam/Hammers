/********************************************************************
 * COPYRIGHT --  
 ********************************************************************
 * Library: Hammers
 * File: Mean.c
 * Author: dfblackburn
 * Created: January 13, 2017
 ********************************************************************
 * Implementation of library Hammers
 ********************************************************************/

#include <bur/plctypes.h>
#ifdef __cplusplus
	extern "C"
	{
#endif

#include "Hammers.h"

#ifdef __cplusplus
	};
#endif


//*******************************************************************
// Return the mean of a data set									*
//*******************************************************************

// Check inputs		TESTED
// Compute mean		TESTED

double Mean(unsigned long pData, unsigned long n)
{

	// Check inputs
	if ((pData == 0) || (n == 0)) return 0;
	
	LREAL *cpData = (LREAL*)pData;
	LREAL sum = 0;
	UDINT i = 0;
	
	for (i = 0; i < n; i++) {
		sum = sum + cpData[i];
	}
	
	return sum/n;
	
}
