/**
 *
 * \file SeatMrg_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: SeatMrg
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 5/8/2023 08:54 AM
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_SeatMrg.h"


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

