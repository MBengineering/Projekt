// 
// 
// 

#include "max6675_init.h"
#include "max6675.h"

#define thermoDO 12
#define  thermoCS1 8
#define  thermoCLK 7

MAX6675 thermocouple1(thermoCLK, thermoCS1, thermoDO);

