/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpedraza <mpedraza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 11:22:45 by mpedraza          #+#    #+#             */
/*   Updated: 2025/11/11 17:35:40 by mpedraza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	char	*b;
	char	*l;

	i = 0;
	if (!*little)
		return ((char *)big);
	while (*big && i < len)
	{
		b = (char *)big;
		l = (char *)little;
		j = i;
		while (*b == *l && *b && *l && j < len)
		{
			b++;
			l++;
			j++;
		}
		if (*l == '\0')
			return ((char *)big);
		big++;
		i++;
	}
	return (NULL);
}
