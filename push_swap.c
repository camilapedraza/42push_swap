/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpedraza <mpedraza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 17:48:05 by mpedraza          #+#    #+#             */
/*   Updated: 2025/12/13 18:51:39 by mpedraza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// AUTHORIZED : read, write, malloc, free, exit

#include "push_swap.h"

void ft_putstr_fd(char *s, int fd)
{
	while (*s)
		write(fd, s++, 1);
}

void quit_push_swap(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_stack	*a_stack;
	t_stack	*b_stack;
	int		a_size;
	t_stack *temp; // remove
	
	if (argc < 2)
		quit_push_swap();

	// this prepares the input (stack built in order of args) and validates it
	// we don't get a stack back if anything fails in the process (program is quit)
	a_stack = parse_input(argc, argv);
	a_size = stack_size(a_stack);
	b_stack = NULL;
	// TO DO: check a_stack exists and how many elements it has (ft_lstsize)
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
	printf("stack received - size: %d\n", a_size);
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
	return (0);
}

// LIMITS (MINIMAL)
// 100 numbers under 700, 1100 or 1300 operations
// 500 numbers under 5500, 8500 or 11500 operations

// LIMITS (FULL)
// 100 in less than 700 and 500 in less than 5500