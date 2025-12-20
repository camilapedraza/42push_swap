/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_execute_rotations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpedraza <mpedraza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 22:52:47 by mpedraza          #+#    #+#             */
/*   Updated: 2025/12/20 20:18:27 by mpedraza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sync_rotations(t_stack **a_stack, t_stack **b_stack, t_moveset *moves)
{
	size_t	rotations;

	if (moves->b_cost >= moves->a_cost)
		rotations = moves->a_cost;
	else
		rotations = moves->b_cost;
	while (rotations--)
	{
		if (moves->a_dir == 1)
		{
			rotate_both(b_stack, a_stack);
			ft_putstr_fd("rr\n", 1);
		}
		else if (moves->a_dir == -1)
		{
			reverse_rotate_both(b_stack, a_stack);
			ft_putstr_fd("rrr\n", 1);
		}
		moves->a_cost--;
		moves->b_cost--;
	}
}

void	b_rotations(t_stack **b_stack, t_moveset *moves)
{
	while (moves->b_cost--)
	{
		if (moves->b_dir == 1)
		{
			rotate(b_stack);
			ft_putstr_fd("rb\n", 1);
		}
		else
		{
			reverse_rotate(b_stack);
			ft_putstr_fd("rrb\n", 1);
		}
	}
}

void	a_rotations(t_stack **a_stack, t_moveset *moves)
{
	while (moves->a_cost--)
	{
		if (moves->a_dir == 1)
		{
			rotate(a_stack);
			ft_putstr_fd("ra\n", 1);
		}
		else
		{
			reverse_rotate(a_stack);
			ft_putstr_fd("rra\n", 1);
		}
	}
}

void	execute_rotations(t_stack **a_stack, t_stack **b_stack, t_moveset moves)
{
	if (moves.b_cost > 0 && moves.a_cost > 0 && moves.b_dir == moves.a_dir)
		sync_rotations(a_stack, b_stack, &moves);
	if (moves.b_cost)
		b_rotations(b_stack, &moves);
	if (moves.a_cost)
		a_rotations(a_stack, &moves);
}
