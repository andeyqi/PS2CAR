#include <stdint.h>
#include "stm32f4xx.h"

#define SYS_TICK_PER_SECOND (1000)

static volatile uint32_t delay_us_counters = 0;
/**
  * @brief  初始化配置system tick定时器.
  * @param  None
  * @retval None
  */

void  bsp_systick_configuration(void)
{
    RCC_ClocksTypeDef  rcc_clocks;
    uint32_t         cnts;
    /* 获取系统时钟频率 */
    RCC_GetClocksFreq(&rcc_clocks);
    /* System Tick 重载值计算 */
    cnts = (uint32_t)rcc_clocks.HCLK_Frequency / SYS_TICK_PER_SECOND;
    cnts = cnts / 8;
    /* 配置System tick 定时器 */
    SysTick_Config(cnts);
    SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK_Div8);
}

/**
  * @brief  system tick 中断处理函数.
  * @param  None
  * @retval None
  */

void SysTick_Handler(void)
{
    static uint32_t increase_cnts = 0;
    delay_us_counters++;
    if(++increase_cnts == SYS_TICK_PER_SECOND/2)
    {
        increase_cnts = 0;
        /* LED输出反转 */
        //board_led_reversal(BOARD_LED_ALL);
    }
}
/**
  * @brief  system tick延时函数ms.
  * @param  ms 需要演示的时间
  * @retval None
  */
void delay_ms(uint32_t ms)
{
    delay_us_counters = 0;
    while(delay_us_counters < ms);
}


void delay_us(uint32_t us)
{
    delay_us_counters = 0;
    while(delay_us_counters < us);
}
/**
  * @brief  获取系统
  * @param  ms 需要演示的时间
  * @retval None
  */
uint32_t get_sys_tick(void)
{
	return delay_us_counters;
}