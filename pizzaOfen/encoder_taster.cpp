// 
// 
// 

#include "encoder_taster.h"
#include "LiquidCrystal_I2C.h"
#include "lcd_menue.h"

extern LiquidCrystal_I2C lcd;

extern volatile bool aktiv;
extern volatile bool lcd_clear_dummy;
extern const uint8_t entprellZeit;		//100ms
extern volatile uint32_t zeitStempel;		//wann wurde das letzte mal gedrückt?

void tasterPressedISR(){

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