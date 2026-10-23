/**
 * @file interrupts.c
 * @brief Source file for interrupt routines (ISR) for different peripherals
 *
 * @author Anirudh Singh
 * @date 23rd October 2026
 */

#include "interrupts.h"
#include "adc.h"

/**
 * Use this name for the ISR logic inside 'adc.c' driver file.
 */
void ADC_IRQHandler(void) {
  ADC_IRQ();
}
