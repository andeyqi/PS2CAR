#include "stm32f4xx.h"
#include "sys.h"

void motor_io_init(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure = {0};
	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA,ENABLE);
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3;
	GPIO_Init(GPIOA,&GPIO_InitStructure);	
}


void motor_go_former(void)
{
	PAout(0) = 1;
	PAout(1) = 0;
}

void motor_go_back(void)
{
	PAout(0) = 0;
	PAout(1) = 1;
}

void motor_turn_right(void)
{
	PAout(2) = 1;
	PAout(3) = 0;

}

void motor_turn_left(void)
{
	PAout(2) = 0;
	PAout(3) = 1;

}


void motor_stop(void)
{
	PAout(0) = 0;
	PAout(1) = 0;
	PAout(2) = 0;
	PAout(3) = 0;

}
