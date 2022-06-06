// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.0.4
// LVGL VERSION: 8.2
// PROJECT: SquareLine_Project

#include "index.h"

///////////////////// VARIABLES ////////////////////
lv_obj_t *ui_Index;
lv_obj_t *ui_MainBox;
lv_obj_t *ui_HeaderBox;
lv_obj_t *ui_TimeLabel;
lv_obj_t *ui_WiFiImg;
lv_obj_t *ui_BatteryFullImg;
lv_obj_t *ui_LeftImg;
lv_obj_t *ui_RightImg;
lv_obj_t *ui_TitleImg;
lv_obj_t *ui_TitleLabel;
///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 16
#error "LV_COLOR_DEPTH should be 16bit to match SquareLine Studio's settings"
#endif
#if LV_COLOR_16_SWAP != 1
#error "#error LV_COLOR_16_SWAP should be 0 to match SquareLine Studio's settings"
#endif

bool FOCUSED_STATE = false;

void start_anim();

///////////////////// ANIMATIONS ////////////////////
static const lv_img_dsc_t *battery_anim_imgs[5] = {
    &ui_img_batteryempty_png,
    &ui_img_batteryquarter_png,
    &ui_img_batteryhalf_png,
    &ui_img_batterythreequarters_png,
    &ui_img_batteryfull_png,
};

static void ui_MainBox_event_cb(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code)
    {
    case LV_EVENT_CLICKED:
        if (FOCUSED_STATE)
        {
            lv_obj_add_flag(ui_LeftImg, LV_OBJ_FLAG_HIDDEN);
            lv_obj_add_flag(ui_RightImg, LV_OBJ_FLAG_HIDDEN);
            lv_obj_add_flag(ui_LeftImg, LV_OBJ_FLAG_SCROLLABLE);
            lv_obj_add_flag(ui_RightImg, LV_OBJ_FLAG_SCROLLABLE);
            obj_set_anim(ui_TitleImg, 0, 0, -110, 500, _ui_anim_callback_set_x, _ui_anim_callback_get_x, lv_anim_path_overshoot);
            obj_set_anim(ui_TitleLabel, 0, 0, -110, 500, _ui_anim_callback_set_x, _ui_anim_callback_get_x, lv_anim_path_overshoot);
        }
        else
        {
            obj_set_anim(ui_TitleImg, 0, 0, 110, 500, _ui_anim_callback_set_x, _ui_anim_callback_get_x, lv_anim_path_overshoot);
            obj_set_anim(ui_TitleLabel, 0, 0, 110, 500, _ui_anim_callback_set_x, _ui_anim_callback_get_x, lv_anim_path_overshoot);
            lv_obj_clear_flag(ui_LeftImg, LV_OBJ_FLAG_SCROLLABLE);
            lv_obj_clear_flag(ui_RightImg, LV_OBJ_FLAG_SCROLLABLE);
            lv_obj_clear_flag(ui_LeftImg, LV_OBJ_FLAG_HIDDEN);
            lv_obj_clear_flag(ui_RightImg, LV_OBJ_FLAG_HIDDEN);
        }
        FOCUSED_STATE = !FOCUSED_STATE;
        break;
    default:
        break;
    }
}

static void ui_LeftImg_event_cb(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code)
    {
    case LV_EVENT_CLICKED:
        lv_img_set_src(ui_TitleImg, &ui_img_home_png);
        lv_label_set_text(ui_TitleLabel, "Home");
        lv_obj_scroll_to_x(ui_Index, 0, LV_ANIM_ON);
        break;
    default:
        break;
    }
}

static void ui_RightImg_event_cb(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code)
    {
    case LV_EVENT_CLICKED:
        lv_img_set_src(ui_TitleImg, &ui_img_about_png);
        lv_label_set_text(ui_TitleLabel, "About");
        lv_obj_scroll_to_x(ui_Index, 328, LV_ANIM_ON);
        break;
    default:
        break;
    }
}

