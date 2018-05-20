// 
// ISR für linke Drehbewegung
// 

#include "encoder_links.h"

extern volatile byte rechtsFlag;				//Hilfsvariable zur Auswertung
extern volatile byte linksFlag;				//Hilfsvariable zur Auswertung
extern volatile uint16_t encPos;			//Laufvariable für Encoder Position
extern volatile byte readPort;					//Hilfsvariable zur Auswertung

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
