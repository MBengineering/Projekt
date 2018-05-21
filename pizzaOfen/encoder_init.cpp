// 
// 
// 

#include "encoder_init.h"
#include "encoder_links.h"
#include "encoder_rechts.h"
#include "encoder_taster.h"

#define pinRechts 19						//++
#define pinLinks  18						//--
#define pinTaster  2						//Taster

volatile bool aktiv;						// ==true : heizvorgang ; ==false : temperatur wählen
volatile bool lcd_clear_dummy;		
volatile uint32_t zeitStempel;				//wann wurde das letzte mal gedrückt?
uint8_t entprellZeit;						//100ms

volatile byte rechtsFlag;					//Hilfsvariable zur Auswertung
volatile byte linksFlag;					//Hilfsvariable zur Auswertung
volatile uint16_t encPos;					//Laufvariable für Encoder Position
volatile byte readPort;						//Hilfsvariable zur Auswertung

void encoderInit() {

	volatile bool aktiv = false;
	volatile bool lcd_clear_dummy = true;

	rechtsFlag = 0;
	linksFlag = 0;
	encPos = 1;	
	readPort = 0;

	pinMode(pinRechts, INPUT_PULLUP);
	pinMode(pinLinks, INPUT_PULLUP);
	pinMode(pinTaster, INPUT_PULLUP);
	attachInterrupt(digitalPinToInterrupt(pinRechts), rechtslaufISR, RISING);
	attachInterrupt(digitalPinToInterrupt(pinLinks), linkslaufISR, RISING);
	attachInterrupt(digitalPinToInterrupt(pinTaster), tasterPressedISR, RISING);

	entprellZeit = 100;
	zeitStempel = millis();
}