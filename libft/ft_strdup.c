/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpedraza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 20:39:00 by mpedraza          #+#    #+#             */
/*   Updated: 2025/11/13 20:46:51 by mpedraza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcpy(char *dest, const char *src)
{
	while (*src)
		*dest++ = *src++;
	*dest = '\0';
	return (dest);
}

char	*ft_strdup(const char *s)
{
	char		*dup;
	long int	slen;

	slen = ft_strlen(s);
	dup = malloc(sizeof(char) * slen + 1);
	if (!dup)
		return (NULL);
	ft_strcpy(dup, s);
	return (dup);
}
