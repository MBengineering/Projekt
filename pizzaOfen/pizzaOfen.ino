#include "Doxygen.h"
#include "ofen_heizvorgang.h"
#include "ofen_temp_wahl.h"
#include "max6675_init.h"
#include "lcd_menue.h"
#include "lcd_init.h"
#include <Wire.h>
#include <time.h>
#include "encoder_taster.h"
#include "encoder_init.h"
#include "encoder_links.h"
#include "encoder_rechts.h"
#include "encoder.h"

extern volatile uint16_t encPos;			//Laufvariable für Encoder Position ; initialisiert in encoder_init.cpp
extern volatile bool aktiv;

uint32_t delayStempel;
uint16_t deelay = 1000;


void setup() {

	encoderInit();
	lcdInit();
	delayStempel = millis();
}


void loop() {
	
	menue();

	if (aktiv) {

		if (millis() - delayStempel >= deelay) {

			heizvorgang();
			delayStempel = millis();
		}
	}
	
}
