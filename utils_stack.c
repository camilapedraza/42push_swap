/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpedraza <mpedraza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 17:03:50 by mpedraza          #+#    #+#             */
/*   Updated: 2025/12/18 22:13:36 by mpedraza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	stack_size(t_stack *stack)
{
	size_t	count;
	t_stack *temp;

	if (!stack)
		return (0);
	count = 1;
	temp = stack;
	while (temp->next)
	{
		temp = temp->next;
		count++;
	}
	return (count);
}

t_stack	*stack_new(int value)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->value = value;
	stack->next = NULL;
	return (stack);
}

void	stack_add_back(t_stack **stack, t_stack *new)
{
	t_stack *temp;

	if (!stack || !new)
		return;
	if (*stack == NULL)
		*stack = new;
	else
	{
		temp = *stack;
		while (temp->next)
			temp = temp->next;
		temp->next = new;
	}
}

t_stack *stack_reverse_find(t_stack *stack, int item)
{
	t_stack *temp;

	if (!stack)
		return (NULL);
	temp = stack;
	if (item == -1)
		while (temp->next)
			temp = temp->next;
	else if (item == -2)
		if (temp->next)
			while (temp->next->next)
				temp = temp->next;
	return (temp);
}

void	stack_free(t_stack **stack)
{
	t_stack *temp;

	if (!stack)
		return;
	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
}