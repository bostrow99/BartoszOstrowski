/*
 * DispParam.h
 *
 *  Created on: Apr 7, 2021
 *      Author: bostrow
 */
/**
  ******************************************************************************
  * @file    DispParam.h
  * @brief   This file contains all the function prototypes for
  *          the DispParam.c file
  ******************************************************************************/

#include "lcd_i2c.h"
#include <stdbool.h>
#include <stdio.h>
#include "sensors.h"
void DisplayPressure(struct lcd_disp *disp_, struct weather_parameters *param_);
void DisplayTemperature(struct lcd_disp *disp_, struct weather_parameters *param_);
void DisplayHumidity(struct lcd_disp *disp_, struct weather_parameters *param_);
void RunDisp(struct lcd_disp *disp_, struct weather_parameters *param_, int position_);
