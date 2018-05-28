#include "encoder_init.h"
#include "encoder_links.h"
#include "encoder_rechts.h"
#include "encoder_taster.h"

/*!
@defined
@abstract Pin zur detektierung rechter Umdrehungsimpulse
*/
#define pinRechts PD3				//++

/*!
@defined
@abstract Pin zur detektierung linker Umdrehungsimpulse
*/
#define pinLinks  PD2						//--

/*!
@defined
@abstract Pin des Tasters
*/
#define pinTaster  PE4					//Taster

extern volatile bool lcd_clear_dummy;
extern volatile bool aktiv;
/** \brief Dient der Auswertung des Dreh Encoders  */
volatile byte rechtsFlag;					//Hilfsvariable zur Auswertung
/** \brief Dient der Auswertung des Dreh Encoders  */
volatile byte linksFlag;					//Hilfsvariable zur Auswertung
/** \brief Aktuelle Position; 0-65635 */
volatile uint16_t encPos;					//Laufvariable für Encoder Position
/** \brief Zum Abfragen des Zustandes an PORTD */
volatile byte readPort;						//Hilfsvariable zur Auswertung
/** \brief Zeit des letzten Aufrufes der tasterPressedISR */
uint32_t volatile zeitStempel;				// wann wurde das letzte mal gedrückt?

/**
* @file encoder_init.cpp
* @brief Dieses file beinhaltet die encoderInit() Funktion
*
* Verwendung einer Funktion aus Open Source Quelle zum initialisieren\n
* der Interrupt Rutinen. attachinterrupt(). Dieser Aufruf bekommt 3 Parameter mitgegeben: \n
* @li digitalPinToInterrupt(Pin) - Gewuenschter Pin .
* @li Name der ISR, sozusagen die Hinsprung Adresse.
* @li Art der Detecktion, steigende/fallende Flanke.
*
* @date 17.03.2018 - Erstellung des Files
*
* @author Marvin Behrens
*
* @version 1.0
*/


/**
*
* Bekanntgabe der hinsprung-Adressen und \n
* Initialisierung der benötigten Variablen der Interrupt Sub Rutinen : \n
* @li rechtslaufISR()
* @li linkslaufISR()
* @li tasterPressedISR()
*
* Ausserdem werden für die Pins, des Encoders, speziefische konfigurationen gewählt: \n
* @li INPUT
* @li PULL-UP (Widerstand)
* @li detektion der steigenden Flanke
*
* @date 20.04.2018 - erfolgreicher Funktionstest mit Hardware
*
* @bug Keine Bugs der Funktion bekannt.
*
*/
void encoderInit() {

	uint8_t temp;
	aktiv = false;
	lcd_clear_dummy = true;

	rechtsFlag = 0;
	linksFlag = 0;
	encPos = 1;	
	readPort = 0;

	DDRE &= ~(1 << PE4);   // setzte Pin2 als eingang

	PORTE |= (1 << PE4);   // aktiviere pull-up widerstand

	DDRD &= ~((1 << PD2) | (1 << PD3));   // setzte Pin18 & 19 als eingang

	PORTD |= (1 << PD2) | (1 << PD3);   // aktiviere pull-up widerstaende

	attachInterrupt(digitalPinToInterrupt(19), rechtslaufISR, RISING);	//rechts
	attachInterrupt(digitalPinToInterrupt(18), linkslaufISR, RISING);		//links
	attachInterrupt(digitalPinToInterrupt(2), tasterPressedISR, RISING);		//taster
}
