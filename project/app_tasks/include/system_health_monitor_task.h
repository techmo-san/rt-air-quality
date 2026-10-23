/**
 * @file system_health_monitor_task.h 
 * @brief Header file for the system health monitor task.
 *
 * It does the following:
 * - Monitors the internal CPU temperature
 * - Monitors the watchdog timer and activates it only when the debugger is not attached
 *
 * @author Anirudh Singh
 * @date 12th October 2026
 */

#ifndef INC_SYSTEM_HEALTH_MONITOR_TASK_H
#define INC_SYSTEM_HEALTH_MONITOR_TASK_H

/**
 * Thresholds for the internal CPU temperature: -40 °C to 125 °C
 */
#define MIN_INT_TEMP_THRESHOLD_CELSIUS (0)
#define MAX_INT_TEMP_THRESHOLD_CELSIUS (35)

/**
 * Constants for temperature ADC conversion
 */
#define V_REF_PLUS (3.3F)
#define V_25 (0.76F)                    // in Volts (V)
#define AVG_SLOPE_SENSE_CURVE (0.0025F) // in V/°C

/**
 * Function definition for the task
 */
void vSystemHealthMonitorTaskStart(void);

#endif
