#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "led.h"

static const char *TAG = "LED";
static bool led_state = false;

void led_init(void)
{
    ESP_LOGI(TAG, "💡 LED initialized from file: %s, line: %d", __FILE__, __LINE__);
    ESP_LOGI(TAG, "🔧 LED module ready");
    led_state = false;
}

void led_on(void)
{
    led_state = true;
    ESP_LOGI(TAG, "✅ LED ON from file: %s, line: %d", __FILE__, __LINE__);
    ESP_LOGI(TAG, "🟢 LED is now ON");
}

void led_off(void)
{
    led_state = false;
    ESP_LOGI(TAG, "❌ LED OFF from file: %s, line: %d", __FILE__, __LINE__);
    ESP_LOGI(TAG, "🔴 LED is now OFF");
}

void led_toggle(void)
{
    if (led_state) {
        led_off();
    } else {
        led_on();
    }
    ESP_LOGI(TAG, "🔄 LED toggled from file: %s, line: %d", __FILE__, __LINE__);
}

bool led_get_state(void)
{
    ESP_LOGD(TAG, "📊 LED state checked from file: %s, line: %d", __FILE__, __LINE__);
    return led_state;
}

void led_blink_task(void *parameter)
{
    ESP_LOGI(TAG, "✨ LED blink task started from file: %s, line: %d", __FILE__, __LINE__);
    
    while (1) {
        led_toggle();
        vTaskDelay(pdMS_TO_TICKS(3000)); // 3 seconds delay
    }
}

void led_start_blinking(void)
{
    ESP_LOGI(TAG, "🚀 Starting LED blink task from file: %s, line: %d", __FILE__, __LINE__);
    xTaskCreate(led_blink_task, "led_blink", 2048, NULL, 5, NULL);
}