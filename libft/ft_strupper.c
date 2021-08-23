#include "libft.h"

char	*ft_strupper(char *str)
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
