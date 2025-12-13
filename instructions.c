/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpedraza <mpedraza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 19:37:44 by mpedraza          #+#    #+#             */
/*   Updated: 2025/12/13 18:43:54 by mpedraza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//t_stack	**stack_a;
//t_stack	**stack_b;

void	swap(t_stack **stack)
{
	// sa (swap a): Swap the first 2 elements at the top of stack a.
	// Do nothing if there is only one element or none.

	// sb (swap b): Swap the first 2 elements at the top of stack b.
	// Do nothing if there is only one element or none.
	t_stack *temp_x;
	t_stack *temp_y;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	temp_x = *stack;
	temp_y = (*stack)->next;
	temp_x->next = temp_y->next;
	temp_y->next = temp_x;
	*stack = temp_y;
}

void	swap_both(void)
{
	//swap_a();
	//swap_b();
}

void	push(t_stack **src, t_stack **dest)
{
	t_stack *temp;

	if (!src || !*src || !dest)
		return ;
	temp = *src;
	*src = temp->next;
	temp->next = *dest;
	*dest = temp;

	// pa (push a): Take the first element at the top of b and put it at the top of a.
	// Do nothing if b is empty.

	// pb (push b): Take the first element at the top of a and put it at the top of b.
	// Do nothing if a is empty.
}

void	rotate(t_stack **stack)
{
	t_stack *temp;
	t_stack *last;

	if (!stack || !*stack || !(*stack)->next)
		return;
	temp = *stack;
	*stack = temp->next;
	last = stack_reverse_find(*stack, -1);
	last->next = temp;
	temp->next = NULL;
	// ra (rotate a): Shift up all elements of stack a by 1.
	// The first element becomes the last one.

	// rb (rotate b): Shift up all elements of stack b by 1.
	// The first element becomes the last one.
}

void	rotate_both(void)
{
	// rr : ra and rb at the same time.
}

void	reverse_rotate(t_stack **stack)
{
	t_stack *last;
	t_stack *next_to_last;

	if (!stack || !*stack || !(*stack)->next)
		return;
	next_to_last = stack_reverse_find(*stack, -2);
	last = next_to_last->next;
	next_to_last->next = NULL;
	last->next = *stack;
	*stack = last;
	// rra (reverse rotate a): Shift down all elements of stack a by 1.
	// The last element becomes the first one.

	// rrb (reverse rotate b): Shift down all elements of stack b by 1.
	// The last element becomes the first one.
}

void	reverse_rotate_both(void)
{
	// rrr : rra and rrb at the same time.
}