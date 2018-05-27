// ofen_init.h

/*************************************************************/
/**
*  @file ofen_init.h
*  @brief Praeprozessor Anweisungen und Bekanntgabe der Funktion
*  @li ofenInit()\n\n
*
*  @author Marvin Behrens
*
*
*  @version 1.1
*************************************************************/

#ifndef _OFEN_INIT_h
#define _OFEN_INIT_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif


#endif

void ofenInit();