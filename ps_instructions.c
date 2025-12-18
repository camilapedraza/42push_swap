/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_instructions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpedraza <mpedraza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 19:37:44 by mpedraza          #+#    #+#             */
/*   Updated: 2025/12/18 22:32:23 by mpedraza         ###   ########.fr       */
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