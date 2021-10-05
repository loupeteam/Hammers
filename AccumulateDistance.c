/********************************************************************
 * COPYRIGHT --  
 ********************************************************************
 * Library: Hammers
 * File: Accumulate.c
 * Author: dfblackburn
 * Created: April 07, 2016
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

//-----------------------------------------
// Accumulate a periodic input (un-modulo)
//-----------------------------------------

// Passes first tests

void AccumulateDistance(struct AccumulateDistance* t)
{	
	
	// Check for null pointer
	if (t == 0) return;
	
	if (t->enable){
		
		// Initialize inputOld and cumulative values
		if (!t->initialized) {
			t->inputOld = t->input;
			t->initialized = 1;
		}
		
		// Compute delta
		t->delta = (LREAL)t->input - (LREAL)t->inputOld;
		
		// Check for rollover
		if (t->delta < (LREAL)(-t->period / 2.0) ) {

			// Positive rollover
			t->delta += (LREAL)t->period;
		
		} else if (t->delta > (LREAL)(t->period / 2.0) ) {

			// Negative rollover
			t->delta -= (LREAL)t->period;
		
		}
		
		//ABS
		if (t->delta < 0) t->delta = t->delta*-1;	
		
		// Compute accumulated values
		*(LREAL*)t->pDistance += t->delta;
		
		// Grab input for delta calculation
		t->inputOld = t->input;
	
		// Format output
		// Use additive value for now
		t->outputREAL = (REAL)*(LREAL*)t->pDistance;
		t->outputLREAL = *(LREAL*)t->pDistance;
		t->outputCYCLIC_POSITION.Integer = (DINT)*(LREAL*)t->pDistance;
		t->outputCYCLIC_POSITION.Real = (REAL)(*(LREAL*)t->pDistance - (LREAL)t->outputCYCLIC_POSITION.Integer);
		
	} else {
		t->initialized = 0;
	}

}
