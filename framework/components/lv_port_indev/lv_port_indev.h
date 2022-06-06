#ifndef LVGL_PORT_INDEV_H
#define LVGL_PORT_INDEV_H

#include "lvgl.h"
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"
#include "esp_freertos_hooks.h"
#include "button.h"

#define Left_Button CONFIG_GPIO_LEFT_Button
#define Right_Button CONFIG_GPIO_RIGHT_Button
#define Middle_Button CONFIG_GPIO_MIDDLE_Button

void lv_port_indev_init(void);
void indev_task_create(void);

lv_indev_t *get_indev(void);
lv_group_t *get_group(void);

#endif