/**
 * @file adc.h
 * @brief Header file for the ADC converter driver
 *
 * @author Anirudh Singh
 * @date 12th October 2026
 */

#ifndef INC_ADC_H
#define INC_ADC_H

// Give channel numbers a name
typedef enum {
  ADC_CH_0 = 0,
  ADC_CH_1,
  ADC_CH_2,
  ADC_CH_3,
  ADC_CH_4,
  ADC_CH_5,
  ADC_CH_6,
  ADC_CH_7,
  ADC_CH_8,
  ADC_CH_9,
  ADC_CH_10,
  ADC_CH_11,
  ADC_CH_12,
  ADC_CH_13,
  ADC_CH_14,
  ADC_CH_15,
  ADC_CH_16,
  ADC_CH_17,
  ADC_CH_18,
} adc_channel_e;

/**
 * Initialise the analog-to-digital converter
 */
void adc_init(void);

#endif // !INC_ADC_H
