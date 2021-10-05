/********************************************************************
 * COPYRIGHT --  
 ********************************************************************
 * Library: Hammers
 * File: StandardDeviation.c
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
#include "math.h"

#ifdef __cplusplus
	};
#endif


//*******************************************************************
// Compute the standard deviation of a data set 					*
//*******************************************************************

// Check inputs					TESTED
// Compute standard deviation	TESTED

double StandardDeviation(unsigned long pData, unsigned long n)
{
	
	// Check inputs
	if ((pData == 0) || (n == 0)) return 0;
	
	LREAL *cpData = (LREAL*)pData;
	LREAL dev2 = 0;
	LREAL sum = 0;
	LREAL mean = Mean(pData, n);
	UDINT i = 0;
	
	for (i = 0; i < n; i++) {
		dev2 = (cpData[i] - mean) * (cpData[i] - mean);
		sum = sum + dev2;
	}

	LREAL variance = sum/n;
	
	return sqrt(variance);
	
}
