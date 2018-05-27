#include "LCD.h"
#include "LiquidCrystal_I2C.h"
#include "lcd_menue.h"
#include <Print.h>

extern LiquidCrystal_I2C lcd;

extern volatile bool lcd_clear_dummy;
extern volatile bool aktiv;

/**
* @file lcd_menue.cpp
* @brief Dieses file beinhaltet die menue() Funktion.\n
*
* Benutzte Open Source Funktionen aus dem LCD.h und Print.h :
* @li void LCD::setCursor(Spalte,Zeile), setzt den Cursor an beliebige stelle.
* @li sive_t Print::print(Spalte,Zeile), Textausgabe auf dem LCD, "Text" oder Variablen.
*
* @date 18.03.2018 - Erstellung des Files
*
* @author Marvin Behrens
*
* @version 1.0
*/


/**
*
* Textausgabe auf dem LCD \n
*
* @param[in] inputMENUE   Instanziierung der Ist-Temperatur
* @param[in] encPosMENUE  Instanziierung der Encoder Position \n
*                         (welche quasi fuer die Soll- bzw. Zieltemperatur steht \n
*
*
* <ul>
*     <li>Die erste If (else) Anweisung liest den Betriebszustand aus.</li>
*     <ol>
*       <li>Sowohl im If{} als auch im Else{} Block, sorgt eine weitere  \n
*			If Anweisung fuer die Ausgabekorrektur \n
*			der Soll- bzw. Zieltemperatur.>
*     </ol>
*	  <li>Die letzt Anweisung dient der Textfeldleerung beim \n
*		   wechsel der Betriebszustaende.>
* </ul>
*
*
* @date 20.04.2018 - erfolgreicher Funktionstest mit Hardware
*
* @bug Keine Bugs der Funktion bekannt.
*
*/

void menue(double inputMENUE, uint16_t encPosMENUE){


	if (!aktiv) {
		
		lcd.setCursor(0, 0);
		lcd.print("Heizvorgang inaktiv");
		lcd.setCursor(1, 2);
		lcd.print("Zieltemperatur :");
		lcd.setCursor(3, 3);
		lcd.print(">");
		lcd.setCursor(7, 3);
		if (encPosMENUE < 10) {
			lcd.print(" ");
			lcd.setCursor(8, 3);
		}
		lcd.print(encPosMENUE * 10);
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
		if (encPosMENUE < 10) {
			lcd.print(" ");
			lcd.setCursor(2, 3);
		}
		lcd.print(encPosMENUE*10);
		lcd.print((char)223);
		lcd.print("C");
		lcd.setCursor(11, 2);
		lcd.print("Ist:");
		lcd.setCursor(11, 3);
		if (inputMENUE < 100.00) {
			lcd.print(" ");
			lcd.setCursor(12, 3);
		}
		lcd.print(inputMENUE);
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