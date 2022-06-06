// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.0.4
// LVGL VERSION: 8.2
// PROJECT: SquareLine_Project

#ifndef __INDEX_H
#define __INDEX_H

#ifdef __cplusplus
extern "C"
{
#endif

#if __has_include("lvgl.h")
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif
#include "lv_port_indev.h"
#include "anim.h"
#include "home.h"
#include "about.h"

    extern lv_obj_t *ui_Index;
    extern lv_obj_t *ui_MainBox;
    extern lv_obj_t *ui_HeaderBox;
    extern lv_obj_t *ui_TimeLabel;
    extern lv_obj_t *ui_WiFiImg;
    extern lv_obj_t *ui_BatteryFullImg;

    LV_IMG_DECLARE(ui_img_wifi_png);
    LV_IMG_DECLARE(ui_img_batteryfull_png);
    LV_IMG_DECLARE(ui_img_batterythreequarters_png);
    LV_IMG_DECLARE(ui_img_batteryhalf_png);
    LV_IMG_DECLARE(ui_img_batteryquarter_png);
    LV_IMG_DECLARE(ui_img_batteryempty_png);
    LV_IMG_DECLARE(ui_img_left_png);
    LV_IMG_DECLARE(ui_img_right_png);

    void index_create(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
