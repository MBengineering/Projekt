// 
// 
// 

#include "pwm_init.h"
/*!
@defined
@abstract Pin fuer PWM Ausgabe
*/
#define outputPin PD6


/**
* @file pwm_init.cpp
* @brief Dieses file beinhaltet die pwm_init() .
*
*
* @author Marvin Behrens
*
* @version 1.0
*/


/**
*
* Initialisierung der 8-Bit Timer \n
*
*
*  Datenrichtungsregister wird fuer den Pin an dem der Luefter bzw \n
*  das Gate vom Mosfet angeschlossen ist manipuliert. => Pin6 Output
*  
* @li Das setzten der bits WGM01 und WGM00 wird der fast pwm mode gewaehlt.
* @li Das setzten des Bits COM0B1, wird das Output Capture Register\n
*     zurueckgesetzt.
* @li Im TCCR0B wird der Prescaler auf 8 konfiguriert. => 7.8kHz pwm Grundfrequenz. \n
*
*
* @date 25.04.2018 - erfolgreicher Funktionstest mit Querstromluefter.
*
* @bug Keine Bugs der Funktion bekannt.
*
*/

void pwm_init() {

	TCCR0A = 0x00;
	TCCR0B = 0x00;

	TCCR0A = (1 << COM0B1) | (1 << WGM01) | (1 << WGM00);
	TCCR0B = (1 << CS01);

	DDRD |= (1 << PD6);
}