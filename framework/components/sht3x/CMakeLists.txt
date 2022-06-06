idf_component_register(SRCS "sht3x.c" "start_sht3x.c"
                        INCLUDE_DIRS include
                        REQUIRES bus lvgl_ui)