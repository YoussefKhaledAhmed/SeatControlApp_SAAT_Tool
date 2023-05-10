/**
 *
 * \file SideSensor_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: SideSensor
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 5/10/2023 01:28 PM
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
	status = Adc_ReadGroup(Adc_GroupType Group , Adc_ValueGroupType* DataBufferPtr);
}

