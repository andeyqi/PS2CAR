#ifndef _BSP_SYSTICK_H_
#define _BSP_SYSTICK_H_
#include <stdint.h>
/**
  * @brief  初始化配置system tick定时器.
  * @param  None
  * @retval None
  */

extern void  bsp_systick_configuration(void);

/**
  * @brief  system tick延时函数ms.
  * @param  ms 需要演示的时间
  * @retval None
  */
  
extern void delay_ms(uint32_t ms);
extern void delay_us(uint32_t us);
extern uint32_t get_sys_tick(void);
#endif /* end of _BSP_SYSTICK_H_*/
