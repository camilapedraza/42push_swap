/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_parse_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpedraza <mpedraza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 14:50:59 by mpedraza          #+#    #+#             */
/*   Updated: 2025/12/12 18:00:06 by mpedraza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.c"

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

char	*parse_list(const char *list, unsigned int start)
{
	int end;
	int digits;
	char *sub_str;

	// Check if EDGE CASE: no list?
	// Check if EDGE CASE: start beyond string?
	// I should not be sending empty strings, null strings, etc!
	end = start;
	digits = 0;
	while (is_space(list[end]))
		end++;
	if (list[end] == '-' || list[end] == '+')
		end++;
	while (is_digit(list[end++]))
		digits++;
	if (!digits)
		return (NULL);
	while (list[end] && !(is_space(list[end])))
		end++;
	sub_str = ft_substr(list, start, (end - start));
	if (!sub_str)
		quit_push_swap();
	return (sub_str);
}

t_stack *parse_input(int n, char **argv)
{
	int		length;
	char	*string;
	int		index;
	//t_stack *a_stack;

	length = count_chars(n, argv);
	string = ft_calloc(sizeof(char), (length + n - 1));
	if (string == NULL)
		quit_push_swap();
	index = 1;
	while (index < n)
	{
		string = string_join(string, argv[index]);
		if (index < n - 1)
			string = string_join(string, " ");
		index++;
	}
	printf("%s", string);
	return (NULL);
	//a_stack = build_stack(string);
	//return (a_stack);
}