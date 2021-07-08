/*
 * Bluetooth.c
 *
 *  Created on: May 22, 2021
 *      Author: kkasp
 */
/**
  ******************************************************************************
  * @file            Bluetooth.c
  * @brief           Plik przechowujący w sobie funkcje do wysyłania danych przez BT
  ******************************************************************************
*/
#include "Bluetooth.h"
void SendDataBT(weather_parameters *Param, UART_HandleTypeDef *uart)
{
	/**
	 * Funkcja służąca do wysłania danych pomiarowych przez BT (żeby dostać dane na telefon, trzeba najpierw wysłać znak s)
	 * */



	 int PressureDigits = 3;	// Ustala liczbę znaków do wysłania danych o ciśnieniu w zależności od tego, jak wysokie jest ciśnienie
     if(((int)Param->pressure/1000) ==0)
    	 PressureDigits=3;
	 else
		 PressureDigits=4;


	 int TemperatureDigits = 2; // Ustala liczbę znaków do wysłania danych o temperaturze
	 if((int)Param -> temperature > 0 )
	 {
		 if((int)Param->temperature/10 == 0)
			 TemperatureDigits = 1;
		 else
			 TemperatureDigits = 2;
	 }
	 else
	 {
		if((int)Param->temperature/10 == 0)
			TemperatureDigits = 2;
		else
			TemperatureDigits = 3;

	 }


    int HumidityDigits = 3; // Ustala liczbę znaków do wysłania danych o wilgotności
	if(((int)Param->humidity/100) ==0)
		HumidityDigits=2;
		 else
		HumidityDigits=3;


	 char temp[TemperatureDigits];
	 char hum[HumidityDigits];
	 char pressure[PressureDigits];

	 char temp_BT[13] = "Temperature: ";
	 char hum_BT[10] = "Humidity: ";
	 char pressure_BT[10] = "Pressure: ";

	 sprintf(temp, "%d", (int)Param -> temperature);
	 sprintf(hum, "%d", (int)Param -> humidity);
	 sprintf(pressure, "%d", (int)Param -> pressure);

	// Przesłanie danych o temperaturze

	HAL_UART_Transmit(&huart1, temp_BT, 13,100);
	HAL_UART_Transmit(&huart1, temp, TemperatureDigits,100);
	HAL_UART_Transmit(&huart1, " 'C", 3,100);
	HAL_UART_Transmit(&huart1, "\n", 1,100);

	// Przesłanie danych o wilgotności

	HAL_UART_Transmit(&huart1, hum_BT, 10,100);
	HAL_UART_Transmit(&huart1, hum, HumidityDigits,100);
	HAL_UART_Transmit(&huart1, "%", 1,100);
	HAL_UART_Transmit(&huart1, "\n", 1,100);

	// Przesłanie danych o ciśnieniu

	HAL_UART_Transmit(&huart1, pressure_BT, 10,100);
	HAL_UART_Transmit(&huart1, pressure, PressureDigits,100);
	HAL_UART_Transmit(&huart1, " hPa", 4,100);
	HAL_UART_Transmit(&huart1, "\n", 1,100);

}
