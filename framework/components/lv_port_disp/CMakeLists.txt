idf_component_register(
    SRCS "lv_port_disp.c"
       
    INCLUDE_DIRS 
        "."
    REQUIRES 
        lvgl 
        lvgl_esp32_drivers)
