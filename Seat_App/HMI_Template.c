/**
 *
 * \file HMI_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: HMI
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 5/13/2023 11:42 AM
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_HMI.h"


/**
 *
 * Runnable HMI_MainFunction
 *
 * Triggered By:
 *  - TimingEventImpl.TE_HMI_MainFunction_100ms
 *
 */

void HMI_MainFunction (void)
{
	Std_ReturnType status;
	MultiStateBtn HeightBtnState;
	MultiStateBtn InclineBtnState;
	MultiStateBtn SlideBtnState;
	uint8 Height;
	uint8 Incline;
	uint8 Slide;
	
	/* Data Receive Points */
	status = Rte_Read_rpSeatCtrlData_Height(&Height);
	status = Rte_Read_rpSeatCtrlData_Incline(&Incline);
	status = Rte_Read_rpSeatCtrlData_Slide(&Slide);
	
	/* Software Logic */
	if(RTE_Height_MAX_AGE_EXCEDDED || Rte_IsUpdated(Height) || Height == 0){
		HeightBtnState = MULTI_STATE_BTN_INIT;
	} else if(Height == 1){
		HeightBtnState = MULTI_STATE_BTN_MINUS;
	} else if(Height == 2){
		HeightBtnState = MULTI_STATE_BTN_PLUS;
	} else{
		/* Do nothing.... */
	}
	
	/* Data Send Points */
	status = Rte_Write_ppSeatCtrlBtns_HeightBtnState(HeightBtnState);
	status = Rte_Write_ppSeatCtrlBtns_InclineBtnState(InclineBtnState);
	status = Rte_Write_ppSeatCtrlBtns_SlideBtnState(SlideBtnState);
	
}


/**
 *
 * Runnable HMI_SeatModeChanged
 *
 * Triggered By:
 *  - DataReceivedEventImpl.DRE_rpSeatModeBtn_SeatModeBtn
 *
 */

void HMI_SeatModeChanged (void)
{
	Std_ReturnType status;
	SeatModeBtnType SeatModeBtn;
	uint8 SeatCtrlMode = RTE_MODE_SeatCtrlMode_INIT;

	/* Data Receive Points */
	status = Rte_Read_rpSeatModeBtn_SeatModeBtn(&SeatModeBtn);
	
	/* Software Logic */
	if(SeatModeBtn == SEAT_MODE_BTN_MANUAL){
		SeatCtrlMode = RTE_MODE_SeatCtrlMode_INIT;
	} else if(SeatModeBtn == SEAT_MODE_BTN_AUTO){
		SeatCtrlMode = RTE_MODE_SeatCtrlMode_AUTO;
	} else{
		/* Keep INIT */
	}
	
	/* Mode Switch Points */
	status = Rte_Switch_ppSeatCtrlMode_SeatCtrlMode(SeatCtrlMode);
	
}

