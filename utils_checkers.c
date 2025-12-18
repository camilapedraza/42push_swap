/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_checkers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpedraza <mpedraza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 17:03:50 by mpedraza          #+#    #+#             */
/*   Updated: 2025/12/18 22:57:32 by mpedraza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_digit(int c)
{
	if (!(c >= 48 && c <= 57))
		return (0);
	return (1);
}

int	is_space(int c)
{
	if (!(c == ' ') && !(c >=9 && c <= 13))
		return (0);
	return (1);
}

int is_sorted(t_stack *stack)
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