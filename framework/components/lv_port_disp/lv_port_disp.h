#ifndef LV_PORT_DISP_H
#define LV_PORT_DISP_H

#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"
#include "esp_freertos_hooks.h"

#include "lvgl.h"
#include "lvgl_helpers.h"

void lv_port_disp_init(void);
void disp_task_create(void);

#endif