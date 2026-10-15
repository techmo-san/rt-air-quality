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

#include <stdbool.h>

#include "FreeRTOSTasks.h"
#include "system_health_monitor_task.h"

/**
 * Function definitions
 */
static void vSystemHealthMonitorTask(void *param);
/**
 * ToDo:
 * - Function to get temperature from analog values
 * - Function to convert the temperature threshold values to ADC values
 * - 
 */

static volatile uint8_t adc_conversion_complete = 0; // Variable to confirm conversion of analog value
static volatile uint8_t adc_temp_val = 0;            // Variable to save the converted temperature value
static volatile bool mcu_temp_ok = true;             // Flag variable to monitor internal CPU temperature

volatile bool g_sensors_task_ok = false;

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

  // float internal_temp;

  if ((CoreDebug->DHCSR & CoreDebug_DHCSR_C_DEBUGEN_Msk) == 0) {
    // ToDo: Initialise the watchdog timer
  }

  // bool system_healthy = false;
}

void vSystemHealthMonitorTaskStart(void) {
  configASSERT(pdPASS == xTaskCreate(vSystemHealthMonitorTask,
                                     "System Health Monitor Task",
                                     SYSTEM_HEALTH_MONITOR_TASK_STACK_SIZE,
                                     NULL,
                                     SYSTEM_HEALTH_MONITOR_TASK_STACK_PRIORITY,
                                     NULL));
}
