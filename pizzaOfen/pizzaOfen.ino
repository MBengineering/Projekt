#include "lcd_menue.h"
#include "lcd_ofen.h"
#include <Wire.h>
#include <time.h>
#include "encoder_taster.h"
#include "encoder_init.h"
#include "encoder_links.h"
#include "encoder_rechts.h"
#include "encoder.h"



extern volatile unsigned int encPos;			//Laufvariable für Encoder Position ; initialisiert in encoder_init.cpp


void setup() {
	encoderInit();
	lcdInit();
	
}

void loop() {
	menue();
}
