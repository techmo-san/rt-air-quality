/**
 * @file tim.c
 * @brief Setup timers inside the MCU
 *
 * @author Anirudh Singh
 * @date 12th October 2026
 */

#include "tim.h"
#include "stm32f4xx.h"

/**
 * Initialise the general purpose timer TIM2 to trigger analog to
 * digital conversion for internal temperature sensor at 1 Hz.
 *
 * Configuration steps:
 * 1. Enable TIM2 clock
 * 2. Set pre-scaler and auto-reload register
 * 3. Configure Master Mode Selection (MMS) to use update event as trigger output
 * 4. Force an update event to reload prescaler immediately
 * 5. Enable TIM2 counter
 */
void tim_2_init() {
  /**
   * Enable TIM2 clock
   *
   * Bit [0] in RCC_APB1ENR register
   */
  RCC->APB1ENR |= (1U << 0);

  /**
   * TIM2 clock speed = 2 * APB1 Clock Speed = 90 MHz (Because APB prescaler is > 1)
   * Section 6.2. page 119 of the reference manual
   *
   * Counter Period = (TIM2 Clock Speed) / ((PSC + 1) * (ARR + 1))
   * - Set the prescaler value (TIMx_PSC)
   * - This is a 16 bit register that accepts the passed value
   */
  TIM2->PSC = 0;              // Reset
  TIM2->PSC |= (44999U << 0); // (PSC + 1) = 45000

  /**
   * Set the auto-reload value (TIMx_ARR)
   * - This is a 16 bit register that accepts the passed value
   * - Depending on the speed of the timer after division with
   *   the prescaler, ARR represents the counts that will be
   *   done from 0 to 1999 (i.e. here) at a frequency of 2 kHz.
   *
   * - freq = 2 kHz
   * - Each tick = 1 / 2000 = 0.5 ms
   * - For 2000 ticks, it takes 1 s.
   */
  TIM2->ARR = 0;             // Reset
  TIM2->ARR |= (1999U << 0); // (ARR + 1) = 2000

  /**
   * Select the Master Mode MMS 2 bits bitfield [6:4] (TIMx_CR2)
   * 0U -> Reset
   * 1U -> Enable
   * 2U -> Update
   * 3U -> Compare Pulse
   * 4U -> Compare - OC1REF signal is used as trigger output (TRGO)
   * 5U -> Compare - OC2REF signal is used as trigger output (TRGO)
   * 6U -> Compare - OC3REF signal is used as trigger output (TRGO)
   * 7U -> Compare - OC4REF signal is used as trigger output (TRGO)
   *
   * By using the update mode, the TRGO signal is generated from the timer
   * whenever the counter register fills up and starts from zero again.
   */
  TIM2->CR2 |= (2U << 4);

  /**
   * Timer event generation (TIMx_EGR)
   *
   * Bit 0 UG (Update generation):
   * 0 -> No action
   * 1 -> Re-initialise the counter & generate and update of the registers
   *
   * Have the new settings take effect immediately.
   */
  TIM2->EGR |= (1U << 0);

  /**
   * Enable the counter
   * - Bit 0 in TIMx_CR1
   * 0 -> Disable counter
   * 1 -> Enable counter
   */
  TIM2->CR1 |= (1U << 0); // Timer runs continuously
}
