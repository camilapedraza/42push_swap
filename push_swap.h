/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpedraza <mpedraza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 17:49:36 by mpedraza          #+#    #+#             */
/*   Updated: 2025/12/12 20:14:56 by mpedraza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <stdint.h>
# include <unistd.h>

	typedef struct s_stack
{
	int 			value;
	struct s_stack *next;
}	t_stack;

t_stack *parse_input(int n, char **argv);
char	*extract_argument(const char *list, unsigned int start);
void	*ft_calloc(size_t nmemb, size_t size);
void	quit_push_swap();
int		is_space(int c);
int		is_digit(int c);
int		atoi_check(const char *nptr);
t_stack *stack_new(int value);
void	stack_add_back(t_stack **stack, t_stack *new);
void	stack_free(t_stack **stack);
int		stack_item_duplicate(t_stack **stack, t_stack **item);
t_stack *build_stack(char *string);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcpy(char *dst, const char *src, size_t siz);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
size_t	ft_strlcat(char *dst, const char *src, size_t siz);
void	swap_a(t_stack **stack_a);

#endif