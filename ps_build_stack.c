/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpedraza <mpedraza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 18:20:02 by mpedraza          #+#    #+#             */
/*   Updated: 2025/12/18 22:17:27 by mpedraza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int stack_item_duplicate(t_stack **stack, t_stack **item)
{
	t_stack *temp;

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

static int	atoi_check(const char *nptr)
{
	long val;
	long n;

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
	if (val * n > INT_MAX || val * n < INT_MIN)
		// is this enough or do I need to free stuff?
		quit_push_swap();
	return (n * val);
}

static char	*extract_argument(const char *list, unsigned int start)
{
	int		end;
	int 	digits;
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

t_stack	*build_stack(char *string)
{
	int		index;
	char	*sub_str;
	t_stack	*stack;
	t_stack	*stack_item;

	stack = NULL;
	index = 0;
	while (string[index])
	{
		sub_str = extract_argument(string, index);
		if (!sub_str)
		{
			stack_free(&stack);
			quit_push_swap();
		}
		// printf("%s|\n", sub_str); REMOVE
		stack_item = stack_new(atoi_check(sub_str));
		if (!stack_item || stack_item_duplicate(&stack, &stack_item))
		{
			stack_free(&stack);
			quit_push_swap();
		}
		stack_add_back(&stack, stack_item);
		index += (ft_strlen(sub_str));
		// printf("index: %d\n", index); REMOVE
	}
	return (stack);
}