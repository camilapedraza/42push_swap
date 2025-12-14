/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpedraza <mpedraza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 17:49:36 by mpedraza          #+#    #+#             */
/*   Updated: 2025/12/14 13:15:06 by mpedraza         ###   ########.fr       */
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
void	*ft_calloc(size_t nmemb, size_t size);
void	quit_push_swap();
int		is_space(int c);
int		is_digit(int c);
t_stack *stack_new(int value);
void	stack_add_back(t_stack **stack, t_stack *new);
void	stack_free(t_stack **stack);
int		stack_size(t_stack *stack);
t_stack	*stack_reverse_find(t_stack *stack, int item);
t_stack	*build_stack(char *string);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlcpy(char *dst, const char *src, size_t siz);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
size_t	ft_strlcat(char *dst, const char *src, size_t siz);
void	swap(t_stack **stack);
void 	push(t_stack **src, t_stack **dest);
void	rotate(t_stack **stack);
void 	reverse_rotate(t_stack **stack);

#endif