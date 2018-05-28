#include "ofen_heizvorgang.h"
#include <Arduino.h>

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
* @file ofen_heizvorgang.cpp
* @brief Dieses file beinhaltet die heizvorgang() Funktion.
*
* @date 19.03.2018 - Erstellung des Files
*
* @author Marvin Behrens
*
* @version 1.0
*/


/**
*
* Textausgabe auf dem LCD \n
*
* @param[in] inputHEIZEN	Instanziierung der Ist-Temperatur
*
* @param[in] encPosMENUE	Instanziierung der Encoder Position \n
*							(Welche quasi fuer die Soll- bzw. Zieltemperatur steht\n
*
* @param	 init			Dient der einmaligen konfiguration der Relais-Pins.\n
*
* @param	 obereGrenze	Beim ueberschreiten dieser Temperatur werden die Relais abgeschaltet.\n

* @param	 untereGrenze	Beim unterschreiten dieser Temperatur werden die Relais zugeschaltet.\n
*
* @param	Sollwert()      extern => ofen_temp_wahl.cpp
* 

*  Es erfolgt eine kalibrierung des kritischen Temperaturbereichs.
*  In der letzten If (else) Anweisung wird sowohl der MIN- als auch\n
*  MAX-Wert des Bereichs staendig mit der Ist-Temperatur verglichen.
*  Nach diesen Vergleichen erfolgt eine entsprechende Bit Maskierungs\n
*  Operation um eine zu- oder abschaltung der Relais zu erzielen.
*
* @li (1<<n) schiebt eine 1 an Stelle n eines Bytes.
* @li ~		 invertiert die Maske . (Aus 00001000 wird 11110111)
* @li &		 PORTn wird mit Maske Bitweise verUNDET.
* @li |		 PORTn wird mit Maske Bitweise verODERT.
*
*
* @date 20.04.2018 - erfolgreicher Funktionstest mit signal LEDs anstelle der Relais.
* @date 25.04.2018 - erfolgreicher Funktionstest mit Relais.
*
* @bug Keine Bugs der Funktion bekannt.
*
*/

void heizvorgang(double inputHEIZEN,uint16_t encPosHEIZEN) {

	extern double Sollwert(uint16_t zwAblage);

	double obereGrenze = 0;
	double untereGrenze = 0;


	obereGrenze = (Sollwert(encPosHEIZEN) * 1.01);
	untereGrenze = (Sollwert(encPosHEIZEN) * 0.99);

	if (inputHEIZEN >= obereGrenze) {

		PORTH &= ~(1 << relais1);					//ausschalten von Pin : D5 
		PORTE &= ~(1 << relais2);					//ausschalten von Pin : D6
	}
	else if (inputHEIZEN <= untereGrenze) {

		PORTH |= (1 << relais1);				//zuschalten von Pin : D5
		PORTE |= (1 << relais2);				//zuschalten von Pin : D6
	}

}