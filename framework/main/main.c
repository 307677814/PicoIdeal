#include "lvgl.h"
#include "lv_port_disp.h"
#include "lv_port_indev.h"
#include "start_sntp.h"
#include "start_sht3x.h"
#include "tcp_client.h"
#include "nvs_flash.h"
#include "app.h"

void app_main(void)
{

    ESP_ERROR_CHECK(nvs_flash_init());
    ESP_ERROR_CHECK(esp_netif_init());
    ESP_ERROR_CHECK(esp_event_loop_create_default());

    lv_init();
    lv_port_disp_init();
    lv_port_indev_init();

    app_init();

    disp_task_create();
    indev_task_create();

    start_sht3x();
    sntp_time_init();

    tcp_client_task_create();
}
