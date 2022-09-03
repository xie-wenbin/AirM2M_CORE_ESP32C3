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
void PlatformInitTask(void *pvParam)
{
    //while (1)
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
    TaskHandle_t pxTask = NULL;

    // TaskHandle_t mInitTaskHdl = NULL;
    xTaskCreate(PlatformInitTask, "PlatformInitTask", 1024, NULL, 1, &pxTask/* &mInitTaskHdl */);

    iPriority = uxTaskPriorityGet(pxTask);

    printf("iPriority = %d\n",iPriority);
}
