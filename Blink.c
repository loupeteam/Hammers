
#include <bur/plctypes.h>
#ifdef __cplusplus
	extern "C"
	{
#endif
	#include "Hammers.h"
#ifdef __cplusplus
	};
#endif
/* Blinks a digital output on for a percentage(0-100) of a given time (in ms) */
void Blink(struct Blink* inst)
{
	// Run Function blocks
	TON(&inst->TimerOn);
	TON(&inst->TimerOff);
	
	if (inst->Enable)
	{
		//Get task cycle time
		if(inst->_RTInfo.status != 0 || inst->_RTInfo.enable == 0){
			inst->_RTInfo.enable= 1;
			RTInfo(&inst->_RTInfo);		
		}
		
		// prepare on and off times
		inst->onTime = inst->Time*inst->Percentage/100;
		inst->TimerOn.PT = inst->onTime;
		// saturate percentage if out of range
		if (inst->Percentage > 100){
			inst->offTime = 0;
		}
		else{
			inst->offTime = inst->Time - inst->onTime;
		}
		inst->TimerOff.PT = inst->offTime;
		if (inst->offTime > inst->_RTInfo.cycle_time/1000)
		{
			inst->offTime = (inst->offTime - inst->_RTInfo.cycle_time/1000);
		}
		if (inst->offTime > 0 && inst->onTime > 0)
		{
			// state machine
			if(inst->Out && inst->TimerOn.Q)
			{
				inst->TimerOn.IN = 0;
				inst->Out = 0;
				inst->TimerOff.IN = 1;
			}
			else if(!inst->Out && inst->TimerOff.Q){
				inst->TimerOn.IN = 1;
				inst->Out = 1;
				inst->TimerOff.IN = 0;
			}
			if(!inst->TimerOn.IN && !inst->TimerOff.IN)
			{
				inst->TimerOn.IN = 1;
				inst->Out = 1;
			} 
		}else 
		{
			inst->TimerOn.IN = 0;
			inst->TimerOff.IN = 0;
			
			if (inst->offTime <= 0) inst->Out = 1;
			if (inst->onTime <= 0) inst->Out = 0;
		}
	
	}
	else
	{
		// disable timers if function block is disabled
		inst->TimerOn.IN = 0;
		inst->TimerOff.IN = 0;
		inst->Out = 0;
	}
		
	// Run Function blocks
	TON(&inst->TimerOn);
	TON(&inst->TimerOff);
	
}
