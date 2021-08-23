#include "libft.h"

static int	getsize(unsigned int nb)
{
	int		size;

	size = 0;
	if (nb <= 0)
		size++;
	while (nb)
	{
		size++;
		nb = nb / 10;
	}
	return (size);
}

char	*ft_utoa(unsigned int n)
{
	char	*nbr;
	int		size;

	size = getsize(n);
	nbr = malloc(sizeof(char) * (size + 1));
	if (!nbr)
		return (NULL);
	nbr[size] = '\0';
	if (n < 0)
		nbr[0] = '-';
	if (n == 0)
		nbr[0] = '0';
	while (n)
	{
		--size;
		if ((n % 10) >= 0)
			nbr[size] = (n % 10) + 48;
		else
			nbr[size] = -1 * (n % 10) + 48;
		n = n / 10;
	}
	return (nbr);
}
