#include "ft_printf.h"

int ft_printf(const char *format, ...)
{
	va_list input;
	int nbchar;
	char *ptr;
	int	tmp_i;

	if (!ft_strchr(format, '%'))
		return (put_str((char *)format));
	va_start(input, format);
	ptr = (char *)format;
	nbchar = printf_handler(&ptr, input);
	tmp_i = 1;
	while (*ptr && tmp_i != -1)
	{
		tmp_i = printf_handler(&ptr, input);
		nbchar += tmp_i;
	}
	va_end(input);
	if (tmp_i == -1)
		return (tmp_i);
	return (nbchar);
}