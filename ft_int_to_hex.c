#include "ft_printf.h"

char *ft_int_to_hex(int n)
{
	ssize_t		i;
	char		p[9];

	i = 8;
	p[i] = '\0';
	if (n == 0)
		return (ft_strdup("0"));
	while (--i != -1 && n != 0)
	{
		if ((n % 16) < 10)
			p[i] = ((n % 16)) + 48;
		else
			p[i] = (n % 16) + 87;
		n = n / 16;
	}
	return (ft_strdup(&p[i + 1]));
}
