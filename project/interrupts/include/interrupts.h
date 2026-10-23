/**
 * @file interrupts.h
 * @brief Header file for interrupt routines (ISR) for different peripherals
 *
 * @author Anirudh Singh
 * @date 23rd October 2026
 */

#ifndef INC_INTERRUPTS_H
#define INC_INTERRUPTS_H

/**
 * ADC Interrupt Handler name as defined inside
 * the startup file 'startup_stm32f446retx.s'.
 *
 * The function will be declared here and then a custome name
 * will be used inside the source file. This is done so that
 * responsibilities are separated.
 *
 * - Interrupt files point to the handler names as defined
 *   inside the startup file.
 * - The interrupt logic is defined in the respective peripheral
 *   driver files.
 */
void ADC_IRQHandler(void);

#endif // !INC_INTERRUPTS_H
