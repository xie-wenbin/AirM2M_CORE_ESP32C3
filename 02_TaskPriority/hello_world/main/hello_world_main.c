/* Hello World Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#include <stdio.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_spi_flash.h"

/**
 * @brief new Init task
 *
 */
void myTask1(void *pvParam)
{
    while (1)
    {
        printf("Task 111!\n");
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }

    vTaskDelete(NULL);
}

/**
 * @brief new Init task
 *
 */
void PlatformInitTask(void *pvParam)
{
    while (1)
    {
        printf("Init Task test!\n");
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }

    vTaskDelete(NULL);
}

void app_main(void)
{
    // printf("Hello world!\n");

    UBaseType_t iPriority = 0;

    TaskHandle_t mInitTaskHdl = NULL;
                /* 任务入口函数      字符串描述符        堆栈大小  传入参数  任务优先级  任务句柄 */
    xTaskCreate(PlatformInitTask, "PlatformInitTask", 1024,    NULL,     1,        &mInitTaskHdl);
    xTaskCreate(myTask1,          "myTask1",          1024,    NULL,     2,        NULL);

    vTaskPrioritySet(mInitTaskHdl, 3);

    iPriority = uxTaskPriorityGet(mInitTaskHdl);

    printf("iPriority = %d\n",iPriority);
}
