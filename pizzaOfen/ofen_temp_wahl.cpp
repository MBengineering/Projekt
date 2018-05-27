#include "ofen_temp_wahl.h"

/**
* @file ofen_temp_wahl.cpp
* @brief Dieses file beinhaltet die Sollwert() Funktion.
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
* Umrechnung Encoder Position => Sollwert \n
*
* @param[in] zwAblage	    "zwischen Ablage", Instanziierung der Encoder Position.
*
* @return					Soll- / Zieltemperatur \n\n
*
*
*
*  Dient der Umrechnung der Encoder Position mit dem Faktor 10\n
*  zur gewuenschten Solltemperatur.
*  Da der der MAX6675 einen Wert in Gleitkommaarithmetik liefert,\n
*  wird die integer Variable mit einer Gleitkommazahl verrechnet\n
*  und als return Wert dem Platzhalter "Sollwert" vom Typ double uebergeben\n
*
*
* @date 18.04.2018 - erfolgreicher Funktionstest.
*
* @bug Keine Bugs der Funktion bekannt.
*
*/

double Sollwert(uint16_t zwAblage) {

	return(zwAblage * 10.0);
}