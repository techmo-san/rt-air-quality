/**
 * @file tim.h
 * @brief Setup timers inside the MCU
 *
 * @author Anirudh Singh
 * @date 12th October 2026
 */

#ifndef INC_TIM_H
#define INC_TIM_H

/**
 * Initialise the general purpose timer TIM2 to trigger analog to
 * digital conversion for internal temperature sensor at 1 Hz.
 */
void tim_2_init(void);

#endif // !INC_TIM_H
