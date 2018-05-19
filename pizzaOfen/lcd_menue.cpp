// 
// Textausgabe auf dem LCD zum auswähler der Solltemperatur
// 

#include "LCD.h"
#include "LiquidCrystal_I2C.h"
#include "lcd_menue.h"

extern LiquidCrystal_I2C lcd;

extern bool aktiv;
extern bool lcd_clear_dummy;
uint16_t zieltemp = 100;

void menue() {

	if (!aktiv) {
		
		lcd.setCursor(1, 0);
		lcd.print("Zieltemperatur :");
		lcd.setCursor(5, 2);
		lcd.print(">");
		lcd.setCursor(8, 2);
		lcd.print(zieltemp);
		lcd.setCursor(13, 2);
		lcd.print("<");
	}
	else {

		lcd.setCursor(0, 0);
		lcd.print("Heizvorgang aktiv !");
		lcd.setCursor(1, 2);
		lcd.print("Soll:");
		lcd.setCursor(1, 3);
		lcd.print(zieltemp);
		lcd.print((char)223);
		lcd.print("C");
		lcd.setCursor(11, 2);
		lcd.print("Ist:");
		lcd.setCursor(11, 3);
		lcd.print(zieltemp);
		lcd.print((char)223);
		lcd.print("C");
	}
	if (lcd_clear_dummy) {

		lcd.setCursor(0, 0);
		lcd.print("                    ");
		lcd.setCursor(0, 1);
		lcd.print("                    ");
		lcd.setCursor(0, 2);
		lcd.print("                    ");
		lcd.setCursor(0, 3);
		lcd.print("                    ");

		lcd_clear_dummy = false;
	}

}