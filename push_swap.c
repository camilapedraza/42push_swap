/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpedraza <mpedraza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 17:48:05 by mpedraza          #+#    #+#             */
/*   Updated: 2025/12/15 13:54:19 by mpedraza         ###   ########.fr       */
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

// Could put this in build_stack.c and rename to build_stacks.c

size_t	factorial(size_t stack_size)
{
	if (stack_size <= 1)
		return (1);
	return (stack_size * factorial(stack_size - 1));
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

void find_limits(t_stack *stack)
{
	int b_max;
	int b_min;

	if (stack->value > stack->next->value)
	{
		b_max = stack->value;
		b_min = stack->next->value;
	}
	else
	{
		b_min = stack->value;
		b_max = stack->next->value;
	}
}

t_stack	*find_target(int n, t_stack *stack)
{
	t_stack *temp;
	t_stack *target;
	int		max;

	write(1, "find_target\n", 12);
	if (!stack)
		return (NULL);
	if (!stack->next)
		return (stack);
	temp = stack;
	target = NULL;
	max = stack->value;
	// find next smaller number
	while (temp)
	{
		if (temp->value < n && temp->value >= max)
		{
			target = temp;
			max = temp->value;
		}
		temp = temp->next;
	}
	if (!target)
	{
		temp = stack;
		while (temp)
		{
			// THIS NEEDS TO BE FIXED! What is the actual best target here!?!?!
			if (temp->value > n && temp->value <= max)
			{
				target = temp;
				max = temp->value;
			}
			temp = temp->next;
		}
	}
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

typedef struct s_moveset
{
	size_t	cost;
	size_t	s_cost;
	int		s_rdir;
	size_t	d_cost;
	int		d_rdir;
} t_moveset;

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

	// NULL checks here
	// what type of struct should move_cost return?
	moves.s_cost = find_node_position(s, src);
	size = stack_size(src);
	if (moves.s_cost > size/2)
	{
		moves.s_cost = size - moves.s_cost;
		moves.s_rdir = -1;
	}
	moves.d_cost = find_node_position(d, dest);
	size = stack_size(dest);
	// IF d_pos is last node in dest stack, it's a no-cost move (same as if first node)
	// add condition here to make moves.d_cost = 0
	if (moves.d_cost > size / 2)
	{
		moves.d_cost = size - moves.d_cost;
		moves.s_rdir = -1;
	}
	moves.cost = moves.s_cost + moves.d_cost;
	// should I calculate R and RR costs separately and then try to find common ground?
	// what is it seems they need to move in opposite directions but actually
	// can be less costly to do synchronous moves first, then finish off with single moves
	// even if it goes against the assumption of less costly move?
	
	// This return is for testing only!!!
	return (moves);
}

void sort_stacks(t_stack **a_stack, t_stack **b_stack)
{
	t_stack		*temp;
	t_stack		*target;
	t_moveset	temp_moves;
	t_stack		*best;
	t_moveset	best_moves;

	temp = *a_stack;
	best = NULL;
	init_moveset(&best_moves);
	write(1, "sort_stacks\n", 12);
	while (temp)
	{
		target = find_target(temp->value, *b_stack);
		write(1, "target found\n", 14);
		if (target != NULL)
		{
			temp_moves = find_move_cost(temp->value, *a_stack, target->value, *b_stack);
			printf("target for %d is %d, cost is %zu\n", temp->value, target->value, temp_moves.cost);
			if (temp_moves.cost == 0)
			{
				best = temp;
				best_moves = temp_moves;
				break ;
			}
			else
			{
				if (!best || (best && (best_moves.cost > temp_moves.cost)))
					{
						best = temp;
						best_moves = temp_moves;
					}
			}		
		}
		temp = temp->next;
	}
	printf("Best candidate is %d - target is %d, cost is %zu\n", best->value, target->value, best_moves.cost);
	/*
	/////////
	// START MOVING THINGS HERE
	// B_STACK ROTATION
	if (best_moves.d_cost && best_moves.d_rdir == 1)
		while (best_moves.d_cost--)
			rotate(b_stack);
	if (best_moves.d_cost && best_moves.d_rdir == -1)
		while (best_moves.d_cost--)
			reverse_rotate(b_stack);
	// A_STACK ROTATION
	if (best_moves.s_cost && best_moves.s_rdir == 1)
		while (best_moves.s_cost--)
			rotate(a_stack);
	if (best_moves.s_cost && best_moves.s_rdir == -1)
		while (best_moves.s_cost--)
			reverse_rotate(a_stack);
	// PUSH A TO B AFTER ROTATION
	push(a_stack, b_stack);
	*/
	// if A node has target
	// calculate A node position and cost
	// calculate target position and cost
	// -- if cost == 0, move immediately, start cycle again
	// else, if no candidate yet, save as candidate, save moves
	// else, if cost smaller than current candidate, replace as candidate, replace moves
	// else, if cost higher than candidate, ignore and move to next A node

	// WHAT TO DO?
	// FIND B min and max (or update)?
	// Calculate for each number in A the cost of moving to B:
	// -- Cost of bringing it to top of A:
	// ---- ra if position is less than half len of A
	// ---- rra if position is more than half len of A
	// -- Cost of bringing target number to top of B 
	// ---- same calculations as A
	// Add up costs (including simultaneous moves for both stacks)
	// Execute instructions for cheapest (first one found)
	// Rinse / repeat

}	

void	init_b_stack(t_stack **a_stack, t_stack **b_stack)
{
	//size_t	pushes;
	//size_t	median;

	//pushes = stack_size(*a_stack) - 2;
	push(a_stack, b_stack);
	push(a_stack, b_stack);
	/*median = a_size / 2;
	while (median--)

		push(a_stack, b_stack);*/
	/*
	rotate(a_stack);
	a_size = stack_size(*a_stack) - 1;
	while (a_size--)
		push(a_stack, b_stack);
	*/
}

int	main(int argc, char **argv)
{
	t_stack	*a_stack;
	t_stack	*b_stack;
	
	t_stack *temp; // remove
	//t_stack *temp_b; // remove
	
	if (argc < 2)
		quit_push_swap();

	// this prepares the input (stack built in order of args) and validates it
	// we don't get a stack back if anything fails in the process (program is quit)
	a_stack = parse_input(argc, argv);
	b_stack = NULL;
	init_b_stack(&a_stack, &b_stack);
	sort_stacks(&a_stack, &b_stack);
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
	printf("\n==========================\n");
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