
#include "ofen_init.h"

/*!
@defined
@abstract Pin des 1. Relais bzw der Oberhitze.
*/
#define relais1		PH3		//oberes Heizelement

/*!
@defined
@abstract Pin des 2. Relais bzw der Unterhitze.
*/
#define relais2		PE3		//unteres Heizelement


/**
* @file ofen_init.cpp
* @brief Dieses file beinhaltet die ofenInit() .
*
*
* @date 19.03.2018 - Erstellung des Files
*
* @author Marvin Behrens
*
* @version 1.0
*/

/**
*
* Initialisierung der Daten Richtungs Register fuer die Ofenrelais \n
*
* @date 25.04.2018 - erfolgreicher Funktionstest am Ofen.
*
* @bug Keine Bugs der Funktion bekannt.
*
*/
void ofenInit() {

	DDRH |= (1 << relais1);				//initialisierung : Pin 5 (PH3) = OUTPUT
	DDRE |= (1 << relais2);				//initialisierung : Pin 6 (PE3) = OUTPUT

}
