#include "stm32f10x.h"                  // Device header
#include "Buzzer.h"
#include "Delay.h"

#define USE_PIN GPIO_Pin_12

void Buzzer_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin =  USE_PIN ;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	Buzzer_Off();
}	



void Buzzer_On(void)
{
	GPIO_WriteBit(GPIOB, USE_PIN, Bit_RESET);
	Delay_ms(500);
	GPIO_WriteBit(GPIOB, USE_PIN, Bit_SET);
	Delay_ms(500);

}	


void Buzzer_Off(void)
{
	GPIO_WriteBit(GPIOB, USE_PIN, Bit_SET);
}
