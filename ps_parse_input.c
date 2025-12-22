/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_parse_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpedraza <mpedraza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 14:50:59 by mpedraza          #+#    #+#             */
/*   Updated: 2025/12/22 20:07:36 by mpedraza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_chars(int n, char **argv)
{
	int	i;
	int	j;
	int	count;

	i = 1;
	count = 0;
	while (i < n)
	{
		j = 0;
		while (argv[i][j++])
			count++;
		i++;
	}
	return (count);
}

char	*parse_input(int n, char **argv)
{
	int		length;
	char	*string;
	int		index;
	size_t	size;

	length = count_chars(n, argv);
	string = ft_calloc(sizeof(char), (length + n - 1));
	if (string == NULL)
		quit_push_swap(NULL);
	index = 1;
	while (index < n)
	{
		size = ft_strlen(string) + ft_strlen(argv[index]);
		ft_strlcat(string, argv[index], size + 1);
		if (index < n - 1)
			ft_strlcat(string, " ", ft_strlen(string) + 2);
		index++;
	}
	return (string);
}
