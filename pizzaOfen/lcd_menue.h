// lcd_menue.h

/*************************************************************/
/**
*  @file lcd_menue.h
*  @brief Praeprozessor Anweisungen und Bekanntgabe der Funktion
*  @li menue()\n\n
*
*  @author Marvin Behrens
*
*
*  @version 1.1
*************************************************************/

#ifndef _LCD_MENUE_h
#define _LCD_MENUE_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif


#endif

void menue(double inputMENUE, uint16_t encPosMENUE);