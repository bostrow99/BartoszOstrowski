/**
 * DispParam.c
 *
 *  Created on: Apr 7, 2021
 *      Author: bostrow
 */
/**
  ******************************************************************************
  * @file            DispParam.c
  * @brief           Plik przechowujący w sobie funkcje do wyświetlania informacji na LCD
  ******************************************************************************
*/
#include "DispParam.h"
#include "lcd_i2c.h"
#include <stdbool.h>
#include <stdio.h>
#include "sensors.h"


void DisplayPressure(struct lcd_disp *disp_, struct weather_parameters *param_){

/**Funkcja wyświetlania ciśnienia pobranego ze struktury typu weather_parameters
arg: "struktura wyświetlacza", "struktura parametrów pogody" */
	
	if(param_->pressure==0){								// Gdy brak danych
		sprintf((char *)disp_->f_line,"Oczekiwanie");		// Załadowanie pierwszej linijki
		sprintf((char *)disp_->s_line,"na pomiar...:");		// Załadowanie drugiej linijki
	}
	else{													// Gdy dane pobrane poprawnie
		
	  lcd_init(disp_);										// inicjalizacja obrazu
	  int pressure_int=(int)param_->pressure;				// pobranie danej do bufora
	  sprintf((char *)disp_->f_line,"Pressure:");			// Załadowanie pierwszej linijki
	  sprintf((char *)disp_->s_line,"%d hPa",pressure_int);	// Załadowanie drugiej linijki
	}

}


void DisplayTemperature(struct lcd_disp *disp_, struct weather_parameters *param_){

/**Funkcja wyświetlania temperatury pobranego ze struktury typu weather_parameters
arg: "struktura wyświetlacza", "struktura parametrów pogody"*/
	
	if(param_->temperature==0){
		sprintf((char *)disp_->f_line,"Oczekiwanie");
		sprintf((char *)disp_->s_line,"na pomiar...:");	
	}
	else{
	  lcd_init(disp_);
	  int temperature_int=(int)param_->temperature;
	  sprintf((char *)disp_->f_line,"Temperature:");
	  sprintf((char *)disp_->s_line,"%d 'C",temperature_int);
	}

}


void DisplayHumidity(struct lcd_disp *disp_, struct weather_parameters *param_){

/**Funkcja wyświetlania wilgotniści pobranego ze struktury typu weather_parameters
arg: "struktura wyświetlacza", "struktura parametrów pogody"*/
	
	if(param_->humidity==0){
		sprintf((char *)disp_->f_line,"Oczekiwanie");
		sprintf((char *)disp_->s_line,"na pomiar...:");	
	}
	else{
	  lcd_init(disp_);
	  int humidity_int=(int)param_->humidity;
	  sprintf((char *)disp_->f_line,"Humidity:");
	  sprintf((char *)disp_->s_line,"%d %%",humidity_int);
	}

}



void RunDisp(struct lcd_disp *disp_, struct weather_parameters *param_, int position_){

/**Funkcja wyboru wyświetlenia odpowiedniego paratemtru pogodowego
arg: "struktura wyświetlacza", "struktura parametrów pogody", "licznik 0-2"*/

	lcd_init(disp_);	// inicjalizacja wyświeltacza
	switch(position_)
	{
		case 0:
			DisplayPressure(disp_,param_);

			break;
		
		case 1:
			DisplayTemperature(disp_,param_);		
			break;
				
		case 2:
			DisplayHumidity(disp_,param_);		
			break;

	}
	lcd_display(disp_);			// Wyświetlenie załadowanych wcześniej danych
}




