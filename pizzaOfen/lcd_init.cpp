#include "lcd_init.h"
#include "LCD.h"
#include "LiquidCrystal_I2C.h"

/** \brief Bekanntgabe des vorhandenen LCD, 0x27 ist die fest vergebene I2C Adresse vom Hersteller. */
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

/**
* @file lcd_init.cpp
* @brief Dieses file beinhaltet die lcdInit() Funktion
*
* Benutzte Open Source Funktionen aus dem LCD.h und LiquidCrystal_I2C.h :
* @li void LiquidCrystal_I2C::begin()
* @li void LCD::backlight()
*
* @date 18.03.2018 - Erstellung des Files
*
* @author Marvin Behrens
*
* @version 1.0
*/


/**
*
* Funktion zum Initialisieren des LCD\n
*
* <ul>
*     <li>Der lcd.begin() Funktion gibt man zwei Parameter mit :</li>
*     <ol>
*       <li>Anzahl der vorhanden Spalten des LCD, hier 20</li>
*       <li>Anzahl der vorhanden Zeilen des LCD, hier 4</li>
*     </ol>
* </ul>
* @li Des weiteren schaltet lcd.backlight() die Hintergrundbeleuchtung des LCD ein. \n
* \n
* @date 20.04.2018 - erfolgreicher Funktionstest mit Hardware
*
* @bug Keine Bugs der Funktion bekannt.
*
*/

void lcdInit() {
	
	lcd.begin(20, 4);
	lcd.backlight();
	delay(50);
}

