/*
 * bm2180_2.h
 *
 *  Created on: 28 mar 2021
 *      Author: kkasp
 */
/**
  ******************************************************************************
  * @file    bmp180.h
  * @brief   This file contains all the function prototypes for
  *          the bmp180.c file
  ******************************************************************************/

#ifndef INC_BMP2180_2_H_
#define INC_BMP2180_2_H_



#endif /* INC_BMP2180_2_H_ */

#include "i2c.h"

typedef struct bmp_state {
	I2C_HandleTypeDef * i2c;
	int16_t AC1, AC2, AC3, B1, B2, MB, MC, MD;
	uint16_t AC4, AC5, AC6;
	int32_t UT, UP, B5;
} bmp_state;

bmp_state bmp_init(I2C_HandleTypeDef * i2c);
uint8_t bmp_read_data(bmp_state * state, uint8_t reg);
void bmp_write_data(bmp_state * state, uint8_t reg, uint8_t value);
void bmp_read_compensation_data(bmp_state * state);
void bmp_read_temp_and_pressure(bmp_state * state);
double bmp_get_temperature(bmp_state * state);
double bmp_get_pressure(bmp_state * state);
double bmp_get_altitude(double p, double p0);
