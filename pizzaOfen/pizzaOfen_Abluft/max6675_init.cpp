// 
// 
// 

#include "max6675_init.h"
#include "max6675.h"

#define supply A2
#define thermoDO 4
#define  thermoCS1 3
#define  thermoCLK 2
MAX6675 thermocouple1(thermoCLK, thermoCS1, thermoDO);

void max6675_init() {

	pinMode(supply, OUTPUT);
	digitalWrite(supply, HIGH);
}

