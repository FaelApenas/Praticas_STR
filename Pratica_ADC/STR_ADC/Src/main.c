/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2024 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>
#include <stdio.h>

#include "adc.h"
#include "Uart.h"

#define SR_EOC	(1U<<1)

int __io_putchar(int ch)
{
	uart_write(ch);
	return ch;
}
static void adc_callback();


int sensor_value;
int main(void)
{
	uart_int(9600);
	adc_init();
	start_conv();
    while(1)
    {

    }
    return 0;
}

static void adc_callback()
{
	sensor_value = ADC1->DR;
	float voltage= sensor_value*3.3/4095;
	printf("Valor lido : %.2f\n\r",voltage);
	for(int i=0; i<1000000;i++){}

}
void ADC_IRQHandler()
{
	if((ADC1->SR & SR_EOC)!=0)
	{
		ADC1->SR &=~SR_EOC;
		adc_callback();

	}
}
