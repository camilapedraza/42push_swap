/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpedraza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 14:26:42 by mpedraza          #+#    #+#             */
/*   Updated: 2025/11/14 16:41:25 by mpedraza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*src;
	char	*dest;
	size_t	slen;
	size_t	dsize;

	if (!s || len == 0)
		return (ft_calloc(1, 1));
	slen = ft_strlen(s);
	if (start > slen)
		return (ft_calloc(1, 1));
	src = (char *)s + start;
	if ((start + len) < slen)
		dsize = len + 1;
	else
		dsize = ft_strlen(src) + 1;
	dest = ft_calloc(dsize, sizeof(char));
	if (!dest)
		return (NULL);
	src = (char *)s + start;
	ft_strlcpy(dest, src, dsize);
	return (dest);
}
