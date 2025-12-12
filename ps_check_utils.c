/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_check_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpedraza <mpedraza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 17:03:50 by mpedraza          #+#    #+#             */
/*   Updated: 2025/12/12 15:19:32 by mpedraza         ###   ########.fr       */
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

int	atoi_check(const char *nptr)
{
	int		val;
	long	n;

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
		// is this enough or do I need to free stuff?
		quit_push_swap();
	return (n * val);
}