set(component_srcs 
    "src/app/app.c"
    
    "src/img/ui_img_batteryempty_png.c"
    "src/img/ui_img_batteryfull_png.c"
    "src/img/ui_img_batteryhalf_png.c"
    "src/img/ui_img_batteryquarter_png.c"
    "src/img/ui_img_batterythreequarters_png.c"
    "src/img/ui_img_hemperature_png.c"
    "src/img/ui_img_home_png.c"
    "src/img/ui_img_humidity_png.c"
    "src/img/ui_img_logo_png.c"
    "src/img/ui_img_wifi_png.c"
    "src/img/ui_img_1_png.c"
    "src/img/ui_img_2_png.c"
    "src/img/ui_img_3_png.c"
    "src/img/ui_img_4_png.c"
    "src/img/ui_img_5_png.c"
    "src/img/ui_img_6_png.c"
    "src/img/ui_img_7_png.c"
    "src/img/ui_img_8_png.c"
    "src/img/ui_img_about_png.c"
    "src/img/ui_img_left_png.c"
    "src/img/ui_img_right_png.c"

    "src/page/index.c"
    "src/page/home.c"
    "src/page/about.c"

    "src/anim/anim.c"
)

idf_component_register(
    SRCS 
        "${component_srcs}"

    INCLUDE_DIRS 
        "include/app"
        "include/page"
        "include/anim"

    REQUIRES
        "lvgl"
        "lv_port_indev"
)