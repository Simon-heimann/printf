#include "ft_printf.h"


static char	*ft_strupcase(char *str);
static char	*get_hex(size_t n, size_t i);

int ft_u_int(va_list input)
{
	int i;
	unsigned int ptr;
	char *str;

	i = 0;
	ptr = va_arg(input, unsigned int);
	str = ft_uitoa(ptr);
	i = put_str(str);
	free(str);
	return (i);
}

int	ft_ptr(va_list args)
{
	size_t			pointer;
	char			*string;
	char			*tmp_str;
	int				counter;

	pointer = va_arg(args, size_t);
	if (!pointer)
		return (write(1, "0x0", 3));
	tmp_str = get_hex(pointer, 16);
	string = ft_strjoin("0x", tmp_str);
	free(tmp_str);
	counter = put_str(string);
	free(string);
	return (counter);
}

int	ft_hex(char converter, va_list args)
{
	unsigned int	hex;
	char			*string;
	int				counter;

	hex = va_arg(args, unsigned int);
	string = get_hex(hex, 8);
	if (converter == 'X')
		counter = put_str((char *)ft_strupcase(string));
	else
		counter = put_str(string);
	free(string);
	return (counter);
}

static char	*ft_strupcase(char *str)
{
	int	counter;

	counter = -1;
	while (str[++counter] != '\0')
	{
		if (str[counter] >= 97 && str[counter] <= 122)
			str[counter] = (str[counter] - 32);
	}
	return (str);
}

static char	*get_hex(size_t n, size_t i)
{
	char		p[i + 1];

	p[i] = '\0';
	if (n == 0)
		return (ft_strdup("0"));
	while (--i != (size_t)-1 && n != 0)
	{
		if ((n % 16) < 10)
			p[i] = ((n % 16)) + 48;
		else
			p[i] = (n % 16) + 87;
		n = n / 16;
	}
	return (ft_strdup(&p[i + 1]));
}

int ft_percent()
{
	write(1, "%", 1);
	return (1);
}