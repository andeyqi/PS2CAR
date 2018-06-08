#ifndef __LOG_H__
#define __LOG_H__
#include <stdio.h>

#define LOG_INFO(fromat,...) printf("\033[33m" fromat "\033[0m\n",##__VA_ARGS__)
#define LOG_ERROR(fromat,...) printf("\033[31m" fromat "\033[0m\n",##__VA_ARGS__)

#endif /* end of __LOG_H__*/
