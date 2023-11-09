/*
 * File: SettleDown.c
 * Copyright (c) 2023 Loupe
 * https://loupe.team
 * 
 * This file is part of Hammers, licensed under the MIT License.
 * 
 */


#include <bur/plctypes.h>
#include <stdbool.h>
#include <standard.h>
#ifdef __cplusplus
	extern "C"
	{
#endif
#include "Hammers.h"
#ifdef __cplusplus
	};
#endif
/* Debounce function block that can be configured for positive edge debounce, negative edge debounce or both */
void SettleDown(struct SettleDown* inst)
{
	switch(inst->internal.state){
		
		case ST_SD_IDLE:
			
			if(inst->in != inst->internal._in){
				
				if(inst->in){
					inst->internal.fb.timer.PT = inst->onTime;
				}else{
					inst->internal.fb.timer.PT = inst->offTime;
				}
				
				if(inst->internal.fb.timer.PT == 0){
					inst->out = inst->in;
				}else{
					inst->internal.state = ST_SD_DEBOUNCE;
				}
			}
			break;
		
		case ST_SD_DEBOUNCE:
		
			inst->internal.fb.timer.IN = true;
			
			if(inst->in != inst->internal._in){
				inst->internal.state = ST_SD_IDLE;
			}else if(inst->internal.fb.timer.Q){
				inst->out = inst->in;
				inst->internal.state = ST_SD_IDLE;
			}
			break;
		
	}
	
	inst->internal._in = inst->in;
	TON(&(inst->internal.fb.timer));
	inst->internal.fb.timer.IN = false;
}
