/********************************************************************
 * COPYRIGHT --  
 ********************************************************************
 * Library: Hammers
 * File: TempSensorFn.c
 * Author: scismd
 * Created: July 25, 2016
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

plcbit hamTempSensorFn(struct hamTempSensor_typ* t) {
	
	// Check for null pointer
	if (t == 0) return 0;
	
	//set defaults
	if (t->IN.CFG.ScaleFactor == 0) t->IN.CFG.ScaleFactor = 0.1;
	if (t->IN.CFG.WarningPercentage == 0) t->IN.CFG.WarningPercentage = 85;
	if (t->IN.CFG.HighPercentage == 0) t->IN.CFG.HighPercentage = 95;
	
	//scale output
	t->OUT.Temperature = t->IN.PAR.aiValue * t->IN.CFG.ScaleFactor;
	
	//reset level
	t->OUT.TempLevel = TEMP_LEVEL_OK;
	
	//set warning
	t->OUT.WarningTempAlarm = ((t->OUT.Temperature/t->IN.CFG.HighTemp)*100 >= t->IN.CFG.WarningPercentage) && !t->OUT.HighTempAlarm;
	if (t->OUT.WarningTempAlarm) t->OUT.TempLevel = TEMP_LEVEL_WARNING;
	
	//set high
	t->OUT.HighTempAlarm = ((t->OUT.Temperature/t->IN.CFG.HighTemp)*100 >= t->IN.CFG.HighPercentage);
	if (t->OUT.HighTempAlarm) t->OUT.TempLevel = TEMP_LEVEL_HIGH;
	
	return 0;
	
}
