// lcd_init.h

/*************************************************************/
/**
*  @file lcd_init.h
*  @brief Praeprozessor Anweisungen und bekanntgabe Funktion
*  @author Marvin Behrens
*
*  @date 20.05.2018 – Implementierung in dieses Projekt
*
*
*  @version 1.1
*************************************************************/

#ifndef _LCD_INIT_h
#define _LCD_INIT_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif


#endif

void lcdInit();
void menue();