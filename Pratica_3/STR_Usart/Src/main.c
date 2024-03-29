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
#include "stm32f4xx.h"
#include "Uart.h"


int main(void)
{
	uart_int(14400);


	while(1)
	{
		uart_write('H');
		uart_write('e');
		uart_write('l');
		uart_write('l');
		uart_write('o');
		uart_write('\n');

		for(int i=0 ; i<1000000;i++);

	}
}
