#include "ft_printf.h"

int	ft_c(va_list input)
{
	char	ptr;

	ptr = va_arg(input, int);
	if (!ptr)
	{
		write(1, &ptr, 1);
		return (1);
	}
	ft_putchar(ptr);
	return (1);
}

int	ft_s(va_list input)
{
	int		i;
	char	*str;
	char	*ptr;

	ptr = va_arg(input, char *);
	if (!ptr)
		return (output("(null)"));
	str = ft_strdup(ptr);
	i = output(str);
	free(str);
	return (i);
}

int	ft_p(va_list input)
{
	size_t			ptr;
	char			*str;
	char			*hex;
	int				i;

	ptr = va_arg(input, size_t);
	if (!ptr)
		return (output("0x0"));
	hex = get_hex(ptr);
	str = ft_strjoin("0x", hex);
	i = output(str);
	free(hex);
	free(str);
	return (i);
}

int	ft_d_i(va_list input)
{
	int		i;
	int		ptr;
	char	*str;

	i = 0;
	ptr = va_arg(input, int);
	str = ft_itoa(ptr);
	i = output(str);
	free(str);
	return (i);
}
