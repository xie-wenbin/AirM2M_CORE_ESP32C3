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
/**************************************************************************
 *  DEFINES
**************************************************************************/
#define APPL_TASK_SCHM

/***************************************************************************/

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
}

/**
 * @brief new Init task
 *
 */
void PlatformInitTask(void *pvParam)
{
    printf("Task test Start!\n");
    vTaskSuspendAll();

    int i = 0;
    int j = 0;

    for (i = 0; i < 999; i++)
    {
        /* code */
        for (j = 0; j < 9999; j++)
        {
            ;
        }
    }

    xTaskResumeAll();
    printf("Task test End!\n");

    // while (1)
    // {
    //     printf("Init Task test!\n");
    //     vTaskDelay(1000 / portTICK_PERIOD_MS);
    // }

    vTaskDelete(NULL);
}

void app_main(void)
{
    TaskHandle_t mpInitTaskHdl = NULL;
                /* 任务入口函数      字符串描述符        堆栈大小  传入参数  任务优先级  任务句柄 */
    xTaskCreate(PlatformInitTask, "PlatformInitTask", 1024,    NULL,     1,        &mpInitTaskHdl);
    xTaskCreate(myTask1,          "myTask1",          1024,    NULL,     2,        NULL);

    char pcWriteBuffer[512] = {0};

    while (1)
    {
        vTaskList(pcWriteBuffer);

        printf("------------------------------------\n");
        printf("Name      State    priority     stack    num\n");
        printf("%s\n", pcWriteBuffer);

        vTaskDelay(3000 / portTICK_PERIOD_MS);
    }
    
    
    // vTaskSuspend(mpInitTaskHdl);
    
    // vTaskDelay(5000 / portTICK_PERIOD_MS);
    // vTaskResume(mpInitTaskHdl);

    // vTaskDelay(3000 / portTICK_PERIOD_MS);
        // vTaskSuspend(mpInitTaskHdl);
}
