/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_basic_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpedraza <mpedraza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 17:12:37 by mpedraza          #+#    #+#             */
/*   Updated: 2026/01/24 20:02:06 by mpedraza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_v2(t_stack **a_stack, int a, int c)
{
	if (a < c)
	{
		swap(a_stack);
		rotate(a_stack);
		ft_putstr_fd("sa\nra\n", 1);
	}
	else
	{
		reverse_rotate(a_stack);
		ft_putstr_fd("rra\n", 1);
	}
}

void	sort_three_v1(t_stack **a_stack, int a, int b, int c)
{
	if (b > c)
	{
		swap(a_stack);
		reverse_rotate(a_stack);
		ft_putstr_fd("sa\nrra\n", 1);
	}
	else if (b < c && a < c)
	{
		swap(a_stack);
		ft_putstr_fd("sa\n", 1);
	}
	else
	{
		rotate(a_stack);
		ft_putstr_fd("ra\n", 1);
	}
}

void	parse_three(t_stack **a_stack)
{
	int	a;
	int	b;
	int	c;

	a = (*a_stack)->value;
	b = (*a_stack)->next->value;
	c = (*a_stack)->next->next->value;
	if (!is_sorted(*a_stack))
	{
		if (a > b)
			sort_three_v1(a_stack, a, b, c);
		else
			sort_three_v2(a_stack, a, c);
	}
}

void	sort_four_plus(t_stack **a_stack, t_stack **b_stack)
{
	int			min;
	t_moveset	min_to_top;

	while (stack_size(*a_stack) > 3)
	{
		min = ((*find_min(*a_stack)).value);
		min_to_top = find_cost(min, *a_stack, 0, NULL);
		execute_rotations(a_stack, NULL, min_to_top);
		if (is_sorted(*a_stack))
			break ;
		push(a_stack, b_stack);
		ft_putstr_fd("pb\n", 1);
	}
	parse_three(a_stack);
	while (*b_stack)
	{
		push(b_stack, a_stack);
		ft_putstr_fd("pa\n", 1);
	}
}

void	basic_sort(t_stack **a_stack, t_stack **b_stack)
{
	size_t	size;

	size = stack_size(*a_stack);
	if (size < 3)
	{
		swap(a_stack);
		ft_putstr_fd("sa\n", 1);
	}
	else if (size == 3)
		parse_three(a_stack);
	else
		sort_four_plus(a_stack, b_stack);
}
