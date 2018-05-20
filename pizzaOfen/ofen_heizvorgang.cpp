// 
// 
// 

#include "ofen_heizvorgang.h"


#include "max6675.h"

#define relais1		5		//oberes Heizelement
#define relais2		6		//unteres Heizelement

extern double Sollwert(uint16_t zwAblage);
extern MAX6675 thermocouple1;
extern volatile uint16_t encPos;

double input;
double obereGrenze, untereGrenze;

void heizvorgang() {
	
	

	input = thermocouple1.readCelsius() - 3;		//3°C Offset abziehen.

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