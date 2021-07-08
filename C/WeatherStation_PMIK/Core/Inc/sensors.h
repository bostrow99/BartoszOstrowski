/*
 * sensors.h
 *
 *  Created on: Apr 7, 2021
 *      Author: kkasp
 */

/**
  ******************************************************************************
  * @file    sensors.h
  * @brief   This file contains structure for weather data
  */


#ifndef INC_SENSORS_H_
#define INC_SENSORS_H_


/** Struktura przechowująca w sobie informacje o zmierzonych wartościach */

typedef struct weather_parameters{


	double temperature;
	double humidity;
	double pressure;


}weather_parameters;

#endif /* INC_SENSORS_H_ */
