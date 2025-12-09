/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpedraza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 17:37:52 by mpedraza          #+#    #+#             */
/*   Updated: 2025/11/14 18:39:44 by mpedraza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(char const *c, char const *set)
{
	while (*set)
		if (*c == *set++)
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*dest;
	size_t	len;

	if (!s1 || !set)
		return (ft_calloc(1, 1));
	while (is_in_set(s1, set))
		s1++;
	len = ft_strlen(s1);
	if (len > 0)
		while (is_in_set((s1 + len - 1), set))
			len--;
	dest = malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	ft_strlcpy(dest, s1, len + 1);
	return (dest);
}
