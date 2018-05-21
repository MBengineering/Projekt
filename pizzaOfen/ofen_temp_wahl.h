// ofen_temp_wahl.h

/*************************************************************/
/**
*  @file ofen_temp_wahl.h
*  @brief Praeprozessor Anweisungen und bekanntgabe Funktion
*  @author Marvin Behrens
*
*  @date 20.05.2018 – Implementierung in dieses Projekt
*
*
*  @version 1.1
*************************************************************/

#ifndef _OFEN_TEMP_WAHL_h
#define _OFEN_TEMP_WAHL_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif


#endif

double Sollwert(uint16_t zwAblage);
