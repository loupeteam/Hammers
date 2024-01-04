
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
/* Used to find the Simulation status for your project */
void SimulationStatus(struct SimulationStatus* inst)
{
	// Check for simulation
	// This is a DevLink using a Windows share which is not supported by ARsim
	// We use this instead of Diag function to support older CPU's
	inst->devLink_0.enable = 1;
	inst->devLink_0.pDevice = (UDINT)&("SimCheck");
	inst->devLink_0.pParam = (UDINT)&("/SIP=127.0.0.1 /PROTOCOL=cifs /SHARE=testfolder /USER=max /PASSWORD=passw");
	
	DevLink(&inst->devLink_0); 
	
	if (inst->devLink_0.status == ERR_NOTIMPLEMENTED) {
		inst->out = 1;
	} else {
		inst->out = 0;
	}
}
