// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.0.4
// LVGL VERSION: 8.2
// PROJECT: SquareLine_Project

#include "home.h"
#include "index.h"

///////////////////// VARIABLES ////////////////////
lv_obj_t *ui_TemperatureBox;
lv_obj_t *ui_HumidityBox;
lv_obj_t *ui_SpacemanBox;
lv_obj_t *ui_HomeImg;
lv_obj_t *ui_HomeLabel;
lv_obj_t *ui_TemperatureImg;
lv_obj_t *ui_HumidityImg;
lv_obj_t *ui_TemperatureHigh;
lv_obj_t *ui_TemperatureLow;
lv_obj_t *ui_HumidityHigh;
lv_obj_t *ui_HumidityLow;
lv_obj_t *ui_TemperatureUnit;
lv_obj_t *ui_HumidityUnit;
///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 16
#error "LV_COLOR_DEPTH should be 16bit to match SquareLine Studio's settings"
#endif
#if LV_COLOR_16_SWAP != 1
#error "#error LV_COLOR_16_SWAP should be 0 to match SquareLine Studio's settings"
#endif

///////////////////// ANIMATIONS ////////////////////
static const lv_img_dsc_t *spaceman_anim_imgs[8] = {
    &ui_img_1_png,
    &ui_img_2_png,
    &ui_img_3_png,
    &ui_img_4_png,
    &ui_img_5_png,
    &ui_img_6_png,
    &ui_img_7_png,
    &ui_img_8_png,
};

///////////////////// SCREENS ////////////////////
void home_create()
{

    // ui_TemperatureBox

    ui_TemperatureBox = lv_obj_create(ui_Index);

    lv_obj_set_width(ui_TemperatureBox, 136);
    lv_obj_set_height(ui_TemperatureBox, 76);

    lv_obj_set_x(ui_TemperatureBox, 8);
    lv_obj_set_y(ui_TemperatureBox, 72);

    lv_obj_set_style_radius(ui_TemperatureBox, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_TemperatureBox, lv_color_hex(0x404040), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_TemperatureBox, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_TemperatureBox, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_TemperatureBox, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_TemperatureBox, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_HumidityBox

    ui_HumidityBox = lv_obj_create(ui_Index);

    lv_obj_set_width(ui_HumidityBox, 136);
    lv_obj_set_height(ui_HumidityBox, 76);

    lv_obj_set_x(ui_HumidityBox, 8);
    lv_obj_set_y(ui_HumidityBox, 156);

    lv_obj_set_style_radius(ui_HumidityBox, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_HumidityBox, lv_color_hex(0x404040), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_HumidityBox, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_HumidityBox, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_HumidityBox, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_HumidityBox, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_SpacemanBox

    ui_SpacemanBox = lv_obj_create(ui_Index);

    lv_obj_set_width(ui_SpacemanBox, 160);
    lv_obj_set_height(ui_SpacemanBox, 160);

    lv_obj_set_x(ui_SpacemanBox, 152);
    lv_obj_set_y(ui_SpacemanBox, 72);

    lv_obj_set_style_radius(ui_SpacemanBox, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_SpacemanBox, lv_color_hex(0x404040), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_SpacemanBox, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_SpacemanBox, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_SpacemanBox, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_SpacemanBox, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_TemperatureImg

    ui_TemperatureImg = lv_img_create(ui_Index);
    lv_img_set_src(ui_TemperatureImg, &ui_img_humidity_png);

    lv_obj_set_width(ui_TemperatureImg, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_TemperatureImg, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_TemperatureImg, 18);
    lv_obj_set_y(ui_TemperatureImg, 85);

    // ui_HumidityImg

    ui_HumidityImg = lv_img_create(ui_Index);
    lv_img_set_src(ui_HumidityImg, &ui_img_hemperature_png);

    lv_obj_set_width(ui_HumidityImg, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_HumidityImg, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_HumidityImg, 18);
    lv_obj_set_y(ui_HumidityImg, 169);

    // ui_TemperatureHigh

    ui_TemperatureHigh = lv_label_create(ui_Index);

    lv_obj_set_width(ui_TemperatureHigh, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_TemperatureHigh, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_TemperatureHigh, 88);
    lv_obj_set_y(ui_TemperatureHigh, 85);

    lv_label_set_text(ui_TemperatureHigh, "--");

    lv_obj_set_style_text_color(ui_TemperatureHigh, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_TemperatureHigh, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_TemperatureHigh, &lv_font_montserrat_28, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_TemperatureLow

    ui_TemperatureLow = lv_label_create(ui_Index);

    lv_obj_set_width(ui_TemperatureLow, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_TemperatureLow, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_TemperatureLow, 88);
    lv_obj_set_y(ui_TemperatureLow, 121);

    lv_label_set_text(ui_TemperatureLow, "--");

    lv_obj_set_style_text_color(ui_TemperatureLow, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_TemperatureLow, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_TemperatureLow, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_HumidityHigh

    ui_HumidityHigh = lv_label_create(ui_Index);

    lv_obj_set_width(ui_HumidityHigh, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_HumidityHigh, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_HumidityHigh, 88);
    lv_obj_set_y(ui_HumidityHigh, 169);

    lv_label_set_text(ui_HumidityHigh, "--");

    lv_obj_set_style_text_color(ui_HumidityHigh, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_HumidityHigh, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_HumidityHigh, &lv_font_montserrat_28, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_HumidityLow

    ui_HumidityLow = lv_label_create(ui_Index);

    lv_obj_set_width(ui_HumidityLow, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_HumidityLow, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_HumidityLow, 88);
    lv_obj_set_y(ui_HumidityLow, 205);

    lv_label_set_text(ui_HumidityLow, "--");

    lv_obj_set_style_text_color(ui_HumidityLow, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_HumidityLow, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_HumidityLow, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_TemperatureUnit

    ui_TemperatureUnit = lv_label_create(ui_Index);

    lv_obj_set_width(ui_TemperatureUnit, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_TemperatureUnit, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_TemperatureUnit, 110);
    lv_obj_set_y(ui_TemperatureUnit, 121);

    lv_label_set_text(ui_TemperatureUnit, "°C");

    lv_obj_set_style_text_color(ui_TemperatureUnit, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_TemperatureUnit, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_TemperatureUnit, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_HumidityUnit

    ui_HumidityUnit = lv_label_create(ui_Index);

    lv_obj_set_width(ui_HumidityUnit, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_HumidityUnit, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_HumidityUnit, 110);
    lv_obj_set_y(ui_HumidityUnit, 205);

    lv_label_set_text(ui_HumidityUnit, "%RH");

    lv_obj_set_style_text_color(ui_HumidityUnit, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_HumidityUnit, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_HumidityUnit, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_SpacemanAnim
    lv_obj_t *ui_SpacemanAnim = lv_animimg_create(ui_Index);
    lv_obj_set_x(ui_SpacemanAnim, 152);
    lv_obj_set_y(ui_SpacemanAnim, 72);
    lv_animimg_set_src(ui_SpacemanAnim, (lv_img_dsc_t **)spaceman_anim_imgs, 8);
    lv_animimg_set_duration(ui_SpacemanAnim, 600);
    lv_animimg_set_repeat_count(ui_SpacemanAnim, LV_ANIM_REPEAT_INFINITE);
    lv_animimg_start(ui_SpacemanAnim);
}
