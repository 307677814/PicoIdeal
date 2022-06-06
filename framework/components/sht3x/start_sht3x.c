#include "start_sht3x.h"

#define I2C_MASTER_SCL_IO (gpio_num_t)22 /*!< gpio number for I2C master clock */
#define I2C_MASTER_SDA_IO (gpio_num_t)21 /*!< gpio number for I2C master data  */
#define I2C_MASTER_NUM I2C_NUM_1         /*!< I2C port number for master dev */
#define I2C_MASTER_FREQ_HZ 100000        /*!< I2C master clock frequency */

i2c_bus_handle_t i2c_bus = NULL;
sht3x_handle_t sht3x = NULL;

/**
 * @brief i2c master initialization
 */
void sht3x_init()
{
    i2c_config_t conf = {
        .mode = I2C_MODE_MASTER,
        .sda_io_num = I2C_MASTER_SDA_IO,
        .sda_pullup_en = GPIO_PULLUP_ENABLE,
        .scl_io_num = I2C_MASTER_SCL_IO,
        .scl_pullup_en = GPIO_PULLUP_ENABLE,
        .master.clk_speed = I2C_MASTER_FREQ_HZ,
    };
    i2c_bus = i2c_bus_create(I2C_MASTER_NUM, &conf);
    sht3x = sht3x_create(i2c_bus, SHT3x_ADDR_PIN_SELECT_VSS);
    sht3x_set_measure_mode(sht3x, SHT3x_PER_2_MEDIUM); /*!< here read data in periodic mode*/
}

void sht3x_get_data_callback()
{
    int temperatureHigh = 0;
    int temperatureLow = 0;
    int humidityHigh = 0;
    int humidityLow = 0;
    if (sht3x_get_humiture(sht3x, &Tem_val, &Hum_val) == 0)
    {
        temperatureHigh = (int)Tem_val;
        temperatureLow = (int)(Tem_val * 100) % 10 + ((int)(Tem_val * 10) % 10) * 10;
        humidityHigh = (int)Hum_val;
        humidityLow = (int)(Hum_val * 100) % 10 + ((int)(Hum_val * 10) % 10) * 10;
        lv_label_set_text_fmt(ui_TemperatureHigh, "%.2d", (int)temperatureHigh);
        lv_label_set_text_fmt(ui_TemperatureLow, "%.2d", (int)temperatureLow);
        lv_label_set_text_fmt(ui_HumidityHigh, "%.2d", (int)humidityHigh);
        lv_label_set_text_fmt(ui_HumidityLow, "%.2d", (int)humidityLow);
    }
}

void start_sht3x()
{
    sht3x_init();
    vTaskDelay(1000 / portTICK_RATE_MS);
    const esp_timer_create_args_t periodic_timer_args = {
        .callback = &sht3x_get_data_callback,
        /* name is optional, but may help identify the timer when debugging */
        .name = "periodic_sht3x"};

    esp_timer_handle_t periodic_timer;
    ESP_ERROR_CHECK(esp_timer_create(&periodic_timer_args, &periodic_timer));
    ESP_ERROR_CHECK(esp_timer_start_periodic(periodic_timer, 1000000));
}
