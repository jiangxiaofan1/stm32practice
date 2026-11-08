#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "Led.h"
#include "Key.h"
#include "Buzzer.h"
#include "OLED.h"
#include "CountSensor.h"
#include "Encoder.h"
#include "Timer.h"
#include "PWM.h"
#include "Servo.h"
uint16_t Num=0;

uint8_t KeyNum;
float Angle=0.0;

int main(void)
{
	LED_Init();
	Key_Init();
	Buzzer_Init();
	OLED_Init();
	CountSensor_Init();
	OLED_ShowString(1,1,"count:");
	Encoder_Init();
	Timer_Init();
	PWM_Init();
	
	uint8_t a = 0;
	int16_t num=0;
	while(1)
	{
//		num +=Encoder_Get();
//		OLED_ShowNum(1,7, num, 5);
//		OLED_ShowNum(2,1,Num, 5);
//		OLED_ShowNum(3,1, TIM_GetCounter(TIM2), 5);
		
		
//		for(int i=0;i<=100;i++)
//		{
//			PWM_SetCompare1(i);
//			Delay_ms(20);
//		}
//		for(int i=0;i<=100;i++)
//		{
//			PWM_SetCompare1(100-i);
//			Delay_ms(20);
//		}
		KeyNum = Key_GetKeyNum();
		if( KeyNum == 2 )
		{
			Angle+=30;
			if(Angle > 180)
			{
				Angle =0;
			}
			Servo_SetAngle(Angle);
			OLED_ShowNum(2,1,Angle, 3);
		}		
		
		
	}
}

void TIM2_IRQHandler(void)
{
	if (TIM_GetITStatus(TIM2, TIM_IT_Update) == SET)
	{
		Num++;
		TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
	}
}