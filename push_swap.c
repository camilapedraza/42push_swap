/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpedraza <mpedraza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 17:48:05 by mpedraza          #+#    #+#             */
/*   Updated: 2025/12/08 18:32:27 by mpedraza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// AUTHORIZED : read, write, malloc, free, exit

int validate_input(char **argv)
{
	// TO DO Validate argv:
	// - only integers
	// -- this includes numbers going over int limits
	// - no duplicates
	// DECIDE: atoi here of afterwards?
}

int	main(int argc, char **argv)
{
	// argv: stack A formatted as a list of integers. 

	// Validate arguments: validate_input
	
	// TO DO Build stack:
	// - Place first argument at TOP of the stack
	// -- BUT: top doesn't mean first in my array. I could put it last!
	// DECIDE: Good moment to keep track of stack size?

	// TO DO Handle errors:
	// - no arguments: exit
	// - errors: display "Error\n" on sterro:
	// -- arguments contain non-integers
	// -- arguments exceed int-limits
	// -- there are duplicates in the arguments

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