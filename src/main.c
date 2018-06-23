#include <stdio.h>
#include <stdlib.h>
#include "usart.h"
#include "pstwo.h"
#include "bsp_systick.h"
#include "motor.h"

int main(void)
{
	u8 key;  
	usart_init();
	bsp_systick_configuration();
	printf("hello world\n");
	PS2_Init();			 //驱动端口初始化
	PS2_SetInit();		 //配配置初始化,配置“红绿灯模式”，并选择是否可以修改
	                     //开启震动模式
	motor_io_init();
	while(1)
	{
		//LED =! LED;
		key=PS2_DataKey();
		if(key!=0)                   //有按键按下
    	{
			printf("  \r\n   %d  is  light  \r\n",Data[1]);//ID
			printf("  \r\n   %d  is  pressed  \r\n",key);
			if(key == 11)
			{
				PS2_Vibration(0xFF,0x00);  //发出震动后必须有延时  delay_ms(1000);
				delay_ms(500);
			}
			else if(key == 12)
			{
				PS2_Vibration(0x00,0xFF);  //发出震动后必须有延时  delay_ms(1000);
				delay_ms(500);
			}
			else
				 PS2_Vibration(0x00,0x00); 
    	}
		printf(" %5d %5d %5d %5d\r\n",PS2_AnologData(PSS_LX),PS2_AnologData(PSS_LY),
		                              PS2_AnologData(PSS_RX),PS2_AnologData(PSS_RY) );
		if(PS2_AnologData(PSS_LX) == 0)
		{
			motor_turn_left();
		}
		else if(PS2_AnologData(PSS_LX) == 255)
		{
			motor_turn_right();
		}
		else if(PS2_AnologData(PSS_LY) == 0)
		{
			motor_go_former();
		}
		else if(PS2_AnologData(PSS_LY) == 255)
		{
			motor_go_back();
		}
		else
		{
			motor_stop();
		}
		delay_ms(50);
	}
	return 0;
}