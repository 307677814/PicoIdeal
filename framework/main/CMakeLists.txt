idf_component_register(SRCS "main.c"
                    INCLUDE_DIRS ""
                    REQUIRES
                    nvs_flash
                    lvgl
                    esp32-button
                    lv_port_disp
                    lv_port_indev
                    lvgl_ui
                    sntp
                    sht3x
                    tcp)