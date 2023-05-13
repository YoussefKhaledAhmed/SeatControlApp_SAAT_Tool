/**
 *
 * \file SeatMrg_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: SeatMrg
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 5/10/2023 01:28 PM
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_SeatMrg.h"
#define boolean bool


static boolean isMotorAdjustNeeded(SensorPositionType position , SensorWeightType weight , StepMotorStepType *step){
	boolean adjustMotor = FALSE;
	
	switch(position)
	{
		case SENSOR_POSITION_STEP_0:
			if(weight > 60){
				*step = MOTOR_STEP_PLUS;
				adjustMotor = TRUE;
			} else{
				/* Do nothing... */
			}
			break;
			
		case SENSOR_POSITION_STEP_1:
			if(weight > 80){
				*step = MOTOR_STEP_PLUS;
				adjustMotor = TRUE;
			} else if(weight <= 80 && weight >= 60){
				/* Position Ok*/
			} else{
				*step = MOTOR_STEP_MINUS;
				adjustMotor = TRUE;
			}
			break;
			
		case SENSOR_POSITION_STEP_2:
			if(weight > 100){
				*step = MOTOR_STEP_PLUS;
				adjustMotor = TRUE;
			} else if(weight <= 100 && weight >= 80){
				/* Position Ok */
			} else{
				*step = MOTOR_STEP_MINUS;
				adjustMotor = TRUE;
			}
			break;
			
		case SENSOR_POSITION_STEP_3:
			if(weight < 100){
				*step = MOTOR_STEP_MINUS;
				adjustMotor = TRUE;
			} else{
				/* Do nothing... */
			}
			break;
			
		default:
			break;
	}
	
	return adjustMotor;
}


/**
 *
 * Runnable SeatManager_AutoHeight
 *
 * Triggered By:
 *  - TimingEventImpl.TE_SeatManager_AutoHeight_200ms
 *
 */

void SeatManager_AutoHeight (void)
{
	Std_ReturnType status;
	StepMotorStepType step;
	SensorPositionType position;
	SensorWeightType weight;
	boolean adjustMotor;

	/* Server Call Points */
	(void)Rte_Call_rpHeightSensor_GetPosition(&position);
	(void)Rte_Call_rpWeightSensor_GetWeight(&weight);
	
	adjustMotor = isMotorAdjustNeeded(position, weight, &step);
	if(adjustMotor){
		(void)Rte_Call_rpHeightMotor_Move(step);
	}
}


/**
 *
 * Runnable SeatManager_AutoIncline
 *
 * Triggered By:
 *  - TimingEventImpl.TE_SeatManager_AutoIncline_200ms
 *
 */

void SeatManager_AutoIncline (void)
{
	Std_ReturnType status;
	StepMotorStepType step;
	SensorPositionType position;
	SensorWeightType weight;
	boolean adjustMotor;

	/* Server Call Points */
	status = Rte_Call_rpInclineSensor_GetPosition(&position);
	status = Rte_Call_rpWeightSensor_GetWeight(&weight);
	
	adjustMotor = isMotorAdjustNeeded(position, weight, &step);
	if(adjustMotor){
		(void)Rte_Call_rpInclineMotor_Move(step);
	}
	
}


/**
 *
 * Runnable SeatManager_AutoSlide
 *
 * Triggered By:
 *  - TimingEventImpl.TE_SeatManager_AutoSlide_200ms
 *
 */

void SeatManager_AutoSlide (void)
{
	Std_ReturnType status;
	StepMotorStepType step;
	SensorPositionType position;
	SensorWeightType weight;
	boolean adjustMotor;

	/* Server Call Points */
	status = Rte_Call_rpSlideSensor_GetPosition(&position);
	status = Rte_Call_rpWeightSensor_GetWeight(&weight);
	
	adjustMotor = isMotorAdjustNeeded(position, weight, &step);
	if(adjustMotor){
		(void)Rte_Call_rpSlideMotor_Move(step);
	}
}


/**
 *
 * Runnable SeatManager_SetHeight
 *
 * Triggered By:
 *  - DataReceivedEventImpl.DRE_rpSeatCtrlBtns_HeightBtnState
 *
 */

void SeatManager_SetHeight (void)
{
	Std_ReturnType status;
	MultiStateBtn HeightBtnState;

	/* Data Receive Points */
	status = Rte_Read_rpSeatCtrlBtns_HeightBtnState(&HeightBtnState);
	
	/* Software Logic */
	if(HeightBtnState == MULTI_STATE_BIN_MINUS){
		Rte_Call_rpHeightMotor_Move(MOTOR_STEP_MINUS);
	} else if(HeightBtnState == MULTI_STATE_BIN_PLUS){
		Rte_Call_rpHeightMotor_Move(MOTOR_STEP_PLUS);
	} else{
		/* Do nothing.... */
	}
}


/**
 *
 * Runnable SeatManager_SetIncline
 *
 * Triggered By:
 *  - DataReceivedEventImpl.DRE_rpSeatCtrlBtns_InclineBtnState
 *
 */

void SeatManager_SetIncline (void)
{
	Std_ReturnType status;
	MultiStateBtn InclineBtnState;

	/* Data Receive Points */
	status = Rte_Read_rpSeatCtrlBtns_InclineBtnState(&InclineBtnState);
	
	/* Software Logic */
	if(InclineBtnState == MULTI_STATE_BIN_MINUS){
		Rte_Call_rpInclineMotor_Move(MOTOR_STEP_MINUS);
	} else if(InclineBtnState == MULTI_STATE_BIN_PLUS){
		Rte_Call_rpInclineMotor_Move(MOTOR_STEP_PLUS);
	} else{
		/* Do nothing.... */
	}
	
}


/**
 *
 * Runnable SeatManager_SetSlide
 *
 * Triggered By:
 *  - DataReceivedEventImpl.DRE_rpSeatCtrlBtns_SlideBtnState
 *
 */

void SeatManager_SetSlide (void)
{
	Std_ReturnType status;
	MultiStateBtn SlideBtnState;

	/* Data Receive Points */
	status = Rte_Read_rpSeatCtrlBtns_SlideBtnState(&SlideBtnState);
	
	/* Software Logic */
	if(SlideBtnState == MULTI_STATE_BIN_MINUS){
		Rte_Call_rpSlideMotor_Move(MOTOR_STEP_MINUS);
	} else if(SlideBtnState == MULTI_STATE_BIN_PLUS){
		Rte_Call_rpSlideMotor_Move(MOTOR_STEP_PLUS);
	} else{
		/* Do nothing.... */
	}
	
}