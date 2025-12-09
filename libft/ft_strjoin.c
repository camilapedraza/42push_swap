/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpedraza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 16:42:47 by mpedraza          #+#    #+#             */
/*   Updated: 2025/11/14 17:09:46 by mpedraza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	size_t	len1;
	size_t	len2;

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
