/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheimann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 19:57:35 by sheimann          #+#    #+#             */
/*   Updated: 2021/02/10 19:57:36 by sheimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*sdup;
	char	*str;
	size_t	size;

	size = ft_strlen(s1) + 1;
	str = malloc(size);
	if (!str)
		return (NULL);
	sdup = (char *)ft_memcpy(str, s1, size);
	if (!sdup)
	{
		free(str);
		return (NULL);
	}
	return (sdup);
}
