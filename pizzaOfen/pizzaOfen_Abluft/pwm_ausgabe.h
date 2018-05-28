// pwm_ausgabe.h

/*************************************************************/
/**
*  @file pwm_ausgabe.h
*  @brief Praeprozessor Anweisungen und Bekanntgabe der Funktion
*  @li pwm_ausgabe\n\n
*
*  @author Marvin Behrens
*
*
*  @version 1.1
*************************************************************/

#ifndef _PWM_AUSGABE_h
#define _PWM_AUSGABE_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif


#endif

void pwm_ausgabe(uint8_t input);