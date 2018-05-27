// ofen_heizvorgang.h

/*************************************************************/
/**
*  @file ofen_heizvorgang.h
*  @brief Praeprozessor Anweisungen und Bekanntgabe der Funktion
*  @li heizvorgang()\n\n
*
*  @author Marvin Behrens
*
*
*  @version 1.1
*************************************************************/

#ifndef _OFEN_HEIZVORGANG_h
#define _OFEN_HEIZVORGANG_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif


#endif

void heizvorgang(double inputHEIZEN, uint16_t encPosHEIZEN);
