/*
 * File: subtractWithRollover.c
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

//-----------------------------------------------
// Subtract two REALs and return the difference,
// corrected for rollover
//-----------------------------------------------

// Passes first tests with zero and nonzero rolloverPeriod

float subtractWithRollover(float minuend, float subtrahend, float rolloverPeriod)
{
	
	// If no period is input, then default to regular old subraction
	if (rolloverPeriod == 0) return (minuend - subtrahend);
	
	// If a period is input, then correct for rollover
	REAL delta = minuend - subtrahend;
	
	if (delta >= rolloverPeriod/2.0) {
		
		delta -= rolloverPeriod;
		
	} else if (delta <= -rolloverPeriod/2.0) {
		
		delta += rolloverPeriod;
		
	}
	
	return delta;
	
}
