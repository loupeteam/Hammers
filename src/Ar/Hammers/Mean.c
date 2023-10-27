/*
 * File: Mean.c
 * Copyright (c) 2023 Loupe
 * https://loupe.team
 * 
 * This file is part of Hammers, licensed under the MIT License.
 * 
 */

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
