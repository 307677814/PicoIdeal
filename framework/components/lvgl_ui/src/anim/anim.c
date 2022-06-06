#include "anim.h"

void _ui_anim_callback_set_x(lv_anim_t *a, int32_t v)
{
    lv_obj_set_x((lv_obj_t *)a->user_data, v);
}

int32_t _ui_anim_callback_get_x(lv_anim_t *a)
{
    return lv_obj_get_x_aligned((lv_obj_t *)a->user_data);
}

void _ui_anim_callback_set_opacity(lv_anim_t *a, int32_t v)
{
    lv_obj_set_style_opa((lv_obj_t *)a->user_data, v, 0);
}

int32_t _ui_anim_callback_get_opacity(lv_anim_t *a)
{
    return lv_obj_get_style_opa((lv_obj_t *)a->user_data, 0);
}

void obj_set_anim(lv_obj_t *TargetObject, int delay, int start, int end, int AnimTime, lv_anim_custom_exec_cb_t exec_cb, lv_anim_get_value_cb_t get_value_cb, lv_anim_path_cb_t path_cb)
{
    lv_anim_t PropertyAnimation_0;
    lv_anim_init(&PropertyAnimation_0);
    lv_anim_set_time(&PropertyAnimation_0, AnimTime);
    lv_anim_set_user_data(&PropertyAnimation_0, TargetObject);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_0, exec_cb);
    lv_anim_set_values(&PropertyAnimation_0, start, end);
    lv_anim_set_path_cb(&PropertyAnimation_0, path_cb);
    lv_anim_set_delay(&PropertyAnimation_0, delay + 0);
    lv_anim_set_early_apply(&PropertyAnimation_0, false);
    lv_anim_set_get_value_cb(&PropertyAnimation_0, get_value_cb);
    lv_anim_start(&PropertyAnimation_0);
}
