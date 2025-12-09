/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpedraza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 18:52:59 by mpedraza          #+#    #+#             */
/*   Updated: 2025/11/17 18:13:52 by mpedraza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	cleanup(char **arr, size_t x)
{
	while (x)
		free(arr[--x]);
	free(arr);
}

static int	fill_array(char **arr, char const *s, char c, size_t size)
{
	int		i;
	int		j;
	size_t	x;

	x = 0;
	i = 0;
	while (x < size - 1)
	{
		while (s[i] && s[i] == c)
			i++;
		j = i + 1;
		while (s[j] && s[j] != c)
			j++;
		arr[x] = malloc(sizeof(char) * (j - i + 1));
		if (!arr[x])
		{
			cleanup(arr, x);
			return (0);
		}
		ft_strlcpy(arr[x], (s + i), (j - i + 1));
		i = j;
		x++;
	}
	arr[x] = NULL;
	return (1);
}

static size_t	array_size(char const *s, char c)
{
	size_t	size;

	size = 0;
	while (*s)
	{
		if (*s != c && (!*(s + 1) || *(s + 1) == c))
			size++;
		s++;
	}
	return (size);
}

char	**ft_split(char const *s, char c)
{
	size_t	size;
	char	**array;

	if (!s || !*s)
		return (ft_calloc(1, sizeof(char *)));
	size = array_size(s, c) + 1;
	array = malloc(sizeof(char *) * size);
	if (!array)
		return (NULL);
	if (!fill_array(array, s, c, size))
		return (NULL);
	return (array);
}
