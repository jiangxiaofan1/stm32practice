#include "stm32f10x.h"                  // Device header
#include "LED.h"
#include "Delay.h"

#define USE_PIN 0x00FE

void LED_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin =  USE_PIN ; // pin 1~7
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	GPIO_Write(GPIOA, ~(0x0000));
}


void LED_On(void)
{
	for(int i=0;i<USE_PIN;i++)
	{
		if( !(USE_PIN & (0x0001 << i))) continue;
		
		GPIO_WriteBit(GPIOA, 0x0001 << i,Bit_RESET);
		Delay_ms(500);
		GPIO_WriteBit(GPIOA, 0x0001 << i,Bit_SET);
		Delay_ms(500);
	}
}

void LED_Off(void)
{
	GPIO_WriteBit(GPIOA, USE_PIN, Bit_SET);
}



