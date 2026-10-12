/**
 * @file system_health_monitor_task.c
 * @brief Source file for the system health monitor task.
 *
 * It does the following:
 * - Monitors the internal CPU temperature
 * - Monitors the watchdog timer and activates it only when the debugger is not attached
 *
 * @author Anirudh Singh
 * @date 12th October 2026
 */

#include "system_health_monitor_task.h"
#include "FreeRTOSTasks.h"

/**
 * Function definitions
 */
static void vSystemHealthMonitorTask(void *param);

/**
 * Task to get temperature values
 *
 * - Call a function that returns temperature in Celsius
 * - Check the resulting temperature against a threshold
 * - If its outside the threshold send an error message
 * - If its inside this value then let it run
 */
static void vSystemHealthMonitorTask(void *param) {
  (void)param;
}

void vSystemHealthMonitorTaskStart(void) {
  configASSERT(pdPASS == xTaskCreate(vSystemHealthMonitorTask,
                                     "System Health Monitor Task",
                                     SYSTEM_HEALTH_MONITOR_TASK_STACK_SIZE,
                                     NULL,
                                     SYSTEM_HEALTH_MONITOR_TASK_STACK_PRIORITY,
                                     NULL));
}
