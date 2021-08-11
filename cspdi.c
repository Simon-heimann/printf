#include "ft_printf.h"

int ft_chr(va_list input)
{
	char ptr;

	ptr = va_arg(input, int);
	if (!ptr)
		{
			write(1, &ptr, 1);
			return (1);
		}
	ft_putchar(ptr);
	return(1);
}

int	ft_str(va_list input)
{
	int		i;
	char 	*str;
	char	*ptr;

	ptr = va_arg(input, char *);
	if (!ptr)
		return (write(1, "(null)", 6));
	str = ft_strdup(ptr);
	i = put_str(str);
	free(str);
	return (i);
}

int ft_int_dec(va_list input)
{
	int i;
	int ptr;
	char *str;

	i = 0;
	ptr = va_arg(input, int);
	str = ft_itoa(ptr);
	i = put_str(str);
	free(str);
	return (i);
}
