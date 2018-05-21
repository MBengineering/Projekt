// 
// 
// 
#include "pwm_ausgabe.h"
#include "pwm_init.h"

#define outputPin 6

void pwm_ausgabe(uint16_t input) {

	uint8_t pwmValue;

	if (input <= 30) {
		pwmValue = 0;
	}
	
	else if (input>30 && input <= 40) {
		pwmValue = 25;
	}
	else if (input>40 && input <= 45) {
		pwmValue = 35;
	}
	else if (input>45 && input <= 50) {
		pwmValue = 50;
	}
	else if (input>50 && input <= 55) {
		pwmValue = 65;
	}
	else if (input>55 && input <= 60) {
		pwmValue = 80;
	}
	else if (input>60) {
		pwmValue = 100;
	}
	analogWrite(outputPin, pwmValue);
}