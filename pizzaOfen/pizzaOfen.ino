#include "ofen_init.h"
#include "Doxygen.h"
#include "ofen_heizvorgang.h"
#include "ofen_temp_wahl.h"
#include "max6675.h"
#include "lcd_menue.h"
#include "lcd_init.h"
#include "Wire.h"
#include "time.h""
#include "encoder_taster.h"
#include "encoder_init.h"
#include "encoder_links.h"
#include "encoder_rechts.h"

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

/*!
@defined
@abstract Daten Output des MAX6675
*/
#define thermoDO 11

/*!
@defined
@abstract Chip Select des MAX6675
*/
#define  thermoCS 8

/*!
@defined
@abstract Clock Signal fuer den MAX6675
*/
#define  thermoCLK 7

/** \brief Klasse aus Opensouce Quelle : max6675.h */
MAX6675 tempSens(thermoCLK, thermoCS, thermoDO);


/** \brief Betriebszustand, true == aktive heizelemente , false == Temperaturwahl */
volatile bool aktiv;

/** \brief Steht fuer eine Anforderung der Textfeldleerung des LCD zur verfuegung. */
volatile bool lcd_clear_dummy;

/** \brief Ablegeplatz der Zeit des letzten aufrufes heizvorgang() . */
uint32_t delayStempel;

/** \brief Speicherort der Ist-Temperatur. */
double input;


/**
* @file pizzaOfen.ino
* @brief Dieses file beinhaltet die setup() und loop() Funktion.\n
*
* Benutzte Open Source Funktionen aus dem Arduino.h und MAX6675.h :
* @li void setup() , wird einmalig aufgerufen.
* @li void loop() , wird staendig abgearbeitet.
* @li double MAX6675::readCelsius() , liest ueber das Serial Peripheral Interface die aktuelle Temperatur ein.\n
*
*
* @date 16.03.2018 - Erstellung des Files
*
*
* @author Marvin Behrens
*
* @version 1.0
*/

/**
*
* Initialisierung der hardware \n
*
* Nach dem einmaligen Aufruf werden encoderInit(), lcdInit() und \n
* ofenInit bearbeitet.
*
* @date 25.04.2018 - Erfolgreiche Inbetriebnahme des Ofens
*
* @bug Keine Bugs der Funktion bekannt.
*
*/

void setup() {

	encoderInit();
	lcdInit();
	ofenInit();

}

/**
*
* Endlosschleife \n
*
*
* @param	delayStempel	Zeit des letzten Funktionsaufrufes heizvorgang()\n
*							und Auslesung der Temperatur.\n
*
* @param	input			Hier wird die aktuelle Ist-Temperatur zur weiteren\n
*							Verarbeitung abgelegt.\n
*
* @param	offset			Messungenauigkeit des MAX6675 begleichen.\n
*
* @param	encPos          extern => encoder_init.cpp\n
*
* @param readPortH			Speicherbereich Prozessabbild des Port : H\n
*
* @param readPortE			Speicherbereich Prozessabbild des Port : E\n

*
* Das menue() wird staendig aufgerufen um in die Naehe einer Echtzeitfaehigen Anzeige zu gelangen.\n
* Die If() Else() Anweisung dient zur ermittlung des Betriebszustandes. \n
* li aktiv == true  => Einlesen der Daten vom MAX6675 mittels tempSens.readCelsius()\n
*						 und heizvorgang() wird ausgefuert.\n
* @li aktiv == false und die beiden relais sind noch aktiv, werden Sie \n
*	  mittels Bit Maskierungsoperationen (siehe heizvorgang() ) ausgeschaltet.\n
*
*
* @date 25.05.2018 - erfolgreicher Funktionstest am Ofen.
*
* @bug Keine Bugs der Funktion bekannt.
*
*/

void loop() {

	extern volatile uint16_t encPos;			//Laufvariable für Encoder Position ; initialisiert in encoder_init.cpp
	const uint16_t deelay = 1000;				// 1 Sekunde
	const uint16_t offset = 3;			// 3°C

	uint8_t readPortH = PORTH & 0x08;
	uint8_t readPortE = PORTE & 0x08;

	if (aktiv) {

		if(millis() - delayStempel >= deelay) {

			delayStempel = millis();

			input = tempSens.readCelsius() - offset;

			heizvorgang(input,encPos);

		}
	}
	else if((readPortH == 0x08) || (readPortE == 0x08)){	// sind die relais noch an? => abschalten

		PORTH &= ~(1 << relais1);					//ausschalten von Pin : D5 
		PORTE &= ~(1 << relais2);					//ausschalten von Pin : D6
		
	}

	menue(input, encPos);

}