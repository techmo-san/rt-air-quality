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
 * Thresholds for the internal CPU temperature
 */
#define MAX_INT_TEMP_THRESHOLD_CELSIUS (100)
#define MIN_INT_TEMP_THRESHOLD_CELSIUS (-10)

/**
 * Function definition for the task
 */
void vSystemHealthMonitorTaskStart(void);

#endif
