/* BSD Socket API Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#include "tcp_client.h"

#if defined(CONFIG_EXAMPLE_IPV4)
#define HOST_IP_ADDR CONFIG_EXAMPLE_IPV4_ADDR
#elif defined(CONFIG_EXAMPLE_IPV6)
#define HOST_IP_ADDR CONFIG_EXAMPLE_IPV6_ADDR
#else
#define HOST_IP_ADDR ""
#endif

#define PORT CONFIG_EXAMPLE_PORT

#define DEVICE_SN CONFIG_DEVICE_SN
#define DEVICE_PWD CONFIG_DEVICE_PWD

static char *TAG = "tcp_client";
static char payload[80];

bool firstSend = true;

float Tem_val, Hum_val;

void static tcp_client_task(void *pvParameters)
{
    // char rx_buffer[128];
    char host_ip[] = HOST_IP_ADDR;
    int addr_family = 0;
    int ip_protocol = 0;

    while (1)
    {
#if defined(CONFIG_EXAMPLE_IPV4)
        struct sockaddr_in dest_addr;
        dest_addr.sin_addr.s_addr = inet_addr(host_ip);
        dest_addr.sin_family = AF_INET;
        dest_addr.sin_port = htons(PORT);
        addr_family = AF_INET;
        ip_protocol = IPPROTO_IP;
#elif defined(CONFIG_EXAMPLE_IPV6)
        struct sockaddr_in6 dest_addr = {0};
        inet6_aton(host_ip, &dest_addr.sin6_addr);
        dest_addr.sin6_family = AF_INET6;
        dest_addr.sin6_port = htons(PORT);
        dest_addr.sin6_scope_id = esp_netif_get_netif_impl_index(EXAMPLE_INTERFACE);
        addr_family = AF_INET6;
        ip_protocol = IPPROTO_IPV6;
#elif defined(CONFIG_EXAMPLE_SOCKET_IP_INPUT_STDIN)
        struct sockaddr_storage dest_addr = {0};
        ESP_ERROR_CHECK(get_addr_from_stdin(PORT, SOCK_STREAM, &ip_protocol, &addr_family, &dest_addr));
#endif
        int sock = socket(addr_family, SOCK_STREAM, ip_protocol);
        if (sock < 0)
        {
            ESP_LOGE(TAG, "Unable to create socket: errno %d", errno);
        }
        else
        {
            ESP_LOGI(TAG, "Socket created, connecting to %s:%d", host_ip, PORT);
        }

        int err = connect(sock, (struct sockaddr *)&dest_addr, sizeof(struct sockaddr_in6));
        if (err != 0)
        {
            ESP_LOGE(TAG, "Socket unable to connect: errno %d", errno);
        }
        else
        {
            ESP_LOGI(TAG, "Successfully connected");
        }

        while (1)
        {
            if (err == 0)
            {
                if (firstSend)
                {
                    sprintf(payload, "{\"deviceSn\":%lld,\"devicePwd\":\"%s\"}", DEVICE_SN, DEVICE_PWD);
                }
                else
                {
                    time_t timestamp = mktime(&tm_info);
                    sprintf(payload, "{\"temperature\":%.2f,\"humidity\":%.2f,\"timestamp\":%ld}", Tem_val, Hum_val, timestamp);
                }

                ESP_LOGE(TAG, "send message %s", payload);
                int err = send(sock, payload, strlen(payload), 0);
                firstSend = false;
                if (err < 0)
                {
                    firstSend = true;
                    ESP_LOGE(TAG, "Error occurred during sending: errno %d", errno);
                    vTaskDelay(1000 / portTICK_PERIOD_MS);
                    break;
                }
            }
            else
            {
                firstSend = true;
                vTaskDelay(1000 / portTICK_PERIOD_MS);
                break;
            }

            vTaskDelay(1000 * 10 / portTICK_PERIOD_MS);
        }

        if (sock != -1)
        {
            ESP_LOGE(TAG, "Shutting down socket and restarting...");
            shutdown(sock, 0);
            close(sock);
        }
    }
    vTaskDelete(NULL);
}

void tcp_client_task_create()
{
    ESP_ERROR_CHECK(example_connect());
    xTaskCreate(tcp_client_task, "tcp_client", 4096, NULL, 5, NULL);
}
