/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_build_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpedraza <mpedraza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 18:20:02 by mpedraza          #+#    #+#             */
/*   Updated: 2025/12/22 19:20:08 by mpedraza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_duplicate_item(t_stack **stack, t_stack **item)
{
	t_stack	*temp;

	if (!stack)
		return (0);
	temp = *stack;
	while (temp)
	{
		if (temp->value == (*item)->value)
			return (1);
		temp = temp->next;
	}
	return (0);
}

static int	ft_atoi(char *nptr)
{
	long	val;
	long	n;

	val = 1;
	n = 0;
	while ((*nptr == ' ') || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			val = val * -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		n = n * 10 + (*nptr - '0');
		nptr++;
	}
	return (val * n);
}

static char	*extract_argument(const char *string, unsigned int start)
{
	int		end;
	int		digits;
	char	*sub_str;

	end = start;
	digits = 0;
	while (is_space(string[end]))
		end++;
	if (string[end] == '-' || string[end] == '+')
		end++;
	while (is_digit(string[end++]))
		digits++;
	if (!digits)
		return (NULL);
	sub_str = ft_substr(string, start, (end - start - 1));
	if (!sub_str)
		return (NULL);
	return (sub_str);
}

t_stack	*build_item(char *sub_str, char *string, t_stack **a_stack)
{
	t_stack	*item;

	item = NULL;
	if (!is_integer(sub_str))
	{
		free(sub_str);
		free(string);
		quit_push_swap(a_stack);
	}
	item = stack_new(ft_atoi(sub_str));
	if (!item)
	{
		free(string);
		exit(EXIT_FAILURE);
	}
	if (is_duplicate_item(a_stack, &item))
	{
		free(sub_str);
		free(string);
		free(item);
		quit_push_swap(a_stack);
	}
	return (item);
}

t_stack	*build_a_stack(int argc, char **argv, t_stack **a_stack)
{
	char	*string;
	int		index;
	char	*sub_str;
	t_stack	*item;

	string = parse_input(argc, argv);
	*a_stack = NULL;
	index = 0;
	while (string[index])
	{
		sub_str = extract_argument(string, index);
		if (!sub_str)
		{
			free(string);
			quit_push_swap(a_stack);
		}
		item = build_item(sub_str, string, a_stack);
		if (!item)
			return (NULL);
		stack_add_back(a_stack, item);
		index += (ft_strlen(sub_str));
		free(sub_str);
	}
	free(string);
	return (*a_stack);
}
