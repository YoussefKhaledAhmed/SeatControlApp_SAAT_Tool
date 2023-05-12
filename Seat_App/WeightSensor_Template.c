/**
 *
 * \file WeightSensor_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: WeightSensor
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 5/12/2023 04:20 PM
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_WeightSensor.h"


/**
 *
 * Runnable WeightSensor_GetWeight
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppWeightSensor_GetWeight
 *
 */

void WeightSensor_GetWeight (SensorWeightType* weight)
{
	Std_ReturnType status;
	IoWeightSensorReadingType weight;

	/* Server Call Points */
	status = Rte_Call_rpIoGetWeight_IoGet(&weight);
	
	/* SoftWare Logic*/
	weight = (SensorWeightType)(weight/1000);
	
}

