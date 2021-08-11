#include "ft_printf.h"

int	put_str(char *str)
{
	int i;

	i = write(1, str, ft_strlen(str));
	return (i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}