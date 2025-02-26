# multiADC_STM32
A HAL based header and source file to read multiple ADC from different Channels
Download the repository and extract it.
Place the Header file to the Core->inc folder
Place the source file to the Core->src folder
Include the header into your main.c
After the initialization call the function Read_ADC(Channel you want to read, ADC handler you've init) and it'll return the 32 bit unsigned integer value of ADC.
For Example:     uint32_t adcVal = Read_ADC(1 , &hadc1);  // It'll read ADC from Channel 1 of ADC1
