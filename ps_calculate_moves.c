/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_calculate_moves.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpedraza <mpedraza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 22:37:06 by mpedraza          #+#    #+#             */
/*   Updated: 2025/12/18 22:51:28 by mpedraza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void	init_moveset(t_moveset *moves)
{
	moves->cost = 0;
	moves->s_cost = 0;
	moves->s_rdir = 1;
	moves->d_cost = 0;
	moves->d_rdir = 1;
}

void find_src_moves(t_moveset *moves, int s, t_stack *src)
{
	size_t size;

	moves->s_cost = find_node_position(s, src);
	size = stack_size(src);
	if (moves->s_cost > (size - 1) / 2)
	{
		moves->s_cost = size - moves->s_cost;
		moves->s_rdir = -1;
	}
}

void find_dest_moves(t_moveset *moves, int d, t_stack *dest)
{
	size_t size;

	moves->d_cost = find_node_position(d, dest);
	size = stack_size(dest);
	if (moves->d_cost > (size - 1) / 2)
	{
		moves->d_cost = size - moves->d_cost;
		moves->d_rdir = -1;
	}
}

t_moveset find_move_cost(int s, t_stack *src, int d, t_stack *dest)
{
	t_moveset moves;

	init_moveset(&moves);
	if (src)
		find_src_moves(&moves, s, src);
	if (dest)
		find_dest_moves(&moves, d, dest);
	if (moves.d_cost > 0 && moves.s_cost > 0 && moves.d_rdir == moves.s_rdir)
	{
		if (moves.d_cost >= moves.s_cost)
			moves.cost = moves.d_cost;
		else
			moves.cost = moves.s_cost;
	}
	else
		moves.cost = moves.s_cost + moves.d_cost;
	return (moves);
}

t_moveset	find_best_moves(t_stack **a_stack, t_stack **b_stack)
{
	t_stack		*temp;
	t_stack		*target;
	t_moveset	temp_moves;
	t_stack		*best;
	t_moveset 	best_moves;

	temp = *a_stack;
	best = NULL;
	init_moveset(&temp_moves);
	while (temp)
	{
		target = find_target(temp->value, *b_stack);
		if (!target)
			break ;
		temp_moves = find_move_cost(temp->value, *a_stack, target->value, *b_stack);
		if (temp_moves.cost == 0 || !best || (best && (best_moves.cost > temp_moves.cost)))
		{
			best = temp;
			best_moves = temp_moves;
		}
		if (temp_moves.cost == 0)
			break;
		temp = temp->next;
	}
	return (best_moves);
}
