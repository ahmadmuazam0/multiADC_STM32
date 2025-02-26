/*
 * ADC_Read.h
 *
 *  Created on: Feb 24, 2025
 *      Author: ranamuazam
 */

#ifndef INC_ADC_READ_H_
#define INC_ADC_READ_H_
#include "main.h"

void switch_adc_ch(uint8_t ch, ADC_HandleTypeDef* hadc) ;
uint32_t Read_ADC(uint8_t ch, ADC_HandleTypeDef* hadc);


#endif /* INC_ADC_READ_H_ */
