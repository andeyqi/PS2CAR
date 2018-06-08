/*
 * File      : usart.h
 * This file is the interface of usart.
 * COPYRIGHT (C) 2006 - 2012, by andey.
 */
#ifndef __USART_H__
#define __USART_H__
#include "stm32f4xx.h"
extern uint8_t usart_init(void);
extern uint8_t usart_send_char(uint16_t data);
extern uint8_t usart_get_char(void);
extern uint8_t usart_send_string(char * s,uint16_t len);
#endif /*end of __USART_H__*/
