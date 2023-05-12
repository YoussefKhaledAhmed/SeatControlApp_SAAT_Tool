/**
 *
 * \file SideSensor_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: SideSensor
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 5/12/2023 04:20 PM
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_SideSensor.h"


/**
 *
 * Runnable SlideSensor_GetPosition
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppSlideSensor_GetPosition
 *
 */

void SlideSensor_GetPosition (SensorPositionType* position)
{
	Std_ReturnType status;
	IoPositionSensorReadingType position;

	/* Server Call Points */
	status = Rte_Call_rpIoGetSlide_IoGet(&position);
	
	/* SoftWare Logic */
	if(position == 0){
		position = SENSOR_POSITION_STEP_0;
	} else if((position > 0) && (position <= 64)){
		position = SENSOR_POSITION_STEP_1;
	} else if((position > 64) && (position <= 192)){
		position = SENSOR_POSITION_STEP_2;
	} else if((position > 192) && (position <= 255)){
		position = SENSOR_POSITION_STEP_3;
	} else{
		/* Do nothing... */
	}
	
}

