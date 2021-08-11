#include "ft_printf.h"

static int	conv_caller(char converter, va_list input)
{
	if (converter == 'c')
		return (ft_chr(input));
	if (converter == 's')
		return (ft_str(input));
	if (converter == 'p')
		return (ft_ptr(input));
	if (converter == 'd' || converter == 'i')
		return (ft_int_dec(input));
	if (converter == 'u')
		return (ft_u_int(input));
	if (converter == 'x' || converter == 'X')
		return (ft_hex(converter, input));
	if (converter == '%')
		return (ft_percent());
	else
		return (conv_invalid(converter));
	return (0);
}

static int	prefix_handler(char **string)
{
	char	*tmp_str;
	char	*start;
	int		counter;

	start = ft_strchr(*string, '%');
	if (!start)
	{
		counter = put_str(*string);
		*string = ft_strchr(*string, '\0');
		return (counter);
	}
	if (!(start - *string))
		return (0);
	tmp_str = ft_substr(*string, 0, start - *string);
	if (!tmp_str)
		return (-1);
	counter = put_str(tmp_str);
	*string = start;
	free(tmp_str);
	return (counter);
}

static char	converter_handler(char **string)
{
	char	conv;

	conv = (*string)[1];
	*string = *string + 2;
	return (conv);
}

int	conv_invalid(char converter)
{
	ft_putchar_fd('%', 1);
	ft_putchar_fd(converter, 1);
	return (2);
}

int	printf_handler(char **string, va_list input)
{
	int		counter;

	if (**string)
	{
		counter = prefix_handler(string);
		if (counter)
			return (counter);
		return (conv_caller(converter_handler(string), input));
	}
	return (0);
}
