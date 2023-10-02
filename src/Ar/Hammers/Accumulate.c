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

void Accumulate(struct Accumulate* t)
{

	// Check for null pointer
	if (t == 0) return;
	
	// Initialize inputOld and cumulative values
	if (!t->initialized) {
		t->inputOld = t->input;
		t->numPeriods = 0;
		t->accumulatedValue_add = (LREAL)t->input;
		t->initialized = 1;
	}
	
	// Accumulate!
	if (t->period == 0 || t->setToInput) {

		// Map input straight through and reset numPeriods
		t->accumulatedValue_add = (LREAL)t->input;
		t->accumulatedValue_mult = (LREAL)t->input;
		t->numPeriods = 0;
		
	} else {
		
		// Compute delta
		t->delta = (LREAL)t->input - (LREAL)t->inputOld;
		
		// Check for rollover
		if (t->delta < (LREAL)(-t->period / 2.0) ) {

			// Positive rollover
			t->numPeriods++;
			t->delta += (LREAL)t->period;
		
		} else if (t->delta > (LREAL)(t->period / 2.0) ) {

			// Negative rollover
			t->numPeriods--;
			t->delta -= (LREAL)t->period;
		
		}
		
		// Compute accumulated values
		t->accumulatedValue_add += t->delta;
		t->accumulatedValue_mult = (LREAL)(t->numPeriods * (LREAL)t->period) + (LREAL)t->input;
		
	}
	
	// Grab input for delta calculation
	t->inputOld = t->input;
	
	// Format output
	// Use additive value for now
	t->outputREAL = (REAL)t->accumulatedValue_add;
	t->outputLREAL = t->accumulatedValue_add;
	t->outputCYCLIC_POSITION.Integer = (DINT)(t->accumulatedValue_add);
	t->outputCYCLIC_POSITION.Real = (REAL)(t->accumulatedValue_add - (LREAL)t->outputCYCLIC_POSITION.Integer);
	
}
