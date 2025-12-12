/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_string_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpedraza <mpedraza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 15:00:12 by mpedraza          #+#    #+#             */
/*   Updated: 2025/12/12 15:16:16 by mpedraza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
		write(fd, s++, 1);
}

size_t ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t ft_strlcpy(char *dst, const char *src, size_t siz)
{
	size_t i;

	i = 0;
	if (siz > 0)
	{
		while (src[i] && i + 1 < siz)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	while (src[i])
		i++;
	return (i);
}

char *ft_substr(char const *s, unsigned int start, size_t len)
{
	char *src;
	char *dest;
	size_t slen;
	size_t dsize;

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

size_t ft_strlcat(char *dst, const char *src, size_t siz)
{
	size_t si;
	size_t di;
	size_t dlen;
	size_t slen;

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

char	*string_join(char const *s1, char const *s2)
{
	char *dest;
	size_t len1;
	size_t len2;

	len1 = 0;
	len2 = 0;
	if (s1)
		len1 = ft_strlen(s1);
	if (s2)
		len2 = ft_strlen(s2);
	dest = ft_calloc((len1 + len2 + 1), sizeof(char));
	if (!dest)
		return (NULL);
	if (s1)
		ft_strlcpy(dest, s1, (len1 + 1));
	if (s2)
		ft_strlcat(dest, s2, (len1 + len2 + 1));
	return (dest);
}
