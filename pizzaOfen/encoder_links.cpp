// 
// ISR f�r linke Drehbewegung
// 

#include "encoder_links.h"

extern volatile byte rechtsFlag;				//Hilfsvariable zur Auswertung
extern volatile byte linksFlag;				//Hilfsvariable zur Auswertung
extern volatile byte readPort;					//Hilfsvariable zur Auswertung
extern volatile uint16_t encPos;			//Laufvariable f�r Encoder Position

/**
* @brief TasterISR
*
*  Interrupt Sub Rutine, extern ausgeloest durch Taster des Encoders\n
*  Sie dient zum aktivieren und deaktivieren des Heizvorganges.\n
*  Ausserdem loest er beim Umschalten in den aktiven Zustand, oder Deaktivierung,\n
*  eine Ruecksetzung der LCD Anzeige aus.
*  Pin2 <- Taster <- GND
*
*
*  @date 17.03.2018 - erster erfolgreicher Test dieser Funktion
*  @date 18.05.2018 - Teil dieses Proejtks
*
*
*  @Bug Keine Bugs der Funktion bekannt. Hardware entprellung von vorteil.
*
*  @version 1.0
*/

void linkslaufISR() {
	cli();
	readPort = PIND & 0xC;
	if (readPort == B00001100 && linksFlag) {
		if (encPos > 40) {

			encPos = 40;
		}
		else {

			encPos++;
		}
		linksFlag = 0;
		rechtsFlag = 0;
	}
	else if (readPort == B00001000) rechtsFlag = 1;
	sei();
}
