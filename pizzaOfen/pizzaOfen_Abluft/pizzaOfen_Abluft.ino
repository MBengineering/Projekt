#include "Doxygen.h"
#include "max6675_init.h"
#include "pwm_ausgabe.h"
#include "pwm_init.h"
#include "max6675.h"
#include <time.h>

/** \brief Zeit des letzten Funktionsaufrufes pwm_ausgabe() und Auslesung der Temperatur.\n . */
uint32_t zeitStempel;

/**
* @file pizzaOfen_Abluft.ino
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
* Nach dem einmaligen Aufruf werden pwm_init(), max6675_init() und \n
* bearbeitet.
*
* @date 25.05.2018 - Erfolgreiche Inbetriebnahme des Ofens
*
* @bug Keine Bugs der Funktion bekannt.
*
*/

void setup() {

	pwm_init();
	max6675_init();
	delay(100);
	Serial.begin(9600);
}

/**
*
* Endlosschleife \n
*
*
* @param	zeitStempel		Zeit des letzten Funktionsaufrufes pwm_ausgabe()\n
*							und Auslesung der Temperatur.\n
*
* @param	input			Hier wird die aktuelle Ist-Temperatur zur weiteren\n
*							Verarbeitung abgelegt.\n
*
* @param	offset			Messungenauigkeit des MAX6675 begleichen.\n
*
*
* Da die Funktion : millis() auf die gleichen Timerregister zugreift, \n
* welche wir fuer unsere PWM Ausgabe angepasst haben zaehlt sie nun \n
* eine neu Definierte Zeit. Sie wird trotzdem benutzt um eine Verzoegerung\n
* des einlesens des Temperatursensors und der Temperaturausgabe zu realisieren.\n
* Da das Serial Peripheral Interface zum Auslesen des Sensors nicht unendlich\n
* schnell arbeitet ist diese Verzoegerung zwingend notwendig. 
*
*
* @date 25.05.2018 - erfolgreicher Funktionstest am Ofen.
*
* @bug Keine Bugs der Funktion bekannt.
*
*/
int i = 0;
void loop() {
	
	extern MAX6675 tempSens;
	extern void pwm_ausgabe(uint16_t input);
	const uint16_t offset = 3;
	

	if (millis() - zeitStempel > 10000) {
		
		zeitStempel = millis();

		pwm_ausgabe(tempSens.readCelsius() - offset);

		Serial.println(tempSens.readCelsius() - offset);
	}
}
