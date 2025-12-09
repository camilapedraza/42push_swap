/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpedraza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 22:12:54 by mpedraza          #+#    #+#             */
/*   Updated: 2025/11/10 22:32:57 by mpedraza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t siz)
{
	size_t	si;
	size_t	di;
	size_t	dlen;
	size_t	slen;

	dlen = ft_strlen(dst);
	slen = ft_strlen(src);
	di = dlen;
	si = 0;
	if (siz == 0)
		return (slen);
	if (siz <= dlen)
		return (slen + siz);
	while (src[si] && si < (siz - dlen - 1))
		dst[di++] = src[si++];
	dst[di] = '\0';
	return (slen + dlen);
}
