idf_component_register(
    SRCS 
        "lv_port_indev.c"
        
    INCLUDE_DIRS 
        "."

    REQUIRES 
        lvgl
        esp32-button)
