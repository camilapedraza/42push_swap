/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpedraza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 17:21:04 by mpedraza          #+#    #+#             */
/*   Updated: 2025/11/17 18:28:40 by mpedraza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(int n)
{
	if (n / 10 == 0)
		return (1);
	return (count_digits(n / 10) + 1);
}

static void	cat_digit(char *dest, char c)
{
	while (*dest)
		dest++;
	*dest = c;
	*(dest + 1) = '\0';
}

static void	parse_int(char *dest, int n)
{
	long	nb;	

	nb = (long)n;
	if (nb < 0)
	{
		cat_digit(dest, '-');
		nb = -nb;
	}
	if (nb > 9)
	{
		parse_int(dest, nb / 10);
		cat_digit(dest, (nb % 10 + 48));
	}
	if (nb < 10)
		cat_digit(dest, nb + 48);
}

char	*ft_itoa(int n)
{
	char	*dest;
	int		len;

	len = count_digits(n);
	if (n < 0)
		len += 1;
	dest = ft_calloc(len + 1, sizeof(char));
	if (!dest)
		return (NULL);
	parse_int(dest, n);
	return (dest);
}
