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
#include "adc.h"
#include "error_handler_task.h"
#include "system_health_monitor_task.h"
#include "tim.h"

/**********************************************
 ******* Private function definitions *********
 *********************************************/

static void prvSystemHealthMonitorTask(void *param);

/**
 * Use the following function to read the analog value
 * for the internal temperature sensor. Then convert it
 * to Celsius.
 *
 * @return read_temp_celsius Temperature in Celsius
 */
static float prvGetInternalTemp(void);

static volatile uint8_t adc_temp_val = 0; // Variable to save the converted temperature value
static volatile bool mcu_temp_ok = true;  // Flag variable to monitor internal CPU temperature
volatile bool g_sensors_task_ok = false;

/**
 * Task to get temperature values
 *
 * - Call a function that returns temperature in Celsius
 * - Check the resulting temperature against a threshold
 * - If its outside the threshold send an error message
 * - If its inside this value then let it run
 */
static void prvSystemHealthMonitorTask(void *param) {
  (void)param;

  float internal_temp = prvGetInternalTemp();
  if (!((internal_temp > MIN_INT_TEMP_THRESHOLD_CELSIUS) && (internal_temp < MAX_INT_TEMP_THRESHOLD_CELSIUS))) {
    vErrorHandlerSendMsg(EVT_SYSTEM_HEALTH_TEMP_EXCEEDED);
  }
}

static float prvGetInternalTemp(void) {
  float read_temp_celsius = 0.0F; // Variable to store the ADC converted temperature value
  float V_SENSE = 0.0F;           // Convert analog value to a voltage
  uint16_t read_analog_val = 0U;  // Read analog value from the data register

  read_analog_val = adc_1_read_data_register(); // Get the value from the register
  if (read_analog_val != 0) {
    V_SENSE = ((float)read_analog_val / 4095.0F) * V_REF_PLUS; // ADC is 12-bit
    read_temp_celsius = ((V_SENSE - V_25) / AVG_SLOPE_SENSE_CURVE) + 25;
  }

  return read_temp_celsius;
}

void vSystemHealthMonitorTaskStart(void) {
  // Initialise and start the clocks
  adc_init();
  tim_2_init();

  configASSERT(pdPASS == xTaskCreate(prvSystemHealthMonitorTask,
                                     "System Health Monitor Task",
                                     SYSTEM_HEALTH_MONITOR_TASK_STACK_SIZE,
                                     NULL,
                                     SYSTEM_HEALTH_MONITOR_TASK_STACK_PRIORITY,
                                     NULL));
}
