 #include "pwm_ausgabe.h"
#include "pwm_init.h"

/*!
@defined
@abstract Pin fuer PWM Ausgabe
*/
#define Luefter 6

/**
* @file pwm_ausgabe.cpp
* @brief Dieses file beinhaltet die pwm_ausgabe() .
*
* Benutzte Funktionen aus open Source Quelle <Arduino.h> :
* @li analogWrite()
* @date 19.03.2018 - Erstellung des Files
*
* @author Marvin Behrens
*
* @version 1.0
*/


/**
*
* Festlegung Tastverhaeltniss in Abheangigkeit der Temperatur \n
*
* @param[in] input			Gemessene Temperatur zwischen Garraum und Gehaeuse.
*
*
* @param	 pwmValue		Tastverhaeltniss in Prozent.\n
*
*
*  Der eingabeparameter "input" wird ausgewertet, der dadurch ermittelte Wert wird in die Variable \n
*  pwmValue geschrieben und spiegelt das Tastverhaeltniss wieder (in Prozent).\n
*  Zur Ausgabe wird analogWrite( Pin, pwmValue) verwendet:
*  
*
*
* @date 25.04.2018 - erfolgreicher Funktionstest mit Querstromluefter.
*
* @bug Keine Bugs der Funktion bekannt.
*
*/


void pwm_ausgabe(uint16_t input) {
	
	uint8_t pwmValue = 0;

	if (input <= 28) {
		pwmValue = 0;
	}

	else if (input > 30 && input <= 40) {
		pwmValue = 50;
	}
	else if (input > 40 && input <= 50) {
		pwmValue = 60;
	}
	else if (input > 50 && input <= 55) {
		pwmValue = 70;
	}
	else if (input > 55 && input <= 60) {
		pwmValue = 85;
	}
	else if (input > 60) {
		pwmValue = 100;
	}
	
	analogWrite(Luefter, pwmValue);
}