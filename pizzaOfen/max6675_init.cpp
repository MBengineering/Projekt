// 
// 
// 

#include "max6675_init.h"
#include "max6675.h"

#define thermoDO 4
#define  thermoCS 3
#define  thermoCLK 2

MAX6675 thermocouple(thermoCLK, thermoCS, thermoDO);

