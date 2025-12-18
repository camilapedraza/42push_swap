/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_find_targets.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpedraza <mpedraza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 22:46:20 by mpedraza          #+#    #+#             */
/*   Updated: 2025/12/18 22:51:31 by mpedraza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t find_node_position(int n, t_stack *stack)
{
	size_t position;

	position = 0;
	while (stack->value != n)
	{
		stack = stack->next;
		position += 1;
	}
	return (position);
}

t_stack *find_max(int n, t_stack *stack)
{
	t_stack *temp;
	t_stack *max;

	temp = stack;
	max = stack;
	while (temp)
	{
		if (temp->value > n && temp->value > max->value)
			max = temp;
		temp = temp->next;
	}
	return (max);
}
t_stack *find_target(int n, t_stack *stack)
{
	t_stack *temp;
	t_stack *target;

	if (!stack)
		return (NULL);
	if (!stack->next)
		return (stack);
	temp = stack;
	target = NULL;
	while (temp)
	{
		if (temp->value < n)
			if (!target || temp->value > target->value)
				target = temp;
		temp = temp->next;
	}
	if (!target)
		target = find_max(n, stack);
	return (target);
}