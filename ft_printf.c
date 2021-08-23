#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	input;
	int		totchar;
	int		mem;
	char	*ptr;

	totchar = 0;
	mem = 1;
	if (!ft_strchr(format, '%'))
		return (output((char *)format));
	va_start(input, format);
	ptr = (char *)format;
	while (*ptr)
	{
		mem = converter(&ptr, input);
		if (mem == -1)
			return (-1);
		totchar += mem;
	}
	va_end(input);
	return (totchar);
}

int	output(char *str)
{
	int	i;

	i = write(1, str, ft_strlen(str));
	return (i);
}
