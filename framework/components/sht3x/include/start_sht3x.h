#ifndef _START_SHT3x_H_
#define _START_SHT3x_H_

#include <stdio.h>
#include "driver/i2c.h"
#include "i2c_bus.h"
#include "esp_system.h"
#include "sht3x.h"
#include "index.h"

extern float Tem_val, Hum_val;

void start_sht3x();


#endif