/*
 * Bluetooth.h
 *
 *  Created on: May 22, 2021
 *      Author: kkasp
 */
/**
  ******************************************************************************
  * @file    Bluetooth.h
  * @brief   This file contains all the function prototypes for
  *          the Bluetooth.c file
  ******************************************************************************
  */
#ifndef INC_BLUETOOTH_H_
#define INC_BLUETOOTH_H_



#endif /* INC_BLUETOOTH_H_ */
#include "usart.h"
#include "sensors.h"
void SendDataBT(weather_parameters *Param, UART_HandleTypeDef *uart);
