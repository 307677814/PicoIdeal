#ifndef _TCP_CLIENT_H_
#define _TCP_CLIENT_H_

#include <string.h>
#include <sys/param.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"
#include "esp_system.h"
#include "esp_wifi.h"
#include "esp_event.h"
#include "esp_log.h"
#include "esp_netif.h"
#include "protocol_common.h"
#include "addr_from_stdin.h"
#include "lwip/err.h"
#include "lwip/sockets.h"
#include "start_sht3x.h"
#include "start_sntp.h"

float Tem_val, Hum_val;
struct tm tm_info;

void tcp_client_task_create();


#endif