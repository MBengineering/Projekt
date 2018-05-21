#include "max6675_init.h"
#include "pwm_ausgabe.h"
#include "pwm_init.h"
#include "max6675.h"
#include "max6675_init.h"

extern MAX6675 thermocouple1;

unsigned long zeitStempel = 0;
const uint8_t offset = 3;

void setup() {

	pwm_init();
	max6675_init();
	delay(100);

}
void loop() {

	if (millis() - zeitStempel > 100000) {
	
		pwm_ausgabe(thermocouple1.readCelsius() - offset);
		zeitStempel = millis();
	}
}
