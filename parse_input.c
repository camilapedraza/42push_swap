/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpedraza <mpedraza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 14:50:59 by mpedraza          #+#    #+#             */
/*   Updated: 2025/12/14 20:32:34 by mpedraza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int count_chars(int n, char **argv)
{
	int i;
	int j;
	int count;

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

static char	*join_arguments(char const *s1, char const *s2)
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
	dest = ft_calloc((len1 + len2 + 2), sizeof(char));
	if (!dest)
		return (NULL);
	if (s1)
		ft_strlcpy(dest, s1, (len1 + 1));
	if (s2)
		ft_strlcat(dest, s2, (len1 + len2 + 1));
	return (dest);
}

t_stack *parse_input(int n, char **argv)
{
	int		length;
	char	*string;
	int		index;
	t_stack *a_stack;

	length = count_chars(n, argv);
	string = ft_calloc(sizeof(char), (length + n - 1));
	if (string == NULL)
		quit_push_swap();
	index = 1;
	while (index < n)
	{
		string = join_arguments(string, argv[index]);
		if (index < n - 1)
			string = join_arguments(string, " ");
		index++;
	}
	// printf("parsed string: %s\n", string);
	a_stack = build_stack(string);
	// I could free this string if I don't need it anymore
	return (a_stack);
}