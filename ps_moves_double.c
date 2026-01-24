/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_moves_double.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpedraza <mpedraza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 19:37:44 by mpedraza          #+#    #+#             */
/*   Updated: 2026/01/24 20:10:10 by mpedraza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_both(t_stack **stack_1, t_stack **stack_2)
{
	rotate(stack_1);
	rotate(stack_2);
}

void	reverse_rotate_both(t_stack **stack_1, t_stack **stack_2)
{
	reverse_rotate(stack_1);
	reverse_rotate(stack_2);
}
