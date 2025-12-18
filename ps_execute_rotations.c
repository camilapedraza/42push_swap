/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_execute_rotations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpedraza <mpedraza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 22:52:47 by mpedraza          #+#    #+#             */
/*   Updated: 2025/12/18 22:53:08 by mpedraza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void execute_combined_rotations(t_stack **src, t_stack **dest, t_moveset *moves)
{
	size_t rotations;

	if (moves->d_cost >= moves->s_cost)
		rotations = moves->s_cost;
	else
		rotations = moves->d_cost;

	while (rotations--)
	{
		if (moves->s_rdir == 1)
		{
			rotate_both(dest, src);
			ft_putstr_fd("rr\n", 1);
		}
		else if (moves->s_rdir == -1)
		{
			reverse_rotate_both(dest, src);
			ft_putstr_fd("rrr\n", 1);
		}
		moves->s_cost--;
		moves->d_cost--;
	}
}

void execute_dest_rotations(t_stack **dest, t_moveset *moves)
{
	while (moves->d_cost--)
	{
		if (moves->d_rdir == 1)
		{
			rotate(dest);
			ft_putstr_fd("rb\n", 1);
		}
		else
		{
			reverse_rotate(dest);
			ft_putstr_fd("rrb\n", 1);
		}
	}
}

void execute_src_rotations(t_stack **src, t_moveset *moves)
{
	while (moves->s_cost--)
	{
		if (moves->s_rdir == 1)
		{
			rotate(src);
			ft_putstr_fd("ra\n", 1);
		}
		else
		{
			reverse_rotate(src);
			ft_putstr_fd("rra\n", 1);
		}
	}
}

void execute_rotations(t_stack **src, t_stack **dest, t_moveset moves)
{
	if (moves.d_cost > 0 && moves.s_cost > 0 && moves.d_rdir == moves.s_rdir)
		execute_combined_rotations(src, dest, &moves);
	// FUNCTION TO ROTATE B
	if (moves.d_cost)
		execute_dest_rotations(dest, &moves);
	if (moves.s_cost)
		execute_src_rotations(src, &moves);
}
