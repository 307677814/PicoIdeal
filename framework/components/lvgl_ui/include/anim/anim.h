#ifndef __ANIM_H
#define __ANIM_H

#include "lvgl.h"

void _ui_anim_callback_set_x(lv_anim_t *a, int32_t v);
int32_t _ui_anim_callback_get_x(lv_anim_t *a);
void _ui_anim_callback_set_opacity(lv_anim_t *a, int32_t v);
int32_t _ui_anim_callback_get_opacity(lv_anim_t *a);
void obj_set_anim(lv_obj_t *TargetObject, int delay, int start, int end, int AnimTime, lv_anim_custom_exec_cb_t exec_cb, lv_anim_get_value_cb_t get_value_cb, lv_anim_path_cb_t path_cb);

#endif