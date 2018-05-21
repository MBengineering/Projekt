// 
// Textausgabe auf dem LCD zum auswähler der Solltemperatur
// 

#include "LCD.h"
#include "LiquidCrystal_I2C.h"
#include "lcd_menue.h"

extern LiquidCrystal_I2C lcd;
extern bool aktiv;
extern bool lcd_clear_dummy;
extern volatile uint16_t encPos;
extern double input;

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
*  @Bug Keine Bugs der Funktion bekannt.
*
*  @version 1.0
*/

void menue() {


	if (!aktiv) {
		
		lcd.setCursor(0, 0);
		lcd.print("Heizvorgang inaktiv");
		lcd.setCursor(1, 2);
		lcd.print("Zieltemperatur :");
		lcd.setCursor(3, 3);
		lcd.print(">");
		lcd.setCursor(7, 3);
		if (encPos < 10) {
			lcd.print(" ");
			lcd.setCursor(8, 3);
		}
		lcd.print(encPos * 10);
		lcd.print((char)223);
		lcd.print("C");
		lcd.setCursor(15, 3);
		lcd.print("<");
	}
	else {

		lcd.setCursor(0, 0);
		lcd.print("Heizvorgang aktiv !");
		lcd.setCursor(1, 2);
		lcd.print("Soll:");
		lcd.setCursor(1, 3);
		if (encPos < 10) {
			lcd.print(" ");
			lcd.setCursor(2, 3);
		}
		lcd.print(encPos*10);
		lcd.print((char)223);
		lcd.print("C");
		lcd.setCursor(11, 2);
		lcd.print("Ist:");
		lcd.setCursor(11, 3);
		if (input < 100.00) {
			lcd.print(" ");
			lcd.setCursor(12, 3);
		}
		lcd.print(input);
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