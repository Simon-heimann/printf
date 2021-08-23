#include "ft_printf.h"

static int	find_converter(char converter, va_list input)
{
	if (converter == 'c')
		return (ft_c(input));
	if (converter == 's')
		return (ft_s(input));
	if (converter == 'p')
		return (ft_p(input));
	if (converter == 'd' || converter == 'i')
		return (ft_d_i(input));
	if (converter == 'u')
		return (ft_u(input));
	if (converter == 'x')
		return (ft_x(0, input));
	if (converter == 'X')
		return (ft_x(1, input));
	if (converter == '%')
		return (ft_percent());
	else
	{
		ft_putchar('%');
		ft_putchar(converter);
		return (2);
	}
	return (0);
}

static char	converter_handler(char **ptr)
{
	char	conv;

	conv = (*ptr)[1];
	*ptr = *ptr + 2;
	return (conv);
}

static int	move_to_percent(char **ptr)
{
	char	*output_str;
	char	*percent;
	int		nbchar;

	percent = ft_strchr(*ptr, '%');
	if (percent == NULL)
	{
		nbchar = output(*ptr);
		*ptr = ft_strchr(*ptr, '\0');
		return (nbchar);
	}
	if ((percent - *ptr) == 0)
		return (0);
	output_str = ft_substr(*ptr, 0, percent - *ptr);
	if (!output_str)
		return (-1);
	nbchar = output(output_str);
	*ptr = percent;
	free(output_str);
	return (nbchar);
}

int	converter(char **ptr, va_list input)
{
	int		nbchar;

	if (**ptr)
	{
		nbchar = move_to_percent(ptr);
		if (nbchar)
			return (nbchar);
		return (find_converter(converter_handler(ptr), input));
	}
	return (0);
}
