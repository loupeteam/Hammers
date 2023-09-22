/********************************************************************
 * COPYRIGHT --  
 ********************************************************************
 * Library: Hammers
 * File: ScaleAnalogInput.c
 * Author: dfblackburn
 * Created: October 26, 2016
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

//--------------------------------------------------
// Scale an analog input value from counts to units 
//--------------------------------------------------

// Passes first tests

void ScaleAnalogInput(struct ScaleAnalogInput* t)
{
	
	// Check for null pointer
	if (t == 0) return;

	// Set up nodes
	USINT i;
	switch (t->configuration) {
		
		case hamAIO_CONFIG_V:

			// Counts to V
			t->internal.mtLookup_ctsToVmA.NodeVectorX[0] = -32767;
			t->internal.mtLookup_ctsToVmA.FcnValues[0] = -10;

			t->internal.mtLookup_ctsToVmA.NodeVectorX[1] = 0;
			t->internal.mtLookup_ctsToVmA.FcnValues[1] = 0;

			t->internal.mtLookup_ctsToVmA.NodeVectorX[2] = 32767;
			t->internal.mtLookup_ctsToVmA.FcnValues[2] = 10;
			
			t->internal.mtLookup_ctsToVmA.NumberOfNodes = 3;
			t->internal.mtLookup_ctsToVmA.Mode = mtLOOKUP_LINEAR_EXTRAPOLATION;
			
			// V to Units
			for (i = 0; i < HAM_NUM_SCALE_POINTS; i++) {
				t->internal.mtLookup_VmAToUnits.NodeVectorX[i] = t->V[i];
				t->internal.mtLookup_VmAToUnits.FcnValues[i] = t->units[i];
			}
		
			t->internal.mtLookup_VmAToUnits.NumberOfNodes = t->numberOfPoints;
			t->internal.mtLookup_VmAToUnits.Mode = mtLOOKUP_LINEAR_EXTRAPOLATION;
			
			break;
		
		
		case hamAIO_CONFIG_0_20_MA:
		
			// Counts to mA
			t->internal.mtLookup_ctsToVmA.NodeVectorX[0] = 0;
			t->internal.mtLookup_ctsToVmA.FcnValues[0] = 0;

			t->internal.mtLookup_ctsToVmA.NodeVectorX[1] = 32767;
			t->internal.mtLookup_ctsToVmA.FcnValues[1] = 20;
			
			t->internal.mtLookup_ctsToVmA.NodeVectorX[2] = 0;
			t->internal.mtLookup_ctsToVmA.FcnValues[2] = 0;
			
			t->internal.mtLookup_ctsToVmA.NumberOfNodes = 2;
			t->internal.mtLookup_ctsToVmA.Mode = mtLOOKUP_LINEAR_EXTRAPOLATION;
			
			// mA to Units
			for (i = 0; i < HAM_NUM_SCALE_POINTS; i++) {
				t->internal.mtLookup_VmAToUnits.NodeVectorX[i] = t->mA[i];
				t->internal.mtLookup_VmAToUnits.FcnValues[i] = t->units[i];
			}
		
			t->internal.mtLookup_VmAToUnits.NumberOfNodes = t->numberOfPoints;
			t->internal.mtLookup_VmAToUnits.Mode = mtLOOKUP_LINEAR_EXTRAPOLATION;
			
			break;
		
		
		case hamAIO_CONFIG_4_20_MA:
		
			// Counts to mA
			t->internal.mtLookup_ctsToVmA.NodeVectorX[0] = 0;
			t->internal.mtLookup_ctsToVmA.FcnValues[0] = 4;

			t->internal.mtLookup_ctsToVmA.NodeVectorX[1] = 32767;
			t->internal.mtLookup_ctsToVmA.FcnValues[1] = 20;
			
			t->internal.mtLookup_ctsToVmA.NodeVectorX[2] = 0;
			t->internal.mtLookup_ctsToVmA.FcnValues[2] = 0;
			
			t->internal.mtLookup_ctsToVmA.NumberOfNodes = 2;
			t->internal.mtLookup_ctsToVmA.Mode = mtLOOKUP_LINEAR_EXTRAPOLATION;
			
			// mA to Units
			for (i = 0; i < HAM_NUM_SCALE_POINTS; i++) {
				t->internal.mtLookup_VmAToUnits.NodeVectorX[i] = t->mA[i];
				t->internal.mtLookup_VmAToUnits.FcnValues[i] = t->units[i];
			}
		
			t->internal.mtLookup_VmAToUnits.NumberOfNodes = t->numberOfPoints;
			t->internal.mtLookup_VmAToUnits.Mode = mtLOOKUP_LINEAR_EXTRAPOLATION;
			
			break;
		
	} // switch(configuration)

	// Perform lookups
	t->internal.mtLookup_ctsToVmA.Enable = t->enable;
	t->internal.mtLookup_ctsToVmA.Update = t->update;
	t->internal.mtLookup_ctsToVmA.InX = t->input;
	MTLookUpTable(&t->internal.mtLookup_ctsToVmA);
	
	t->internal.mtLookup_VmAToUnits.Enable = t->enable;
	t->internal.mtLookup_VmAToUnits.Update = t->update;
	t->internal.mtLookup_VmAToUnits.InX = t->internal.mtLookup_ctsToVmA.Out;
	MTLookUpTable(&t->internal.mtLookup_VmAToUnits);
	
	// Set outputs
	if (t->internal.mtLookup_ctsToVmA.StatusID != 0) {
		
		t->output = 0;
		t->status = t->internal.mtLookup_ctsToVmA.StatusID;
		t->updateDone = 0;
		
	} else if (t->internal.mtLookup_VmAToUnits.StatusID != 0) {
	
		t->output = 0;
		t->status = t->internal.mtLookup_VmAToUnits.StatusID;
		t->updateDone = 0;
	
	} else {
	
		t->output = t->internal.mtLookup_VmAToUnits.Out;
		t->status = t->internal.mtLookup_VmAToUnits.StatusID;
		t->updateDone = t->internal.mtLookup_ctsToVmA.UpdateDone && t->internal.mtLookup_VmAToUnits.UpdateDone;
	
	}
	
} // End Fn
