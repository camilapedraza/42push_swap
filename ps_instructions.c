/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_instructions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpedraza <mpedraza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 19:37:44 by mpedraza          #+#    #+#             */
/*   Updated: 2025/12/18 22:42:21 by mpedraza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* void	swap(t_stack **stack)
**{
**	t_stack	*temp_x;
**	t_stack *temp_y;
**
**	if (!stack || !*stack || !(*stack)->next)
**		return ;
**	temp_x = *stack;
**	temp_y = (*stack)->next;
**	temp_x->next = temp_y->next;
**	temp_y->next = temp_x;
**	*stack = temp_y;
} */

void	push(t_stack **src, t_stack **dest)
{
	t_stack *temp;

	if (!src || !*src || !dest)
		return ;
	temp = *src;
	*src = temp->next;
	temp->next = *dest;
	*dest = temp;
}

void	rotate(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*last;

	if (!stack || !*stack || !(*stack)->next)
		return;
	temp = *stack;
	*stack = temp->next;
	last = stack_reverse_find(*stack, -1);
	last->next = temp;
	temp->next = NULL;
}

void	rotate_both(t_stack **stack_1, t_stack **stack_2)
{
	rotate(stack_1);
	rotate(stack_2);
}

void	reverse_rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*next_to_last;

	if (!stack || !*stack || !(*stack)->next)
		return;
	next_to_last = stack_reverse_find(*stack, -2);
	last = next_to_last->next;
	next_to_last->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	reverse_rotate_both(t_stack **stack_1, t_stack **stack_2)
{
	reverse_rotate(stack_1);
	reverse_rotate(stack_2);
}