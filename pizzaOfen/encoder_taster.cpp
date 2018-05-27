
#include "encoder_taster.h"


extern volatile bool aktiv;						// ==true : heizvorgang ; ==false : temperatur wählen
extern volatile bool lcd_clear_dummy;			// initialisiert in pizzaOfen.ino
extern volatile uint32_t zeitStempel;


/**
* @file encoder_taster.cpp
* @brief Dieses file beinhaltet die tasterPressedISR() Funktion
*
* Interrupt Sub Rutine, extern ausgeloest durch Taster des Encoders\n
* Sie dient zum aktivieren und deaktivieren des Heizvorganges.\n
* Ausserdem loest er beim Umschalten in den aktiven Zustand, oder Deaktivierung,\n
* eine Ruecksetzung der LCD Anzeige aus.
* Pin2 <- Taster <- GND\n
*
* @date 17.03.2018 - Erstellung des Files
*
* @author Marvin Behrens
*
* @version 1.0
*/

/**
* @param zeitStempel		die Zeit des letzten Aufrufes der tasterPressedISR().\n
* @param lcd_clear_dummy	(extern) bei true == leerung des LCD angefordert.\n
* @param aktiv(extern)		bei true == Heizvorgang aktiv.\n
* @param entprellZeit		==> defines
*
*
* @li Die erste if Anweisung dient zur softwaremaessigen Entprellung des Tasters. Sie \n
* fragt ob die Differenz der aktuelle Zeit subtrahiert durch die Zeit \n
* des letzten aufrufes groesser ist als die fest definierte Entprellungszeit \n
* von 100ms.\n
* @li Die zweite if (else) Anweisung ist fuer das toggeln der Variable aktiv zustaendig.\n
* @li Die dritte if Anweisung Setzt die Variable, welche zur Anforderung einer\n
* Textfeldleerung dient.\n
* @li Durch den Befehl cli() werden Interrupts unterdrueckt/gesperrt und durch sei() \n
* wie freigegeben.\n
*
* @date 20.04.2018 - erfolgreicher Funktionstest mit Hardware
*
* @bug Keine Bugs der Funktion bekannt. Hardware entprellung von vorteil.
*
*/
void tasterPressedISR(){
	
	const uint32_t entprellZeit = 1000;				// 1 Sekunde

	cli();
	if (millis() - zeitStempel >= entprellZeit) {	

		zeitStempel = millis();
		if (!aktiv) {

			aktiv = true;
		}
		else {

			aktiv = false;

		}
		if (!lcd_clear_dummy) {

			lcd_clear_dummy = true;
		}
	}
	sei();
}