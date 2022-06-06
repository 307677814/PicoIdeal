// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.0.4
// LVGL VERSION: 8.2
// PROJECT: SquareLine_Project

#include "about.h"
#include "index.h"

///////////////////// VARIABLES ////////////////////
lv_obj_t *ui_AboutLabel;
lv_obj_t *ui_AboutImg;
lv_obj_t *ui_AboutBox;
lv_obj_t *ui_LogoImg;
lv_obj_t *ui_VersionLabel;
lv_obj_t *ui_CopyrightLabel;

///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 16
#error "LV_COLOR_DEPTH should be 16bit to match SquareLine Studio's settings"
#endif
#if LV_COLOR_16_SWAP != 1
#error "#error LV_COLOR_16_SWAP should be 0 to match SquareLine Studio's settings"
#endif

///////////////////// SCREENS ////////////////////
void about_create()
{
    // ui_AboutBox

    ui_AboutBox = lv_obj_create(ui_Index);

    lv_obj_set_width(ui_AboutBox, 304);
    lv_obj_set_height(ui_AboutBox, 160);

    lv_obj_set_x(ui_AboutBox, 8 + 320);
    lv_obj_set_y(ui_AboutBox, 72);

    lv_obj_set_style_radius(ui_AboutBox, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_AboutBox, lv_color_hex(0x404040), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_AboutBox, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_AboutBox, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_AboutBox, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_AboutBox, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_LogoImg

    ui_LogoImg = lv_img_create(ui_Index);
    lv_img_set_src(ui_LogoImg, &ui_img_logo_png);

    lv_obj_set_width(ui_LogoImg, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_LogoImg, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_LogoImg, 0 + 320);
    lv_obj_set_y(ui_LogoImg, -4);

    lv_obj_set_align(ui_LogoImg, LV_ALIGN_CENTER);

    // ui_VersionLabel

    ui_VersionLabel = lv_label_create(ui_Index);

    lv_obj_set_width(ui_VersionLabel, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_VersionLabel, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_VersionLabel, 0 + 320);
    lv_obj_set_y(ui_VersionLabel, 26);

    lv_obj_set_align(ui_VersionLabel, LV_ALIGN_CENTER);

    lv_label_set_text(ui_VersionLabel, "Version: 1.0");

    lv_obj_set_style_text_color(ui_VersionLabel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_VersionLabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_VersionLabel, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_CopyrightLabel

    ui_CopyrightLabel = lv_label_create(ui_Index);

    lv_obj_set_width(ui_CopyrightLabel, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_CopyrightLabel, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_CopyrightLabel, 0 + 320);
    lv_obj_set_y(ui_CopyrightLabel, 90);

    lv_obj_set_align(ui_CopyrightLabel, LV_ALIGN_CENTER);

    lv_label_set_text(ui_CopyrightLabel, "Copyright hsinyuwang All Rights Reserved ");

    lv_obj_set_style_text_color(ui_CopyrightLabel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_CopyrightLabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_CopyrightLabel, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);
}
