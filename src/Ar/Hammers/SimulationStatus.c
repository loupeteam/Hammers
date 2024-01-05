
#include <bur/plctypes.h>
#include <stdbool.h>
#include <standard.h>
#include <AsIODiag.h>
#ifdef __cplusplus
	extern "C"
	{
#endif
#include "Hammers.h"
#ifdef __cplusplus
	};
#endif
/* Used to find the Simulation status for your project */
plcbit SimulationStatus(unsigned long pOverride)
{
	
	// check if override address is present
	if (pOverride == 0){
		if (DiagCpuIsARsim()) {
			return 1;
		} else {
			return 0;
		}
	}
	else{
		plcbit override = *((plcbit*)pOverride);
		if (override == 1){
			return 1;
		}
		else{
			return 0; 
		}
	}
	
}
