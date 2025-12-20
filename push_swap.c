/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpedraza <mpedraza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 17:48:05 by mpedraza          #+#    #+#             */
/*   Updated: 2025/12/20 20:33:00 by mpedraza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// AUTHORIZED : read, write, malloc, free, exit

#include "push_swap.h"

void	quit_push_swap(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

void	sort_b_stack(t_stack **a_stack, t_stack **b_stack)
{
	t_moveset	best_moves;
	size_t		items;
	size_t		break_point;

	init_moveset(&best_moves);
	items = stack_size(*a_stack);
	break_point = items / 10;
	while (items--)
	{
		best_moves = find_best_moves(a_stack, b_stack);
		execute_rotations(a_stack, b_stack, best_moves);
		push(a_stack, b_stack);
		ft_putstr_fd("pb\n", 1);
	}
}

void	sort_a_stack(t_stack **a_stack, t_stack **b_stack)
{
	int			max;
	t_moveset	max_to_top;
	size_t		items;

	max = ((*find_max(*b_stack)).value);
	max_to_top = find_cost(0, NULL, max, *b_stack);
	execute_rotations(NULL, b_stack, max_to_top);
	items = stack_size(*b_stack);
	while (items--)
	{
		push(b_stack, a_stack);
		ft_putstr_fd("pa\n", 1);
	}
}

void	init_b_stack(t_stack **a_stack, t_stack **b_stack)
{
	size_t	pushes;

	pushes = 0;
	while (pushes++ < B_INIT_SIZE)
	{
		push(a_stack, b_stack);
		ft_putstr_fd("pb\n", 1);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a_stack;
	t_stack	*b_stack;

	if (argc < 2)
		quit_push_swap();
	a_stack = parse_input(argc, argv);
	if (is_sorted(a_stack))
	{
		stack_free(&a_stack);
		exit(EXIT_SUCCESS);
	}
	b_stack = NULL;
	init_b_stack(&a_stack, &b_stack);
	sort_b_stack(&a_stack, &b_stack);
	sort_a_stack(&a_stack, &b_stack);
	/* printf("\n==========================\n");
	printf("A stack\n");
	t_stack *temp = a_stack;
	while (temp)
	{
		printf("%d\n", temp->value);
		temp = temp->next;
	}
	if (is_sorted(a_stack))
		write(1, "yes", 3); */
	stack_free(&a_stack);
	stack_free(&b_stack);
	return (0);
}

// LIMITS (MINIMAL)
// 100 numbers under 700, 1100 or 1300 operations
// 500 numbers under 5500, 8500 or 11500 operations

// LIMITS (FULL)
// 100 in less than 700 and 500 in less than 5500