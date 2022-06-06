#include "lv_port_indev.h"

static void button_read(lv_indev_drv_t *indev_drv, lv_indev_data_t *data);
static SemaphoreHandle_t button_mutex = NULL;

lv_indev_t *indev_encoder;
lv_group_t *group;

static button_event_t ev;
static QueueHandle_t button_events;
static bool is_push = false;

static int32_t button_diff = 0;

void lv_port_indev_init(void)
{
    static lv_indev_drv_t indev_drv;
    button_mutex = xSemaphoreCreateMutex();
    button_events = button_init(PIN_BIT(Left_Button) | PIN_BIT(Right_Button) | PIN_BIT(Middle_Button));

    /*Register a encoder input device*/
    lv_indev_drv_init(&indev_drv);
    indev_drv.type = LV_INDEV_TYPE_ENCODER;
    indev_drv.read_cb = button_read;
    indev_encoder = lv_indev_drv_register(&indev_drv);

    group = lv_group_create();
    lv_indev_set_group(indev_encoder, group);
}

static void button_read(lv_indev_drv_t *indev_drv, lv_indev_data_t *data)
{
    data->enc_diff = button_diff;

    data->state = is_push ? LV_INDEV_STATE_PRESSED : LV_INDEV_STATE_RELEASED;

    if (button_diff != 0)
    {
        button_diff = 0;
    }
    if (is_push)
    {
        is_push = false;
    }
}

static void indev_task(void *pvParameter)
{

    while (1)
    {
        vTaskDelay(pdMS_TO_TICKS(150));

        if (pdTRUE == xSemaphoreTake(button_mutex, portMAX_DELAY))
        {
            if (xQueueReceive(button_events, &ev, 1000 / portTICK_PERIOD_MS))
            {
                if ((ev.pin == Left_Button) && (ev.event == BUTTON_DOWN))
                {
                    button_diff = -1;
                }
                if ((ev.pin == Right_Button) && (ev.event == BUTTON_DOWN))
                {
                    button_diff = 1;
                }
                if ((ev.pin == Middle_Button) && (ev.event == BUTTON_DOWN))
                {
                    is_push = true;
                }
            }
            xSemaphoreGive(button_mutex);
        }
    }
}

void indev_task_create(void)
{
    xTaskCreatePinnedToCore(indev_task, "indev_task", 1024, NULL, 1, NULL, 1);
}

lv_indev_t *get_indev(void)
{
    return indev_encoder;
}

lv_group_t *get_group(void)
{
    return group;
}