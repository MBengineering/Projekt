// 
// 
// 
#include "lcd_init.h"
#include "LCD.h"
#include "LiquidCrystal_I2C.h"

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

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

void lcdInit() {
	
	delay(50);
	lcd.begin(20, 4);
	lcd.backlight();
}

