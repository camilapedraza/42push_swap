/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpedraza <mpedraza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 19:37:44 by mpedraza          #+#    #+#             */
/*   Updated: 2025/12/12 20:31:10 by mpedraza         ###   ########.fr       */
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
	int	temp;

	if (!stack || !*stack || stack_size(*stack) < 2)
		return ;
	temp = (*stack)->value;
	(*stack)->value = (*stack)->next->value;
	(*stack)->next->value = temp;
}

void	swap_both(void)
{
	//swap_a();
	//swap_b();
}

void	push_b_to_a(void)
{
	// pa (push a): Take the first element at the top of b and put it at the top of a.
	// Do nothing if b is empty.
}

void	push_a_to_b(void)
{
	// pb (push b): Take the first element at the top of a and put it at the top of b.
	// Do nothing if a is empty.
}

void	rotate_a(void)
{
	// ra (rotate a): Shift up all elements of stack a by 1.
	// The first element becomes the last one.
}

void	rotate_b(void)
{
// rb (rotate b): Shift up all elements of stack b by 1.
// The first element becomes the last one.
}

void	rotate_both(void)
{
	// rr : ra and rb at the same time.
}

void	reverse_rotate_a(void)
{
	// rra (reverse rotate a): Shift down all elements of stack a by 1.
	// The last element becomes the first one.
}

void	reverse_rotate_b(void)
{
	// rrb (reverse rotate b): Shift down all elements of stack b by 1.
	// The last element becomes the first one.
}

void	reverse_rotate_both(void)
{
	// rrr : rra and rrb at the same time.
}