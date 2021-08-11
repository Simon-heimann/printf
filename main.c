#include "ft_printf.h"
#include <stdio.h>

int main()
{
	unsigned int x = -1;
	printf("%x\n", x);
	ft_printf("%x\n", x);
}

/*
int bol = 0;
	if (bol)
	{
		//unsigned int c = 999999999;
		int ret = ft_printf("%%");
		ft_printf("\nthe return was %i", ret);
	}
	else 
	{
		//unsigned int c = 999999999;
		int ret = printf("%%");
		printf("\nthe return was %i", ret);
	}
*/