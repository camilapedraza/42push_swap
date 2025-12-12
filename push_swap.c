/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpedraza <mpedraza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 17:48:05 by mpedraza          #+#    #+#             */
/*   Updated: 2025/12/12 18:03:36 by mpedraza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// AUTHORIZED : read, write, malloc, free, exit

#include "push_swap.h"

void quit_push_swap(void)
{
	ft_putstr_fd("Error\n", 3);
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_stack	*a_stack;
	
	if (argc < 2)
		//quit_push_swap();
		return(1);

	// this prepares the input (stack built in order of args) and validates it
	// we don't get a stack back if anything fails in the process (program is quit)
	a_stack = parse_input(argc, argv);
	// TO DO: check a_stack exists and how many elements it has (ft_lstsize)
	// TO DO: parse stack based on size

	/* The program must display the sequence of instructions needed to sort
	stack A in ascending order (in the FEWEST number of operations possible)
	Instructions must be separated by a ’\n’ and nothing else */

	// DEFINITION OF DONE:
	// - Stack A is properly sorted
	// - Stack A is sorted in the fewest number of moves possible (not exceed limits)
	// - Stack B is empty

	return (0);
}

// LIMITS (MINIMAL)
// 100 numbers under 700, 1100 or 1300 operations
// 500 numbers under 5500, 8500 or 11500 operations

// LIMITS (FULL)
// 100 in less than 700 and 500 in less than 5500