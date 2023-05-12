/**
 *
 * \file IoHwAbs_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: IoHwAbs
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 5/12/2023 04:20 PM
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_IoHwAbs.h"

/* For reading the position sensors */
#include "Adc.h"

/* For reading the weight */
#include "Spi.h"

/* For controlling the motors */
#include "Dio.h"


/**
 *
 * Runnable IoHwAbs_ECUGet_Height
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppIoGetHieght_IoGet
 *
 */

void IoHwAbs_ECUGet_Height (IoPositionSensorReadingType* position)
{
	Std_ReturnType status;
	
	status = Adc_ReadGroup(AdcConf_AdcGroup_PositionsSensorsGrp , &position);
	
	if(status != E_OK){
		/* here the code to handle the error */
	} else{
		/* Do nothing... */
	}
	
}


/**
 *
 * Runnable IoHwAbs_ECUGet_Incline
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppIoGetIncline_IoGet
 *
 */

void IoHwAbs_ECUGet_Incline (IoPositionSensorReadingType* position)
{
	Std_ReturnType status;
	
	status = Adc_ReadGroup(AdcConf_AdcGroup_PositionsSensorsGrp , &position);
	
	if(status != E_OK){
		/* here the code to handle the error */
	} else{
		/* Do nothing... */
	}

}


/**
 *
 * Runnable IoHwAbs_ECUGet_Slide
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppIoGetSlide_IoGet
 *
 */

void IoHwAbs_ECUGet_Slide (IoPositionSensorReadingType* position)
{
	Std_ReturnType status;
	
	status = Adc_ReadGroup(AdcConf_AdcGroup_PositionsSensorsGrp , &position);
	
	if(status != E_OK){
		/* here the code to handle the error */
	} else{
		/* Do nothing... */
	}

}


/**
 *
 * Runnable IoHwAbs_ECUGet_Weight
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppIoGetWeight_IoGet
 *
 */

void IoHwAbs_ECUGet_Weight (IoWeightSensorReadingType* weight)
{
	Std_ReturnType status;
	
	status = Spi_ReadIB(SpiConf_SpiChannel_WeightSensor , &weight);
	
	if(status != E_OK){
		/* here the code to handle the error */
	} else{
		/* Do nothing... */
	}

}


/**
 *
 * Runnable IoHwAbs_ECUSetForward_Height
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppIoSetHeight_IoSetForward
 *
 */

void IoHwAbs_ECUSetForward_Height (void)
{
	Std_ReturnType status;
	
	status = Dio_WriteChannel(DioConf_DioChannel_HeightMotorCh, STD_HIGH);

}


/**
 *
 * Runnable IoHwAbs_ECUSetForward_Incline
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppIoSetIncline_IoSetForward
 *
 */

void IoHwAbs_ECUSetForward_Incline (void)
{
	Std_ReturnType status;
	
	status = Dio_WriteChannel(DioConf_DioChannel_InclineMotorCh, STD_HIGH);

}


/**
 *
 * Runnable IoHwAbs_ECUSetForward_Slide
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppIoSetSlide_IoSetForward
 *
 */

void IoHwAbs_ECUSetForward_Slide (void)
{
	Std_ReturnType status;
	
	status = Dio_WriteChannel(DioConf_DioChannel_SlideMotorCh, STD_HIGH);

}


/**
 *
 * Runnable IoHwAbs_ECUSetReverse_Height
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppIoSetHeight_IoSetReverse
 *
 */

void IoHwAbs_ECUSetReverse_Height (void)
{
	Std_ReturnType status;
	
	status = Dio_WriteChannel(DioConf_DioChannel_HeightMotorCh, STD_LOW);

}


/**
 *
 * Runnable IoHwAbs_ECUSetReverse_Incline
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppIoSetIncline_IoSetReverse
 *
 */

void IoHwAbs_ECUSetReverse_Incline (void)
{
	Std_ReturnType status;
	
	status = Dio_WriteChannel(DioConf_DioChannel_InclineMotorCh, STD_LOW);

}


/**
 *
 * Runnable IoHwAbs_ECUSetReverse_Slide
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppIoSetSlide_IoSetReverse
 *
 */

void IoHwAbs_ECUSetReverse_Slide (void)
{
	Std_ReturnType status;
	
	status = Dio_WriteChannel(DioConf_DioChannel_SlideMotorCh, STD_LOW);

}

