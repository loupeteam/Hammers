PROGRAM _INIT
	
	myInitSimStatus := SimulationStatus(0);
	
END_PROGRAM
	

PROGRAM _CYCLIC
	
	myCyclicSimStatus := SimulationStatus(0);
	myOverrideSimStatus := SimulationStatus(ADR(override));
	
	SettleDown_0();
	
END_PROGRAM

