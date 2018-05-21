// 
// 
// 

#include "encoder_taster.h"
#include "LiquidCrystal_I2C.h"
#include "lcd_menue.h"

extern LiquidCrystal_I2C lcd;
extern volatile bool aktiv;
extern volatile bool lcd_clear_dummy;
extern const uint8_t entprellZeit;
extern volatile uint64_t zeitStempel;		

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