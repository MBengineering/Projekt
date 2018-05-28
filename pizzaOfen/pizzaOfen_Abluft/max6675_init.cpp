
#include "max6675_init.h"
#include "max6675.h"

/*!
@defined
@abstract 5V fuer MAX6675
*/
#define supply PC2

/*!
@defined
@abstract Daten Output des MAX6675
*/
#define thermoDO 4

/*!
@defined
@abstract Chip Select des MAX6675
*/
#define  thermoCS 3

/*!
@defined
@abstract Clock Signal fuer den MAX6675
*/
#define  thermoCLK 2

/** \brief Klasse aus Opensouce Quelle : max6675.h */
MAX6675 tempSens(thermoCLK, thermoCS, thermoDO);


/**
* @file max6675_init.cpp
* @brief Dieses file beinhaltet die max6675_init() Funktion.
*
*
* @date 19.03.2018 - Erstellung des Files
*
* @author Marvin Behrens
*
* @version 1.0
*/


/**
* Initialisierung des Spannungsversorgungspins fuer den Sensor.
*
* @li (1<<n) schiebt eine 1 an Stelle n eines Bytes.
* @li |		 PORTn wird mit Maske Bitweise verODERT.
*
*
* @date 20.04.2018 - erfolgreicher Funktionstest mit Hardware.
*
* @bug Keine Bugs der Funktion bekannt.
*
*/

void max6675_init() {

	DDRC |= (1 << PC2);
	PORTC |= (1 << PC2);
}

