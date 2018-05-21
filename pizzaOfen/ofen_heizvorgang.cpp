// 
// 
// 

#include "ofen_heizvorgang.h"


#include "max6675.h"

#define relais1		5		//oberes Heizelement
#define relais2		6		//unteres Heizelement

extern double Sollwert(uint16_t zwAblage);
extern MAX6675 thermocouple;
extern volatile uint16_t encPos;

double input;
double obereGrenze, untereGrenze;
const uint8_t offsetRaumtemp = 3;

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

void heizvorgang() {
	
	input = thermocouple.readCelsius() - offsetRaumtemp;	

	obereGrenze = (Sollwert(encPos) * 1.01);
	untereGrenze = (Sollwert(encPos) * 0.99);

	if (input > obereGrenze){

		digitalWrite(relais1, LOW);
		digitalWrite(relais2, LOW);

	}

	else if (input < untereGrenze){

		digitalWrite(relais1, HIGH);
		digitalWrite(relais2, HIGH);
	}
	
}