(********************************************************************
 * COPYRIGHT --  
 ********************************************************************
 * Library: Hammers
 * File: Hammers.typ
 * Author: dfblackburn
 * Created: April 07, 2016
 ********************************************************************
 * Data types of library Hammers
 ********************************************************************)

TYPE
	hamAIO_CONFIG : 
		(
		hamAIO_CONFIG_V,
		hamAIO_CONFIG_0_20_MA,
		hamAIO_CONFIG_4_20_MA
		);
	hamCYCLIC_POSITION : 	STRUCT 
		Integer : DINT;
		Real : REAL;
	END_STRUCT;
	hamScaleAI_internal_typ : 	STRUCT 
		mtLookup_ctsToVmA : MTLookUpTable;
		mtLookup_VmAToUnits : MTLookUpTable;
	END_STRUCT;
	SdInternal_typ : 	STRUCT 
		fb : SdFB_typ;
		_in : BOOL;
		state : SdState_enum;
	END_STRUCT;
	SdFB_typ : 	STRUCT 
		timer : TON;
	END_STRUCT;
	SdState_enum : 
		(
		ST_SD_IDLE,
		ST_SD_DEBOUNCE
		);
END_TYPE
