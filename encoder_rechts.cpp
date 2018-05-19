// 
// ISR für rechte Drehbewegung
// 


#include "encoder_rechts.h"

extern volatile byte rechtsFlag;				//Hilfsvariable zur Auswertung
extern volatile byte linksFlag;					//Hilfsvariable zur Auswertung
extern volatile uint16_t encPos;			//Laufvariable für Encoder Position
extern volatile byte readPort;					//Hilfsvariable zur Auswertung

void rechtslaufISR() {
	cli();
	readPort = PIND & 0xC;
	if (readPort == B00001100 && rechtsFlag) {

		encPos--;
		linksFlag = 0;
		rechtsFlag = 0;
	}
	else if (readPort == B00000100) linksFlag = 1;
	sei();
}


