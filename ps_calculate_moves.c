/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_calculate_moves.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpedraza <mpedraza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 22:37:06 by mpedraza          #+#    #+#             */
/*   Updated: 2025/12/22 19:30:56 by mpedraza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_moveset(t_moveset *moves)
{
	moves->cost = 0;
	moves->a_cost = 0;
	moves->a_dir = 1;
	moves->b_cost = 0;
	moves->b_dir = 1;
}

void	find_a_moves(t_moveset *moves, int s, t_stack *src)
{
	size_t	size;

	moves->a_cost = find_node_position(s, src);
	size = stack_size(src);
	if (moves->a_cost > size / 2)
	{
		moves->a_cost = size - moves->a_cost;
		moves->a_dir = -1;
	}
}

void	find_b_moves(t_moveset *moves, int d, t_stack *dest)
{
	size_t	size;

	moves->b_cost = find_node_position(d, dest);
	size = stack_size(dest);
	if (moves->b_cost > size / 2)
	{
		moves->b_cost = size - moves->b_cost;
		moves->b_dir = -1;
	}
}

t_moveset	find_cost(int s, t_stack *src, int d, t_stack *dest)
{
	t_moveset	moves;

	init_moveset(&moves);
	if (src)
		find_a_moves(&moves, s, src);
	if (dest)
		find_b_moves(&moves, d, dest);
	if (moves.b_cost > 0 && moves.a_cost > 0 && moves.b_dir == moves.a_dir)
	{
		if (moves.b_cost >= moves.a_cost)
			moves.cost = moves.b_cost;
		else
			moves.cost = moves.a_cost;
	}
	else
		moves.cost = moves.a_cost + moves.b_cost;
	return (moves);
}

t_moveset	find_best_moves(t_stack **a_stack, t_stack **b_stack)
{
	t_stack		*target;
	t_stack		*temp;
	t_moveset	temp_moves;
	t_stack		*best;
	t_moveset	best_moves;

	temp = *a_stack;
	best = NULL;
	while (temp)
	{
		target = find_target(temp->value, *b_stack);
		if (!target)
			break ;
		temp_moves = find_cost(temp->value, *a_stack, target->value, *b_stack);
		if (temp_moves.cost == 0 || !best
			|| (best && (best_moves.cost > temp_moves.cost)))
		{
			best = temp;
			best_moves = temp_moves;
		}
		if (temp_moves.cost == 0)
			break ;
		temp = temp->next;
	}
	return (best_moves);
}
