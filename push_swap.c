/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpedraza <mpedraza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 17:48:05 by mpedraza          #+#    #+#             */
/*   Updated: 2025/12/09 21:40:12 by mpedraza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// AUTHORIZED : read, write, malloc, free, exit

#include "push_swap.h"

char	*parse_list(const char *list, unsigned int start)
{
	int		end;
	int		digits;
	char	*sub_str;

	// Check if EDGE CASE: no list?
	// Check if EDGE CASE: start beyond string?
	// I should not be sending empty strings, null strings, etc!
	end = start;
	digits = 0;
	while (is_space(list[end]))
		end++;
	if (list[end] == '-' || list[end] == '+')
		end++;
	while (ft_isdigit(list[end++]))
		digits++;
	if (!digits)
		return(NULL);
	while (list[end] && !(is_space(list[end])))
		end++;
	sub_str = ft_substr(list, start, (end - start));
	if (!sub_str)
		quit_push_swap();
	return (sub_str);
}

t_stack	*build_stack_a(char *list)
{
	int			index;
	char		*sub_str;
	int			value;
	t_stack		*stack_a;
	t_stack		*stack_item;

	stack_a = NULL;
	index = 0;
	while (list[index])
	{
		sub_str = parse_list(list, index);
		if (!sub_str)
			break ;
		value = ft_atoi_check(sub_str);
		stack_item = ft_stack_new(value);
		if (!stack_item)
		{
			// TO DO: lstclear on stack_a before quit
			quit_push_swap();
		}
		// check no other stack item has the same value! No duplicates
		// if duplicate, clear stack; quit_push_swap()
		ft_stack_add_back(&stack_a, stack_item);
		index = (ft_strlen(sub_str));
	}
	return (stack_a);
}

t_stack	*parse_input(int n, char **argv)
{
	int		i;
	char	*list;
	t_stack	*a_stack;

	i = 1;
	list = NULL;
	a_stack = NULL;
	while (i < n)
	{
		// URGENT: THIS NEEDS FIXING, ADD SPACE BETWEEN EACH ARGUMENT!!!
		list = ft_strjoin(list, argv[i++]);
		if (!list)
			quit_push_swap;
	}
	a_stack = build_stack_a(list);
	return (a_stack);
}	

int	main(int argc, char **argv)
{
	t_stack	*a_stack;
	
	if (argc < 2)
		quit_push_swap();

	// this prepares the input (stack built in order of args) and validates it
	// we don't get a stack back if anything fails in the process
	a_stack = parse_input((argc - 1), argv);
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