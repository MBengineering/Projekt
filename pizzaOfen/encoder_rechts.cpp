/**@file encoder_rechts.cpp */


#include "encoder_rechts.h"

extern volatile byte rechtsFlag;				//Hilfsvariable zur Auswertung
extern volatile byte linksFlag;					//Hilfsvariable zur Auswertung
extern volatile byte readPort;					//Hilfsvariable zur Auswertung
extern volatile uint16_t encPos;			//Laufvariable für Encoder Position

/**
* @file encoder_rechts.cpp
* @brief Dieses file beinhaltet die rechtslaufISR()
*
* @date 18.03.2018 - Erstellung des Files
*
* @author Marvin Behrens
*
* @version 1.0
*/


/**
*
* Interrupt Sub Rutine zur auswertung des Encoders (rechte drehbewegung). \n
*
* @li cli(); sperrt auftretene Interrupts (intern und extern) \n
~ @li readPort wird mit dem Input Registers des PORTD und einer 12 (C) logisch verundet.
* @li die erste If (else) Anweisung vergleicht den Zustand des Portes D \n
*     mit der Bitweisen verundung von einer 12 mit dem rechtsFlag. \n
*     Dieser schritt ist ausschlaggebend für die Auswertung der Drehrichtung.
* @li die zweite If (else) Anweisung ist fuer die Eingrenzung der Encoderposition zustaendig.
* @li sei(); gibt interne und externe Interruts wieder frei.
*
* @date 20.05.2018 - erfolgreicher Funktionstest mit Hardware
*
* @bug Keine Bugs der Funktion bekannt.
*
											*/

void rechtslaufISR() {

	cli();
	readPort = PIND & 0xC;

	if (readPort == B00001100 && rechtsFlag) {
		if (encPos <= 1) {

			encPos = 1;
		}
		else {

			encPos--;
		}
		linksFlag = 0;
		rechtsFlag = 0;
	}
	else if (readPort == B00000100) linksFlag = 1;
	
	sei();

}


