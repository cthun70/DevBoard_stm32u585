/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    ux_device_cdc_acm.c
  * @author  MCD Application Team
  * @brief   USBX Device applicative file
  ******************************************************************************
    * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "ux_device_cdc_acm.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
UX_SLAVE_CLASS_CDC_ACM *cdc_acm;
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
UX_SLAVE_CLASS_CDC_ACM_CALLBACK_PARAMETER cdc_acm_slave_callback;

int Test = 0;
UCHAR RcvByte;
UINT USBX_cdc_acm_device_read_callback(struct UX_SLAVE_CLASS_CDC_ACM_STRUCT *cdc_acm, UINT status, UCHAR *data_pointer, ULONG length)
{

	RcvByte = *data_pointer;
	Test = length;
	return 0;
}

UINT USBX_cdc_acm_device_write_callback(struct UX_SLAVE_CLASS_CDC_ACM_STRUCT *cdc_acm, UINT status, ULONG length)
{

	return 0;
}
/* USER CODE END 0 */

/**
  * @brief  USBD_CDC_ACM_Activate
  *         This function is called when insertion of a CDC ACM device.
  * @param  cdc_acm_instance: Pointer to the cdc acm class instance.
  * @retval none
  */
VOID USBD_CDC_ACM_Activate(VOID *cdc_acm_instance)
{
  /* USER CODE BEGIN USBD_CDC_ACM_Activate */
  UX_PARAMETER_NOT_USED(cdc_acm_instance);
  cdc_acm = cdc_acm_instance;


  cdc_acm_slave_callback.ux_device_class_cdc_acm_parameter_read_callback = USBX_cdc_acm_device_read_callback;
  cdc_acm_slave_callback.ux_device_class_cdc_acm_parameter_write_callback = USBX_cdc_acm_device_write_callback;
  ux_device_class_cdc_acm_ioctl(cdc_acm, UX_SLAVE_CLASS_CDC_ACM_IOCTL_TRANSMISSION_START, (VOID*)&cdc_acm_slave_callback);
  /* USER CODE END USBD_CDC_ACM_Activate */

  return;
}

/**
  * @brief  USBD_CDC_ACM_Deactivate
  *         This function is called when extraction of a CDC ACM device.
  * @param  cdc_acm_instance: Pointer to the cdc acm class instance.
  * @retval none
  */
VOID USBD_CDC_ACM_Deactivate(VOID *cdc_acm_instance)
{
  /* USER CODE BEGIN USBD_CDC_ACM_Deactivate */
  UX_PARAMETER_NOT_USED(cdc_acm_instance);
  /* USER CODE END USBD_CDC_ACM_Deactivate */

  return;
}

/**
  * @brief  USBD_CDC_ACM_ParameterChange
  *         This function is invoked to manage the CDC ACM class requests.
  * @param  cdc_acm_instance: Pointer to the cdc acm class instance.
  * @retval none
  */
VOID USBD_CDC_ACM_ParameterChange(VOID *cdc_acm_instance)
{
  /* USER CODE BEGIN USBD_CDC_ACM_ParameterChange */
  UX_PARAMETER_NOT_USED(cdc_acm_instance);
  /* USER CODE END USBD_CDC_ACM_ParameterChange */

  return;
}

/* USER CODE BEGIN 1 */
UCHAR UserRxBuffer[64];

UCHAR* usbx_cdc_acm_read_process(int* Size)
{
	if(cdc_acm!=0)
	{
		ULONG rx_actual_length=0;
		ux_device_class_cdc_acm_read_run(cdc_acm, (UCHAR *)UserRxBuffer, 64, &rx_actual_length);
		if(rx_actual_length>0)
		{
			*Size = (int)rx_actual_length;
			return UserRxBuffer;
		}
	}
	return 0;
}

int usbx_cdc_acm_write_process(UCHAR* msg, int Size)
{
      /* Private Variables */
#if 0
	unsigned int tx_actual_length;
	ux_device_class_cdc_acm_write_run(cdc_acm, (UCHAR *)(msg), Size, (ULONG *)&tx_actual_length);
	return(tx_actual_length);
#else
	ux_device_class_cdc_acm_write_with_callback(cdc_acm, (UCHAR *)(msg), Size);
	return 0;
#endif
}
/* USER CODE END 1 */
