/*
 * ADC_Read.c
 *
 *  Created on: Feb 25, 2025
 *      Author: ranamuazam
 */

#include "ADC_Read.h"

/**
 * @brief: To switch the channel to read multiple ADC values on respective channels
 * @param: Channel number (`ch`), ADC Handle pointer (`hadc`)
 * @return: NONE
 */
void switch_adc_ch(uint8_t ch, ADC_HandleTypeDef* hadc) {
    // Define a structure for ADC configuration
    ADC_ChannelConfTypeDef sConfig = {0};  // Initialize to zero to clear previous values

    // Configure the channel based on the input channel number
    switch(ch) {
        case 0:
            sConfig.Channel = ADC_CHANNEL_0;
            break;
        case 1:
            sConfig.Channel = ADC_CHANNEL_1;
            break;
        case 2:
            sConfig.Channel = ADC_CHANNEL_2;
            break;
        case 3:
            sConfig.Channel = ADC_CHANNEL_3;
            break;
        case 4:
            sConfig.Channel = ADC_CHANNEL_4;
            break;
        case 5:
            sConfig.Channel = ADC_CHANNEL_5;
            break;
        case 6:
            sConfig.Channel = ADC_CHANNEL_6;
            break;
        case 7:
            sConfig.Channel = ADC_CHANNEL_7;
            break;
        case 8:
            sConfig.Channel = ADC_CHANNEL_8;
            break;
        case 9:
            sConfig.Channel = ADC_CHANNEL_9;
            break;
        default:
            // Handle invalid channel case
            return;  // Exit if an invalid channel is passed
    }
    	sConfig.Rank = ADC_REGULAR_RANK_1;
		sConfig.SamplingTime = ADC_SAMPLETIME_13CYCLES_5;
    // Configure the selected ADC channel based on the provided ADC handle
    if (HAL_ADC_ConfigChannel(hadc, &sConfig) != HAL_OK) {
        Error_Handler();  // Handle the error if the configuration fails
    }
}

/**
 * @brief: To read the ADC value from a specific channel
 * @param: Channel number (`ch`), ADC Handle pointer (`hadc`)
 * @return: Return the uint32_t raw ADC value of the selected channel and ADC
 */
uint32_t Read_ADC(uint8_t ch, ADC_HandleTypeDef* hadc) {
    // Configure the selected channel
    switch_adc_ch(ch, hadc);  // Reuse the switch_adc_ch function to configure the channel

    // Start the ADC conversion
    if (HAL_ADC_Start(hadc) != HAL_OK) {
        // Error handling if starting the ADC conversion fails
        Error_Handler();
    }

    // Wait for the conversion to finish (Polling method)
    if (HAL_ADC_PollForConversion(hadc, 100) != HAL_OK) {
        // If conversion fails or times out, handle the error
        Error_Handler();
    }

    // Get the raw ADC value (12-bit resolution, so the range is 0-4095 for a single-channel ADC)
    uint32_t adcValue = HAL_ADC_GetValue(hadc);

    // Stop the ADC conversion after reading the value
    HAL_ADC_Stop(hadc);

    // Return the raw ADC value
    return adcValue;
}

