/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpedraza <mpedraza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 17:03:50 by mpedraza          #+#    #+#             */
/*   Updated: 2025/12/09 21:05:22 by mpedraza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quit_push_swap()
{
	ft_putstr_fd("Error\n", 3);
	exit(EXIT_FAILURE);
}

int		is_space(int c)
{
	if (!(c == ' ') && !(c >=9 || c <= 13))
		return (0);
	return (1);
}

t_stack	*ft_stack_new(int *value)
{
	t_stack *stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->value = value;
	stack->next = NULL;
	return (stack);
}

void	ft_stack_add_back(t_stack **stack, t_stack *new)
{
	t_stack *temp;

	if (!stack || !new)
		return;
	if (*stack == NULL)
		*stack = new;
	else
	{
		temp = *stack;
		while (temp->next)
			temp = temp->next;
		temp->next = new;
	}
}

int	ft_atoi_check(const char *nptr)
{
	int		val;
	long	n;
	int		result;

	val = 1;
	n = 0;
	while ((*nptr == ' ') || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			val = val * -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		n = n * 10 + (*nptr - '0');
		nptr++;
	}
	if (val * n > INT_MAX || val * n < INT_MIN)
		quit_push_swap();
	return (n * val);
}