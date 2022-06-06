// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.0.4
// LVGL VERSION: 8.2
// PROJECT: SquareLine_Project

#ifndef __ABOUT_H
#define __ABOUT_H

#ifdef __cplusplus
extern "C"
{
#endif

#if __has_include("lvgl.h")
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif

    extern lv_obj_t *ui_TemperatureBox;
    extern lv_obj_t *ui_AboutLabel;
    extern lv_obj_t *ui_AboutImg;
    extern lv_obj_t *ui_AboutBox;
    extern lv_obj_t *ui_LogoImg;
    extern lv_obj_t *ui_VersionLabel;
    extern lv_obj_t *ui_CopyrightLabel;

    LV_IMG_DECLARE(ui_img_about_png);
    LV_IMG_DECLARE(ui_img_logo_png);

    void about_create();

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
