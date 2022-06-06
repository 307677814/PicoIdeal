idf_component_register(SRCS "src/start_sntp.c"
                    INCLUDE_DIRS "include"
                    REQUIRES protocol_common
                    lvgl
                    lvgl_ui)