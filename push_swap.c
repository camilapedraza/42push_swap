/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpedraza <mpedraza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 17:48:05 by mpedraza          #+#    #+#             */
/*   Updated: 2025/12/17 21:00:44 by mpedraza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// AUTHORIZED : read, write, malloc, free, exit

#include "push_swap.h"

void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
		write(fd, s++, 1);
}

void	quit_push_swap(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

int	is_sorted(t_stack *stack)
{

	if (!stack || !stack->next)
		return (1);

	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

t_stack	*find_max(int n, t_stack *stack)
{
	t_stack *temp;
	t_stack *max;

	temp = stack;
	max = stack;
	while (temp)
	{
		if (temp->value > n && temp->value > max->value)
			max = temp;
		temp = temp->next;
	}
	return (max);
}

t_stack	*find_target(int n, t_stack *stack)
{
	t_stack *temp;
	t_stack *target;

	if (!stack)
		return (NULL);
	if (!stack->next)
		return (stack);
	temp = stack;
	target = NULL;
	while (temp)
	{
		if (temp->value < n)
			if (!target || temp->value > target->value)
				target = temp;
		temp = temp->next;
	}
	if (!target)
		target = find_max(n, stack);
	return (target);
}

size_t	find_node_position(int n, t_stack *stack)
{
	size_t	position;

	position = 0;
	while (stack->value != n)
	{
		stack = stack->next;
		position += 1;
	}
	return (position);
}

void	init_moveset(t_moveset *moves)
{
	moves->cost = 0;
	moves->s_cost = 0;
	moves->s_rdir = 1;
	moves->d_cost = 0;
	moves->d_rdir = 1;
}

t_moveset find_move_cost(int s, t_stack *src, int d, t_stack *dest)
{
	size_t		size;
	t_moveset	moves;

	init_moveset(&moves);
	if (src)
	{
		moves.s_cost = find_node_position(s, src);
		size = stack_size(src);
		if (moves.s_cost > (size - 1) / 2)
		{
			moves.s_cost = size - moves.s_cost;
			moves.s_rdir = -1;
		}
	}
	if (dest)
	{
		moves.d_cost = find_node_position(d, dest);
		size = stack_size(dest);
		if (moves.d_cost > (size - 1) / 2)
		{
			moves.d_cost = size - moves.d_cost;
			moves.d_rdir = -1;
		}
	}
	moves.cost = moves.s_cost + moves.d_cost;
	return (moves);
}

void	execute_rotations(t_stack **src, t_stack **dest, t_moveset moves)
{
	if (moves.d_cost > 0 && moves.s_cost > 0 && moves.d_rdir == moves.s_rdir)
	{
		if (moves.d_cost >= moves.s_cost)
		{
			while (moves.s_cost)
			{
				if (moves.s_rdir == 1)
				{
					rotate_both(dest, src);
					ft_putstr_fd("rr\n", 1);
				}
				else if (moves.s_rdir == -1)
				{
					reverse_rotate_both(dest, src);
					ft_putstr_fd("rrr\n", 1);
				}
				moves.s_cost--;
				moves.d_cost--;
			}
		}
		if (moves.d_cost < moves.s_cost)
			while (moves.d_cost)
			{
				if (moves.d_rdir == 1)
				{
					rotate_both(dest, src);
					ft_putstr_fd("rr\n", 1);
				}
				else if (moves.d_rdir == -1)
				{
					reverse_rotate_both(dest, src);
					ft_putstr_fd("rrr\n", 1);
				}
				moves.d_cost--;
				moves.s_cost--;
			}
	}

	if (moves.d_cost && moves.d_rdir == 1)
	{
		while (moves.d_cost--)
		{
			rotate(dest);
			ft_putstr_fd("rb\n", 1);
		}
	}
	else if (moves.d_cost && moves.d_rdir == -1)
	{
		while (moves.d_cost--)
		{
			reverse_rotate(dest);
			ft_putstr_fd("rrb\n", 1);
		}
	}
	if (moves.s_cost && moves.s_rdir == 1)
	{
		while (moves.s_cost--)
		{
			rotate(src);
			ft_putstr_fd("ra\n", 1);
		}
	}
	else if (moves.s_cost && moves.s_rdir == -1)
	{
		while (moves.s_cost--)
		{
			reverse_rotate(src);
			ft_putstr_fd("rra\n", 1);
		}
	}
}

void	sort_b_stack(t_stack **a_stack, t_stack **b_stack)
{
	t_stack		*temp;
	t_stack		*target;
	t_moveset	temp_moves;
	t_stack		*best;
	t_moveset	best_moves;
	size_t		items;
	
	init_moveset(&temp_moves);
	items = stack_size(*a_stack);
	while (items--)
	{
		temp = *a_stack;
		best = NULL;
		while (temp)
		{
			target = find_target(temp->value, *b_stack);
			if (target)
			{
				temp_moves = find_move_cost(temp->value, *a_stack, target->value, *b_stack);
				if (temp_moves.cost == 0)
				{
					best = temp;
					best_moves = temp_moves;
					break ;
				}
				else if (!best || (best && (best_moves.cost > temp_moves.cost)))
				{
					best = temp;
					best_moves = temp_moves;
				}
			}
			else
				break ;
			temp = temp->next;
		}

		execute_rotations(a_stack, b_stack, best_moves);
		// PUSH A TO B AFTER ROTATION
		push(a_stack, b_stack);
		ft_putstr_fd("pb\n", 1);
	}
}

void	sort_a_stack(t_stack **a_stack, t_stack **b_stack)
{
	int			max;
	t_moveset	max_to_top;
	size_t		passes;
	
	// NULL CHECKS HERE!!!

	max = ((*find_max((*b_stack)->value, *b_stack)).value);
	max_to_top = find_move_cost(0, NULL, max, *b_stack);
	execute_rotations(NULL, b_stack, max_to_top);
	passes = stack_size(*b_stack);
	while (passes--)
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
	
	//t_stack *temp_b; // remove
	
	if (argc < 2)
		quit_push_swap();
	a_stack = parse_input(argc, argv);
	if (is_sorted(a_stack))
		exit(EXIT_SUCCESS);
	b_stack = NULL;
	init_b_stack(&a_stack, &b_stack);
	sort_b_stack(&a_stack, &b_stack);
	sort_a_stack(&a_stack, &b_stack);
	//if (is_sorted(a_stack))
		//ft_putstr_fd("sorted succesfully!\n", 1);
	// TO DO: parse stack based on size

	/* The program must display the sequence of instructions needed to sort
	tack A in ascending order (in the FEWEST number of operations possible)
	Instructions must be separated by a ’\n’ and nothing else */

	// DEFINITION OF DONE:
	// - Stack A is properly sorted
	// - Stack A is sorted in the fewest number of moves possible (not exceed limits)
	// - Stack B is empty

	// ------------------------------------------------------------------
	// tester code from here on
	// TEST INIT B
	/*
	t_stack *temp;

	printf("\n========== RESULT! =============\n");
	printf("A stack\n");
	temp = a_stack;
	while (temp)
	{
		printf("%d\n", temp->value);
		temp = temp->next;
	}
	printf("B stack\n");
	temp = b_stack;
	while (temp)
	{
		printf("%d\n", temp->value);
		temp = temp->next;
	}
	*/
	/*
	// TEST SWAP A
	swap(&a_stack);
	printf("swap!\n");
	temp = a_stack;
	while (temp)
	{
		printf("%d\n", temp->value);
		temp = temp->next;
	}
	// TEST PUSH B
	printf("push A to B!\n");
	push(&a_stack, &b_stack);
	printf("New A stack:\n");
	temp = a_stack;
	while (temp)
	{
		printf("%d\n", temp->value);
		temp = temp->next;
	}
	printf("New B stack:\n");
	temp = b_stack;
	while (temp)
	{
		printf("%d\n", temp->value);
		temp = temp->next;
	}
	// TEST ROTATE A
	rotate(&a_stack);
	printf("rotate A!\n");
	temp = a_stack;
	while (temp)
	{
		printf("%d\n", temp->value);
		temp = temp->next;
	}
	// TEST PUSH A
	printf("push B to A!\n");
	push(&b_stack, &a_stack);
	printf("New A stack:\n");
	temp = a_stack;
	while (temp)
	{
		printf("%d\n", temp->value);
		temp = temp->next;
	}
	// TEST REVERSE ROTATE A
	reverse_rotate(&a_stack);
	printf("reverse rotate A!\n");
	temp = a_stack;
	while (temp)
	{
		printf("%d\n", temp->value);
		temp = temp->next;
	}
	// TEST ON EMPTY STACK
	swap(&b_stack);
	push(&b_stack, &a_stack);
	rotate(&b_stack);
	reverse_rotate(&b_stack);
	printf("still alive!\n");
	*/
	return (0);
}

// LIMITS (MINIMAL)
// 100 numbers under 700, 1100 or 1300 operations
// 500 numbers under 5500, 8500 or 11500 operations

// LIMITS (FULL)
// 100 in less than 700 and 500 in less than 5500