/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpedraza <mpedraza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 17:03:50 by mpedraza          #+#    #+#             */
/*   Updated: 2025/12/12 18:23:40 by mpedraza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_new(int value)
{
	t_stack *stack;

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

void stack_free(t_stack **stack)
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

int stack_item_duplicate(t_stack **stack, t_stack **item)
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