#include "ft_printf.h"

int	ft_u(va_list input)
{
	int				i;
	unsigned int	ptr;
	char			*str;

	i = 0;
	ptr = va_arg(input, unsigned int);
	str = ft_utoa(ptr);
	i = output(str);
	free(str);
	return (i);
}

int	ft_x(int upper, va_list args)
{
	unsigned int	num;
	char			*hex;
	int				i;

	num = va_arg(args, unsigned int);
	hex = get_hex(num);
	if (upper)
		hex = (char *)ft_strupper(hex);
	i = output(hex);
	free(hex);
	return (i);
}

char	*get_hex(size_t n)
{
	char	p[16 + 1];
	int		i;

	i = 15;
	p[16] = '\0';
	if (n == 0)
		return (ft_strdup("0"));
	while (i != -1 && n)
	{
		if ((n % 16) < 10)
			p[i] = (n % 16) + 48;
		else
			p[i] = (n % 16) + 87;
		n = n / 16;
		i--;
	}
	return (ft_strdup(&p[i + 1]));
}

int	ft_percent(void)
{
	write(1, "%", 1);
	return (1);
}
