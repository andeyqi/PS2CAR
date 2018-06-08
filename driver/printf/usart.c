#include "stm32f4xx.h"
#include <string.h>
uint8_t usart_gpio_cfg(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure = {0};

	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA,ENABLE); //enable gpioa clock
	GPIO_PinAFConfig(GPIOA,GPIO_PinSource9,GPIO_AF_USART1); 
	GPIO_PinAFConfig(GPIOA,GPIO_PinSource10,GPIO_AF_USART1);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9 | GPIO_Pin_10; //config gpio9 && gpio10
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;//set af mode
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; //set the speep of gpio 
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP; 
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP; 
	GPIO_Init(GPIOA,&GPIO_InitStructure); 
	return 0;
}

uint8_t usart_cfg(void)
{
	USART_InitTypeDef USART_InitStructure = {0};
	//0x4002 3800 - 0x4002 3BFF offset 0x44
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);//enable usart1 clock

	USART_InitStructure.USART_BaudRate = 115200;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	USART_InitStructure.USART_Parity = USART_Parity_No;
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	USART_Init(USART1, &USART_InitStructure); 

	USART_Cmd(USART1, ENABLE);
	//USART_ITConfig(USART1,USART_IT_RXNE,DISABLE);
	//USART_DMACmd(USART1,USART_DMAReq_Rx,ENABLE);
	return 0;
}


uint8_t usart_init(void)
{
	usart_gpio_cfg();
	usart_cfg();	
	//usart_it_cfg();
	return 0;
}

uint8_t usart_send_char(uint16_t data)
{
	USART_SendData(USART1, data);
	while(!USART_GetFlagStatus(USART1, USART_FLAG_TXE)){}
	return 0;
}

uint8_t usart_send_string(char * s,uint16_t len)
{
	for(;len > 0; len--)
	{
		usart_send_char(*(s++));
	}
	return 0;
}

uint8_t usart_get_char(void)
{
	uint16_t data = 0;
	while(USART_GetFlagStatus(USART1, USART_FLAG_RXNE) == RESET){}
	data = USART_ReceiveData(USART1);
	return data;
}