///////////////////// SCREENS ////////////////////
void index_create(void)
{

    // ui_Index
    lv_group_t *group = get_group();

    ui_Index = lv_scr_act();

    lv_obj_clear_flag(ui_Index, LV_OBJ_FLAG_SCROLLABLE);

    // ui_MainBox

    ui_MainBox = lv_obj_create(ui_Index);

    lv_obj_set_width(ui_MainBox, 320 + 320);
    lv_obj_set_height(ui_MainBox, 208);

    lv_obj_set_x(ui_MainBox, 0);
    lv_obj_set_y(ui_MainBox, 32);

    lv_obj_set_style_radius(ui_MainBox, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_MainBox, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_MainBox, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_MainBox, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_MainBox, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_MainBox, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_MainBox, ui_MainBox_event_cb, LV_EVENT_CLICKED, NULL);
    lv_obj_clear_flag(ui_MainBox, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_add_state(ui_MainBox, LV_STATE_FOCUSED);

    // ui_LeftImg

    ui_LeftImg = lv_imgbtn_create(ui_Index);

    lv_imgbtn_set_src(ui_LeftImg, LV_IMGBTN_STATE_RELEASED, NULL, &ui_img_left_png, NULL);
    lv_imgbtn_set_src(ui_LeftImg, LV_IMGBTN_STATE_PRESSED, NULL, &ui_img_left_png, NULL);

    lv_obj_set_width(ui_LeftImg, 20);
    lv_obj_set_height(ui_LeftImg, 20);

    lv_obj_add_flag(ui_LeftImg, LV_OBJ_FLAG_FLOATING);
    lv_obj_align(ui_LeftImg, LV_ALIGN_TOP_LEFT, 8, 42);

    lv_obj_set_style_radius(ui_LeftImg, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_LeftImg, lv_color_hex(0x323232), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_LeftImg, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_radius(ui_LeftImg, 2, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_bg_color(ui_LeftImg, lv_color_hex(0x505050), LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_bg_opa(ui_LeftImg, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_color(ui_LeftImg, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui_LeftImg, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui_LeftImg, 2, LV_PART_MAIN | LV_STATE_PRESSED);

    lv_obj_set_style_radius(ui_LeftImg, 2, LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_border_color(ui_LeftImg, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_border_opa(ui_LeftImg, 255, LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_border_width(ui_LeftImg, 2, LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_add_event_cb(ui_LeftImg, ui_LeftImg_event_cb, LV_EVENT_CLICKED, NULL);
    lv_obj_add_flag(ui_LeftImg, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui_LeftImg, LV_OBJ_FLAG_SCROLLABLE);

    // ui_RightImg

    ui_RightImg = lv_imgbtn_create(ui_Index);
    lv_imgbtn_set_src(ui_RightImg, LV_IMGBTN_STATE_RELEASED, NULL, &ui_img_right_png, NULL);
    lv_imgbtn_set_src(ui_RightImg, LV_IMGBTN_STATE_PRESSED, NULL, &ui_img_right_png, NULL);

    lv_obj_set_width(ui_RightImg, 20);
    lv_obj_set_height(ui_RightImg, 20);

    lv_obj_add_flag(ui_RightImg, LV_OBJ_FLAG_FLOATING);
    lv_obj_align(ui_RightImg, LV_ALIGN_TOP_LEFT, 292, 42);

    lv_obj_set_style_radius(ui_RightImg, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_RightImg, lv_color_hex(0x323232), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_RightImg, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_radius(ui_RightImg, 2, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_bg_color(ui_RightImg, lv_color_hex(0x505050), LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_bg_opa(ui_RightImg, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_color(ui_RightImg, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui_RightImg, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui_RightImg, 2, LV_PART_MAIN | LV_STATE_PRESSED);

    lv_obj_set_style_radius(ui_RightImg, 2, LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_border_color(ui_RightImg, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_border_opa(ui_RightImg, 255, LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_border_width(ui_RightImg, 2, LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_add_event_cb(ui_RightImg, ui_RightImg_event_cb, LV_EVENT_CLICKED, NULL);
    lv_obj_add_flag(ui_RightImg, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui_RightImg, LV_OBJ_FLAG_SCROLLABLE);

    // ui_HeaderBox

    ui_HeaderBox = lv_obj_create(ui_Index);

    lv_obj_set_width(ui_HeaderBox, 320);
    lv_obj_set_height(ui_HeaderBox, 32);

    lv_obj_add_flag(ui_HeaderBox, LV_OBJ_FLAG_FLOATING);
    lv_obj_align(ui_HeaderBox, LV_ALIGN_TOP_LEFT, 0, 0);

    lv_obj_set_style_radius(ui_HeaderBox, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_HeaderBox, lv_color_hex(0x404040), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_HeaderBox, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_HeaderBox, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_HeaderBox, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_HeaderBox, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_TimeLabel

    ui_TimeLabel = lv_label_create(ui_Index);

    lv_obj_set_width(ui_TimeLabel, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_TimeLabel, LV_SIZE_CONTENT);

    lv_obj_add_flag(ui_TimeLabel, LV_OBJ_FLAG_FLOATING);
    lv_obj_align(ui_TimeLabel, LV_ALIGN_TOP_LEFT, 8, 8);

    lv_label_set_text(ui_TimeLabel, "--:--");

    lv_obj_set_style_text_color(ui_TimeLabel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_TimeLabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_TimeLabel, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_WiFiImg

    ui_WiFiImg = lv_img_create(ui_Index);
    lv_img_set_src(ui_WiFiImg, &ui_img_wifi_png);

    lv_obj_add_flag(ui_WiFiImg, LV_OBJ_FLAG_HIDDEN);

    lv_obj_set_width(ui_WiFiImg, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_WiFiImg, LV_SIZE_CONTENT);

    lv_obj_add_flag(ui_WiFiImg, LV_OBJ_FLAG_FLOATING);
    lv_obj_align(ui_WiFiImg, LV_ALIGN_TOP_LEFT, 258, 6);

    // ui_BatteryFullImg

    // ui_BatteryFullImg = lv_img_create(ui_Index);
    // lv_img_set_src(ui_BatteryFullImg, &ui_img_batteryfull_png);

    // lv_obj_set_width(ui_BatteryFullImg, LV_SIZE_CONTENT);
    // lv_obj_set_height(ui_BatteryFullImg, LV_SIZE_CONTENT);

    // // lv_obj_set_x(ui_BatteryFullImg, 286);
    // // lv_obj_set_y(ui_BatteryFullImg, 6);
    // lv_obj_add_flag(ui_BatteryFullImg, LV_OBJ_FLAG_FLOATING);
    // lv_obj_align(ui_BatteryFullImg, LV_ALIGN_TOP_LEFT, 286, 6);

    // ui_BatteryAnim

    lv_obj_t *ui_BatteryAnim = lv_animimg_create(ui_Index);

    lv_obj_add_flag(ui_BatteryAnim, LV_OBJ_FLAG_FLOATING);
    lv_obj_align(ui_BatteryAnim, LV_ALIGN_TOP_LEFT, 286, 6);
    lv_animimg_set_src(ui_BatteryAnim, (lv_img_dsc_t **)battery_anim_imgs, 5);
    lv_animimg_set_duration(ui_BatteryAnim, 800);
    lv_animimg_set_repeat_count(ui_BatteryAnim, LV_ANIM_REPEAT_INFINITE);
    lv_animimg_start(ui_BatteryAnim);

    // ui_TitleImg

    ui_TitleImg = lv_img_create(ui_Index);
    lv_img_set_src(ui_TitleImg, &ui_img_home_png);

    lv_obj_set_width(ui_TitleImg, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_TitleImg, LV_SIZE_CONTENT);

    lv_obj_add_flag(ui_TitleImg, LV_OBJ_FLAG_FLOATING);
    lv_obj_align(ui_TitleImg, LV_ALIGN_TOP_LEFT, 8, 42);

    // ui_TitleLabel

    ui_TitleLabel = lv_label_create(ui_Index);

    lv_obj_set_width(ui_TitleLabel, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_TitleLabel, LV_SIZE_CONTENT);

    lv_obj_add_flag(ui_TitleLabel, LV_OBJ_FLAG_FLOATING);
    lv_obj_align(ui_TitleLabel, LV_ALIGN_TOP_LEFT, 34, 44);

    lv_label_set_text(ui_TitleLabel, "Home");

    lv_obj_set_style_text_color(ui_TitleLabel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_TitleLabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_TitleLabel, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_group_add_obj(group, ui_MainBox);
    lv_group_add_obj(group, ui_LeftImg);
    lv_group_add_obj(group, ui_RightImg);
}
