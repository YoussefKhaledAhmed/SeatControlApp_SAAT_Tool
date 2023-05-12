/**
 *
 * \file HeightMotor_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: HeightMotor
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 5/12/2023 04:20 PM
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_HeightMotor.h"


/**
 *
 * Runnable HeightMotor_Move
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppHeightMotor_Move
 *
 */

void HeightMotor_Move (StepMotorStepType step)
{
	Std_ReturnType status;

	/* Server Call Points */
	if(step == MOTOR_STEP_PLUS){
		status = Rte_Call_rpIoSetHeight_IoSetForward();
	} else if(step == MOTOR_STEP_MINUS){
		status = Rte_Call_rpIoSetHeight_IoSetReverse();
	} else{
		/*Do nothing... */
	}
	
}

