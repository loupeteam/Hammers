/*
 * File: FastTON.c
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
/* Timer with fidelity of the task class it is called in */
void FastTON(struct FastTON* inst)
{
	
	if(!inst) {return;}
	
	if(inst->IN){
		
		// save start time once
		if(!inst->started){
			inst->start = (UDINT) AsIOTimeCyclicStart();
			inst->started = 1;
		}
		
		// track elapsed time
		if(inst->ET < inst->PT){
			inst->ET = ((UDINT) AsIOTimeCyclicStart()) - inst->start;
		}
		
		// set Q
		inst->Q = (inst->ET >= inst->PT);
		
	} else{
		
		// clear
		inst->Q = 0;
		inst->ET = 0;
		inst->start = 0;
		inst->started = 0;
		
	}
}

