/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_parse_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpedraza <mpedraza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 14:50:59 by mpedraza          #+#    #+#             */
/*   Updated: 2025/12/12 18:30:25 by mpedraza         ###   ########.fr       */
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
		string = ft_strjoin(string, argv[index]);
		if (index < n - 1)
			string = ft_strjoin(string, " ");
		index++;
	}
	printf("parsed string: %s\n", string);
	a_stack = build_stack(string);
	return (a_stack);
}