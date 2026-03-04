#include "key_scan_regular_scan_raw_demo.h"
//key scan regular scan mode

void app_example(void)
{     
    RTK_LOGI(TAG, "kscan_regular_scan_raw_thread creat!\r\n");   
    if (rtos_task_create(NULL, "kscan_regular_scan_raw_thread", (rtos_task_t) kscan_regular_scan_raw_thread, NULL, 1024 * 4, 1) != RTK_SUCCESS) 
    {
        RTK_LOGE(TAG, "\n\r%s rtos_task_create(init_thread) failed", __FUNCTION__);
    }
}
