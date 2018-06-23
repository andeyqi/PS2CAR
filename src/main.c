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
    PS2_Init();          //驱动端口初始化
    PS2_SetInit();       //配配置初始化,配置“红绿灯模式”，并选择是否可以修改
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
            switch(key)
            {
                case 5:
                case 13:
                {
                    motor_go_former();
                    printf("go former\n");
                }
                    break;
                case 7:
                case 15:
                {
                    motor_go_back();
                    printf("go back\n");
                }
                    break;
                case 8:
                {
                    motor_turn_left();
                    motor_go_former();
                    printf("turn left\n");

                }
                    break;
                case 6:
                {
                    motor_turn_right();
                    motor_go_former();
                    printf("turn right\n");
                }
                    break;
                case 16:
                {
                    motor_turn_left();
                    motor_go_back();
                    printf("back left\n");
                }
                    break;
                case 14:
                {
                    motor_turn_right();
                    motor_go_back();
                    printf("back right\n");
                }
                    break;
            }
        }
        else
        {
            motor_stop();
        }

        delay_ms(50);
    }
    return 0;
}