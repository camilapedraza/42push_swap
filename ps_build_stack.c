/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_build_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpedraza <mpedraza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 18:20:02 by mpedraza          #+#    #+#             */
/*   Updated: 2025/12/20 23:42:58 by mpedraza         ###   ########.fr       */
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

static char	*extract_argument(const char *list, unsigned int start)
{
	int		end;
	int		digits;
	char	*sub_str;

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
	sub_str = ft_substr(list, start, (end - start - 1));
	if (!sub_str)
		return (NULL);
	return (sub_str);
}

t_stack	*build_a_stack(char *string, t_stack **a_stack)
{
	int		index;
	char	*sub_str;
	t_stack	*item;

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
		if (!is_integer(sub_str))
		{
			free(string);
			free(sub_str);
			quit_push_swap(a_stack);
		}
		item = stack_new(ft_atoi(sub_str));
		if (!item)
			return (NULL);
		if (is_duplicate_item(a_stack, &item))
		{
			free(string);
			free(sub_str);
			quit_push_swap(a_stack);
		}
		stack_add_back(a_stack, item);
		index += (ft_strlen(sub_str));
		free(sub_str);
	}
	return (*a_stack);
}
