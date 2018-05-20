// 
// 
// 

#include "pwm_init.h"

#define outputPin 6
#define MICROSECONDS_PER_TIMER0_OVERFLOW (clockCyclesToMicroseconds(1 * 256))


void pwm_init() {

	TCCR0A = _BV(COM0A1) | _BV(COM0B1) | _BV(WGM01) | _BV(WGM00);
	TCCR0B = _BV(CS00);

	pinMode(outputPin, OUTPUT);
}