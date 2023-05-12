/**
 *
 * \file SlideMotor_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: SlideMotor
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 5/12/2023 04:20 PM
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_SlideMotor.h"


/**
 *
 * Runnable SlideMotor_Move
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppSlideMotor_Move
 *
 */

void SlideMotor_Move (StepMotorStepType step)
{
	Std_ReturnType status;

	/* Server Call Points */
	if(step == MOTOR_STEP_PLUS){
		status = Rte_Call_rpIoSetSlide_IoSetForward();
	} else if(step == MOTOR_STEP_MINUS){
		status = Rte_Call_rpIoSetSlide_IoSetReverse();
	} else{
		/* Do nothing... */
	}
	
}

