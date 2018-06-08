#include <stdio.h>
#include <stdlib.h>
#include "usart.h"

int main(void)
{
	usart_init();
	printf("hello world\n");
	while(1);
	return 0;
}